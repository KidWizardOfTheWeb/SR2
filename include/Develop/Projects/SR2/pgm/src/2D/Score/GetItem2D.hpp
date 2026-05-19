#ifndef GETITEM2D_HPP
#define GETITEM2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Temporary2D.hpp"

// total size: 0x90
class clsGetItem2D_Task : public clsTemporary2D_Task {
public:
    clsGetItem2D_Task(s32 s32Param1, s32 s32Param2);
    virtual ~clsGetItem2D_Task();

    void execute();
    void draw();

    s32 m_s32View;      // offset 0x58, size 0x4
    s32 m_s32Item;      // offset 0x5C, size 0x4
    u8 m_u8Alpha;       // offset 0x60, size 0x1
    s32 m_s32Width;     // offset 0x64, size 0x4
    s32 m_s32Height;    // offset 0x68, size 0x4
    s32 m_s32CenterX;   // offset 0x6C, size 0x4
    s32 m_s32CenterY;   // offset 0x70, size 0x4
    s32 m_s32DrawX;     // offset 0x74, size 0x4
    s32 m_s32DrawY;     // offset 0x78, size 0x4
    f32 m_f32Scale;     // offset 0x7C, size 0x4
    f32 m_f32DefScale;  // offset 0x80, size 0x4
    f32 m_f32OutScale;  // offset 0x84, size 0x4
    f32 m_f32StopFrame; // offset 0x88, size 0x4
    f32 m_f32FadeFrame; // offset 0x8C, size 0x4
};

#endif // GETITEM2D_HPP
