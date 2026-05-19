#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03SecurityGate.hpp"

NNS_VECTORFAST clsSecurityGate_Obj::m_osOffsetPos = {5.5f, 11.0f, 0.0f, 0.0f};

void clsSecurityGateCollision::contactTriggerEvent(clsPlayerTask* pcPlayer)
{
}

void clsSecurityGateCollision::contactRemoveEvent(clsPlayerTask* pcPlayer)
{
}

void clsSecurityGate_Obj::createData()
{
}

void clsSecurityGate_Obj::destroyData()
{
}

void clsSecurityGate_Obj::openDoor()
{
}

void clsSecurityGate_Obj::main()
{
}

void clsSecurityGate_Obj::requestDrawBreakEffect()
{
}

void clsSecurityGate_Obj::drawPartsBreakEffect(const NNS_VECTORFAST& rsPosVecFast)
{
}

void clsSecurityGate_Obj::contactInterraction(clsRigidBodyGimmickObj* pcObject)
{
}

void clsSecurityGate_Ctrl::reset()
{
}

void clsSecurityGate_Ctrl::openDoor(u32 u32PlayerNo)
{
}

void clsSecurityGate_Ctrl::openDoor()
{
}

void clsSecurityGate_Ctrl::createData()
{
}

void clsSecurityGate_Ctrl::destroyData()
{
}

void clsSecurityGate_Ctrl::draw(clsModelType_OB_TX_MO& rcModel,
                                f32 (*psMtxPal)[4][4],
                                u32* psNodeStat,
                                const f32 (*opaNnViewMtx)[4][4],
                                f32 (*psMtxWork)[4][4],
                                u32 u32ViewNo)
{
}

clsSecurityGate_Task::clsSecurityGate_Task(u32 u32ObjectAreaNum)
    : clsBaseGimmickBody<clsSecurityGate_Task, clsSecurityGate_Ctrl, clsSecurityGateModel>(
          u32ObjectAreaNum, 0)
{
}

void clsSecurityGate_Task::reset()
{
}

void clsSecurityGate_Task::createModel(stcBinInfo& rsBinInfoI)
{
}

void clsSecurityGate_Task::execute()
{
}

void clsSecurityGate_Task::draw()
{
}
