#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

// RECONSTRUCTED: source ownership.

hkSpatialRigidBodyDeactivator::hkSpatialRigidBodyDeactivator()
{
    static const f32 HK_REAL_MAX = 3.40282e38f;
    m_highFrequencyReferencePosition.x = HK_REAL_MAX;
    m_highFrequencyReferencePosition.y = HK_REAL_MAX;
    m_highFrequencyReferencePosition.z = HK_REAL_MAX;
    m_highFrequencyReferencePosition.w = HK_REAL_MAX;
    m_highFrequencyReferenceRotation.m_vec.x = 0.0f;
    m_highFrequencyReferenceRotation.m_vec.y = 0.0f;
    m_highFrequencyReferenceRotation.m_vec.z = 0.0f;
    m_highFrequencyReferenceRotation.m_vec.w = 1.0f;
    m_lowFrequencyReferencePosition.x = HK_REAL_MAX;
    m_lowFrequencyReferencePosition.y = HK_REAL_MAX;
    m_lowFrequencyReferencePosition.z = HK_REAL_MAX;
    m_lowFrequencyReferencePosition.w = HK_REAL_MAX;
    m_lowFrequencyReferenceRotation.m_vec.x = 0.0f;
    m_lowFrequencyReferenceRotation.m_vec.y = 0.0f;
    m_lowFrequencyReferenceRotation.m_vec.z = 0.0f;
    m_lowFrequencyReferenceRotation.m_vec.w = 1.0f;
    m_referenceRadius = -1.0f;
    m_highFrequencyLinearThreshold = 0.01f;
    m_highFrequencyAngularThreshold = 0.005f;
    m_lowFrequencyLinearThreshold = 0.1f;
    m_lowFrequencyAngularThreshold = 0.2f;
}
