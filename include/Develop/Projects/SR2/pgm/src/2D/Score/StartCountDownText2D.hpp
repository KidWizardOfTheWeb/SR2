#ifndef STARTCOUNTDOWNTEXT2D_HPP
#define STARTCOUNTDOWNTEXT2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Temporary2D.hpp"

class clsCountDownStartText2D_Task : public clsTemporary2D_Task {
public:
    clsCountDownStartText2D_Task();
    virtual ~clsCountDownStartText2D_Task();

    virtual void execute();
    virtual void draw();

    // Members
    s16 m_s16BaseX;     // offset 0x58, size 0x2
    s16 m_s16BaseY;     // offset 0x5A, size 0x2
    s16 m_s16Move;      // offset 0x5C, size 0x2
    s16 m_s16MoveMax;   // offset 0x5E, size 0x2
    u8 m_au8Alpha[3];   // offset 0x60, size 0x3
    f32 m_af32Scale[3]; // offset 0x64, size 0xC
    f32 m_f32InFrame;   // offset 0x70, size 0x4
    f32 m_f32StopFrame; // offset 0x74, size 0x4
    f32 m_f32OutFrame;  // offset 0x78, size 0x4
};

#endif // STARTCOUNTDOWNTEXT2D_HPP
