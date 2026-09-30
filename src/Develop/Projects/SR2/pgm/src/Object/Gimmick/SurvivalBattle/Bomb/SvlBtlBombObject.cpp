#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/Bomb/SvlBtlBombObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/Debug.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOProfile.hpp"
#include "usr/local/sce/ee/gcc/ee/lib/libm/sf_sin.h"
#include "usr/local/cri/mwlib/ee/lib/cri_libs.h"
#include "Develop/Projects/SR2/pgm/src/Object/Clipper.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/GimmickCommon.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/nn/NNUtil_PS2.hpp"
#include "usr/local/sega/nn/src/Node/nnnodestatuslist.h"
#include "usr/local/sega/nn/src/Node/nncalcmatrixpalette.h"
#include "Develop/Projects/SR2/pgm/src/Effect/Particle/ParticleLayer.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/GlobalData.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/Game.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/SurvivalBattleRace.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/Bomb/SvlBtlBombTask.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/SvlBtlExplosion.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Key/PlayerKey.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_CRI/PS2Cri.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/nn/NNUtil.hpp"

NNS_VECTORFAST clsSvlBtlBomb_Object::t_osOffsetPosVecFastTable = {0.0f, 0.0f, -1.5f, 1.0f};
f32 clsSvlBtlBomb_Object::t_f32SphereRadius = 1.0f;
const f32 clsSvlBtlBomb_Object::t_of32ClipSqDist = 40000.0f * clsGimmickCommon::t_of32ClipDistRate;
f32 t_of32GCtrlSpeed;
f32 t_of32TouchRadius;
f32 clsSvlBtlBomb_Object::t_of32LimitFrame = 600.0f;
f32 t_of32GCtrlFrmae;
f32 t_of32HormingSpeed;
f32 tof32LockOnRange;
f32 t_of32LockOnDorPro;

namespace {

// RECONSTRUCTED: shared player-rotation helper.
inline void getBombPlayerRotation(s32 s32PlayerNo, NNS_QUATERNION* psRotation)
{
    clsPlayerTask* pcPlayer = nspGlobal::sTask.apcPlayer[s32PlayerNo];
    clsGravityActionManager* pcGravity = pcPlayer->getGravityActionManagerRef();
    if (pcGravity->m_eType == clsGravityActionManager::TYPE_CTRL_SLIDE) {
        static_cast<clsGravityControl*>(pcGravity->getAction(clsGravityActionManager::ACTION_CTRL))
            ->calcRotateQuaternion(psRotation);
    } else {
        nnCopyQuaternion(psRotation, pcPlayer->getVelocityQuatPtr());
    }
}

// RECONSTRUCTED: shared camera-shake helper.
inline void quakeAllPlayer()
{
    for (s32 i = 0; i < nspGlobal::sTask.pcBaseRace->getUserNum(); ++i) {
        clsPlayerTask* pcPlayer = nspGlobal::sTask.apcPlayer[i];
        pcPlayer->quakeCamera(5, 50.0f);
        pcPlayer->getKeyRef()->requestRumble(5);
    }
}

} // namespace

clsSvlBtlBomb_Object::clsSvlBtlBomb_Object()
    : m_eMode(MODE__READY), m_s32PlayerNo(-1), m_s32AttackerNo(-1), m_s32LockOnNo(-1),
      m_f32FrameCount(0.0f), m_f32LimitFrame(0.0f), m_f32FormingFrame(0.0f), m_f32SeBlingFrame(0.0f)
{
}

clsSvlBtlBomb_Object::~clsSvlBtlBomb_Object()
{
}

