#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage13/St13Catapult.hpp"

static f32 tof32RotY;

NNS_VECTOR clsSt13CatapultThroughCollision::tosPosVec = {-162.0f, 30.0f, 189.0f};

void clsSt13CatapultThroughCollision::contactTriggerEvent(clsPlayerTask* pcPlayer)
{
}

void clsSt13Catapult_Obj::createData()
{
}

void clsSt13Catapult_Obj::destroyData()
{
}

void clsSt13Catapult_Obj::init()
{
}

void clsSt13Catapult_Obj::reset()
{
}

void clsSt13Catapult_Obj::contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

clsSt13Catapult_Task::clsSt13Catapult_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsSt13Catapult_Task, clsSt13Catapult_Obj, clsModelType_OB_TX_MO>(
          0, 0)
{
}

void clsSt13Catapult_Task::execute()
{
}

void clsSt13Catapult_Task::reset()
{
}

void clsSt13Catapult_Task::draw()
{
}

void clsSt13Catapult_Task::GoToCatapult(clsPlayerTask* pcPlayer)
{
}

clsSt13Catapult_Obj::clsSt13Catapult_Obj()
{
}

clsSt13Catapult_Obj::~clsSt13Catapult_Obj()
{
}

void clsSt13Catapult_Obj::shootPlayerToGround()
{
}

void clsSt13Catapult_Obj::movePlayer()
{
}
