#ifndef SCOREPARTS2D_HPP
#define SCOREPARTS2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Lap.hpp"

class clsPlayerTask;
class clsEnergyFlow2D;
class clsScore2D_Task;

// total size: 0x68
struct stcPartsData {
    u8 u8Height;                   // offset 0x0, size 0x1
    u8 u8BarHeight;                // offset 0x1, size 0x1
    u8 u8LineHeight;               // offset 0x2, size 0x1
    s8 s8MaxUpInfoX;               // offset 0x3, size 0x1
    s8 s8MaxUpInfoY;               // offset 0x4, size 0x1
    s8 s8MaxUpInfoW;               // offset 0x5, size 0x1
    f32 f32CircleX;                // offset 0x8, size 0x4
    f32 f32CircleY;                // offset 0xC, size 0x4
    u8 u8CurNumW;                  // offset 0x10, size 0x1
    u8 u8CurNumH;                  // offset 0x11, size 0x1
    u8 u8MaxNumW;                  // offset 0x12, size 0x1
    u8 u8MaxNumH;                  // offset 0x13, size 0x1
    u8 u8PartsX;                   // offset 0x14, size 0x1
    u8 u8PartsY;                   // offset 0x15, size 0x1
    u8 u8PartsDist;                // offset 0x16, size 0x1
    f32 f32Scale;                  // offset 0x18, size 0x4
    f32 f32CurScale;               // offset 0x1C, size 0x4
    s16 s16NameW;                  // offset 0x20, size 0x2
    s16 s16NameH;                  // offset 0x22, size 0x2
    s16 s16NameDiffY;              // offset 0x24, size 0x2
    s16 s16ButtonX;                // offset 0x26, size 0x2
    s16 s16ButtonSize;             // offset 0x28, size 0x2
    f32 f32NumMarginScale;         // offset 0x2C, size 0x4
    f32 f32SelectLineAreaFrame;    // offset 0x30, size 0x4
    f32 f32SelectLineDistFrame;    // offset 0x34, size 0x4
    f32 f32SelectLineHeight;       // offset 0x38, size 0x4
    f32 f32ActEffectStartScale;    // offset 0x3C, size 0x4
    f32 f32ActEffectAddWidthScale; // offset 0x40, size 0x4
    f32 f32ActEffectChengeScale;   // offset 0x44, size 0x4
    f32 f32ActEffectAfterScale;    // offset 0x48, size 0x4
    u8 u8LineStartX;               // offset 0x4C, size 0x1
    u8 u8LineMiddleX;              // offset 0x4D, size 0x1
    u8 u8LineEndX;                 // offset 0x4E, size 0x1
    s8 s8LineStartY;               // offset 0x4F, size 0x1
    s8 s8LineEndY;                 // offset 0x50, size 0x1
    u8 u8ELineHeight;              // offset 0x51, size 0x1
    f32 f32LinePointFrame;         // offset 0x54, size 0x4
    f32 f32MarginFrame;            // offset 0x58, size 0x4
    f32 f32HeadScale;              // offset 0x5C, size 0x4
    f32 f32HeadAddFrame;           // offset 0x60, size 0x4
    f32 f32HeadAddScale;           // offset 0x64, size 0x4
};

namespace nspOOMisc {
// total size: 0x4
struct stcPoint2D_s16 {
    s16 s16x; // offset 0x0, size 0x2
    s16 s16y; // offset 0x2, size 0x2
};
} // namespace nspOOMisc
typedef nspOOMisc::stcPoint2D_s16 stcPoint2D_s16;

// total size: 0xC
struct stcLinePoint {
    f32 f32Frame;           // offset 0x0, size 0x4
    stcPoint2D_s16 sFast;   // offset 0x4, size 0x4
    stcPoint2D_s16 sSecond; // offset 0x8, size 0x4
};

// total size: 0x360
class clsScoreParts2D {
public:
    // Nested structs (Q2-qualified in function signatures)
    // total size: 0x10
    struct stcTempParam {
        u32 u32Used;   // offset 0x0, size 0x4
        f32 f32Frame;  // offset 0x4, size 0x4
        f32 f32Height; // offset 0x8, size 0x4
        f32 f32Point;  // offset 0xC, size 0x4
    };

    // total size: 0x18
    struct stcActEffectParam {
        u32 u32Mode;   // offset 0x0, size 0x4
        f32 f32Frame;  // offset 0x4, size 0x4
        f32 f32ScaleX; // offset 0x8, size 0x4
        f32 f32ScaleY; // offset 0xC, size 0x4
        s32 s32DrawX;  // offset 0x10, size 0x4
        s32 s32DrawY;  // offset 0x14, size 0x4
    };

