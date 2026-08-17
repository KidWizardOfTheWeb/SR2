#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickRigidBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Gravity/GravityActionControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/DebrisControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GravityGimmickManager/GravityGimmickManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/Debug.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Post/BurnOut/BurnOutCore.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/Game.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Mission/MissionBreakMsg2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/BonusPoint2D.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/MissionRace.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/Havok.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2System.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OORandom.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/GlobalData.hpp"
#include "usr/local/sega/nn/src/Matrix/nnmakematrix.h"
#include "usr/local/sega/nn/src/Matrix/nnmatrix.h"
#include "usr/local/sega/nn/src/Print/nnprint.h"

#include "Develop/Projects/SR2/pgm/src/Havok/HavokBase.hpp"

static inline void updateMissionBreak(clsRigidBodyGimmickObj* pcObj)
{
    if (clsGameMgr::GS()->getGameMode() == clsGameMgr::GAME_MODE___MISSION) {
        clsMissionRace_Task* pcMission =
            static_cast<clsMissionRace_Task*>(nspGlobal::sTask.pcBaseRace);
        if (pcMission->getRuleType() == 11) {
            if ((pcObj->m_f32MissionBreakFrame += 1.0f) >=
                clsMissionRace_Task::tof32MissionBreakFrame)
            {
                if (pcObj->m_pcGravityGimmickControl == 0) {
                    pcObj->startBreak(clsRigidBodyGimmickObj::BREAK_TYPE_PLAYER);
                } else {
                    pcObj->startBreak(clsRigidBodyGimmickObj::BREAK_TYPE_GRAVITY);
                }
            }
        }
    }
}

stcInfo clsRigidBodyGimmickObj::oasGroundInfo[4];

void clsRigidBodyGimmickObj::resetBaseControl()
{
    m_cBreakControl.reset();
    m_cContactControl.reset();
    if (m_pcGravityGimmickControl != 0) {
        m_pcGravityGimmickControl->reset();
    }
    clsDebrisControl* pcDebrisControl = m_pcDebrisControl;
    if (pcDebrisControl != 0) {
        pcDebrisControl->reset();
    }
    m_eBreakType = BREAK_TYPE_OTHER;
    m_eControlMode = CTRL_MODE_MAIN;
    m_pcContactPlayer = 0;
    m_pcContactObject = 0;
}

void clsRigidBodyGimmickObj::reset()
{
    hkVector4 cZero;

    setSetData();
    setData();
    resetBaseControl();

    cZero.setZero4();
    m_pcRigidBody->setLinearVelocity(cZero);
    m_pcRigidBody->setAngularVelocity(cZero);

    m_pcRigidBody->m_motion.m_motionState.m_maxLinearVelocity = 200.0f;
    m_pcRigidBody->m_motion.m_motionState.m_maxAngularVelocity = 200.0f;
    m_pcRigidBody->m_motion.m_motionState.m_linearDamping = 0.05f;
    m_pcRigidBody->m_motion.m_motionState.m_angularDamping = 0.05f;
    m_pcRigidBody->setFlag(1, 0);

    clsGimmickRigidBody* pcRigidBody = m_pcRigidBody;
    hkVector4 position(m_sPosVecFast.x, m_sPosVecFast.y, m_sPosVecFast.z, 0.0f);
    hkQuaternion rotation(m_sRotQuat.x, m_sRotQuat.y, m_sRotQuat.z, m_sRotQuat.w);
    pcRigidBody->setPositionAndRotation(position, rotation);
}

