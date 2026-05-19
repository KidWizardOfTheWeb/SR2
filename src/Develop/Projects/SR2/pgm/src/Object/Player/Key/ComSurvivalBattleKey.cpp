#include "Develop/Projects/SR2/pgm/src/Object/Player/Key/ComSurvivalBattleKey.hpp"

f32 tof32ModeRunFrame_MoveItemBox;
f32 tof32ModeRunFrame_MoveCourse;
f32 tof32ModeRunFrame_EscapeMissile;
f32 tof32ModeRunFrame_SearchPlayer;

static s32 toas32OddsTabele_Bomb[2][5] = {
    {80, 10, 0, 10, 0},
    {60, 10, 30, 0, 0},
};

static s32 toas32OddsTabele_Missile[2][5] = {
    {80, 10, 10, 0, 0},
    {50, 20, 0, 30, 0},
};

static s32 toas32OddsTabele_Noting[5] = {0, 0, 0, 30, 70};

u32 clsComSurvivalBattleKey::execWalk()
{
    return 0;
}

u32 clsComSurvivalBattleKey::execRun()
{
    return 0;
}

u32 clsComSurvivalBattleKey::execGCtrlSlide()
{
    return 0;
}

void clsComSurvivalBattleKey::selectMode()
{
}

void clsComSurvivalBattleKey::selectModeOddsTable(const s32* pParam1)
{
}

void clsComSurvivalBattleKey::calcRotateTargetPoint(stcRotateData* pParam1,
                                                    const NNS_VECTORFAST* pParam2)
{
}

void clsComSurvivalBattleKey::calcMoveCourse(NNS_VECTORFAST* pParam1)
{
}

void clsComSurvivalBattleKey::calcMoveItemBox(NNS_VECTORFAST* pParam1)
{
}

u8 clsComSurvivalBattleKey::controlGoalTime(s8 s8Param1)
{
    return 0;
}
