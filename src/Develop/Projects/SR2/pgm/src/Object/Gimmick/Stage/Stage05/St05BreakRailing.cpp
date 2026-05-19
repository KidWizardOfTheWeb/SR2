#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage05/St05BreakRailing.hpp"

void clsBreakRailingThrCol::contactAlwaysEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

void clsBreakRailingThrCol::contactRemoveEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

void clsBreakRailing_Obj::reset()
{
}

void clsBreakRailing_Obj::setData()
{
}

void clsBreakRailing_Obj::createData()
{
}

void clsBreakRailing_Obj::destroyData()
{
}

void clsBreakRailing_Obj::checkThrough(clsPlayerTask* pcPlayerTask)
{
}

void clsBreakRailing_Task::reset()
{
}

void clsBreakRailing_Task::createModel(stcBinInfo& rBinInfo)
{
}

void clsBreakRailing_Task::execute()
{
}

void clsBreakRailing_Task::draw()
{
}

clsBreakRailing_Task::clsBreakRailing_Task(u32 param)
    : clsBaseGimmickBody<clsBreakRailing_Task, clsBreakRailing_Obj, clsModelType_OB>(0, 0)
{
}

clsBreakRailing_Task::~clsBreakRailing_Task()
{
}
