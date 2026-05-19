#ifndef FOG_HPP
#define FOG_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptLight.hpp"

// total size: 0x24
struct stcFog {
    u8 bUsed;         // offset 0x0, size 0x1
    u8 bSwitch;       // offset 0x1, size 0x1
    stcRgbF32 sColor; // offset 0x4, size 0xC
    u32 u32Type;      // offset 0x10, size 0x4
    f32 f32Near;      // offset 0x14, size 0x4
    f32 f32Far;       // offset 0x18, size 0x4
    f32 f32Min;       // offset 0x1C, size 0x4
    f32 f32Max;       // offset 0x20, size 0x4
};

#endif // FOG_HPP
