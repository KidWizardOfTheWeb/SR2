#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02Plant.hpp"

u32 clsPlant_Obj::otau32Se_Glass[2] = {265134, 267182};
f32 clsPlant_Obj::tof32ClipSqDist = 0.0f;

u8 clsPlant_Obj::checkRequestDrawDebris()
{
    return m_cBreakControl.isBreak();
}

void clsPlant_Obj::requestDrawBreakEffect()
{
}

void clsPlant_Obj::setData()
{
}

void clsPlant_Obj::createData()
{
}

void clsPlant_Obj::destroyData()
{
}

clsPlant_Task::clsPlant_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsPlant_Task, clsPlant_Obj, clsModelType_OB_TX>(u32ObjectAreaNum,
                                                                                  0)
{
}

void clsPlant_Task::reset()
{
}

void clsPlant_Task::execute()
{
}

void clsPlant_Task::draw()
{
}

clsPlant_Obj::~clsPlant_Obj()
{
}
