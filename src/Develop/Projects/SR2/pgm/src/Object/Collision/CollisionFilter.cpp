#include "Develop/Projects/SR2/pgm/src/Object/Collision/CollisionFilter.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

s32 clsCollisionFilter::m_s32AllNum;
s32 clsCollisionFilter::m_s32TrueNum;

hkBool clsCollisionFilter::isCollisionEnabled(const hkWorldRayCastInput& rcParam1,
                                              const hkCollidable& rcParam2) const
{
    return hkBool();
}

hkBool clsCollisionFilter::isCollisionEnabled(const hkShapeRayCastInput& rcParam1,
                                              const hkShape& rcParam2,
                                              const hkShapeContainer& rcParam3,
                                              u32 u32Param4) const
{
    return hkBool();
}

hkBool clsCollisionFilter::isCollisionEnabled(const hkCollisionInput& rcParam1,
                                              const hkCdBody& rcParam2,
                                              const hkCdBody& rcParam3,
                                              const hkShapeContainer& rcParam4,
                                              u32 u32Param5) const
{
    return hkBool();
}

hkBool clsCollisionFilter::isCollisionEnabled(const hkCollidable& rcParam1,
                                              const hkCollidable& rcParam2) const
{
    return hkBool();
}

clsCollisionFilter::~clsCollisionFilter()
{
}
