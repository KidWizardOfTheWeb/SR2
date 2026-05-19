#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/St11FSecurityGate.hpp"

namespace {
static f32 tof32ClipSqDist = 0.0f;
}

NNS_VECTORFAST clsFSecurityGate_Obj::m_osOffsetColPos = {0.0f, 0.0f, 12.0f, 0.0f};

void clsFSecurityGateCollision::contactTriggerEvent(clsPlayerTask* pcPlayer)
{
}

void clsFSecurityGateCollision::contactRemoveEvent(clsPlayerTask* pcPlayer)
{
}

void clsFSecurityGate_Obj::createData()
{
}

void clsFSecurityGate_Obj::destroyData()
{
}

void clsFSecurityGate_Obj::main()
{
}

void clsFSecurityGate_Ctrl::reset()
{
}

void clsFSecurityGate_Ctrl::createData()
{
}

void clsFSecurityGate_Ctrl::destroyData()
{
}

void clsFSecurityGate_Ctrl::draw(clsModelType_OB_TX_MO_MA& rcModel,
                                 f32 (*psMtxPal)[4][4],
                                 u32* psNodeStat,
                                 const f32 (*opaNnViewMtx)[4][4],
                                 f32 (*psMtxWork)[4][4],
                                 u32 u32ViewNo)
{
}

clsFSecurityGate_Task::clsFSecurityGate_Task(u32 u32ObjectAreaNum) : clsBaseGimmickBody(0, 0)
{
}

void clsFSecurityGate_Task::reset()
{
}

void clsFSecurityGate_Task::createModel(stcBinInfo& rsBinInfoI)
{
}

void clsFSecurityGate_Task::execute()
{
}

void clsFSecurityGate_Task::draw()
{
}

clsFSecurityGate_Task::~clsFSecurityGate_Task()
{
}
