#ifndef ST03PRESS_HPP
#define ST03PRESS_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "types.h"

class clsSe3DControl;
class clsPress_Task;

enum enmPressMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

enum enmPressState {
    STATE_SLEEP = 0,
    STATE_SAFE_STOP = 1,
    STATE_STARTWAIT = 2,
    STATE_FALL = 3,
    STATE_FALL_WAIT = 4,
    STATE_RISE = 5,
    STATE_RISE_WAIT = 6,
};

// total size: 0x14
class clsPressCollision : public clsBaseThroughCollision {
public:
    enum enmMode {
        MODE_NONE = 0,
        MODE_START = 1,
        MODE_STOP = 2,
    };

    clsPressCollision() {}
    virtual ~clsPressCollision() {}

    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);
    virtual void contactRemoveEvent(clsPlayerTask* pParam1);

    enmMode m_eMode;               // offset 0x8, size 0x4
    clsPress_Task* m_pcPress_Task; // offset 0xC, size 0x4
    u32 m_u32ThroughCount;         // offset 0x10, size 0x4
};

// total size: 0x100
class clsPress_Obj : public clsRigidBodyGimmickObj {
public:
    clsPress_Obj() {}
    virtual ~clsPress_Obj() {}

    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST03_PRESS_13010; }
    virtual void reset() {}
    virtual void init() {}
    virtual void main();

    enmPressMode getMode() const { return m_ePressMode; }
    enmPressState getState() const { return m_ePressState; }

    enmPressMode m_ePressMode;       // offset 0xD0, size 0x4
    enmPressState m_ePressState;     // offset 0xD4, size 0x4
    f32 m_f32StartWaitFrame;         // offset 0xD8, size 0x4
    f32 m_f32FallSafeY;              // offset 0xDC, size 0x4
    clsPressCollision m_cCollision;  // offset 0xE0, size 0x14
    clsSe3DControl* m_pcSe3DControl; // offset 0xF4, size 0x4
};

// total size: 0xDC
class clsPress_Task
    : public clsSingleModelGimmick_Task<clsPress_Task, clsPress_Obj, clsModelType_OB_TX> {
public:
    enum enmThroughCollisionNum {
        THROUGH_COLLISION_START_00 = 0,
        THROUGH_COLLISION_START_01 = 1,
        THROUGH_COLLISION_START_02 = 2,
        THROUGH_COLLISION_STOP = 3,
        THROUGH_COLLISION_MAX = 4,
    };

    // Note: enmState collision with NearData.hpp and other owners; nested for the clsPress_Task
    // layout.
    enum enmState {
        STATE_START = 0,
        STATE_STOP = 1,
    };

    clsPress_Task(u32 u32ObjectAreaNum);
    virtual ~clsPress_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();

    enmState getState() const { return m_eState; }
    enmPressState getObjState(u32 u32ObjectNo) { return STATE_SLEEP; }
    void createThroughCollision(enmThroughCollisionNum eColissionNum,
                                clsPressCollision::enmMode eMode);

    static NNS_VECTOR m_tosThroughCollisionPosVec[5];
    static f32 m_tof32ThroughCollisionRotY[5];

    hkShape* m_pcShape;                 // offset 0x94, size 0x4
    clsPressCollision m_acCollision[3]; // offset 0x98, size 0x3C
    enmState m_eState;                  // offset 0xD4, size 0x4
    u32 m_u32PlayerFlg;                 // offset 0xD8, size 0x4
};

#endif // ST03PRESS_HPP