void clsSvlBtlBomb_Object::draw(NNS_OBJECT* psObject,
                                NNS_MATRIX*,
                                u32*,
                                const NNS_MATRIX* psViewMtx,
                                NNS_MATRIX* psWorldMtx,
                                u32 u32ViewNo)
{
    if (m_cBreakControl.isDraw() && m_eMode != MODE__READY && m_eMode != MODE__BLAST) {
        nnMakeQuaternionMatrix(psWorldMtx, &m_sRotQuat);
        nnCopyVectorFastMatrixTranslation(psWorldMtx, &m_sPosVecFast);
        nnScaleMatrix(psWorldMtx, psWorldMtx, 0.3f, 0.3f, 0.3f);
        m_enClipRet = clsClipper::GS()->check(
            u32ViewNo, *psObject, *psWorldMtx, m_u8PortalNo, t_of32ClipSqDist, NULL);
        if (m_enClipRet >= OUT_VISIBLE) {
            return;
        }
        NNS_MATRIX* psMtxPal;
        u32* pu32NodeStatus;
        nspNnUtil::GetMultiDrawBuffer(psObject, &psMtxPal, &pu32NodeStatus);
        NNS_MATRIX sMtx;
        nnMultiplyMatrix(&sMtx, psViewMtx, psWorldMtx);
        nnSetUpNodeStatusList(pu32NodeStatus, psObject->nNode, 0);
        nnCalcMatrixPalette(psMtxPal,
                            pu32NodeStatus,
                            psObject,
                            &sMtx,
                            &nspNnUtil::tsNnMtxStack,
                            GetDrawNodeStatus());
    }
    drawCollision();
}

void clsSvlBtlBomb_Object::charge()
{
    m_eMode = MODE__CHARGE;
    m_s32LockOnNo = -1;
}

void clsSvlBtlBomb_Object::shoot()
{
    NNS_VECTORFAST sDirVecFast;
    NNS_VECTORFAST sSpeedVecFast;
    NNS_MATRIX sRotMtx;

    lockon();

    m_s32AttackerNo = m_s32PlayerNo;

    clsSvlBtlBomb_Task::GS()->requestDeleteLockOnTargetEffect(m_s32PlayerNo);

    if (m_s32LockOnNo < 0 || !clsSvlBtlBomb_Task::GS()->isGlopBomb(m_s32LockOnNo)) {
        m_eMode = MODE__SHOOT;
        m_f32FrameCount = 5.0f;

        clsSvlBtlBomb_Task::GS()->m_asPlayerData[m_s32PlayerNo].m_pcBombObject = NULL;

        clsGimmickRigidBody* pcRigidBody = m_pcRigidBody;
        pcRigidBody->setMotionType(hkMotion::MOTION_DYNAMIC,
                                   HK_ENTITY_ACTIVATION_DO_ACTIVATE,
                                   HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);
        pcRigidBody->setPositionRotate(&m_sPosVecFast, &m_sRotQuat);

        hkVector4 cZero;
        cZero.setZero4();
        pcRigidBody->setLinearVelocity(cZero);

        nnSetUpVectorFast(&sSpeedVecFast, 0.0f, 0.0f, 0.9259259f);
        nnMakeQuaternionMatrix(&sRotMtx, &m_sRotQuat);
        nnTransformVectorFast(&sDirVecFast, &sRotMtx, &sSpeedVecFast);
        pcRigidBody->applyForceFrameSpeedVecFast(&sDirVecFast);

        pcRigidBody->setCollisionFilter(clsCollisionFilter::FILTER_GROUND,
                                        clsCollisionFilter::FULL_MASK);
    } else {
        m_eMode = MODE__HORMING;

        clsSvlBtlBomb_Task::GS()->glop(m_s32AttackerNo, m_s32LockOnNo);
        m_s32PlayerNo = m_s32LockOnNo;

        m_f32FormingFrame = m_f32FrameCount =
            nnDistanceVectorFast(&nspGlobal::sTask.apcPlayer[m_s32AttackerNo]->m_sPosVecFast[0],
                                 &nspGlobal::sTask.apcPlayer[m_s32LockOnNo]->m_sPosVecFast[0]) /
            0.9259259f;
    }
}

