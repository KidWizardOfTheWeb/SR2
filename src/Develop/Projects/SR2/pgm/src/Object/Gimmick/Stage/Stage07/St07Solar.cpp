#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07Solar.hpp"

f32 clsSolar_Obj::t_of32CLIP_DISTx2 = 0.0f;

clsSolar_Obj::clsSolar_Obj()
{
}

void clsSolar_Obj::init()
{
}

void clsSolar_Obj::reset()
{
}

void clsSolar_Obj::setData()
{
}

void clsSolar_Obj::createData()
{
}

void clsSolar_Obj::destroyData()
{
}

void clsSolar_Obj::requestDrawBreakEffect()
{
}

void clsSolar_Obj::adminSe()
{
}

void clsSolar_Obj::callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rParam1)
{
}

void clsSolar_Obj::callbackGravityEvent()
{
}

void clsSolar_Obj::draw(clsModelType_OB_TX_MO_MA& rParam1,
                        f32 (*psMtxPal)[4][4],
                        u32* puParam1,
                        const f32 (*opaNnViewMtx)[4][4],
                        f32 (*psMtxWork)[4][4])
{
}

clsSolar_Task::clsSolar_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsSolar_Task, clsSolar_Obj, clsModelType_OB_TX_MO_MA>(
          u32ObjectAreaNum, 0x18A88)
{
}

void clsSolar_Task::reset()
{
}

void clsSolar_Task::execute()
{
}

void clsSolar_Task::draw()
{
}
