#ifndef DATASIZE_HPP
#define DATASIZE_HPP

#include "types.h"

// total size: 0x18
struct stcDataSize {
    s32 s32StagePack;    // offset 0x0, size 0x4
    s32 s32MapAll;       // offset 0x4, size 0x4
    s32 s32MapTexture;   // offset 0x8, size 0x4
    s32 s32PlayerData;   // offset 0xC, size 0x4
    s32 s32PlayerMotion; // offset 0x10, size 0x4
    s32 s32GearData;     // offset 0x14, size 0x4
};

#endif // DATASIZE_HPP
