#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage10/St10GLinkSnowman.hpp"

NNS_VECTOR clsGLinkSnowman_Object::tosCollisionHalfSizeVec;
f32 clsGLinkSnowman_Object::tof32ClipSqDist = 0.0f;
clsGravityGimmickParam clsGLinkSnowman_Object::t_ocGravityGimmickParam;

void clsGLinkSnowman_Object::draw(NNS_OBJECT* pParam1,
                                  f32 (*)[4][4],
                                  u32* pParam3,
                                  const f32 (*)[4][4],
                                  f32 (*)[4][4],
                                  u32 u32Param6)
{
}

void clsGLinkSnowman_Object::reset()
{
}

void clsGLinkSnowman_Object::main()
{
}

void clsGLinkSnowman_Object::requestDrawBreakEffect()
{
}

void clsGLinkSnowman_Object::callbackContactTriggerRigidBody(
    const hkContactPointConfirmedEvent& rParam1)
{
}

void clsGLinkSnowman_Object::requestDrawContactEffect(const hkContactPoint* pParam1)
{
}

void clsGLinkSnowman_Object::drawEffect(clsPlayerTask* pParam1)
{
}

void clsGLinkSnowman_Object::setData()
{
}

void clsGLinkSnowman_Object::createData()
{
}

void clsGLinkSnowman_Object::destroyData()
{
}

void clsGLinkSnowman_Object::drawShadow(clsModelType_OB& rParam1)
{
}

clsGLinkSnowman_Task::clsGLinkSnowman_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 0x18702)
{
}

void clsGLinkSnowman_Task::reset()
{
}

void clsGLinkSnowman_Task::execute()
{
}

void clsGLinkSnowman_Task::draw()
{
}

void clsGLinkSnowman_Task::setShadowModel(const u8* rsBinInfoI)
{
}

NNS_VECTOR* clsGLinkSnowman_Object::getCollisionHalfSizeVecPtr() const
{
    return 0;
}
