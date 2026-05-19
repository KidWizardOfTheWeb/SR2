#ifndef ENERGYFLOW2D_HPP
#define ENERGYFLOW2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreParts2D.hpp"

class clsScore2D_Task;

// total size: 0x40
class clsEnergyFlow2D {
public:
    clsEnergyFlow2D(s32 s32PosX,
                    s32 s32PosY,
                    const f32* opf32Frame,
                    const stcLinePoint* opsPoint,
                    s32 s32Num,
                    clsScore2D_Task* pcScore,
                    f32 f32MarginFrame);
    ~clsEnergyFlow2D();
    void draw();
    void execute();
    void updateTail();
    void drawEnergyLine();

    u32 m_u32Mode;              // offset 0x0, size 0x4
    s32 m_s32BaseX;             // offset 0x4, size 0x4
    s32 m_s32BaseY;             // offset 0x8, size 0x4
    u32 m_u32Flg;               // offset 0xC, size 0x4
    s32 m_s32Num;               // offset 0x10, size 0x4
    f32 m_f32HeadScale;         // offset 0x14, size 0x4
    f32 m_f32MarginFrame;       // offset 0x18, size 0x4
    stcLinePoint m_sHeadPoint;  // offset 0x1C, size 0xC
    stcLinePoint m_sTailPoint;  // offset 0x28, size 0xC
    f32* m_opf32TargetFrame;    // offset 0x34, size 0x4
    stcLinePoint* m_opsPoint;   // offset 0x38, size 0x4
    clsScore2D_Task* m_pcScore; // offset 0x3C, size 0x4
};

#endif // ENERGYFLOW2D_HPP
