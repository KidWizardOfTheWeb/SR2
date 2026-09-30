#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

void hkSphereMotion::getInertiaLocal(hkMatrix3& rInertia) const
{
    const f32 inertia = 1.0f / m_inertiaAndMassInv.x;
    rInertia.setZero();
    rInertia.m_col0.x = inertia;
    rInertia.m_col1.y = inertia;
    rInertia.m_col2.z = inertia;
}

void hkSphereMotion::getInertiaWorld(hkMatrix3& rInertia) const
{
    const f32 inertia = 1.0f / m_inertiaAndMassInv.x;
    rInertia.setZero();
    rInertia.m_col0.x = inertia;
    rInertia.m_col1.y = inertia;
    rInertia.m_col2.z = inertia;
}

void hkSphereMotion::setInertiaLocal(const hkMatrix3& rInertia)
{
    const f32 inertia1 = rInertia.m_col1.y;
    const f32 inertia0 = rInertia.m_col0.x;
    const f32 inertia2 = rInertia.m_col2.z;
    f32 inertia = (inertia0 > inertia1) ? inertia0 : inertia1;
    inertia = (inertia > inertia2) ? inertia : inertia2;

    const f32 inertiaInv = (inertia > 0.0f) ? (1.0f / inertia) : 0.0f;
    m_inertiaAndMassInv.x = inertiaInv;
    m_inertiaAndMassInv.y = inertiaInv;
    m_inertiaAndMassInv.z = inertiaInv;
}

void hkSphereMotion::setInertiaInvLocal(const hkMatrix3& rInertia)
{
    const f32 inertiaInv1 = rInertia.m_col1.y;
    const f32 inertiaInv0 = rInertia.m_col0.x;
    const f32 inertiaInv2 = rInertia.m_col2.z;
    f32 inertiaInv = (inertiaInv0 < inertiaInv1) ? inertiaInv0 : inertiaInv1;
    inertiaInv = (inertiaInv < inertiaInv2) ? inertiaInv : inertiaInv2;
    m_inertiaAndMassInv.x = inertiaInv;
    m_inertiaAndMassInv.y = inertiaInv;
    m_inertiaAndMassInv.z = inertiaInv;
}

void hkSphereMotion::getInertiaInvLocal(hkMatrix3& rInertia) const
{
    const f32 inertiaInv = m_inertiaAndMassInv.x;
    rInertia.setZero();
    rInertia.m_col0.x = inertiaInv;
    rInertia.m_col1.y = inertiaInv;
    rInertia.m_col2.z = inertiaInv;
}

void hkSphereMotion::getInertiaInvWorld(hkMatrix3& rInertia) const
{
    const f32 inertiaInv = m_inertiaAndMassInv.x;
    rInertia.setZero();
    rInertia.m_col0.x = inertiaInv;
    rInertia.m_col1.y = inertiaInv;
    rInertia.m_col2.z = inertiaInv;
}

void hkSphereMotion::applyPointImpulse(const hkVector4& impulse, const hkVector4& point)
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
    hkSphereMotion::applyAngularImpulse(angularImpulse);
}

void hkSphereMotion::applyAngularImpulse(const hkVector4& impulse)
{
    m_angularVelocity.x += m_inertiaAndMassInv.x * impulse.x;
    m_angularVelocity.y += m_inertiaAndMassInv.y * impulse.y;
    m_angularVelocity.z += m_inertiaAndMassInv.z * impulse.z;
    m_angularVelocity.w += m_inertiaAndMassInv.w * impulse.w;
}

void hkSphereMotion::applyForce(f32 deltaTime, const hkVector4& force)
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

void hkSphereMotion::applyForce(f32 deltaTime, const hkVector4& force, const hkVector4& point)
{
    hkVector4 impulse;
    impulse.x = deltaTime * force.x;
    impulse.y = deltaTime * force.y;
    impulse.z = deltaTime * force.z;
    impulse.w = deltaTime * force.w;
    applyPointImpulse(impulse, point);
}

void hkSphereMotion::applyTorque(f32 deltaTime, const hkVector4& torque)
{
    hkVector4 impulse;
    impulse.x = deltaTime * torque.x;
    impulse.y = deltaTime * torque.y;
    impulse.z = deltaTime * torque.z;
    impulse.w = deltaTime * torque.w;
    applyAngularImpulse(impulse);
}
