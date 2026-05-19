#ifndef OOCLOCK_HPP
#define OOCLOCK_HPP

#include "types.h"

// total size: 0x24
class clsOOClock {
public:
    // total size: 0x4
    struct stcRecord {
        u8 u8Minite;       // offset 0x0, size 0x1
        u8 u8Second;       // offset 0x1, size 0x1
        u16 u16MiliSecond; // offset 0x2, size 0x2
    };

    virtual ~clsOOClock() {}

    void update();
    void reinit(u32 oeCountTypeI,
                s32 os32MinuteI,
                s32 os32SecI,
                s32 os32MSecI,
                s32 os32MinuteUpLimitI,
                s32 os32SecUpLimitI,
                s32 os32MSecUpLimitI);

    f32 getMSec() const { return m_f32MSec; }
    s32 getSec() const { return m_s32Sec; }

    s32 m_s32Minute;        // offset 0x4, size 0x4
    s32 m_s32Sec;           // offset 0x8, size 0x4
    f32 m_f32MSec;          // offset 0xC, size 0x4
    s32 m_s32MinuteUpLimit; // offset 0x10, size 0x4
    s32 m_s32SecUpLimit;    // offset 0x14, size 0x4
    s32 m_s32MSecUpLimit;   // offset 0x18, size 0x4
    u32 m_eCountType;       // offset 0x1C, size 0x4
    u8 m_bOverFlow;         // offset 0x20, size 0x1
    u8 m_bCountStop;        // offset 0x21, size 0x1
    // gap 0x22-0x23 (alignment)
};

typedef clsOOClock::stcRecord stcRecord;

#endif // OOCLOCK_HPP
