#ifndef GOALLAPTIME2D_HPP
#define GOALLAPTIME2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Temporary2D.hpp"

// total size: 0x20
struct stcLapTime2D {
    s16 s16PosXDiff;        // offset 0x0, size 0x2
    s16 s16PosYDiff;        // offset 0x2, size 0x2
    s32 s32WindowWidth;     // offset 0x4, size 0x4
    s16 s16TitlePosY;       // offset 0x8, size 0x2
    s16 s16MarignWidth;     // offset 0xA, size 0x2
    s16 s16MarignHeight;    // offset 0xC, size 0x2
    s16 s16ItemHeight;      // offset 0xE, size 0x2
    s16 s16TextMarignWidth; // offset 0x10, size 0x2
    u8 u8TitleMarignWidth;  // offset 0x12, size 0x1
    u8 au8LapPosDiff[3];    // offset 0x13, size 0x3
    f32 f32MarginScale;     // offset 0x18, size 0x4
    f32 f32MarkMarginScale; // offset 0x1C, size 0x4
};

// total size: 0x78
class clsGoalLapTime2D_Task : public clsTemporary2D_Task {
public:
    s32 m_s32View;      // offset 0x58, size 0x4
    u8 m_u8Alpha;       // offset 0x5C, size 0x1
    u8 m_u8BestAlpha;   // offset 0x5D, size 0x1
    s16 m_s16CenterX;   // offset 0x5E, size 0x2
    s16 m_s16CenterY;   // offset 0x60, size 0x2
    s16 m_s16WindowW;   // offset 0x62, size 0x2
    s16 m_s16WindowH;   // offset 0x64, size 0x2
    s16 m_s16TextLeft;  // offset 0x66, size 0x2
    s16 m_s16TimeLeft;  // offset 0x68, size 0x2
    f32 m_f32WaitFrame; // offset 0x6C, size 0x4
    f32 m_f32StopFrame; // offset 0x70, size 0x4
    f32 m_f32FadeFrame; // offset 0x74, size 0x4

    clsGoalLapTime2D_Task(s32 s32Param1);
    virtual ~clsGoalLapTime2D_Task();
    virtual void execute();
    virtual void draw();
    void drawWindowItem();
    void drawTime();
};

#endif