void clsRigidBodyGimmickObj::execute()
{
    if (m_pcDebrisControl != 0) {
        if ((m_eControlFlag & CTRL_FLAG_UPDATE_DEBRIS) != 0) {
            m_pcDebrisControl->update();
            clsGimmickRigidBody* pcRigidBody = m_pcRigidBody;
            clsDebrisControl* pcDebrisControl = m_pcDebrisControl;
            f32 f32VelocityZ = pcRigidBody->m_motion.m_linearVelocity.z;
            f32 f32VelocityY = pcRigidBody->m_motion.m_linearVelocity.y;
            f32 f32VelocityX = pcRigidBody->m_motion.m_linearVelocity.x;
            pcDebrisControl->m_sVelocity.x = f32VelocityX;
            pcDebrisControl->m_sVelocity.y = f32VelocityY;
            pcDebrisControl->m_sVelocity.z = f32VelocityZ;

            if (checkRequestDrawDebris() && !m_pcDebrisControl->m_bBreak) {
                NNS_MATRIX sTrsMtx;
                NNS_VECTORFAST sBoundVecFast;
                nnMakeQuaternionMatrix(&sTrsMtx, &m_sRotQuat);
                nnCopyVectorFastMatrixTranslation(&sTrsMtx, &m_sPosVecFast);
                nnSetUpVectorFast(&sBoundVecFast,
                                  m_pcDebrisControl->m_sVelocity.x,
                                  m_pcDebrisControl->m_sVelocity.y * -1.0f,
                                  m_pcDebrisControl->m_sVelocity.z);
                sBoundVecFast.w = 1.0f;
                nnScaleVectorFast(
                    &sBoundVecFast, &sBoundVecFast, 1.0f / clsPfSystem::GS()->m_f32FrameRate);
                if (sBoundVecFast.y * sBoundVecFast.y < 1.0f) {
                    sBoundVecFast.y *= 2.0f;
                }
                m_pcDebrisControl->startBreak(&sTrsMtx, &sBoundVecFast);
            }
        }
    }

    if (m_cBreakControl.m_eMode == clsBreakControl::MODE_EXECUTE) {
        m_cBreakControl.update();
        if (m_cBreakControl.m_eMode == clsBreakControl::MODE_BREAK) {
            startBreak(m_eBreakType);
        }
    }

    switch (m_eControlMode) {
    case CTRL_MODE_MAIN:
        main();
        if (m_cContactControl.m_eMode == clsContactControl::MODE_EXECUTE) {
            startCrash(BREAK_TYPE_PLAYER);
            return;
        }
        if (m_cContactControl.m_eMode == clsContactControl::MODE_BREAK) {
            startBreak(BREAK_TYPE_PLAYER);
        }
        break;

    case CTRL_MODE_GRAVITY:
        mainGravity();
        if (m_pcGravityGimmickControl != 0) {
            m_pcGravityGimmickControl->actionGravity();
            m_pcGravityGimmickControl->manageDestroy();
            switch (m_pcGravityGimmickControl->m_eStatus) {
            case 0:
                if ((m_eControlFlag & CTRL_FLAG_GCANCEL_BREAK) != 0) {
                    startBreak(BREAK_TYPE_GRAVITY);
                    clsGravityGimmickManager::GS()->clsGravityGimmickManager::requestCrash(
                        this, clsGravityGimmickManager::BREAK_TYPE_0);
                } else {
                    m_eControlMode = CTRL_MODE_MAIN;
                    m_f32MissionBreakFrame = 0.0f;
                }
                break;
            case 2:
                startCrash(BREAK_TYPE_GRAVITY);
                clsGravityGimmickManager::GS()->clsGravityGimmickManager::requestCrash(
                    this, clsGravityGimmickManager::BREAK_TYPE_0);
                break;
            case 3:
                startBreak(BREAK_TYPE_GRAVITY);
                clsGravityGimmickManager::GS()->clsGravityGimmickManager::requestCrash(
                    this, clsGravityGimmickManager::BREAK_TYPE_0);
                break;
            default:
                break;
            }
        }
        updateMissionBreak(this);
        {
            clsGimmickRigidBody* pcRigidBody = m_pcRigidBody;
            nnSetUpVectorFast(&m_sPosVecFast,
                              pcRigidBody->m_motion.m_motionState.m_transform.m_translation.x,
                              pcRigidBody->m_motion.m_motionState.m_transform.m_translation.y,
                              pcRigidBody->m_motion.m_motionState.m_transform.m_translation.z);
            m_sRotQuat.x = pcRigidBody->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.x;
            m_sRotQuat.y = pcRigidBody->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.y;
            m_sRotQuat.z = pcRigidBody->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.z;
            m_sRotQuat.w = pcRigidBody->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.w;
        }
        break;

    case CTRL_MODE_CRASH:
        mainCrash();
        updateMissionBreak(this);
        {
            clsGimmickRigidBody* pcRigidBody = m_pcRigidBody;
            nnSetUpVectorFast(&m_sPosVecFast,
                              pcRigidBody->m_motion.m_motionState.m_transform.m_translation.x,
                              pcRigidBody->m_motion.m_motionState.m_transform.m_translation.y,
                              pcRigidBody->m_motion.m_motionState.m_transform.m_translation.z);
            m_sRotQuat.x = pcRigidBody->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.x;
            m_sRotQuat.y = pcRigidBody->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.y;
            m_sRotQuat.z = pcRigidBody->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.z;
            m_sRotQuat.w = pcRigidBody->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.w;
        }
        break;

    case CTRL_MODE_BREAKING:
        mainBreaking();
        switch (m_eBreakType) {
        case BREAK_TYPE_OTHER:
            break;
        case BREAK_TYPE_PLAYER:
            break;
        case BREAK_TYPE_INTERRACTION:
            break;
        case BREAK_TYPE_GRAVITY:
            if (m_pcGravityGimmickControl->m_pcPlayer != 0) {
                if (clsGameMgr::GS()->m_eMode == clsGameMgr::GAME_MODE___MISSION) {
                    clsMissionRace_Task* pcMission =
                        static_cast<clsMissionRace_Task*>(nspGlobal::sTask.pcBaseRace);
                    if (pcMission->m_sMissionParamTbl.u8RuleType == 11) {
                        new clsMissionBreakMsg2D_Task(&m_sPosVecFast);
                    }
                }
                ++m_pcGravityGimmickControl->m_pcPlayer->m_cGravityActionManager.m_s32BreakNum;
                clsPrfm::stcData* psData =
                    m_pcGravityGimmickControl->m_pcPlayer->m_cPrfm.getDataPtr();
                if ((psData->u32Ability & 0x2000) != 0 &&
                    m_pcGravityGimmickControl->m_eType == clsGravityActionControl::TYPE_CTRL)
                {
                    clsPlayerTask* pcPlayer = m_pcGravityGimmickControl->m_pcPlayer;
                    volatile f32& f32Point = pcPlayer->m_cGravityActionManager.m_f32Point;
                    pcPlayer->m_cGravityActionManager.m_f32Point = 5.0f + f32Point;
                    pcPlayer->m_cGravityActionManager.checkLimitPoint();
                    bool bCanDraw = true;
                    bool bNormalControl = false;
                    if (pcPlayer->m_eCtrlType >= CTRL_TYPE_1P &&
                        pcPlayer->m_eCtrlType <= CTRL_TYPE_4P)
                    {
                        bNormalControl = true;
                    }
                    if (!bNormalControl && !pcPlayer->isDemo()) {
                        bCanDraw = false;
                    }
                    if (bCanDraw || pcPlayer->m_eCtrlType == CTRL_TYPE_REPLAY) {
                        new (::operator new(sizeof(clsBonusPoint2D_Task)))
                            clsBonusPoint2D_Task(pcPlayer->m_ePlayerNo, 0, 5.0f);
                    }
                }
            }
            break;
        default:
            break;
        }
        m_eControlMode = CTRL_MODE_DEAD;
        callbackDeadEvent();
        break;

    case CTRL_MODE_DEAD:
        mainDead();
        if (clsGameMgr::GS()->m_eMode == clsGameMgr::GAME_MODE___MISSION) {
            clsPlayerTask* pcPlayer = nspGlobal::sTask.apcPlayer[0];
            u8 u8RuleType = static_cast<clsMissionRace_Task*>(nspGlobal::sTask.pcBaseRace)
                                ->m_sMissionParamTbl.u8RuleType;
            u8 b32NotRest = false;
            switch (u8RuleType) {
            case 11:
                b32NotRest = true;
                break;
            case 4:
                if ((pcPlayer->m_cPrfm.m_sData.u32Ability & 4) != 0) {
                    b32NotRest = true;
                }
                break;
            default:
                break;
            }
            if (b32NotRest) {
                return;
            }
        }
        m_cBreakControl.m_cRebirthFrame.update();
        if (m_cBreakControl.m_cRebirthFrame.isEndCount()) {
            reset();
            m_eControlMode = CTRL_MODE_MAIN;
            m_f32MissionBreakFrame = 0.0f;
        }
        break;
    }
}

