#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/Missile/SvlBtlMissileTask.hpp"

NNS_VECTORFAST clsSvlBtlMissile_Task::m_OffsetPosVecFastTable[4] = {
    {1.0f, 0.5f, -1.0f, 1.0f},
    {-1.0f, 0.5f, -1.0f, 1.0f},
    {0.5f, 1.3f, -2.0f, 1.0f},
    {-0.5f, 1.3f, -2.0f, 1.0f},
};
f32 tof32LockOnDorPro;
f32 tof32LockOnRangeSq;
f32 tofShootIntervalFrame;

void clsSvlBtlMissile_Task::reset()
{
}

void clsSvlBtlMissile_Task::execute()
{
}

void clsSvlBtlMissile_Task::draw()
{
}

s32 clsSvlBtlMissile_Task::calcSetupMissileNum(s32 s32PlayerNo, s32 s32Num)
{
    return 0;
}

void clsSvlBtlMissile_Task::setupMissile(s32 s32PlayerNo, s32 s32Num)
{
}

void clsSvlBtlMissile_Task::lockonMissile(s32 s32PlayerNo)
{
}

void clsSvlBtlMissile_Task::shootMissile(s32 s32PlayerNo)
{
}

void clsSvlBtlMissile_Task::lostMissile(s32 s32PlayerNo)
{
}

void clsSvlBtlMissile_Task::setLockOnPlayer(f32 f32Distance,
                                            s32 s32PlayerNo,
                                            s32 s32TargetNo,
                                            enmLockOnPlayerType eType)
{
}

void clsSvlBtlMissile_Task::cancelDrawTargetLockOnAll(s32 s32PlayerNo)
{
}
