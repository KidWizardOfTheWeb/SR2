#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage14/St14SteelFrame.hpp"

f32 clsSteelFrame_Obj::tof32ClipSqDist = 0.0f;

void clsSteelFrame_Obj::requestDrawCrashEffect(const hkContactPoint* pParam1)
{
}

void clsSteelFrame_Obj::setData()
{
}

void clsSteelFrame_Obj::createData()
{
}

void clsSteelFrame_Obj::destroyData()
{
}

clsSteelFrame_Task::clsSteelFrame_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 0x18A88)
{
}

void clsSteelFrame_Task::reset()
{
}

void clsSteelFrame_Task::execute()
{
}

void clsSteelFrame_Task::draw()
{
}

clsSteelFrame_Obj::clsSteelFrame_Obj() : clsRigidBodyGimmickObj()
{
}

clsSteelFrame_Obj::~clsSteelFrame_Obj()
{
}

void clsSteelFrame_Obj::init()
{
}

nspPackId::enm clsSteelFrame_Obj::getPackId() const
{
    return nspPackId::ST14_STEEL_FRAME_24040;
}

void clsSteelFrame_Obj::reset()
{
}

void clsSteelFrame_Obj::main()
{
}

u8 clsSteelFrame_Obj::checkRequestDrawDebris()
{
    return 0;
}
