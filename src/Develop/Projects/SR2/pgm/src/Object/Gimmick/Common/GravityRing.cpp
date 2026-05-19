#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/GravityRing.hpp"

f32 clsGravityRing_Object::tof32ClipSqDist = 0.0f;

void clsGravityRingThroughCollision::contactAlwaysEvent(clsPlayerTask* pcPlayer)
{
}

void clsGravityRing_Object::execute()
{
}

void clsGravityRing_Object::draw(clsModelType_OB_TX_MO_MA& rcModel, f32 (*psMtxWork)[4][4])
{
}

void clsGravityRing_Object::start(clsPlayerTask* pcPlayer)
{
}

void clsGravityRing_Object::setData()
{
}

void clsGravityRing_Object::createData()
{
}

void clsGravityRing_Object::destroyData()
{
}

clsGravityRing_Task::clsGravityRing_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 0x18A88)
{
}

void clsGravityRing_Task::reset()
{
}

void clsGravityRing_Task::execute()
{
}

void clsGravityRing_Task::draw()
{
}

clsGravityRing_Object* clsGravityRing_Task::getGravityRingObjectPtr()
{
    return 0;
}

void clsGravityRing_Task::createModel(stcBinInfo& rsBinInfoI)
{
}
