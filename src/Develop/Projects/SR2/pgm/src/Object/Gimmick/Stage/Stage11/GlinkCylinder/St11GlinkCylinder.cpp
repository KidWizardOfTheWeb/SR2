#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/GlinkCylinder/St11GlinkCylinder.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/GlinkCylinder/St11GlinkCylinderManager.hpp"

NNS_VECTOR clsGlinkCylinder_Object::tosCollisionHalfSizeVec = {5.0f, 5.0f, 18.0f};
f32 clsGlinkCylinder_Object::tof32ClipSqDist = 0.0f;
clsGravityGimmickParam clsGlinkCylinder_Object::t_ocGravityGimmickParam;

void clsGlinkCylinder_Object::reset()
{
}

void clsGlinkCylinder_Object::setData()
{
}

void clsGlinkCylinder_Object::createData()
{
}

void clsGlinkCylinder_Object::destroyData()
{
}

void clsGlinkCylinder_Object::drawEffect(clsPlayerTask* pcPlayer)
{
}

void clsGlinkCylinder_Object::requestDrawBreakEffect()
{
}

void clsGlinkCylinder_Object::callbackContactTriggerRigidBody(
    const hkContactPointConfirmedEvent& rsEvent)
{
}

void clsGlinkCylinder_Object::start()
{
}

void clsGlinkCylinder_Object::stepPathFrame()
{
}

void clsGlinkCylinder_Object::callbackGravityEvent()
{
}

void clsGlinkCylinder_Object::main()
{
}

void clsGlinkCylinder_Object::draw(NNS_OBJECT* psObject,
                                   NNS_MATRIX* psMtxPal,
                                   u32* psNodeStat,
                                   const NNS_MATRIX* opaNnViewMtx,
                                   NNS_MATRIX* psMtxWork,
                                   u32 u32ViewNo)
{
}

clsGlinkCylinder_Task::clsGlinkCylinder_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsGlinkCylinder_Task,
                                 clsGlinkCylinderManager_Obj,
                                 clsModelType_OB_TX>(u32ObjectAreaNum, 0x18A88)
{
}

void clsGlinkCylinder_Task::reset()
{
}

void clsGlinkCylinder_Task::execute()
{
}

void clsGlinkCylinder_Task::draw()
{
}
