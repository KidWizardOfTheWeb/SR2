#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaKnuckles.hpp"

stcParam clsCharaKnuckles::sKnucklesLineParam = {256, /* 0x100 */
                                                 0,
                                                 255,
                                                 255,
                                                 852005,     /* 0xD0025 */
                                                 -535554817, /* -0x1FEBEB01 */
                                                 0.0f,
                                                 1.0f,
                                                 0.0f};

f32 clsCharaKnuckles::tof32CollisionRadius = 0.6f;

clsCharaKnuckles::clsCharaKnuckles(clsPlayerTask* pcTask, u8 u8Param1)
    : clsCharaNodeBase(pcTask, u8Param1, 0)
{
}

void clsCharaKnuckles::behavior()
{
}

void clsCharaKnuckles::initAttack00()
{
}

void clsCharaKnuckles::initAttack01()
{
}

void clsCharaKnuckles::actionAttack00()
{
}

void clsCharaKnuckles::actionAttack01()
{
}

void clsCharaKnuckles::loadAdditionalData(stcBinInfo& rsBinInfo)
{
}

clsCharaKnuckles::~clsCharaKnuckles()
{
}
