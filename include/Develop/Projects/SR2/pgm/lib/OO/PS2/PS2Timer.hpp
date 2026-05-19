#ifndef PS2TIMER_HPP
#define PS2TIMER_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOTimer.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"

// total size: 0x30
class clsPfTimer : public clsSingleton<clsPfTimer>, public clsOOTimer {
public:
    virtual ~clsPfTimer() {}
    virtual s32 getTick() const { return *(volatile s32*)0x10000000; }
    virtual s32 TickDiff2MicroSec(s32 s32Tick) const
    {
        return static_cast<s32>(static_cast<f32>((s32Tick & 0xFFFF) << 8) * 0.00678168f);
    }
    virtual s32 TickDiff2MicroSec(s32 s32TickA, s32 s32TickB) const
    {
        return TickDiff2MicroSec(s32TickA - s32TickB);
    }
};

#endif // PS2TIMER_HPP
