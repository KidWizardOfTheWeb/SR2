#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaSilver.hpp"

stcParam clsCharaSilver::sSilverLineParam = {256, /* 0x100 */
                                             255,
                                             255,
                                             852005,     /* 0xD0025 */
                                             -754983681, /* -0x2D002301 */
                                             0.0f,
                                             1.0f,
                                             0.0f};

f32 clsCharaSilver::tof32CollisionRadius = 0.6f;

clsCharaSilver::clsCharaSilver(clsPlayerTask* pcPlayer, u8 u8ModelType)
    : clsCharaNodeBase(pcPlayer, u8ModelType, 0)
{
}

void clsCharaSilver::behavior()
{
}

void clsCharaSilver::initAttack00()
{
}

void clsCharaSilver::initAttack01()
{
}

void clsCharaSilver::actionAttack00()
{
}

void clsCharaSilver::actionAttack01()
{
}

void clsCharaSilver::loadAdditionalData(stcBinInfo& rsBinInfo)
{
}
