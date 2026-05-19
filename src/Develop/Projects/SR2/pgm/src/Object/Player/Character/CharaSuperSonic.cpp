#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaSuperSonic.hpp"

f32 clsCharaSuperSonic::tof32CollisionRadius = 0.6f;
f32 SUPER_SONIC_RATE_RING;
f32 SUPER_SONIC_RATE_RING_BOOST;
f32 SUPER_SONIC_RATE_RING_GRAVITY;
s32 SUPER_SONIC_RATE_USE_RING;
s32 SUPER_SONIC_RATE_BOOST_CHANGE;
s32 clsCharaSuperSonic::SUPER_SONIC_RATE_START_BONUS = 0;
f32 clsCharaSuperSonic::SUPER_SONIC_RATE_SPEED = 5.0f / 6.0f;
f32 SUPER_SONIC_RATE_ACCELE;
f32 clsCharaSuperSonic::SUPER_SONIC_RATE_ATTACK_FRAME = 600.0f;

clsCharaSuperSonic::clsCharaSuperSonic(clsPlayerTask* pTask, u8 a) : clsCharaNodeBase(pTask, a, 0)
{
}

void clsCharaSuperSonic::reset()
{
}

void clsCharaSuperSonic::behavior()
{
}

void clsCharaSuperSonic::draw(u32 flags)
{
}

s32 clsCharaSuperSonic::updateLimitTime(f32 dt, stcRingRateTime* pTime)
{
    return 0;
}

void clsCharaSuperSonic::updateAction()
{
}

void clsCharaSuperSonic::updateGravity()
{
}

void clsCharaSuperSonic::initAttack00()
{
}

void clsCharaSuperSonic::initAttack01()
{
}

void clsCharaSuperSonic::actionAttack00()
{
}

void clsCharaSuperSonic::drawAttackEffect()
{
}

void clsCharaSuperSonic::actionAttack01()
{
}

void clsCharaSuperSonic::loadAdditionalData(stcBinInfo& info)
{
}
