#include "usr/local/sce/ee/gcc/ee/lib/libm/s_fabs.h"
#include "usr/local/sce/ee/gcc/ee/lib/libc/memcpy.h"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/CollisionManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Camera/SrCamCtrlMgr.hpp"
#include "Develop/Projects/SR2/pgm/src/System/SrCamCtrl.hpp"
#include "usr/local/cri/mwlib/ee/lib/cri_libs.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOProfile.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnCameraMgr.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/Debug.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/SetEditor.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/VaporTrail.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/BaseEffect.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Attack/EggmanConfetti.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Attack/NightsAtkEffect.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/PlayerDebug.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/PlayerPhysic.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Key/PlayerKey.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Lap.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/Character.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/BaseStage.hpp"
#include "Develop/Projects/SR2/pgm/src/System/ZNone.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"

namespace {
static f32 NODE_VIB__ADD_CYCLE_A32 = 728.0f;
}

static clsBackLineEffectTask::stcParam oasPlayerLineParam = {1,
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
const f32 clsPlayerTask::t_of32RingRateTime = 100.0f;
const f32 clsPlayerTask::t_of32RingGravityRateTime = 6.0f;
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
    clsCollisionManager::stcRetRayCast sRetRayCast;
    NNS_VECTORFAST sRayVF;
    NNS_VECTORFAST sRankVF;
    NNS_VECTORFAST sStartPosVF;
    NNS_VECTORFAST sDownVF;
    NNS_VECTORFAST sDownMinVF;
    NNS_VECTORFAST sTmpVF;

    nnCopyVectorFast(&sStartPosVF, &m_sPosVecFast[0]);
    nnAddVectorFast(&sRayVF, &m_sPosVecFast[0], &m_cGravity.m_sUpVecFast);
    nnSubtractVectorFast(&sDownVF, &m_sPosVecFast[0], &sRayVF);
    nnScaleVectorFast(&sRayVF, &sDownVF, 30.0f);
    nnAddVectorFast(&sRayVF, &sRayVF, &sStartPosVF);
    nnScaleVectorFast(&sDownMinVF, &sDownVF, 0.01f);

    if (clsCollisionManager::GS()->checkRayCast(sRetRayCast, sStartPosVF, sRayVF, 0x10000)) {
        if (sRetRayCast.psInfo != NULL && sRetRayCast.psInfo->u8Attr == 12) {
            nnAddVectorFast(&sStartPosVF, &sRetRayCast.sCrossVecFast, &sDownMinVF);
            if (clsCollisionManager::GS()->checkRayCast(sRetRayCast, sStartPosVF, sRayVF, 0x10000))
            {
                nnSubtractVectorFast(&sRankVF, &sRetRayCast.sCrossVecFast, &m_sPosVecFast[0]);
                f32 f32Length = nnLengthVectorFast(&sRankVF);
                nnCrossProductVectorFast(&sTmpVF, &m_sUpVecFast, &sDownVF);
                if (nnDotProductVectorFast(&m_sVelocityVecFast, &sTmpVF) < 0.0f) {
                    f32 f32Rotate = f32Length / 4.0f * 0.017453292f;
                    f32 f32Velocity = m_cVelocity.m_cRotate.m_f32Result + f32Rotate;
                    m_cVelocity.m_cRotate.startLerp(f32Velocity, f32Velocity, 0.0f);
                    f32 f32Postural = m_cPostural.m_cRotate.m_f32Result + f32Rotate;
                    m_cPostural.m_cRotate.startLerp(f32Postural, f32Postural, 0.0f);
                } else {
                    f32 f32Rotate = f32Length / 4.0f * 0.017453292f;
                    f32 f32Velocity = m_cVelocity.m_cRotate.m_f32Result - f32Rotate;
                    m_cVelocity.m_cRotate.startLerp(f32Velocity, f32Velocity, 0.0f);
                    f32 f32Postural = m_cPostural.m_cRotate.m_f32Result - f32Rotate;
                    m_cPostural.m_cRotate.startLerp(f32Postural, f32Postural, 0.0f);
                }
            }
        }
    }
}

void clsPlayerTask::checkGCtrlSlide()
{
}

void clsPlayerTask::quakeCamera(s32 s32Index, f32 f32Frame)
{
}

