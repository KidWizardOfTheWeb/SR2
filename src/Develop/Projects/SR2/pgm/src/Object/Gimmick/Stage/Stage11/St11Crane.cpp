#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/St11Crane.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Pendulum.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/PendulumControl.hpp"

f32 clsCrane::m_tof32CLIP_DISTx2 = 0.0f;

namespace nspCrane {
static stcInfoParam tosCraneParamSt11 = {3.24f, 8.0f, 25.0f, 50.0f, 2.4f, 1.2f};
static stcInfoParam tosCraneParamSt14 = {4.54f, 8.0f, 25.0f, 50.0f, 2.4f, 1.2f};
static stcInfoParam tosPlayerParam = {0.6f, 10.0f, 25.0f, 35.0f, 0.4f, 1.4f};
static stcControlParam tosControlParam = {0.008333334f,
                                          2,
                                          {10.0f, 20.0f, 0.0f, 0.0f},
                                          {1.2f, 1.5f, 0.0f, 0.0f},
                                          {{10.0f, 20.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
                                           {15.0f, 30.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
                                           {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
                                           {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}};
static NNS_VECTORFAST tosPlayerOffsetPosFast00 = {0.2f, -3.54f, -0.45f, 1.0f};
static NNS_VECTORFAST tosPlayerOffsetPosFast01 = {0.0f, 0.0f, -0.45f, 1.0f};
} // namespace nspCrane

void clsCrane::start(clsPlayerTask* pcPlayerTask, clsCrane_Obj* pcObj)
{
}

void clsCrane::execute()
{
}

u8 clsCrane::draw(clsModelType_OB_TX& rcModel,
                  f32 (*psMtxPal)[4][4],
                  u32* psNodeStat,
                  const f32 (*opaNnViewMtx)[4][4],
                  f32 (*psMtxWork)[4][4],
                  u32 u32ViewNo,
                  u32 NodeStatus)
{
    return 0;
}

void clsCrane_Obj::createData()
{
}

void clsCrane_Obj::destroyData()
{
}

void clsCrane_Obj::contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

void clsCrane_Task::reset()
{
}

void clsCrane_Task::execute()
{
}

void clsCrane_Task::draw()
{
}

clsCrane::clsCrane()
{
}

clsCrane::~clsCrane()
{
}
