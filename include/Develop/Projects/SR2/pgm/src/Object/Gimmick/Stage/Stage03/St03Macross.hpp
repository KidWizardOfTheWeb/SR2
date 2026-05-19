#ifndef ST03MACROSS_HPP
#define ST03MACROSS_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickAutoRunObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsModelType_OB_TX;
class clsMacross;
class clsMacross_Obj;
class clsMacrossModels;
class clsPack;
class clsPendulumControl;
class clsPlayerTask;

// total size: 0x8
class clsMacrossModels {
public:
    clsModelType_OB_TX* m_pcModelLift;  // offset 0x0, size 0x4
    clsModelType_OB_TX* m_pcModelCrane; // offset 0x4, size 0x4
};

// total size: 0x8
class clsMacrossThroughCollision : public clsBaseThroughCollision {
public:
    virtual ~clsMacrossThroughCollision() {}
    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);

    void create(const NNS_VECTOR& orsPosVec, f32 f32RotY);
};

// total size: 0x210
class clsMacross : public clsGimmickAutoRunObj {
public:
    // Note: enmMode collides with unrelated DWARF enum bodies; this body matches clsMacross.
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
        MODE_SLEEP = 2,
    };

    // Note: enmMoveMode collides with unrelated DWARF enum bodies; this body matches clsMacross.
    enum enmMoveMode {
        MOVEMODE_APPROACH = 0,
        MOVEMODE_MAIN_WAIT = 1,
        MOVEMODE_MAIN = 2,
        MOVEMODE_END = 3,
        MOVEMODE_LIFT_WAIT = 4,
        MOVEMODE_LIFT_START = 5,
        MOVEMODE_LIFT_UP_INIT = 6,
        MOVEMODE_LIFT_UP = 7,
        MOVEMODE_LIFT_DOWN = 8,
    };

    clsMacross() {}
    virtual ~clsMacross() {}

    virtual void destroy() {}
    void movePlayer() {}
    u8 draw(clsMacrossModels& rcModels,
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
    clsMacross_Obj* m_pcMacrossObj;          // offset 0x1C8, size 0x4
    f32 m_f32CountFrame;                     // offset 0x1CC, size 0x4
    f32 m_f32EffectFrame;                    // offset 0x1D0, size 0x4
    clsPendulumControl* m_pcPendulumControl; // offset 0x1D4, size 0x4
    NNS_VECTORFAST m_sOldPosVecFast;         // offset 0x1E0, size 0x10
    NNS_QUATERNION m_sOldRotQuat;            // offset 0x1F0, size 0x10
    NNS_QUATERNION m_sDebugRotQuat;          // offset 0x200, size 0x10
};

// total size: 0xB0
class clsMacross_Task
    : public clsBaseGimmickBody<clsMacross_Task, clsMacross_Obj, clsModelType_OB_TX> {
public:
    clsMacross_Task(u32 u32ObjectAreaNum);
    virtual ~clsMacross_Task() {}

    f32* m_pf32TexCoordV;                           // offset 0x94, size 0x4
    clsModelType_OB_TX m_cModelCrane;               // offset 0x98, size 0x8
    clsMacrossModels m_cModels;                     // offset 0xA0, size 0x8
    clsMacrossThroughCollision m_cThroughCollision; // offset 0xA8, size 0x8

    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI);
};

// total size: 0xB0
class clsMacross_Obj : public clsPhantomGimmickObject {
public:
    enum enmMacrossMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    // enmControlMode collision with global enmControlMode in PlayerData.hpp
    enum enmControlMode {
        CONTROL_NULL = 0,
        CONTROL_RUN = 1,
        CONTROL_STOP = 2,
    };

    clsMacross_Obj() {}
    virtual ~clsMacross_Obj() {}

    virtual void contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST03_MACROSS_13070; }
    virtual u32 getMultiDrawNum() const { return 1; }

    void init();
    void setMode(enmMacrossMode eMode) { m_eMacrossMode = eMode; }
    enmMacrossMode getMode() const { return m_eMacrossMode; }
    void elaseExexute(clsMacross* pcMacross) {}
    void controlPlayer() {}

    static f32 tof32CLIP_DISTx2;

    enmMacrossMode m_eMacrossMode;                        // offset 0x60, size 0x4
    f32 m_f32MaxSpeed;                                    // offset 0x64, size 0x4
    f32 m_f32MinSpeed;                                    // offset 0x68, size 0x4
    u32 m_u32PlayerFlg;                                   // offset 0x6C, size 0x4
    clsGimmickAutoRunBuffer<clsMacross> m_cMacrossBuffer; // offset 0x70, size 0x1C
    enmControlMode m_aeControlMode[8];                    // offset 0x8C, size 0x20
};

#endif // ST03MACROSS_HPP
