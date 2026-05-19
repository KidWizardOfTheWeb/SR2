#ifndef WINLOSE2D_HPP
#define WINLOSE2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0x94
class clsWinLose2D_Task : public clsTask {
public:
    virtual ~clsWinLose2D_Task() {}
    virtual void execute();
    virtual void draw();

    void drawRingNum(s32 s32x, s32 s32y, s32 s32Point);
    void drawRank(s32 s32x, s32 s32y, s32 s32Rank);
    void drawText(s32 s32x, s32 s32y);
    void drawWindow(s32 s32x, s32 s32y, s32 s32w, s32 s32h, u8 u8Alpha, bool bColor);
    void init();

    s32 m_s32ViewNum;          // offset 0x54, size 0x4
    s16 m_s16DrawX[4];         // offset 0x58, size 0x8
    s16 m_s16DrawY[4];         // offset 0x60, size 0x8
    s16 m_s16Rank[4];          // offset 0x68, size 0x8
    u8 m_u8Alpha;              // offset 0x70, size 0x1
    s8 m_s8PauseFrame;         // offset 0x71, size 0x1
    f32 m_f32Scale;            // offset 0x74, size 0x4
    f32 m_f32TextScale;        // offset 0x78, size 0x4
    f32 m_f32RankScale;        // offset 0x7C, size 0x4
    u8* m_pbAnmFlag;           // offset 0x80, size 0x4
    u8* m_pbPlayerWinFlag;     // offset 0x84, size 0x4
    u32* m_pu32PlayerWinCount; // offset 0x88, size 0x4
    u32 m_u32BattleCount;      // offset 0x8C, size 0x4
    u32 m_u32NextCount;        // offset 0x90, size 0x4
};

#endif // WINLOSE2D_HPP
