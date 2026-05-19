#ifndef SCORECOM2D_HPP
#define SCORECOM2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreInfo2D.hpp"

class clsScore2D_Task;

// total size: 0x4
struct stcComStatus {
    s16 s16DrawX; // offset 0x0, size 0x2
    s16 s16DrawY; // offset 0x2, size 0x2
};

// total size: 0x40
class clsScoreCom2D {
public:
    clsScoreCom2D(clsScore2D_Task* pcParent);
    virtual ~clsScoreCom2D();

    void init();
    void _drawComPoint(u32 u32ComNo, u32 u32PlayerNo, u32 u32DrawNum, s32 s32Digit, f32 f32Dist);

    virtual void draw() {}

    clsScore2D_Task* m_pcParent;   // offset 0x4, size 0x4
    stcUnionStatus m_sUnionStatus; // offset 0x8, size 0x18
    stcComStatus m_asComStatus[7]; // offset 0x20, size 0x1C
    u8 m_bDraw;                    // offset 0x3C, size 0x1
};

#endif // SCORECOM2D_HPP
