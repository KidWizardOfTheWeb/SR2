#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokMath.hpp"

// MATCHING_WORKAROUND: Preserve comparison operand order.
inline bool scalarNotEqual(f32 left, f32 right)
{
    return left != right;
}
inline void hkSweptTransformUtil::_stepMotionState(const hkStepInfo& stepInfo,
                                                   hkVector4& linearVelocity,
                                                   hkVector4& angularVelocity,
                                                   hkMotionState& motionState)
{
    static hkQuadReal maxVelf = {1000000.0f, 1000000.0f, 1000000.0f, 1000000.0f};

    hkVector4 linearAbsolute;
    linearAbsolute.setAbs4(linearVelocity);
    hkVector4 angularAbsolute;
    angularAbsolute.setAbs4(angularVelocity);

    const hkVector4& maximum = *reinterpret_cast<const hkVector4*>(&maxVelf);

    s32 angularRangeMask = angularAbsolute.compareLessThan4(maximum);
    s32 linearRangeMask = linearAbsolute.compareLessThan4(maximum);
    s32 validRangeMask = linearRangeMask & angularRangeMask;
    s32 angularFiniteMask = angularVelocity.compareEqual4(angularVelocity);
    s32 linearFiniteMask = linearVelocity.compareEqual4(linearVelocity);

    if ((validRangeMask & (linearFiniteMask & angularFiniteMask) & 0xe) != 0xe) {
        const hkQuadReal& identity = hkTransform::getIdentity().m_rotation.m_col0.getQuad();
        linearVelocity.x = identity.x;
        linearVelocity.y = identity.y;
        linearVelocity.z = identity.z;
        linearVelocity.w = identity.w;
        angularVelocity.x = identity.x;
        angularVelocity.y = identity.y;
        angularVelocity.z = identity.z;
        angularVelocity.w = identity.w;
    }

    motionState.m_sweptTransform.m_centerOfMass0.x = motionState.m_sweptTransform.m_centerOfMass1.x;
    motionState.m_sweptTransform.m_centerOfMass0.y = motionState.m_sweptTransform.m_centerOfMass1.y;
    motionState.m_sweptTransform.m_centerOfMass0.z = motionState.m_sweptTransform.m_centerOfMass1.z;
    motionState.m_sweptTransform.m_centerOfMass0.w = motionState.m_sweptTransform.m_centerOfMass1.w;
    motionState.m_sweptTransform.m_centerOfMass0.w = stepInfo.m_startTime.m_storage;

    const hkVector4& linearQuad = linearVelocity;
    f32 linearVelocitySq =
        linearQuad.x * linearQuad.x + linearQuad.y * linearQuad.y + linearQuad.z * linearQuad.z;
    f32 maxLinearVelocity = motionState.m_maxLinearVelocity;
    if (linearVelocitySq > maxLinearVelocity * maxLinearVelocity) {
        f32 scale = maxLinearVelocity * hkMath::sqrtInverse(linearVelocitySq);
        linearVelocity.x *= scale;
        linearVelocity.y *= scale;
        linearVelocity.z *= scale;
        linearVelocity.w *= scale;
    }

    f32 deltaTime = stepInfo.m_deltaTime.m_storage;
    motionState.m_sweptTransform.m_centerOfMass1.x += deltaTime * linearVelocity.x;
    motionState.m_sweptTransform.m_centerOfMass1.y += deltaTime * linearVelocity.y;
    motionState.m_sweptTransform.m_centerOfMass1.z += deltaTime * linearVelocity.z;
    motionState.m_sweptTransform.m_centerOfMass1.w += deltaTime * linearVelocity.w;
    motionState.m_sweptTransform.m_centerOfMass1.w = stepInfo.m_invDeltaTime.m_storage;

    hkQuadReal oldRotation;
    oldRotation.x = motionState.m_sweptTransform.m_rotation1.m_vec.x;
    oldRotation.y = motionState.m_sweptTransform.m_rotation1.m_vec.y;
    oldRotation.z = motionState.m_sweptTransform.m_rotation1.m_vec.z;
    oldRotation.w = motionState.m_sweptTransform.m_rotation1.m_vec.w;
    motionState.m_sweptTransform.m_rotation0.m_vec.x = oldRotation.x;
    motionState.m_sweptTransform.m_rotation0.m_vec.y = oldRotation.y;
    motionState.m_sweptTransform.m_rotation0.m_vec.z = oldRotation.z;
    motionState.m_sweptTransform.m_rotation0.m_vec.w = oldRotation.w;

    f32 angularDeltaTime = stepInfo.m_deltaTime.m_storage;
    f32 halfDeltaTime = 0.5f * angularDeltaTime;
    hkQuadReal angle;
    angle.x = halfDeltaTime * angularVelocity.x;
    angle.y = halfDeltaTime * angularVelocity.y;
    angle.z = halfDeltaTime * angularVelocity.z;
    f32 angleLengthSq = angle.x * angle.x + angle.y * angle.y + angle.z * angle.z;
    f32 scaledAngleLengthSq = 0.40528470277786255f * angleLengthSq;
    f32 maxAngle = motionState.m_maxAngularVelocity * angularDeltaTime;
    maxAngle = (0.9f < maxAngle) ? 0.9f : maxAngle;
    f32 maxAngleSq = maxAngle * maxAngle;

    if (scaledAngleLengthSq <= maxAngleSq) {
        f32 scaledAngleLengthSq2 = scaledAngleLengthSq * scaledAngleLengthSq;
        angle.w = 1.0f - 0.8229479789733887f * scaledAngleLengthSq -
                  0.1305290013551712f * scaledAngleLengthSq2 -
                  scaledAngleLengthSq2 * (0.04440800100564957f * scaledAngleLengthSq);
    } else {
        f32 scale = maxAngle * hkMath::sqrtInverse(scaledAngleLengthSq);
        angularVelocity.x *= scale;
        angularVelocity.y *= scale;
        angularVelocity.z *= scale;
        angularVelocity.w *= scale;
        angle.x *= scale;
        angle.y *= scale;
        angle.z *= scale;
        scaledAngleLengthSq = maxAngleSq;

        f32 scaledAngleLengthSq2 = scaledAngleLengthSq * scaledAngleLengthSq;
        angle.w = 1.0f - 0.8229479789733887f * scaledAngleLengthSq -
                  0.1305290013551712f * scaledAngleLengthSq2 -
                  scaledAngleLengthSq2 * (0.04440800100564957f * scaledAngleLengthSq);
    }

    hkQuadReal updatedRotation;
    updatedRotation.x = angle.y * oldRotation.z - angle.z * oldRotation.y;
    updatedRotation.y = angle.z * oldRotation.x - angle.x * oldRotation.z;
    updatedRotation.z = angle.x * oldRotation.y - angle.y * oldRotation.x;
    updatedRotation.x += angle.w * oldRotation.x;
    updatedRotation.y += angle.w * oldRotation.y;
    updatedRotation.z += angle.w * oldRotation.z;
    updatedRotation.x += oldRotation.w * angle.x;
    updatedRotation.y += oldRotation.w * angle.y;
    updatedRotation.z += oldRotation.w * angle.z;
    updatedRotation.w =
        angle.w * oldRotation.w -
        (angle.x * oldRotation.x + angle.y * oldRotation.y + angle.z * oldRotation.z);

    f32 rotationLengthSq =
        updatedRotation.x * updatedRotation.x + updatedRotation.y * updatedRotation.y +
        updatedRotation.z * updatedRotation.z + updatedRotation.w * updatedRotation.w;
    f32 rotationInvLength;
    if (scalarNotEqual(rotationLengthSq, 0.0f)) {
        rotationInvLength = hkMath::sqrtInverse(rotationLengthSq);
    } else {
        rotationInvLength = 0.0f;
    }

    updatedRotation.x *= rotationInvLength;
    updatedRotation.y *= rotationInvLength;
    updatedRotation.z *= rotationInvLength;
    updatedRotation.w *= rotationInvLength;

    motionState.m_deltaAngle.x = angle.x + angle.x;
    motionState.m_deltaAngle.y = angle.y + angle.y;
    motionState.m_deltaAngle.z = angle.z + angle.z;
    motionState.m_deltaAngle.w = angle.w + angle.w;
    motionState.m_deltaAngle.w = 3.1415927410125732f * hkMath::sqrt(scaledAngleLengthSq);

    motionState.m_sweptTransform.m_rotation1.m_vec.x = updatedRotation.x;
    motionState.m_sweptTransform.m_rotation1.m_vec.y = updatedRotation.y;
    motionState.m_sweptTransform.m_rotation1.m_vec.z = updatedRotation.z;
    motionState.m_sweptTransform.m_rotation1.m_vec.w = updatedRotation.w;

    hkTransform& transform = motionState.m_transform;
    hkSweptTransform& sweptTransform = motionState.m_sweptTransform;
    transform.m_rotation.set(sweptTransform.m_rotation1);

    f32 localCenterX = sweptTransform.m_centerOfMassLocal.x;
    f32 localCenterY = sweptTransform.m_centerOfMassLocal.y;
    f32 localCenterZ = sweptTransform.m_centerOfMassLocal.z;
    const hkRotation& rotation = transform.m_rotation;
    hkVector4 rotatedCenter;
    hkQuadReal& rotatedQuad = rotatedCenter.getQuad();
    rotatedQuad.x = localCenterX * rotation.m_col0.x + localCenterY * rotation.m_col1.x +
                    localCenterZ * rotation.m_col2.x;
    rotatedQuad.y = localCenterX * rotation.m_col0.y + localCenterY * rotation.m_col1.y +
                    localCenterZ * rotation.m_col2.y;
    rotatedQuad.z = localCenterX * rotation.m_col0.z + localCenterY * rotation.m_col1.z +
                    localCenterZ * rotation.m_col2.z;
    rotatedQuad.w = 0.0f;
    transform.m_translation.x = sweptTransform.m_centerOfMass1.x - rotatedCenter.x;
    transform.m_translation.y = sweptTransform.m_centerOfMass1.y - rotatedCenter.y;
    transform.m_translation.z = sweptTransform.m_centerOfMass1.z - rotatedCenter.z;
    transform.m_translation.w = sweptTransform.m_centerOfMass1.w - rotatedCenter.w;
}

