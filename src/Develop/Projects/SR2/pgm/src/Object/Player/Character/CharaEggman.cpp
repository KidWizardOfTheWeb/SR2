#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaEggman.hpp"

f32 clsCharaEggman::tof32CollisionRadius = 0.6f;
f32 tof32MufflerOffset;
f32 tof32MufflerRange1;
f32 tof32MufflerRange2;
f32 tof32MufflerRange3;

clsCharaEggman::clsCharaEggman(clsPlayerTask* pcPlayer, u8 u8ModelType)
    : clsCharacter(pcPlayer, u8ModelType, 0)
{
}

void clsCharaEggman::behavior()
{
}

void clsCharaEggman::initAttack00()
{
}

void clsCharaEggman::initAttack01()
{
}

void clsCharaEggman::actionAttack00()
{
}

void clsCharaEggman::actionAttack01()
{
}

s8 clsCharaEggman::getNodeIndex(clsCharacter::enmCharaBornNo eIndex) const
{
    return 0;
}

void clsCharaEggman::draw(u32 u32AddDrawFlagI)
{
}

void clsCharaEggman::loadAdditionalData(stcBinInfo& rsBinInfo)
{
}
