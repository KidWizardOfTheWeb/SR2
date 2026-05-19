#ifndef SCORETIMER2D_HPP
#define SCORETIMER2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Score2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreInfo2D.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

// total size: 0x14
struct stcTimerData {
    s16 s16OpenEnd;     // offset 0x0, size 0x2
    s16 s16LinePosY;    // offset 0x2, size 0x2
    s8 s8NumPosYDiff;   // offset 0x4, size 0x1
    s8 s8ClosedW;       // offset 0x5, size 0x1
    s8 s8LineHeight;    // offset 0x6, size 0x1
    u8 u8NumW;          // offset 0x7, size 0x1
    u8 u8NumH;          // offset 0x8, size 0x1
    f32 f32MarginScale; // offset 0xC, size 0x4
    u8 u8SingleW;       // offset 0x10, size 0x1
    u8 u8DoubleW;       // offset 0x11, size 0x1
};

// total size: 0x24
class clsScoreTimer2D {
public:
    clsScoreTimer2D(clsScore2D_Task* pParam1);
    virtual ~clsScoreTimer2D();

    void init();
    void execute();
    void draw();
    void _drawLine();
    void _drawTime();

    stcUnionStatus m_sUnionStatus; // offset 0x0, size 0x14
    u8 m_bDraw;                    // offset 0x14, size 0x1
    u8 m_bLine;                    // offset 0x15, size 0x1
    clsScore2D_Task* m_pcParent;   // offset 0x18, size 0x4
    stcTimerData* m_opsDrawData;   // offset 0x1C, size 0x4
};

#endif // SCORETIMER2D_HPP
