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
                              NNS_MATRIX* psMtxPal,
                              u32* psNodeStat,
                              const NNS_MATRIX* opaNnViewMtx,
                              NNS_MATRIX* psMtxWork,
                              u32 u32ViewNo)
{
}

clsWallGimmick_Task::clsWallGimmick_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 101010)
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
