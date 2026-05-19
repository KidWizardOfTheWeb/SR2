#ifndef SEINFO_HPP
#define SEINFO_HPP

#include "types.h"

// total size: 0x8
struct stcSeInfo {
    u32 u32SndId; // offset 0x0, size 0x4
    u8 u8Stop;    // offset 0x4, size 0x1
    u8 u8Padd[3]; // offset 0x5, size 0x3
};

#endif // SEINFO_HPP
