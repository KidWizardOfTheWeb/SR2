#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage06/St06BlockadeObj.hpp"

f32 clsBlockadeObj_Obj::tof32ClipSqDist = 0.0f;

void clsBlockadeObj_Obj::requestDrawBreakEffect()
{
}

void clsBlockadeObj_Obj::setData()
{
}

void clsBlockadeObj_Obj::createData()
{
}

void clsBlockadeObj_Obj::destroyData()
{
}

clsBlockadeObj_Task::clsBlockadeObj_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 0x18A88)
{
}

void clsBlockadeObj_Task::reset()
{
}

void clsBlockadeObj_Task::execute()
{
}

void clsBlockadeObj_Task::draw()
{
}

clsBlockadeObj_Obj::clsBlockadeObj_Obj()
{
}

clsBlockadeObj_Obj::~clsBlockadeObj_Obj()
{
}

inline void clsBlockadeObj_Obj::reset()
{
}

inline void clsBlockadeObj_Obj::main()
{
}

inline u8 clsBlockadeObj_Obj::checkRequestDrawDebris()
{
    return 0;
}

inline nspPackId::enm clsBlockadeObj_Obj::getPackId() const
{
    return nspPackId::ST06_BLOCKADEOBJ_16010;
}
