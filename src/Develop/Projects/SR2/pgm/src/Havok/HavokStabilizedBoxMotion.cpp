#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

hkStabilizedBoxMotion::hkStabilizedBoxMotion(const hkVector4& rPosition,
                                             const hkQuaternion& rRotation)
    : hkBoxMotion(rPosition, rRotation)
{
    m_type = MOTION_BOX_STABILIZED;
}
