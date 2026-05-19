#include "Develop/Projects/SR2/pgm/src/Game/MissionRace.hpp"

f32 clsMissionRace_Task::tof32MissionBreakFrame;
s32 clsMissionRace_Task::sos32TrickPoint[7];
stcMissionRingAgp clsMissionRace_Task::scosMissionRingAgp[20];
f32 clsMissionRace_Task::scosAgpPointRate[17];
void* clsMissionRace_Task::m_pvMission2DPackBuffer;
void* clsMissionRace_Task::m_pvMissionStg2DPackBuffer;
f32 tof32Stage15_5GDiveActionRange;

void clsMissionRace_Task::LoadTexture(clsGameMgr::enmMode eMode, s32 s32A)
{
}

clsMissionRace_Task::clsMissionRace_Task(
    s32 s32A, s32 s32B, const stcSendAdv* pcAdv, void** ppv, enmMode eMode)
    : clsBaseRace_Task(0, 0, 0, 0, 0, pcAdv, ppv, eMode, 0)
{
}

u8 clsMissionRace_Task::isBestScore(u32 u32Idx)
{
    return 0;
}

void clsMissionRace_Task::requestReadEtc()
{
}

u8 clsMissionRace_Task::packEtc()
{
    return 0;
}

void clsMissionRace_Task::setMissionParam(u8* pu8)
{
}

void clsMissionRace_Task::getAddTime(u32 u32Idx)
{
}

void clsMissionRace_Task::restart()
{
}

void clsMissionRace_Task::setPauseScreen(s32 s32A, enmPadConnectDraw ePad)
{
}

void clsMissionRace_Task::wakeUpResult()
{
}

void clsMissionRace_Task::setClearUnlock()
{
}

s8 clsMissionRace_Task::checkCondition()
{
    return 0;
}

void clsMissionRace_Task::setMissionClearUnlock()
{
}

void clsMissionRace_Task::execute()
{
}

void clsMissionRace_Task::draw()
{
}
