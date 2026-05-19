#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage04/St04SmallWaterSphere.hpp"

NNS_VECTOR clsSmallWaterSphere_Object::tosCollisionHalfSizeVec = {2.0f, 2.0f, 2.0f};
f32 clsSmallWaterSphere_Object::tof32ClipSqDist = 0.0f;
clsGravityGimmickParam clsSmallWaterSphere_Object::t_ocGravityGimmickParam;

void clsSmallWaterSphere_Object::draw(clsModelType_OB_TX_MO_MA& rcModel,
                                      f32 (*psMtxPal)[4][4],
                                      u32* psNodeStat,
                                      const f32 (*opaNnViewMtx)[4][4],
                                      f32 (*psMtxWork)[4][4],
                                      u32 u32Seed,
                                      u32 u32ViewNo)
{
}

void clsSmallWaterSphere_Object::reset()
{
}

void clsSmallWaterSphere_Object::main()
{
}

void clsSmallWaterSphere_Object::mainGravity()
{
}

void clsSmallWaterSphere_Object::mainCrash()
{
}

void clsSmallWaterSphere_Object::requestDrawBreakEffect()
{
}

void clsSmallWaterSphere_Object::callbackContactTriggerRigidBody(
    const hkContactPointConfirmedEvent& rParam1)
{
}

void clsSmallWaterSphere_Object::playSe(clsPlayerTask* pParam1)
{
}

void clsSmallWaterSphere_Object::drawEffect(clsPlayerTask* pParam1)
{
}

void clsSmallWaterSphere_Object::setData()
{
}

void clsSmallWaterSphere_Object::createData()
{
}

void clsSmallWaterSphere_Object::destroyData()
{
}

clsSmallWaterSphere_Task::clsSmallWaterSphere_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsSmallWaterSphere_Task,
                                 clsSmallWaterSphere_Object,
                                 clsModelType_OB_TX_MO_MA>(u32ObjectAreaNum, 0x18A88)
{
}

void clsSmallWaterSphere_Task::execute()
{
}

void clsSmallWaterSphere_Task::draw()
{
}

void clsSmallWaterSphere_Task::reset()
{
}

clsSmallWaterSphere_Object::clsSmallWaterSphere_Object()
{
}

void clsSmallWaterSphere_Object::callbackCrashEvent()
{
}

NNS_VECTOR* clsSmallWaterSphere_Object::getCollisionHalfSizeVecPtr() const
{
    return &tosCollisionHalfSizeVec;
}

nspPackId::enm clsSmallWaterSphere_Object::getPackId() const
{
    return nspPackId::ST04_SMALL_WATERSPHERE_14070;
}
