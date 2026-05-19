#ifndef FADE_HPP
#define FADE_HPP

#include "types.h"

// total size: 0x14
struct stcFade {
    u16 u16Flg;       // offset 0x0, size 0x2
    u16 u16View;      // offset 0x2, size 0x2
    f32 f32EndFrame;  // offset 0x4, size 0x4
    u32 u32Type;      // offset 0x8, size 0x4
    u32 u32Color;     // offset 0xC, size 0x4
    f32 f32WaitFrame; // offset 0x10, size 0x4
};

#endif // FADE_HPP
