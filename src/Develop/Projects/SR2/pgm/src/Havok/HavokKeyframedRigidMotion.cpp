#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

hkKeyframedRigidMotion::hkKeyframedRigidMotion(const hkVector4& rParam1,
                                               const hkQuaternion& rParam2)
    : hkMotion(rParam1, rParam2, false)
{
    m_savedMotion = NULL;
    m_savedQualityTypeIndex = 0;
    m_inertiaAndMassInv.x = m_inertiaAndMassInv.y = m_inertiaAndMassInv.z = m_inertiaAndMassInv.w =
        0.0f;
    m_type = MOTION_KEYFRAMED;
}

hkKeyframedRigidMotion::~hkKeyframedRigidMotion()
{
    if (m_savedMotion != NULL) {
        m_savedMotion->removeReference();
    }
}

void hkKeyframedRigidMotion::setMass(f32 f32Param1)
{
}

void hkKeyframedRigidMotion::setMassInv(f32 f32Param1)
{
}

void hkKeyframedRigidMotion::getInertiaLocal(hkMatrix3& rParam1) const
{
    rParam1.setZero();
}

void hkKeyframedRigidMotion::getInertiaWorld(hkMatrix3& rParam1) const
{
    rParam1.setZero();
}

void hkKeyframedRigidMotion::setInertiaLocal(const hkMatrix3& rParam1)
{
}

void hkKeyframedRigidMotion::setInertiaInvLocal(const hkMatrix3& rParam1)
{
}

void hkKeyframedRigidMotion::getInertiaInvLocal(hkMatrix3& rParam1) const
{
    rParam1.setZero();
}

void hkKeyframedRigidMotion::getInertiaInvWorld(hkMatrix3& rParam1) const
{
    rParam1.setZero();
}

void hkKeyframedRigidMotion::applyLinearImpulse(const hkVector4& rParam1)
{
}

void hkKeyframedRigidMotion::applyPointImpulse(const hkVector4& rParam1, const hkVector4& rParam2)
{
}

void hkKeyframedRigidMotion::applyAngularImpulse(const hkVector4& rParam1)
{
}

void hkKeyframedRigidMotion::applyForce(f32 f32Param1, const hkVector4& rParam2)
{
}

void hkKeyframedRigidMotion::applyForce(f32 f32Param1,
                                        const hkVector4& rParam2,
                                        const hkVector4& rParam3)
{
}

void hkKeyframedRigidMotion::applyTorque(f32 f32Param1, const hkVector4& rParam2)
{
}

void hkKeyframedRigidMotion::setStepPosition(f32 f32Param1, f32 f32Param2)
{
}

void hkKeyframedRigidMotion::setStoredMotion(hkMaxSizeMotion* pParam1)
{
    if (pParam1 != NULL) {
        pParam1->addReference();
    }
    if (m_savedMotion != NULL) {
        m_savedMotion->removeReference();
    }
    m_savedMotion = pParam1;
}

f32 hkKeyframedRigidMotion::getWeight() const
{
    if (m_savedMotion != NULL) {
        return m_savedMotion->getMass();
    }
    return getMass();
}
