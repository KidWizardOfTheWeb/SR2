#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08RoadGlinkBus.hpp"

// Static member definitions
f32 clsRoadGlinkBus_Obj::m_tof32ClipSqDist = 0.0f;
NNS_VECTOR clsRoadGlinkBus_Obj::t_osCollisionHalfSizeVec = {3.0f, 3.0f, 16.0f};
clsGravityGimmickParam clsRoadGlinkBus_Obj::t_ocGravityGimmickParam = {};

void clsRoadGlinkBus_Obj::init()
{
}

void clsRoadGlinkBus_Obj::reset()
{
}

void clsRoadGlinkBus_Obj::setData()
{
}

void clsRoadGlinkBus_Obj::createData()
{
}

void clsRoadGlinkBus_Obj::destroyData()
{
}

void clsRoadGlinkBus_Obj::requestDrawBreakEffect()
{
}

void clsRoadGlinkBus_Obj::callbackContactTriggerRigidBody(
    const hkContactPointConfirmedEvent& rParam1)
{
}

void clsRoadGlinkBus_Obj::drawEffect(clsPlayerTask* pcPlayer)
{
}

void clsRoadGlinkBus_Obj::draw(clsModelType_OB_TX& rcObj,
                               f32 (*psMtxPal)[4][4],
                               u32* psNodeStat,
                               const f32 (*opaNnViewMtx)[4][4],
                               f32 (*psMtxWork)[4][4],
                               u32 u32ViewNo)
{
}

clsRoadGlinkBus_Task::clsRoadGlinkBus_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsRoadGlinkBus_Task, clsRoadGlinkBus_Obj, clsModelType_OB_TX>(
          u32ObjectAreaNum, 0)
{
}

void clsRoadGlinkBus_Task::reset()
{
}

void clsRoadGlinkBus_Task::execute()
{
}

void clsRoadGlinkBus_Task::draw()
{
}

clsRoadGlinkBus_Obj::clsRoadGlinkBus_Obj()
{
}

clsRoadGlinkBus_Obj::~clsRoadGlinkBus_Obj()
{
}
