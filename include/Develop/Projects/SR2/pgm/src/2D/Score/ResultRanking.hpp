#ifndef RESULTRANKING_HPP
#define RESULTRANKING_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreParts2D.hpp"

namespace nspResultRanking {
// total size: 0x7C
struct stcResultRanking {
    u16 u16RingWindowX;          // offset 0x0, size 0x2
    u16 u16RingWindowY;          // offset 0x2, size 0x2
    u16 u16RingWindowW;          // offset 0x4, size 0x2
    u16 u16RingWindowH;          // offset 0x6, size 0x2
    u16 u16LineStartY;           // offset 0x8, size 0x2
    u16 u16LineAreaY;            // offset 0xA, size 0x2
    u16 u16LineItemYDiff;        // offset 0xC, size 0x2
    f32 f32WaitFrame;            // offset 0x10, size 0x4
    f32 f32RankFrame;            // offset 0x14, size 0x4
    f32 f32NameFrame;            // offset 0x18, size 0x4
    f32 f32TimeFrame;            // offset 0x1C, size 0x4
    f32 f32PointFrame;           // offset 0x20, size 0x4
    f32 f32TrophyFrame;          // offset 0x24, size 0x4
    s16 s16RankPosX;             // offset 0x28, size 0x2
    s16 s16RankPosY;             // offset 0x2A, size 0x2
    s16 s16RankPosXDiff;         // offset 0x2C, size 0x2
    f32 f32RankScale;            // offset 0x30, size 0x4
    f32 f32RankMiddleScale;      // offset 0x34, size 0x4
    f32 f32RankSmallScale;       // offset 0x38, size 0x4
    f32 f32RankSmallMarginScale; // offset 0x3C, size 0x4
    s16 s16NamePosX;             // offset 0x40, size 0x2
    s16 s16NamePosXDiff;         // offset 0x42, size 0x2
    s16 s16NameCharaX;           // offset 0x44, size 0x2
    s16 s16TimePosXDiff;         // offset 0x46, size 0x2
    s16 s16TimeRightMargin;      // offset 0x48, size 0x2
    f32 f32TimeMarginScale;      // offset 0x4C, size 0x4
    f32 f32TrophyScale;          // offset 0x50, size 0x4
    f32 f32TrophyStartScale;     // offset 0x54, size 0x4
    u8 u8RingPosX;               // offset 0x58, size 0x1
    u8 u8RingNumX;               // offset 0x59, size 0x1
    u8 u8ConmaPosY;              // offset 0x5A, size 0x1
    s16 s16LineStartX;           // offset 0x5C, size 0x2
    s16 s16LineMiddleX;          // offset 0x5E, size 0x2
    s16 s16LineEndX;             // offset 0x60, size 0x2
    s16 s16LineStartY;           // offset 0x62, size 0x2
    s16 s16LineEndY;             // offset 0x64, size 0x2
    u8 u8ELineHeight;            // offset 0x66, size 0x1
    f32 f32LinePointFrame;       // offset 0x68, size 0x4
    f32 f32MarginFrame;          // offset 0x6C, size 0x4
    f32 f32HeadScale;            // offset 0x70, size 0x4
    f32 f32HeadAddFrame;         // offset 0x74, size 0x4
    f32 f32HeadAddScale;         // offset 0x78, size 0x4
};

extern u8 MAT_ALPHA_SPEED;
extern stcResultRanking osDrawData;
} // namespace nspResultRanking

// total size: 0x2A4
class clsResultRanking2D_Task : public clsTask {
public:
    // Q2-qualified as clsResultRanking2D_Task::stcRankingLine; nested because it only appears under
    // this class in DWARF. Verify during implementation.
    struct stcRankingLine {
        u32 u32Flg;                  // offset 0x0, size 0x4
        f32 f32WaitFrame;            // offset 0x4, size 0x4
        f32 f32RankFrame;            // offset 0x8, size 0x4
        f32 f32NameFrame;            // offset 0xC, size 0x4
        f32 f32TimeFrame;            // offset 0x10, size 0x4
        f32 f32PointFrame;           // offset 0x14, size 0x4
        f32 f32TrophyFrame;          // offset 0x18, size 0x4
        s16 s16DrawX;                // offset 0x1C, size 0x2
        s16 s16DrawY;                // offset 0x1E, size 0x2
        u32 u32Rank;                 // offset 0x20, size 0x4
        u16 u16CharaId;              // offset 0x24, size 0x2
        u8 u8Minite;                 // offset 0x26, size 0x1
        u8 u8Second;                 // offset 0x27, size 0x1
        u16 u16MSecond;              // offset 0x28, size 0x2
        s16 s16Point;                // offset 0x2A, size 0x2
        s16 s16AddPoint;             // offset 0x2C, size 0x2
        f32 f32BaseLineFrame;        // offset 0x30, size 0x4
        f32 f32AddLineFrame;         // offset 0x34, size 0x4
        clsEnergyFlow2D* pcBaseLine; // offset 0x38, size 0x4
        clsEnergyFlow2D* pcAddLine;  // offset 0x3C, size 0x4
    };

    virtual ~clsResultRanking2D_Task();
    virtual void execute();
    virtual void draw();
    virtual void init();

    clsResultRanking2D_Task(u32 u32Flg, bool bPause);

    void drawRing();
    void drawBackMat(stcRankingLine* psLine);
    void drawTrophy(stcRankingLine* psLine);
    void drawPoint(stcRankingLine* psLine);
    void drawTime(stcRankingLine* psLine);
    void drawName(stcRankingLine* psLine);
    void drawRanking(stcRankingLine* psLine);
    u8 setOutMode();
    void execPoint(stcRankingLine* psLine);
    void execTime(stcRankingLine* psLine);
    void execName(stcRankingLine* psLine);
    void execRanking(stcRankingLine* psLine);
    void execEnergyLine(stcRankingLine* psLine);
    u8 checkWait(stcRankingLine* psLine);

    u32 m_u32Flg;               // offset 0x54, size 0x4
    f32 m_f32AllWaitFrame;      // offset 0x58, size 0x4
    s32 m_s32RingWindowX;       // offset 0x5C, size 0x4
    s32 m_s32RingWindowY;       // offset 0x60, size 0x4
    f32 m_f32LineFrameMax;      // offset 0x64, size 0x4
    u8 m_u8MatAlpha;            // offset 0x68, size 0x1
    u32 m_u32DrawRingNum;       // offset 0x6C, size 0x4
    u32 m_u32EndRingNum;        // offset 0x70, size 0x4
    stcRankingLine m_asLine[8]; // offset 0x74, size 0x200
    stcLinePoint m_asPoint[4];  // offset 0x274, size 0x30
};

#endif // RESULTRANKING_HPP
