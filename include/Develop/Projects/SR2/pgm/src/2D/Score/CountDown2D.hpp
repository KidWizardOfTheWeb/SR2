#ifndef COUNTDOWN2D_HPP
#define COUNTDOWN2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Temporary2D.hpp"

// total size: 0x88
class clsCountDown2D_Task : public clsTemporary2D_Task {
public:
    virtual ~clsCountDown2D_Task();
    virtual void execute();
    virtual void draw();

    clsCountDown2D_Task();

    void drawStartMap();

    u8 m_bStartCheck;       // offset 0x58, size 0x1
    s16 m_s16Left;          // offset 0x5A, size 0x2
    s16 m_s16Top;           // offset 0x5C, size 0x2
    u8 m_u8LastSecond;      // offset 0x5E, size 0x1
    u8 m_u8IconUserAlpha;   // offset 0x5F, size 0x1
    u8 m_u8NumWidth;        // offset 0x60, size 0x1
    u8 m_u8NumHeight;       // offset 0x61, size 0x1
    u8 m_u8SNumWidth;       // offset 0x62, size 0x1
    u8 m_u8SNumHeight;      // offset 0x63, size 0x1
    u8 m_u8MarkWidth;       // offset 0x64, size 0x1
    u8 m_u8MarkHeight;      // offset 0x65, size 0x1
    f32 m_f32Scale;         // offset 0x68, size 0x4
    f32 m_f32MaxScale;      // offset 0x6C, size 0x4
    f32 m_f32DefScale;      // offset 0x70, size 0x4
    f32 m_f32MarginScale;   // offset 0x74, size 0x4
    f32 m_f32ScaleFrame;    // offset 0x78, size 0x4
    s16 m_s16MapLeft;       // offset 0x7C, size 0x2
    s16 m_s16MapTop;        // offset 0x7E, size 0x2
    s16 m_s16MapWidth;      // offset 0x80, size 0x2
    s16 m_s16MapHeight;     // offset 0x82, size 0x2
    s16 m_s16MapLineHeight; // offset 0x84, size 0x2
};

#endif // COUNTDOWN2D_HPP
