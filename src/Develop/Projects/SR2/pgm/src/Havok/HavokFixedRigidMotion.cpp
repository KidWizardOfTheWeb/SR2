#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

hkFixedRigidMotion::hkFixedRigidMotion(const hkVector4& rPosition, const hkQuaternion& rRotation)
    : hkKeyframedRigidMotion(rPosition, rRotation)
{
    m_type = MOTION_FIXED;
}

void hkFixedRigidMotion::setStepPosition(f32 f32Param1, f32 f32Param2)
{
}

void hkFixedRigidMotion::getPositionAndVelocities(hkMotion* pMotion)
{
    pMotion->m_motionState = m_motionState;
    pMotion->m_linearVelocity.x = pMotion->m_linearVelocity.y = pMotion->m_linearVelocity.z =
        pMotion->m_linearVelocity.w = 0.0f;
    pMotion->m_angularVelocity.x = pMotion->m_angularVelocity.y = pMotion->m_angularVelocity.z =
        pMotion->m_angularVelocity.w = 0.0f;
}
