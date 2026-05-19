#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage16/St16AutoRunHeli.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Pendulum.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/PendulumControl.hpp"

f32 clsAutoRunHeli::m_tof32CLIP_DISTx2 = 0.0f;

namespace nspAutoRunHeli {
static u8 tau8PathNo[3] = {0, 1, 2};
static NNS_VECTOR tosThrColPosVec = {-33.0f, 124.3f, -547.2f};
static stcInfoParam tosCraneParam = {7.0f, 8.0f, 10.0f, 50.0f, 2.4f, 1.2f};
static stcInfoParam tosPlayerParam = {0.6f, 10.0f, 10.0f, 35.0f, 0.4f, 1.4f};
static stcControlParam tosControlParam = {0.009259259f,
                                          2,
                                          {5.0f, 10.0f, 0.0f, 0.0f},
                                          {1.2f, 1.5f, 0.0f, 0.0f},
                                          {{5.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
                                           {5.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
                                           {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
                                           {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}};
static NNS_VECTORFAST tosPlayerOffsetPosFast00 = {0.1f, 0.0f, -0.85f, 1.0f};
static NNS_VECTORFAST tosPlayerOffsetPosFast01 = {0.1f, 0.0f, -0.85f, 1.0f};
} // namespace nspAutoRunHeli

void clsAutoRunHeli::setStartWait(clsAutoRunHeli_Obj* pcObj)
{
}

void clsAutoRunHeli::start(clsPlayerTask* pcPlayerTask, clsAutoRunHeli_Obj* pcObj)
{
}

u8 clsAutoRunHeli::movePath(bool bFunc)
{
    return 0;
}

void clsAutoRunHeli::getPathRotQuat(NNS_QUATERNION& rsRotQuat)
{
}

void clsAutoRunHeli::getEffectPosVecFast(NNS_VECTORFAST& rsPosVecFast)
{
}

void clsAutoRunHeli::execute()
{
}

u8 clsAutoRunHeli::draw(clsAutoRunHeliModel& rcModel,
                        f32 (*psMtxPal)[4][4],
                        u32* psNodeStat,
                        const f32 (*opaNnViewMtx)[4][4],
                        f32 (*psMtxWork)[4][4],
                        u32 u32ViewNo,
                        u32 NodeStatus)
{
    return 0;
}

void clsAutoRunHeli_Obj::init()
{
}

void clsAutoRunHeli_Obj::reset()
{
}

void clsAutoRunHeli_Obj::createData()
{
}

void clsAutoRunHeli_Obj::destroyData()
{
}

void clsAutoRunHeli_Obj::contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

clsAutoRunHeli* clsAutoRunHeli_Obj::getMoveModeCmp(clsAutoRunHeli::enmMoveMode eMoveMode)
{
    return 0;
}

void clsAutoRunHeli_Task::reset()
{
}

void clsAutoRunHeli_Task::createModel(stcBinInfo& rsBinInfoI)
{
}

void clsAutoRunHeli_Task::execute()
{
}

void clsAutoRunHeli_Task::draw()
{
}

clsAutoRunHeli_Task::clsAutoRunHeli_Task(u32 u32ObjectAreaNum) : clsBaseGimmickBody(0, 0)
{
}

clsAutoRunHeli_Task::~clsAutoRunHeli_Task()
{
}
