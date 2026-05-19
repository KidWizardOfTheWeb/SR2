#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Mission/MissionMark.hpp"

clsMissionMark_Obj::clsMissionMark_Obj()
{
}

void clsMissionMark_Obj::createData()
{
}

void clsMissionMark_Obj::draw(clsModelType_OB_TX_MO_MA& rcObj,
                              f32 (*psMtxPal)[4][4],
                              u32* psNodeStat,
                              const f32 (*opaNnViewMtx)[4][4],
                              f32 (*psMtxWork)[4][4])
{
}

void clsMissionMark_Obj::contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

void clsMissionMark_Obj::destroyData()
{
}

void clsMissionMark_Task::reset()
{
}

void clsMissionMark_Task::execute()
{
}

void clsMissionMark_Task::draw()
{
}

clsMissionMark_Task::clsMissionMark_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsMissionMark_Task, clsMissionMark_Obj, clsModelType_OB_TX_MO_MA>(
          0, 0)
{
}

clsMissionMark_Task::~clsMissionMark_Task()
{
}

void clsMissionMark_Task::setMode(u32)
{
}

void clsMissionMark_Task::addMode()
{
}

void clsMissionMark_Task::addMode(u32)
{
}

void clsMissionMark_Task::subMode()
{
}

void clsMissionMark_Task::subMode(u32)
{
}

void clsMissionMark_Task::reinitMode()
{
}

void clsMissionMark_Task::createModel(stcBinInfo& rsBinInfo)
{
}

void clsMissionMark_Task::setSetData(const stcSetDataDetail& rsDetail)
{
}