extern "C" bool hkRigidMotionUtilCanDeactivateFinal(const hkStepInfo&,
                                                    hkEntity** ppEntities,
                                                    s32 s32NumEntities,
                                                    s32 s32MotionOffset)
{
    while (--s32NumEntities >= 0) {
        hkMotion* pMotion =
            reinterpret_cast<hkMotion*>(reinterpret_cast<u8*>(*ppEntities) + s32MotionOffset);

        f32 f32ObjectRadius = pMotion->m_motionState.m_objectRadius;
        f32ObjectRadius = (1.0f < f32ObjectRadius) ? 1.0f : f32ObjectRadius;

        f32 f32AngularVelocitySq = pMotion->m_angularVelocity.x * pMotion->m_angularVelocity.x +
                                   pMotion->m_angularVelocity.y * pMotion->m_angularVelocity.y +
                                   pMotion->m_angularVelocity.z * pMotion->m_angularVelocity.z;
        f32 f32LinearY = pMotion->m_linearVelocity.y;
        f32 f32LinearX = pMotion->m_linearVelocity.x;
        f32 f32LinearZ = pMotion->m_linearVelocity.z;
        f32 f32LinearVelocitySq =
            f32LinearX * f32LinearX + f32LinearY * f32LinearY + f32LinearZ * f32LinearZ;
        f32 f32ObjectRadiusSq = f32ObjectRadius * f32ObjectRadius;
        f32 f32MotionValue =
            0.25f * (f32LinearVelocitySq + f32AngularVelocitySq * f32ObjectRadiusSq) -
            (0.1f * 0.1f);

        if ((pMotion->m_deactivationNumInactiveFrames[0] & 0x7f) >
            (pMotion->m_deactivationNumInactiveFrames[1] & 0x7f))
        {
            if (f32MotionValue > pMotion->m_deactivationRefPosition[0].w) {
                return false;
            }
        } else {
            if (f32MotionValue > pMotion->m_deactivationRefPosition[1].w) {
                return false;
            }
        }

        ++ppEntities;
    }

    return true;
}

