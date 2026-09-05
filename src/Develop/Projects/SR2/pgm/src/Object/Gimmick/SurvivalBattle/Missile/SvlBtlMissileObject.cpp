#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/Missile/SvlBtlMissileObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"

static clsBackLineEffectTask::stcParam sSvlBtlMissileLineParam[20];
static stcGimickSubParam sSvlBtlMissileLineSubParam;

NNS_VECTOR clsSvlBtlMissile_Object::tosCollisionHalfSizeVec = {0.08f, 0.08f, 0.95f};
f32 clsSvlBtlMissile_Object::tof32ClipSqDist = 0.0f;
f32 tof32ShootSpeed;
f32 tof32CruiseSpeed;
f32 tof32ShootFrame;
f32 tof32CruiseFrame;
f32 tof32ShootHomigRate;
f32 tof32CruiseHomingRate;
f32 tof32PlayerHitRange;
NNS_VECTOR clsSvlBtlMissile_Object::tosOffsetVec_1st = {0.0f, 8.0f, 40.0f};
NNS_VECTOR clsSvlBtlMissile_Object::tosAccurcayVec_1st = {5.0f, 3.0f, 5.0f};
f32 tof32RangeDotPro_1st;
NNS_VECTOR clsSvlBtlMissile_Object::tosOffsetVec_2nd = {0.0f, 0.0f, 18.0f};
NNS_VECTOR clsSvlBtlMissile_Object::tosAccurcayVec_2nd = {5.0f, 0.0f, 0.5f};
f32 tof32RangeDotPro_2nd;
f32 tof32HormingRate_2nd;

clsSvlBtlMissile_Object::clsSvlBtlMissile_Object()
{
}

clsSvlBtlMissile_Object::~clsSvlBtlMissile_Object()
{
}

void clsSvlBtlMissile_Object::draw(NNS_OBJECT* pParam1,
                                   f32 (*)[4][4],
                                   u32* pParam3,
                                   const f32 (*)[4][4],
                                   f32 (*)[4][4],
                                   u32 u32Param6)
{
}

void clsSvlBtlMissile_Object::reset()
{
}

void clsSvlBtlMissile_Object::main()
{
}

void clsSvlBtlMissile_Object::setData()
{
}

void clsSvlBtlMissile_Object::createData()
{
}

void clsSvlBtlMissile_Object::destroyData()
{
}

void clsSvlBtlMissile_Object::contactTriggerCallback(hkContactPointConfirmedEvent& rParam1)
{
}

void clsSvlBtlMissile_Object::callbackBreakEvent()
{
}

void clsSvlBtlMissile_Object::setup(s32 s32Param1, s32 s32Param2)
{
}

void clsSvlBtlMissile_Object::charge()
{
}

void clsSvlBtlMissile_Object::shoot(s32 s32Param1, f32 f32Param2)
{
}

void clsSvlBtlMissile_Object::checkHitPlayer()
{
}

void clsSvlBtlMissile_Object::requestDrawBreakEffect()
{
}
