#ifndef THROUGHLAP2D_HPP
#define THROUGHLAP2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Score2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Temporary2D.hpp"

// total size: 0x80
class clsThroughLap2D_Task : public clsTemporary2D_Task {
public:
    clsThroughLap2D_Task(u32 u32View, s32 s32Lap);
    virtual ~clsThroughLap2D_Task();
    virtual void execute();
    virtual void draw();
    virtual void reset();

    u8 m_bFinal; // offset 0x58, size 0x1

    s32 m_s32Lap; // offset 0x5C, size 0x4

    s16 m_s16DrawX; // offset 0x60, size 0x2

    s16 m_s16BaseX; // offset 0x62, size 0x2

    s16 m_s16BaseY; // offset 0x64, size 0x2

    s16 m_s16StopX; // offset 0x66, size 0x2

    s16 m_s16OutX; // offset 0x68, size 0x2

    f32 m_f32DrawScale; // offset 0x6C, size 0x4

    f32 m_f32MoveFrame; // offset 0x70, size 0x4

    f32 m_f32StopFrame; // offset 0x74, size 0x4

    f32 m_f32OutFrame; // offset 0x78, size 0x4

    stcViewRect* m_opsRect; // offset 0x7C, size 0x4

    // total size: 0x80
};

#endif // THROUGHLAP2D_HPP
