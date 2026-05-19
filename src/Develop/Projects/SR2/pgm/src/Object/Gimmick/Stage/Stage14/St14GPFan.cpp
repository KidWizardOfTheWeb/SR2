#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage14/St14GPFan.hpp"

f32 clsGPFan_Obj::tof32ClipSqDist = 0.0f;

void clsGPFan_Obj::requestDrawBreakEffect()
{
}

void clsGPFan_Obj::contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject)
{
}

void clsGPFan_Obj::setData()
{
}

void clsGPFan_Obj::createData()
{
}

void clsGPFan_Obj::destroyData()
{
}

clsGPFan_Task::clsGPFan_Task(u32 u32ObjectAreaNum)
    : clsBaseGimmickBody<clsGPFan_Task, clsGPFan_Obj, clsGPFanModel>(u32ObjectAreaNum,
                                                                     u32ObjectAreaNum)
{
}

void clsGPFan_Task::createModel(stcBinInfo& rsBinInfoI)
{
}

void clsGPFan_Task::reset()
{
}

void clsGPFan_Task::execute()
{
}

void clsGPFan_Task::draw()
{
}

void clsGPFan_Obj::main()
{
}

nspPackId::enm clsGPFan_Obj::getPackId() const
{
    return nspPackId::ST14_FAN_24000;
}

u32 clsGPFan_Obj::getTexNo() const
{
    return 0;
}

u8 clsGPFan_Obj::checkRequestDrawDebris()
{
    return 0;
}

clsGPFan_Task::~clsGPFan_Task()
{
}

void clsGPFan_Task::setDrawTexNo(u32 param_1)
{
}
