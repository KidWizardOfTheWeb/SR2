#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03PowerBreak.hpp"

f32 clsPowerBreak_Obj::tof32ClipSqDist = 0.0f;

clsGravityGimmickParam clsPowerBreak_Obj::t_ocGravityGimmickParam = {
    {}, {}, 10.0f, 6.0f, 10.0f, 60.0f,       0.5f,  25.0f / 18.0f, 60.0f, 30.0f,
    {}, {}, {},    6.0f, 2.0f,  5.0f / 6.0f, 20.0f, 30.0f,         1820,  0.035f};

void clsPowerBreak_Obj::reset()
{
}

void clsPowerBreak_Obj::main()
{
}

void clsPowerBreak_Obj::requestDrawBreakEffect()
{
}

void clsPowerBreak_Obj::setData()
{
}

void clsPowerBreak_Obj::createData()
{
}

void clsPowerBreak_Obj::destroyData()
{
}

clsPowerBreak_Task::clsPowerBreak_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsPowerBreak_Task, clsPowerBreak_Obj, clsModelType_OB_TX>(
          u32ObjectAreaNum, 0x18A88)
{
}

void clsPowerBreak_Task::reset()
{
}

void clsPowerBreak_Task::execute()
{
}

void clsPowerBreak_Task::draw()
{
}

clsPowerBreak_Obj::clsPowerBreak_Obj()
{
}

clsPowerBreak_Obj::~clsPowerBreak_Obj()
{
}

inline nspPackId::enm clsPowerBreak_Obj::getPackId() const
{
    return nspPackId::ST03_POWER_BREAK_13060;
}
