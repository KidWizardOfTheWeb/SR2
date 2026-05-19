#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBall/SurvivalStart.hpp"

clsSurvivalBallStart_Obj::clsSurvivalBallStart_Obj()
{
}

void clsSurvivalBallStart_Obj::createData()
{
}

void clsSurvivalBallStart_Obj::destroyData()
{
}

void clsSurvivalBallStart_Obj::contactAlwaysEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

void clsSurvivalBallStart_Obj::contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject)
{
}

void clsSurvivalBallStart_Obj::draw(clsModelType_OB_TX_MO_MA& rcModel,
                                    f32 (*psMtxPal)[4][4],
                                    u32* psNodeStat,
                                    const f32 (*opaNnViewMtx)[4][4],
                                    f32 (*psMtxWork)[4][4])
{
}

clsSurvivalBallStart_Task::clsSurvivalBallStart_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsSurvivalBallStart_Task,
                                 clsSurvivalBallStart_Obj,
                                 clsModelType_OB_TX_MO_MA>(u32ObjectAreaNum, 0x18A92)
{
}

void clsSurvivalBallStart_Task::reset()
{
}

void clsSurvivalBallStart_Task::execute()
{
}

void clsSurvivalBallStart_Task::draw()
{
}
