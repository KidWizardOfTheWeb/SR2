#ifndef TURBULENCEDBG_HPP
#define TURBULENCEDBG_HPP

#include "types.h"

// total size: 0x5
struct stcTurbulenceDbg {
    u8 u8DrawFlg;       // offset 0x0, size 0x1
    u8 u8DrawIdx;       // offset 0x1, size 0x1
    u8 u8NoDead;        // offset 0x2, size 0x1
    u8 u8DrawTrickLine; // offset 0x3, size 0x1
    u8 u8Disable;       // offset 0x4, size 0x1
};

#endif // TURBULENCEDBG_HPP
