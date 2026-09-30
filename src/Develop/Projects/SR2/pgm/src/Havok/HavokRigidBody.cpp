#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokMath.hpp"

namespace {
// RECONSTRUCTED: queued operation types.
enum RigidBodyQueuedOperationType {
    RIGID_BODY_OPERATION_SET_MOTION_TYPE = 4,
    RIGID_BODY_OPERATION_SET_SHAPE = 5,
};

class QueuedSetMotionTypeOperation : public hkWorldOperation::BaseOperation {
public:
    QueuedSetMotionTypeOperation(hkRigidBody* pRigidBody,
                                 hkMotion::MotionType sMotionType,
                                 hkEntityActivation sActivation,
                                 hkUpdateCollisionFilterOnEntityMode sFilterMode)
        : hkWorldOperation::BaseOperation(RIGID_BODY_OPERATION_SET_MOTION_TYPE),
          m_rigidBody(pRigidBody), m_motionType(static_cast<u8>(sMotionType)),
          m_activation(static_cast<u8>(sActivation)), m_filterMode(static_cast<u8>(sFilterMode))
    {
    }

    hkRigidBody* m_rigidBody;
    u8 m_motionType;
    u8 m_activation;
    u8 m_filterMode;
};

class QueuedSetShapeOperation : public hkWorldOperation::BaseOperation {
public:
    QueuedSetShapeOperation(hkRigidBody* pRigidBody, const hkShape* pShape)
        : hkWorldOperation::BaseOperation(RIGID_BODY_OPERATION_SET_SHAPE), m_rigidBody(pRigidBody),
          m_shape(pShape)
    {
    }

    hkRigidBody* m_rigidBody;
    const hkShape* m_shape;
};
} // namespace

static void estimateAllowedPenetrationDepth(hkCollidable* pCollidable,
                                            f32,
                                            const hkVector4& rCachedShapeInfo)
{
    const f32 z = rCachedShapeInfo.z;
    f32 minExtent =
        rCachedShapeInfo.x < rCachedShapeInfo.y ? rCachedShapeInfo.x : rCachedShapeInfo.y;
    minExtent = minExtent < z ? minExtent : z;

    if (minExtent < 0.5f) {
        pCollidable->m_allowedPenetrationDepth = 0.2f * minExtent;
    } else {
        pCollidable->m_allowedPenetrationDepth = 0.1f;
    }
}

void hkRigidBody::updateCachedShapeInfo(const hkShape* pParam1, hkVector4& rParam2)
{
    hkAabb aabb;
    pParam1->getAabbImpl(hkTransform::getIdentity(), 0.0f, aabb);

    rParam2.setSub4(aabb.m_max, aabb.m_min);
    // MATCHING_WORKAROUND: Preserve square-root scheduling.
    f32 extentLength =
        hkMath::sqrt(rParam2.x * rParam2.x + rParam2.y * rParam2.y + rParam2.z * rParam2.z);
    f32 halfExtentLength = 0.5f;
    halfExtentLength *= extentLength;

    hkVector4 center;
    center.setAdd4(aabb.m_min, aabb.m_max);
    center.mul4(0.5f);
    center.sub4(m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal);
    f32 centerDistance =
        hkMath::sqrt(center.x * center.x + center.y * center.y + center.z * center.z);
    m_motion.m_motionState.m_objectRadius = halfExtentLength + centerDistance;
}

