#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

hkMotion::hkMotion(const hkVector4& rParam1, const hkQuaternion& rParam2, bool bParam3)
{
    m_linearVelocity.x = m_linearVelocity.y = m_linearVelocity.z = m_linearVelocity.w = 0.0f;
    m_angularVelocity.x = m_angularVelocity.y = m_angularVelocity.z = m_angularVelocity.w = 0.0f;

    m_motionState.initMotionState(rParam1, rParam2);
    m_motionState.m_linearDamping = 0.0f;
    m_motionState.m_angularDamping = 0.0f;
    m_type = MOTION_INVALID;

    if (bParam3) {
        m_deactivationIntegrateCounter = static_cast<u8>(static_cast<s32>(rParam1.x) & 0xf);
    } else {
        m_deactivationIntegrateCounter = 0xff;
    }
    m_deactivationNumInactiveFrames[0] = 0;
    m_deactivationNumInactiveFrames[1] = 0;

    m_deactivationRefPosition[0].x = m_deactivationRefPosition[0].y =
        m_deactivationRefPosition[0].z = m_deactivationRefPosition[0].w = 0.0f;
    m_deactivationRefPosition[1].x = m_deactivationRefPosition[1].y =
        m_deactivationRefPosition[1].z = m_deactivationRefPosition[1].w = 0.0f;
    m_motionState.m_deactivationRefOrientation[0] = 0;
    m_motionState.m_deactivationRefOrientation[1] = 0;
}

void hkMotion::setMass(f32 f32Param1)
{
    f32 f32MassInv = (f32Param1 == 0.0f) ? 0.0f : (1.0f / f32Param1);
    setMassInv(f32MassInv);
}

f32 hkMotion::getMass() const
{
    if (m_inertiaAndMassInv.w == 0.0f) {
        return 0.0f;
    }
    return 1.0f / m_inertiaAndMassInv.w;
}

void hkMotion::setMassInv(f32 f32Param1)
{
    m_inertiaAndMassInv.w = f32Param1;
}

void hkMotion::setCenterOfMassInLocal(const hkVector4& rParam1)
{
    hkSweptTransformUtil::setCentreOfRotationLocal(rParam1, m_motionState);
}

void hkMotion::setPosition(const hkVector4& rParam1)
{
    hkSweptTransformUtil::warpToPosition(rParam1, m_motionState);
}

void hkMotion::setRotation(const hkQuaternion& rParam1)
{
    hkSweptTransformUtil::warpToRotation(rParam1, m_motionState);
}

void hkMotion::setPositionAndRotation(const hkVector4& rParam1, const hkQuaternion& rParam2)
{
    hkSweptTransformUtil::warpTo(rParam1, rParam2, m_motionState);
}

void hkMotion::setTransform(const hkTransform& rParam1)
{
    hkSweptTransformUtil::warpTo(rParam1, m_motionState);
}

void hkMotion::setLinearVelocity(const hkVector4& rParam1)
{
    m_linearVelocity = rParam1;
}

void hkMotion::setAngularVelocity(const hkVector4& rParam1)
{
    m_angularVelocity = rParam1;
}

void hkMotion::applyLinearImpulse(const hkVector4& rParam1)
{
    f32 f32MassInv = m_inertiaAndMassInv.w;
    m_linearVelocity.x += f32MassInv * rParam1.x;
    m_linearVelocity.y += f32MassInv * rParam1.y;
    m_linearVelocity.z += f32MassInv * rParam1.z;
    m_linearVelocity.w += f32MassInv * rParam1.w;
}

void hkMotion::getMotionStateAndVelocitiesAndDeactivationType(hkMotion* pParam1)
{
    pParam1->m_motionState = m_motionState;
    pParam1->m_linearVelocity = m_linearVelocity;
    pParam1->m_angularVelocity = m_angularVelocity;
    pParam1->m_deactivationIntegrateCounter = m_deactivationIntegrateCounter;
}

void hkMotion::setDeactivationClass(s32 s32Param1)
{
    m_motionState.m_deactivationClass = static_cast<u16>(s32Param1);
}