    // total size: 0x80
    struct stcUnionStatus {
        u32 u32Mode;            // offset 0x0, size 0x4
        f32 f32WaitFrame;       // offset 0x4, size 0x4
        u32 u32Flg;             // offset 0x8, size 0x4
        s32 s32LeftX;           // offset 0xC, size 0x4
        s32 s32TopY;            // offset 0x10, size 0x4
        s32 s32WidthDiff;       // offset 0x14, size 0x4
        s32 s32HeightDiff;      // offset 0x18, size 0x4
        f32 f32BackGroundWidth; // offset 0x1C, size 0x4
        f32 f32EnergyFrameMax;  // offset 0x20, size 0x4
        s32 s32RingRot;         // offset 0x24, size 0x4
        f32 sRingMtx[4][4];     // offset 0x30, size 0x40
        u8 FrameTexNo;          // offset 0x70, size 0x1
        u8 FrameLineTexNo;      // offset 0x71, size 0x1
        u8 NumBackTexNo;        // offset 0x72, size 0x1
        u8 RingTexNo;           // offset 0x73, size 0x1
        u8 PipeTexNo;           // offset 0x74, size 0x1
        u8 SelectEffectTexNo;   // offset 0x75, size 0x1
        u8 FrameCapTexNo;       // offset 0x76, size 0x1
        u8 SelectLineTexNo;     // offset 0x77, size 0x1
        u8 FrameCapLightTexNo;  // offset 0x78, size 0x1
    };

    // total size: 0xB0
    struct stcUserStatus {
        u32 u32Flg;                         // offset 0x0, size 0x4
        u8 u8SelectAlpha;                   // offset 0x4, size 0x1
        u8 u8NameAlpha;                     // offset 0x5, size 0x1
        s32 s32LastMaxRing;                 // offset 0x8, size 0x4
        f32 f32DrawWidth;                   // offset 0xC, size 0x4
        f32 f32InfoPoint;                   // offset 0x10, size 0x4
        stcTempParam sTempParam;            // offset 0x14, size 0x10
        stcActEffectParam asEffectParam[3]; // offset 0x24, size 0x48
        f32 f32EnergyFrame;                 // offset 0x6C, size 0x4
        f32 f32EnergySubFrame;              // offset 0x70, size 0x4
        f32 f32SelectFrame;                 // offset 0x74, size 0x4
        clsEnergyFlow2D* pcBaseLine;        // offset 0x78, size 0x4
        clsEnergyFlow2D* pcAddLine;         // offset 0x7C, size 0x4
        stcLinePoint asPoint[4];            // offset 0x80, size 0x30
    };

    virtual ~clsScoreParts2D();
    virtual void draw();
    virtual void drawGearWindow(s32 s32PlayerNo,
                                s32 s32View,
                                stcUnionStatus* psUnionSt,
                                s32 s32PosX,
                                s32 s32PosY,
                                s32 s32Dir,
                                u32 u32Param7);
    virtual void drawRingWindow(s32 s32PlayerNo,
                                s32 s32View,
                                stcUnionStatus* psUnionSt,
                                s32 s32PosX,
                                s32 s32PosY,
                                s32 s32Dir,
                                u32 ou32CharaColor);
    virtual void drawAddEffect(s32 s32PlayerNo,
                               s32 s32View,
                               stcUnionStatus* psUnionSt,
                               s32 s32PosX,
                               s32 s32PosY,
                               s32 s32Dir,
                               u32 u32Param7);
    virtual void drawComPoint() {}

    clsScoreParts2D(clsScore2D_Task* pcParent);

    void init();
    void _exeEnergyLine(stcUserStatus* psUserSt);
    void execute();
    void _drawMaxUpInfo(stcTempParam* psParam, s32 s32PosX, s32 s32PosY, s32 s32Dir, f32 f32Width);
    void _initActEffect(stcUserStatus* psUserSt, s32 s32No);
    void _setActEffect(stcUserStatus* psUserSt, s32 s32No, s32 s32x, s32 s32y);
    void _drawActEffect(stcUserStatus* psUserSt);
    void _drawRing(s32 s32PosX, s32 s32PosY, s32 s32Dir);
    void _drawNumBack(s32 s32PosX, s32 s32PosY, s32 s32Dir, f32 f32Width, u32 u32Color);
    void _drawFrame(s32 s32PosX, s32 s32PosY, s32 s32Dir, f32 f32Width, u32 u32Param5);
    void _drawRingNum(s32 s32PosX, s32 s32PosY, s32 s32Dir, s32 s32Ring, s32 s32RingMax);
    void _drawPartsIcon(
        s32 s32PosX, s32 s32PosY, s32 s32Dir, clsPlayerTask* pcPlayer, stcUserStatus* psUserSt);
    void _drawPartsEtc(s32 s32PosX,
                       s32 s32PosY,
                       s32 s32Dir,
                       clsPlayerTask* pcPlayer,
                       stcUserStatus* psUserSt,
                       bool bBotton);
    void _drawPartsName(
        s32 s32PosX, s32 s32PosY, s32 s32Dir, clsPlayerTask* pcPlayer, stcUserStatus* psUserSt);
    void _drawPartsLight(
        s32 s32PosX, s32 s32PosY, s32 s32Dir, clsPlayerTask* pcPlayer, u8 u8AddAlpha);
    void _drawSelectLine(
        s32 s32PosX, s32 s32PosY, s32 s32Dir, clsPlayerTask* pcPlayer, stcUserStatus* psUserSt);
    void drawParts(u32 u32View, u32 u32PlayerNo);

    clsScore2D_Task* m_pcParent;     // offset 0x0, size 0x4
    u8 m_bDraw;                      // offset 0x4, size 0x1
    stcPartsData* m_opsDrawData;     // offset 0x8, size 0x4
    stcUnionStatus m_sUnionStatus;   // offset 0x10, size 0x80
    stcUserStatus m_asUserStatus[4]; // offset 0x90, size 0x2C0
};

#endif // SCOREPARTS2D_HPP
