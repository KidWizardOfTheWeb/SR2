#ifndef SCOREINFO2D_HPP
#define SCOREINFO2D_HPP

#include "types.h"

class clsScore2D_Task;

// total size: 0x30
struct stcInfoData {
    s16 s16RankPosX;        // offset 0x0, size 0x2
    s16 s16RankPosY;        // offset 0x2, size 0x2
    s16 s16LapPosX;         // offset 0x4, size 0x2
    s16 s16LapPosY;         // offset 0x6, size 0x2
    s16 s16BackOpenMax;     // offset 0x8, size 0x2
    s16 s16BackOpenMaxWide; // offset 0xA, size 0x2
    s16 s16BackOpenAddWide; // offset 0xC, size 0x2
    s16 s16BackHeight;      // offset 0xE, size 0x2
    s16 s16BackLineHeight;  // offset 0x10, size 0x2
    u8 u8LapTextW;          // offset 0x12, size 0x1
    u8 u8LapCurW;           // offset 0x13, size 0x1
    u8 u8LapCurH;           // offset 0x14, size 0x1
    u8 u8LapMaxW;           // offset 0x15, size 0x1
    u8 u8LapMaxH;           // offset 0x16, size 0x1
    s8 s8LapMargin;         // offset 0x17, size 0x1
    u8 u8LineOut;           // offset 0x18, size 0x1
    u8 u8LineHeight;        // offset 0x19, size 0x1
    f32 f32LinePointFrame;  // offset 0x1C, size 0x4
    f32 f32MarginFrame;     // offset 0x20, size 0x4
    f32 f32HeadScale;       // offset 0x24, size 0x4
    f32 f32HeadAddFrame;    // offset 0x28, size 0x4
    f32 f32HeadAddScale;    // offset 0x2C, size 0x4
};

// Global stcUnionStatus used by ScoreInfo2D (size 0x30).
// NOTE: clsScoreMeter2D also has a nested stcUnionStatus (size 0x2C) — these are separate types.
// total size: 0x30
struct stcUnionStatus {
    u32 u32Mode;           // offset 0x0, size 0x4
    u32 u32Flg;            // offset 0x4
    f32 f32WaitFrame;      // offset 0x8
    s16 s16Right;          // offset 0xC
    s16 s16Bottom;         // offset 0xE
    s32 s32WidthDiff;      // offset 0x10
    s32 s32HeightDiff;     // offset 0x14
    s32 s32Open;           // offset 0x18
    u8 u8Alpha;            // offset 0x1C
    f32 f32RankScaleSpeed; // offset 0x20
    f32 f32RankDefScale;   // offset 0x24
    f32 f32RankSmallScale; // offset 0x28
    f32 f32RankLargeScale; // offset 0x2C
};

// Global stcUserStatus used by ScoreInfo2D (size 0xC).
// NOTE: clsScoreMeter2D also has a nested stcUserStatus (size 0x34) — these are separate types.
// total size: 0xC
struct stcUserStatus {
    s32 s32OldRank;  // offset 0x0
    s32 s32LastRank; // offset 0x4
    f32 f32Scale;    // offset 0x8
};

// total size: 0x70
class clsScoreInfo2D {
public:
    clsScoreInfo2D(clsScore2D_Task* pcParent);
    virtual ~clsScoreInfo2D();
    virtual void draw();
    virtual void RankMain();

    void init();
    void execute();
    void drawInfo(u32 u32Arg0, u32 u32Arg1);
    void _drawLap(s32 s32Arg0, s32 s32Arg1, s32 s32Arg2, s32 s32Arg3, s32 s32Arg4);
    void _drawLapBack(s32 s32Arg0, s32 s32Arg1, s32 s32Arg2, s32 s32Arg3, s32 s32Arg4);
    void _drawRank(s32 s32Arg0, s32 s32Arg1, s32 s32Arg2, s32 s32Arg3, s32 s32Arg4, f32 f32Arg5);

    stcInfoData* m_opsDrawData;      // offset 0x0, size 0x4
    u8 m_bDraw;                      // offset 0x4, size 0x1
    clsScore2D_Task* m_pcParent;     // offset 0x8, size 0x4
    stcUnionStatus m_sUnionStatus;   // offset 0xC, size 0x30
    stcUserStatus m_asUserStatus[4]; // offset 0x3C, size 0x30
};

#endif // SCOREINFO2D_HPP
