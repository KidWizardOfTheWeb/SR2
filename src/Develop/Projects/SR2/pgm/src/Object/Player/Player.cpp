#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"

namespace {
static f32 NODE_VIB__ADD_CYCLE_A32 = 728.0f;
}

static stcParam oasPlayerLineParam = {1,
                                      1,
                                      0xFF,
                                      0,
                                      0x25,
                                      0x10,
                                      0xFFFFFFFF,
                                      0.0f,
                                      1.0f,
                                      {0.0f, 0.0f, 0.0f, 0.0f},
                                      {0.0f, 0.0f, 0.0f, 0.0f}};
static stcTrickSubParam oasPlayerLineTrickParam = {0x18, 0.1f, 0.2f};

static f32 toaf32StageMinimumHeightTable[17] = {-100.0f,
                                                -100.0f,
                                                -340.0f,
                                                -100.0f,
                                                -100.0f,
                                                -10000.0f,
                                                -100.0f,
                                                -100.0f,
                                                -100.0f,
                                                -100.0f,
                                                -340.0f,
                                                -100.0f,
                                                -100.0f,
                                                -100.0f,
                                                -100.0f,
                                                -300.0f,
                                                -100.0f};
static f32 toaf32RankingRingRateTable[8] = {2.0f, 1.5f, 1.2f, 1.0f, 0.8f, 0.4f, 0.2f, 0.0f};
static f32 toaf32NotDamageRingRateTable[8] = {
    1.25f, 1.25f, 1.25f, 1.25f, 1.25f, 1.25f, 1.25f, 1.25f};

f32 clsPlayerTask::t_of32DefaultMinSpeed = -5.0f / 9.0f;
f32 clsPlayerTask::t_of32TurbMinSpeed = 5.0f / 6.0f;
f32 clsPlayerTask::t_of32TurbMaxSpeed = 35.0f / 36.0f;
f32 clsPlayerTask::t_of32SurfaceAdjustScale = -0.05f;
f32 clsPlayerTask::t_of32RingRateTime = 100.0f;
f32 clsPlayerTask::t_of32RingGravityRateTime = 6.0f;
_ActionFuncTbl clsPlayerTask::t_sActionFuncTbl[34];
s32 t_os32NotReplayCamMode;

void clsPlayerTask::initWalkSpring()
{
}

void clsPlayerTask::actionWalkSpring()
{
}

void clsPlayerTask::initBoost()
{
}

void clsPlayerTask::initGearAttack()
{
}

void clsPlayerTask::initGearGDive()
{
}

void clsPlayerTask::initGearGDiveAuto()
{
}

void clsPlayerTask::initGearGCtrlTrick()
{
}

void clsPlayerTask::initGearFlight()
{
}

void clsPlayerTask::initGearJump()
{
}

void clsPlayerTask::initWalkBrake()
{
}

void clsPlayerTask::initWalkFlight()
{
}

void clsPlayerTask::initGearDirRegulateRun()
{
}

void clsPlayerTask::initGearGCtrlFlight()
{
}

void clsPlayerTask::initGearGCtrlSlide()
{
}

void clsPlayerTask::initWalkRun()
{
}

void clsPlayerTask::initWalkWait()
{
}

void clsPlayerTask::initWalkBack()
{
}

void clsPlayerTask::initDamage01()
{
}

void clsPlayerTask::initDemo()
{
}

void clsPlayerTask::initGearInertia()
{
}

void clsPlayerTask::initFalseStart()
{
}

void clsPlayerTask::initDamage00()
{
}

void clsPlayerTask::initGearRun()
{
}

void clsPlayerTask::cancelGearFly()
{
}

void clsPlayerTask::initGearPower()
{
}

void clsPlayerTask::initGearBrake()
{
}

void clsPlayerTask::initReStart()
{
}

void clsPlayerTask::actionGearGDive()
{
}

void clsPlayerTask::initAutoWallRun()
{
}

void clsPlayerTask::actionGearGDiveAuto()
{
}

void clsPlayerTask::actionGearGCtrlTrick()
{
}

void clsPlayerTask::actionGearGCtrlFlight()
{
}

void clsPlayerTask::actionGearGCtrlSlide()
{
}

void clsPlayerTask::actionGearInertia()
{
}

void clsPlayerTask::initGearTrick()
{
}

void clsPlayerTask::initGearTranslationMovePath()
{
}

void clsPlayerTask::actionBoost()
{
}

void clsPlayerTask::initGearPath()
{
}

void clsPlayerTask::initGearRail()
{
}

void clsPlayerTask::actionGearFlight()
{
}

void clsPlayerTask::actionWalkBrake()
{
}

void clsPlayerTask::actionWalkWait()
{
}

void clsPlayerTask::actionDemo()
{
}

