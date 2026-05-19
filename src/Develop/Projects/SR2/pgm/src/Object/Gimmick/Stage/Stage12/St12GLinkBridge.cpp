#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage12/St12GLinkBridge.hpp"

NNS_VECTOR clsGLinkBridge_Object::tosCollisionHalfSizeVec = {3.5f, 3.5f, 13.0f};
f32 clsGLinkBridge_Object::tof32ClipSqDist = 0.0f;
clsGravityGimmickParam clsGLinkBridge_Object::t_ocGravityGimmickParam;

void clsGLinkBridge_Object::draw(NNS_OBJECT* psObject,
                                 f32 (*psMtxPal)[4][4],
                                 u32* psNodeStat,
                                 const f32 (*opaNnViewMtx)[4][4],
                                 f32 (*psMtxWork)[4][4],
                                 u32 u32ViewNo)
{
}

void clsGLinkBridge_Object::reset()
{
}

void clsGLinkBridge_Object::main()
{
}

void clsGLinkBridge_Object::requestDrawBreakEffect()
{
}

void clsGLinkBridge_Object::callbackGravityEvent()
{
}

void clsGLinkBridge_Object::drawEffect(clsPlayerTask* pcPlayer)
{
}

void clsGLinkBridge_Object::requestDrawContactEffect(const hkContactPoint* pcContact)
{
}

void clsGLinkBridge_Object::setData()
{
}

void clsGLinkBridge_Object::createData()
{
}

void clsGLinkBridge_Object::destroyData()
{
}

clsGLinkBridge_Task::clsGLinkBridge_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsGLinkBridge_Task, clsGLinkBridge_Object, clsModelType_OB_TX>(
          u32ObjectAreaNum, 0x18A88)
{
}

void clsGLinkBridge_Task::execute()
{
}

void clsGLinkBridge_Task::draw()
{
}