void hkRigidBody::createDynamicRigidMotion(hkMotion::MotionType sParam1,
                                           const hkVector4& rParam2,
                                           const hkQuaternion& rParam3,
                                           f32 f32Param4,
                                           const hkMatrix3& rParam5,
                                           const hkVector4& rParam6,
                                           f32 f32Param7,
                                           f32 f32Param8,
                                           hkMaxSizeMotion* pParam9)
{
    hkMotion* pMotion = pParam9;

    switch (sParam1) {
    case hkMotion::MOTION_SPHERE_INERTIA:
        pMotion = new (pParam9) hkSphereMotion(rParam2, rParam3);
        break;
    case hkMotion::MOTION_BOX_INERTIA:
        pMotion = new (pParam9) hkBoxMotion(rParam2, rParam3);
        break;
    case hkMotion::MOTION_THIN_BOX_INERTIA:
        pMotion = new (pParam9) hkThinBoxMotion(rParam2, rParam3);
        break;
    case hkMotion::MOTION_SPHERE_STABILIZED:
        pMotion = new (pParam9) hkStabilizedSphereMotion(rParam2, rParam3);
        break;
    case hkMotion::MOTION_BOX_STABILIZED:
        pMotion = new (pParam9) hkStabilizedBoxMotion(rParam2, rParam3);
        break;
    case hkMotion::MOTION_DYNAMIC: {
        f32 inertia0 = rParam5.m_col0.x;
        f32 inertia1 = rParam5.m_col1.y;
        f32 inertia2 = rParam5.m_col2.z;

        f32 maxInertia;
        if (inertia1 > inertia2) {
            maxInertia = inertia1;
        } else {
            maxInertia = inertia2;
        }
        if (inertia0 > maxInertia) {
            maxInertia = inertia0;
        }

        f32 minInertia;
        if (inertia1 < inertia2) {
            minInertia = inertia1;
        } else {
            minInertia = inertia2;
        }
        minInertia = inertia0 < minInertia ? inertia0 : minInertia;

        if (minInertia > 0.8f * maxInertia) {
            pMotion = new (pParam9) hkSphereMotion(rParam2, rParam3);
        } else {
            pMotion = new (pParam9) hkBoxMotion(rParam2, rParam3);
        }
        break;
    }
    case hkMotion::MOTION_KEYFRAMED:
        f32Param7 = 1000000.0f;
        f32Param8 = 1000000.0f;
        pMotion = new (pParam9) hkKeyframedRigidMotion(rParam2, rParam3);
        break;
    case hkMotion::MOTION_INVALID:
    case hkMotion::MOTION_FIXED:
    default:
        pMotion = new (pParam9) hkFixedRigidMotion(rParam2, rParam3);
        break;
    }

    if (sParam1 != hkMotion::MOTION_KEYFRAMED) {
        pMotion->setInertiaLocal(rParam5);
        pMotion->setCenterOfMassInLocal(rParam6);
        pMotion->setMass(f32Param4);
    }

    pMotion->m_motionState.m_deactivationCounter = 20;
    pMotion->m_motionState.m_maxLinearVelocity = f32Param7;
    pMotion->m_motionState.m_maxAngularVelocity = f32Param8;
}

