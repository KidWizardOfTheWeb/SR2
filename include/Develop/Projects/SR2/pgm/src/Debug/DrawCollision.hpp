#ifndef DRAWCOLLISION_HPP
#define DRAWCOLLISION_HPP

#include "types.h"

// total size: 0x5
struct stcDrawCollision {
    u8 u8DrawPhantom;     // offset 0x0, size 0x1
    u8 u8DrawGimmick;     // offset 0x1, size 0x1
    u8 u8DrawMap;         // offset 0x2, size 0x1
    u8 u8DrawThrough;     // offset 0x3, size 0x1
    u8 u8DrawSetCamColli; // offset 0x4, size 0x1
};

#endif // DRAWCOLLISION_HPP