extern "C" void hkRigidMotionUtilStep(const hkStepInfo& stepInfo,
                                      hkEntity** ppEntities,
                                      s32 numEntities,
                                      s32 motionOffset)
{
    s32 entityIndex = numEntities - 1;
    for (; entityIndex >= 0; --entityIndex) {
        hkMotion* motion =
            reinterpret_cast<hkMotion*>(reinterpret_cast<u8*>(*ppEntities) + motionOffset);
        hkSweptTransformUtil::_stepMotionState(
            stepInfo, motion->m_linearVelocity, motion->m_angularVelocity, motion->m_motionState);
        ++ppEntities;
    }
}

// RECONSTRUCTED: local helper names.
static inline f32 hkRigidMotionUtilGetDampingFactor(f32 f32DeltaTime, f32 f32Damping)
{
    f32 factor = 1.0f - f32DeltaTime * f32Damping;
    return (factor > 0.0f) ? factor : 0.0f;
}

static inline void hkRigidMotionUtilApplyGravityAndDamping(const hkStepInfo& rStepInfo,
                                                           const hkVector4& rAcceleration,
                                                           hkMotion& rMotion)
{
    hkVector4& linearVelocity = rMotion.m_linearVelocity;
    linearVelocity.x += rAcceleration.x;
    linearVelocity.y += rAcceleration.y;
    linearVelocity.z += rAcceleration.z;
    linearVelocity.w += rAcceleration.w;
    const f32 deltaTime = rStepInfo.m_deltaTime.m_storage;
    linearVelocity.mul4(
        hkRigidMotionUtilGetDampingFactor(deltaTime, rMotion.m_motionState.m_linearDamping));
    rMotion.m_angularVelocity.mul4(
        hkRigidMotionUtilGetDampingFactor(deltaTime, rMotion.m_motionState.m_angularDamping));
}

static inline void hkRigidMotionUtilClampVelocity(hkVector4& rVelocity, f32 f32Maximum)
{
    f32 velocitySq =
        rVelocity.x * rVelocity.x + rVelocity.y * rVelocity.y + rVelocity.z * rVelocity.z;
    f32 maximumSq = f32Maximum * f32Maximum;
    if (velocitySq <= maximumSq && velocitySq == velocitySq) {
        return;
    }

    f32 scale = f32Maximum * __rsqrt(1.0f, velocitySq);
    rVelocity.x *= scale;
    rVelocity.y *= scale;
    rVelocity.z *= scale;
    rVelocity.w *= scale;

    if (velocitySq == velocitySq) {
        return;
    }
    const hkQuadReal& invalidVelocity = hkTransform::getIdentity().m_rotation.m_col0.getQuad();
    rVelocity.x = invalidVelocity.x;
    rVelocity.y = invalidVelocity.y;
    rVelocity.z = invalidVelocity.z;
    rVelocity.w = invalidVelocity.w;
}

