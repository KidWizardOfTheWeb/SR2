#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBall/SurvivalPole.hpp"

void clsSurvivalBallPole_Obj::createData()
{
}

void clsSurvivalBallPole_Obj::destroyData()
{
}

void clsSurvivalBallPole_Obj::reset()
{
}

void clsSurvivalBallPole_Obj::requestDrawContactEffect(const hkContactPoint* pParam1)
{
}

void clsSurvivalBallPole_Obj::requestDrawBreakEffect()
{
}

void clsSurvivalBallPole_Obj::main()
{
}

void clsSurvivalBallPole_Obj::mainCrash()
{
}

void clsSurvivalBallPole_Obj::draw(clsModelType_OB_TX_MO_MA& rcModel,
                                   f32 (*psMtxPal)[4][4],
                                   u32* psNodeStat,
                                   const f32 (*opaNnViewMtx)[4][4],
                                   f32 (*psMtxWork)[4][4],
                                   u32 u32ViewNo)
{
}

clsSurvivalBallPole_Task::clsSurvivalBallPole_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsSurvivalBallPole_Task,
                                 clsSurvivalBallPole_Obj,
                                 clsModelType_OB_TX_MO_MA>(u32ObjectAreaNum, 0x18A92)
{
}

void clsSurvivalBallPole_Task::reset()
{
}

void clsSurvivalBallPole_Task::execute()
{
}

void clsSurvivalBallPole_Task::draw()
{
}
