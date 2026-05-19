#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02Ivy.hpp"

void clsIvy_Obj::createData()
{
}

void clsIvy_Obj::destroyData()
{
}

void clsIvy_Obj::init()
{
}

void clsIvy_Obj::reset()
{
}

void clsIvy_Obj::contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

void clsIvy_Obj::setLandingGround()
{
}

clsIvy_Task::clsIvy_Task(u32 u32ObjectAreaNum) : clsSingleModelGimmick_Task(0, 0)
{
}

void clsIvy_Task::reset()
{
}

void clsIvy_Task::execute()
{
}

void clsIvy_Task::draw()
{
}

void clsIvy_Task::shootPlayerToIvy(clsPlayerTask* pcPlayerTask)
{
}

clsIvy_Obj::clsIvy_Obj(u32 u32ObjectAreaNum)
{
}

clsIvy_Obj::~clsIvy_Obj()
{
}

nspPackId::enm clsIvy_Obj::getPackId() const
{
    return nspPackId::ST02_IVY_12000;
}

void clsIvy_Obj::shootPlayerToGround()
{
}

clsIvy_Task::~clsIvy_Task()
{
}
