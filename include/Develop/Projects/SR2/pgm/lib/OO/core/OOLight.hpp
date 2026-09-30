#ifndef OOLIGHT_HPP
#define OOLIGHT_HPP

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOColor.hpp"

// total size: 0xC
class clsOOLight {
public:
    // RECONSTRUCTED: nested scope.
    // total size: 0x84
    struct stcDetail {
        stcRgbF32 sAmbientRgb;    // offset 0x0, size 0xC
        f32 f32InterpolateSpeed;  // offset 0xC, size 0x4
        stcRgbaF32 sParallelRgba; // offset 0x10, size 0x10
        f32 f32ParallelInten;     // offset 0x20, size 0x4
        NNS_VECTOR sParallelDir;  // offset 0x24, size 0xC
        NNS_VECTOR sParallelPos;  // offset 0x30, size 0xC
        stcRgbaF32 sSpecularRgba; // offset 0x3C, size 0x10
        NNS_VECTOR sSpecularDir;  // offset 0x4C, size 0xC
        stcRgbaF32 sPointRgba;    // offset 0x58, size 0x10
        f32 f32PointInten;        // offset 0x68, size 0x4
        NNS_VECTOR sPointPos;     // offset 0x6C, size 0xC
        f32 f32PointFallOffStart; // offset 0x78, size 0x4
        f32 f32PointFallOffEnd;   // offset 0x7C, size 0x4
        u32 eUseType;             // offset 0x80, size 0x4
    };

    virtual ~clsOOLight() = 0 { delete[] m_psDetail_Heap; }
    void setAmbientRgb(u32 ou32NoI, f32 of32rI, f32 of32gI, f32 of32bI);
    void setParallelRgba(u32 ou32NoI, f32 of32rI, f32 of32gI, f32 of32bI, f32 of32aI);
    void setParallelInten(u32 ou32NoI, f32 of32IntenI);
    void setParallelDir(u32 ou32NoI, f32 of32xI, f32 of32yI, f32 of32zI);
    void setParallelPos(u32 ou32NoI, f32 of32xI, f32 of32yI, f32 of32zI);
    void setSpecularRgba(u32 ou32NoI, f32 of32rI, f32 of32gI, f32 of32bI, f32 of32aI);
    void setSpecularDir(u32 ou32NoI, f32 of32xI, f32 of32yI, f32 of32zI);
    virtual void reinitLight(u32 ou32HardWareNumI, u32 ou32SoftWareNumI, const NNS_MATRIX* pParam3);

    virtual void updateLightMtx(const NNS_MATRIX& rsMtxI) const = 0;
    virtual void sendLight(u32 ou32NoI) = 0;

    stcDetail* m_psDetail_Heap; // offset 0x4, size 0x4
    u8 m_u8HardWareNum;         // offset 0x8, size 0x1
    u8 m_u8SoftWareNum;         // offset 0x9, size 0x1
};

#endif // OOLIGHT_HPP
