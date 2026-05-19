#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03Macross.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Pendulum.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/PendulumControl.hpp"

f32 clsMacross_Obj::tof32CLIP_DISTx2 = 0.0f;
f32 clsMacross::tof32CLIP_DISTx2 = 0.0f;
NNS_VECTORFAST clsMacross::tosPlayerOffsetPosFast = {0.0f, 0.0f, -0.45f, 1.0f};

namespace nspMacross {
NNS_VECTOR tosPosVec = {640.0f, -8.0f, -99.0f};
static stcInfoParam tosCraneParam = {3.24f, 8.0f, 25.0f, 50.0f, 2.4f, 1.2f};
static stcInfoParam tosPlayerParam = {0.6f, 10.0f, 25.0f, 35.0f, 0.4f, 1.4f};
static stcControlParam tosControlParam = {0.008333334f,
                                          2,
                                          {10.0f, 20.0f, 0.0f, 0.0f},
                                          {1.2f, 1.5f, 0.0f, 0.0f},
                                          {{10.0f, 20.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
                                           {15.0f, 30.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
                                           {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
                                           {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}};
} // namespace nspMacross

void clsMacrossThroughCollision::create(const NNS_VECTOR& orsPosVec, f32 f32RotY)
{
}

void clsMacrossThroughCollision::contactTriggerEvent(clsPlayerTask* pcPlayer)
{
}

void clsMacross_Obj::init()
{
}

void clsMacross_Obj::createData()
{
}

void clsMacross_Obj::destroyData()
{
}

void clsMacross_Obj::contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

clsMacross_Task::clsMacross_Task(u32 u32ObjectAreaNum)
    : clsBaseGimmickBody<clsMacross_Task, clsMacross_Obj, clsModelType_OB_TX>(u32ObjectAreaNum, 0)
{
}

void clsMacross_Task::reset()
{
}

void clsMacross_Task::createModel(stcBinInfo& rsBinInfoI)
{
}

void clsMacross_Task::execute()
{
}

void clsMacross_Task::draw()
{
}

u8 clsMacross::draw(clsMacrossModels& rcModels,
                    f32 (*psMtxPal)[4][4],
                    u32* psNodeStat,
                    const f32 (*opaNnViewMtx)[4][4],
                    f32 (*psMtxWork)[4][4],
                    u32 u32ViewNo,
                    u32 NodeStatus)
{
    return 0;
}
