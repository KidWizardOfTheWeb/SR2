#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08RoadTrailer/St08RoadTrailer.hpp"

f32 clsRoadTrailer_Obj::m_tof32ClipSqDist = 0.0f;
clsGravityGimmickParam clsRoadTrailer_Obj::t_ocGravityGimmickParam;

void clsRoadTrailer_Obj::init()
{
}

void clsRoadTrailer_Obj::reset()
{
}

void clsRoadTrailer_Obj::resetObject()
{
}

void clsRoadTrailer_Obj::createData()
{
}

void clsRoadTrailer_Obj::destroyData()
{
}

void clsRoadTrailer_Obj::eventSetPosition()
{
}

void clsRoadTrailer_Obj::eventStartMove()
{
}

void clsRoadTrailer_Obj::eventStopMove()
{
}

void clsRoadTrailer_Obj::requestDrawBreakEffect()
{
}

void clsRoadTrailer_Obj::execute()
{
}

void clsRoadTrailer_Obj::draw(clsModelType_OB_TX& rcObj,
                              NNS_MATRIX* psMtxPal,
                              u32* psNodeStat,
                              const NNS_MATRIX* opaNnViewMtx,
                              NNS_MATRIX* psMtxWork,
                              u32 u32ViewNo)
{
}

clsRoadTrailer_Task::clsRoadTrailer_Task(u32 u32ObjectAreaNum)
    : clsMultiModelGimmick_Task<clsRoadTrailer_Task, clsRoadTrailer_Obj, clsMultiObTxModels>(
          u32ObjectAreaNum, 101000)
{
}

void clsRoadTrailer_Task::reset()
{
}

void clsRoadTrailer_Task::execute()
{
}

void clsRoadTrailer_Task::draw()
{
}
