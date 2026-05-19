#ifndef WAVE_HPP
#define WAVE_HPP

#include "types.h"

// total size: 0x10
struct stcWave {
    u8 bUsed;         // offset 0x0, size 0x1
    u8 bEnd;          // offset 0x1, size 0x1
    u32 u32Pri;       // offset 0x4, size 0x4
    f32 f32Frame;     // offset 0x8, size 0x4
    f32 f32WaitFrame; // offset 0xC, size 0x4
};

#endif // WAVE_HPP
