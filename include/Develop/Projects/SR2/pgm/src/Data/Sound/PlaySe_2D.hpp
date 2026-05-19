#ifndef PLAYSE_2D_HPP
#define PLAYSE_2D_HPP

#include "types.h"

// total size: 0x8
class clsPlaySe_2D {
public:
    ~clsPlaySe_2D() {}

    u8 isPlay();
    void play();
    void stop();
    void setVolume(u32 u32VolI);

    s32 m_s32SeId;          // offset 0x0, size 0x4
    u8 m_bIsPlayWait;       // offset 0x4, size 0x1
    u8 m_u8PlayWaitTimeOut; // offset 0x5, size 0x1
};

#endif // PLAYSE_2D_HPP
