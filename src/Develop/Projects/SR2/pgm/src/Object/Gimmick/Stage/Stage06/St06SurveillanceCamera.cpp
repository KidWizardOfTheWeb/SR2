#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage06/St06SurveillanceCamera.hpp"

f32 clsSurveillanceCamera_Obj::tof32ClipSqDist = 0.0f;
s32 clsSurveillanceCamera_Obj::toA32RotateAdd;
clsGravityGimmickParam clsSurveillanceCamera_Obj::t_ocGravityGimmickParam;

void clsSurveillanceCamera_Obj::requestDrawBreakEffect()
{
}

void clsSurveillanceCamera_Obj::setData()
{
}

void clsSurveillanceCamera_Obj::createData()
{
}

void clsSurveillanceCamera_Obj::destroyData()
{
}

clsSurveillanceCamera_Task::clsSurveillanceCamera_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 0)
{
}

void clsSurveillanceCamera_Task::reset()
{
}

void clsSurveillanceCamera_Task::execute()
{
}

void clsSurveillanceCamera_Task::draw()
{
}

clsSurveillanceCamera_Obj::clsSurveillanceCamera_Obj() : clsRigidBodyGimmickObj()
{
}

clsSurveillanceCamera_Obj::~clsSurveillanceCamera_Obj()
{
}

void clsSurveillanceCamera_Obj::init()
{
}

nspPackId::enm clsSurveillanceCamera_Obj::getPackId() const
{
    return nspPackId::ST06_SURVEILLANCE_CAMERA_16000;
}

void clsSurveillanceCamera_Obj::reset()
{
}

void clsSurveillanceCamera_Obj::main()
{
}

u8 clsSurveillanceCamera_Obj::checkRequestDrawDebris()
{
    return 0;
}

void clsSurveillanceCamera_Obj::callbackContactTriggerRigidBody(
    const hkContactPointConfirmedEvent& rParam1)
{
}
