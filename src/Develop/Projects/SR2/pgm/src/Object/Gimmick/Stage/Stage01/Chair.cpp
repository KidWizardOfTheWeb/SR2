#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/Chair.hpp"

void clsChairA_Obj::createData()
{
}

void clsChairA_Obj::destroyData()
{
}

void clsChairA_Obj::reset()
{
}

void clsChairA_Obj::main()
{
}

void clsChairA_Obj::draw(clsModelType_OB_TX& rModels,
                         f32 (*psMtxPal)[4][4],
                         u32* psNodeStat,
                         const f32 (*opaNnViewMtx)[4][4],
                         f32 (*psMtxWork)[4][4])
{
}

clsChairA_Task::clsChairA_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsChairA_Task, clsChairA_Obj, clsModelType_OB_TX>(
          u32ObjectAreaNum, 0x18A88)
{
}

void clsChairA_Task::reset()
{
}

void clsChairA_Task::execute()
{
}

void clsChairA_Task::draw()
{
}

clsChairA_Obj::clsChairA_Obj()
{
}

clsChairA_Obj::~clsChairA_Obj()
{
}
