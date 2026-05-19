#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/st11SecurityRoboManager.hpp"

stcRoboArray clsSecurityRoboManager_Obj::m_oastcRoboArray[3];

void clsSecurityRoboCollision::contactTriggerEvent(clsPlayerTask* pcPlayer)
{
}

void clsSecurityRoboManager_Obj::setData()
{
}

void clsSecurityRoboManager_Obj::createData()
{
}

void clsSecurityRoboManager_Obj::destroyData()
{
}

clsSecurityRoboManager_Task::clsSecurityRoboManager_Task(u32 u32ObjectAreaNum)
    : clsBaseGimmickBody<clsSecurityRoboManager_Task,
                         clsSecurityRoboManager_Obj,
                         clsSt11SecurityRoboModels>(0, 0)
{
}

void clsSecurityRoboManager_Task::reset()
{
}

void clsSecurityRoboManager_Task::createModel(stcBinInfo& rsBinInfoI)
{
}

void clsSecurityRoboManager_Task::execute()
{
}

void clsSecurityRoboManager_Task::draw()
{
}
