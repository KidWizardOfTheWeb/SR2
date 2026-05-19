#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08Road.hpp"

void clsRoad_Obj::setData()
{
}

void clsRoad_Obj::createData()
{
}

void clsRoad_Obj::destroyData()
{
}

u8 clsRoad_Obj::setCar(clsRoadCarControl* pcCar)
{
    return 0;
}

void clsRoad_Obj::contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObj)
{
}

u8 clsRoad_Obj::sortPathRate()
{
    return 0;
}

void clsRoad_Obj::requestStop()
{
}

void clsRoad_Obj::requestMove()
{
}

void clsRoad_Obj::execute()
{
}

void clsRoad_Task::reset()
{
}

void clsRoad_Task::execute()
{
}

void clsRoad_Task::draw()
{
}

stcRoadInfo* clsRoad_Obj::getRoadInfo() const
{
    return 0;
}

bool clsRoad_Obj::clsCarObjectLenCmp::operator()(const clsRoadCarControl* a,
                                                 const clsRoadCarControl* b) const
{
    return false;
}

stcRoadInfo clsRoad_Obj::t_astcRoadInfoTbl[6];
f32 clsRoad_Obj::t_of32AccleFrame = 30.0f;
f32 clsRoad_Obj::t_of32SlowDownFrame;
