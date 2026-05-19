#ifndef CATAPULT_HPP
#define CATAPULT_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsPlayerTask;

enum enmCatapultMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

// Forward-declared for clsCatapultThroughCollision cross-reference
class clsCatapult_Obj;

// total size: 0xC
class clsCatapultThroughCollision : public clsBaseThroughCollision {
public:
    virtual ~clsCatapultThroughCollision() {}
    virtual void contactAlwaysEvent(clsPlayerTask* pcPlayer);

    clsCatapult_Obj* m_pcCatapult; // offset 0x8, size 0x4
};

// total size: 0x160
class clsCatapult_Obj : public clsRigidBodyGimmickObj {
public:
    enum enmAiMode {
        AIMODE_WAIT = 0,
        AIMODE_OPEN = 1,
        AIMODE_OPEN_WAIT = 2,
        AIMODE_CLOSE = 3,
    };

    virtual ~clsCatapult_Obj() {}
    clsCatapult_Obj() {}

    virtual void contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject);
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::CATAPULT_2130; }
    virtual void reset();
    virtual void init() {}
    virtual void main();

    enmAiMode getAiMode() const { return m_eAiMode; }

    void setCollisionFilter(bool bFlag);
    u8 stepMotionFrame();
    void checkShooting(clsPlayerTask* pcPlayerTask, u32 u32TaskNum);
    void setAiMode(enmAiMode eMode);

    static f32 tof32ClipSqDist;

    enmCatapultMode m_eMode;                    // offset 0xD0, size 0x4
    f32 m_f32Scale;                             // offset 0xD4, size 0x4
    f32 m_f32PushSpeed;                         // offset 0xD8, size 0x4
    f32 m_f32Angle;                             // offset 0xDC, size 0x4
    enmAiMode m_eAiMode;                        // offset 0xE0, size 0x4
    f32 m_f32NowAngle;                          // offset 0xE4, size 0x4
    hkVector4 m_cUpSpeed;                       // offset 0xF0, size 0x10
    hkVector4 m_cDownSpeed;                     // offset 0x100, size 0x10
    NNS_QUATERNION m_sInitRotQuat;              // offset 0x110, size 0x10
    clsPlayerTask* m_pcPlayerTask[8];           // offset 0x120, size 0x20
    clsCatapultThroughCollision* m_pcCollision; // offset 0x140, size 0x4
    s32 m_s32HitCount;                          // offset 0x144, size 0x4
    f32 m_f32MoveAngle;                         // offset 0x148, size 0x4
    f32 m_f32NodeAngle;                         // offset 0x14C, size 0x4
    f32 m_f32MatMotionFrame;                    // offset 0x150, size 0x4
    f32 m_f32MatMotionAcceleRate;               // offset 0x154, size 0x4
};

// total size: 0xAC
class clsCatapult_Task : public clsSingleModelGimmick_Task<clsCatapult_Task,
                                                           clsCatapult_Obj,
                                                           clsModelType_OB_TX_MO_MA> {
public:
    clsCatapult_Task(u32 u32ObjectAreaNum);
    virtual ~clsCatapult_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI);
};

#endif // CATAPULT_HPP
