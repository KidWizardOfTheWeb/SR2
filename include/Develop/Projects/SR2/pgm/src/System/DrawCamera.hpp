#ifndef DRAWCAMERA_HPP
#define DRAWCAMERA_HPP

#include "types.h"

// total size: 0x6
struct stcDrawCamera {
    u8 u8DrawCamNo;       // offset 0x0, size 0x1
    u8 au8DrawCamData[5]; // offset 0x1, size 0x5
};

#endif // DRAWCAMERA_HPP
