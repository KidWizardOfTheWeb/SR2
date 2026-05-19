#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03PathRobo.hpp"

void clsPathRobo_Obj::reset()
{
}

void clsPathRobo_Obj::createData()
{
}

void clsPathRobo_Obj::destroyData()
{
}

void clsPathRobo_Obj::requestDrawBreakEffect()
{
}

void clsPathRobo_Obj::draw(clsModelType_OB_TX& rcObj,
                           f32 (*psMtxPal)[4][4],
                           u32* psNodeStat,
                           const f32 (*opaNnViewMtx)[4][4],
                           f32 (*psMtxWork)[4][4],
                           u32 u32ViewNo)
{
}

clsPathRobo_Task::clsPathRobo_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsPathRobo_Task, clsPathRobo_Obj, clsModelType_OB_TX>(
          u32ObjectAreaNum, 0x18A88)
{
}

void clsPathRobo_Task::reset()
{
}

void clsPathRobo_Task::execute()
{
}

void clsPathRobo_Task::draw()
{
}
