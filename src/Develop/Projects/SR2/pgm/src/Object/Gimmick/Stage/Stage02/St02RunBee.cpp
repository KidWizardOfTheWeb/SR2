#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02RunBee.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Pendulum.hpp"

namespace {
static NNS_VECTOR tosThroughCollisionPos = {-96.0f, -246.0f, 589.0f};
}

namespace nspRunBee {
static stcInfoParam tosBeeParam = {1.0f, 11.0f, 5.5f, 50.0f, 2.4f, 1.0f};
static stcInfoParam tosPlayerParam = {0.6f, 8.0f, 0.5f, 100.0f, 0.4f, 1.0f};
static stcControlParam tosControlParam = {0.009259259f,
                                          2,
                                          {25.0f, 40.0f, 0.0f, 0.0f},
                                          {1.0f, 1.0f, 0.0f, 0.0f},
                                          {{45.0f, 30.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
                                           {60.0f, 45.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
                                           {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
                                           {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}};
} // namespace nspRunBee

NNS_VECTORFAST clsRunBee_Obj::m_tosPlayerOffsetFast = {0.0f, -1.75f, -0.4f, 1.0f};
NNS_VECTORFAST clsRunBee::tosPlayerOffsetPosFast = {0.0f, -0.3f, -0.4f, 1.0f};

void clsRunBeeCollision::contactTriggerEvent(clsPlayerTask* pcPlayer)
{
}

void clsRunBee::searchNextPath()
{
}

void clsRunBee::followPlayer()
{
}

void clsRunBee_Obj::init()
{
}

void clsRunBee_Obj::createData()
{
}

void clsRunBee_Obj::destroyData()
{
}

void clsRunBee_Obj::start(clsPlayerTask* pcPlayerTask)
{
}

void clsRunBee_Obj::setClearPlayerFlg(clsPlayerTask* pcPlayerTask)
{
}

clsRunBee_Task::clsRunBee_Task(u32 u32ObjectAreaNum) : clsBaseGimmickBody(0, 0)
{
}

void clsRunBee_Task::reset()
{
}

void clsRunBee_Task::createModel(stcBinInfo& rsBinInfoI)
{
}

void clsRunBee_Task::execute()
{
}

void clsRunBee_Task::draw()
{
}

u8 clsRunBee::draw(NNS_OBJECT* psObject,
                   f32 (*psMtxPal)[4][4],
                   u32* psNodeStat,
                   const f32 (*opaNnViewMtx)[4][4],
                   f32 (*psMtxWork)[4][4],
                   u32 NodeStatus,
                   u32 u32ViewNo)
{
    return 0;
}

clsRunBee_Task::~clsRunBee_Task()
{
}
