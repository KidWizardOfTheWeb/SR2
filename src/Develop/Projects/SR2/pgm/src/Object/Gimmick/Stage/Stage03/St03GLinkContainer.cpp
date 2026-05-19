#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03GLinkContainer.hpp"

f32 clsGLinkContainer_Object::tof32ClipSqDist = 0.0f;
NNS_VECTOR clsGLinkContainer_Object::tosCollisionHalfSizeVec = {4.2f, 4.9f, 19.4f};

void clsGLinkContainer_Object::draw(NNS_OBJECT* psObject,
                                    f32 (*psMtxPal)[4][4],
                                    u32* psNodeStat,
                                    const f32 (*opaNnViewMtx)[4][4],
                                    f32 (*psMtxWork)[4][4],
                                    u32 u32ViewNo)
{
}

void clsGLinkContainer_Object::reset()
{
}

void clsGLinkContainer_Object::main()
{
}

void clsGLinkContainer_Object::requestDrawBreakEffect()
{
}

void clsGLinkContainer_Object::callbackContactTriggerRigidBody(
    const hkContactPointConfirmedEvent& rParam1)
{
}

void clsGLinkContainer_Object::drawEffect(clsPlayerTask* pcPlayer)
{
}

void clsGLinkContainer_Object::setData()
{
}

void clsGLinkContainer_Object::createData()
{
}

void clsGLinkContainer_Object::destroyData()
{
}

clsGLinkContainer_Task::clsGLinkContainer_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsGLinkContainer_Task,
                                 clsGLinkContainer_Object,
                                 clsModelType_OB_TX>(u32ObjectAreaNum, 0x18A88)
{
}

void clsGLinkContainer_Task::reset()
{
}

void clsGLinkContainer_Task::execute()
{
}

void clsGLinkContainer_Task::draw()
{
}

NNS_VECTOR* clsGLinkContainer_Object::getCollisionHalfSizeVecPtr() const
{
    return &tosCollisionHalfSizeVec;
}