u8 clsRigidBodyGimmickObj::contactGravityActionRangeEvent(clsPlayerTask* pcPlayer)
{
    if (m_pcGravityGimmickControl != 0 && (m_eControlFlag & CTRL_FLAG_UPDATE_GRAVITY) != 0 &&
        m_pcGravityGimmickControl->m_pcPlayer != pcPlayer)
    {
        m_pcGravityGimmickControl->contactGravityActionRangeEvent(pcPlayer);
        m_eControlMode = CTRL_MODE_GRAVITY;
        callbackGravityEvent();
        clsGravityGimmickManager::GS()->clsGravityGimmickManager::regist(this);
        return 1;
    }
    return 0;
}

void clsRigidBodyGimmickObj::requestDrawContactEffect(const hkContactPoint* pcContact)
{
    static NNS_VECTOR BEGIN_SP = {0.0f, 0.06f, -0.1f};
    static NNS_VECTOR RAND_SP = {0.5f, 0.03f, 0.06f};
    static NNS_VECTOR LOCAL_POS = {0.0f, 0.0f, 0.5f};
    static NNS_VECTOR LOCAL_POS_R = {1.2f, 0.6f, 1.2f};
    static f32 LIFE_FRAME = 60.0f;

    clsGimmickRigidBody* pcRigidBody = m_pcRigidBody;
    if (m_u8DrawFlg != 0) {
        NNS_VECTOR sContactVec;
        sContactVec.x = pcContact->m_position.x;
        sContactVec.y = pcContact->m_position.y;
        sContactVec.z = pcContact->m_position.z;

        NNS_MATRIX sMtx;
        nnMakeQuaternionMatrix(&sMtx, &m_sRotQuat);

        NNS_VECTOR sVelo;
        f32 f32VelocityZ = pcRigidBody->m_motion.m_linearVelocity.z;
        f32 f32VelocityY = pcRigidBody->m_motion.m_linearVelocity.y;
        f32 f32VelocityX = pcRigidBody->m_motion.m_linearVelocity.x;
        sVelo.x = f32VelocityX;
        sVelo.y = f32VelocityY;
        sVelo.z = f32VelocityZ;
        nnScaleVector(&sVelo, &sVelo, 1.0f / 60.0f);
        nnAddVector(&sVelo, &sVelo, &BEGIN_SP);

        void* pvMemory = ::operator new(sizeof(clsBurnOutCore_Task));
        new (pvMemory) clsBurnOutCore_Task(5,
                                           4,
                                           sMtx,
                                           sContactVec,
                                           LOCAL_POS,
                                           LOCAL_POS_R,
                                           sVelo,
                                           RAND_SP,
                                           sContactVec.y,
                                           0.75f,
                                           0.4f,
                                           static_cast<u32>(LIFE_FRAME),
                                           -0.6f,
                                           0.0f);
    }
}

