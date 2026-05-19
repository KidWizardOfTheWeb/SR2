#ifndef PT_DOOR_HPP
#define PT_DOOR_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsPlayerTask;

enum enmPT_DoorMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

// total size: 0xE0
class clsPT_Door_Obj : public clsRigidBodyGimmickObj {
public:
    virtual ~clsPT_Door_Obj() {}
    clsPT_Door_Obj() {}

    virtual void contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject);
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::PT_DOOR_2080; }
    virtual u32 getMultiDrawNum() const { return 0; }
    virtual void reset() {}
    virtual void main() {}
    virtual void contactInterraction(clsRigidBodyGimmickObj* pcObject);
    virtual void callbackGravityEvent();
    virtual void callbackBreakEvent();

    void startBreak(clsPlayerTask* pcHitPlayer);

    static f32 m_tof32CLIP_DISTx2;

    enmPT_DoorMode m_ePtDoorMode; // offset 0xD0, size 0x4
};

// total size: 0x98
class clsPT_Door_Task
    : public clsSingleModelGimmick_Task<clsPT_Door_Task, clsPT_Door_Obj, clsModelType_OB_TX> {
public:
    clsPT_Door_Task(u32 u32ObjectAreaNum)
        : clsSingleModelGimmick_Task<clsPT_Door_Task, clsPT_Door_Obj, clsModelType_OB_TX>(
              u32ObjectAreaNum, 0)
    {
    }
    virtual ~clsPT_Door_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // PT_DOOR_HPP
