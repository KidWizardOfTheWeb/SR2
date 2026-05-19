#ifndef BLUR_HPP
#define BLUR_HPP

#include "types.h"

// total size: 0x20
// Note: A second stcBlur variant (0x1C) exists in DWARF — likely nested in a specific class.
struct stcBlur {
    u8 bUsed;         // offset 0x0, size 0x1
    u8 bEnd;          // offset 0x1, size 0x1
    u8 u8Type;        // offset 0x2, size 0x1
    u8 u8Alpha;       // offset 0x3, size 0x1
    u8 u8SAlpha;      // offset 0x4, size 0x1
    u8 u8EAlpha;      // offset 0x5, size 0x1
    s16 s16EndFrame;  // offset 0x6, size 0x2
    f32 f32Per;       // offset 0x8, size 0x4
    f32 f32SPer;      // offset 0xC, size 0x4
    f32 f32EPer;      // offset 0x10, size 0x4
    f32 f32GFrame;    // offset 0x14, size 0x4
    f32 f32WaitFrame; // offset 0x18, size 0x4
    f32 f32FadeFrame; // offset 0x1C, size 0x4
};

#endif // BLUR_HPP
