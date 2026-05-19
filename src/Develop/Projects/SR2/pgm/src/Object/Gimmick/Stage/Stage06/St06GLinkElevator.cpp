#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage06/St06GLinkElevator.hpp"

namespace {

NNS_VECTORFAST toasPointVecFast[14][2];

} // namespace

NNS_VECTOR clsGLinkElevator_Object::tosCollisionHalfSizeVec = {5.0f, 5.0f, 10.0f};
f32 clsGLinkElevator_Object::tof32ClipSqDist = 0.0f;
clsGravityGimmickParam clsGLinkElevator_Object::t_ocSt6GravityGimmickParam;
clsGravityGimmickParam clsGLinkElevator_Object::t_ocSt14GravityGimmickParam;

void clsGLinkElevator_Object::reset()
{
}

void clsGLinkElevator_Object::main()
{
}

void clsGLinkElevator_Object::mainGravity()
{
}

void clsGLinkElevator_Object::mainCrash()
{
}

void clsGLinkElevator_Object::requestDrawBreakEffect()
{
}

void clsGLinkElevator_Object::drawEffect(clsPlayerTask* pcPlayer)
{
}

void clsGLinkElevator_Object::setData()
{
}

void clsGLinkElevator_Object::createData()
{
}

void clsGLinkElevator_Object::destroyData()
{
}

clsGLinkElevator_Task::clsGLinkElevator_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsGLinkElevator_Task,
                                 clsGLinkElevator_Object,
                                 clsModelType_OB_TX>(u32ObjectAreaNum, 0)
{
}

void clsGLinkElevator_Task::reset()
{
}

void clsGLinkElevator_Task::execute()
{
}

void clsGLinkElevator_Task::draw()
{
}

void clsGLinkElevator_Object::callbackContactTriggerRigidBody(
    const hkContactPointConfirmedEvent& rsEventI)
{
}

void clsGLinkElevator_Object::callbackGravityEvent()
{
}
