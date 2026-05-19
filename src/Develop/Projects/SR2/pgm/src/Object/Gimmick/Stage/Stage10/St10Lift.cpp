#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage10/St10Lift.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Pendulum.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/PendulumControl.hpp"

static f32 tof32RotY;

namespace nspLift {
static stcInfoParam tosCraneParam = {8.24f, 9.0f, 13.0f, 24.0f, 12.4f, 0.5f};
static stcInfoParam tosPlayerParam = {0.6f, 30.0f, 10.0f, 35.0f, 0.4f, 1.0f};
static stcControlParam tosControlParam = {0.009259259f,
                                          2,
                                          {10.0f, 20.0f, 0.0f, 0.0f},
                                          {1.2f, 1.5f, 0.0f, 0.0f},
                                          {{10.0f, 20.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
                                           {15.0f, 30.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
                                           {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
                                           {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}};
} // namespace nspLift

NNS_VECTOR clsLiftThroughCollision::tosPosVec = {-18.0f, -90.0f, -267.0f};
f32 clsLift_Obj::tof32CLIP_DISTx2 = 0.0f;
NNS_VECTOR clsLift_Obj::tosPosVec = {-141.3f, -189.3f, -156.4f};
f32 clsLift::tof32CLIP_DISTx2 = 0.0f;
NNS_VECTORFAST clsLift::tosPlayerOffsetPosFast = {0.0f, 0.0f, -0.45f, 1.0f};

void clsLiftThroughCollision::contactTriggerEvent(clsPlayerTask* pcPlayer)
{
}

void clsLift_Obj::init()
{
}

void clsLift_Obj::createData()
{
}

void clsLift_Obj::destroyData()
{
}

void clsLift_Obj::contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

clsLift_Task::clsLift_Task(u32 u32ObjectAreaNum)
    : clsBaseGimmickBody<clsLift_Task, clsLift_Obj, clsModelType_OB_TX>(0, 0)
{
}

void clsLift_Task::reset()
{
}

void clsLift_Task::createModel(stcBinInfo& rsBinInfoI)
{
}

void clsLift_Task::execute()
{
}

void clsLift_Task::draw()
{
}

u8 clsLift::draw(clsLiftModels& rcModels,
                 f32 (*psMtxPal)[4][4],
                 u32* psNodeStat,
                 const f32 (*opaNnViewMtx)[4][4],
                 f32 (*psMtxWork)[4][4],
                 u32 u32ViewNo,
                 u32 NodeStatus)
{
    return 0;
}
