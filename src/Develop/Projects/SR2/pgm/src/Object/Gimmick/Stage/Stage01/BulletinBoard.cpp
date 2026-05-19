#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/BulletinBoard.hpp"

void clsBulletinBoard_Obj::createData()
{
}

void clsBulletinBoard_Obj::destroyData()
{
}

void clsBulletinBoard_Obj::main()
{
}

void clsBulletinBoard_Obj::draw(clsModelType_OB_TX& rcModel,
                                f32 (*psMtxPal)[4][4],
                                u32* psNodeStat,
                                const f32 (*opaNnViewMtx)[4][4],
                                f32 (*psMtxWork)[4][4],
                                u32 u32ViewNo)
{
}

clsBulletinBoard_Task::clsBulletinBoard_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsBulletinBoard_Task, clsBulletinBoard_Obj, clsModelType_OB_TX>(
          u32ObjectAreaNum, 0x18A88)
{
}

void clsBulletinBoard_Task::reset()
{
}

void clsBulletinBoard_Task::execute()
{
}

void clsBulletinBoard_Task::draw()
{
}

clsBulletinBoard_Obj::clsBulletinBoard_Obj()
{
}

clsBulletinBoard_Obj::~clsBulletinBoard_Obj()
{
}
