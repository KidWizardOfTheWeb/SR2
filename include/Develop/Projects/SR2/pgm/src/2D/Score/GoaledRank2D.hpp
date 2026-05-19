#ifndef GOALEDRANK2D_HPP
#define GOALEDRANK2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Temporary2D.hpp"

// total size: 0x74
class clsGoaledRank2D_Task : public clsTemporary2D_Task {
public:
    clsGoaledRank2D_Task(s32 s32Param1, s32 s32Param2);
    virtual ~clsGoaledRank2D_Task();
    virtual void execute();
    virtual void draw();

    s32 m_s32View;      // offset 0x58, size 0x4
    s32 m_s32Rank;      // offset 0x5C, size 0x4
    u8 m_u8Alpha;       // offset 0x60, size 0x1
    s16 m_s16DrawX;     // offset 0x62, size 0x2
    s16 m_s16DrawY;     // offset 0x64, size 0x2
    f32 m_f32Scale;     // offset 0x68, size 0x4
    f32 m_f32StopFrame; // offset 0x6C, size 0x4
    f32 m_f32FadeFrame; // offset 0x70, size 0x4
};

#endif // GOALEDRANK2D_HPP
