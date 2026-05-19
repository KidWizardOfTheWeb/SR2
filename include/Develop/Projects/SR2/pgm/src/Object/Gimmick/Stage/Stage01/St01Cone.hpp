#ifndef ST01CONE_HPP
#define ST01CONE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsSe3DControl;

// total size: 0xE0
class clsCone_Obj : public clsRigidBodyGimmickObj {
public:
    clsCone_Obj();
    virtual ~clsCone_Obj();

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST01_CONE_11194; }
    virtual void requestDrawBreakEffect();
    virtual void callbackCrashEvent();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rEvent);

    static u32 otau32Se_Cone[2];

    // Members
    clsSe3DControl* m_pcSe3DControl; // offset 0xD0, size 0x4
    u8 m_u8ContactSeCount;           // offset 0xD4, size 0x1
};

// total size: 0x98
class clsCone_Task
    : public clsSingleModelGimmick_Task<clsCone_Task, clsCone_Obj, clsModelType_OB_TX> {
public:
    clsCone_Task(u32 u32ObjectAreaNum);
    virtual ~clsCone_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST01CONE_HPP
