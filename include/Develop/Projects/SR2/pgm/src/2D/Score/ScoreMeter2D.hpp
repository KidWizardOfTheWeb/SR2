#ifndef SCOREMETER2D_HPP
#define SCOREMETER2D_HPP

#include "types.h"

class clsScore2D_Task;

// total size: 0x10
struct stcTempParam {
    u32 u32Used;   // offset 0x0, size 0x4
    f32 f32Frame;  // offset 0x4, size 0x4
    f32 f32Height; // offset 0x8, size 0x4
    f32 f32Point;  // offset 0xC, size 0x4
};

// total size: 0x34
struct stcMeterData {
    u8 u8GaugeHeight;      // offset 0x0, size 0x1
    u8 u8LineHeight;       // offset 0x1, size 0x1
    s8 s8SpeedX;           // offset 0x2, size 0x1
    s8 s8SpeedY;           // offset 0x3, size 0x1
    s8 s8MaxUpInfoX;       // offset 0x4, size 0x1
    s8 s8MaxUpInfoY;       // offset 0x5, size 0x1
    s8 s8MaxUpInfoW;       // offset 0x6, size 0x1
    f32 f32CircleX;        // offset 0x8, size 0x4
    f32 f32CircleY;        // offset 0xC, size 0x4
    f32 f32NumDefScale;    // offset 0x10, size 0x4
    f32 f32NumMaxScale;    // offset 0x14, size 0x4
    u8 u8NumW;             // offset 0x18, size 0x1
    u8 u8NumH;             // offset 0x19, size 0x1
    f32 f32NumMarignScale; // offset 0x1C, size 0x4
    s16 s16CircleSize;     // offset 0x20, size 0x2
    s16 s16LightSize;      // offset 0x22, size 0x2
    s16 s16TexAnmCnt;      // offset 0x24, size 0x2
    s16 s16TexAnmMax;      // offset 0x26, size 0x2
    u8 u8TexMinAlpha;      // offset 0x28, size 0x1
    u8 u8TexMaxAlpha;      // offset 0x29, size 0x1
    f32 f32EfDefScale;     // offset 0x2C, size 0x4
    f32 f32EfMaxScale;     // offset 0x30, size 0x4
};

// total size: 0x10C
class clsScoreMeter2D {
public:
    struct stcTempParam {
        u32 u32Used;   // offset 0x0, size 0x4
        f32 f32Frame;  // offset 0x4, size 0x4
        f32 f32Height; // offset 0x8, size 0x4
        f32 f32Point;  // offset 0xC, size 0x4
    };

    // Q2-qualified as clsScoreMeter2D::stcUnionStatus; also exists as global DWARF struct (0x2C).
    // Declared nested to match mangled signature.
    struct stcUnionStatus {
        u32 u32Mode;          // offset 0x0, size 0x4
        f32 f32WaitFrame;     // offset 0x4, size 0x4
        u32 u32Flg;           // offset 0x8, size 0x4
        s32 s32LeftX;         // offset 0xC, size 0x4
        s32 s32BottomY;       // offset 0x10
        s32 s32WidthDiff;     // offset 0x14, size 0x4
        s32 s32HeightDiff;    // offset 0x18, size 0x4
        f32 f32GaugeDefWidth; // offset 0x1C
        u8 FrameTexNo;        // offset 0x20
        u8 FrameBackTexNo;    // offset 0x21
        u8 MiniCircleTexNo;   // offset 0x22
        u8 BarLineTexNo;      // offset 0x23
        u8 BarGaugeTexNo;     // offset 0x24
        u8 BarBackTexNo;      // offset 0x25
        u8 BarCapTexNo;       // offset 0x26
        u8 BarLightTexNo;     // offset 0x27
        u8 SpeedNumTexNo;     // offset 0x28
    };

    // Q2-qualified as clsScoreMeter2D::stcUserStatus; also exists as global DWARF struct (0x34).
    // Declared nested to match mangled signature.
    struct stcUserStatus {
        u32 u32Flg;              // offset 0x0, size 0x4
        s32 s32Rot;              // offset 0x4
        u8 u8AddAlpha;           // offset 0x8
        u8 u8LightAlpha;         // offset 0x9
        u8 u8EffectAlpha;        // offset 0xA
        s32 s32TexAnmCnt;        // offset 0xC
        f32 f32EffectScale;      // offset 0x10
        f32 f32NumScale;         // offset 0x14
        f32 f32LastMaxAgp;       // offset 0x18
        f32 f32DrawMaxAgp;       // offset 0x1C
        f32 f32InfoPoint;        // offset 0x20
        stcTempParam sTempParam; // offset 0x24, size 0x10
    };

    virtual ~clsScoreMeter2D();
    virtual void draw();
    virtual void executeMeter(u32 u32View, u32 u32PlayerNo);

    clsScoreMeter2D(clsScore2D_Task* pcParent);

    void drawMeter(u32 u32View, u32 u32PlayerNo);
    void _drawCloseEffect(s32 s32PosX, s32 s32PosY, s32 s32Dir, stcUserStatus* psUserSt);
    void _drawDiveEffect(s32 s32PosX, s32 s32PosY, s32 s32Dir, stcUserStatus* psUserSt);
    void _drawCircleEffect(s32 s32PosX, s32 s32PosY, s32 s32Dir, stcUserStatus* psUserSt);
    void _drawLight(s32 s32PosX, s32 s32PosY, s32 s32Dir, f32 f32Width, u8 u8Alpha);
    void _drawMaxUpInfo(stcTempParam* psParam, s32 s32PosX, s32 s32PosY, s32 s32Dir, f32 f32Width);
    void _drawSpeed(s32 s32PosX, s32 s32PosY, s32 s32Dir, s32 s32Speed, f32 f32Scale);
    void _drawFrame(s32 s32PosX, s32 s32PosY, s32 s32Dir, f32 f32Width, u32 u32Color);
    void _drawGaugeLight(s32 s32PosX,
                         s32 s32PosY,
                         s32 s32Dir,
                         f32 f32Width,
                         f32 f32Gauge,
                         f32 f32Back,
                         f32 f32Max,
                         u8 u8AddAlpha);
    void _drawGauge(
        s32 s32PosX, s32 s32PosY, s32 s32Dir, f32 f32Width, f32 f32Gauge, f32 f32Back, f32 f32Max);
    void execute();
    void init();

    clsScore2D_Task* m_pcParent;     // offset 0x0, size 0x4
    u8 m_bDraw;                      // offset 0x4, size 0x1
    stcUnionStatus m_sUnionStatus;   // offset 0x8, size 0x2C
    stcMeterData* m_opsDrawData;     // offset 0x34, size 0x4
    stcUserStatus m_asUserStatus[4]; // offset 0x38, size 0xD0
};

#endif // SCOREMETER2D_HPP