void clsPlayerTask::actionWalkFlight()
{
}

void clsPlayerTask::actionFalseStart()
{
}

void clsPlayerTask::actionWalkRun()
{
}

void clsPlayerTask::actionWalkBack()
{
}

void clsPlayerTask::actionGearBrake()
{
}

void clsPlayerTask::actionGearAttack()
{
}

void clsPlayerTask::actionGearRun()
{
}

void clsPlayerTask::initWheelDrift()
{
}

void clsPlayerTask::actionAutoWallRun()
{
}

void clsPlayerTask::actionReStart()
{
}

void clsPlayerTask::actionGearJump()
{
}

void clsPlayerTask::actionGearPower()
{
}

void clsPlayerTask::setActionType(clsPlayerTask::enmActionType eType)
{
}

void clsPlayerTask::actionGearDirRegulateRun()
{
}

void clsPlayerTask::endGearFly()
{
}

void clsPlayerTask::actionDamage01()
{
}

void clsPlayerTask::actionDamage00()
{
}

void clsPlayerTask::actionGearTrick()
{
}

void clsPlayerTask::initData_Restart()
{
}

void clsPlayerTask::actionGearPath()
{
}

void clsPlayerTask::setTrickXEffect()
{
}

f32 clsPlayerTask::getStageMinimumHeight(u32 u32StageNo) const
{
    return 0;
}

void clsPlayerTask::updateAction()
{
}

clsPlayerTask::~clsPlayerTask()
{
}

void clsPlayerTask::initCommonRun()
{
}

void clsPlayerTask::cancelGearAttack()
{
}

void clsPlayerTask::initGearFly()
{
}

void clsPlayerTask::actionGearTranslationMovePath()
{
}

void clsPlayerTask::setSetData(const clsPack::stcSetDataDetail* opsSetDataDetailI)
{
}

void clsPlayerTask::initCommonFlight()
{
}

void clsPlayerTask::initAttackDamage()
{
}

void clsPlayerTask::actionWheelDrift()
{
}

void clsPlayerTask::vibrationLanding()
{
}

void clsPlayerTask::setCancelAttackDamage()
{
}

void clsPlayerTask::vibrationCurve()
{
}

void clsPlayerTask::actionAttackDamage()
{
}

void clsPlayerTask::registanceFlightSpeed()
{
}

void clsPlayerTask::actionGearFly()
{
}

void clsPlayerTask::registanceFlightFloating(f32 f32Accele)
{
}

void clsPlayerTask::actionGearRail()
{
}

void clsPlayerTask::checkBrake()
{
}

void clsPlayerTask::checkGDive()
{
}

void clsPlayerTask::restrictTurbRun()
{
}

void clsPlayerTask::checkGCtrlSlide()
{
}

void clsPlayerTask::quakeCamera(s32 s32Index, f32 f32Frame)
{
}

void clsPlayerTask::physic()
{
}

void clsPlayerTask::checkGCtrlTrick()
{
}

void clsPlayerTask::checkGCtrlFlight()
{
}

void clsPlayerTask::checkGearChange()
{
}

void clsPlayerTask::requestFlightAction()
{
}

void clsPlayerTask::requestJumpOrTrick()
{
}

void clsPlayerTask::calcVelocity(NNS_VECTORFAST* psVelocityVecFast)
{
}

void clsPlayerTask::initFixedSpeed(const clsPathData::stcLine* opsLine)
{
}

void clsPlayerTask::initFreeAccele(const clsPathData::stcLine* opsLine)
{
}

void clsPlayerTask::initFrameAccele(const clsPathData::stcLine* opsLine)
{
}

void clsPlayerTask::initRateAccele(const clsPathData::stcLine* opsLine)
{
}

void clsPlayerTask::actionFixedSpeed(const clsPathData::stcLine* pParam1)
{
}

void clsPlayerTask::actionFreeAccele(const clsPathData::stcLine* pParam1)
{
}

void clsPlayerTask::actionFrameAccele(const clsPathData::stcLine* opsLine)
{
}

void clsPlayerTask::actionRateAccele(const clsPathData::stcLine* opsLine)
{
}

void clsPlayerTask::endMovePath()
{
}

void clsPlayerTask::acceleWalk()
{
}

void clsPlayerTask::curveWalk(f32 f32Ratio)
{
}

u32 clsPlayerTask::checkRailAction()
{
    return 0;
}

void clsPlayerTask::setCollisionFilterWalk()
{
}

void clsPlayerTask::clearCollisionFilterWalk()
{
}

void clsPlayerTask::update()
{
}

void clsPlayerTask::checkDirectionRegulation()
{
}

void clsPlayerTask::clearMoveSubParam()
{
}

void clsPlayerTask::breakObstacle()
{
}

void clsPlayerTask::updateObstacle()
{
}

