#include "Develop/Projects/SR2/pgm/src/Game/SurvivalRelayRace.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Performance.hpp"

namespace {
static enmWalkType cosenmWalkRanSpeedType[17] = {WALK_PRFM_SVLRACE_USUALLY,
                                                 WALK_PRFM_SVLRACE_USUALLY,
                                                 WALK_PRFM_SVLRACE_USUALLY,
                                                 WALK_PRFM_SVLRACE_USUALLY,
                                                 WALK_PRFM_SVLRACE_USUALLY,
                                                 WALK_PRFM_SVLRACE_USUALLY,
                                                 WALK_PRFM_SVLRACE_USUALLY,
                                                 WALK_PRFM_SVLRACE_USUALLY,
                                                 WALK_PRFM_SVLRACE_USUALLY,
                                                 WALK_PRFM_SVLRACE_USUALLY,
                                                 WALK_PRFM_SVLRACE_USUALLY,
                                                 WALK_PRFM_SVLRACE_USUALLY,
                                                 WALK_PRFM_SVLRACE_USUALLY,
                                                 WALK_PRFM_SVLRACE_USUALLY,
                                                 WALK_PRFM_SVLRACE_USUALLY,
                                                 WALK_PRFM_SVLRACE_USUALLY,
                                                 WALK_PRFM_SVLRACE_USUALLY};
static s32 tos32BonusStepLength = 10;
static u8 chk__tof32BonusSpeedTable_SizeCheck_[1];
static u8 chk__tof32BonusAgpTable_SizeCheck_[1];
static u8 chk__tof32BonusRateTable_SizeCheck_[1];
static f32 tof32BonusSpeedTable[10] = {0.25463f,
                                       0.277778f,
                                       0.300926f,
                                       0.324074f,
                                       0.347222f,
                                       0.37037f,
                                       0.393519f,
                                       0.416667f,
                                       0.439815f,
                                       0.462963f};
static f32 tof32BonusAgpTable[10] = {
    10.0f, 15.0f, 20.0f, 25.0f, 30.0f, 35.0f, 40.0f, 45.0f, 50.0f, 55.0f};
static f32 tof32BonusRateTable[10] = {0.0f, 0.0f, 0.0f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f};
static stcCamFilter tof32StartInFilter = {{0.0f, -10.0f, 10.0f},
                                          {0.0f, 1.0f, 2.0f},
                                          0.0f,
                                          0,
                                          0,
                                          0,
                                          0,
                                          0,
                                          0.0f,
                                          60.0f,
                                          -1.0f,
                                          180.0f,
                                          0,
                                          0};
static f32 cosf32WalkRanBack[17] = {0.0f,
                                    10.0f,
                                    10.0f,
                                    10.0f,
                                    10.0f,
                                    10.0f,
                                    0.0f,
                                    10.0f,
                                    10.0f,
                                    10.0f,
                                    10.0f,
                                    0.0f,
                                    5.0f,
                                    10.0f,
                                    10.0f,
                                    5.0f,
                                    10.0f};
} // namespace

u32 clsSurvivalRelayRace_Task::m_u32BattleCount;
u32 clsSurvivalRelayRace_Task::m_au32PlayerWinCount[4];

void clsSurvivalRelayRace_Task::setPlayerGear(u32 u32Param1, stcSendAdv* pParam2)
{
}

clsSurvivalRelayRace_Task::clsSurvivalRelayRace_Task(
    s32 p1, s32 p2, s32 p3, s32 p4, s32 p5, const stcSendAdv* p6, void** p7, enmMode p8)
    : clsBaseRace_Task(p1, p2, p3, p4, p5, p6, p7, p8, 0)
{
}

void clsSurvivalRelayRace_Task::requestReadEtc()
{
}

u8 clsSurvivalRelayRace_Task::packEtc()
{
    return 0;
}

void clsSurvivalRelayRace_Task::initStartCamMotion()
{
}

void clsSurvivalRelayRace_Task::endStartCamMotion()
{
}

void clsSurvivalRelayRace_Task::endDemoSetting()
{
}

u8 clsSurvivalRelayRace_Task::checkGoalPlayer()
{
    return 0;
}

void clsSurvivalRelayRace_Task::updateRanking()
{
}

void clsSurvivalRelayRace_Task::SettingNextPlayer(s32 s32Param1,
                                                  u32 u32Param2,
                                                  const NNS_VECTORFAST* pParam3,
                                                  const NNS_VECTOR* pParam4,
                                                  const NNS_VECTOR* pParam5)
{
}

void clsSurvivalRelayRace_Task::StartDash(clsPlayerTask* pParam1)
{
}

void clsSurvivalRelayRace_Task::ChangeNextPlayer(
    s32 s32Param1, s32 s32Param2, s32 s32Param3, s32 s32Param4, bool bParam5)
{
}

void clsSurvivalRelayRace_Task::WalkRanAreaGoesOutPlayer(s32 s32Param1)
{
}

void clsSurvivalRelayRace_Task::execute()
{
}

void clsSurvivalRelayRace_Task::draw()
{
}
