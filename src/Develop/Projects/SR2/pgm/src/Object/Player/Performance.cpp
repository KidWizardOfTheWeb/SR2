#include "Develop/Projects/SR2/pgm/src/Object/Player/Performance.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2System.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/Havok.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/Character.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/CtrlData.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearCtrl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/PlayerPhysic.hpp"

f32 clsPrfm::t_of32FLightMaxSpeed = 0.8333333f;
f32 clsPrfm::t_of32FlightMinSpeed = 0.2777778f;
f32 clsPrfm::t_of32FlightResistanceRate = 0.004f;
f32 clsPrfm::t_of32FlightFloatingBaseRate = 0.75f;
f32 clsPrfm::t_of32FlightFloatingDiffRate = 0.25f;
extern f32 t_of32InfiniGpLimitFrame;
extern f32 t_of32InfiniGpCheckUsed;
f32 clsPrfm::t_of32InfiniGpCheckNotUse = -10.0f;

namespace nspAgp {
const f32 toaf32GpUsedRate[5] = {1.0f, 0.9f, 1.1f, 1.0f, 1.0f};
} // namespace nspAgp

void clsPrfm::reset()
{
    m_f32InfiniGpFrame = -10.0f;
}

void clsPrfm::Limit(stcData& rsData)
{
    if (rsData.f32Speed[0] > 1.1574074f) {
        rsData.f32Speed[0] = 1.1574074f;
    } else if (rsData.f32Speed[0] < 0.5555556f) {
        rsData.f32Speed[0] = 0.5555556f;
    }
    if (rsData.f32Speed[1] > 1.1574074f) {
        rsData.f32Speed[1] = 1.1574074f;
    } else if (rsData.f32Speed[1] < 0.5555556f) {
        rsData.f32Speed[1] = 0.5555556f;
    }
    if (rsData.f32Speed[2] > 1.1574074f) {
        rsData.f32Speed[2] = 1.1574074f;
    } else if (rsData.f32Speed[2] < 0.5555556f) {
        rsData.f32Speed[2] = 0.5555556f;
    }
    if (rsData.f32Accele[0] > 0.011574074f) {
        rsData.f32Accele[0] = 0.011574074f;
    } else if (rsData.f32Accele[0] < 0.0015432098f) {
        rsData.f32Accele[0] = 0.0015432098f;
    }
    if (rsData.f32Accele[1] > 0.0077160494f) {
        rsData.f32Accele[1] = 0.0077160494f;
    } else if (rsData.f32Accele[1] < 0.00023148148f) {
        rsData.f32Accele[1] = 0.00023148148f;
    }
    if (rsData.f32Accele[2] > 0.0077160494f) {
        rsData.f32Accele[2] = 0.0077160494f;
    } else if (rsData.f32Accele[2] < 0.00010802469f) {
        rsData.f32Accele[2] = 0.00010802469f;
    }
    if (rsData.f32Durability > 200.0f) {
        rsData.f32Durability = 200.0f;
    } else if (rsData.f32Durability < 10.0f) {
        rsData.f32Durability = 10.0f;
    }
    if (rsData.f32Grip > 1.0f) {
        rsData.f32Grip = 1.0f;
    } else if (rsData.f32Grip < 0.0f) {
        rsData.f32Grip = 0.0f;
    }
    if (rsData.f32RotateSpeed > 0.17453292f) {
        rsData.f32RotateSpeed = 0.17453292f;
    } else if (rsData.f32RotateSpeed < 0.0f) {
        rsData.f32RotateSpeed = 0.0f;
    }
    if (rsData.f32RotateAccele > 0.17453292f) {
        rsData.f32RotateAccele = 0.17453292f;
    } else if (rsData.f32RotateAccele < 0.0f) {
        rsData.f32RotateAccele = 0.0f;
    }
}

