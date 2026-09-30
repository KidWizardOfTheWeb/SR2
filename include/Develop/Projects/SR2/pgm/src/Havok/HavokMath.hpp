#ifndef HAVOK_MATH_HPP
#define HAVOK_MATH_HPP

#include "types.h"

class hkMath {
public:
    static f32 hkFloor(f32 v);
    static s32 hkFloorToInt(f32 v);
    static s32 hkFloatToInt(f32 v);
    static bool isNegative(f32 v);

    // MATCHING_WORKAROUND: Preserve PS2 math scheduling.
    static f32 sqrt(f32 value)
    {
        f32 result;
        asm volatile("sqrt.s %0, %1" : "=f"(result) : "f"(value));
        return result;
    }

    static f32 sqrtInverse(f32 value)
    {
        f32 result;
        asm volatile("rsqrt.s %0, %1, %2" : "=f"(result) : "f"(1.0f), "f"(value));
        return result;
    }

    static f32 fabs(f32 value)
    {
        f32 result;
        asm volatile("abs.s %0, %1" : "=f"(result) : "f"(value));
        return result;
    }
};

#endif // HAVOK_MATH_HPP
