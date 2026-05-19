#ifndef DRAWINFODATA_HPP
#define DRAWINFODATA_HPP

#include "types.h"

// total size: 0x38
struct stcDrawInfoData {
    s16 s16NameX;          // offset 0x0, size 0x2
    s16 s16NameY;          // offset 0x2, size 0x2
    s16 s16UserX;          // offset 0x4, size 0x2
    s16 s16UserY;          // offset 0x6, size 0x2
    s16 s16UserIconX;      // offset 0x8, size 0x2
    s16 s16UserIconY;      // offset 0xA, size 0x2
    s16 s16UserIconW;      // offset 0xC, size 0x2
    s16 s16UserIconH;      // offset 0xE, size 0x2
    s16 s16GearX;          // offset 0x10, size 0x2
    s16 s16GearY;          // offset 0x12, size 0x2
    s16 s16GearW;          // offset 0x14, size 0x2
    s16 s16GearH;          // offset 0x16, size 0x2
    s16 s16RingX;          // offset 0x18, size 0x2
    s16 s16RingY;          // offset 0x1A, size 0x2
    s16 s16PartsX;         // offset 0x1C, size 0x2
    s16 s16PartsY;         // offset 0x1E, size 0x2
    s16 s16PartsIconX;     // offset 0x20, size 0x2
    s16 s16DetailX;        // offset 0x22, size 0x2
    s16 s16DetailY;        // offset 0x24, size 0x2
    s16 s16DetailW;        // offset 0x26, size 0x2
    s16 s16DetailH;        // offset 0x28, size 0x2
    s16 s16DetailWindowX;  // offset 0x2A, size 0x2
    s16 s16StatusX;        // offset 0x2C, size 0x2
    s16 s16StatusY;        // offset 0x2E, size 0x2
    s16 s16StatusW;        // offset 0x30, size 0x2
    s16 s16StatusH;        // offset 0x32, size 0x2
    s16 s16StatusInterval; // offset 0x34, size 0x2
    u8 u8ItemNextX;        // offset 0x36, size 0x1
    u8 u8ItemNextY;        // offset 0x37, size 0x1
};

#endif // DRAWINFODATA_HPP