void clsPrfm::updateData()
{
    clsGearCtrl& rcGearCtrl = *m_pcGearCtrl;
    clsPlayerTask* pcPlayer = rcGearCtrl.m_pcPlayer;
    f32 f32GpUsedRate = nspAgp::toaf32GpUsedRate[pcPlayer->m_pcCharacter->m_eBaseType];

    for (s32 i = 0; i < 3; i++) {
        m_sData.f32Speed[i] = m_f32AdjustSpeedRate *
                              (rcGearCtrl.m_sAddPrfmData.f32MaxSpeedRate * m_sBase.f32Speed[i] +
                               rcGearCtrl.m_sAddPrfmData.f32Speed[i] + 0.0f);

        m_sData.f32Accele[i] = m_f32AdjustAcceleRate *
                               (m_sBase.f32Accele[i] * rcGearCtrl.m_sAddPrfmData.f32AcceleRate +
                                rcGearCtrl.m_sAddPrfmData.f32Accele[i] + 0.0f);
    }

    m_sData.f32RotateSpeed = m_sBase.f32RotateSpeed * rcGearCtrl.m_sAddPrfmData.f32RotateSpeedRate +
                             rcGearCtrl.m_sAddPrfmData.f32RotateSpeed + 0.0f;

    m_sData.f32RotateAccele =
        m_sBase.f32RotateAccele * rcGearCtrl.m_sAddPrfmData.f32RotateAcceleRate +
        rcGearCtrl.m_sAddPrfmData.f32RotateAccele + 0.0f;

    m_sData.f32Grip = m_sBase.f32Grip * rcGearCtrl.m_sAddPrfmData.f32GripRate +
                      rcGearCtrl.m_sAddPrfmData.f32Grip + 0.0f;

    m_sData.f32JumpSpeed = m_sBase.f32JumpSpeed;
    m_sData.f32JumpAccele = m_sWalk.f32JumpAccele;

    m_sData.f32Durability = m_sBase.f32Durability * rcGearCtrl.m_sAddPrfmData.f32DurabilityRate +
                            rcGearCtrl.m_sAddPrfmData.f32Durability + 0.0f;

    m_sData.f32MaxAgp = m_sBase.f32MaxAgp + rcGearCtrl.m_sAddPrfmData.f32MaxAgp;

    m_sData.u32Ability = m_sBase.u32Ability | rcGearCtrl.m_sAddPrfmData.u32Ability;

    m_sData.f32GCtrlDischargeSpeed =
        m_sBase.f32GCtrlDischargeSpeed + rcGearCtrl.m_sAddPrfmData.f32GCtrlDischargeSpeed;

    m_sData.f32GDiveSpeedRate =
        m_sBase.f32GDiveSpeedRate * rcGearCtrl.m_sAddPrfmData.f32GDiveSpeedRate;

    m_sData.f32GPTakeRate = m_sBase.f32GPTakeRate + rcGearCtrl.m_sAddPrfmData.f32GPTakeRate;

    m_sData.f32GCtrlGpUseRate = m_sBase.f32GCtrlGpUseRate * f32GpUsedRate +
                                rcGearCtrl.m_sAddPrfmData.f32GCtrlGpUseRate + 0.0f;

    m_sData.f32GDiveGpUseRate = m_sBase.f32GDiveGpUseRate * f32GpUsedRate +
                                rcGearCtrl.m_sAddPrfmData.f32GDiveGpUseRate + 0.0f;

    m_sData.s32AttackEnableFrame =
        m_sBase.s32AttackEnableFrame + rcGearCtrl.m_sAddPrfmData.s32AttackEnableFrame;

    m_sData.s16RingCapacity = m_sBase.s16RingCapacity + rcGearCtrl.m_sAddPrfmData.s16RingCapacity;

    m_sData.s8TrickRank = m_sBase.s8TrickRank + rcGearCtrl.m_sAddPrfmData.s8TrickRank;

    m_sData.s8ItemRank = m_sBase.s8ItemRank + rcGearCtrl.m_sAddPrfmData.s8ItemRank;

    m_sWalk.s16RingCapacity = m_sBase.s16RingCapacity + rcGearCtrl.m_sAddPrfmData.s16RingCapacity;

    m_sWalk.f32MaxAgp = m_sBase.f32MaxAgp + rcGearCtrl.m_sAddPrfmData.f32MaxAgp;

    if ((pcPlayer->m_eStatus & STATUS_LINK_ONE) != STATUS_NULL) {
        m_sData.u32Ability = 0;
    }

    if (pcPlayer->getPlayerType() != PLAYER_TYPE__GHOST) {
        if (m_sData.u32Ability & ABILITY_GHOST) {
            pcPlayer->m_pcCharacter->m_f32DrawAlpha = 0.3f;

            clsPlayerPhysic* pcPhysic = pcPlayer->m_pcPhysic;

            pcPhysic->m_cMaskColFilter &=
                ~(clsCollisionFilter::TYPE_PLAYER | clsCollisionFilter::FILTER_PLAYER);

            pcPhysic->m_pcProxy->getShapePhantom()
                ->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo =
                pcPhysic->m_pcPhantom->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo &
                pcPhysic->m_cMaskColFilter;

            clsHavok::GS()->m_pcWorld->updateCollisionFilterOnPhantom(
                pcPhysic->m_pcPhantom, HK_UPDATE_COLLECTION_FILTER_IGNORE_SHAPE_COLLECTIONS);
        } else {
            pcPlayer->m_pcCharacter->m_f32DrawAlpha = 1.0f;

            clsPlayerPhysic* pcPhysic = pcPlayer->m_pcPhysic;

            pcPhysic->m_cMaskColFilter = clsCollisionFilter::FULL_MASK;

            pcPhysic->m_pcProxy->getShapePhantom()
                ->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo =
                pcPhysic->m_pcPhantom->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo &
                pcPhysic->m_cMaskColFilter;

            clsHavok::GS()->m_pcWorld->updateCollisionFilterOnPhantom(
                pcPhysic->m_pcPhantom, HK_UPDATE_COLLECTION_FILTER_IGNORE_SHAPE_COLLECTIONS);
        }
    }

    if ((m_sData.u32Ability & ABILITY_GP_INFINITY) && !(m_sBase.u32Ability & ABILITY_GP_INFINITY)) {
        if (m_f32InfiniGpFrame == -10.0f) {
            m_f32InfiniGpFrame = 1500.0f;

            pcPlayer->m_cGravityActionManager.m_f32Point = m_sData.f32MaxAgp;

            pcPlayer->m_cGravityActionManager.checkLimitPoint();
        } else if (m_f32InfiniGpFrame == -1.0f) {
            m_sData.u32Ability &= ~ABILITY_GP_INFINITY;
        }
    } else {
        m_f32InfiniGpFrame = -10.0f;

        if (m_pcGearCtrl->m_eCtrlNo == nspGear::CTRL_MAG) {
            m_pcGearCtrl->setUnuseGearLevel(nspGear::LV_03);
        }
    }

    if (clsGameMgr::GS()->m_eMode != GAME_MODE___SURVIVAL_BATTLE) {
        Limit(m_sData);
    }

    pcPlayer->m_f32MaxSpeed = m_sData.f32Speed[2];
}

