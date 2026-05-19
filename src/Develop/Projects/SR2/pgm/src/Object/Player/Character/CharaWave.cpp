#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaWave.hpp"

clsCharaWave::clsCharaWave(clsPlayerTask* pcPlayer, u8 u8ModelType)
    : clsCharaNodeBase(pcPlayer, u8ModelType, 0)
{
}

void clsCharaWave::behavior()
{
}

void clsCharaWave::initAttack00()
{
}

void clsCharaWave::initAttack01()
{
}

void clsCharaWave::actionAttack00()
{
}

void clsCharaWave::actionAttack01()
{
}

void clsCharaWave::draw(u32 u32AddDrawFlagI)
{
}

f32 clsCharaWave::getCollisionRadius() const
{
    return tof32CollisionRadius;
}

f32 clsCharaWave::getDrawOffset() const
{
    return 0.0f;
}

void clsCharaWave::loadAdditionalData(stcBinInfo& rsBinInfo)
{
}

stcParam clsCharaWave::sWaveLineParam = {};
f32 clsCharaWave::tof32CollisionRadius = 0.6f;
