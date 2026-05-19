#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/Character.hpp"

static u8 chk__clsCharacter_m_toaFalseStartOffsetVec_SizeCheck_[1];

f32 clsCharacter::t_of32OffsetWalkHeight = -0.02f;
f32 clsCharacter::t_of32OffsetGearHeight = 0.8f;
NNS_VECTORFAST clsCharacter::m_toaFalseStartOffsetVec[19];
f32 t_of32OffsetSkateHeight;

clsCharacter::clsCharacter(clsPlayerTask* pcPlayer, u8 u8Type, u8 u8ModelType)
{
}

u32 clsCharacter::holdAttackBase()
{
    return 0;
}

void clsCharacter::addAttackMotionFrame()
{
}

void clsCharacter::drawAttackEffect()
{
}

void clsCharacter::draw(u32 u32AddDrawFlagI)
{
}

u8 clsCharacter::isBehaviorMotion(const nspChara::stcMotionFlgs* oapsMotionFlg)
{
    return 0;
}

f32 clsCharacter::getSpeedRate()
{
    return 0.0f;
}

f32 clsCharacter::checkPlayRangeAttackSe()
{
    return 0.0f;
}

void clsCharacter::setShadowMatrix()
{
}
