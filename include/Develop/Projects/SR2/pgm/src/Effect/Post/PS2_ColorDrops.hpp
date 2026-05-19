#ifndef PS2_COLORDROPS_HPP
#define PS2_COLORDROPS_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Effect/Post/PS2_RainDrops.hpp"

namespace nspColorDrops {
extern stcPrimitive tsPrimitive[10];
}

// total size: 0x7E4
class clsColorDrops_Task : public clsRainDrops_Task {
public:
    virtual ~clsColorDrops_Task() {}

    virtual void addDetail(u32 u32vI, u32 u32NumI, u32 u32ScaleI, f32 f32LifeFrameI, u8 u8Param5);
    virtual void reinit();
    virtual void drawGeometry() {}

    void reinitView(u8 u8ViewNoI);
    void addDetail(u32 u32vI, u32 u32NumI, u32 u32ScaleI, f32 f32LifeFrameI, u32 bSnowI);

    stcDetail m_sDetail[64]; // offset 0x2E4, size 0x500
};

#endif // PS2_COLORDROPS_HPP