void clsSvlBtlBomb_Object::lockon()
{
    NNS_VECTORFAST sDirVecFast;
    NNS_VECTORFAST sSubVecFast;
    NNS_VECTORFAST sNormVecFast;
    NNS_MATRIX sRotMtx;
    f32 f32MinDist = 10000.0f;

    nnMakeQuaternionMatrix(&sRotMtx, &m_sRotQuat);
    nnTransformVectorFast(&sDirVecFast, &sRotMtx, &nspNnUtil::tosZVecFast);

    m_s32LockOnNo = -1;
    for (s32 i = 0; i < nspGlobal::sTask.pcBaseRace->getPlayerNum(); ++i) {
        if (i != m_s32PlayerNo) {
            clsPlayerTask* pcPlayer = nspGlobal::sTask.apcPlayer[i];
            if (pcPlayer->m_eMoveFlag != MOVE_FLAG_NULL &&
                clsSvlBtlBomb_Task::GS()->isGlopBomb(pcPlayer->m_ePlayerNo))
            {
                nnSubtractVectorFast(&sSubVecFast, &pcPlayer->m_sPosVecFast[0], &m_sPosVecFast);
                nnNormalizeVectorFast(&sNormVecFast, &sSubVecFast);
                if (nnDotProductVectorFast(&sDirVecFast, &sNormVecFast) > 0.5f) {
                    f32 f32Dist = nnLengthSqVectorFast(&sSubVecFast);
                    if (f32Dist < f32MinDist &&
                        clsSvlBtlBomb_Task::GS()->isGlopBomb(pcPlayer->m_ePlayerNo))
                    {
                        f32MinDist = f32Dist;
                        m_s32LockOnNo = i;
                    }
                }
            }
        }
    }

    clsSvlBtlBomb_Task::GS()->requestRegistLockOnTargetEffect(m_s32PlayerNo, m_s32LockOnNo);
}

void clsSvlBtlBomb_Object::reset()
{
    clsRigidBodyGimmickObj::reset();
    m_eMode = MODE__READY;
    m_f32LimitFrame = 0.0f;
    m_pcRigidBody->setCollisionFilter(clsCollisionFilter::CLEAR_MASK,
                                      clsCollisionFilter::FULL_MASK);
    m_pcRigidBody->setFlag(1, 1);
    m_s32PlayerNo = -1;
    m_s32AttackerNo = -1;
    m_s32LockOnNo = -1;
}

