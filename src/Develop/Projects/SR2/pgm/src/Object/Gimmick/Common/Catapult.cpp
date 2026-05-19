#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/Catapult.hpp"

f32 clsCatapult_Obj::tof32ClipSqDist = 0.0f;

void clsCatapultThroughCollision::contactAlwaysEvent(clsPlayerTask* pcPlayer)
{
}

void clsCatapult_Obj::reset()
{
}

void clsCatapult_Obj::main()
{
}

void clsCatapult_Obj::setAiMode(clsCatapult_Obj::enmAiMode eMode)
{
}

void clsCatapult_Obj::setData()
{
}

void clsCatapult_Obj::createData()
{
}

void clsCatapult_Obj::destroyData()
{
}

void clsCatapult_Obj::contactTriggerEvent(hkContactPoint* pcObject, clsObject* pcOther)
{
}

void clsCatapult_Obj::checkShooting(clsPlayerTask* pcPlayerTask, u32 u32TaskNum)
{
}

u8 clsCatapult_Obj::stepMotionFrame()
{
    return 0;
}

void clsCatapult_Obj::setCollisionFilter(bool bFlag)
{
}

clsCatapult_Task::clsCatapult_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsCatapult_Task, clsCatapult_Obj, clsModelType_OB_TX_MO_MA>(
          u32ObjectAreaNum, 0)
{
}

void clsCatapult_Task::reset()
{
}

void clsCatapult_Task::execute()
{
}

void clsCatapult_Task::draw()
{
}

void clsCatapult_Task::createModel(stcBinInfo& rsBinInfoI)
{
}
