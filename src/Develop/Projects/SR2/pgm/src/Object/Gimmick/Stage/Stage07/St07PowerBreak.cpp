#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07PowerBreak.hpp"

f32 clsSt07PowerBreak_Obj::tof32ClipSqDist = 0.0f;

void clsSt07PowerBreak_Obj::reset()
{
}

void clsSt07PowerBreak_Obj::requestDrawBreakEffect()
{
}

void clsSt07PowerBreak_Obj::setData()
{
}

void clsSt07PowerBreak_Obj::createData()
{
}

void clsSt07PowerBreak_Obj::destroyData()
{
}

void clsSt07PowerBreak_Obj::setCollisionFilter(bool bParam1)
{
}

clsSt07PowerBreak_Task::clsSt07PowerBreak_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsSt07PowerBreak_Task, clsSt07PowerBreak_Obj, clsModelType_OB_TX>(
          u32ObjectAreaNum, 0x18A88)
{
}

void clsSt07PowerBreak_Task::reset()
{
}

void clsSt07PowerBreak_Task::execute()
{
}

void clsSt07PowerBreak_Task::draw()
{
}

clsSt07PowerBreak_Obj::clsSt07PowerBreak_Obj() : clsRigidBodyGimmickObj()
{
}

clsSt07PowerBreak_Obj::~clsSt07PowerBreak_Obj()
{
}

void clsSt07PowerBreak_Obj::init()
{
}

nspPackId::enm clsSt07PowerBreak_Obj::getPackId() const
{
    return nspPackId::ST07_POWER_BREAK_17070;
}

void clsSt07PowerBreak_Obj::main()
{
}