void clsSvlBtlBomb_Object::main()
{
    if (clsOOProfile::GS()->m_bRunning) {
        clsOOProfile::GS()->begin("Bomb Exe");
    }
    clsPlayerTask* pcPlayer = nspGlobal::sTask.apcPlayer[m_s32PlayerNo];
    clsGimmickRigidBody* pcRigidBody = m_pcRigidBody;
    switch (m_eMode) {
    case MODE__READY:
        break;
    case MODE__WAIT: {
        m_f32FrameCount += clsPfSystem::GS()->getFrameRateAdd();
        NNS_QUATERNION sRotation;
        getBombPlayerRotation(m_s32PlayerNo, &sRotation);
        nnCopyQuaternion(&m_sRotQuat, &sRotation);
        NNS_VECTORFAST sOffset;
        nnSetUpVectorFast(&sOffset, 0.0f, 0.15f * sinf(0.052359879f * m_f32FrameCount), 0.0f);
        NNS_MATRIX sMtx;
        nnMakeQuaternionMatrix(&sMtx, &m_sRotQuat);
        nnCopyVectorFastMatrixTranslation(&sMtx, &pcPlayer->m_sPosVecFast[0]);
        NNS_VECTORFAST sPosition;
        nnAddVectorFast(&sPosition, &sOffset, &t_osOffsetPosVecFastTable);
        nnTransformVectorFast(&m_sPosVecFast, &sMtx, &sPosition);
        break;
    }
    case MODE__CHARGE: {
        m_f32FrameCount += clsPfSystem::GS()->getFrameRateAdd();
        lockon();
        NNS_QUATERNION sRotation;
        getBombPlayerRotation(m_s32PlayerNo, &sRotation);
        nnCopyQuaternion(&m_sRotQuat, &sRotation);
        NNS_VECTORFAST sOffset;
        nnSetUpVectorFast(&sOffset, 0.0f, 0.15f * sinf(0.052359879f * m_f32FrameCount), 0.0f);
        NNS_MATRIX sMtx;
        nnMakeQuaternionMatrix(&sMtx, &m_sRotQuat);
        nnCopyVectorFastMatrixTranslation(&sMtx, &pcPlayer->m_sPosVecFast[0]);
        NNS_VECTORFAST sPosition;
        nnAddVectorFast(&sPosition, &sOffset, &t_osOffsetPosVecFastTable);
        nnTransformVectorFast(&m_sPosVecFast, &sMtx, &sPosition);
        if (pcPlayer->getGravityActionManagerRef()->getActionType() ==
            clsGravityActionManager::ACTION_NULL)
        {
            clsSvlBtlBomb_Task::GS()->requestDeleteLockOnTargetEffect(m_s32PlayerNo);
            m_eMode = MODE__WAIT;
        }
        break;
    }
    case MODE__SHOOT:
        if (m_f32FrameCount > 0.0f) {
            m_f32FrameCount -= clsPfSystem::GS()->getFrameRateAdd();
            if (m_f32FrameCount <= 0.0f) {
                m_f32FrameCount = 0.0f;
                pcRigidBody->setCollisionFilter(
                    clsCollisionFilter::FILTER_GROUND | clsCollisionFilter::TYPE_PLAYER |
                        clsCollisionFilter::TYPE_GIMMICK | clsCollisionFilter::TYPE_GIMMICK_CLOG,
                    clsCollisionFilter::FULL_MASK);
                pcRigidBody->setFlag(1, 0);
            }
        }
        pcRigidBody->getPositionRotate(&m_sPosVecFast, &m_sRotQuat);
        break;
    case MODE__HORMING: {
        m_f32FrameCount -= clsPfSystem::GS()->getFrameRateAdd();
        pcPlayer = nspGlobal::sTask.apcPlayer[m_s32LockOnNo];
        NNS_MATRIX sMtx;
        nnMakeQuaternionMatrix(&sMtx, pcPlayer->getVelocityQuatPtr());
        nnCopyVectorFastMatrixTranslation(&sMtx, &pcPlayer->m_sPosVecFast[0]);
        NNS_VECTORFAST sTarget;
        nnTransformVectorFast(&sTarget, &sMtx, &t_osOffsetPosVecFastTable);
        NNS_VECTORFAST sDistance;
        nnSubtractVectorFast(&sDistance, &m_sPosVecFast, &sTarget);
        nnScaleAddVectorFast(&m_sPosVecFast,
                             &pcPlayer->m_sPosVecFast[0],
                             &sDistance,
                             m_f32FrameCount / m_f32FormingFrame);
        if (m_f32FrameCount < 0.0f) {
            m_eMode = MODE__WAIT;
        }
        break;
    }
    case MODE__BLAST:
        m_f32FrameCount -= clsPfSystem::GS()->getFrameRateAdd();
        if (m_f32FrameCount <= 0.0f) {
            reset();
        }
        break;
    }
    if (m_f32LimitFrame > 0.0f) {
        m_f32LimitFrame -= clsPfSystem::GS()->getFrameRateAdd();
        m_f32SeBlingFrame -= clsPfSystem::GS()->getFrameRateAdd();
        if (m_f32LimitFrame < 120.0f) {
            if (m_f32SeBlingFrame <= 0.0f) {
                SNDF_SendSeqRequest(0x81AA9);
                m_f32SeBlingFrame = 5.0f;
            }
        } else if (m_f32SeBlingFrame <= 0.0f) {
            SNDF_SendSeqRequest(0x81AA9);
            m_f32SeBlingFrame = m_f32LimitFrame / 10.0f;
        }
        if (m_f32LimitFrame <= 0.0f) {
            m_f32LimitFrame = 0.0f;
            if (m_eMode < MODE__BLAST) {
                m_eMode = MODE__BLAST;
                requestDrawBreakEffect();
                clsSvlBtlExplosion_Task::GS()->start(&m_sPosVecFast,
                                                     nspGlobal::sTask.apcPlayer[m_s32AttackerNo],
                                                     clsSvlBtlExplosion_Object::DAMAGE_TYPE__BOMB,
                                                     10.0f,
                                                     50.0f,
                                                     50.0f);
                clsSvlBtlBomb_Task::GS()->requestDeleteLockOnTargetEffect(m_s32PlayerNo);
                clsSvlBtlBomb_Task::GS()->m_asPlayerData[m_s32PlayerNo].m_pcBombObject = NULL;
                clsPfCri::GS()->playSfSe_3D(0x101AE);
                quakeAllPlayer();
            }
        }
    }
    if (clsOOProfile::GS()->m_bRunning) {
        clsOOProfile::GS()->end("Bomb Exe");
    }
}

void clsSvlBtlBomb_Object::setData()
{
}

