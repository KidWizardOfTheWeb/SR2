#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalRelay/SurvivalWalkRunObj.hpp"

void clsSurvivalRelayWalkRunObj_Obj::main()
{
}

void clsSurvivalRelayWalkRunObj_Obj::contactTriggerEvent(hkContactPoint* pcObject,
                                                         clsObject* pParam2)
{
}

void clsSurvivalRelayWalkRunObj_Obj::contactRemoveEvent(hkContactPoint* pcObject,
                                                        clsObject* pParam2)
{
}

void clsSurvivalRelayWalkRunObj_Obj::contactAlwaysEvent(hkContactPoint* pcObject,
                                                        clsObject* pParam2)
{
}

void clsSurvivalRelayWalkRunObj_Obj::createData()
{
}

void clsSurvivalRelayWalkRunObj_Obj::destroyData()
{
}

clsSurvivalRelayWalkRunObj_Task::clsSurvivalRelayWalkRunObj_Task(u32 u32ObjectAreaNum)
    : clsBaseGimmickBody<clsSurvivalRelayWalkRunObj_Task,
                         clsSurvivalRelayWalkRunObj_Obj,
                         clsSurvivalRelayWalkRunObjModels>(0, 0)
{
} // [verify params from ASM]

clsSurvivalRelayWalkRunObj_Task::~clsSurvivalRelayWalkRunObj_Task()
{
}

void clsSurvivalRelayWalkRunObj_Task::startHitPlayer(clsSurvivalRelayPlayerTask* pcPlayer,
                                                     u32 u32TypeNo,
                                                     clsSurvivalRelayWalkRunObj_Obj* psObj,
                                                     const NNS_VECTOR* copsRot)
{
}

void clsSurvivalRelayWalkRunObj_Task::reset()
{
}

void clsSurvivalRelayWalkRunObj_Task::createModel(stcBinInfo& rsBinInfoI)
{
}

void clsSurvivalRelayWalkRunObj_Task::execute()
{
}

void clsSurvivalRelayWalkRunObj_Task::draw()
{
}
