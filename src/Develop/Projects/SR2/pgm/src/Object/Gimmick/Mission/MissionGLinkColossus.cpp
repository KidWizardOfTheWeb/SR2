#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Mission/MissionGLinkColossus.hpp"

f32 clsMissionGLinkColossus_Object::tof32ClipSqDist = 0.0f;
NNS_VECTOR clsMissionGLinkColossus_Object::tosCollisionHalfSizeVec = {4.2f, 4.9f, 19.4f};

u8 clsMissionGLinkColossus_Object::draw(NNS_OBJECT* psObject,
                                        f32 (*psMtxPal)[4][4],
                                        u32* psNodeStat,
                                        const f32 (*opaNnViewMtx)[4][4],
                                        f32 (*psMtxWork)[4][4],
                                        u32 u32ViewNo)
{
    return 0;
}

void clsMissionGLinkColossus_Object::reset()
{
}

void clsMissionGLinkColossus_Object::main()
{
}

void clsMissionGLinkColossus_Object::requestDrawContactEffect(const hkContactPoint* pcContact)
{
}

void clsMissionGLinkColossus_Object::requestDrawBreakEffect()
{
}

void clsMissionGLinkColossus_Object::callbackContactTriggerRigidBody(
    const hkContactPointConfirmedEvent& rParam1)
{
}

void clsMissionGLinkColossus_Object::drawEffect(clsPlayerTask* pcPlayer)
{
}

void clsMissionGLinkColossus_Object::setData()
{
}

void clsMissionGLinkColossus_Object::createData()
{
}

void clsMissionGLinkColossus_Object::destroyData()
{
}

clsMissionGLinkColossus_Task::clsMissionGLinkColossus_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsMissionGLinkColossus_Task,
                                 clsMissionGLinkColossus_Object,
                                 clsModelType_OB_TX>(u32ObjectAreaNum, 0x18A88),
      m_pcBurnLightTask(0)
{
}

void clsMissionGLinkColossus_Task::execute()
{
}

void clsMissionGLinkColossus_Task::draw()
{
}

NNS_VECTOR* clsMissionGLinkColossus_Object::getCollisionHalfSizeVecPtr() const
{
    return &tosCollisionHalfSizeVec;
}
