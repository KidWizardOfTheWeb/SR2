#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaStorm.hpp"

stcParam clsCharaStorm::sStormLineParam = {};

f32 clsCharaStorm::tof32CollisionRadius = 0.6f;

clsCharaStorm::clsCharaStorm(clsPlayerTask* pcPlayer, u8 u8Param2)
    : clsCharaNodeBase(pcPlayer, u8Param2, 0)
{
}

void clsCharaStorm::behavior()
{
}

void clsCharaStorm::initAttack00()
{
}

void clsCharaStorm::initAttack01()
{
}

void clsCharaStorm::actionAttack00()
{
}

void clsCharaStorm::actionAttack01()
{
}

void clsCharaStorm::loadAdditionalData(stcBinInfo& rsBinInfo)
{
}

clsCharaStorm::~clsCharaStorm()
{
}

f32 clsCharaStorm::getCollisionRadius() const
{
    return tof32CollisionRadius;
}

f32 clsCharaStorm::getDrawOffset() const
{
    return 0.0f;
}
