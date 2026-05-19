#include "Develop/Projects/SR2/pgm/src/Game/SurvivalBattleRace.hpp"

f32 clsSurvivalBattleRace_Task::tof32PlayerScale = 1.75f;
f32 clsSurvivalBattleRace_Task::tof32ItemBoxScale = 1.5f;
s32 clsSurvivalBattleRace_Task::toas32SettingLifeTable[3] = {3, 6, 9};
s32 clsSurvivalBattleRace_Task::toas32SettingTimeTable[3] = {3, 5, 10};
u32 clsSurvivalBattleRace_Task::m_u32BattleCount;
u32 clsSurvivalBattleRace_Task::m_au32PlayerWinCount[4];
f32 tof32AttackCureAgp;
f32 tof32DefaultAgp;
f32 tof32GCtrlInvalidFrame;
f32 tof32GCtrlMaxSpeed;
f32 tof32GCtrlMinSpeed;
f32 tof32GCtrlRange;
f32 tof32GCtrlRotateAcceleRate;
f32 tof32GCtrlRotateAcceleX;
f32 tof32GCtrlRotateAcceleY;
f32 tof32GCtrlSlideSlowdownFrame;
f32 tof32GCtrlUsedRate;
f32 tof32GDiveRange;
f32 tof32GDiveUsedRate;
f32 tof32SystemGDiveReadyFrame;
s32 tos32DefaultPointLife;
s32 tos32DefaultSuddenDeathTimeSec;

clsSurvivalBattleRace_Task::clsSurvivalBattleRace_Task(enmRule eRule,
                                                       enmSetting eSetting,
                                                       s32 s32Param0,
                                                       s32 s32Param1,
                                                       s32 s32Param2,
                                                       const stcSendAdv* pcSendAdv,
                                                       void** ppvParam,
                                                       enmMode eMode)
    : clsBaseRace_Task(s32Param0, s32Param1, s32Param2, 0, 0, pcSendAdv, ppvParam, eMode, 0)
{
}

s32 clsSurvivalBattleRace_Task::getLifeMax()
{
    return 0;
}

void clsSurvivalBattleRace_Task::requestReadEtc()
{
}

u8 clsSurvivalBattleRace_Task::packEtc()
{
    return 0;
}

void clsSurvivalBattleRace_Task::execute()
{
}

void clsSurvivalBattleRace_Task::draw()
{
}

void clsSurvivalBattleRace_Task::mainSuddenDeathRule()
{
}

void clsSurvivalBattleRace_Task::damegeMissile(clsPlayerTask* pcAttacker, clsPlayerTask* pcTarget)
{
}

void clsSurvivalBattleRace_Task::damegeBomb(clsPlayerTask* pcAttacker, clsPlayerTask* pcTarget)
{
}

void clsSurvivalBattleRace_Task::damegeGimmick(clsPlayerTask* pcTarget)
{
}

void clsSurvivalBattleRace_Task::damegeGravity(clsPlayerTask* pcAttacker, clsPlayerTask* pcTarget)
{
}

void clsSurvivalBattleRace_Task::damegeFall(clsPlayerTask* pcTarget)
{
}