void clsPlayerTask::useRingGear()
{
}

void clsPlayerTask::setDamageStatus(f32 f32Frame)
{
}

void clsPlayerTask::setInvincibilityStatus(f32 f32Frame)
{
}

void clsPlayerTask::setTrapColorBallStatus(f32 f32Frame)
{
}

void clsPlayerTask::setTrapPartsLockStatus(f32 f32Frame)
{
}

void clsPlayerTask::setSpeedDownStatus(f32 f32Frame)
{
}

void clsPlayerTask::setEggConfettiStatus(f32 f32Frame)
{
}

void clsPlayerTask::setNightsAtkEffectStatus(f32 f32Frame)
{
}

void clsPlayerTask::clearPlayerCondition()
{
}

void clsPlayerTask::setAndStatus(clsPlayerTask::enmStatus eStatus)
{
}

void clsPlayerTask::setClearStatus(clsPlayerTask::enmStatus eStatus)
{
}

void clsPlayerTask::reset()
{
}

void clsPlayerTask::createMothion(nspChara::enmCharaType enCharaType)
{
}

void clsPlayerTask::init(nspPlayer::enmNo ePlayerNo,
                         enPlayerCtrlType eCtrlType,
                         u32 u32CharaNo,
                         nspGear::enmGearCtrl eGearCtrlNo,
                         u32 u32GearLevel,
                         u8 u8PadNo)
{
}

void clsPlayerTask::initCamera(enPlayerCtrlType eCtrlType, u32 u32CharaNo)
{
}

void clsPlayerTask::initKey(nspPlayer::enmNo u8PadNo, enPlayerCtrlType sParam2, u8 u8Param3)
{
}

void clsPlayerTask::createChara(nspChara::enmCharaType eCharaType,
                                nspChara::enmModelType eModelType)
{
}

void clsPlayerTask::createGear(nspGear::enmGearCtrl eGearCtrlNo, u32 u32InitEquipsGears)
{
}

void clsPlayerTask::execute()
{
}

void clsPlayerTask::draw()
{
}

void clsPlayerTask::setInertia(const NNS_VECTORFAST* psNrmDirVecFast, f32 f32Speed, f32 f32Frame)
{
}

void clsPlayerTask::reconfigurationVelocity(const NNS_VECTORFAST* opsVelocityVecFast)
{
}

void clsPlayerTask::changeTrickCameraRq(u8 u8Rank, nspTrick::enmKicker eKickerType)
{
}

void clsPlayerTask::changeCameraRq(u32 u32Type)
{
}

u8 clsPlayerTask::GoalPlayer()
{
    return 0;
}

void clsPlayerTask::setGoalComPlayer()
{
}

void clsPlayerTask::setFalseStartAction(s32 s32ShockFrame, s32 s32PenaltyFrame)
{
}

void clsPlayerTask::setVaporTrail(bool bFlg)
{
}

u8 clsPlayerTask::setLoopParticle(u8 u8No, u32 u32View, u32 u32Particle, u8 u8Type)
{
    return 0;
}

void clsPlayerTask::stopLoopParticle(u8 u8No)
{
}

u8 clsPlayerTask::setLoopEffect(u8 u8No, clsTask* pcEffectTask)
{
    return 0;
}

u8 clsPlayerTask::setLoopEffect(u8 u8No, u32 u32TIp, clsModelType_OB_TX_MO_MA* pcModel, u32 u32Flg)
{
    return 0;
}

void clsPlayerTask::stopLoopEffect(u8 u8No)
{
}

u8 clsPlayerTask::checkLoopEffect(u8 u8No)
{
    return 0;
}

void clsPlayerTask::setWeather(u8 u8No)
{
}

void clsPlayerTask::demoMotionWeather()
{
}

void clsPlayerTask::setDrawBackLineFlg()
{
}

void clsPlayerTask::setStartDemoEffect()
{
}

void clsPlayerTask::setSlipStreamEffect()
{
}

void clsPlayerTask::updateSlipStreamEffect()
{
}

void clsPlayerTask::stopSlipStreamEffect()
{
}

void clsPlayerTask::calcNodePos()
{
}

void clsPlayerTask::changeUserToCom()
{
}

void clsPlayerTask::contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject)
{
}

u8 clsPlayerTask::isReverse()
{
    return 0;
}

void clsPlayerTask::registLightCollision(clsThroughCollision* pcCollision)
{
}

void clsPlayerTask::deleteLightCollision(clsThroughCollision* pcCollision)
{
}

void clsPlayerTask::updateLightNo()
{
}

void clsPlayerTask::setRingNum(s32 s32Num)
{
}

void clsPlayerTask::setBoardMtx(u32 u32v, s32 s32Id)
{
}

u8 clsPlayerTask::isDemo() const
{
    return 0;
}
