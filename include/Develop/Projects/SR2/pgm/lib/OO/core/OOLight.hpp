#ifndef OOLIGHT_HPP
#define OOLIGHT_HPP

#include "types.h"

struct stcDetail;

// total size: 0xC
class clsOOLight {
public:
    void setAmbientRgb(u32 ou32NoI, f32 of32rI, f32 of32gI, f32 of32bI);
    void setParallelRgba(u32 ou32NoI, f32 of32rI, f32 of32gI, f32 of32bI, f32 of32aI);
    void setParallelInten(u32 ou32NoI, f32 of32IntenI);
    void setParallelDir(u32 ou32NoI, f32 of32xI, f32 of32yI, f32 of32zI);
    void setParallelPos(u32 ou32NoI, f32 of32xI, f32 of32yI, f32 of32zI);
    void setSpecularRgba(u32 ou32NoI, f32 of32rI, f32 of32gI, f32 of32bI, f32 of32aI);
    void setSpecularDir(u32 ou32NoI, f32 of32xI, f32 of32yI, f32 of32zI);
    virtual void reinitLight(u32 ou32HardWareNumI,
                             u32 ou32SoftWareNumI,
                             const f32 (*pParam3)[4][4]);

    stcDetail* m_psDetail_Heap; // offset 0x4, size 0x4
    u8 m_u8HardWareNum;         // offset 0x8, size 0x1
    u8 m_u8SoftWareNum;         // offset 0x9, size 0x1
};

#endif // OOLIGHT_HPP
