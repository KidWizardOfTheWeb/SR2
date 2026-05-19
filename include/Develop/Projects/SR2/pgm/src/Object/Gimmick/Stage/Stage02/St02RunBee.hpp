#ifndef ST02RUNBEE_HPP
#define ST02RUNBEE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickAutoRunObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/PendulumControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02PathBee.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

class clsRunBee_Obj;
class clsRunBee;

// total size: 0x94
class clsRunBee_Task
    : public clsBaseGimmickBody<clsRunBee_Task, clsRunBee_Obj, clsModelType_OB_TX> {
public:
    clsRunBee_Task(u32 u32ObjectAreaNum);
    virtual ~clsRunBee_Task();

    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI);
};

// total size: 0xC
class clsRunBeeCollision : public clsBaseThroughCollision {
public:
    virtual ~clsRunBeeCollision() {}

    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);

    clsRunBee_Obj* m_pcRunBeeObj; // offset 0x8, size 0x4
};

// total size: 0x90
class clsRunBee_Obj : public clsGimmickObj {
public:
    inline clsRunBee_Obj() : clsGimmickObj() {}
    virtual ~clsRunBee_Obj() {}

    enum enmRunBeeMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enmRunBeeMode m_eRunBeeMode;     // offset 0x50, size 0x4
    clsRunBee* m_apcRunBee;          // offset 0x54, size 0x4
    clsRunBee** m_ppcExecute;        // offset 0x58, size 0x4
    u32 m_u32ExecuteNum;             // offset 0x5C, size 0x4
    clsRunBee** m_ppcSleep;          // offset 0x60, size 0x4
    u32 m_u32SleepNum;               // offset 0x64, size 0x4
    u32 m_u32ObjectNum;              // offset 0x68, size 0x4
    f32 m_f32MaxSpeed;               // offset 0x6C, size 0x4
    f32 m_f32MinSpeed;               // offset 0x70, size 0x4
    clsRunBeeCollision m_cCollision; // offset 0x74, size 0xC
    u32 m_u32PlayerFlg;              // offset 0x80, size 0x4
    hkShape* m_pcShape;              // offset 0x84, size 0x4

    static NNS_VECTORFAST m_tosPlayerOffsetFast;

    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST02_RUN_BEE_12070; }

    void init();
    void start(clsPlayerTask* pcPlayerTask);
    void setClearPlayerFlg(clsPlayerTask* pcPlayerTask);
    inline void setMode(enmRunBeeMode eRunBeeMode) { m_eRunBeeMode = eRunBeeMode; }
    inline enmRunBeeMode getMode() const { return m_eRunBeeMode; }
    inline f32 getMinSpeed() const { return m_f32MinSpeed; }
    inline void elaseExexute(clsRunBee*) {}
};

// total size: 0x3B0
class clsRunBee : public clsBeeRoboBase_Obj, public clsGimmickAutoRunObj {
public:
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enum enmMoveMode {
        MOVEMODE_CATCH = 0,
        MOVEMODE_FOLLOW = 1,
        MOVEMODE_MOVE = 2,
        MOVEMODE_RETURN = 3,
        MOVEMODE_END = 4,
    };

    clsRunBee() {}
    virtual ~clsRunBee() {}

    virtual void destroy() {}
    u8 execute() { return 0; }
    u8 draw(NNS_OBJECT* psObject,
            f32 (*psMtxPal)[4][4],
            u32* psNodeStat,
            const f32 (*opaNnViewMtx)[4][4],
            f32 (*psMtxWork)[4][4],
            u32 NodeStatus,
            u32 u32ViewNo);
    void getPathRotQuat(NNS_QUATERNION& rRotQuat) {}

    void searchNextPath();
    void followPlayer();

    static NNS_VECTORFAST tosPlayerOffsetPosFast;

    enmMode m_eMode;                         // offset 0x1D0, size 0x4
    enmMoveMode m_eMoveMode;                 // offset 0x1D4, size 0x4
    u32 m_u32PlayerFlg;                      // offset 0x1D8, size 0x4
    NNS_VECTORFAST m_sPosVecFast;            // offset 0x1E0, size 0x10
    NNS_QUATERNION m_sRotQuat;               // offset 0x1F0, size 0x10
    f32 m_f32FollowFrame;                    // offset 0x200, size 0x4
    clsGimmickPath m_cGimmickPath;           // offset 0x210, size 0x190
    clsRunBee_Obj* m_pcRunBeeObj;            // offset 0x3A0, size 0x4
    clsPendulumControl* m_pcPendulumControl; // offset 0x3A4, size 0x4
};

#endif // ST02RUNBEE_HPP
