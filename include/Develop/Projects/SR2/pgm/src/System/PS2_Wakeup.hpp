#ifndef PS2_WAKEUP_HPP
#define PS2_WAKEUP_HPP

#include "Develop/Projects/SR2/pgm/src/System/BaseWakeup.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnGraphics.hpp"
#include "types.h"

// total size: 0x64
class clsWakeup_Task : public clsBaseWakeup_Task {
public:
    clsWakeup_Task();
    virtual ~clsWakeup_Task() {}

    s32 m_s32h;     // offset 0x54, size 0x4
    s32 m_s32hh;    // offset 0x58, size 0x4
    f32 m_f32Timer; // offset 0x5C, size 0x4
    u16 m_u16Alpha; // offset 0x60, size 0x2
    u8 m_bYesNo;    // offset 0x62, size 0x1

    virtual void execute();
    virtual void draw();
    virtual void drawMessage(s32 s32yI, u32 u32RgbI, s32 s32FontTblNoI, u32 bDrawWakuI);
    virtual void changeVideoMode(clsOOGraphics_Consumer::enmScreenMode eScreenModeI);
    inline void setInterlace() {}
};

#endif // PS2_WAKEUP_HPP
