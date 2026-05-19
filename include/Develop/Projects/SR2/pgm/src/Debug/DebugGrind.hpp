#ifndef DEBUGGRIND_HPP
#define DEBUGGRIND_HPP

#include "types.h"

// total size: 0x10
struct stcDebugGrind {
    u8 bEnableGrindDebug;    // offset 0x0, size 0x1
    f32 f32GrindSpeed;       // offset 0x4, size 0x4
    f32 f32GrindAcceleFrame; // offset 0x8, size 0x4
    s32 s32PathRate;         // offset 0xC, size 0x4
};

#endif // DEBUGGRIND_HPP