void clsRigidBodyGimmickObj::requestDrawCrashEffect(const hkContactPoint* pcParam1)
{
}

void clsRigidBodyGimmickObj::requestDrawBreakEffect()
{
}

void clsRigidBodyGimmickObj::contactInterraction(clsRigidBodyGimmickObj* pcObject)
{
    startCrash(BREAK_TYPE_INTERRACTION);

    clsGimmickRigidBody* pcRigidBody = m_pcRigidBody;
    clsGimmickRigidBody* pcOtherRigidBody = pcObject->m_pcRigidBody;
    pcRigidBody->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = 0x10004;
    clsHavok::GS()->m_pcWorld->updateCollisionFilterOnEntity(
        pcRigidBody,
        HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
        HK_UPDATE_COLLECTION_FILTER_IGNORE_SHAPE_COLLECTIONS);
    pcRigidBody->setMotionType(hkMotion::MOTION_DYNAMIC,
                               HK_ENTITY_ACTIVATION_DO_ACTIVATE,
                               HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);

    if ((m_eControlFlag & CTRL_FLAG_INTERRACTION_PHYSIC) == 0) {
        pcRigidBody->activate();
        pcRigidBody->m_motion.setLinearVelocity(pcOtherRigidBody->m_motion.m_linearVelocity);

        hkVector4 cRot;
        cRot.x = pcOtherRigidBody->m_motion.m_angularVelocity.x * 0.5f;
        cRot.y = pcOtherRigidBody->m_motion.m_angularVelocity.y * 0.5f;
        cRot.z = pcOtherRigidBody->m_motion.m_angularVelocity.z * 0.5f;
        cRot.w = pcOtherRigidBody->m_motion.m_angularVelocity.w * 0.5f;
        pcRigidBody->m_motion.m_motionState.m_maxAngularVelocity = 47.12389f;
        pcRigidBody->activate();
        pcRigidBody->m_motion.setAngularVelocity(cRot);
        pcRigidBody->m_motion.m_motionState.m_angularDamping = 0.9f;
    }
}

