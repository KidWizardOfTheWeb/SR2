#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/St11EnergyCylinder.hpp"

stcThroughColInfo clsEnergyCylinder_Task::m_toasThroughColInfo[6];
f32 clsEnergyCylinder_Obj::m_tof32LowPolyDist;
f32 clsEnergyCylinder_Obj::m_tof32ClipSqDist;

void clsEnergyThroughCol::contactAlwaysEvent(clsPlayerTask* pcPlayer)
{
}

void clsEnergyThroughCol::contactRemoveEvent(clsPlayerTask* pcPlayer)
{
}

void clsEnergyCylinder_Obj::init()
{
}

void clsEnergyCylinder_Obj::reset()
{
}

void clsEnergyCylinder_Obj::setData()
{
}

void clsEnergyCylinder_Obj::createData()
{
}

void clsEnergyCylinder_Obj::destroyData()
{
}

void clsEnergyCylinder_Obj::requestDrawContactEffect(const hkContactPoint* pcContact)
{
}

void clsEnergyCylinder_Obj::requestDrawBreakEffect()
{
}

void clsEnergyCylinder_Obj::callbackGravityEvent()
{
}

void clsEnergyCylinder_Obj::setNear(u32 u32Flg, f32 f32Rate)
{
}

void clsEnergyCylinder_Obj::callbackContactTriggerRigidBody(
    const hkContactPointConfirmedEvent& rParam1)
{
}

void clsEnergyCylinder_Obj::main()
{
}

clsEnergyCylinder_Task::clsEnergyCylinder_Task(u32 u32ObjectAreaNum)
    : clsBaseGimmickBody<clsEnergyCylinder_Task, clsEnergyCylinder_Obj, clsEnergyCylinderModels>(0,
                                                                                                 0)
{
} // [verify params from ASM]

void clsEnergyCylinder_Task::init()
{
}

void clsEnergyCylinder_Task::reset()
{
}

void clsEnergyCylinder_Task::createModel(stcBinInfo& rsBinInfoI)
{
}

void clsEnergyCylinder_Task::execute()
{
}

void clsEnergyCylinder_Task::draw()
{
}

void clsEnergyCylinder_Obj::draw(clsModelType_OB_TX* pcModel,
                                 f32 (*psMtxPal)[4][4],
                                 u32* psNodeStat,
                                 const f32 (*opaNnViewMtx)[4][4],
                                 f32 (*psMtxWork)[4][4])
{
}
