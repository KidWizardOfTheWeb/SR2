#ifndef DEBUGMINIWAVE_HPP
#define DEBUGMINIWAVE_HPP

#include "types.h"

// total size: 0x2C
struct stcDebugMiniWave {
    u8 bEnableMiniWaveDebug; // offset 0x0, size 0x1
    u8 bAlwaysEnable;        // offset 0x1, size 0x1
    u8 bDispDebugLine;       // offset 0x2, size 0x1
    u8 bDispDebugMessage;    // offset 0x3, size 0x1
    f32 f32UVSpeed;          // offset 0x4, size 0x4
    f32 f32StartWidth;       // offset 0x8, size 0x4
    f32 f32EndWidth;         // offset 0xC, size 0x4
    f32 f32MaxWidth;         // offset 0x10, size 0x4
    f32 f32BackLength;       // offset 0x14, size 0x4
    f32 f32ReviseValIn;      // offset 0x18, size 0x4
    f32 f32ReviseValOut;     // offset 0x1C, size 0x4
    f32 f32InclinationAngle; // offset 0x20, size 0x4
    f32 f32CurveMax;         // offset 0x24, size 0x4
    s32 s32CurveTiming;      // offset 0x28, size 0x4
};

#endif // DEBUGMINIWAVE_HPP