static inline void hkRigidMotionUtilUpdateDeactivation(const hkSolverInfo& rSolverInfo,
                                                       hkMotion& rMotion)
{
    u32 integrateCounter = static_cast<u8>(rMotion.m_deactivationIntegrateCounter) + 1;
    rMotion.m_deactivationIntegrateCounter = static_cast<u8>(integrateCounter);

    if ((integrateCounter & 3) != 0) {
        return;
    }

    s32 referenceIndex;
    if ((integrateCounter & 0xf) != 0) {
        referenceIndex = 0;
    } else {
        if (integrateCounter == 0x100) {
            rMotion.m_deactivationIntegrateCounter = 0xff;
            return;
        }
        rMotion.m_deactivationIntegrateCounter = 0;
        referenceIndex = 1;
    }

    f32 objectRadius = rMotion.m_motionState.m_objectRadius;
    objectRadius = (1.0f < objectRadius) ? 1.0f : objectRadius;
    f32 angularVelocitySq = rMotion.m_angularVelocity.x * rMotion.m_angularVelocity.x +
                            rMotion.m_angularVelocity.y * rMotion.m_angularVelocity.y +
                            rMotion.m_angularVelocity.z * rMotion.m_angularVelocity.z;
    f32 linearY = rMotion.m_linearVelocity.y;
    f32 linearX = rMotion.m_linearVelocity.x;
    f32 linearZ = rMotion.m_linearVelocity.z;
    f32 linearVelocitySq = linearX * linearX + linearY * linearY + linearZ * linearZ;
    f32 objectRadiusSq = objectRadius * objectRadius;
    f32 motionValue = linearVelocitySq + angularVelocitySq * objectRadiusSq;

    hkVector4& referencePosition = rMotion.m_deactivationRefPosition[referenceIndex];
    f32& maximumMotionValue = referencePosition(3);
    maximumMotionValue = (maximumMotionValue > motionValue) ? maximumMotionValue : motionValue;

    const hkSweptTransform& sweptTransform = rMotion.m_motionState.m_sweptTransform;
    const hkVector4& centerOfMass = sweptTransform.m_centerOfMass1;
    const hkVector4& rotation = sweptTransform.m_rotation1.m_vec;
    u32& referenceOrientation = rMotion.m_motionState.m_deactivationRefOrientation[referenceIndex];
    const DeactivationInfo& deactivationInfo =
        rSolverInfo.m_deactivationInfo[rMotion.m_motionState.m_deactivationClass];
    f32 deltaX = referencePosition.x - centerOfMass.x;
    f32 deltaY = referencePosition.y - centerOfMass.y;
    f32 deltaZ = referencePosition.z - centerOfMass.z;
    f32 distanceSq = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;

    if (distanceSq <= deactivationInfo.m_maxDistSqrd[referenceIndex]) {
        u32 packedOrientation = referenceOrientation;
        union HalfFloat {
            s32 m_bits;
            f32 m_float;
        } maxRotationDistance;
        maxRotationDistance.m_bits =
            static_cast<s32>(deactivationInfo.m_maxRotSqrd[referenceIndex].m_value) << 16;
        const f32 unpackScale = 0.00859375f;
        f32 referenceX = static_cast<s32>((packedOrientation & 0xff) - 0x80) * unpackScale;
        f32 referenceY = static_cast<s32>(((packedOrientation >> 8) & 0xff) - 0x80) * unpackScale;
        f32 referenceZ = static_cast<s32>(((packedOrientation >> 16) & 0xff) - 0x80) * unpackScale;
        f32 referenceW = static_cast<s32>((packedOrientation >> 24) - 0x80) * unpackScale;
        f32 rotationDeltaX = referenceX - rotation.x;
        f32 rotationDeltaY = referenceY - rotation.y;
        f32 rotationDeltaZ = referenceZ - rotation.z;
        f32 rotationDeltaW = referenceW - rotation.w;
        f32 rotationDeltaSq = rotationDeltaX * rotationDeltaX + rotationDeltaY * rotationDeltaY +
                              rotationDeltaZ * rotationDeltaZ + rotationDeltaW * rotationDeltaW;

        if (rotationDeltaSq <= maxRotationDistance.m_float) {
            u16 inactiveFrames = rMotion.m_deactivationNumInactiveFrames[referenceIndex] & 0x7f;
            rMotion.m_deactivationNumInactiveFrames[referenceIndex] =
                (rSolverInfo.m_deactivationNumInactiveFramesSelectFlag[referenceIndex] << 14) |
                (((inactiveFrames + 1) - (inactiveFrames >> 6)) | (inactiveFrames << 7));
            return;
        }
    }

    u16 inactiveFrames = rMotion.m_deactivationNumInactiveFrames[referenceIndex] & 0x7f;
    rMotion.m_deactivationNumInactiveFrames[referenceIndex] =
        (rSolverInfo.m_deactivationNumInactiveFramesSelectFlag[referenceIndex] << 14) |
        (inactiveFrames << 7);
    f32 centerY = centerOfMass.y;
    f32 centerZ = centerOfMass.z;
    f32 centerX = centerOfMass.x;
    referencePosition.x = centerX;
    referencePosition.y = centerY;
    referencePosition.z = centerZ;
    referencePosition.w = 0.0f;
    referenceOrientation = hkVector4Util::packQuaternionIntoInt32(rotation);
}

