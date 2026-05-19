#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaRoboBase.hpp"

f32 clsCharaRoboBase::tof32CollisionRadius = 0.6f;
s8 clsCharaRoboBase::m_tas8ConvertTable[52] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0};

void clsCharaRoboBase::reset()
{
}

void clsCharaRoboBase::updateRoboCurve()
{
}

void clsCharaRoboBase::updateLampFrame()
{
}

void clsCharaRoboBase::updateRoboRotate()
{
}

void clsCharaRoboBase::behavior()
{
}

void clsCharaRoboBase::initAttack00()
{
}

void clsCharaRoboBase::initAttack01()
{
}

void clsCharaRoboBase::actionAttack00()
{
}

void clsCharaRoboBase::actionAttack01()
{
}

void clsCharaRoboBase::updateModel()
{
}

s8 clsCharaRoboBase::getNodeIndex(enmCharaBornNo) const
{
    return 0;
}

f32 clsCharaRoboBase::getCollisionRadius() const
{
    return 0.0f;
}

f32 clsCharaRoboBase::getDrawOffset() const
{
    return 0.0f;
}
