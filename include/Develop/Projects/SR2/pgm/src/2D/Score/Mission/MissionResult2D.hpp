#ifndef MISSIONRESULT2D_HPP
#define MISSIONRESULT2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Mission/Mission2D.hpp"

// total size: 0xA8
class clsMissionResult2D_Task : public clsTask {
public:
    stcPos2D* m_opsPosVec;    // offset 0x54, size 0x4
    enmMissionInfo m_eModoNo; // offset 0x58, size 0x4
    u32 m_u32NowScore;        // offset 0x5C, size 0x4
    u32 m_u32OldScore;        // offset 0x60, size 0x4
    u32 m_u32NowRank;         // offset 0x64, size 0x4
    u32 m_u32OldRank;         // offset 0x68, size 0x4
    u32 m_u32Count;           // offset 0x6C, size 0x4
    u8 m_bChangeScore;        // offset 0x70, size 0x1
    u8 m_bEndFlag2D;          // offset 0x71, size 0x1
    s8* m_ops8RankCount;      // offset 0x74, size 0x4
    f32 m_f32ScaleLankBox;    // offset 0x78, size 0x4
    f32 m_f32ScaleBestBox;    // offset 0x7C, size 0x4
    f32 m_f32ScaleResultBox;  // offset 0x80, size 0x4
    f32 m_f32ScaleMegBox;     // offset 0x84, size 0x4
    f32 m_f32ScaleBestLv;     // offset 0x88, size 0x4
    f32 m_f32AlphaBestLv;     // offset 0x8C, size 0x4
    f32 m_f32RankBoxAnm00Y;   // offset 0x90, size 0x4
    f32 m_f32RankBoxAnm01Y;   // offset 0x94, size 0x4
    f32 m_f32RankBoxAnm02Y;   // offset 0x98, size 0x4
    u32 m_u32AnmModo;         // offset 0x9C, size 0x4
    u32 m_u32AnmCount;        // offset 0xA0, size 0x4
    f32 m_f32CardRotY;        // offset 0xA4, size 0x4

    clsMissionResult2D_Task(enmMissionInfo,
                            u32 u32Param2,
                            u32 u32Param3,
                            u32 u32Param4,
                            u32 u32Param5,
                            const s8* pParam6);
    virtual ~clsMissionResult2D_Task() {}
    virtual void execute();
    virtual void draw();
    void main();
    void drawRankBox();
    void drawMessegeBox();
    void drawTrickLank();
};

#endif
