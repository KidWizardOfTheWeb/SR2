#ifndef SCISSORRECT_HPP
#define SCISSORRECT_HPP

#include "types.h"

// total size: 0x10
struct stcScissorRect {
    u32 u32OffsetX; // offset 0x0, size 0x4
    u32 u32OffsetY; // offset 0x4, size 0x4
    u32 u32Right;   // offset 0x8, size 0x4
    u32 u32Bottom;  // offset 0xC, size 0x4
};

#endif // SCISSORRECT_HPP
