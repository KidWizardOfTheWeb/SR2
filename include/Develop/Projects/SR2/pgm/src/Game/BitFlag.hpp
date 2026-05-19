#ifndef BITFLAG_HPP
#define BITFLAG_HPP

#include "types.h"

// total size: 0x4
struct stcBitFlag {
    u32 bEnableDrawOrigin : 1;         // offset 0x0
    u32 bDisableGravWave : 1;          // offset 0x0
    u32 bDisableDrawMap : 1;           // offset 0x0
    u32 bDisableDrawSky : 1;           // offset 0x0
    u32 bDisableDrawRing : 1;          // offset 0x0
    u32 bDisableDrawStGate : 1;        // offset 0x0
    u32 bDisableDrawSunLenz : 1;       // offset 0x0
    u32 bDisableDrawWeather : 1;       // offset 0x0
    u32 bDisablePortal : 1;            // offset 0x0
    u32 bDisableChangeDebugCamera : 1; // offset 0x0
    u32 bEnableGCtrlCamZRot : 1;       // offset 0x0
    u32 bDisableFastShader_PS2 : 1;    // offset 0x0
    u32 bEnableBaseEffect : 1;         // offset 0x0
    u32 bEnableReplayCamera : 1;       // offset 0x0
};

#endif // BITFLAG_HPP
