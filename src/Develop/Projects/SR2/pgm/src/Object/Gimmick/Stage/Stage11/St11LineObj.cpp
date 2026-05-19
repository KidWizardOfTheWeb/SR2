#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/St11LineObj.hpp"

clsGravityGimmickParam clsLineObj_Obj::t_ocGravityGimmickParam;

void clsLineObj_Obj::reset()
{
}

void clsLineObj_Obj::resetRigidBody()
{
}

void clsLineObj_Obj::createData()
{
}

void clsLineObj_Obj::destroyData()
{
}

void clsLineObj_Obj::mainCrash()
{
}

void clsLineObj_Obj::mainGravity()
{
}

void clsLineObj_Obj::requestDrawContactEffect(const hkContactPoint* pcContact)
{
}

void clsLineObj_Obj::requestDrawBreakEffect()
{
}

void clsLineObj_Obj::callbackGravityEvent()
{
}

void clsLineObj_Obj::draw(clsModelType_OB_TX& rcObj,
                          f32 (*psMtxPal)[4][4],
                          u32* psNodeStat,
                          const f32 (*opaNnViewMtx)[4][4],
                          f32 (*psMtxWork)[4][4],
                          u32 u32ViewNo)
{
}

clsLineObj_Task::clsLineObj_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsLineObj_Task, clsLineObj_Obj, clsModelType_OB_TX>(
          u32ObjectAreaNum, 0x18A88)
{
}

void clsLineObj_Task::reset()
{
}

void clsLineObj_Task::execute()
{
}

void clsLineObj_Task::draw()
{
}
