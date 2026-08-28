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
        TYPE_NULL = 0,
        TYPE_GROUND = 1,
        TYPE_THROUGH = 2,
        TYPE_PLAYER = 4,
        TYPE_ITEM = 8,
        TYPE_RING = 16,
        TYPE_GIMMICK = 32,
        TYPE_GIMMICK_WALL = 64,
        TYPE_GIMMICK_CLOG = 128,
        TYPE_GRAVITY = 256,
        TYPE_GLINK = 512,
        TYPE_WALL_WALK = 1024,
        TYPE_WALL_GRAVITY = 2048,
        TYPE_DEAD = 4096,
        FILTER_NULL = 0,
        FILTER_GROUND = 65536,
        FILTER_THROUGH = 131072,
        FILTER_PLAYER = 262144,
        FILTER_ITEM = 524288,
        FILTER_RING = 1048576,
        FILTER_GIMMICK = 2097152,
        FILTER_GIMMICK_WALL = 4194304,
        FILTER_GIMMICK_CLOG = 8388608,
        FILTER_GRAVITY = 16777216,
        FILTER_GLINK = 33554432,
        FILTER_WALL_GRAVITY = 134217728,
        FILTER_WALL_WALK = 67108864,
        FILTER_DEAD = 268435456,
        TYPE_MASK = 65535,
        FILTER_MASK = -65536,
        FULL_MASK = -1,
        CLEAR_MASK = 0,
        TYPE_GIMMICK_MASK = 33554728,
        DEFAULT_PLAYER = 352256004,
        DEFAULT_COM = 352256004,
        CLIP_COM = 342294532,
        DEFAULT_GROUND = 1,
        DEFAULT_THROUGH = 262146,
        SAME_NONHIT_GIMMICK = 16842784,
        DEFAULT_GIMMICK = 14745632,
        DEFAULT_GIMMICK_WALL = 14745664,
        DEFAULT_GIMMICK_CLOG = 14745728,
        DEFAULT_GRAVITY_GIMMICK = 18939936,
        DEFAULT_GLINK_GIMMICK = 35717632,
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
