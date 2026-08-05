#ifndef PS2TIMER_HPP
#define PS2TIMER_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOTimer.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"

// total size: 0x30
class clsPfTimer : public clsSingleton<clsPfTimer>, public clsOOTimer {
public:
    virtual ~clsPfTimer();
    virtual s32 getTick() const;
    virtual s32 TickDiff2MicroSec(s32 s32Tick) const;
    virtual s32 TickDiff2MicroSec(s32 s32TickA, s32 s32TickB) const;
};

#endif // PS2TIMER_HPP
