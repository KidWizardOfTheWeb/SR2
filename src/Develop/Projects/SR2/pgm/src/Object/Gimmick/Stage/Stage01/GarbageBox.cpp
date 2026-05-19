#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/GarbageBox.hpp"

void clsGarbageBox_Obj::createData()
{
}

void clsGarbageBox_Obj::destroyData()
{
}

void clsGarbageBox_Obj::reset()
{
}

void clsGarbageBox_Obj::main()
{
}

void clsGarbageBox_Obj::draw(clsModelType_OB_TX& rModels,
                             f32 (*psMtxPal)[4][4],
                             u32* psNodeStat,
                             const f32 (*opaNnViewMtx)[4][4],
                             f32 (*psMtxWork)[4][4])
{
}

clsGarbageBox_Task::clsGarbageBox_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsGarbageBox_Task, clsGarbageBox_Obj, clsModelType_OB_TX>(
          u32ObjectAreaNum, 0x18A88)
{
}

void clsGarbageBox_Task::reset()
{
}

void clsGarbageBox_Task::execute()
{
}

void clsGarbageBox_Task::draw()
{
}

clsGarbageBox_Obj::clsGarbageBox_Obj()
{
}

clsGarbageBox_Obj::~clsGarbageBox_Obj()
{
}
