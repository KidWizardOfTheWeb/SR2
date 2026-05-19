#ifndef GOALTEXT2D_HPP
#define GOALTEXT2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Temporary2D.hpp"

// total size: 0xB0
class clsGoalText2D_Task : public clsTemporary2D_Task {
public:
    s32 m_s32View;         // offset 0x58, size 0x4
    u8 m_u8Alpha;          // offset 0x5C, size 0x1
    u8 m_u8CurrentAlpha;   // offset 0x5D, size 0x1
    u8 m_u8TextNum;        // offset 0x5E, size 0x1
    u8 m_u8TexStartNo;     // offset 0x5F, size 0x1
    s16 m_s16Left;         // offset 0x60, size 0x2
    s16 m_s16Top;          // offset 0x62, size 0x2
    s32 m_s32CenterX;      // offset 0x64, size 0x4
    f32 m_f32DifWidth;     // offset 0x68, size 0x4
    f32 m_f32DefaultScale; // offset 0x6C, size 0x4
    s16 m_as16MoveX[9];    // offset 0x70, size 0x12
    s16 m_as16MoveMaxX[9]; // offset 0x82, size 0x12
    f32 m_f32CurrentScale; // offset 0x94, size 0x4
    f32 m_f32MaxScale;     // offset 0x98, size 0x4
    f32 m_f32AfterScale;   // offset 0x9C, size 0x4
    f32 m_f32PlayFrame;    // offset 0xA0, size 0x4
    f32 m_f32ScaleFrame;   // offset 0xA4, size 0x4
    f32 m_f32StopFrame;    // offset 0xA8, size 0x4
    f32 m_f32FadeFrame;    // offset 0xAC, size 0x4

    clsGoalText2D_Task(s32 s32Param1);
    virtual ~clsGoalText2D_Task();
    virtual void execute();
    virtual void draw();
};

#endif // GOALTEXT2D_HPP
