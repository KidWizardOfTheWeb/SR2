#ifndef WEATHER_HPP
#define WEATHER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsPlaySe_2D;

// total size: 0x18
struct stcWaterDropStatus {
    s32 s32NextDataNo; // offset 0x0, size 0x4
    u8 bSnow;          // offset 0x4, size 0x1
    f32 f32Frame;      // offset 0x8, size 0x4
    f32 f32EndFrame;   // offset 0xC, size 0x4
    u32 u32Num;        // offset 0x10, size 0x4
    f32 f32LifeFrame;  // offset 0x14, size 0x4
};

// total size: 0x70
struct stcDebugWeather {
    u8 u8Page;             // offset 0x0, size 0x1
    s32 s32PlayNum;        // offset 0x4, size 0x4
    u32 u32Flg;            // offset 0x8, size 0x4
    u8 u8Weather;          // offset 0xC, size 0x1
    u8 u8Windy;            // offset 0xD, size 0x1
    u8 u8WindyWay;         // offset 0xE, size 0x1
    s32 s32Num;            // offset 0x10, size 0x4
    u8 u8Rand;             // offset 0x14, size 0x1
    f32 f32Height;         // offset 0x18, size 0x4
    f32 f32Frame;          // offset 0x1C, size 0x4
    f32 f32Speed;          // offset 0x20, size 0x4
    f32 f32RandSpeed;      // offset 0x24, size 0x4
    f32 f32FallSpeed;      // offset 0x28, size 0x4
    f32 f32RandFallSpeed;  // offset 0x2C, size 0x4
    s32 s32TexNo;          // offset 0x30, size 0x4
    u8 u8r;                // offset 0x34, size 0x1
    u8 u8g;                // offset 0x35, size 0x1
    u8 u8b;                // offset 0x36, size 0x1
    u8 u8a;                // offset 0x37, size 0x1
    s32 s32RotX;           // offset 0x38, size 0x4
    f32 f32SpeedInfl;      // offset 0x3C, size 0x4
    NNS_VECTOR sStartArea; // offset 0x40, size 0xC
    NNS_VECTOR sScale;     // offset 0x4C, size 0xC
    NNS_VECTOR sRandScale; // offset 0x58, size 0xC
    NNS_VECTOR sOfsVec;    // offset 0x64, size 0xC
};

// total size: 0x19C0
class clsWeather_Task : public clsTask {
public:
    // total size: 0x68
    struct stcStatus {
        u32 u32Flg;            // offset 0x0, size 0x4
        u8 u8Windy;            // offset 0x4, size 0x1
        u8 u8WindWay;          // offset 0x5, size 0x1
        s32 s32Num;            // offset 0x8, size 0x4
        u8 u8RandApr;          // offset 0xC, size 0x1
        f32 f32Up;             // offset 0x10, size 0x4
        f32 f32Frame;          // offset 0x14, size 0x4
        f32 f32Speed;          // offset 0x18, size 0x4
        f32 f32RandSpeed;      // offset 0x1C, size 0x4
        f32 f32FallSpeed;      // offset 0x20, size 0x4
        f32 f32RandFallSpeed;  // offset 0x24, size 0x4
        s32 s32TexNo;          // offset 0x28, size 0x4
        u8 u8r;                // offset 0x2C, size 0x1
        u8 u8g;                // offset 0x2D, size 0x1
        u8 u8b;                // offset 0x2E, size 0x1
        u8 u8a;                // offset 0x2F, size 0x1
        s32 s32WindUnit;       // offset 0x30, size 0x4
        f32 f32SpeedInfl;      // offset 0x34, size 0x4
        NNS_VECTOR sStartArea; // offset 0x38, size 0xC
        NNS_VECTOR sScale;     // offset 0x44, size 0xC
        NNS_VECTOR sRandScale; // offset 0x50, size 0xC
        NNS_VECTOR sOfsVec;    // offset 0x5C, size 0xC
    };

    // total size: 0x30
    struct stcSeed {
        NNS_VECTOR sPosVec;   // offset 0x0, size 0xC
        NNS_VECTOR sScale;    // offset 0xC, size 0xC
        NNS_VECTOR sSpeedVec; // offset 0x18, size 0xC
        f32 f32Gravity;       // offset 0x24, size 0x4
        s32 s32Frame;         // offset 0x28, size 0x4
        s32 s32Rot;           // offset 0x2C, size 0x4
    };

    static stcDebugWeather sDebugInfo;

    clsWeather_Task(u32 u32A, u8 u8B);
    virtual ~clsWeather_Task() {}
    virtual void execute();
    virtual void draw();

    void setCreated(stcStatus* psStatus, stcSeed* psSeed, f32 (*psNnMtxList)[4][4]) {}

    void drawBill();
    void drawNotBill();
    void setWeather(u8 u8Weather);
    void setDeafaultInfo(u8 u8A);
    s32 DebugInfo(s32 s32A, s32 s32B, s32 s32C, s32 s32D);

    f32 m_sWindMtx[4][4];               // offset 0x60, size 0x40
    f32 m_sSpdMtx[4][4];                // offset 0xA0, size 0x40
    stcStatus m_sStatus;                // offset 0xE0, size 0x68
    stcWaterDropStatus* m_opsWaterDrop; // offset 0x148, size 0x4
    u8 m_u8Weather;                     // offset 0x14C, size 0x1
    u32 m_u32View;                      // offset 0x150, size 0x4
    f32 m_f32WaterDropFrame;            // offset 0x154, size 0x4
    f32 m_f32WaterDropPlayFrame;        // offset 0x158, size 0x4
    s32 m_s32RotX;                      // offset 0x15C, size 0x4
    s32 m_s32RotY;                      // offset 0x160, size 0x4
    u32 m_u32Col;                       // offset 0x164, size 0x4
    f32 m_sDrawMtx[4][4];               // offset 0x170, size 0x40
    stcSeed m_asSeed[128];              // offset 0x1B0, size 0x1800
    clsPlaySe_2D* m_pcPlaySe2D;         // offset 0x19B0, size 0x4
};

#endif // WEATHER_HPP
