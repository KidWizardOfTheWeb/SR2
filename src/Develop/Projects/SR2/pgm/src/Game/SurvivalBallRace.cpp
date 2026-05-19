#include "Develop/Projects/SR2/pgm/src/Game/SurvivalBallRace.hpp"

namespace {
static u32 stcoau32RuleTime[3] = {3, 5, 10};
static u32 stcoau32RulePoint[4] = {100, 300, 500, 0};
} // namespace

namespace nspGDive {
f32 tof32ReadyFrame;
}

f32 clsSurvivalBallRace_Task::tof32ItemBoxScale = 1.2f;
_strSurvivalBallData clsSurvivalBallRace_Task::scosSurvivalBallData[4];
_strSurvivalBallData clsSurvivalBallRace_Task::m_sDbgSurvivalBallData;
u32 clsSurvivalBallRace_Task::m_u32BattleCount;
u32 clsSurvivalBallRace_Task::m_au32PlayerWinCount[4];

clsSurvivalBallRace_Task::clsSurvivalBallRace_Task(s32 s32StageNoI,
                                                   u32 u32RuleTimeType,
                                                   u32 u32RulePointType,
                                                   s32 s32PlayerNumI,
                                                   s32 s32UserNumI,
                                                   s32 s32LapNumI,
                                                   const stcSendAdv* opsSendAdvI,
                                                   void** ppvMapBufferI,
                                                   enmMode eModeI)
    : clsBaseRace_Task(s32StageNoI,
                       (s32)u32RuleTimeType,
                       (s32)u32RulePointType,
                       s32PlayerNumI,
                       s32UserNumI,
                       opsSendAdvI,
                       ppvMapBufferI,
                       eModeI,
                       s32LapNumI)
{
} // [verify params from ASM]

u32 clsSurvivalBallRace_Task::getMaxPoint()
{
    return 0;
}

void clsSurvivalBallRace_Task::requestReadEtc()
{
}

u8 clsSurvivalBallRace_Task::packEtc()
{
    return 0;
}

void clsSurvivalBallRace_Task::addPlayerPoint(u32 u32PlayerNo, s32 s32Point)
{
}

void clsSurvivalBallRace_Task::updateRanking()
{
}

void clsSurvivalBallRace_Task::execute()
{
}

void clsSurvivalBallRace_Task::draw()
{
}
