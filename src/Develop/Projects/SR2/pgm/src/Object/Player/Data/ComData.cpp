#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/ComData.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Key/ComAI.hpp"

namespace nspCom {
_ComStartParam oasComStartParam[7] = {{0, 0.0027777778450399637f},
                                      {10, 0.002314814832061529f},
                                      {20, 0.0020833334419876337f},
                                      {30, 0.0025462962221354246f},
                                      {40, 0.002314814832061529f},
                                      {50, 0.0027777778450399637f},
                                      {60, 0.0018518518190830946f}};
enmComMode oaeComAITable_Boss[6][7];
enmComMode oaeComAITable_Free[5][4];
enmComMode oaeComAITable_Mission[5][4];
enmComMode oaeComAITable_Story[5][7];
s32 oas32GoalTime[17][7];
s32 oas32LapUpDownTime[17][2];
u32 oau32AttackMissionTime[17][14];
u32 oau32LapDownAITime[17][2];
u32 oau32LapTimeLimit[17][1];
u32 oau32MissionRemainderTime[17][4];
u32 oau32MissionTime[17][14];
u32 oau32NormalRemainderTime[17][4];
u32 oau32NormalRoundTime[17][14];
u32 oau32StoryRemainderTime[17][4];
u32 oau32StoryRoundTime[17][14];
u8 oau8GearChangeRate100[17][19][2][6];
u8 oau8HighTrickRankRate[17][4];
u8 oau8LowTrickRankRate[17][4];
u8 oau8TrickRankRate[17][7][4];
} // namespace nspCom

static u8 chk__nspCom_oas32GoalTime_SizeCheck_[1];
static u8 chk__nspCom_oas32LapUpDownTime_SizeCheck_[1];
static u8 chk__nspCom_oau32AttackMissionTime_SizeCheck_[1];
static u8 chk__nspCom_oau32LapDownAITime_SizeCheck_[1];
static u8 chk__nspCom_oau32LapTimeLimit_SizeCheck_[1];
static u8 chk__nspCom_oau32MissionRemainderTime_SizeCheck_[1];
static u8 chk__nspCom_oau32MissionTime_SizeCheck_[1];
static u8 chk__nspCom_oau32NormalRemainderTime_SizeCheck_[1];
static u8 chk__nspCom_oau32NormalRoundTime_SizeCheck_[1];
static u8 chk__nspCom_oau32StoryRemainderTime_SizeCheck_[1];
static u8 chk__nspCom_oau32StoryRoundTime_SizeCheck_[1];
static u8 chk__nspCom_oau8GearChangeRate100_2_SizeCheck_[1];
static u8 chk__nspCom_oau8GearChangeRate100_3_SizeCheck_[1];
static u8 chk__nspCom_oau8GearChangeRate100_4_SizeCheck_[1];
static u8 chk__nspCom_oau8GearChangeRate100_SizeCheck_[1];
