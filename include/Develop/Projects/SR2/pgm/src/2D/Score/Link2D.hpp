#ifndef LINK2D_HPP
#define LINK2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Temporary2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/EnergyFlow2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreHint2D.hpp"

namespace nspLink2D {
// total size: 0x38
struct stcLinkData {
    s16 s16MoveMax;        // offset 0x0, size 0x2
    f32 f32WaitFrame;      // offset 0x4, size 0x4
    f32 f32TextY;          // offset 0x8, size 0x4
    f32 f32LinkScale;      // offset 0xC, size 0x4
    f32 f32NumScale;       // offset 0x10, size 0x4
    f32 f32NumMaxScale;    // offset 0x14, size 0x4
    s16 s16LineStartX;     // offset 0x18, size 0x2
    s16 s16LineMiddleX;    // offset 0x1A, size 0x2
    s16 s16LineEndX;       // offset 0x1C, size 0x2
    s16 s16LineStartY;     // offset 0x1E, size 0x2
    s16 s16LineEndY;       // offset 0x20, size 0x2
    u8 u8ELineHeight;      // offset 0x22, size 0x1
    f32 f32LinePointFrame; // offset 0x24, size 0x4
    f32 f32MarginFrame;    // offset 0x28, size 0x4
    f32 f32HeadScale;      // offset 0x2C, size 0x4
    f32 f32HeadAddFrame;   // offset 0x30, size 0x4
    f32 f32HeadAddScale;   // offset 0x34, size 0x4
};

struct stcEnergyPoint {
    s32 s32BaseX;            // offset 0x0, size 0x4
    s32 s32BaseY;            // offset 0x4, size 0x4
    s32 s32Dir;              // offset 0x8, size 0x4
    f32 f32FrameMax;         // offset 0xC, size 0x4
    stcLinePoint asPoint[4]; // offset 0x10, size 0x30
};

void setupEnergyPoint();

extern stcLinkData DrawData1v;
extern stcLinkData DrawData2v;
extern stcLinkData DrawData4v;
extern stcLinkData* opsDrawData;
extern stcEnergyPoint asEnergyPoint[4];
extern f32 tf32EnergyFrameMax;
} // namespace nspLink2D

// total size: 0x84
class clsLink2D_Task : public clsTemporary2D_Task {
public:
    clsLink2D_Task(s32 s32PlayerNo, s32 s32Link, const s32* ops32SrcLink);
    virtual ~clsLink2D_Task();
    virtual void execute();
    virtual void draw();

    void _drawLink();
    void exeAddLine();

    u32 m_u32View;                 // offset 0x58, size 0x4
    u32 m_u32Flg;                  // offset 0x5C, size 0x4
    s32 m_s32Link;                 // offset 0x60, size 0x4
    s32* m_ops32SrcLink;           // offset 0x64, size 0x4
    f32 m_f32NumScale;             // offset 0x68, size 0x4
    s16 m_s16Move;                 // offset 0x6C, size 0x2
    u8 m_u8Alpha;                  // offset 0x6E, size 0x1
    u8 m_u8HideFlg;                // offset 0x6F, size 0x1
    f32 m_f32EnergyFrame;          // offset 0x70, size 0x4
    f32 m_f32EnergySubFrame;       // offset 0x74, size 0x4
    clsPlayerTask* m_pcPlayer;     // offset 0x78, size 0x4
    clsEnergyFlow2D* m_pcBaseLine; // offset 0x7C, size 0x4
    clsEnergyFlow2D* m_pcAddLine;  // offset 0x80, size 0x4
};

#endif // LINK2D_HPP
