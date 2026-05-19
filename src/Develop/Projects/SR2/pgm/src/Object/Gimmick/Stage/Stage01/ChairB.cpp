#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/ChairB.hpp"

void clsChairB_Obj::createData()
{
}

void clsChairB_Obj::destroyData()
{
}

void clsChairB_Obj::reset()
{
}

void clsChairB_Obj::main()
{
}

void clsChairB_Obj::draw(clsModelType_OB_TX& rModels,
                         f32 (*psMtxPal)[4][4],
                         u32* psNodeStat,
                         const f32 (*opaNnViewMtx)[4][4],
                         f32 (*psMtxWork)[4][4])
{
}

clsChairB_Task::clsChairB_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsChairB_Task, clsChairB_Obj, clsModelType_OB_TX>(
          u32ObjectAreaNum, 0x18A88)
{
}

void clsChairB_Task::reset()
{
}

void clsChairB_Task::execute()
{
}

void clsChairB_Task::draw()
{
}

clsChairB_Obj::clsChairB_Obj()
{
}

clsChairB_Obj::~clsChairB_Obj()
{
}
