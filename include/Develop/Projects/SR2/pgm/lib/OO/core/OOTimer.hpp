#ifndef OOTIMER_HPP
#define OOTIMER_HPP

#include "types.h"

// total size: 0x2C
class clsOOTimer {
public:
    virtual ~clsOOTimer() {}
    virtual s32 getTick() const { return 0; }
    virtual s32 TickDiff2MicroSec(s32 s32Tick) const;
    virtual s32 TickDiff2MicroSec(s32 s32TickA, s32 s32TickB) const { return 0; }

    static clsOOTimer* t_cInstance;

    s32 m_s32CpuMicroSec;       // offset 0x4, size 0x4
    s32 m_s32GpuMicroSec;       // offset 0x8, size 0x4
    s32 m_s32BeginCpuTick;      // offset 0xC, size 0x4
    s32 m_s32EndCpuDiffTick;    // offset 0x10, size 0x4
    s32 m_s32BeginGpuTick;      // offset 0x14, size 0x4
    s32 m_s32EndGpuDiffTick;    // offset 0x18, size 0x4
    u32 m_u32CpuAverage;        // offset 0x1C, size 0x4
    u32 m_u32GpuAverage;        // offset 0x20, size 0x4
    u32 m_u32AverageCnt;        // offset 0x24, size 0x4
    u32 m_u32AverageClearFrame; // offset 0x28, size 0x4
};

#endif // OOTIMER_HPP
