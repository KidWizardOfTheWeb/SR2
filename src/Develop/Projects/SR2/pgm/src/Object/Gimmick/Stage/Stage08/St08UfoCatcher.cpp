#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08UfoCatcher.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"

static stcParam asUfoBallLineParam[2];
static stcGimickSubParam asUfoBallLineSubParam[1];
static u8 chk__asUfoBallLineParam_SizeCheck_[1];

f32 clsUfoCatcher_Obj::t_of32ClipDistx2 = 0.0f;
NNS_VECTORFAST clsUfoCatcher_Obj::t_osPosVecFast = {-750.0f, 47.0f, -400.0f, 1.0f};
f32 clsUfoCatcher::m_tof32CLIP_DISTx2 = 0.0f;
NNS_VECTORFAST clsUfoCatcher::t_osPlayerOffstVecFast = {0.0f, 0.0f, 0.0f, 1.0f};

void clsUfoCatcher::setBall(clsPlayerTask* pcPlayerTask, clsUfoCatcher_Obj* pcObj)
{
}

void clsUfoCatcher::start(clsPlayerTask* pcPlayerTask, clsUfoCatcher_Obj* pcObj)
{
}

u8 clsUfoCatcher::stepArmFrame(f32 f32EndFrame)
{
    return 0;
}

void clsUfoCatcher::execute()
{
}

void clsUfoCatcher::draw(clsUfoCatcherModels& rcModel,
                         f32 (*psMtxPal)[4][4],
                         u32* psNodeStat,
                         const f32 (*opaNnViewMtx)[4][4],
                         f32 (*psMtxWork)[4][4],
                         u32 u32ViewNo,
                         u32 NodeStatus)
{
}

void clsUfoCatcher_Obj::init()
{
}

void clsUfoCatcher_Obj::createData()
{
}

void clsUfoCatcher_Obj::destroyData()
{
}

void clsUfoCatcher_Obj::contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2)
{
}

void clsUfoCatcher_Obj::registBall(clsPlayerTask* pcPlayer)
{
}

void clsUfoCatcher_Obj::playBallSe(clsPlayerTask* pcPlayer)
{
}

void clsUfoCatcher_Obj::stopBallSe(clsPlayerTask* pcPlayer)
{
}

void clsUfoCatcher_Obj::openDoor(f32 f32Distx2, clsPlayerTask* pcPlayer)
{
}

clsUfoCatcher* clsUfoCatcher_Obj::getStateCmp(clsUfoCatcher::enmState eState)
{
    return 0;
}

void clsUfoCatcher_Obj::execute()
{
}

void clsUfoCatcher_Obj::draw(clsUfoCatcherModels& rcModel,
                             f32 (*psMtxPal)[4][4],
                             u32* psNodeStat,
                             const f32 (*opaNnViewMtx)[4][4],
                             f32 (*psMtxWork)[4][4],
                             u32 u32ViewNo)
{
}

void clsUfoCatcher_Task::reset()
{
}

void clsUfoCatcher_Task::createModel(stcBinInfo& rsBinInfoI)
{
}

void clsUfoCatcher_Task::execute()
{
}

void clsUfoCatcher_Task::draw()
{
}

clsUfoCatcher_Task::clsUfoCatcher_Task(u32 u32ObjectAreaNum) : clsBaseGimmickBody(0, 0)
{
}

clsUfoCatcher_Task::~clsUfoCatcher_Task()
{
}