void clsPlayerTask::physic()
{
    if (!OOCheckBitsEq(m_eStatus, STATUS_GROUND)) {
        if (nspGlobal::sTask.pcBaseRace->m_s32StageNo == 2 &&
            SNDF_SeqIdGetStat(static_cast<u8>(m_s32SfId[8])))
        {
            SNDF_SeqIdStop(static_cast<u8>(m_s32SfId[8]));
        }
        return;
    }

    u8 u8Attr = m_pcPhysic->m_sColInfo[m_pcPhysic->m_u8ColInfoNo].u8Attr;
    if (OOCheckBitsEq(m_eFlag, FLAG_SLOPE_SLOWDOWN) && m_f32Speed > 0.0f &&
        m_cGravityActionManager.m_eType == clsGravityActionManager::TYPE_NULL &&
        nspGlobal::sTask.pcBaseRace->m_s32StageNo != 2 &&
        nspGlobal::sTask.pcBaseRace->m_s32StageNo != 10)
    {
        NNS_VECTORFAST sSlopeVecFast;
        NNS_MATRIX sInverseMtx;
        nnInvertMatrix(&sInverseMtx, &m_cVelocity.m_sMtx);
        nnTransformVectorFast(&sSlopeVecFast, &sInverseMtx, &m_cGravity.m_sUpVecFast);
        m_f32Accele -= sSlopeVecFast.z * (0.8f * 1000.0f / 216000.0f);
    }

    if (nspGlobal::sTask.pcBaseRace->m_s32StageNo == 2 && m_f32Speed > 0.0f &&
        m_pcGearCtrl->m_eCtrlMode != clsGearCtrl::CTRL_MODE_WALK &&
        (isUser() || m_eCtrlType == CTRL_TYPE_REPLAY))
    {
        if (m_eStatusOld & STATUS_ON_SNOW) {
            if (SNDF_SeqIdGetStat(static_cast<u8>(m_s32SfId[8]))) {
                SNDF_SeqIdStop(static_cast<u8>(m_s32SfId[8]));
            }
        } else if (!SNDF_SeqIdGetStat(static_cast<u8>(m_s32SfId[8]))) {
            SNDF_SeqIdPlay(static_cast<u8>(m_s32SfId[8]));
        }
    } else if (SNDF_SeqIdGetStat(static_cast<u8>(m_s32SfId[8]))) {
        SNDF_SeqIdStop(static_cast<u8>(m_s32SfId[8]));
    }

    if (u8Attr == 12 && m_pcGearCtrl->m_eCtrlMode != clsGearCtrl::CTRL_MODE_WALK &&
        nspGlobal::sTask.pcBaseRace->m_s32StageNo != 4)
    {
        restrictTurbRun();
    }
    if (u8Attr == 3 && !OOCheckBitsEq(m_eStatus, STATUS_INVINCIBILITY) &&
        m_cGravityActionManager.m_eType == clsGravityActionManager::TYPE_NULL &&
        m_pcGearCtrl->m_eCtrlMode != clsGearCtrl::CTRL_MODE_WALK)
    {
        f32 f32Durability = m_cPrfm.getDataPtr()->f32Durability;
        if (!(m_cPrfm.getDataPtr()->u32Ability & 0x4000)) {
            f32 f32LimitSpeed = (f32Durability * 0.5f + 60.0f) * 1000.0f / 216000.0f;
            if (m_f32Speed > f32LimitSpeed) {
                m_f32Accele = 0.0f;
                m_f32Speed -= 0.5f * 1000.0f / 216000.0f;
                if (m_f32Speed < f32LimitSpeed) {
                    m_f32Speed = f32LimitSpeed;
                }
            }
        } else {
            m_cGravityActionManager.m_f32Point +=
                m_f32SpeedRate * (1.0f - static_cast<u32>(m_f32Speed < 0.0f) * 2.0f) * 0.1f;
            m_cGravityActionManager.checkLimitPoint();
        }
    }
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

inline void clsPlayerTask::updateCentrifugalForce()
{
    if ((getStatus() & STATUS_GROUND) && getGearCtrlRef()->isRide() &&
        (getFlag() & FLAG_CENTRIFUGAL_FORCE))
    {
        f32 f32Grip = m_pcDebug->m_f32GripRate;
        if (f32Grip == 1.0f) {
            f32Grip = getPhysicRef()->getColInfoRef().s8Grip / 100.0f + 1.0f;
        }
        NNS_MATRIX sRotateMtx;
        nnMakeRotateYMatrix(&sRotateMtx, static_cast<s32>(-getCurveRad() * 10430.378f));
        f32 f32CentrifugalForce;
        if (f32Grip == 1.0f) {
            f32CentrifugalForce = 0.0f;
            if (m_cControlMatrix.getAutoRotA32Ref()->y != 0.0f &&
                m_cControlMatrix.getAutoRotRetAddA32Ref()->y == 0.0f)
            {
                m_cControlMatrix.getAutoRotRetAddA32Ref()->y = static_cast<s32>(
                    (1.0f -
                     static_cast<u32>(m_cControlMatrix.getAutoRotA32Ref()->y > 0.0f) * 2.0f) *
                    728.0f);
            }
        } else {
            NNS_VECTORFAST sVecFast;
            nnSetUpVectorFast(&sVecFast, getCentrifugalForce(), 0.0f, 0.0f);
            nnTransformVectorFast(&sVecFast, &sRotateMtx, &sVecFast);
            f32 f32Force = sVecFast.x;
            nnSetUpVectorFast(&sVecFast, 0.0f, 0.0f, getSpeed());
            nnTransformVectorFast(&sVecFast, &sRotateMtx, &sVecFast);
            f32CentrifugalForce =
                (f32Force +
                 static_cast<f32>(sVecFast.x * ((1.0f - f32Grip) * 3.0f *
                                                    (m_f32SpeedRate * fabs(m_f32CurveRotateRate)) +
                                                1.0))) *
                (0.99f - f32Grip * 0.05f);
            if (f32CentrifugalForce > 0.25f) {
                f32CentrifugalForce = 0.25f;
            } else if (f32CentrifugalForce < -0.25f) {
                f32CentrifugalForce = -0.25f;
            }
            m_cControlMatrix.getAutoRotA32Ref()->y =
                static_cast<s32>(m_f32CurveRotateRate * 9102.0f);
        }
        if (!isCom()) {
            setCentrifugalForce(f32CentrifugalForce);
        }
    }
}

void clsPlayerTask::calcVelocity(NNS_VECTORFAST* psVelocityVecFast)
{
    NNS_VECTORFAST sSpeedVecFast;
    f32 f32FrameRate = m_f32FrameRate * clsPfSystem::GS()->getFrameRateAdd();
    nnCopyVectorFast(psVelocityVecFast, &nspNnUtil::tosZeroVecFast);
    if (m_f32InertiaDecayFrame != 0.0f) {
        m_f32InertiaDecayFrame -= clsPfSystem::GS()->getFrameRateAdd();
        nnAddVectorFast(psVelocityVecFast, psVelocityVecFast, &m_sInertiaVecFast);
        if (m_f32InertiaDecayFrame <= 0.0f) {
            nnCopyVectorFast(&m_sInertiaVecFast, &nspNnUtil::tosZeroVecFast);
            nnCopyVectorFast(&m_sInertiaDecayVecFast, &nspNnUtil::tosZeroVecFast);
            m_f32InertiaDecayFrame = 0.0f;
        } else {
            nnScaleAddVectorFast(
                &m_sInertiaVecFast, &m_sInertiaVecFast, &m_sInertiaDecayVecFast, -f32FrameRate);
        }
    }
    if (m_pcDebug->m_s32MaxSpeed > 0) {
        m_f32MaxSpeed = m_pcDebug->m_s32MaxSpeed * 1000.0f / 216000.0f;
    }
    if (m_pcDebug->m_s32Accele > 0) {
        m_f32Accele = m_pcDebug->m_s32Accele * 1000.0f / 216000.0f / 60.0f;
    }
    if (m_eMoveFlag & MOVE_FLAG_SPEED) {
        f32 f32MaxSpeed = m_f32AdjustMaxSpeed;
        if (f32MaxSpeed == 0.0f) {
            f32MaxSpeed = m_f32MaxSpeed;
        }
        updateCentrifugalForce();
        if (m_f32Speed > f32MaxSpeed) {
            f32 af32SlowDownRateTable[2] = {0.02f, 0.015f};
            f32 f32SlowDownRate =
                af32SlowDownRateTable[m_pcGearCtrl->getEquipsGearType() == GEAR_TYPE_SURFING];
            m_f32Speed += f32FrameRate * (f32SlowDownRate * (f32MaxSpeed - m_f32Speed));
            if (m_f32Accele < 0.0f) {
                m_f32Speed += f32FrameRate * m_f32Accele;
            }
            if (m_f32Speed < f32MaxSpeed) {
                m_f32Speed = f32MaxSpeed;
            }
        } else if (m_f32Speed < m_f32MinSpeed) {
            m_f32Speed = m_f32MinSpeed;
        } else if (m_eActionType == ACTION_TYPE_BRAKE || m_eActionType == ACTION_TYPE_RESTART ||
                   m_eActionType == ACTION_TYPE_WALK_BRAKE ||
                   (m_pcGearCtrl->m_eCtrlMode == clsGearCtrl::CTRL_MODE_WALK &&
                    m_pcKey->m_sKeyData.s8LeverY == 0))
        {
            m_f32Speed += m_f32Accele * f32FrameRate;
            if (m_f32Speed < 0.0f) {
                m_f32Speed = 0.0f;
            }
        } else {
            m_f32Speed += m_f32Accele * f32FrameRate;
            if (m_f32Speed > f32MaxSpeed) {
                m_f32Speed = f32MaxSpeed;
            } else if (m_f32Speed < m_f32MinSpeed) {
                m_f32Speed = m_f32MinSpeed;
            }
        }
        f32 f32SpeedRate = m_f32Speed / m_f32MaxSpeed;
        if (f32SpeedRate > 1.0f) {
            f32SpeedRate = 1.0f;
        }
        m_f32SpeedRate = f32SpeedRate;
        nnSetUpVectorFast(&sSpeedVecFast, 0.0f, 0.0f, m_f32Speed);
        nnTransformVectorFast(&m_sSpeedVecFast, &m_cVelocity.m_sMtx, &sSpeedVecFast);
        nnSetUpVectorFast(&sSpeedVecFast, m_f32CentrifugalForce, 0.0f, 0.0f);
        nnTransformVectorFast(&sSpeedVecFast, &m_cVelocity.m_sMtx, &sSpeedVecFast);
        nnAddVectorFast(&m_sSpeedVecFast, &m_sSpeedVecFast, &sSpeedVecFast);
        nnAddVectorFast(psVelocityVecFast, psVelocityVecFast, &m_sSpeedVecFast);
    }
    if (m_eMoveFlag & MOVE_FLAG_GRAVITY) {
        nnAddVectorFast(psVelocityVecFast, psVelocityVecFast, &m_cGravity.m_sVecFast);
    }
    if (m_eMoveFlag & MOVE_FLAG_JUMP) {
        nnAddVectorFast(psVelocityVecFast, psVelocityVecFast, &m_sAirVecFast);
    }
    if (m_eMoveFlag & MOVE_FLAG_VECTOR) {
        nnAddVectorFast(psVelocityVecFast, psVelocityVecFast, &m_sVectorMoveVecFast);
    }
    if ((m_eMoveFlag & MOVE_FLAG_SURFACE_ADJUST) && (m_eStatus & STATUS_GROUND)) {
        nnScaleAddVectorFast(psVelocityVecFast, psVelocityVecFast, &m_sUpVecFast, -0.05f);
    }
    nnScaleVectorFast(psVelocityVecFast, psVelocityVecFast, f32FrameRate);
    if (m_eMoveFlag & MOVE_FLAG_PATH) {
        nnAddVectorFast(psVelocityVecFast, psVelocityVecFast, &m_sPathMoveVecFast);
    }
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
    m_cPrfm.updateFrame();
    updateObstacle();
    m_cVelocity.m_cSurface.update();
    m_cVelocity.m_cRotate.update();
    m_cVelocity.update();
    m_cPostural.m_cSurface.update();
    m_cPostural.m_cRotate.update();
    m_cPostural.update();
    m_u8CurrentDrawMtxNo ^= 1;

    if (m_pcGearCtrl->m_eCtrlMode == clsGearCtrl::CTRL_MODE_WALK) {
        f32 f32Height = m_pcCharacter->m_f32OffsetPosition;
        f32 f32MinHeight = clsCharacter::t_of32OffsetWalkHeight;
        if (f32Height > f32MinHeight) {
            f32Height -= 0.01f;
            if (f32Height < f32MinHeight) {
                f32Height = f32MinHeight;
            }
            m_pcCharacter->m_f32OffsetPosition = f32Height;
        }
    } else {
        f32 f32Height = m_pcCharacter->m_f32OffsetPosition;
        m_pcGearCtrl->getEquipsPrototypeGear();
        f32 f32MaxHeight = clsCharacter::t_of32OffsetGearHeight;
        if (f32Height < f32MaxHeight) {
            f32Height += 0.05f;
            if (f32Height > f32MaxHeight) {
                f32Height = f32MaxHeight;
            }
            m_pcCharacter->m_f32OffsetPosition = f32Height;
        }
    }

    NNS_MATRIX sOffsetMtx;
    NNS_MATRIX sScaleMtx;
    NNS_VECTORFAST sOffsetVecFast;
    NNS_VECTORFAST sPosVecFast;
    nnCopyVectorFast(&sOffsetVecFast, &m_sOffsetDrawVecFast);
    sOffsetVecFast.y += m_pcCharacter->getDrawOffset();
    nnMakeQuaternionMatrix(&sOffsetMtx, &m_cSurface.m_sQuat);
    nnTransformVectorFast(&sOffsetVecFast, &sOffsetMtx, &sOffsetVecFast);
    nnAddVectorFast(&sPosVecFast, &sOffsetVecFast, &m_sPosVecFast[0]);
    nnCopyMatrix(&m_sDrawMtx[m_u8CurrentDrawMtxNo], &m_cPostural.m_sMtx);
    nnCopyVectorFastMatrixTranslation(&m_sDrawMtx[m_u8CurrentDrawMtxNo], &sPosVecFast);
    nnMakeScaleMatrix(&sScaleMtx, m_f32SystemScale, m_f32SystemScale, m_f32SystemScale);
    nnMultiplyMatrix(
        &m_sDrawMtx[m_u8CurrentDrawMtxNo], &m_sDrawMtx[m_u8CurrentDrawMtxNo], &sScaleMtx);
    m_f32ItemFrame -= clsPfSystem::GS()->getFrameRateAdd();
    m_f32ItemFrame *= static_cast<u32>(m_f32ItemFrame > 0.0f);
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

inline void clsPlayerTask::updateVisibility()
{
    m_bMotionVisible = 0;
    m_bDrawVisible = 0;
    if (isDefaultUser()) {
        m_bMotionVisible = 1;
        m_bDrawVisible = 1;
    }
    if (getActionType() == ACTION_TYPE_ATTACKDAMAGE || getActionType() == ACTION_TYPE_ATTACK) {
        m_bMotionVisible = 1;
    }
    s32 s32ViewNum = clsPfSystem::GS()->getViewportNum();
    for (s32 s32View = 0; s32View < s32ViewNum; ++s32View) {
        if (m_aeClipperRet[s32View] < 2) {
            m_bDrawVisible = 1;
        }
        if (m_f32CamMostDistRet < m_of32MotionClipDistx1) {
            m_bMotionVisible = 1;
        }
    }
    m_f32CamMostDistRet = 100000000.0f;
}

inline void clsPlayerTask::updateSurface()
{
    f32 f32Dot = nnDotProductVectorFast(&m_sUpVecFast, &m_cSurface.m_sUpVecFast);
    if (f32Dot < 0.999999f && (m_eStatus & STATUS_GROUND)) {
        m_cSurface.update(m_sUpVecFast);
        m_cVelocity.m_cSurface.startSlerp(&m_cSurface.m_sQuat, &m_cSurface.m_sQuat, 0.0f);
        if (m_eFlag & FLAG_UPDATE_POSTURAL_QUAT) {
            m_cPostural.m_cSurface.startSlerp(&m_cPostural.m_cSurface.m_sResultQuat,
                                              &m_cSurface.m_sQuat,
                                              f32Dot * f32Dot * 15.0f + 10.0f);
        }
    }
}

inline void clsPlayerTask::updateModel()
{
    if (getPlayerNo() < 1) {
        if (clsPfCameraMgr::GS()->getCamera(getPlayerNo())->getDebugLookMode() != 1 &&
            clsPfCameraMgr::GS()->getCamera(getPlayerNo())->getDebugDomeMode() != 1 &&
            !isMotionVisibleAllView())
        {
            m_pcMotion->updatePlayData();
            getControlMatrixRef()->update();
            m_pcMotion->updateFrame();
            return;
        }
    } else if (!isMotionVisibleAllView()) {
        m_pcMotion->updatePlayData();
        getControlMatrixRef()->update();
        m_pcMotion->updateFrame();
        return;
    }
    NNS_MATRIX sScaleMtx;
    nnMakeScaleMatrix(
        &sScaleMtx, (getCharacterRef()->m_posData->u8Style == 1) * -2.0f + 1.0f, 1.0f, 1.0f);
    if (isAttackDmgScale()) {
        nnScaleMatrix(&sScaleMtx, &sScaleMtx, m_f32AttackDmgScale, 1.0f, 1.0f);
        m_f32AttackDmgScale -= clsPfSystem::GS()->getFrameRateAdd() * 0.005f;
        if (m_f32AttackDmgScale < 0.5f) {
            m_f32AttackDmgScale = 0.5f;
        }
    } else {
        m_f32AttackDmgScale += clsPfSystem::GS()->getFrameRateAdd() * 0.005f;
        if (m_f32AttackDmgScale >= 1.0f) {
            m_f32AttackDmgScale = 1.0f;
        } else {
            nnScaleMatrix(&sScaleMtx, &sScaleMtx, m_f32AttackDmgScale, 1.0f, 1.0f);
        }
    }
    m_pcMotion->updatePlayData();
    if ((m_ePlayerNo & 1) == (clsPfSystem::GS()->getGameCnt() & 1) || isDefaultUser() ||
        ((getCharacterRef()->getType() == 16 || getCharacterRef()->getType() == 17) &&
         !getGearCtrlRef()->isRide()))
    {
        m_pcMotion->updateTrs();
        if (m_eFlag & FLAG_UPDATE_BEHAVIOR) {
            m_pcCharacter->behavior();
            behaviorTrs();
        }
    } else if (!m_pcMotion->getCurrentChangeFlag()) {
        memcpy(m_pcMotion->getTrsCurrentPtr(),
               m_pcMotion->getTrsOldPtr(),
               sizeof(NNS_TRS) * m_pcMotion->getObjectPtr()->nNode);
    }
    m_pcMotion->updateMtxList(&sScaleMtx);
    behaviorMtxList();
    m_pcMotion->updateMtxPal(NULL);
    if ((m_eFlag & FLAG_UPDATE_BEHAVIOR) && m_pcGearCtrl->isRide()) {
        m_pcGearCtrl->behavior();
    }
    behaviorMtxPal();
    if ((m_eFlag & FLAG_UPDATE_BEHAVIOR) && m_pcGearCtrl->isRide()) {
        m_pcGearCtrl->behavior_NodeMtx();
    }
    nnMultiplyMatrix(getDrawMtxRef(), getDrawMtxRef(), &m_sEffMtx);
    getControlMatrixRef()->update();
    nnMultiplyMatrix(getDrawMtxRef(), getDrawMtxRef(), getControlMatrixRef()->getMtxRef());
    m_pcMotion->updateFrame();
    calcNodePos();
}

inline void clsPlayerTask::updateStatus()
{
    enmStatus eStatus = static_cast<enmStatus>(m_eStatus | m_eStatusOld);
    m_eStatusTrigger = static_cast<enmStatus>(m_eStatus & (m_eStatusOld ^ m_eStatus));
    m_eStatusRemove = static_cast<enmStatus>(m_eStatusOld & (m_eStatusOld ^ m_eStatus));
    m_eStatusOld = m_eStatus;
    setAndStatus(STATUS_MASK_UPDATE);
    if (eStatus & STATUS_DAMAGE) {
        if (m_eStatus & STATUS_DAMAGE) {
            if (m_eStatusTrigger & STATUS_DAMAGE) {
                getPhysicRef()->setClearColFilter(
                    static_cast<clsCollisionFilter::enmInfo>(0x800000));
            }
            m_f32DamageFrame -= clsPfSystem::GS()->getFrameRateAdd();
            if (m_f32DamageFrame <= 0.0f) {
                setClearStatus(STATUS_DAMAGE);
                setClearStatus(STATUS_ATTACKDAMAGE);
            }
        } else if (m_eStatusRemove & STATUS_DAMAGE) {
            getPhysicRef()->setOrColFilter(static_cast<clsCollisionFilter::enmInfo>(0x800000));
        }
    }
    if ((m_eStatus & STATUS_ATTACKDAMAGE) && !(m_eStatus & STATUS_DAMAGE)) {
        m_f32DamageFrame -= clsPfSystem::GS()->getFrameRateAdd();
        if (m_f32DamageFrame <= 0.0f) {
            setClearStatus(STATUS_ATTACKDAMAGE);
        }
    }
    if ((eStatus & STATUS_INVINCIBILITY) && (m_eStatus & STATUS_INVINCIBILITY)) {
        m_f32InvincibilityFrame -= clsPfSystem::GS()->getFrameRateAdd();
        if (m_f32InvincibilityFrame <= 0.0f) {
            setClearStatus(STATUS_INVINCIBILITY);
        }
    }
    if ((getFlag() & FLAG_ALL_TIME_ATTACK) && !(getStatus() & STATUS_GOAL)) {
        m_f32AttackFrame = 600.0f;
    }
    if ((getPrfmRef()->getGearDataPtr()->u32Ability & 0x10000) &&
        getPhysicRef()->getColInfoRef().u8Attr != 5 &&
        (getActionType() == ACTION_TYPE_RUN || getActionType() == ACTION_TYPE_ATTACK))
    {
        if (getPrfmRef()->getDataPtr()->f32MaxAgp == getGravityActionManagerRef()->getPoint()) {
            m_f32AttackFrame = 600.0f;
            getGravityActionManagerRef()->addPoint(getPrfmRef()->getDataPtr()->f32MaxAgp * -0.5f);
        }
    }
    m_f32AttackFrame -= clsPfSystem::GS()->getFrameRateAdd();
    if (m_f32AttackFrame <= 0.0f) {
        m_f32AttackFrame = 0.0f;
    }
    if (m_f32BoostAttackFrame != 0.0f) {
        m_f32BoostAttackFrame -= clsPfSystem::GS()->getFrameRateAdd();
        if (m_f32BoostAttackFrame <= 0.0f) {
            m_f32BoostAttackFrame = 0.0f;
        }
    }
    setGroundEffect();
    if ((isUser() || isReplay()) && (getStatusTrigger() & STATUS_WALL)) {
        clsModelType_OB_TX_MO_MA* pcModel =
            nspGlobal::sTask.pcBaseRace->cResidenceEffect.getCrashModel();
        pcModel->m_psMotion->StartFrame = 0.0f;
        new clsBaseEffect_Task(
            300100, 5, pcModel, 0x41, getCameraNo(), getPlayerNo(), NODE_POS_SPINE, 0.0f);
        getKeyRef()->playSfSe_User(0x501a9);
    }
    if (eStatus & STATUS_TRAP_COLORBALL) {
        if (m_eStatus & STATUS_TRAP_COLORBALL) {
            m_f32TrapColorBallFrame -= clsPfSystem::GS()->getFrameRateAdd();
            if (isUser() && m_u32TrapColorBallDropCnt < m_u32TrapColorBallDropMaxCnt) {
                m_f32TrapColorBallDropFrame -= clsPfSystem::GS()->getFrameRateAdd();
                if (m_f32TrapColorBallDropFrame <= 0.0f) {
                    switch (m_u32TrapColorBallDropCnt) {
                    case 0:
                        if (clsPfSystem::RS().getViewportNum() < 3) {
                            nspGlobal::sTask.pcBaseStage->addColorDropsEffect(
                                getPlayerNo(), 10, 60, m_f32TrapColorBallFrame, 0);
                        } else {
                            nspGlobal::sTask.pcBaseStage->addColorDropsEffect(
                                getPlayerNo(), 8, 50, m_f32TrapColorBallFrame, 0);
                        }
                        m_f32TrapColorBallDropFrame = 5.0f;
                        break;
                    case 1:
                        if (clsPfSystem::RS().getViewportNum() < 3) {
                            nspGlobal::sTask.pcBaseStage->addColorDropsEffect(
                                getPlayerNo(), 10, 20, m_f32TrapColorBallFrame, 0);
                        } else {
                            nspGlobal::sTask.pcBaseStage->addColorDropsEffect(
                                getPlayerNo(), 8, 30, m_f32TrapColorBallFrame, 0);
                        }
                        m_f32TrapColorBallDropFrame = 5.0f;
                        break;
                    case 2:
                        nspGlobal::sTask.pcBaseStage->addColorDropsEffect(
                            getPlayerNo(), 10, 5, m_f32TrapColorBallFrame, 0);
                        break;
                    }
                    ++m_u32TrapColorBallDropCnt;
                }
            }
            if (m_f32TrapColorBallFrame <= 0.0f) {
                setClearStatus(STATUS_TRAP_COLORBALL);
            }
        } else if (m_eStatusRemove & STATUS_TRAP_COLORBALL) {
            nspGlobal::sTask.pcBaseStage->deleteColorViewDetail(getPlayerNo());
            if (isDemoCom()) {
                getMotionRef()->registBegin();
                getMotionRef()->registTableBase(0, 0.0f, 2.0f, clsMotion::STATUS_LINK_ONE);
                getMotionRef()->registEnd(clsPlayerMotion::PRI_NORMAL, clsPlayerMotion::PRI_NORMAL);
            }
        }
    }
    if (eStatus & STATUS_TRAP_PARTSLOCK) {
        if (m_eStatus & STATUS_TRAP_PARTSLOCK) {
            m_f32TrapPartsLockFrame -= clsPfSystem::GS()->getFrameRateAdd();
            if (m_f32TrapPartsLockFrame <= 0.0f) {
                setClearStatus(STATUS_TRAP_PARTSLOCK);
            }
        } else if (m_eStatusRemove & STATUS_TRAP_PARTSLOCK) {
            getKeyRef()->setKeyMask(0);
            m_pcBackLineTask->subFlg(0x100);
            stopLoopParticle(3);
            m_f32TrapPartsLockFrame = 0.0f;
        }
    }
    if (eStatus & STATUS_EGGCONFETTI) {
        if (m_eStatus & STATUS_EGGCONFETTI) {
            m_f32EggConfettiFrame -= clsPfSystem::GS()->getFrameRateAdd();
            if (m_f32EggConfettiDropFrame > 0.0f) {
                m_f32EggConfettiDropFrame -= clsPfSystem::GS()->getFrameRateAdd();
                if (m_f32EggConfettiDropFrame <= 0.0f) {
                    if (m_pcEggConfetti != NULL) {
                        m_pcEggConfetti->addDetail(getPlayerNo(), 13, 0, m_f32EggConfettiFrame);
                    } else {
                        m_pcEggConfetti =
                            new clsEggConfetti(getPlayerNo(), 13, 0, m_f32EggConfettiFrame);
                    }
                    m_f32EggConfettiDropFrame = 0.0f;
                }
            }
            if (m_pcEggConfetti != NULL) {
                m_pcEggConfetti->draw();
            }
            if (m_f32EggConfettiFrame <= 0.0f) {
                setClearStatus(STATUS_EGGCONFETTI);
            }
        } else if (m_eStatusRemove & STATUS_EGGCONFETTI) {
            delete m_pcEggConfetti;
            m_pcEggConfetti = NULL;
        }
    }
    if (eStatus & STATUS_NIGHTSEFFECT) {
        if (m_eStatus & STATUS_NIGHTSEFFECT) {
            m_f32NightsAtkEffectFrame -= clsPfSystem::GS()->getFrameRateAdd();
            if (m_u32NightsAtkEffectDropCnt < 2) {
                m_f32NightsAtkEffectDropFrame -= clsPfSystem::GS()->getFrameRateAdd();
                if (m_f32NightsAtkEffectDropFrame <= 0.0f) {
                    switch (m_u32NightsAtkEffectDropCnt) {
                    case 0:
                        nspGlobal::sTask.pcBaseStage->addColorDropsEffect(
                            getPlayerNo(), 8, 20, m_f32NightsAtkEffectFrame, 1);
                        m_f32NightsAtkEffectDropFrame = 5.0f;
                        break;
                    case 1:
                        nspGlobal::sTask.pcBaseStage->addColorDropsEffect(
                            getPlayerNo(), 8, 30, m_f32NightsAtkEffectFrame, 1);
                        break;
                    }
                    ++m_u32NightsAtkEffectDropCnt;
                }
            }
            if (m_pcNightsAtkEffect != NULL) {
                m_pcNightsAtkEffect->draw();
            }
            if (m_f32NightsAtkEffectFrame <= 0.0f) {
                delete m_pcNightsAtkEffect;
                m_pcNightsAtkEffect = NULL;
                setClearStatus(STATUS_NIGHTSEFFECT);
            }
        } else if (m_eStatusRemove & STATUS_NIGHTSEFFECT) {
            nspGlobal::sTask.pcBaseStage->deleteColorViewDetail(getPlayerNo());
        }
    }
}

inline void clsPlayerTask::updateReverse()
{
    if (getPlayerNo() < nspGlobal::sTask.pcBaseRace->getUserNum() &&
        (clsDebug::GS()->isDebugCamera(getPlayerNo()) || nspSetEditor::enable()))
    {
        return;
    }
    if (m_cRetCoursePath.getDotPro() < -0.1f && getActionType() != ACTION_TYPE_NULL &&
        getActionType() != ACTION_TYPE_FLY && getActionType() != ACTION_TYPE_RAIL &&
        getActionType() != ACTION_TYPE_RESTART && getActionType() != ACTION_TYPE_AUTOWALLRUN &&
        (nspGlobal::sTask.pcBaseRace->getJudgmentAttr() & JUDGMENTATTR_STATUS_REVERSE) &&
        (getFlag() & FLAG_REVERSE) &&
        !(nspGlobal::sTask.pcBaseRace->getStageNo() == 15 && getActionType() == ACTION_TYPE_TRICK))
    {
        if (m_f32ReverseStartCountFrame > 0.0f) {
            m_f32ReverseStartCountFrame -= clsPfSystem::GS()->getFrameRateAdd();
            if (m_f32ReverseStartCountFrame <= 0.0f) {
                m_f32ReverseStartCountFrame = 0.0f;
                getKeyRef()->playSfSe_User(0xe01a9);
                getKeyRef()->playSfPadSe(getSfId(SF_ID_REVERSE));
            }
        } else {
            setOrStatus(STATUS_REVERSE);
            if (m_f32ReverseRestartCountFrame > 0.0f) {
                m_f32ReverseRestartCountFrame -= clsPfSystem::GS()->getFrameRateAdd();
                if (m_f32ReverseRestartCountFrame < 0.0f) {
                    m_f32ReverseRestartCountFrame = 0.0f;
                }
            } else {
                setActionType(ACTION_TYPE_RESTART);
            }
        }
    } else {
        m_f32ReverseStartCountFrame = 60.0f;
        m_f32ReverseRestartCountFrame = 300.0f;
    }
}

inline void clsPlayerTask::updateReturnPoint()
{
    u16 u16OldLine = m_u16ReturnLineNo;
    u16 u16Attr = nspGlobal::sTask.pcBaseStage->getCoursePathPtr()
                      ->getLineData(getRetCoursePathRef()->getActiveLineNo())
                      ->u16TypeAttr;
    u16 u16Line = m_cRetCoursePath.m_u16ActiveLineNo;
    if (u16OldLine != u16Line &&
        ((getStatus() & STATUS_GROUND) || getActionType() == ACTION_TYPE_GDIVE ||
         getActionType() == ACTION_TYPE_GDIVE_AUTO || getActionType() == ACTION_TYPE_FLY ||
         (clsGameMgr::GS()->getGameMode() == clsGameMgr::GAME_MODE___MISSION &&
          static_cast<clsMissionRace_Task*>(nspGlobal::sTask.pcBaseRace)->getRuleType() == 4) ||
         m_bForcedUpdateFlag))
    {
        if (getActionType() != ACTION_TYPE_RESTART && !(u16Attr & 1)) {
            m_bForcedUpdateFlag = 0;
            setReturnLineNo(u16Line);
            memcpy(&m_cBackUpGravity, getGravityRef(), sizeof(m_cBackUpGravity));
            setBackUpLightNo(getLightNo());
            if (isUser() || isReplay()) {
                setBackUpFogNo(
                    nspGlobal::sTask.pcBaseRace->getReInitGraphics_Task()->getFogNo(getPlayerNo()));
            }
        }
    }
}

void clsPlayerTask::execute()
{
    switch (getMode()) {
    case 2:
        if (nspGlobal::sTask.pcBaseRace->getRaceInfo() < RACE_INFO___RESTART) {
            return;
        }
        if (m_opcResidenceTexModel_PS2 != NULL) {
            nspNnUtil::TexResidence_PS2(m_opcResidenceTexModel_PS2->m_psTexList);
        }
        if (m_pcBackLineTask != NULL) {
            // The original destroys the task before deleting it.
            m_pcBackLineTask->~clsBackLineEffectTask();
            delete m_pcBackLineTask;
        }
        m_pcBackLineTask = new clsBackLineEffectTask(0, &oasPlayerLineParam, m_ePlayerNo);
        m_pcBackLineTask->m_opsTrickSubParam = &oasPlayerLineTrickParam;
        m_pcVaporTrailTask = new clsVaporTrail_Task(m_s8CameraNo, m_ePlayerNo, 0);
        addMode();
        break;

    case 3: {
        if (clsOOProfile::GS()->m_bRunning) {
            clsOOProfile::GS()->begin("P exec");
        }
        m_pcDebug->execute();
        m_pcDebug->test();
        if (getPlayerNo() < nspGlobal::sTask.pcBaseRace->getUserNum()) {
            if (clsDebug::GS()->isDebugCamera(getPlayerNo())) {
                if (clsOOProfile::GS()->m_bRunning) {
                    clsOOProfile::GS()->end("P exec");
                }
                return;
            }
        } else if (clsDebug::GS()->isDebugCamera(0)) {
            if (clsOOProfile::GS()->m_bRunning) {
                clsOOProfile::GS()->end("P exec");
            }
            return;
        }
        m_pcDebug->update();
        NNS_VECTORFAST sFixedPosVecFast;
        if (m_pcDebug->isFlag(static_cast<clsPlayerDebug::enmFlag>(0x200))) {
            nnCopyVectorFast(&sFixedPosVecFast, &m_sPosVecFast[0]);
        }
        updateVisibility();
        if (m_sPosVecFast[0].y <=
                toaf32StageMinimumHeightTable[nspGlobal::sTask.pcBaseRace->getStageNo()] &&
            getActionType() != ACTION_TYPE_RESTART)
        {
            setActionType(ACTION_TYPE_RESTART);
        }
        m_pcKey->update();
        if (m_pcPhysic->m_enColUpdateType != COL_UPDATE_NOT_ONEFRAME) {
            m_cGravityActionManager.update();
        }
        m_cCharaVoice.update();
        if (m_f32CamDelayRqTime > 0.0f) {
            m_f32CamDelayRqTime -= clsPfSystem::GS()->getFrameRateAdd();
            if (m_f32CamDelayRqTime <= 0.0f) {
                changeCameraRq(m_u32CamDelayRqType);
            }
        }
        setClearStatus(STATUS_ON_WATER);
        setClearStatus(STATUS_ON_SNOW);
        if (getStatus() & STATUS_GROUND) {
            setClearStatus(STATUS_SEARCH_RAIL);
        } else if (getKeyRef()->GetState().u32KeyState & 0x800000) {
            setOrStatus(STATUS_SEARCH_RAIL);
        }
        useRingGear();
        updateAction();
        m_pcGearCtrl->updateAction();
        m_cGravity.update();
        physic();
        if (nspGlobal::sTask.pcBaseRace->getRaceInfo() >= RACE_INFO___COUNT_DOWN) {
            calcVelocity(&m_sVelocityVecFast);
            nnNormalizeVectorFast(&m_sMoveNrmVecFast, &m_sVelocityVecFast);
            m_pcPhysic->update();
            m_cReaction.updateWall();
            m_cReaction.updateGround();
            m_cSlipStream.update(this);
        }
        updateStatus();
        updateSurface();
        update();
        updateModel();
        nspGlobal::sTask.pcBaseStage->getCoursePathPtr()->searchPoint(
            &m_cRetCoursePath, &m_sPosVecFast[0], m_cVelocity.getDirVecFastPtr(), 0);
        updateReverse();
        m_pcLap->update();
        if (m_pcLap->m_s32LapNum != m_pcLap->m_s32LapOld) {
            m_bForcedUpdateFlag = 1;
        }
        updateReturnPoint();
        m_pcBackLineTask->addFlg(8);
        if (m_pcDebug->isFlag(static_cast<clsPlayerDebug::enmFlag>(0x200))) {
            nnCopyVectorFast(&m_sPosVecFast[0], &sFixedPosVecFast);
            m_pcPhysic->setPosition(&m_sPosVecFast[0]);
        }
        if (clsOOProfile::GS()->m_bRunning) {
            clsOOProfile::GS()->end("P exec");
        }
        break;
    }
    }
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
    clsPfCameraMgr* pcCameraMgr = clsPfCameraMgr::GS();
    if (!isDefaultUser()) {
        return;
    }
    clsPfCamera* pcCamera = pcCameraMgr->getCamera(m_s8CameraNo);
    switch (u32Type) {
    case 0x2:
        pcCamera->getMixer()->setCamCtrlTbl(u32Type, 2, 0);
        break;
    case 0x4E:
        pcCamera->getMixer()->setCamCtrlTbl(u32Type, 2, 0);
        break;
    case 0x5:
        pcCamera->getMixer()->setCamCtrlTbl(u32Type, 3, 0);
        break;
    case 0x9:
        pcCamera->getMixer()->setCamCtrlTbl(u32Type, 2, 0);
        break;
    case 0xB:
        pcCamera->getMixer()->setCamCtrlTbl(u32Type, 3, 0);
        break;
    case 0xF:
        pcCamera->getMixer()->setCamCtrlTbl(u32Type, 3, 0);
        break;
    case 0x15:
        pcCamera->getMixer()->setCamCtrlTbl(u32Type, 1, 0);
        break;
    case 0x66:
        pcCamera->getMixer()->setCamCtrlTbl(u32Type, 2, 0);
        break;
    case 0x12:
        pcCamera->getMixer()->setCamCtrlTbl(u32Type, 3, 0);
        break;
    case 0x1C:
        pcCamera->getMixer()->setCamCtrlTbl(u32Type, 2, 0);
        break;
    case 0x22:
        pcCamera->getMixer()->setCamCtrlTbl(u32Type, 2, 0);
        break;
    case 0x24: {
        clsCamMixer* pcMixer = pcCameraMgr->getCamera(m_eDefaultCtrlType)->getMixer();
        pcMixer->m_pacCamCtrl[0] = pcMixer->m_pacCamCtrl[1] = NULL;
        pcMixer->m_u8HasNum = 0;
        pcCamera->getMixer()->setCamCtrlTbl(u32Type, 2, 0);
        switch (m_eDefaultCtrlType) {
        case CTRL_TYPE_1P:
        case CTRL_TYPE_2P:
        case CTRL_TYPE_3P:
        case CTRL_TYPE_4P: {
            pcCameraMgr->getCamera(m_eDefaultCtrlType)->resetMixerData();
            clsSrCamCtrlMgr* pcSrCamCtrlMgr = clsSrCamCtrlMgr::GS();
            clsSrCamMixer* pcSrCamMixer = m_ePlayerNo < pcSrCamCtrlMgr->m_vecpcSrCamMixer.size()
                                              ? pcSrCamCtrlMgr->m_vecpcSrCamMixer[m_ePlayerNo]
                                              : NULL;
            pcSrCamMixer->m_u32MaxParamIdx = 9;
            pcSrCamMixer->clearCamFilter();
            break;
        }
        }
        break;
    }
    case 0x33:
        pcCamera->getMixer()->setCamCtrlTbl(u32Type, 2, 0);
        break;
    case 0x5A:
        pcCamera->getMixer()->setCamCtrlTbl(u32Type, 2, 0);
        break;
    case 0x68:
        pcCamera->getMixer()->setCamCtrlTbl(u32Type, 2, 0);
        break;
    default:
        pcCamera->getMixer()->setCamCtrlTbl(u32Type, 1, 0);
        break;
    }
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
