#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

hkThinBoxMotion::hkThinBoxMotion(const hkVector4& rPosition, const hkQuaternion& rRotation)
    : hkBoxMotion(rPosition, rRotation)
{
    m_type = MOTION_THIN_BOX_INERTIA;
}
