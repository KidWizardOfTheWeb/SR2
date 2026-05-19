#ifndef BONUSPOINT2D_HPP
#define BONUSPOINT2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Temporary2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreParts2D.hpp"

class clsBonusPoint2D_Task;

namespace nspBonusPoint2D {
// total size: 0x40
struct stcBonusPointData {
    s16 s16MoveMax;        // offset 0x0, size 0x2
    f32 f32WaitFrame;      // offset 0x4, size 0x4
    f32 f32TextScale;      // offset 0x8, size 0x4
    f32 f32NumScale;       // offset 0xC, size 0x4
    f32 f32MarginScale;    // offset 0x10, size 0x4
    f32 f32ShotFrame;      // offset 0x14, size 0x4
    f32 f32ShotScale;      // offset 0x18, size 0x4
    f32 f32CircleX;        // offset 0x1C, size 0x4
    f32 f32CircleY;        // offset 0x20, size 0x4
    u8 u8LineStartX;       // offset 0x24, size 0x1
    u8 u8LineMiddleX;      // offset 0x25, size 0x1
    u8 u8LineEndX;         // offset 0x26, size 0x1
    s8 s8LineStartY;       // offset 0x27, size 0x1
    s8 s8LineEndY;         // offset 0x28, size 0x1
    u8 u8ELineHeight;      // offset 0x29, size 0x1
    f32 f32LinePointFrame; // offset 0x2C, size 0x4
    f32 f32MarginFrame;    // offset 0x30, size 0x4
    f32 f32HeadScale;      // offset 0x34, size 0x4
    f32 f32HeadAddFrame;   // offset 0x38, size 0x4
    f32 f32HeadAddScale;   // offset 0x3C, size 0x4
};

// total size: 0x4C
struct stcEnergyPoint {
    s32 s32BaseX;            // offset 0x0, size 0x4
    s32 s32BaseY;            // offset 0x4, size 0x4
    s32 s32Dir;              // offset 0x8, size 0x4
    s32 s32ShotX;            // offset 0xC, size 0x4
    s32 s32ShotY;            // offset 0x10, size 0x4
    s32 s32CircleX;          // offset 0x14, size 0x4
    s32 s32CircleY;          // offset 0x18, size 0x4
    stcLinePoint asPoint[4]; // offset 0x1C, size 0x30
};

void setupEnergyPoint();

extern stcBonusPointData DrawData1v;
extern stcBonusPointData DrawData2v;
extern stcBonusPointData DrawData4v;
extern stcBonusPointData* opsDrawData;
extern stcEnergyPoint asEnergyPoint[4];
extern f32 tf32EnergyFrameMax;
extern clsBonusPoint2D_Task* apcCurentGLinkPoint[5];
} // namespace nspBonusPoint2D

// total size: 0x90
class clsBonusPoint2D_Task : public clsTemporary2D_Task {
public:
    virtual ~clsBonusPoint2D_Task();
    virtual void execute();
    virtual void draw();

    clsBonusPoint2D_Task(s32 s32Player, u32 u32Type, f32 f32BonusAgp);

    void _drawShot();
    void _drawPoint();

    u32 m_u32View;                 // offset 0x58, size 0x4
    u32 m_u32Player;               // offset 0x5C, size 0x4
    u32 m_u32Type;                 // offset 0x60, size 0x4
    u32 m_u32Flg;                  // offset 0x64, size 0x4
    f32 m_f32BonusAgp;             // offset 0x68, size 0x4
    f32 m_f32WaitFrame;            // offset 0x6C, size 0x4
    u8 m_u8TextAlpha;              // offset 0x70, size 0x1
    u8 m_u8NumAlpha;               // offset 0x71, size 0x1
    s16 m_s16TextMove;             // offset 0x72, size 0x2
    s16 m_s16NumMove;              // offset 0x74, size 0x2
    f32 m_f32ShotFrame;            // offset 0x78, size 0x4
    f32 m_f32EnergyFrame;          // offset 0x7C, size 0x4
    f32 m_f32EnergySubFrame;       // offset 0x80, size 0x4
    f32 m_f32GlinkWaitFrame;       // offset 0x84, size 0x4
    clsEnergyFlow2D* m_pcBaseLine; // offset 0x88, size 0x4
    clsEnergyFlow2D* m_pcAddLine;  // offset 0x8C, size 0x4
};

#endif // BONUSPOINT2D_HPP
