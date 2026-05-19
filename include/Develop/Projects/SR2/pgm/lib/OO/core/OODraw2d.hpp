#ifndef OODRAW2D_HPP
#define OODRAW2D_HPP
#include "types.h"

// total size: 0xC
class clsOODraw2d {
public:
    // total size: 0x8
    struct stcTexCoord {
        f32 f32u; // offset 0x0, size 0x4
        f32 f32v; // offset 0x4, size 0x4
    };

    // total size: 0x10
    struct stcTexUV {
        stcTexCoord sUpperLeft;   // offset 0x0, size 0x8
        stcTexCoord sBottomRight; // offset 0x8, size 0x8
    };

    // total size: 0xC
    struct stcPrim2d_PC {
        f32 f32x;   // offset 0x0, size 0x4
        f32 f32y;   // offset 0x4, size 0x4
        u32 u32Col; // offset 0x8, size 0x4
    };

    u8 m_bWide2dConv; // offset 0x0, size 0x1
    u32 m_eTexFlag;   // offset 0x8, size 0x4

    void renderDp_Debug(f32 of32x0I, f32 of32y0I, f32 of32x1I, f32 of32y1I, u32 ou32ColI);
    void renderDiff(f32 f32Param1,
                    f32 f32Param2,
                    f32 f32Param3,
                    f32 f32Param4,
                    u32 u32Param5,
                    u32 u32Param6,
                    const stcTexUV* psParam7,
                    const f32 (*pasParam8)[4][4],
                    f32 f32Param9)
    {
    }
    void setWide2dConv(bool bParam1) { m_bWide2dConv = bParam1; }
};

typedef clsOODraw2d::stcTexCoord stcTexCoord;
typedef clsOODraw2d::stcTexUV stcTexUV;

#endif // OODRAW2D_HPP
