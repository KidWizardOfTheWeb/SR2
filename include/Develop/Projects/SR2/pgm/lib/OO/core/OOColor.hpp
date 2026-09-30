#ifndef OOCOLOR_HPP
#define OOCOLOR_HPP

#include "types.h"

// total size: 0xC
struct stcRgbF32 {
    f32 f32r; // offset 0x0, size 0x4
    f32 f32g; // offset 0x4, size 0x4
    f32 f32b; // offset 0x8, size 0x4
};

// total size: 0x10
struct stcRgbaF32 {
    f32 f32r; // offset 0x0, size 0x4
    f32 f32g; // offset 0x4, size 0x4
    f32 f32b; // offset 0x8, size 0x4
    f32 f32a; // offset 0xC, size 0x4
};

#endif // OOCOLOR_HPP