void clsSvlBtlBomb_Object::createData()
{
    hkRigidBodyCinfo cRigidBodyInfo;

    clsHavok* pcHavok = clsHavok::GS();

    cRigidBodyInfo.m_shape = clsSvlBtlBomb_Task::GS()->m_pcRigidShape;
    cRigidBodyInfo.m_position.set(m_sPosVecFast.x, m_sPosVecFast.y, m_sPosVecFast.z, 0.0f);
    cRigidBodyInfo.m_motionType = hkMotion::MOTION_DYNAMIC;
    cRigidBodyInfo.m_allowedPenetrationDepth = 2.0f;
    cRigidBodyInfo.m_collisionFilterInfo = 0;
    cRigidBodyInfo.m_mass = clsHavok::t_of32WeightTypeMiddle;
    cRigidBodyInfo.m_linearDamping = 0.7f;
    cRigidBodyInfo.m_friction = 1.0f;
    cRigidBodyInfo.m_restitution = 0.0f;
    cRigidBodyInfo.m_maxAngularVelocity = 6.981317f;

    clsGimmickRigidBody* pcRigidBody =
        new (HK_MEMORY_CLASS_ENTITY) clsGimmickRigidBody(cRigidBodyInfo, this);

    pcHavok->m_pcWorld->addEntity(pcRigidBody, HK_ENTITY_ACTIVATION_DO_ACTIVATE);

    pcRigidBody->setCollisionInfo(oasGroundInfo);
    pcRigidBody->setMotionType(hkMotion::MOTION_KEYFRAMED,
                               HK_ENTITY_ACTIVATION_DO_ACTIVATE,
                               HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);
    pcRigidBody->m_motion.m_motionState.m_maxLinearVelocity = 55.555553f;
    pcRigidBody->m_motion.m_motionState.m_maxAngularVelocity = 0.17453292f;
    pcRigidBody->setPositionRotate(&m_sPosVecFast, &m_sRotQuat);
    pcRigidBody->setFlag(1, 1);

    m_pcRigidBody = pcRigidBody;
    pcRigidBody->m_pcUnaryAction = new (HK_MEMORY_CLASS_ACTION) clsGimmickUnaryAction(pcRigidBody);
    clsHavok::GS()->m_pcWorld->addAction(pcRigidBody->m_pcUnaryAction);
}

void clsSvlBtlBomb_Object::destroyData()
{
    delete m_pcRigidBody;
    m_pcRigidBody = NULL;
}

void clsSvlBtlBomb_Object::contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2)
{
    if (m_eControlMode >= CTRL_MODE_BREAKING) {
        return;
    }
    if (m_eMode != MODE__SHOOT) {
        return;
    }

    m_pcContactPlayer = pParam2;
    if (clsGameMgr::GS()->getGameMode() == clsGameMgr::GAME_MODE___SURVIVAL_BATTLE) {
        static_cast<clsSurvivalBattleRace_Task*>(nspGlobal::sTask.pcBaseRace)
            ->damegeBomb(static_cast<clsPlayerTask*>(pParam2),
                         nspGlobal::sTask.apcPlayer[m_s32PlayerNo]);
    }
    m_eMode = MODE__BLAST;
    requestDrawBreakEffect();
    clsSvlBtlExplosion_Task::GS()->start(&m_sPosVecFast,
                                         nspGlobal::sTask.apcPlayer[m_s32AttackerNo],
                                         clsSvlBtlExplosion_Object::DAMAGE_TYPE__BOMB,
                                         10.0f,
                                         50.0f,
                                         50.0f);
    clsSvlBtlBomb_Task::GS()->requestDeleteLockOnTargetEffect(m_s32PlayerNo);
    clsSvlBtlBomb_Task::GS()->m_asPlayerData[m_s32PlayerNo].m_pcBombObject = NULL;
    clsPfCri::GS()->playSfSe_3D(0x101AE);
    quakeAllPlayer();
}

void clsSvlBtlBomb_Object::contactTriggerCallback(hkContactPointConfirmedEvent& rParam1)
{
    if (m_eMode < MODE__BLAST) {
        callbackContactTriggerRigidBody(rParam1);

        const hkCollidable* pcCollidable = rParam1.m_collidableB;
        const hkWorldObject* pcOwner =
            pcCollidable->m_broadPhaseHandle.m_type == 1 ? pcCollidable->getOwner() : NULL;
        m_pcContactObject = static_cast<clsObject*>(pcOwner->getUserData());
    }
}

void clsSvlBtlBomb_Object::requestDrawBreakEffect()
{
    if (!clsDebug::GS()->m_sParticle.u8CarEffect) {
        nspParticleSet::registTask(4, 0x31, &m_sPosVecFast, 2);
        nspParticleSet::registTask(4, 0x32, &m_sPosVecFast, 2);
    }
}
