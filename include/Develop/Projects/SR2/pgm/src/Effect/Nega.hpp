#ifndef NEGA_HPP
#define NEGA_HPP

#include "types.h"

// total size: 0x18
struct stcNega {
    f32 f32Frame;     // offset 0x0, size 0x4
    f32 f32SubFrame;  // offset 0x4, size 0x4
    f32 f32EndFrame;  // offset 0x8, size 0x4
    f32 f32WaitFrame; // offset 0xC, size 0x4
    u8 bUsed;         // offset 0x10, size 0x1
    u8 bEnd;          // offset 0x11, size 0x1
    u8 u8Pri;         // offset 0x12, size 0x1
    u8 u8Type;        // offset 0x13, size 0x1
    u8 u8rgb;         // offset 0x14, size 0x1
    s16 s16EndFrame;  // offset 0x16, size 0x2
};

// total size: 0x8
struct stcNegaZ {
    s32 s32z;   // offset 0x0, size 0x4
    u8 u8ColNo; // offset 0x4, size 0x1
    u8 u8r;     // offset 0x5, size 0x1
    u8 u8g;     // offset 0x6, size 0x1
    u8 u8b;     // offset 0x7, size 0x1
};

#endif // NEGA_HPP