void clsPrfm::updateFrame()
{
    if (m_sBase.u32Ability & ABILITY_GP_INFINITY) {
        return;
    }
    if (m_f32InfiniGpFrame <= 0.0f) {
        return;
    }
    m_f32InfiniGpFrame -= clsPfSystem::GS()->getFrameRateAdd();
    if (m_f32InfiniGpFrame > 0.0f) {
        return;
    }
    m_sData.u32Ability &= ~ABILITY_GP_INFINITY;
    m_f32InfiniGpFrame = -10.0f;
    if (m_pcGearCtrl->m_eCtrlNo == nspGear::CTRL_MAG) {
        m_pcGearCtrl->setUnuseGearLevel(nspGear::LV_03);
    }
}

clsPrfm::stcData* clsPrfm::getDataPtr() const
{
    if (m_pcGearCtrl->m_eCtrlMode != clsGearCtrl::CTRL_MODE_WALK) {
        return const_cast<stcData*>(&m_sData);
    }
    return const_cast<stcData*>(&m_sWalk);
}

void clsPrfm::setup(clsCharacter* pcChara, clsGearCtrl* pcGearCtrl)
{
    const stcCtrlData* psGearData = pcGearCtrl->m_posData;
    const ::stcData* psCharaData = pcChara->m_posData;
    const stcBasePrfm& rcWalk = nspChara::osWalkPrfm[pcChara->m_eWalkType];
    const stcBasePrfm& rcBase = nspChara::oasBasePrfm[pcChara->m_eBaseType];
    m_pcGearCtrl = pcGearCtrl;

    for (s32 i = 0; i < 3; i++) {
        m_sWalk.f32Speed[i] = rcWalk.f32Speed[i];
        m_sWalk.f32Accele[i] = rcWalk.f32Accele[i];
    }

    m_sWalk.f32RotateSpeed = rcWalk.f32RotateSpeed;
    m_sWalk.f32RotateAccele = rcWalk.f32RotateAccele;
    m_sWalk.f32Grip = rcWalk.f32Grip;
    m_sWalk.f32JumpSpeed = 0.31578946f;
    m_sWalk.f32JumpAccele = 0.01754386f;
    m_sWalk.f32MaxAgp = 100.0f;
    m_sWalk.f32Durability = rcWalk.f32Durability;
    m_sWalk.s16RingCapacity = 100;
    m_sWalk.s8TrickRank = '\0';
    m_sWalk.s8ItemRank = '\0';
    m_sWalk.f32GPTakeRate = 1.0f;
    m_sWalk.f32GCtrlGpUseRate = 1.0f;
    m_sWalk.f32GDiveGpUseRate = 1.0f;
    m_sWalk.u32Ability = 0;

    if (clsGameMgr::GS()->m_eMode != GAME_MODE___SURVIVAL_BATTLE) {
        Limit(m_sWalk);
    }

    m_f32WeightRate = psCharaData->f32Weight + psGearData->f32Weight;
    f32 f32AdjustSpeedRate = 1.0f + m_f32WeightRate;
    f32 f32AdjustCurveRate = 1.0f - m_f32WeightRate;

    for (s32 i = 0; i < 3; i++) {
        m_sBase.f32Speed[i] = f32AdjustSpeedRate * rcBase.f32Speed[i];
        m_sBase.f32Accele[i] = f32AdjustCurveRate * rcBase.f32Accele[i];
    }

    m_sBase.f32RotateSpeed = f32AdjustCurveRate * rcBase.f32RotateSpeed;
    m_sBase.f32RotateAccele = f32AdjustCurveRate * rcBase.f32RotateAccele;
    m_sBase.f32Grip = f32AdjustCurveRate * rcBase.f32Grip;
    m_sBase.f32JumpSpeed = 0.31578946f;
    m_sBase.f32JumpAccele = 0.01754386f;
    m_sBase.f32MaxAgp = 100.0f;
    m_sBase.f32Durability = f32AdjustSpeedRate * rcBase.f32Durability;
    m_sBase.s16RingCapacity = 100;
    m_sBase.s8TrickRank = '\0';
    m_sBase.s8ItemRank = '\0';
    m_sBase.f32GPTakeRate = 1.0f;
    m_sBase.f32GCtrlGpUseRate = 1.0f;
    m_sBase.f32GDiveGpUseRate = 1.0f;
    m_sBase.u32Ability = rcBase.u32Ability;
    m_sBase.f32GCtrlDischargeSpeed = clsGravityControl::t_sCommonSetting.f32MaxSpeed;
    m_sBase.f32GDiveSpeedRate = 1.0f;

    if (clsGameMgr::GS()->m_eMode == GAME_MODE___FREE_RACE ||
        clsGameMgr::GS()->m_eMode == GAME_MODE___SURVIVAL_RELAY)
    {
        s8 s8Agp;

        if (clsGameMgr::GS()->m_eMode == GAME_MODE___FREE_RACE) {
            s8Agp = clsGameMgr::GS()->getFreeAgp_Option();
        } else {
            s8Agp = clsGameMgr::GS()->getRelayAgp_Option();
        }

        // AGP option: low = 0.5x, normal = 1.0x, high = 1.5x
        switch (s8Agp) {
        case 0:
            m_sBase.f32GPTakeRate *= 0.5f;
            break;

        case 1:
            m_sBase.f32GPTakeRate *= 1.0f;
            break;

        case 2:
            m_sBase.f32GPTakeRate *= 1.5f;
            break;
        }
    }

    if (clsGameMgr::GS()->m_eMode != GAME_MODE___SURVIVAL_BATTLE) {
        Limit(m_sBase);
    }

    updateData();
}

void clsPrfm::setRingCapacity(s16 s16Ring)
{
    m_sWalk.s16RingCapacity = s16Ring;
    m_sBase.s16RingCapacity = s16Ring;
    return;
}

void clsPrfm::setMaxAgp(f32 f32MaxAGP)
{
    m_sWalk.f32MaxAgp = f32MaxAGP;
    m_sBase.f32MaxAgp = f32MaxAGP;
    return;
}
