#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PutGravityObj2.hpp"

f32 clsPutGravityObj2_Obj::m_tof32CLIP_DISTx2 = 0.0f;
clsGravityGimmickParam clsPutGravityObj2_Obj::t_ocGravityGimmickParam;

void clsPutGravityObj2_Obj::init()
{
}

void clsPutGravityObj2_Obj::reset()
{
}

void clsPutGravityObj2_Obj::setData()
{
}

void clsPutGravityObj2_Obj::createData()
{
}

void clsPutGravityObj2_Obj::createDebris(NNS_OBJECT* psObject,
                                         u32 u32DebrisStartNodeNum,
                                         f32 f32LimitFrame)
{
}

f32 clsPutGravityObj2_Obj::getMass()
{
    return 0.0f;
}

hkShape* clsPutGravityObj2_Obj::getShape()
{
    return 0;
}

f32 clsPutGravityObj2_Obj::getRestitution()
{
    return 0.0f;
}

f32 clsPutGravityObj2_Obj::getFriction()
{
    return 0.0f;
}

void clsPutGravityObj2_Obj::createSe()
{
}

void clsPutGravityObj2_Obj::destroyData()
{
}

void clsPutGravityObj2_Obj::requestDrawContactEffect(const hkContactPoint* pcContact)
{
}

void clsPutGravityObj2_Obj::requestDrawBreakEffect()
{
}

void clsPutGravityObj2_Obj::callbackGravityEvent()
{
}

void clsPutGravityObj2_Obj::callbackBreakEvent()
{
}

void clsPutGravityObj2_Obj::contactInterraction(clsRigidBodyGimmickObj* pcObject)
{
}

void clsPutGravityObj2_Obj::main()
{
}

void clsPutGravityObj2_Obj::draw(clsModelType_OB_TX* pcModels,
                                 f32 (*psMtxPal)[4][4],
                                 u32* psNodeStat,
                                 const f32 (*opaNnViewMtx)[4][4],
                                 f32 (*psMtxWork)[4][4],
                                 u32 u32ViewNo,
                                 clsPutGravityObj2_Task* pcTask)
{
}

void clsPutGravityObj2_Task::init()
{
}

void clsPutGravityObj2_Task::reset()
{
}

void clsPutGravityObj2_Task::execute()
{
}

void clsPutGravityObj2_Task::draw()
{
}
