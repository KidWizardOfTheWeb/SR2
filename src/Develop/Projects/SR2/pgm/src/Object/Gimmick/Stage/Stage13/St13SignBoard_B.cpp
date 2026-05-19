#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage13/St13SignBoard_B.hpp"

f32 clsSignBoardB_Object::tof32ClipSqDist;

void clsSignBoardB_Object::draw(clsModelType_OB_TX_MO_MA& rcModel,
                                f32 (*psMtxPal)[4][4],
                                u32* psNodeStat,
                                const f32 (*opaNnViewMtx)[4][4],
                                f32 (*psMtxWork)[4][4],
                                u32 u32ViewNo)
{
}

void clsSignBoardB_Object::setData()
{
}

void clsSignBoardB_Object::destroyData()
{
}

clsSignBoardB_Task::clsSignBoardB_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsSignBoardB_Task,
                                 clsSignBoardB_Object,
                                 clsModelType_OB_TX_MO_MA>(u32ObjectAreaNum, 0x18A88)
{
}

void clsSignBoardB_Task::execute()
{
}

void clsSignBoardB_Task::draw()
{
}
