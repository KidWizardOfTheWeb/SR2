#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage13/St13Pillar.hpp"

f32 clsPillar_Obj::tof32ClipSqDist = 0.0f;

void clsPillarThroughCollision::contactTriggerEvent(clsPlayerTask* pParam1)
{
}

void clsPillarThroughCollision::contactRemoveEvent(clsPlayerTask* pParam1)
{
}

void clsPillar_Obj::reset()
{
}

void clsPillar_Obj::setData()
{
}

void clsPillar_Obj::createData()
{
}

void clsPillar_Obj::destroyData()
{
}

void clsPillar_Obj::CountUp()
{
}

void clsPillar_Obj::CheckObjRemove()
{
}

clsPillar_Task::clsPillar_Task(u32 u32ObjectAreaNum)
    : clsMultiModelGimmick_Task<clsPillar_Task, clsPillar_Obj, clsMultiObTxModels>(u32ObjectAreaNum,
                                                                                   0)
{
}

void clsPillar_Task::reset()
{
}

void clsPillar_Task::execute()
{
}

void clsPillar_Task::draw()
{
}

void clsPillar_Obj::setState(enmPillarState)
{
}

clsPillar_Obj::enmPillarState clsPillar_Obj::getState() const
{
    return PILLAR_STATE_MAIN;
}

void clsPillar_Obj::setMode(enmPillarMode)
{
}

void clsPillar_Obj::init()
{
}

clsPillar_Obj::enmPillarMode clsPillar_Obj::getMode() const
{
    return PILLAR_MODE_INIT;
}
