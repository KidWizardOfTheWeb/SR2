#ifndef PS2_RAINDROPS_HPP
#define PS2_RAINDROPS_HPP

#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreParts2D.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Post/PS2_Blur.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

static u32 ALL_GS_PACKET_DRAW_RAINDROPS_NUM;
static u32 DRAW_RAINDROPS_PRIMITIVE_N_NUM;

// total size: 0x4
struct stcBufNo {
    u16 u16Begin; // offset 0x0, size 0x2
    u16 u16End;   // offset 0x2, size 0x2
};

// total size: 0xB0
struct stcDetail {
    NNS_VECTORFAST m_sPosFast;          // offset 0x0, size 0x10
    NNS_VECTOR m_sVelocity;             // offset 0x10, size 0xC
    stcPoint2D_s16 _m_asScreen2d[4][8]; // offset 0x1C, size 0x80
    stcBufNo asBufNo[4];                // offset 0x9C, size 0x10
    u8 bExist;                          // offset 0xAC, size 0x1
    u8 bRandAir;                        // offset 0xAD, size 0x1
    u8 m_u8Size2;                       // offset 0xAE, size 0x1
    u8 m_u8Length2;                     // offset 0xAF, size 0x1
};

namespace nspRainDrops {
extern stcPrimitive tsPrimitive[10];
}

// total size: 0x2E4
class clsRainDrops_Task : public clsTask {
public:
    clsRainDrops_Task(u32 u32Tp, s32 s32Flg);
    virtual ~clsRainDrops_Task() {}

    virtual void draw();
    virtual void addDetail(u32 u32vI, u32 u32NumI, u32 bSnowI, f32 f32LifeFrameI, u8 u8IsGrowType);
    virtual void reinit();
    virtual void drawGeometry() {}

    void drawBegin();

    stcDetail m_sDetail[32];           // offset 0x54, size 0x280
    u8 m_u8DetailLoopNo;               // offset 0x2D4, size 0x1
    u64* m_pu64GsPacket_DrawRainDrops; // offset 0x2D8, size 0x4
    u32 m_u32MY;                       // offset 0x2DC, size 0x4
    f32 m_f32GSDH;                     // offset 0x2E0, size 0x4
};

#endif // PS2_RAINDROPS_HPP
