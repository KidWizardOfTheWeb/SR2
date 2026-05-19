#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage12/St12MotionObj.hpp"

f32 clsSt12MotionObj_Obj::tof32ClipSqDist = 0.0f;

void clsSt12MotionObjThroughCollision::contactTriggerEvent(clsPlayerTask* pParam1)
{
}

void clsSt12MotionObj_Obj::reset()
{
}

void clsSt12MotionObj_Obj::setData()
{
}

void clsSt12MotionObj_Obj::createData()
{
}

void clsSt12MotionObj_Obj::destroyData()
{
}

clsSt12MotionObj_Task::clsSt12MotionObj_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsSt12MotionObj_Task,
                                 clsSt12MotionObj_Obj,
                                 clsModelType_OB_TX_MO_MA>(u32ObjectAreaNum, 0x18A88)
{
}

void clsSt12MotionObj_Task::reset()
{
}

void clsSt12MotionObj_Task::execute()
{
}

void clsSt12MotionObj_Task::draw()
{
}
