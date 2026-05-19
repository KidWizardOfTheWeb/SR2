#ifndef PT_DOOR2_HPP
#define PT_DOOR2_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

enum enmPT_Door2Mode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

class clsPT_Door2_Obj : public clsRigidBodyGimmickObj {
public:
    clsPT_Door2_Obj();

    virtual ~clsPT_Door2_Obj() {}
    virtual nspPackId::enm getPackId() const { return nspPackId::PT_DOOR_2081; }
    virtual void main() {}

    virtual void reset();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void callbackCrashEvent();

    enum enmPT_Door2Mode m_ePtDoorMode; // offset 0xD0, size 0x4
};

// total size: 0x98
class clsPT_Door2_Task
    : public clsSingleModelGimmick_Task<clsPT_Door2_Task, clsPT_Door2_Obj, clsModelType_OB_TX> {
public:
    clsPT_Door2_Task(u32 u32ObjectAreaNum)
        : clsSingleModelGimmick_Task<clsPT_Door2_Task, clsPT_Door2_Obj, clsModelType_OB_TX>(
              u32ObjectAreaNum, 0)
    {
    }
    virtual ~clsPT_Door2_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // PT_DOOR2_HPP