extern "C" u32 hkRigidMotionUtilApplyForcesAndStep(const hkSolverInfo& rSolverInfo,
                                                   const hkStepInfo& rStepInfo,
                                                   const hkVector4& rGlobalAccelerationPerStep,
                                                   hkEntity** ppEntities,
                                                   s32 s32NumEntities,
                                                   s32 s32MotionOffset)
{
    s32 minimumInactiveFrames = 0x7fffffff;
    s32 entityIndex = s32NumEntities - 1;
    while (entityIndex >= 0) {
        hkMotion* pMotion =
            reinterpret_cast<hkMotion*>(reinterpret_cast<u8*>(*ppEntities) + s32MotionOffset);
        hkMotion::MotionType motionType = pMotion->getType();

        if (motionType != hkMotion::MOTION_FIXED) {
            if (motionType == hkMotion::MOTION_THIN_BOX_INERTIA) {
                hkRigidMotionUtilApplyGravityAndDamping(
                    rStepInfo, rGlobalAccelerationPerStep, *pMotion);

                {
                    hkVector4 worldAngularMomentum;
                    {
                        hkVector4 localAngularMomentum;
                        localAngularMomentum.setRotatedInverseDir(
                            pMotion->m_motionState.m_transform.m_rotation,
                            pMotion->m_angularVelocity);
                        const f32 inertiaW = 1.0f / pMotion->m_inertiaAndMassInv.w;
                        const f32 inertiaY = 1.0f / pMotion->m_inertiaAndMassInv.y;
                        const f32 inertiaZ = 1.0f / pMotion->m_inertiaAndMassInv.z;
                        const f32 inertiaX = 1.0f / pMotion->m_inertiaAndMassInv.x;
                        localAngularMomentum.w *= inertiaW;
                        localAngularMomentum.y *= inertiaY;
                        localAngularMomentum.z *= inertiaZ;
                        localAngularMomentum.x *= inertiaX;
                        worldAngularMomentum.setRotatedDir(
                            pMotion->m_motionState.m_transform.m_rotation, localAngularMomentum);
                    }

                    hkSweptTransformUtil::_stepMotionState(rStepInfo,
                                                           pMotion->m_linearVelocity,
                                                           pMotion->m_angularVelocity,
                                                           pMotion->m_motionState);

                    {
                        hkVector4 localAngularMomentum;
                        localAngularMomentum.setRotatedInverseDir(
                            pMotion->m_motionState.m_transform.m_rotation, worldAngularMomentum);
                        localAngularMomentum.x *= pMotion->m_inertiaAndMassInv.x;
                        localAngularMomentum.y *= pMotion->m_inertiaAndMassInv.y;
                        localAngularMomentum.z *= pMotion->m_inertiaAndMassInv.z;
                        localAngularMomentum.w *= pMotion->m_inertiaAndMassInv.w;
                        pMotion->m_angularVelocity.setRotatedDir(
                            pMotion->m_motionState.m_transform.m_rotation, localAngularMomentum);
                    }
                }

                hkRigidMotionUtilClampVelocity(pMotion->m_linearVelocity,
                                               pMotion->m_motionState.m_maxLinearVelocity);
                hkRigidMotionUtilClampVelocity(pMotion->m_angularVelocity,
                                               pMotion->m_motionState.m_maxAngularVelocity);
            } else {
                if (motionType != hkMotion::MOTION_KEYFRAMED) {
                    hkRigidMotionUtilApplyGravityAndDamping(
                        rStepInfo, rGlobalAccelerationPerStep, *pMotion);
                }
                hkSweptTransformUtil::_stepMotionState(rStepInfo,
                                                       pMotion->m_linearVelocity,
                                                       pMotion->m_angularVelocity,
                                                       pMotion->m_motionState);
            }
            hkRigidMotionUtilUpdateDeactivation(rSolverInfo, *pMotion);
            {
                s32 inactiveFrames1 = pMotion->m_deactivationNumInactiveFrames[1] & 0x7f;
                s32 inactiveFrames0 = pMotion->m_deactivationNumInactiveFrames[0] & 0x7f;
                s32 maximumInactiveFrames =
                    (inactiveFrames1 < inactiveFrames0) ? inactiveFrames0 : inactiveFrames1;
                minimumInactiveFrames = (minimumInactiveFrames < maximumInactiveFrames)
                                            ? minimumInactiveFrames
                                            : maximumInactiveFrames;
            }
        }
        --entityIndex;
        ++ppEntities;
    }
    return minimumInactiveFrames;
}

static inline void hkRigidMotionUtilSetAccumulatorCenterOfMass(const hkStepInfo& rStepInfo,
                                                               const hkMotion& rMotion,
                                                               hkVelocityAccumulator& rAccumulator)
{
    const hkSweptTransform& sweptTransform = rMotion.m_motionState.m_sweptTransform;
    f32 interpolationDelta = rStepInfo.m_startTime.m_storage - sweptTransform.m_centerOfMass0.w;
    f32 interpolation = interpolationDelta * sweptTransform.m_centerOfMass1.w;
    f32 inverseInterpolation = 1.0f - interpolation;
    rAccumulator.m_centerOfMass.x = inverseInterpolation * sweptTransform.m_centerOfMass0.x +
                                    interpolation * sweptTransform.m_centerOfMass1.x;
    rAccumulator.m_centerOfMass.y = inverseInterpolation * sweptTransform.m_centerOfMass0.y +
                                    interpolation * sweptTransform.m_centerOfMass1.y;
    rAccumulator.m_centerOfMass.z = inverseInterpolation * sweptTransform.m_centerOfMass0.z +
                                    interpolation * sweptTransform.m_centerOfMass1.z;
    rAccumulator.m_centerOfMass.w = inverseInterpolation * sweptTransform.m_centerOfMass0.w +
                                    interpolation * sweptTransform.m_centerOfMass1.w;
}

