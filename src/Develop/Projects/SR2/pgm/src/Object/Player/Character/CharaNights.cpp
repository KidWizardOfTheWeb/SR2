#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaNights.hpp"

stcParam clsCharaNights::asNightsLineParam[2] = {
    {
        0,
        5,
        255,
        120,
        10,
        5,
        0xBEB4FFFF,
        0.0f,
        1.0f,
        {0.08f, 0.04f, -0.02f, 0.0f},
        {0.0f, 0.0f, 0.0f, 0.0f},
    },
    {
        0,
        5,
        255,
        120,
        19,
        5,
        0xBEB4FFFF,
        0.0f,
        1.0f,
        {0.08f, 0.04f, -0.02f, 0.0f},
        {0.0f, 0.0f, 0.0f, 0.0f},
    },
};

f32 clsCharaNights::tof32CollisionRadius = 0.6f;

clsCharaNights::clsCharaNights(clsPlayerTask* pcPlayer, u8 u8ModelType)
    : clsCharaNodeBase(pcPlayer, u8ModelType, 0)
{
}

void clsCharaNights::behavior()
{
}

void clsCharaNights::initAttack00()
{
}

void clsCharaNights::initAttack01()
{
}

void clsCharaNights::actionAttack00()
{
}

void clsCharaNights::actionAttack01()
{
}

void clsCharaNights::loadAdditionalData(stcBinInfo& rParam1)
{
}

clsCharaNights::~clsCharaNights()
{
}

f32 clsCharaNights::getCollisionRadius() const
{
    return 0.6f;
}

f32 clsCharaNights::getDrawOffset() const
{
    return 0.0f;
}
