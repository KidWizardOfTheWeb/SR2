#ifndef NEARDATA_HPP
#define NEARDATA_HPP

#include "types.h"

enum enmState {
    STATE_MAIN = 0,
    STATE_ACTION = 1,
    STATE_WAIT = 2,
    STATE_STOP = 3,
};

// total size: 0x34
struct stcNearData {
    enmState eState;    // offset 0x0, size 0x4
    f32 f32Near;        // offset 0x4, size 0x4
    f32 f32Far;         // offset 0x8, size 0x4
    f32 f32DefNear;     // offset 0xC, size 0x4
    f32 f32DefFar;      // offset 0x10, size 0x4
    f32 f32r;           // offset 0x14, size 0x4
    f32 f32g;           // offset 0x18, size 0x4
    f32 f32b;           // offset 0x1C, size 0x4
    f32 f32Defr;        // offset 0x20, size 0x4
    f32 f32Defg;        // offset 0x24, size 0x4
    f32 f32Defb;        // offset 0x28, size 0x4
    f32 f32Frame;       // offset 0x2C, size 0x4
    u16 u16IsRequest;   // offset 0x30, size 0x2
    u16 u16BackUpFogNo; // offset 0x32, size 0x2
};

#endif // NEARDATA_HPP
