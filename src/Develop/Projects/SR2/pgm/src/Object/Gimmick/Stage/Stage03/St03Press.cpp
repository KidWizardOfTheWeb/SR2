#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03Press.hpp"

f32 tofFallLength;
f32 tofRiseFrame;
f32 tofFallFrame;
f32 tofRiseWaitFrame;
f32 tofFallWaitFrame;
f32 tofRiseSpeed;
f32 tofFallSPeed;

NNS_VECTOR clsPress_Task::m_tosThroughCollisionPosVec[5] = {
    {135.0f, -30.0f, 144.0f},
};
f32 clsPress_Task::m_tof32ThroughCollisionRotY[5] = {89.0f, 58.0f, 131.0f};

void clsPressCollision::contactTriggerEvent(clsPlayerTask* pcPlayer)
{
}

void clsPressCollision::contactRemoveEvent(clsPlayerTask* pParam1)
{
}

void clsPress_Obj::createData()
{
}

void clsPress_Obj::destroyData()
{
}

void clsPress_Obj::main()
{
}

clsPress_Task::clsPress_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsPress_Task, clsPress_Obj, clsModelType_OB_TX>(u32ObjectAreaNum,
                                                                                  0)
{
}

void clsPress_Task::reset()
{
}

void clsPress_Task::createThroughCollision(enmThroughCollisionNum eColissionNum,
                                           clsPressCollision::enmMode eMode)
{
}

void clsPress_Task::execute()
{
}

void clsPress_Task::draw()
{
}
