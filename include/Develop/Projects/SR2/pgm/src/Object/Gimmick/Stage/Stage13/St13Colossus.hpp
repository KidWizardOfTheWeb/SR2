#ifndef ST13COLOSSUS_HPP
#define ST13COLOSSUS_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"

class clsSe3DControl;

enum enmColossusMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

class clsColossus_Obj : public clsRigidBodyGimmickObj {
public:
    clsColossus_Obj();
    virtual ~clsColossus_Obj();

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rEvent);

    nspPackId::enm getPackId() const { return nspPackId::ST13_COLOSSUS_23030; }

    static f32 tof32ClipSqDist;

    // Members
    enmColossusMode m_eMode;         // offset 0xD0, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xD4, size 0x4
    u8 m_u8ContactSeCount;           // offset 0xD8, size 0x1
};

// total size: 0x98
class clsColossus_Task
    : public clsSingleModelGimmick_Task<clsColossus_Task, clsColossus_Obj, clsModelType_OB_TX> {
public:
    clsColossus_Task(u32 u32ObjectAreaNum);
    virtual ~clsColossus_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST13COLOSSUS_HPP
