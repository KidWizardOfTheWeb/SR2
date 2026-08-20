#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/MapPartsObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/Havok.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickUnaryAction.hpp"
#include "usr/local/sce/ee/gcc/ee/lib/libc/memset.h"

clsMapPartsObject::clsMapPartsObject()
{
    memset(&m_sColInfo, 0, sizeof(m_sColInfo));
}

clsMapPartsObject::~clsMapPartsObject()
{
}

void clsMapPartsObject::createBaseMapParts(hkShape* pcShape, f32 f32Weight)
{
    hkRigidBodyCinfo cRigidBodyInfo;

    cRigidBodyInfo.m_shape = pcShape;
    f32 z = m_sPosVecFast.z;
    f32 y = m_sPosVecFast.y;
    f32 x = m_sPosVecFast.x;
    cRigidBodyInfo.m_position.x = x;
    cRigidBodyInfo.m_position.w = 0.0f;
    cRigidBodyInfo.m_position.y = y;
    cRigidBodyInfo.m_position.z = z;
    cRigidBodyInfo.m_rotation =
        hkQuaternion(m_sRotQuat.x, m_sRotQuat.y, m_sRotQuat.z, m_sRotQuat.w);
    cRigidBodyInfo.m_angularDamping = 0.05f;
    cRigidBodyInfo.m_linearDamping = 0.0f;
    cRigidBodyInfo.m_friction = 0.25f;
    cRigidBodyInfo.m_allowedPenetrationDepth = 0.2f;
    cRigidBodyInfo.m_mass = f32Weight;
    if (f32Weight > clsHavok::t_of32WeightTypeGround) {
        cRigidBodyInfo.m_motionType.m_storage = hkMotion::MOTION_DYNAMIC;
    } else {
        cRigidBodyInfo.m_motionType.m_storage = hkMotion::MOTION_CHARACTER;
    }
    cRigidBodyInfo.m_collisionFilterInfo = 1;

    clsGimmickRigidBody* pcRigidBody =
        new (HK_MEMORY_CLASS_ENTITY) clsGimmickRigidBody(cRigidBodyInfo, this);
    pcRigidBody->setCollisionInfo(&m_sColInfo);
    pcRigidBody->setMotionType(hkMotion::MOTION_CHARACTER,
                               HK_ENTITY_ACTIVATION_DO_ACTIVATE,
                               HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);
    clsHavok::GS()->m_pcWorld->addEntity(pcRigidBody, HK_ENTITY_ACTIVATION_DO_ACTIVATE);

    m_pcRigidBody = pcRigidBody;
    pcRigidBody->m_pcUnaryAction = new (HK_MEMORY_CLASS_ACTION) clsGimmickUnaryAction(pcRigidBody);
    clsHavok::GS()->m_pcWorld->addAction(pcRigidBody->m_pcUnaryAction);

    m_eControlFlag = static_cast<enmControlFlag>(
        m_eControlFlag & ~(CTRL_FLAG_UPDATE_CONTACT | CTRL_FLAG_UPDATE_INTERRACTION));
}

void clsMapPartsObject::setData()
{
    clsRigidBodyGimmickObj::setData();
    m_eControlFlag = static_cast<enmControlFlag>(CTRL_FLAG_DEFAULT & ~CTRL_FLAG_UPDATE_CONTACT);
}
