#ifndef LIMITTIME_HPP
#define LIMITTIME_HPP

#include "types.h"

struct stcRateTime {
    s32 s32Sec;         // offset 0x0, size 0x4
    s32 s32PassageSec;  // offset 0x4, size 0x4
    f32 f32MSec;        // offset 0x8, size 0x4
    f32 f32PassageMSec; // offset 0xC, size 0x4
};

class clsLimitTime {
public:
    clsLimitTime(f32 f32Param1 = 0.0f) {}
    u8 update();

    stcRateTime m_sRateTime; // offset 0x0, size 0x10
    f32 m_f32LimitTime;      // offset 0x10, size 0x4
};

#endif // LIMITTIME_HPP
