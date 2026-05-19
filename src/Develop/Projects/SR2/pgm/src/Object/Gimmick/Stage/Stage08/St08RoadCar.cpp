#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08RoadCar.hpp"

f32 clsRoadCar_Obj::m_tof32ClipSqDist = 0.0f;
clsGravityGimmickParam clsRoadCar_Obj::t_ocGravityGimmickParam;

void clsRoadCar_Obj::init()
{
}

void clsRoadCar_Obj::reset()
{
}

void clsRoadCar_Obj::createData()
{
}

void clsRoadCar_Obj::destroyData()
{
}

void clsRoadCar_Obj::requestDrawBreakEffect()
{
}

void clsRoadCar_Obj::requestDrawContactEffect(const hkContactPoint* pParam1)
{
}

void clsRoadCar_Obj::draw(clsModelType_OB_TX& rcObj,
                          f32 (*psMtxPal)[4][4],
                          u32* psNodeStat,
                          const f32 (*opaNnViewMtx)[4][4],
                          f32 (*psMtxWork)[4][4],
                          u32 u32ViewNo)
{
}

clsRoadCar_Task::clsRoadCar_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsRoadCar_Task, clsRoadCar_Obj, clsModelType_OB_TX>(
          u32ObjectAreaNum, 0)
{
}

void clsRoadCar_Task::reset()
{
}

void clsRoadCar_Task::execute()
{
}

void clsRoadCar_Task::draw()
{
}
