#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PutCar.hpp"

u32 clsPutCar_Obj::otau32Se_CarCrash[3] = {0x119AE, 0x70AAE, 0x612AE};
f32 clsPutCar_Obj::tof32ClipSqDist = 0.0f;
u32 clsPutCar_Obj::t_ou32DrawNode[2] = {2, 7};

void clsPutCar_Obj::reset()
{
}

void clsPutCar_Obj::main()
{
}

void clsPutCar_Obj::requestDrawBreakEffect()
{
}

void clsPutCar_Obj::setData()
{
}

void clsPutCar_Obj::createData()
{
}

void clsPutCar_Obj::destroyData()
{
}

void clsPutCar_Obj::callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rParam1)
{
}

clsPutCar_Task::clsPutCar_Task(u32 u32ObjectAreaNum)
    : clsMultiModelGimmick_Task<clsPutCar_Task, clsPutCar_Obj, clsMultiObTxModels>(u32ObjectAreaNum,
                                                                                   0)
{
}

void clsPutCar_Task::reset()
{
}

void clsPutCar_Task::execute()
{
}

void clsPutCar_Task::draw()
{
}