hkRigidBody::hkRigidBody(const hkRigidBodyCinfo& rParam1) : hkEntity(rParam1.m_shape)
{
    m_material.m_responseType.m_storage = rParam1.m_collisionResponse.m_storage;
    m_processContactCallbackDelay = rParam1.m_processContactCallbackDelay;
    m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = rParam1.m_collisionFilterInfo;

    hkMotion::MotionType motionType =
        static_cast<hkMotion::MotionType>(rParam1.m_motionType.m_storage);
    hkBool isFixedMotion = motionType == hkMotion::MOTION_FIXED;
    if (isFixedMotion) {
        hkMotion* pMotion =
            new (&m_motion) hkFixedRigidMotion(rParam1.m_position, rParam1.m_rotation);
        pMotion->m_motionState.m_maxLinearVelocity = rParam1.m_maxLinearVelocity;
        pMotion->m_motionState.m_maxAngularVelocity = rParam1.m_maxAngularVelocity;
        pMotion->setDeactivationClass(1);
        m_collidable.m_motion = &m_motion.m_motionState;

        if (rParam1.m_allowedPenetrationDepth <= 0.0f) {
            static const f32 HK_REAL_MAX = 3.40282e38f;
            m_collidable.m_allowedPenetrationDepth = HK_REAL_MAX;
        } else {
            m_collidable.m_allowedPenetrationDepth = rParam1.m_allowedPenetrationDepth;
        }
    } else {
        createDynamicRigidMotion(motionType,
                                 rParam1.m_position,
                                 rParam1.m_rotation,
                                 rParam1.m_mass,
                                 rParam1.m_inertiaTensor,
                                 rParam1.m_centerOfMass,
                                 rParam1.m_maxLinearVelocity,
                                 rParam1.m_maxAngularVelocity,
                                 &m_motion);
        m_motion.setDeactivationClass(rParam1.m_solverDeactivation.m_storage);
        activate();
        m_motion.setLinearVelocity(rParam1.m_linearVelocity);
        activate();
        m_motion.setAngularVelocity(rParam1.m_angularVelocity);
        m_collidable.m_motion = &m_motion.m_motionState;
        setDeactivator(static_cast<hkRigidBodyDeactivator::DeactivatorType>(
            rParam1.m_rigidBodyDeactivatorType.m_storage));
        m_collidable.m_allowedPenetrationDepth = rParam1.m_allowedPenetrationDepth;
    }

    m_motion.m_motionState.m_linearDamping = rParam1.m_linearDamping;
    m_motion.m_motionState.m_angularDamping = rParam1.m_angularDamping;

    if (m_collidable.m_shape != NULL) {
        hkVector4 cachedShapeInfo;
        updateCachedShapeInfo(m_collidable.m_shape, cachedShapeInfo);
        if (m_collidable.m_allowedPenetrationDepth <= 0.0f) {
            estimateAllowedPenetrationDepth(
                &m_collidable, m_collidable.m_allowedPenetrationDepth, cachedShapeInfo);
        }
    }

    hkBool hasQualityType = rParam1.m_qualityType.m_storage != 0;
    if (hasQualityType) {
        m_collidable.m_broadPhaseHandle.m_objectQualityType = rParam1.m_qualityType.m_storage;
    } else {
        hkBool isFixedQuality = m_motion.isFixed();
        if (isFixedQuality) {
            m_collidable.m_broadPhaseHandle.m_objectQualityType = 1;
        } else {
            hkBool isKeyframedQuality =
                static_cast<hkMotion::MotionType>(rParam1.m_motionType.m_storage) ==
                hkMotion::MOTION_KEYFRAMED;
            if (isKeyframedQuality) {
                m_collidable.m_broadPhaseHandle.m_objectQualityType = 2;
            } else {
                m_collidable.m_broadPhaseHandle.m_objectQualityType = 3;
            }
        }
    }

    m_autoRemoveLevel = rParam1.m_autoRemoveLevel;
    if (rParam1.m_forceCollideOntoPpu) {
        m_collidable.m_forceCollideOntoPpu |= 1;
    }
    m_material.m_friction = rParam1.m_friction;
    m_material.m_restitution = rParam1.m_restitution;
}

hkRigidBody::~hkRigidBody()
{
}

hkMotionState* hkRigidBody::getMotionState()
{
    return &m_motion.m_motionState;
}

hkRigidBody* hkRigidBody::clone() const
{
    hkRigidBodyCinfo cinfo;
    getCinfo(cinfo);

    hkRigidBody* pRigidBody = new hkRigidBody(cinfo);
    hkString::memCpy16(&pRigidBody->m_motion, &m_motion, sizeof(m_motion) / 16);

    if (m_motion.m_savedMotion != NULL) {
        pRigidBody->m_motion.m_savedMotion = new hkMaxSizeMotion;
        hkString::memCpy16(pRigidBody->m_motion.m_savedMotion,
                           m_motion.m_savedMotion,
                           sizeof(*m_motion.m_savedMotion) / 16);
    }

    pRigidBody->m_collidable.m_motion = pRigidBody->getMotionState();
    pRigidBody->m_properties = m_properties;
    pRigidBody->m_name = m_name;
    pRigidBody->m_userData = m_userData;
    return pRigidBody;
}

