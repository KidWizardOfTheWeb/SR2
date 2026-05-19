#ifndef PS2_BLUR_HPP
#define PS2_BLUR_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0xA
struct stcPrimitive {
    u16 u16x;     // offset 0x0, size 0x2
    u16 u16y;     // offset 0x2, size 0x2
    u16 u16u;     // offset 0x4, size 0x2
    u16 u16v;     // offset 0x6, size 0x2
    u8 u8Alpha;   // offset 0x8, size 0x1
    u8 u8RegAddr; // offset 0x9, size 0x1
};

// total size: 0x7C
class clsBlur_Task : public clsTask {
public:
    f32 m_af32GravityFrame[4];    // offset 0x54, size 0x10
    u64* m_pu64GsPacket_Capture;  // offset 0x64, size 0x4
    u64* m_pu64GsPacket_DrawBlur; // offset 0x68, size 0x4
    u32 m_u32FbDrawHeightx16;     // offset 0x6C, size 0x4
    u32 m_u32WY_TEXHx16;          // offset 0x70, size 0x4
    u16 m_u16DrawBlur_BaseW;      // offset 0x74, size 0x2
    u16 m_u16DrawBlur_BaseH0;     // offset 0x76, size 0x2
    u16 m_u16DrawBlur_BaseH1;     // offset 0x78, size 0x2

    clsBlur_Task(u32 u32a, s32 s32b);
    virtual ~clsBlur_Task() {}

    virtual void execute();
    virtual void draw();

    void drawGravity(u32 u32a, bool b);
    void drawNormal(u32 u32a, u8 u8b, f32 f32c);
    void captureFullScreen();
};

#endif // PS2_BLUR_HPP
