#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/WallGimmick.hpp"

f32 clsWallGimmick_Obj::atof32ClipSqDist[17] = {0.0f,
                                                0.0f,
                                                0.0f,
                                                0.0f,
                                                0.0f,
                                                0.0f,
                                                0.0f,
                                                0.0f,
                                                0.0f,
                                                0.0f,
                                                0.0f,
                                                0.0f,
                                                0.0f,
                                                0.0f,
                                                0.0f,
                                                0.0f,
                                                0.0f};

void clsWallGimmick_Obj::contactInterraction(clsRigidBodyGimmickObj* pParam1)
{
}

void clsWallGimmick_Obj::createData()
{
}

void clsWallGimmick_Obj::destroyData()
{
}

void clsWallGimmick_Obj::reset()
{
}

void clsWallGimmick_Obj::main()
{
}

void clsWallGimmick_Obj::draw(clsModelType_OB_TX& rcObj,
                              f32 (*psMtxPal)[4][4],
                              u32* psNodeStat,
                              const f32 (*opaNnViewMtx)[4][4],
                              f32 (*psMtxWork)[4][4],
                              u32 u32ViewNo)
{
}

clsWallGimmick_Task::clsWallGimmick_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(0, u32ObjectAreaNum)
{
}

void clsWallGimmick_Task::reset()
{
}

void clsWallGimmick_Task::execute()
{
}

void clsWallGimmick_Task::draw()
{
}
