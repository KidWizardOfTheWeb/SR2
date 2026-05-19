#ifndef ST15BREAKFLOOR_HPP
#define ST15BREAKFLOOR_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"

class clsBreakFloor_Obj : public clsRigidBodyGimmickObj {
public:
    enum enmBreakFloorMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
        MODE_BREAK = 2,
    };

    clsBreakFloor_Obj();
    virtual ~clsBreakFloor_Obj();

    virtual void setData();
    virtual void createData();
    virtual void destroyData();

    virtual void reset();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void callbackCrashEvent();
    virtual u8 checkRequestDrawDebris();

    nspPackId::enm getPackId() const { return nspPackId::ST15_BREAK_FLOOR_25070; }

    static f32 tof32ClipSqDist;

    // Members
    enmBreakFloorMode m_eBreakFloorMode; // offset 0xD0, size 0x4
    u32 m_u32LinkMapUserDataNo;          // offset 0xD4, size 0x4
};

// total size: 0x98
class clsBreakFloor_Task
    : public clsSingleModelGimmick_Task<clsBreakFloor_Task, clsBreakFloor_Obj, clsModelType_OB_TX> {
public:
    clsBreakFloor_Task(u32 u32ObjectAreaNum);
    virtual ~clsBreakFloor_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST15BREAKFLOOR_HPP
