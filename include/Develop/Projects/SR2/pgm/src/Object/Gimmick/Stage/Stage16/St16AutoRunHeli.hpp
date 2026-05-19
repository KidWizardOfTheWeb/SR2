#ifndef ST16AUTORUNHELI_HPP
#define ST16AUTORUNHELI_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickAutoRunObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08UfoCatcher.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/SlerpQuat.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03Macross.hpp"

class clsAutoRunHeli_Obj;

// total size: 0x18
class clsAutoRunHeliModel {
public:
    clsAutoRunHeliModel() {}
    ~clsAutoRunHeliModel() {}

    clsModelType_OB_TX_MO m_cModelHeli; // offset 0x0, size 0x10
    clsModelType_OB_TX m_cModelRope;    // offset 0x10, size 0x8
};

class clsPendulumControl; // PLACEHOLDER — empty header, scaffold first when possible
class clsPlayerTask;

// total size: 0x250
class clsAutoRunHeli : public clsGimmickAutoRunObj {
public:
    clsAutoRunHeli() {}
    virtual ~clsAutoRunHeli() {}
    virtual void destroy() {}

    // Name collision with Game.hpp — nested inside class per scaffold rule
    // Note: enmMode name collision — Game.hpp declares different values at global scope
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    // Name collision with other TUs — nested inside class per scaffold rule
    // Note: enmMoveMode name collision — Stage06/St06GLinkElevator.hpp declares different values
    enum enmMoveMode {
        MOVEMODE_WAIT = 0,
        MOVEMODE_MOVE = 1,
        MOVEMODE_STOP = 2,
        MOVEMODE_RETURN = 3,
        MOVEMODE_END = 4,
        MOVEMODE_EMPTYWAIT = 5,
        MOVEMODE_EMPTYWAIT_RUN = 6,
        MOVEMODE_STARTWAIT = 7,
    };

    enmMode m_eMode;                         // offset 0x1C0, size 0x4
    enmMoveMode m_eMoveMode;                 // offset 0x1C4, size 0x4
    clsAutoRunHeli_Obj* m_pcHeliObj;         // offset 0x1C8, size 0x4
    f32 m_f32InterpolateFrame;               // offset 0x1CC, size 0x4
    f32 m_f32EffectFrame;                    // offset 0x1D0, size 0x4
    clsPendulumControl* m_pcPendulumControl; // offset 0x1D4, size 0x4
    f32 m_f32AirMove;                        // offset 0x1D8, size 0x4
    NNS_QUATERNION m_sRopeRotQuat;           // offset 0x1DC, size 0x10
    clsSe3DControl* m_pcSe3DControl;         // offset 0x1EC, size 0x4
    clsSlerpQuat m_SlerpQuat;                // offset 0x1F0, size 0x3C
    f32 m_f32AccelFrame;                     // offset 0x22C, size 0x4
    f32 m_f32Accel;                          // offset 0x230, size 0x4
    u8 m_bIsCatch;                           // offset 0x234, size 0x1
    u8 m_bLight;                             // offset 0x235, size 0x1
    f32 m_f32EffectCnt;                      // offset 0x238, size 0x4
    NNS_VECTORFAST m_sEffectPos;             // offset 0x240, size 0x10

    static f32 m_tof32CLIP_DISTx2;

    virtual void setStartWait(clsAutoRunHeli_Obj* pcObj);
    virtual void start(clsPlayerTask* pcPlayerTask, clsAutoRunHeli_Obj* pcObj);
    virtual u8 movePath(bool bFunc);
    virtual void getPathRotQuat(NNS_QUATERNION& rsRotQuat);
    virtual void getEffectPosVecFast(NNS_VECTORFAST& rsPosVecFast);
    virtual void execute();
    virtual u8 draw(clsAutoRunHeliModel& rcModel,
                    f32 (*psMtxPal)[4][4],
                    u32* psNodeStat,
                    const f32 (*opaNnViewMtx)[4][4],
                    f32 (*psMtxWork)[4][4],
                    u32 u32ViewNo,
                    u32 NodeStatus);

    void setMoveMode(enmMoveMode eMode) { m_eMoveMode = eMode; }
    enmMoveMode getMoveMode() const { return m_eMoveMode; }
};

// total size: 0xB0
class clsAutoRunHeli_Obj : public clsPhantomGimmickObject {
public:
    enum enmMode {
        MODE__READY = 0,
        MODE__WAIT = 1,
        MODE__CHARGE = 2,
        MODE__SHOOT = 3,
        MODE__HORMING = 4,
        MODE__BLAST = 5,
    };

    enum enmCtrlMode {
        CTRL_NULL = 0,
        CTRL_RUN = 1,
        CTRL_STOP = 2,
    };

    clsAutoRunHeli_Obj() : clsPhantomGimmickObject() {}
    virtual ~clsAutoRunHeli_Obj() {}

    virtual void contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST16_AUTORUN_HELI_26030; }

    void init();
    void reset();
    clsAutoRunHeli* getMoveModeCmp(clsAutoRunHeli::enmMoveMode eMoveMode);
    void controlPlayer() {}

    void setMode(enmMode eMode) { m_eMode = eMode; }
    enmMode getMode() const { return m_eMode; }
    f32 getSpeed() const { return m_sScaleVec.x; }
    f32 getStartSpeed() const { return m_sScaleVec.y; }
    f32 getAccelFrame() const { return m_sScaleVec.z; }

    enmMode m_eMode;                                       // offset 0x60, size 0x4
    clsGimmickAutoRunBuffer<clsAutoRunHeli> m_cHeliBuffer; // offset 0x64, size 0x1C
    enmCtrlMode m_aeCtrlMode[8];                           // offset 0x80, size 0x20
    NNS_VECTORFAST m_sDirPosVecFast;                       // offset 0xA0, size 0x10
};

class clsAutoRunHeli_Task
    : public clsBaseGimmickBody<clsAutoRunHeli_Task, clsAutoRunHeli_Obj, clsAutoRunHeliModel> {
public:
    clsAutoRunHeli_Task(u32 u32ObjectAreaNum);
    virtual ~clsAutoRunHeli_Task();
    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI);
    virtual void execute();
    virtual void draw();

    // Members
    clsMacrossThroughCollision m_cThroughCollision; // offset 0xA4, size 0x8
    NNS_ROTATE_A32* m_pA32Rot;                      // offset 0xAC, size 0x4
    f32 m_f32AirCnt;                                // offset 0xB0, size 0x4
};

#endif // ST16AUTORUNHELI_HPP