static inline void hkRigidMotionUtilClearAccumulatorMatrix(hkVelocityAccumulator& rAccumulator)
{
    rAccumulator.m_coreFromWorld.m_col0.x = 0.0f;
    rAccumulator.m_coreFromWorld.m_col0.y = 0.0f;
    rAccumulator.m_coreFromWorld.m_col0.z = 0.0f;
    rAccumulator.m_coreFromWorld.m_col0.w = 0.0f;
    rAccumulator.m_coreFromWorld.m_col1.x = 0.0f;
    rAccumulator.m_coreFromWorld.m_col1.y = 0.0f;
    rAccumulator.m_coreFromWorld.m_col1.z = 0.0f;
    rAccumulator.m_coreFromWorld.m_col1.w = 0.0f;
    rAccumulator.m_coreFromWorld.m_col2.x = 0.0f;
    rAccumulator.m_coreFromWorld.m_col2.y = 0.0f;
    rAccumulator.m_coreFromWorld.m_col2.z = 0.0f;
    rAccumulator.m_coreFromWorld.m_col2.w = 0.0f;
}

extern "C" hkVelocityAccumulator* hkRigidMotionUtilApplyForcesAndBuildAccumulators(
    const hkStepInfo& rStepInfo,
    hkEntity** ppEntities,
    s32 s32NumEntities,
    s32 s32MotionOffset,
    hkVelocityAccumulator* pAccumulators)
{
    s32 entityIndex = s32NumEntities - 1;
    for (; entityIndex >= 0; --entityIndex) {
        hkMotion* pMotion =
            reinterpret_cast<hkMotion*>(reinterpret_cast<u8*>(*ppEntities) + s32MotionOffset);
        hkVelocityAccumulator& accumulator = *pAccumulators;

        switch (pMotion->getType()) {
        case hkMotion::MOTION_BOX_INERTIA:
        case hkMotion::MOTION_BOX_STABILIZED:
        case hkMotion::MOTION_THIN_BOX_INERTIA: {
            const f32 deltaTime = rStepInfo.m_deltaTime.m_storage;
            f32 linearFactor = 1.0f - deltaTime * pMotion->m_motionState.m_linearDamping;
            linearFactor = (0.0f > linearFactor) ? 0.0f : linearFactor;
            pMotion->m_linearVelocity.mul4(linearFactor);

            f32 angularFactor = 1.0f - deltaTime * pMotion->m_motionState.m_angularDamping;
            angularFactor = (0.0f > angularFactor) ? 0.0f : angularFactor;
            pMotion->m_angularVelocity.mul4(angularFactor);

            accumulator.m_coreFromWorld.setTranspose(pMotion->m_motionState.m_transform.m_rotation);
            accumulator.m_type = 0;
            accumulator.m_invMasses = pMotion->m_inertiaAndMassInv;
            accumulator.m_linearVelocity = pMotion->m_linearVelocity;
            hkRigidMotionUtilSetAccumulatorCenterOfMass(rStepInfo, *pMotion, accumulator);

            accumulator.m_angularVelocity.setMul3(accumulator.m_coreFromWorld,
                                                  pMotion->m_angularVelocity);
            accumulator.m_matrixIsIdentity = 0;
            accumulator.m_deactivationClass = pMotion->m_motionState.m_deactivationClass;
            accumulator.m_deactivationCounter = pMotion->m_motionState.m_deactivationCounter;
            break;
        }
        case hkMotion::MOTION_SPHERE_INERTIA:
        case hkMotion::MOTION_SPHERE_STABILIZED: {
            const f32 deltaTime = rStepInfo.m_deltaTime.m_storage;
            f32 linearFactor = 1.0f - deltaTime * pMotion->m_motionState.m_linearDamping;
            linearFactor = (0.0f > linearFactor) ? 0.0f : linearFactor;
            pMotion->m_linearVelocity.mul4(linearFactor);

            f32 angularFactor = 1.0f - deltaTime * pMotion->m_motionState.m_angularDamping;
            angularFactor = (0.0f > angularFactor) ? 0.0f : angularFactor;
            pMotion->m_angularVelocity.mul4(angularFactor);

            accumulator.m_type = 0;
            accumulator.m_invMasses = pMotion->m_inertiaAndMassInv;
            hkRigidMotionUtilSetAccumulatorCenterOfMass(rStepInfo, *pMotion, accumulator);
            accumulator.m_angularVelocity = pMotion->m_angularVelocity;
            accumulator.m_linearVelocity = pMotion->m_linearVelocity;
            hkRigidMotionUtilClearAccumulatorMatrix(accumulator);
            accumulator.m_coreFromWorld.m_col0.x = 1.0f;
            accumulator.m_coreFromWorld.m_col1.y = 1.0f;
            accumulator.m_coreFromWorld.m_col2.z = 1.0f;
            accumulator.m_matrixIsIdentity = 1;
            accumulator.m_deactivationClass = pMotion->m_motionState.m_deactivationClass;
            accumulator.m_deactivationCounter = pMotion->m_motionState.m_deactivationCounter;
            break;
        }
        case hkMotion::MOTION_FIXED:
            accumulator.m_type = 1;
            accumulator.m_matrixIsIdentity = 1;
            accumulator.m_invMasses.x = accumulator.m_invMasses.y = accumulator.m_invMasses.z =
                accumulator.m_invMasses.w = 0.0f;
            accumulator.m_linearVelocity.x = accumulator.m_linearVelocity.y =
                accumulator.m_linearVelocity.z = accumulator.m_linearVelocity.w = 0.0f;
            accumulator.m_angularVelocity.x = accumulator.m_angularVelocity.y =
                accumulator.m_angularVelocity.z = accumulator.m_angularVelocity.w = 0.0f;
            accumulator.m_centerOfMass.x = accumulator.m_centerOfMass.y =
                accumulator.m_centerOfMass.z = accumulator.m_centerOfMass.w = 0.0f;
            hkRigidMotionUtilClearAccumulatorMatrix(accumulator);
            break;
        case hkMotion::MOTION_KEYFRAMED:
            accumulator.m_type = 1;
            accumulator.m_invMasses.x = accumulator.m_invMasses.y = accumulator.m_invMasses.z =
                accumulator.m_invMasses.w = 0.0f;
            accumulator.m_centerOfMass = pMotion->m_motionState.m_sweptTransform.m_centerOfMass1;
            accumulator.m_angularVelocity = pMotion->m_angularVelocity;
            accumulator.m_linearVelocity = pMotion->m_linearVelocity;
            hkRigidMotionUtilClearAccumulatorMatrix(accumulator);
            accumulator.m_coreFromWorld.m_col0.x = 1.0f;
            accumulator.m_coreFromWorld.m_col1.y = 1.0f;
            accumulator.m_coreFromWorld.m_col2.z = 1.0f;
            accumulator.m_matrixIsIdentity = 1;
            break;
        default:
            break;
        }

        ++ppEntities;
        ++pAccumulators;
    }
    return pAccumulators;
}

