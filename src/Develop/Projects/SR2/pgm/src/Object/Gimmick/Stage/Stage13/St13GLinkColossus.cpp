#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage13/St13GLinkColossus.hpp"

clsGravityGimmickParam clsGLinkColossus_Object::t_ocGravityGimmickParam[2];
f32 clsGLinkColossus_Object::tof32ClipSqDist = 0.0f;
NNS_VECTOR clsGLinkColossus_Object::tosCollisionHalfSizeVec = {4.0f, 4.0f, 16.0f};

u8 clsGLinkColossus_Object::draw(NNS_OBJECT* psObject,
                                 f32 (*psMtxPal)[4][4],
                                 u32* psNodeStat,
                                 const f32 (*opaNnViewMtx)[4][4],
                                 f32 (*psMtxWork)[4][4],
                                 u32 u32ViewNo)
{
    return 0;
}

void clsGLinkColossus_Object::reset()
{
}

void clsGLinkColossus_Object::main()
{
}

void clsGLinkColossus_Object::requestDrawBreakEffect()
{
}

void clsGLinkColossus_Object::drawEffect(clsPlayerTask* pcPlayer)
{
}

void clsGLinkColossus_Object::setData()
{
}

void clsGLinkColossus_Object::createData()
{
}

void clsGLinkColossus_Object::destroyData()
{
}

clsGLinkColossus_Task::clsGLinkColossus_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsGLinkColossus_Task,
                                 clsGLinkColossus_Object,
                                 clsModelType_OB_TX>(u32ObjectAreaNum, 0x18A88)
{
}

void clsGLinkColossus_Task::execute()
{
}

void clsGLinkColossus_Task::draw()
{
}

void clsGLinkColossus_Task::reset()
{
}

void clsGLinkColossus_Object::countEffect()
{
}

NNS_VECTOR* clsGLinkColossus_Object::getCollisionHalfSizeVecPtr() const
{
    return &tosCollisionHalfSizeVec;
}

nspPackId::enm clsGLinkColossus_Object::getPackId() const
{
    return nspPackId::ST13_GLINK_COLOSSUS_23040;
}
