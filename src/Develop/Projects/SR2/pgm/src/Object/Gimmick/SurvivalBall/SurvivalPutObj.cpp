#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBall/SurvivalPutObj.hpp"

clsSurvivalBallPutObj_Obj::clsSurvivalBallPutObj_Obj()
{
}

void clsSurvivalBallPutObj_Obj::createData()
{
}

void clsSurvivalBallPutObj_Obj::destroyData()
{
}

void clsSurvivalBallPutObj_Obj::reset()
{
}

void clsSurvivalBallPutObj_Obj::main()
{
}

void clsSurvivalBallPutObj_Obj::draw(NNS_OBJECT* psObject,
                                     f32 (*psMtxPal)[4][4],
                                     u32* psNodeStat,
                                     const f32 (*opaNnViewMtx)[4][4],
                                     f32 (*psMtxWork)[4][4],
                                     u32 u32ViewNo)
{
}

void clsSurvivalBallPutObj_Obj::contactTriggerCallback(hkContactPointConfirmedEvent& cEvent)
{
}

clsSurvivalBallPutObj_Task::clsSurvivalBallPutObj_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsSurvivalBallPutObj_Task,
                                 clsSurvivalBallPutObj_Obj,
                                 clsModelType_OB_TX>(u32ObjectAreaNum, 0x18A92)
{
}

void clsSurvivalBallPutObj_Task::reset()
{
}

void clsSurvivalBallPutObj_Task::execute()
{
}

void clsSurvivalBallPutObj_Task::draw()
{
}
