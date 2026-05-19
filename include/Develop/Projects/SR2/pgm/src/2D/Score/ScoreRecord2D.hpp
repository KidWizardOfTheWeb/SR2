#ifndef SCORERECORD2D_HPP
#define SCORERECORD2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreParts2D.hpp"

class clsScore2D_Task;
class clsPlayerTask;
class clsEnergyFlow2D;

// total size: 0x2C
struct stcRecordData {
    u8 u8NumWidth;         // offset 0x0, size 0x1
    u8 u8TextWidth;        // offset 0x1, size 0x1
    u8 u8MarkWidth;        // offset 0x2, size 0x1
    u8 u8Height;           // offset 0x3, size 0x1
    s16 s16SlideMax;       // offset 0x4, size 0x2
    f32 f32MarginScale;    // offset 0x8, size 0x4
    u8 u8LineStartX;       // offset 0xC, size 0x1
    u8 u8LineMiddleX;      // offset 0xD, size 0x1
    u8 u8LineEndX;         // offset 0xE, size 0x1
    s16 s16LineStartY;     // offset 0x10, size 0x2
    s16 s16LineEndY;       // offset 0x12, size 0x2
    u8 u8ELineHeight;      // offset 0x14, size 0x1
    f32 f32LinePointFrame; // offset 0x18, size 0x4
    f32 f32MarginFrame;    // offset 0x1C, size 0x4
    f32 f32HeadScale;      // offset 0x20, size 0x4
    f32 f32HeadAddFrame;   // offset 0x24, size 0x4
    f32 f32HeadAddScale;   // offset 0x28, size 0x4
};

// total size: 0x20
struct stcUnionStatus {
    u32 u32Mode;           // offset 0x0, size 0x4
    u32 u32Flg;            // offset 0x4, size 0x4
    s32 s32LeftX;          // offset 0x8, size 0x4
    s32 s32BottomY;        // offset 0xC, size 0x4
    s32 s32MoveMax;        // offset 0x10, size 0x4
    f32 f32EnergyFrameMax; // offset 0x14, size 0x4
    s32 s32WidthDiff;      // offset 0x18, size 0x4
    s32 s32HeightDiff;     // offset 0x1C, size 0x4
};

// total size: 0x54
struct stcUserStatus {
    u32 u32Mode;                 // offset 0x0, size 0x4
    u32 u32Flg;                  // offset 0x4, size 0x4
    f32 f32WaitFrame;            // offset 0x8, size 0x4
    u8 u8Alpha;                  // offset 0xC, size 0x1
    s16 s16MoveX;                // offset 0xE, size 0x2
    u8 u8TimeAlpha;              // offset 0x10, size 0x1
    s16 s16TimeMoveX;            // offset 0x12, size 0x2
    f32 f32EnergyFrame;          // offset 0x14, size 0x4
    f32 f32EnergySubFrame;       // offset 0x18, size 0x4
    clsEnergyFlow2D* pcBaseLine; // offset 0x1C, size 0x4
    clsEnergyFlow2D* pcAddLine;  // offset 0x20, size 0x4
    stcLinePoint asPoint[4];     // offset 0x24, size 0x30
};

// total size: 0x180
class clsScoreRecord2D {
public:
    struct stcUserStatus {
        u32 u32Mode;                 // offset 0x0, size 0x4
        u32 u32Flg;                  // offset 0x4, size 0x4
        f32 f32WaitFrame;            // offset 0x8, size 0x4
        u8 u8Alpha;                  // offset 0xC, size 0x1
        s16 s16MoveX;                // offset 0xE, size 0x2
        u8 u8TimeAlpha;              // offset 0x10, size 0x1
        s16 s16TimeMoveX;            // offset 0x12, size 0x2
        f32 f32EnergyFrame;          // offset 0x14, size 0x4
        f32 f32EnergySubFrame;       // offset 0x18, size 0x4
        clsEnergyFlow2D* pcBaseLine; // offset 0x1C, size 0x4
        clsEnergyFlow2D* pcAddLine;  // offset 0x20, size 0x4
        stcLinePoint asPoint[4];     // offset 0x24, size 0x30
    };

    clsScore2D_Task* m_pcParent;     // offset 0x0, size 0x4
    stcRecordData* m_opsDrawData;    // offset 0x4, size 0x4
    u8 m_bDraw;                      // offset 0x8, size 0x1
    stcUnionStatus m_sUnionStatus;   // offset 0xC, size 0x20
    stcUserStatus m_asUserStatus[4]; // offset 0x2C, size 0x150

    clsScoreRecord2D(clsScore2D_Task* pParam1);
    virtual ~clsScoreRecord2D();
    void drawRecord(u32 u32Param1, u32 u32Param2);
    void draw();
    void _drawRecordTime(clsPlayerTask* pParam1, stcUserStatus* pParam2, s32 s32Param3);
    void execute();
    void init();
};

#endif
