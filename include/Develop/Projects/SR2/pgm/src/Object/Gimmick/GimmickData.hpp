#ifndef GIMMICKDATA_HPP
#define GIMMICKDATA_HPP

#include "types.h"

// total size: 0x8
struct stcGimmick {
    u32 u32DisableClip;    // offset 0x0, size 0x4
    u8 u8ParticleBreakNum; // offset 0x4, size 0x1
};

#endif // GIMMICKDATA_HPP
