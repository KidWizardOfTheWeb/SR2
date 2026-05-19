#include "Develop/Projects/SR2/pgm/src/Game/TimeAttack.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOFontSystem.hpp"

namespace {
static u32 TIMEATTACK_RANKING_WAIT_TIME;
static u32 GHOSTSAVE_WAIT_TIME = 240;
} // namespace

namespace nspTimeAttack2D {
_NNS_TEXLIST* psTexList_TimeAttack2D;
} // namespace nspTimeAttack2D

nspOOMisc::stcSize2d<u16> osTexSize[1];

clsTimeAttack_Task::clsTimeAttack_Task(s32 s32StageNoI,
                                       s32 s32PlayerNumI,
                                       s32 s32UserNumI,
                                       s32 s32LapNumI,
                                       const stcSendAdv* opsSendAdvI,
                                       void** ppvMapBufferI,
                                       enmMode eModeI)
    : clsBaseRace_Task(s32StageNoI,
                       s32PlayerNumI,
                       s32UserNumI,
                       s32LapNumI,
                       0,
                       opsSendAdvI,
                       ppvMapBufferI,
                       eModeI,
                       0)
{
} // [verify params from ASM]

clsTimeAttack_Task::~clsTimeAttack_Task()
{
}

void clsTimeAttack_Task::start()
{
}

void clsTimeAttack_Task::restart()
{
}

void clsTimeAttack_Task::setPauseScreen(s32 s32PushPausePadNo, enmPadConnectDraw enConnectDraw)
{
}

void clsTimeAttack_Task::setPauseReslutScreen(s32 s32PushPausePadNo)
{
}

void clsTimeAttack_Task::createGhostTask()
{
}

void clsTimeAttack_Task::addReadChara(
    oostd::clsOOSet<u32, std::less<u32>, oostd::clsOOStlAllocator<u32> >* pcCharaList)
{
}

void clsTimeAttack_Task::addReadGear(
    oostd::clsOOSet<u32, std::less<u32>, oostd::clsOOStlAllocator<u32> >* pcGearList,
    u32* pu32GearLoadCnt)
{
}

void clsTimeAttack_Task::addReadCharaMotion(
    std::vector<const clsGameMgr::stcSendAdv*, std::allocator<const clsGameMgr::stcSendAdv*> >*
        pcCharaMotionList)
{
}

void clsTimeAttack_Task::requestReadEtc()
{
}

u8 clsTimeAttack_Task::packEtc()
{
    return 0;
}

void clsTimeAttack_Task::setBestTime()
{
}

void clsTimeAttack_Task::execute()
{
}

u8 clsTimeAttack_Task::loadGhostData()
{
    return 0;
}

u8 clsTimeAttack_Task::saveGhostData()
{
    return 0;
}

void clsTimeAttack_Task::checkPauseResult(s32 bOnI)
{
}