static inline f32 hkRigidMotionUtilLengthSquared3(const hkVector4& velocity)
{
    return velocity.x * velocity.x + velocity.y * velocity.y + velocity.z * velocity.z;
}

static inline void hkRigidMotionUtilClampMotionVelocities(hkMotion& rMotion)
{
    f32 linearVelocitySq = hkRigidMotionUtilLengthSquared3(rMotion.m_linearVelocity);
    f32 angularVelocitySq = hkRigidMotionUtilLengthSquared3(rMotion.m_angularVelocity);
    f32 maxAngularVelocitySq =
        rMotion.m_motionState.m_maxAngularVelocity * rMotion.m_motionState.m_maxAngularVelocity;
    f32 maxLinearVelocity = rMotion.m_motionState.m_maxLinearVelocity;
    f32 maxLinearVelocitySq = maxLinearVelocity * maxLinearVelocity;

    if (!(linearVelocitySq <= maxLinearVelocitySq && linearVelocitySq == linearVelocitySq)) {
        f32 scale = maxLinearVelocity * hkMath::sqrtInverse(linearVelocitySq);
        rMotion.m_linearVelocity.x *= scale;
        rMotion.m_linearVelocity.y *= scale;
        rMotion.m_linearVelocity.z *= scale;
        rMotion.m_linearVelocity.w *= scale;
        if (!(linearVelocitySq == linearVelocitySq)) {
            const hkQuadReal& invalidVelocity =
                hkTransform::getIdentity().m_rotation.m_col0.getQuad();
            rMotion.m_linearVelocity.x = invalidVelocity.x;
            rMotion.m_linearVelocity.y = invalidVelocity.y;
            rMotion.m_linearVelocity.z = invalidVelocity.z;
            rMotion.m_linearVelocity.w = invalidVelocity.w;
        }
    }

    if (!(angularVelocitySq <= maxAngularVelocitySq && angularVelocitySq == angularVelocitySq)) {
        f32 scale =
            rMotion.m_motionState.m_maxAngularVelocity * hkMath::sqrtInverse(angularVelocitySq);
        rMotion.m_angularVelocity.x *= scale;
        rMotion.m_angularVelocity.y *= scale;
        rMotion.m_angularVelocity.z *= scale;
        rMotion.m_angularVelocity.w *= scale;
        if (!(angularVelocitySq == angularVelocitySq)) {
            const hkQuadReal& invalidVelocity =
                hkTransform::getIdentity().m_rotation.m_col0.getQuad();
            rMotion.m_angularVelocity.x = invalidVelocity.x;
            rMotion.m_angularVelocity.y = invalidVelocity.y;
            rMotion.m_angularVelocity.z = invalidVelocity.z;
            rMotion.m_angularVelocity.w = invalidVelocity.w;
        }
    }
}

