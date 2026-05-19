#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage04/St04AutoRunCanoe.hpp"

NNS_VECTORFAST clsAutoRunCanoe_Obj::m_sPlayerOffsetFast = {0.0f, -8.1f, 1.2f, 0.0f};
u32 clsAutoRunCanoe::otau32Se_CanoeL[2] = {134574, 333230};
u32 clsAutoRunCanoe::otau32Se_CanoeBreak[2] = {789929, 857513};
u32 clsAutoRunCanoe::otau32Se_WaterStraight[2] = {69033, 267689};

void clsAutoRunCanoe_Obj::init()
{
}

void clsAutoRunCanoe_Obj::createData()
{
}

void clsAutoRunCanoe_Obj::destroyData()
{
}

void clsAutoRunCanoe_Obj::contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

clsAutoRunCanoe_Task::clsAutoRunCanoe_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 0x18A88)
{
}

void clsAutoRunCanoe_Task::execute()
{
}

void clsAutoRunCanoe_Task::draw()
{
}

void clsAutoRunCanoe_Task::reset()
{
}

clsAutoRunCanoe_Obj::clsAutoRunCanoe_Obj()
{
}

clsAutoRunCanoe_Obj::~clsAutoRunCanoe_Obj()
{
}

void clsAutoRunCanoe_Obj::controlPlayer()
{
}

void clsAutoRunCanoe_Obj::elaseExexuteAutoRunCanoe(clsAutoRunCanoe* pCanoe)
{
}

void clsAutoRunCanoe::draw(clsModelType_OB_TX& rcModel,
                           f32 (*psMtxPal)[4][4],
                           u32* psNodeStat,
                           const f32 (*opaNnViewMtx)[4][4],
                           f32 (*psMtxWork)[4][4],
                           u32 NodeStatus)
{
}
