#ifndef TRICKRESULTRANK2D_HPP
#define TRICKRESULTRANK2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Temporary2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/EnergyFlow2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Score2D.hpp"

class clsPlayerTask;

namespace nspTrickResultRank2D {
// total size: 0x40
struct stcTrikRankData {
    s16 s16MoveMax;        // offset 0x0, size 0x2
    s16 s16PosYDiff;       // offset 0x2, size 0x2
    s32 s32RotMax;         // offset 0x4, size 0x4
    s32 s32ChengeRot;      // offset 0x8, size 0x4
    f32 f32InWaitFrame;    // offset 0xC, size 0x4
    f32 f32RotWaitFrame;   // offset 0x10, size 0x4
    f32 f32OutWaitFrame;   // offset 0x14, size 0x4
    f32 f32FontScale;      // offset 0x18, size 0x4
    f32 f32RankScale;      // offset 0x1C, size 0x4
    s16 s16LineStartX;     // offset 0x20, size 0x2
    s16 s16LineMiddleX;    // offset 0x22, size 0x2
    s16 s16LineEndX;       // offset 0x24, size 0x2
    s16 s16LineStartY;     // offset 0x26, size 0x2
    s16 s16LineEndY;       // offset 0x28, size 0x2
    u8 u8ELineHeight;      // offset 0x2A, size 0x1
    f32 f32LinePointFrame; // offset 0x2C, size 0x4
    f32 f32MarginFrame;    // offset 0x30, size 0x4
    f32 f32HeadScale;      // offset 0x34, size 0x4
    f32 f32HeadAddFrame;   // offset 0x38, size 0x4
    f32 f32HeadAddScale;   // offset 0x3C, size 0x4
};

struct stcEnergyPoint {
    s32 s32BaseX;            // offset 0x0, size 0x4
    s32 s32BaseY;            // offset 0x4, size 0x4
    s32 s32Dir;              // offset 0x8, size 0x4
    f32 f32FrameMax;         // offset 0xC, size 0x4
    stcLinePoint asPoint[4]; // offset 0x10, size 0x30
};

void setupEnergyPoint();

extern stcTrikRankData DrawData1v;
extern stcTrikRankData DrawData2v;
extern stcTrikRankData DrawData4v;
extern stcTrikRankData* opsDrawData;
extern stcEnergyPoint asEnergyPoint[4];
extern f32 tf32EnergyFrameMax;
} // namespace nspTrickResultRank2D

// total size: 0xF0
class clsTrickResultRank2D_Task : public clsTemporary2D_Task {
public:
    clsTrickResultRank2D_Task(u32 u32View,
                              s32 s32StartRank,
                              s32 s32EndRank,
                              clsPlayerTask* pcPlayer);
    virtual ~clsTrickResultRank2D_Task();
    virtual void execute();
    virtual void draw();

    void exeAddLine();
    void _drawRank();

    u32 m_u32View;                 // offset 0x58, size 0x4
    s32 m_s32Rank;                 // offset 0x5C, size 0x4
    s32 m_s32OldRank;              // offset 0x60, size 0x4
    clsPlayerTask* m_pcPlayer;     // offset 0x64, size 0x4
    stcViewRect* m_opsRect;        // offset 0x68, size 0x4
    u8 m_u8RankAlpha;              // offset 0x6C, size 0x1
    s16 m_s16RankMove;             // offset 0x6E, size 0x2
    u8 m_u8TextAlpha;              // offset 0x70, size 0x1
    s16 m_s16TextMove;             // offset 0x72, size 0x2
    u32 m_u32HideFlg;              // offset 0x74, size 0x4
    f32 m_f32InWait;               // offset 0x78, size 0x4
    f32 m_f32RotWait;              // offset 0x7C, size 0x4
    f32 m_f32OutWait;              // offset 0x80, size 0x4
    s32 m_s32Rot;                  // offset 0x84, size 0x4
    f32 m_sDrawMtx[4][4];          // offset 0x90, size 0x40
    u8 m_bChanged;                 // offset 0xD0, size 0x1
    f32 m_f32EnergyFrame;          // offset 0xD4, size 0x4
    f32 m_f32EnergySubFrame;       // offset 0xD8, size 0x4
    clsEnergyFlow2D* m_pcBaseLine; // offset 0xDC, size 0x4
    clsEnergyFlow2D* m_pcAddLine;  // offset 0xE0, size 0x4
};

#endif // TRICKRESULTRANK2D_HPP
