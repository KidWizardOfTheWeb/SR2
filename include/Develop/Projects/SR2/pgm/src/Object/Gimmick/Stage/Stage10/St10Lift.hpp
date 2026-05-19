#ifndef ST10LIFT_HPP
#define ST10LIFT_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickAutoRunObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage10/LiftModels.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsLift;
class clsLift_Obj;
class clsPendulumControl;
class clsPlaySe_2D;

class clsLiftThroughCollision : public clsBaseThroughCollision {
public:
    clsLiftThroughCollision() {}
    virtual ~clsLiftThroughCollision() {}

    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);

    static NNS_VECTOR tosPosVec;
};

// total size: 0xB0
class clsLift_Obj : public clsPhantomGimmickObject {
public:
    enum enmLiftMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    clsLift_Obj() {}
    virtual ~clsLift_Obj() {}

    virtual void contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST10_LIFT_20040; }

    void init();
    void setMode(enmLiftMode eMode) { m_eLiftMode = eMode; }
    enmLiftMode getMode() const { return m_eLiftMode; }
    void elaseExexute(clsLift* pcLift) {}
    void controlPlayer() {}

    static f32 tof32CLIP_DISTx2;
    static NNS_VECTOR tosPosVec;

    enmLiftMode m_eLiftMode;                                   // offset 0x60, size 0x4
    f32 m_f32MaxSpeed;                                         // offset 0x64, size 0x4
    f32 m_f32MinSpeed;                                         // offset 0x68, size 0x4
    u32 m_u32PlayerFlg;                                        // offset 0x6C, size 0x4
    clsGimmickAutoRunBuffer<clsLift> m_cLiftBuffer;            // offset 0x70, size 0x1C
    clsRigidBodyGimmickObj::enmControlMode m_aeControlMode[8]; // offset 0x8C, size 0x20
};

// total size: 0x220
class clsLift : public clsGimmickAutoRunObj {
public:
    // Note: enmMode collides with unrelated DWARF enum bodies; this body matches clsLift.
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
        MODE_SLEEP = 2,
    };

    // Note: enmMoveMode collides with unrelated DWARF enum bodies; this body matches clsLift.
    enum enmMoveMode {
        MOVEMODE_APPROACH = 0,
        MOVEMODE_MAIN_WAIT = 1,
        MOVEMODE_MAIN = 2,
        MOVEMODE_END = 3,
        MOVEMODE_LIFT_WAIT = 4,
        MOVEMODE_LIFT_START = 5,
        MOVEMODE_LIFT_CATCH = 6,
        MOVEMODE_LIFT_DOWN = 7,
    };

    clsLift() {}
    virtual ~clsLift() {}

    virtual void destroy() {}
    void movePlayer() {}
    u8 draw(clsLiftModels& rcModels,
            f32 (*psMtxPal)[4][4],
            u32* psNodeStat,
            const f32 (*opaNnViewMtx)[4][4],
            f32 (*psMtxWork)[4][4],
            u32 u32ViewNo,
            u32 NodeStatus);

    static f32 tof32CLIP_DISTx2;
    static NNS_VECTORFAST tosPlayerOffsetPosFast;

    enmMode m_eMode;                         // offset 0x1C0, size 0x4
    enmMoveMode m_eMoveMode;                 // offset 0x1C4, size 0x4
    clsLift_Obj* m_pcLiftObj;                // offset 0x1C8, size 0x4
    f32 m_f32CountFrame;                     // offset 0x1CC, size 0x4
    f32 m_f32EffectFrame;                    // offset 0x1D0, size 0x4
    clsPendulumControl* m_pcPendulumControl; // offset 0x1D4, size 0x4
    NNS_VECTORFAST m_sOldPosVecFast;         // offset 0x1E0, size 0x10
    NNS_QUATERNION m_sOldRotQuat;            // offset 0x1F0, size 0x10
    NNS_VECTORFAST m_sSetPosVecFast;         // offset 0x200, size 0x10
    clsPlaySe_2D* m_pcPlaySe2D;              // offset 0x210, size 0x4
    u32 m_u32SeId;                           // offset 0x214, size 0x4
};

class clsLift_Task : public clsBaseGimmickBody<clsLift_Task, clsLift_Obj, clsModelType_OB_TX> {
public:
    clsLift_Task(u32 u32ObjectAreaNum);
    virtual ~clsLift_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();
    virtual void createModel(stcBinInfo& rsBinInfoI);

    f32* m_pf32TexCoordV;                        // offset 0x94, size 0x4
    clsModelType_OB_TX m_cModelCrane;            // offset 0x98, size 0x8
    clsLiftModels m_cModels;                     // offset 0xA0, size 0x4
    clsLiftThroughCollision m_cThroughCollision; // offset 0xA4, size 0x8
};

#endif // ST10LIFT_HPP