void clsRigidBodyGimmickObj::setData()
{
}

void clsRigidBodyGimmickObj::createData()
{
}

void clsRigidBodyGimmickObj::destroyData()
{
    delete m_pcRigidBody;
    m_pcRigidBody = 0;
}

void clsRigidBodyGimmickObj::contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject)
{
    clsPlayerTask* pcPlayer = static_cast<clsPlayerTask*>(pcObject);
    m_pcContactPlayer = pcObject;

    if (m_cContactControl.isBreak()) {
        return;
    }
    if (m_cContactControl.isExecute()) {
        return;
    }
    if ((m_eControlFlag & CTRL_FLAG_UPDATE_CONTACT) == 0) {
        return;
    }

    if (m_pcGravityGimmickControl != 0 &&
        pcPlayer->m_cGravityActionManager.m_eType == clsGravityActionManager::TYPE_FRONT &&
        m_pcGravityGimmickControl->m_pcPlayer == pcPlayer &&
        clsGameMgr::GS()->m_eMode != clsGameMgr::GAME_MODE___SURVIVAL_BALL)
    {
        startBreak(BREAK_TYPE_PLAYER);
        return;
    }

    m_cContactControl.updateContactPlayer(pcContact, m_pcRigidBody, pcPlayer);

    if (m_cContactControl.m_eMode == clsContactControl::MODE_EXECUTE) {
        startCrash(BREAK_TYPE_PLAYER);
        requestPowerTypeSe(pcPlayer);

        if ((m_eControlFlag & CTRL_FLAG_DRAW_CRASH_EFFECT) != 0) {
            requestDrawCrashEffect(pcContact);
        }
        return;
    }

    if (m_cContactControl.m_eMode == clsContactControl::MODE_BREAK) {
        startBreak(BREAK_TYPE_PLAYER);
    }
}

void clsRigidBodyGimmickObj::contactTriggerCallback(hkContactPointConfirmedEvent& cEvent)
{
    if (m_eControlMode >= CTRL_MODE_BREAKING) {
        return;
    }

    callbackContactTriggerRigidBody(cEvent);
    ++m_cContactControl.m_s32ContactNum;

    const hkCollidable* pcCollidable = cEvent.m_collidableB;
    const hkWorldObject* pcOwner =
        pcCollidable->m_broadPhaseHandle.m_type == 1 ? pcCollidable->getOwner() : 0;
    m_pcContactObject = static_cast<clsObject*>(pcOwner->getUserData());

    if ((m_eControlFlag & CTRL_FLAG_UPDATE_INTERRACTION) != 0) {
        if (m_pcContactObject != 0 && m_pcContactObject->getObjectType() == TYPE_GIMMICK_RIGID) {
            u8 u8MotionType = m_pcRigidBody->m_motion.m_type.m_storage;
            clsRigidBodyGimmickObj* pcRigidObject =
                static_cast<clsRigidBodyGimmickObj*>(m_pcContactObject);
            if (u8MotionType != hkMotion::MOTION_THIN_BOX_INERTIA &&
                u8MotionType != hkMotion::MOTION_CHARACTER &&
                (m_eControlFlag & CTRL_FLAG_INTERRACTION) != 0 &&
                checkContactInterraction(pcRigidObject))
            {
                pcRigidObject->contactInterraction(this);
            }
        }
    }

    if ((m_eControlFlag & CTRL_FLAG_UPDATE_BREAK) != 0) {
        if (m_cBreakControl.m_eMode == clsBreakControl::MODE_EXECUTE) {
            ++m_cBreakControl.m_s32ContactNum;
        }
    }

    if ((m_eControlFlag & CTRL_FLAG_DRAW_CONTACT_EFFECT) != 0 &&
        m_cContactControl.m_s32ContactNum < 2)
    {
        requestDrawContactEffect(cEvent.m_contactPoint);
        m_f32ContactBurnOutEffectFrame = m_f32ContactBurnOutFrame;
        m_s32ContactBurnOutCount = m_s8ContactBurnOutRequestNum;
    }
}

