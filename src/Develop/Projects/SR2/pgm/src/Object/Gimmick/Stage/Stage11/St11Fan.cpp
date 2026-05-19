#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/St11Fan.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

NNS_VECTORFAST clsFan_Task::m_tosPartsOffsetFast[12] = {
    {0.059f, 4.48f, 0.349f, 1.0f},
    {0.059f, 4.48f, 0.349f, 1.0f},
    {0.059f, 4.48f, 0.349f, 1.0f},
    {0.059f, 4.48f, 0.349f, 1.0f},
    {0.059f, 4.48f, 0.349f, 1.0f},
    {0.059f, 4.48f, 0.349f, 1.0f},
    {0.059f, 4.48f, 0.349f, 1.0f},
    {0.059f, 4.48f, 0.349f, 1.0f},
    {0.059f, 4.48f, 0.349f, 1.0f},
    {0.059f, 4.48f, 0.349f, 1.0f},
    {0.059f, 4.48f, 0.349f, 1.0f},
    {0.059f, 4.48f, 0.349f, 1.0f},
};

NNS_VECTOR clsFan_Task::m_tosThroughCollisionPosVec[5] = {
    {-560.0f, 19.0f, 30.0f},
    {-560.0f, 19.0f, 30.0f},
    {-560.0f, 19.0f, 30.0f},
    {-560.0f, 19.0f, 30.0f},
    {-560.0f, 19.0f, 30.0f},
};

f32 clsFan_Task::m_tof32ThroughCollisionRotY[5] = {80.0f, 0.0f, 0.0f, 0.0f, 0.0f};

void clsFanThroughCollision::contactTriggerEvent(clsPlayerTask* pcPlayer)
{
}

void clsFan_Parts::reset()
{
}

void clsFan_Parts::createData()
{
}

void clsFan_Parts::destroyData()
{
}

void clsFan_Parts::requestDrawBreakEffect()
{
}

void clsFan_Parts::requestDrawCrashEffect(const hkContactPoint* pParam1)
{
}

void clsFan_Parts::callbackCrashEvent()
{
}

void clsFan_Parts::contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject)
{
}

void clsFan_Parts::main()
{
}

void clsFan_Obj::createData()
{
}

void clsFan_Obj::destroyData()
{
}

clsFan_Task::clsFan_Task(u32 u32ObjectAreaNum)
    : clsBaseGimmickBody<clsFan_Task, clsFan_Obj, clsFanModel>(u32ObjectAreaNum, 0)
{
}

void clsFan_Task::reset()
{
}

void clsFan_Task::createModel(stcBinInfo& rsBinInfoI)
{
}

void clsFan_Task::execute()
{
}

void clsFan_Task::draw()
{
}
