#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

hkBoxMotion::hkBoxMotion(const hkVector4& rPosition, const hkQuaternion& rRotation)
    : hkMotion(rPosition, rRotation, false)
{
    m_inertiaAndMassInv.x = 1.0f;
    m_inertiaAndMassInv.y = 1.0f;
    m_inertiaAndMassInv.z = 1.0f;
    m_inertiaAndMassInv.w = 1.0f;
    m_type = MOTION_BOX_INERTIA;
}

void hkBoxMotion::getInertiaLocal(hkMatrix3& rInertia) const
{
    const f32 inertia0 = 1.0f / m_inertiaAndMassInv.x;
    const f32 inertia1 = 1.0f / m_inertiaAndMassInv.y;
    const f32 inertia2 = 1.0f / m_inertiaAndMassInv.z;
    rInertia.setZero();
    rInertia.m_col0.x = inertia0;
    rInertia.m_col1.y = inertia1;
    rInertia.m_col2.z = inertia2;
}

void hkBoxMotion::setInertiaLocal(const hkMatrix3& rInertia)
{
    const f32 inertiaInv1 = 1.0f / rInertia.m_col1.y;
    const f32 inertiaInv0 = 1.0f / rInertia.m_col0.x;
    const f32 inertiaInv2 = 1.0f / rInertia.m_col2.z;
    const f32 massInv = m_inertiaAndMassInv.w;
    m_inertiaAndMassInv.set(inertiaInv0, inertiaInv1, inertiaInv2, massInv);
}

void hkBoxMotion::getInertiaInvLocal(hkMatrix3& rInertia) const
{
    const f32 inertiaInv0 = m_inertiaAndMassInv.x;
    const f32 inertiaInv1 = m_inertiaAndMassInv.y;
    const f32 inertiaInv2 = m_inertiaAndMassInv.z;
    rInertia.setZero();
    rInertia.m_col0.x = inertiaInv0;
    rInertia.m_col1.y = inertiaInv1;
    rInertia.m_col2.z = inertiaInv2;
}

void hkBoxMotion::setInertiaInvLocal(const hkMatrix3& rInertia)
{
    m_inertiaAndMassInv.set(
        rInertia.m_col0.x, rInertia.m_col1.y, rInertia.m_col2.z, m_inertiaAndMassInv.w);
}

void hkBoxMotion::getInertiaInvWorld(hkMatrix3& rInertia) const
{
    const hkRotation& rotation = m_motionState.m_transform.m_rotation;
    const f32 inertiaInv0 = m_inertiaAndMassInv.x;
    const f32 inertiaInv1 = m_inertiaAndMassInv.y;
    const f32 inertiaInv2 = m_inertiaAndMassInv.z;
    hkMatrix3 local;
    local.m_col0.x = inertiaInv0 * rotation.m_col0.x;
    local.m_col0.y = inertiaInv0 * rotation.m_col0.y;
    local.m_col0.z = inertiaInv0 * rotation.m_col0.z;
    local.m_col0.w = inertiaInv0 * rotation.m_col0.w;
    local.m_col1.x = inertiaInv1 * rotation.m_col1.x;
    local.m_col1.y = inertiaInv1 * rotation.m_col1.y;
    local.m_col1.z = inertiaInv1 * rotation.m_col1.z;
    local.m_col1.w = inertiaInv1 * rotation.m_col1.w;
    local.m_col2.x = inertiaInv2 * rotation.m_col2.x;
    local.m_col2.y = inertiaInv2 * rotation.m_col2.y;
    local.m_col2.z = inertiaInv2 * rotation.m_col2.z;
    local.m_col2.w = inertiaInv2 * rotation.m_col2.w;
    rInertia.setMulInverse(local, rotation);
}

void hkBoxMotion::getInertiaWorld(hkMatrix3& rInertia) const
{
    const f32 inertia0 = 1.0f / m_inertiaAndMassInv.x;
    const f32 inertia1 = 1.0f / m_inertiaAndMassInv.y;
    const f32 inertia2 = 1.0f / m_inertiaAndMassInv.z;
    rInertia.setZero();
    rInertia.m_col0.x = inertia0;
    rInertia.m_col1.y = inertia1;
    rInertia.m_col2.z = inertia2;
    rInertia.changeBasis(m_motionState.m_transform.m_rotation);
}