void clsRigidBodyGimmickObj::contactAlwaysCallback(hkContactProcessEvent& cEvent)
{
    if (m_f32ContactBurnOutEffectFrame > 0.0f) {
        m_f32ContactBurnOutEffectFrame -= clsPfSystem::GS()->getFrameRateAdd();
        if (m_f32ContactBurnOutEffectFrame < 0.0f) {
            m_f32ContactBurnOutEffectFrame = 0.0f;
        }
        if (m_s32ContactBurnOutCount != 0 && (static_cast<u32>(m_f32ContactBurnOutEffectFrame) &
                                              (m_s32ContactBurnOutInterval - 1)) == 0)
        {
            requestDrawContactEffect(&cEvent.m_collisionData->m_contactPoints[0].m_contact);
            --m_s32ContactBurnOutCount;
        }
    }
}

void clsRigidBodyGimmickObj::boundAction(clsPlayerTask* pcPlayerTask)
{
    clsRigidBody* pcRigidBody = m_pcRigidBody;
    NNS_VECTORFAST sSpeedVecFast;
    NNS_VECTORFAST sForceVecFast;
    hkVector4 cRot;
    hkVector4 cPos;
    hkVector4 cZero;
    hkVector4 cForce;

    pcRigidBody->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = 0x00410000;
    clsHavok::GS()->m_pcWorld->updateCollisionFilterOnEntity(
        pcRigidBody,
        HK_UPDATE_FILTER_ON_ENTITY_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY,
        HK_UPDATE_COLLECTION_FILTER_IGNORE_SHAPE_COLLECTIONS);
    pcRigidBody->setMotionType(hkMotion::MOTION_DYNAMIC,
                               HK_ENTITY_ACTIVATION_DO_ACTIVATE,
                               HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);

    if ((pcPlayerTask->m_cPrfm.getDataPtr()->u32Ability & 4) != 0) {
        nnScaleAddVectorFast(&sSpeedVecFast,
                             &pcPlayerTask->m_cVelocity.m_sDirVecFast,
                             &pcPlayerTask->m_sUpVecFast,
                             0.25f);
        nnNormalizeVectorFast(&sSpeedVecFast, &sSpeedVecFast);
        nnScaleVectorFast(&sForceVecFast, &sSpeedVecFast, 1.8518518f);

        cPos.set(sForceVecFast.x, sForceVecFast.y, sForceVecFast.z, 0.0f);
        cPos.mul4(clsHavok::GS()->m_cStepInfo.m_invDeltaTime *
                  clsPfSystem::GS()->getFrameRateAdd());
        pcRigidBody->setLinearVelocity(cPos);

        const f32 f32RandX =
            static_cast<f32>(clsOORandom::GS()->rand_DependGame()) * 2.3283064e-10f;
        const f32 f32RandY =
            static_cast<f32>(clsOORandom::GS()->rand_DependGame()) * 2.3283064e-10f;
        const f32 f32RandZ =
            static_cast<f32>(clsOORandom::GS()->rand_DependGame()) * 2.3283064e-10f;
        cRot.set((0.34906584f - 0.69813168f * f32RandZ) * 60.0f,
                 (0.34906584f - 0.69813168f * f32RandY) * 60.0f,
                 (0.34906584f - 0.69813168f * f32RandX) * 60.0f,
                 0.0f);
    } else {
        nnScaleAddVectorFast(&sSpeedVecFast,
                             &pcPlayerTask->m_cVelocity.m_sDirVecFast,
                             &pcPlayerTask->m_sUpVecFast,
                             0.4f);
        nnNormalizeVectorFast(&sSpeedVecFast, &sSpeedVecFast);
        nnScaleVectorFast(
            &sForceVecFast, &sSpeedVecFast, (pcPlayerTask->m_f32Speed + 0.2777778f) * 80.0f);

        cZero.setZero4();
        pcRigidBody->setLinearVelocity(cZero);

        cForce.set(sForceVecFast.x, sForceVecFast.y, sForceVecFast.z, 0.0f);
        cForce.mul4(clsHavok::GS()->m_cStepInfo.m_invDeltaTimeCaret2 *
                    clsPfSystem::GS()->getFrameRateAdd());
        const f32 f32DeltaTime = clsHavok::GS()->m_cStepInfo.m_deltaTime;
        pcRigidBody->activate();
        pcRigidBody->m_motion.applyForce(f32DeltaTime, cForce);

        const f32 f32RandX =
            static_cast<f32>(clsOORandom::GS()->rand_DependGame()) * 2.3283064e-10f;
        const f32 f32RandY =
            static_cast<f32>(clsOORandom::GS()->rand_DependGame()) * 2.3283064e-10f;
        const f32 f32RandZ =
            static_cast<f32>(clsOORandom::GS()->rand_DependGame()) * 2.3283064e-10f;
        cRot.set((0.034906585f - 0.06981317f * f32RandZ) * 60.0f,
                 (0.05235988f - 0.10471976f * f32RandY) * 60.0f,
                 (0.06981317f - 0.13962634f * f32RandX) * 60.0f,
                 0.0f);
    }

    pcRigidBody->m_motion.m_motionState.m_maxAngularVelocity = 6.6666665f;
    pcRigidBody->setAngularVelocity(cRot);
    pcRigidBody->m_motion.m_motionState.m_angularDamping = 0.9f;
}

