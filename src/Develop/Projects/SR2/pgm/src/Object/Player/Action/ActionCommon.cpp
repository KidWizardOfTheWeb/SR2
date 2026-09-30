#include "Develop/Projects/SR2/pgm/src/2D/Score/BonusPoint2D.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/Character.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/PlayerPhysic.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Key/PlayerKey.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Action/ActionCommon.hpp"
#include "Develop/Projects/SR2/pgm/src/Config/nspWheel.hpp"

namespace nspAgp {
f32 toaf32BonusPower[6] = {2.5f, 5.0f, 7.5f, 10.0f, 12.5f, 15.0f};
} // namespace nspAgp

static u8 chk__clsPlayerTask_t_sActionFuncTbl_SizeCheck_[1];

void clsPlayerTask::updateAction()
{
    void (clsPlayerTask::*pfAction)() = t_sActionFuncTbl[m_eActionType].pfExexAction;
    if (pfAction != NULL) {
        (this->*pfAction)();
    }
}

void clsPlayerTask::useRingGear()
{
    if (m_pcCharacter->getType() == 18 || !(m_cPrfm.m_sData.u32Ability & 0x800) ||
        (m_eStatus & STATUS_GOAL))
    {
        return;
    }
    clsGearCtrl* pcGear = m_pcGearCtrl;
    enmActionType eAction = m_eActionType;
    u8 u8RingTime = m_cRingLimitTime.update();
    u8 u8GravityTime = m_cRingGravityLimitTime.update();
    bool bRide = pcGear->m_eCtrlMode != clsGearCtrl::CTRL_MODE_WALK;
    u8 u8UseRing = m_cGravityActionManager.m_eAction != clsGravityActionManager::ACTION_NULL
                       ? u8GravityTime
                       : u8RingTime;
    if (u8UseRing && bRide && eAction != ACTION_TYPE_ATTACK && eAction != ACTION_TYPE_PATH &&
        eAction != ACTION_TYPE_NULL)
    {
        setRingNum(m_s32RingNum - 1);
    }
    if (((eAction >= ACTION_TYPE_WALK_RUN && eAction <= ACTION_TYPE_WALK_BRAKE) ||
         (eAction >= ACTION_TYPE_RUN && eAction <= ACTION_TYPE_BRAKE)) &&
        m_pcKey->m_bValidFlag && eAction != ACTION_TYPE_ATTACK)
    {
        if (m_s32RingNum > 0) {
            if (!bRide && (m_eStatus & STATUS_GROUND) && !(m_eStatus & STATUS_NONE_RIDE)) {
                pcGear->requestGearRide(1, 15.0f, ACTION_TYPE_RUN);
            }
        } else if (m_s32RingNum == 0 && bRide && (m_eStatus & STATUS_GROUND) &&
                   m_pcPhysic->m_sColInfo[m_pcPhysic->m_u8ColInfoNo].u8Attr != 5 &&
                   m_pcPhysic->m_sColInfo[1 - m_pcPhysic->m_u8ColInfoNo].u8Attr != 5 &&
                   m_f32Speed >= 0.0f)
        {
            pcGear->requestGearRide(0, 15.0f, ACTION_TYPE_WALK_RUN);
        }
    }
}

void clsPlayerTask::updateObstacle()
{
    if (m_f32ObstacleFrame > 0.0f) {
        m_f32ObstacleFrame -= clsPfSystem::GS()->getFrameRateAdd();
        if (m_f32ObstacleFrame <= 0.0f) {
            m_f32ObstacleFrame = 0.0f;
            m_eLinkType = LINK_TYPE_NULL;
            if (!(m_cPrfm.getDataPtr()->u32Ability & 0x800)) {
                new clsBonusPoint2D_Task(
                    m_ePlayerNo, 1, m_cGravityActionManager.m_f32LinkBonusPoint);
            }
        }
    }
}
