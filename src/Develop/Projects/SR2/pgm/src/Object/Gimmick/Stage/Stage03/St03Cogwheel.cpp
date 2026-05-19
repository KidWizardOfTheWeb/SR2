#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03Cogwheel.hpp"

// clsCogwheelThroughCollision statics (none)

namespace {
f32 toaf32MissionRotAngle[3] = {20.0f, -20.0f, 20.0f};
}

NNS_VECTORFAST clsCogwheel_Task::m_tosPartsOffsetFast[12] = {
    {-0.0022f, 7.2471f, 0.0f, 1.0f},
    {-6.2773f, 3.6217f, 0.0f, 1.0f},
    {-6.2751f, -3.6254f, 0.0f, 1.0f},
    {0.0022f, -7.2471f, 0.0f, 1.0f},
    {6.2773f, -3.6217f, 0.0f, 1.0f},
    {6.2751f, 3.6254f, 0.0f, 1.0f},
    {-0.0025f, 13.785f, 0.0f, 1.0f},
    {-11.9393f, 6.8904f, 0.0f, 1.0f},
    {-11.9369f, -6.8946f, 0.0f, 1.0f},
    {0.0025f, -13.785f, 0.0f, 1.0f},
    {11.9393f, -6.8904f, 0.0f, 1.0f},
    {11.9369f, 6.8946f, 0.0f, 1.0f},
};

NNS_VECTOR clsCogwheel_Task::m_tosThroughCollisionPosVec[5] = {
    {538.0f, -10.0f, -61.0f},
    {648.0f, -12.0f, 15.0f},
    {640.0f, -8.0f, -99.0f},
    {1027.6f, 0.0f, 103.0f},
    {1042.0f, 0.3f, 77.8f},
};

f32 clsCogwheel_Task::m_tof32ThroughCollisionRotY[5] = {156.0f, 131.0f, 61.0f, -30.0f, -30.0f};

void clsCogwheelThroughCollision::contactTriggerEvent(clsPlayerTask* pParam1)
{
}

void clsCogwheel_Parts::reset()
{
}

void clsCogwheel_Parts::createData()
{
}

void clsCogwheel_Parts::destroyData()
{
}

void clsCogwheel_Parts::requestDrawBreakEffect()
{
}

void clsCogwheel_Parts::requestDrawCrashEffect(const hkContactPoint* pParam1)
{
}

void clsCogwheel_Parts::callbackCrashEvent()
{
}

void clsCogwheel_Parts::contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2)
{
}

void clsCogwheel_Parts::main()
{
}

void clsCogwheel_Obj::createData()
{
}

void clsCogwheel_Obj::destroyData()
{
}

void clsCogwheel_Obj::debugDrawCollision()
{
}

clsCogwheel_Task::clsCogwheel_Task(u32 packId)
    : clsSingleModelGimmick_Task<clsCogwheel_Task, clsCogwheel_Obj, clsCogWhellModel>(packId, 0)
{
}

void clsCogwheel_Task::reset()
{
}

void clsCogwheel_Task::createThroughCollision(enmThroughCollisionNum,
                                              clsCogwheelThroughCollision::enmMode,
                                              u8 u8Param3)
{
}

void clsCogwheel_Task::createModel(stcBinInfo& rParam1)
{
}

f32 clsCogwheel_Task::getMissionRot(clsCogwheel_Obj* pParam1)
{
    return 0.0f;
}

void clsCogwheel_Task::execute()
{
}

void clsCogwheel_Task::draw()
{
}

clsCogwheelThroughCollision::clsCogwheelThroughCollision()
{
}
