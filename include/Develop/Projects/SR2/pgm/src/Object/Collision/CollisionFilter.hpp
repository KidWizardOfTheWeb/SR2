#ifndef COLLISIONFILTER_HPP
#define COLLISIONFILTER_HPP

#include "types.h"

class hkBool;
class hkCdBody;
class hkCollidable;
class hkCollisionInput;
class hkShape;
class hkShapeContainer;
class hkShapeRayCastInput;
class hkWorldRayCastInput;

class clsCollisionFilter {
public:
    enum enmInfo {
        INFO_NONE = 0,
    };

    virtual ~clsCollisionFilter();
    virtual hkBool isCollisionEnabled(const hkCollidable& rcParam1,
                                      const hkCollidable& rcParam2) const;
    virtual hkBool isCollisionEnabled(const hkCollisionInput& rcParam1,
                                      const hkCdBody& rcParam2,
                                      const hkCdBody& rcParam3,
                                      const hkShapeContainer& rcParam4,
                                      u32 u32Param5) const;
    virtual hkBool isCollisionEnabled(const hkShapeRayCastInput& rcParam1,
                                      const hkShape& rcParam2,
                                      const hkShapeContainer& rcParam3,
                                      u32 u32Param4) const;
    virtual hkBool isCollisionEnabled(const hkWorldRayCastInput& rcParam1,
                                      const hkCollidable& rcParam2) const;

    static s32 m_s32AllNum;
    static s32 m_s32TrueNum;
};

#endif // COLLISIONFILTER_HPP