bool hkRigidBody::setShape(const hkShape* pParam1)
{
    if (m_world != NULL && m_world->m_criticalOperationsLockCount != 0) {
        QueuedSetShapeOperation operation(this, pParam1);
        m_world->queueOperation(operation);
        return false;
    }

    if (m_world != NULL) {
        ++m_world->m_criticalOperationsLockCount;
        hkWorldOperationUtil::removeEntityBP(m_world, this);
    }

    const hkShape* pOldShape = m_collidable.m_shape;
    m_collidable.m_shape = pParam1;
    pParam1->addReference();
    if (pOldShape != NULL) {
        pOldShape->removeReference();
    }

    hkVector4 vCachedShapeInfo;
    updateCachedShapeInfo(pParam1, vCachedShapeInfo);

    static const f32 HK_REAL_MAX = 3.40282e38f;
    if (pOldShape != NULL && m_collidable.m_allowedPenetrationDepth != HK_REAL_MAX) {
        m_collidable.m_allowedPenetrationDepth = -1.0f;
    }
    const f32& rf32AllowedPenetrationDepth = m_collidable.m_allowedPenetrationDepth;
    if (rf32AllowedPenetrationDepth <= 0.0f) {
        estimateAllowedPenetrationDepth(
            &m_collidable, m_collidable.m_allowedPenetrationDepth, vCachedShapeInfo);
    }

    if (m_world != NULL) {
        hkWorldCallbackUtil::fireEntityShapeSet(m_world, this);
    }
    hkEntityCallbackUtil::fireEntityShapeSet(this);

    if (m_world != NULL) {
        hkWorldOperationUtil::addEntityBP(m_world, this);
        hkWorld* pWorld = m_world;
        if (--pWorld->m_criticalOperationsLockCount == 0 && pWorld->m_pendingOperationsCount != 0 &&
            !pWorld->m_blockExecutingPendingOperations)
        {
            pWorld->internal_executePendingOperations();
        }
    }

    return true;
}

void hkRigidBody::getCinfo(hkRigidBodyCinfo& rParam1) const
{
    rParam1.m_forceCollideOntoPpu = hkBool((m_collidable.m_forceCollideOntoPpu & 1) != 0);
    rParam1.m_autoRemoveLevel = m_autoRemoveLevel;
    rParam1.m_processContactCallbackDelay = m_processContactCallbackDelay;

    rParam1.m_rigidBodyDeactivatorType =
        m_deactivator != NULL ? static_cast<hkRigidBodyDeactivator::DeactivatorType>(
                                    static_cast<hkRigidBodyDeactivator*>(m_deactivator)
                                        ->getRigidBodyDeactivatorType())
                              : hkRigidBodyDeactivator::DEACTIVATOR_NEVER;

    rParam1.m_friction = m_material.m_friction;
    rParam1.m_collisionResponse.m_storage = m_material.m_responseType.m_storage;
    rParam1.m_restitution = m_material.m_restitution;
    rParam1.m_linearDamping = m_motion.m_motionState.m_linearDamping;
    rParam1.m_angularDamping = m_motion.m_motionState.m_angularDamping;
    rParam1.m_linearVelocity = m_motion.m_linearVelocity;
    rParam1.m_angularVelocity = m_motion.m_angularVelocity;
    rParam1.m_mass = m_motion.getMass();
    m_motion.getInertiaLocal(rParam1.m_inertiaTensor);
    rParam1.m_motionType =
        static_cast<hkMotion::MotionType>(static_cast<u8>(m_motion.m_type.m_storage));
    rParam1.m_solverDeactivation.m_storage =
        static_cast<u8>(m_motion.m_motionState.m_deactivationClass);
    rParam1.m_maxLinearVelocity = m_motion.m_motionState.m_maxLinearVelocity;
    rParam1.m_maxAngularVelocity = m_motion.m_motionState.m_maxAngularVelocity;
    rParam1.m_position = m_motion.m_motionState.m_transform.m_translation;
    rParam1.m_rotation = m_motion.m_motionState.m_sweptTransform.m_rotation1;
    rParam1.m_centerOfMass = m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal;
    rParam1.m_shape = m_collidable.m_shape;
    rParam1.m_collisionFilterInfo = m_collidable.m_broadPhaseHandle.m_collisionFilterInfo;
    rParam1.m_allowedPenetrationDepth = m_collidable.m_allowedPenetrationDepth;
    rParam1.m_qualityType.m_storage =
        static_cast<u8>(m_collidable.m_broadPhaseHandle.m_objectQualityType);
}

