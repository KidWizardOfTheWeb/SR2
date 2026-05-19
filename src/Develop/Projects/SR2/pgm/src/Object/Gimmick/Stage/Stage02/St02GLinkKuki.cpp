#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02GLinkKuki.hpp"

u32 clsGLinkKuki_Object::otau32Se_BotanicalLink[2] = {2985, 529321};
u32 clsGLinkKuki_Object::otau32Se_ShidaCut[2] = {2990, 136110};
u32 clsGLinkKuki_Object::otau32Se_ShidaCrash[2] = {68526, 201646};
NNS_VECTOR clsGLinkKuki_Object::tosCollisionHalfSizeVec = {3.0f, 3.0f, 12.5f};
f32 clsGLinkKuki_Object::tof32ClipSqDist = 0.0f;
clsGravityGimmickParam clsGLinkKuki_Object::t_ocGravityGimmickParam;

void clsGLinkKuki_Object::draw(NNS_OBJECT* psObject,
                               f32 (*psMtxPal)[4][4],
                               u32* psNodeStat,
                               const f32 (*opaNnViewMtx)[4][4],
                               f32 (*psMtxWork)[4][4],
                               u32 u32ViewNo)
{
}

void clsGLinkKuki_Object::reset()
{
}

void clsGLinkKuki_Object::main()
{
}

void clsGLinkKuki_Object::requestDrawBreakEffect()
{
}

void clsGLinkKuki_Object::callbackGravityEvent()
{
}

void clsGLinkKuki_Object::playSe(clsPlayerTask* pcPlayer)
{
}

void clsGLinkKuki_Object::drawEffect(clsPlayerTask* pcPlayer)
{
}

void clsGLinkKuki_Object::requestDrawContactEffect(const hkContactPoint* pcContact)
{
}

void clsGLinkKuki_Object::setData()
{
}

void clsGLinkKuki_Object::createData()
{
}

void clsGLinkKuki_Object::destroyData()
{
}

clsGLinkKuki_Task::clsGLinkKuki_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsGLinkKuki_Task, clsGLinkKuki_Object, clsModelType_OB_TX>(
          u32ObjectAreaNum, 0x18A88)
{
}

void clsGLinkKuki_Task::reset()
{
}

void clsGLinkKuki_Task::execute()
{
}

void clsGLinkKuki_Task::draw()
{
}
