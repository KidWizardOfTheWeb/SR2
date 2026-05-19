#include "Develop/Projects/SR2/pgm/src/Game/BaseRace.hpp"
#include "Develop/Projects/SR2/pgm/src/Config/nspStartCam.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"

namespace {
static f32 tof32StartCamFrame[4] = {120.0f, 120.0f, 140.0f, 140.0f};
static f32 tof32StartCamFrame4[4] = {120.0f, 120.0f, 180.0f, 180.0f};
static stcParam oasGCtrlLineParam = {2,
                                     1,
                                     0xFF,
                                     0xFF,
                                     37,
                                     16,
                                     0xFFFFFFFF,
                                     0.0f,
                                     1.0f,
                                     {0.15f, 0.15f, 0.0f, 0.0f},
                                     {0.0f, 0.05f, 0.0f, 0.0f}};
} // namespace

c8* clsBaseRace_Task::m_toac8StageName_Debug[17];

clsBaseRace_Task::clsBaseRace_Task(s32 s32Param1,
                                   s32 s32Param2,
                                   s32 s32Param3,
                                   s32 s32Param4,
                                   s32 s32Param5,
                                   const stcSendAdv* pParam6,
                                   void** pvParam7,
                                   enmMode,
                                   s32 s32Param9)
    : clsTask(0, 0)
{
}

clsBaseRace_Task::~clsBaseRace_Task()
{
}

void clsBaseRace_Task::LoadStageData(s32 s32Param1)
{
}

void clsBaseRace_Task::init()
{
}

u8 clsBaseRace_Task::packMap()
{
    return 0;
}

void clsBaseRace_Task::addReadChara(
    oostd::clsOOSet<u32, std::less<u32>, oostd::clsOOStlAllocator<u32> >* pcParam1)
{
}

void clsBaseRace_Task::addReadGear(
    oostd::clsOOSet<u32, std::less<u32>, oostd::clsOOStlAllocator<u32> >* pcParam1, u32* pu32Param2)
{
}

void clsBaseRace_Task::addReadCharaMotion(
    std::vector<const clsGameMgr::stcSendAdv*, std::allocator<const clsGameMgr::stcSendAdv*> >*
        pcParam1)
{
}

void clsBaseRace_Task::requestReadChara()
{
}

void clsBaseRace_Task::requestReadGear()
{
}

void clsBaseRace_Task::requestReadCharaMotion()
{
}

void clsBaseRace_Task::requestReadEtc()
{
}

u8 clsBaseRace_Task::packMotion()
{
    return 0;
}

u8 clsBaseRace_Task::setSeData()
{
    return 0;
}

u8 clsBaseRace_Task::packEtc()
{
    return 0;
}

void clsBaseRace_Task::start()
{
}

void clsBaseRace_Task::settingPlayer()
{
}

void clsBaseRace_Task::restart()
{
}

u8 clsBaseRace_Task::countDown()
{
    return 0;
}

void clsBaseRace_Task::setRaceTime(u32 u32Param1,
                                   s32 s32Param2,
                                   s32 s32Param3,
                                   s32 s32Param4,
                                   s32 s32Param5,
                                   s32 s32Param6,
                                   s32 s32Param7)
{
}

void clsBaseRace_Task::setSendAdv(const stcSendAdv* pParam1)
{
}

s8 clsBaseRace_Task::chkPadConnect(u32* pParam1)
{
    return 0;
}

void clsBaseRace_Task::setPauseScreen(s32 s32Param1, enmPadConnectDraw)
{
}

void clsBaseRace_Task::setPauseReslutScreen(s32 s32Param1)
{
}

void clsBaseRace_Task::setBestTime()
{
}

void clsBaseRace_Task::checkPause(s32 s32Param1)
{
}

void clsBaseRace_Task::checkPauseResult(s32 s32Param1)
{
}

void clsBaseRace_Task::copyCharaMotionTable(nspChara::enmCharaType, nspGame::stcMotionTable* (&)[8])
{
}

u8 clsBaseRace_Task::checkGoalPlayer()
{
    return 0;
}

void clsBaseRace_Task::updateRanking()
{
}

void clsBaseRace_Task::setGoalComPlayer()
{
}

void clsBaseRace_Task::setComPlannedRank()
{
}

void clsBaseRace_Task::setStartCamMotion(enmCamMotionNo,
                                         const NNS_VECTORFAST* pParam2,
                                         const NNS_QUATERNION* pParam3)
{
}

void clsBaseRace_Task::initStartCamMotion()
{
}

void clsBaseRace_Task::endStartCamMotion()
{
}

void clsBaseRace_Task::setPlayerStartCamData(u32 u32Param1)
{
}

u8 clsBaseRace_Task::updateStartCamMotion()
{
    return 0;
}

void clsBaseRace_Task::execGoal()
{
}

void clsBaseRace_Task::endDemoSetting()
{
}

void clsBaseRace_Task::setFreeRaceUnlock()
{
}

void clsBaseRace_Task::setStoryUnlock()
{
}

void clsBaseRace_Task::execute()
{
}

void clsBaseRace_Task::selectedPauseMenu_RET___RESTART()
{
}

void clsBaseRace_Task::selectedPauseMenu_RET___EXIT()
{
}

void clsBaseRace_Task::selectedPauseMenu_RET___CANCEL()
{
}