void hkRigidBody::setDeactivator(hkRigidBodyDeactivator* pParam1)
{
    hkEntity::setDeactivator(pParam1);
}

void hkRigidBody::setMotionType(hkMotion::MotionType sParam1,
                                hkEntityActivation sParam2,
                                hkUpdateCollisionFilterOnEntityMode sParam3)
{
    hkWorld* pWorld = m_world;
    if (pWorld != NULL && pWorld->m_criticalOperationsLockCount != 0) {
        QueuedSetMotionTypeOperation operation(this, sParam1, sParam2, sParam3);
        pWorld->queueOperation(operation);
        return;
    }

    hkWorldOperationUtil::setRigidBodyMotionType(this, sParam1, sParam2, sParam3);
}

void hkRigidBody::setCenterOfMassLocal(const hkVector4& rParam1)
{
    m_motion.setCenterOfMassInLocal(rParam1);
    hkVector4 vCachedShapeInfo;
    updateCachedShapeInfo(m_collidable.m_shape, vCachedShapeInfo);
}

void hkRigidBody::setDeactivator(hkRigidBodyDeactivator::DeactivatorType sParam1)
{
    if (m_deactivator != NULL &&
        static_cast<hkRigidBodyDeactivator*>(m_deactivator)->getRigidBodyDeactivatorType() ==
            sParam1)
    {
        return;
    }

    switch (sParam1) {
    case hkRigidBodyDeactivator::DEACTIVATOR_NEVER:
        setDeactivator(&hkFakeRigidBodyDeactivator::m_fakeRigidBodyDeactivator);
        m_motion.m_deactivationIntegrateCounter = 0xff;
        m_motion.m_deactivationNumInactiveFrames[0] = 0;
        m_motion.m_deactivationNumInactiveFrames[1] = 0;
        break;
    case hkRigidBodyDeactivator::DEACTIVATOR_SPATIAL: {
        hkSpatialRigidBodyDeactivator* pDeactivator = static_cast<hkSpatialRigidBodyDeactivator*>(
            hkSpatialRigidBodyDeactivator::operator new(sizeof(hkSpatialRigidBodyDeactivator)));
        ::new (pDeactivator) hkSpatialRigidBodyDeactivator;
        setDeactivator(pDeactivator);
        m_motion.m_deactivationIntegrateCounter = static_cast<u8>(m_uid & 0xf);
        pDeactivator->removeReference();
        break;
    }
    default:
        break;
    }
}

void hkRigidBody::updateBroadphaseAndResetCollisionInformationOfWarpedBody(hkEntity* pParam1)
{
    hkRigidBody* pRigidBody = static_cast<hkRigidBody*>(pParam1);
    hkWorld* pWorld = pRigidBody->m_world;
    if (pWorld == NULL) {
        return;
    }

    if (pWorld->areCriticalOperationsLocked()) {
        // RECONSTRUCTED: operation name.
        struct QueuedOperation : public hkWorldOperation::BaseOperation {
            QueuedOperation(hkEntity* pEntity)
                : hkWorldOperation::BaseOperation(21), m_entity(pEntity)
            {
            }
            hkEntity* m_entity;
        } operation(pParam1);
        pWorld->queueOperation(operation);
        return;
    }

    ++pWorld->m_criticalOperationsLockCount;

    hkEntity* pEntities[1] = {NULL};
    pEntities[0] = pParam1;
    pWorld->m_simulation->resetCollisionInformationForEntities(pEntities, 1, pWorld, false);

    if (pRigidBody->m_collidable.m_shape != NULL) {
        hkSimulation::collideEntitiesBroadPhaseDiscrete(pEntities, 1, pWorld);
    }

    if (!pRigidBody->isActive()) {
        if (pWorld->m_shouldActivateOnRigidBodyTransformChange) {
            if (!pRigidBody->m_motion.isFixed()) {
                pRigidBody->activate();
            }
        }
        hkWorldCallbackUtil::fireInactiveEntityMoved(pWorld, pParam1);
    }

    --pWorld->m_criticalOperationsLockCount;
    if (pWorld->m_criticalOperationsLockCount == 0 && pWorld->m_pendingOperationsCount != 0 &&
        !pWorld->m_blockExecutingPendingOperations)
    {
        pWorld->internal_executePendingOperations();
    }
}

