#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaShadow.hpp"

f32 clsCharaShadow::tof32CollisionRadius = 0.6f;

clsCharaShadow::clsCharaShadow(clsPlayerTask* pcPlayer, u8 u8ModelType)
    : clsCharaNodeBase(pcPlayer, u8ModelType, 0)
{
}

void clsCharaShadow::behavior()
{
}

void clsCharaShadow::initAttack00()
{
}

void clsCharaShadow::initAttack01()
{
}

void clsCharaShadow::actionAttack00()
{
}

void clsCharaShadow::actionAttack01()
{
}

void clsCharaShadow::drawAttackEffect()
{
}

void clsCharaShadow::loadAdditionalData(stcBinInfo& rsBinInfo)
{
}

void clsCharaShadow::draw(u32 u32AddDrawFlagI)
{
}

f32 clsCharaShadow::getCollisionRadius() const
{
    return tof32CollisionRadius;
}

f32 clsCharaShadow::getDrawOffset() const
{
    return 0.0f;
}