void hkBoxMotion::setMass(f32 mass)
{
    setMassInv(1.0f / mass);
}

#pragma opt_scalarize off
// MATCHING_WORKAROUND: Preserve the original vector stack homes.
void hkBoxMotion::applyAngularImpulse(const hkVector4& impulse)
{
    const hkRotation& rotation = m_motionState.m_transform.m_rotation;
    const f32 impulseY = impulse.y;
    hkVector4 localImpulse;
    localImpulse.x = impulse.x * rotation.getColumn(0).x + impulseY * rotation.getColumn(0).y +
                     impulse.z * rotation.getColumn(0).z;
    localImpulse.y = impulse.x * rotation.getColumn(1).x + impulseY * rotation.getColumn(1).y +
                     impulse.z * rotation.getColumn(1).z;
    localImpulse.z = impulse.x * rotation.getColumn(2).x + impulseY * rotation.getColumn(2).y +
                     impulse.z * rotation.getColumn(2).z;
    localImpulse.w = 0.0f;

    const f32 localX = m_inertiaAndMassInv.x * localImpulse.x;
    const f32 localY = m_inertiaAndMassInv.y * localImpulse.y;
    const f32 localZ = m_inertiaAndMassInv.z * localImpulse.z;

    hkVector4 worldImpulse;
    worldImpulse.x =
        localX * rotation.m_col0.x + localY * rotation.m_col1.x + localZ * rotation.m_col2.x;
    worldImpulse.y =
        localX * rotation.m_col0.y + localY * rotation.m_col1.y + localZ * rotation.m_col2.y;
    worldImpulse.z =
        localX * rotation.m_col0.z + localY * rotation.m_col1.z + localZ * rotation.m_col2.z;
    worldImpulse.w = 0.0f;

    m_angularVelocity.add4(worldImpulse);
}

void hkBoxMotion::applyPointImpulse(const hkVector4& impulse, const hkVector4& point)
{
    const f32 massInv = m_inertiaAndMassInv.w;
    m_linearVelocity.x += massInv * impulse.x;
    m_linearVelocity.y += massInv * impulse.y;
    m_linearVelocity.z += massInv * impulse.z;
    m_linearVelocity.w += massInv * impulse.w;

    const hkVector4& centerOfMass = m_motionState.m_sweptTransform.m_centerOfMass1;
    const f32 armX = point.x - centerOfMass.x;
    const f32 armY = point.y - centerOfMass.y;
    const f32 armZ = point.z - centerOfMass.z;
    hkVector4 angularImpulse;
    angularImpulse.x = armY * impulse.z - armZ * impulse.y;
    angularImpulse.y = armZ * impulse.x - armX * impulse.z;
    angularImpulse.z = armX * impulse.y - armY * impulse.x;
    angularImpulse.w = 0.0f;
    hkBoxMotion::applyAngularImpulse(angularImpulse);
}

#pragma opt_scalarize on
void hkBoxMotion::applyForce(f32 deltaTime, const hkVector4& force)
{
    hkVector4 impulse;
    impulse.x = deltaTime * force.x;
    impulse.y = deltaTime * force.y;
    impulse.z = deltaTime * force.z;
    impulse.w = deltaTime * force.w;
    const f32 massInv = m_inertiaAndMassInv.w;
    m_linearVelocity.x += massInv * impulse.x;
    m_linearVelocity.y += massInv * impulse.y;
    m_linearVelocity.z += massInv * impulse.z;
    m_linearVelocity.w += massInv * impulse.w;
}

void hkBoxMotion::applyForce(f32 deltaTime, const hkVector4& force, const hkVector4& point)
{
    hkVector4 impulse;
    impulse.x = deltaTime * force.x;
    impulse.y = deltaTime * force.y;
    impulse.z = deltaTime * force.z;
    impulse.w = deltaTime * force.w;
    applyPointImpulse(impulse, point);
}

void hkBoxMotion::applyTorque(f32 deltaTime, const hkVector4& torque)
{
    hkVector4 impulse;
    impulse.x = deltaTime * torque.x;
    impulse.y = deltaTime * torque.y;
    impulse.z = deltaTime * torque.z;
    impulse.w = deltaTime * torque.w;
    applyAngularImpulse(impulse);
}