void clsRigidBodyGimmickObj::setControlMode(enmControlMode eMode)
{
    m_eControlMode = eMode;
    switch (eMode) {
    case CTRL_MODE_MAIN:
        m_f32MissionBreakFrame = 0.0f;
        break;
    case CTRL_MODE_GRAVITY:
        callbackGravityEvent();
        break;
    case CTRL_MODE_CRASH:
        callbackCrashEvent();
        break;
    case CTRL_MODE_BREAKING:
        callbackBreakEvent();
        break;
    case CTRL_MODE_DEAD:
        callbackDeadEvent();
        break;
    }
}

void clsRigidBodyGimmickObj::updateSetEditorCollision()
{
    if (m_pcRigidBody != 0) {
        hkVector4 position(m_sPosVecFast.x, m_sPosVecFast.y, m_sPosVecFast.z, 0.0f);
        hkQuaternion rotation(m_sRotQuat.x, m_sRotQuat.y, m_sRotQuat.z, m_sRotQuat.w);
        m_pcRigidBody->setPositionAndRotation(position, rotation);
    }
}

void clsRigidBodyGimmickObj::checkSetEditorCollision()
{
    if (m_pcRigidBody != 0) {
        hkAllCdBodyPairCollector cCollecter;

        hkSimpleShapePhantom* pcPhantom = new (HK_MEMORY_CLASS_PHANTOM)
            hkSimpleShapePhantom(m_pcRigidBody->m_collidable.m_shape,
                                 m_pcRigidBody->m_motion.m_motionState.m_transform,
                                 0x00e10020);

        clsHavok::GS()->m_pcWorld->addPhantom(pcPhantom);
        pcPhantom->getPenetrations(cCollecter, 0);

        if (cCollecter.getHits()->getSize() > 1) {
            nnSetPrintColor(0xe01414ff);
            nnPrint(30, 20, "Hit Collision !!");
            nnSetPrintColor(0xffffffff);
        }

        clsHavok::GS()->m_pcWorld->removePhantom(pcPhantom);
        pcPhantom->removeReference();
    }
}

void clsRigidBodyGimmickObj::drawCollision()
{
    if (clsDebug::GS()->m_sDrawCollision.u8DrawGimmick != 0 && m_pcRigidBody != 0) {
        hkRigidBodyCinfo cInfo;
        m_pcRigidBody->getCinfo(cInfo);
        clsHavok::GS()->drawShape(clsTaskManager::GS()->getCurViewNo(),
                                  cInfo.m_shape,
                                  m_pcRigidBody->m_motion.m_motionState.m_transform,
                                  0xff);
    }
}
