#ifndef EGGDETAIL_HPP
#define EGGDETAIL_HPP

#include "types.h"

// total size: 0x10
struct stcEggDetail {
    f32 f32LifeFrame; // offset 0x0, size 0x4
    u16 u16x;         // offset 0x4, size 0x2
    u16 u16y;         // offset 0x6, size 0x2
    u8 u8Size;        // offset 0x8, size 0x1
    u8 u8ColorNo;     // offset 0x9, size 0x1
    s8 s8Uv;          // offset 0xA, size 0x1
    u8 u8ViewportNo;  // offset 0xB, size 0x1
    u16 s16Alpha;     // offset 0xC, size 0x2
    s16 s16Rot;       // offset 0xE, size 0x2
};

#endif // EGGDETAIL_HPP
