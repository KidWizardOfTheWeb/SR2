#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/ProductionRobo/ProductionRoboManager.hpp"

void clsProductionRoboCollision::contactTriggerEvent(clsPlayerTask* pcPlayer)
{
}

void clsProductRoboManager_Obj::setData()
{
}

void clsProductRoboManager_Obj::createData()
{
}

void clsProductRoboManager_Obj::destroyData()
{
}

clsProductionRobo_Task::clsProductionRobo_Task(u32 u32ObjectAreaNum)
    : clsBaseGimmickBody<clsProductionRobo_Task, clsProductRoboManager_Obj, clsSecurityRoboModels>(
          u32ObjectAreaNum, u32ObjectAreaNum)
{
}

void clsProductionRobo_Task::reset()
{
}

void clsProductionRobo_Task::createModel(stcBinInfo& rsBinInfoI)
{
}

void clsProductionRobo_Task::execute()
{
}

void clsProductionRobo_Task::draw()
{
}

clsProductionRobo_Task::~clsProductionRobo_Task()
{
}

hkShape* clsProductionRobo_Task::getShapeRobo()
{
    return m_pcShapeRobo;
}

f32 clsProductionRobo_Task::getMotionEndFrame()
{
    return 0.0f;
}