void hkRigidBody::setPosition(const hkVector4& rParam1)
{
    m_motion.setPosition(rParam1);
    updateBroadphaseAndResetCollisionInformationOfWarpedBody(this);
}

void hkRigidBody::setRotation(const hkQuaternion& rParam1)
{
    m_motion.setRotation(rParam1);
    updateBroadphaseAndResetCollisionInformationOfWarpedBody(this);
}

void hkRigidBody::setPositionAndRotation(const hkVector4& rParam1, const hkQuaternion& rParam2)
{
    m_motion.setPositionAndRotation(rParam1, rParam2);
    updateBroadphaseAndResetCollisionInformationOfWarpedBody(this);
}

void hkRigidBody::setTransform(const hkTransform& rParam1)
{
    m_motion.setTransform(rParam1);
    updateBroadphaseAndResetCollisionInformationOfWarpedBody(this);
}

void hkRigidBody::setMass(f32 f32Param1)
{
    m_motion.setMass(f32Param1);
}

const hkQuaternion& hkRigidBody::getRotation() const
{
    static hkQuaternion sRotation;
    return sRotation;
}

hkRigidBodyCinfo::hkRigidBodyCinfo()
{
    m_position.x = m_position.y = m_position.z = m_position.w = 0.0f;

    m_rotation.m_vec.x = 0.0f;
    m_rotation.m_vec.y = 0.0f;
    m_rotation.m_vec.z = 0.0f;
    m_rotation.m_vec.w = 1.0f;

    m_linearVelocity.x = m_linearVelocity.y = m_linearVelocity.z = m_linearVelocity.w = 0.0f;
    m_angularVelocity.x = m_angularVelocity.y = m_angularVelocity.z = m_angularVelocity.w = 0.0f;

    m_inertiaTensor.m_col0.x = 0.0f;
    m_inertiaTensor.m_col0.y = 0.0f;
    m_inertiaTensor.m_col0.z = 0.0f;
    m_inertiaTensor.m_col0.w = 0.0f;
    m_inertiaTensor.m_col1.x = 0.0f;
    m_inertiaTensor.m_col1.y = 0.0f;
    m_inertiaTensor.m_col1.z = 0.0f;
    m_inertiaTensor.m_col1.w = 0.0f;
    m_inertiaTensor.m_col2.x = 0.0f;
    m_inertiaTensor.m_col2.y = 0.0f;
    m_inertiaTensor.m_col2.z = 0.0f;
    m_inertiaTensor.m_col2.w = 0.0f;
    m_inertiaTensor.m_col0.x = 1.0f;
    m_inertiaTensor.m_col1.y = 1.0f;
    m_inertiaTensor.m_col2.z = 1.0f;

    m_centerOfMass.x = m_centerOfMass.y = m_centerOfMass.z = m_centerOfMass.w = 0.0f;

    m_mass = 1.0f;
    m_linearDamping = 0.0f;
    m_angularDamping = 0.05f;
    m_friction = 0.5f;
    m_restitution = 0.4f;
    m_maxLinearVelocity = 200.0f;
    m_maxAngularVelocity = 200.0f;
    m_allowedPenetrationDepth = -1.0f;
    m_motionType = hkMotion::MOTION_DYNAMIC;
    m_rigidBodyDeactivatorType = hkRigidBodyDeactivator::DEACTIVATOR_SPATIAL;
    m_solverDeactivation.m_storage = 2;
    m_qualityType.m_storage = 0;
    m_collisionResponse.m_storage = 1;
    m_processContactCallbackDelay = 0xffff;
    m_collisionFilterInfo = 0;
    m_shape = NULL;
    m_autoRemoveLevel = 0;
    m_forceCollideOntoPpu = hkBool(false);
}
