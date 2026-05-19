#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage10/St10SnowBall.hpp"

clsSnowBall_Obj::clsSnowBall_Obj()
{
}

void clsSnowBall_Obj::createData()
{
}

void clsSnowBall_Obj::destroyData()
{
}

void clsSnowBall_Obj::reset()
{
}

void clsSnowBall_Obj::main()
{
}

void clsSnowBall_Obj::draw(clsModelType_OB_TX& rcModel,
                           f32 (*psMtxPal)[4][4],
                           u32* psNodeStat,
                           const f32 (*opaNnViewMtx)[4][4],
                           f32 (*psMtxWork)[4][4],
                           u32 u32ViewNo)
{
}

void clsSnowBall_Obj::drawShadow(clsModelType_OB& rcModel)
{
}

void clsSnowBall_Obj::contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject)
{
}

void clsSnowBall_Obj::callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& cEvent)
{
}

void clsSnowBall_Obj::callbackGravityEvent()
{
}

void clsSnowBall_Obj::requestDrawContactEffect(const hkContactPoint* pcContact)
{
}

void clsSnowBall_Obj::callbackBreakEvent()
{
}

void clsSnowBall_Obj::requestDrawBreakEffect()
{
}

clsSnowBall_Task::clsSnowBall_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 0)
{
}

void clsSnowBall_Task::reset()
{
}

void clsSnowBall_Task::execute()
{
}

void clsSnowBall_Task::draw()
{
}

void clsSnowBall_Task::setShadowModel(const u8* rsBinInfoI)
{
}