extern "C" u32 hkRigidMotionUtilApplyAccumulators(const hkSolverInfo& rSolverInfo,
                                                  const hkStepInfo& rStepInfo,
                                                  hkVelocityAccumulator* pAccumulators,
                                                  hkEntity** ppEntities,
                                                  s32 s32NumEntities,
                                                  s32 s32MotionOffset)
{
    s32 minimumInactiveFrames = 0x7fffffff;
    s32 entityIndex = s32NumEntities - 1;
    for (; entityIndex >= 0; --entityIndex, ++ppEntities, ++pAccumulators) {
        hkMotion* pMotion =
            reinterpret_cast<hkMotion*>(reinterpret_cast<u8*>(*ppEntities) + s32MotionOffset);
        hkVelocityAccumulator& accumulator = *pAccumulators;
        hkVector4 linearVelocity;
        hkVector4 angularVelocity;
        hkVector4 thinBoxAngularMomentum;
        hkVector4 localAngularMomentum;

        bool bStepMotion = true;
        bool bUpdateCounter = true;
        switch (pMotion->getType()) {
        case hkMotion::MOTION_INVALID:
        case hkMotion::MOTION_THIN_BOX_INERTIA: {
            localAngularMomentum = accumulator.m_angularVelocity;
            f32 invInertiaW = 1.0f / pMotion->m_inertiaAndMassInv.w;
            f32 invInertiaY = 1.0f / pMotion->m_inertiaAndMassInv.y;
            f32 invInertiaZ = 1.0f / pMotion->m_inertiaAndMassInv.z;
            f32 invInertiaX = 1.0f / pMotion->m_inertiaAndMassInv.x;
            localAngularMomentum.x *= invInertiaX;
            localAngularMomentum.y *= invInertiaY;
            localAngularMomentum.z *= invInertiaZ;
            localAngularMomentum.w *= invInertiaW;
            thinBoxAngularMomentum.setRotatedDir(pMotion->m_motionState.m_transform.m_rotation,
                                                 localAngularMomentum);
        }
        case hkMotion::MOTION_BOX_INERTIA:
            pMotion->m_linearVelocity = accumulator.m_linearVelocity;
            {
                const hkRotation& rotation = pMotion->m_motionState.m_transform.m_rotation;
                f32 angularX = accumulator.m_angularVelocity.x;
                f32 angularY = accumulator.m_angularVelocity.y;
                f32 angularZ = accumulator.m_angularVelocity.z;
                pMotion->m_angularVelocity.x = angularX * rotation.m_col0.x +
                                               angularY * rotation.m_col1.x +
                                               angularZ * rotation.m_col2.x;
                pMotion->m_angularVelocity.y = angularX * rotation.m_col0.y +
                                               angularY * rotation.m_col1.y +
                                               angularZ * rotation.m_col2.y;
                pMotion->m_angularVelocity.z = angularX * rotation.m_col0.z +
                                               angularY * rotation.m_col1.z +
                                               angularZ * rotation.m_col2.z;
                pMotion->m_angularVelocity.w = 0.0f;
            }
            linearVelocity = accumulator.m_centerOfMass;
            angularVelocity.setRotatedDir(pMotion->m_motionState.m_transform.m_rotation,
                                          accumulator.m_coreFromWorld.m_col0);
            break;

        case hkMotion::MOTION_BOX_STABILIZED: {
            const hkVector4& sumAngularVelocity = accumulator.m_coreFromWorld.m_col0;
            pMotion->m_linearVelocity = accumulator.m_centerOfMass;
            pMotion->m_angularVelocity = sumAngularVelocity;
            linearVelocity = accumulator.m_centerOfMass;
            angularVelocity.setRotatedDir(pMotion->m_motionState.m_transform.m_rotation,
                                          sumAngularVelocity);
            break;
        }

        case hkMotion::MOTION_SPHERE_STABILIZED:
            pMotion->m_linearVelocity = accumulator.m_centerOfMass;
            pMotion->m_angularVelocity = accumulator.m_coreFromWorld.m_col0;
            linearVelocity = accumulator.m_centerOfMass;
            angularVelocity = accumulator.m_coreFromWorld.m_col0;
            break;

        case hkMotion::MOTION_KEYFRAMED:
            linearVelocity = pMotion->m_linearVelocity;
            angularVelocity = pMotion->m_angularVelocity;
            bUpdateCounter = false;
            break;

        case hkMotion::MOTION_SPHERE_INERTIA:
            pMotion->m_linearVelocity = accumulator.m_linearVelocity;
            pMotion->m_angularVelocity = accumulator.m_angularVelocity;
            linearVelocity = accumulator.m_centerOfMass;
            angularVelocity = accumulator.m_coreFromWorld.m_col0;
            break;

        default:
            bStepMotion = false;
            break;
        }

        if (bStepMotion) {
            if (bUpdateCounter) {
                pMotion->m_motionState.m_deactivationCounter =
                    static_cast<u16>(accumulator.m_deactivationCounter);
            }
            hkSweptTransformUtil::_stepMotionState(
                rStepInfo, linearVelocity, angularVelocity, pMotion->m_motionState);
        }
        hkBool isThinBoxMotion(pMotion->getType() == hkMotion::MOTION_THIN_BOX_INERTIA);
        if (isThinBoxMotion) {
            pMotion->m_linearVelocity = accumulator.m_linearVelocity;
            hkVector4 inverseRotatedAngularMomentum;
            inverseRotatedAngularMomentum.setRotatedInverseDir(
                pMotion->m_motionState.m_transform.m_rotation, thinBoxAngularMomentum);
            inverseRotatedAngularMomentum.mul4(pMotion->m_inertiaAndMassInv);
            pMotion->m_angularVelocity.setRotatedDir(pMotion->m_motionState.m_transform.m_rotation,
                                                     inverseRotatedAngularMomentum);
        }

        hkRigidMotionUtilClampMotionVelocities(*pMotion);
        hkRigidMotionUtilUpdateDeactivation(rSolverInfo, *pMotion);

        s32 inactiveFrames1 = pMotion->m_deactivationNumInactiveFrames[1] & 0x7f;
        s32 inactiveFrames0 = pMotion->m_deactivationNumInactiveFrames[0] & 0x7f;
        s32 maximumInactiveFrames =
            (inactiveFrames1 < inactiveFrames0) ? inactiveFrames0 : inactiveFrames1;
        minimumInactiveFrames = (minimumInactiveFrames < maximumInactiveFrames)
                                    ? minimumInactiveFrames
                                    : maximumInactiveFrames;
    }
    return minimumInactiveFrames;
}
