#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage10/St10FallSnowBall.hpp"

clsFallSnowBall_Obj::clsFallSnowBall_Obj()
{
}

void clsFallSnowBall_Obj::createData()
{
}

void clsFallSnowBall_Obj::destroyData()
{
}

void clsFallSnowBall_Obj::reset()
{
}

void clsFallSnowBall_Obj::main()
{
}

void clsFallSnowBall_Obj::draw(clsModelType_OB_TX& rcModel,
                               f32 (*psMtxPal)[4][4],
                               u32* psNodeStat,
                               const f32 (*opaNnViewMtx)[4][4],
                               f32 (*psMtxWork)[4][4],
                               u32 u32ViewNo)
{
}

void clsFallSnowBall_Obj::contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject)
{
}

void clsFallSnowBall_Obj::callbackContactTriggerRigidBody(
    const hkContactPointConfirmedEvent& cEvent)
{
}

void clsFallSnowBall_Obj::requestDrawContactEffect(const hkContactPoint* pcContact)
{
}

void clsFallSnowBall_Obj::CheckCount()
{
}

void clsFallSnowBall_Obj::callbackGravityEvent()
{
}

void clsFallSnowBall_Obj::drawShadow(clsModelType_OB& model)
{
}

void clsFallSnowBall_Obj::requestDrawBreakEffect()
{
}

clsFallSnowBall_Task::clsFallSnowBall_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 0x18702)
{
}

void clsFallSnowBall_Task::reset()
{
}

void clsFallSnowBall_Task::execute()
{
}

void clsFallSnowBall_Task::draw()
{
}

void clsFallSnowBall_Task::setShadowModel(const u8* rsBinInfoI)
{
}
