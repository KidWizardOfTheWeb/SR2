#ifndef SCREEN2D_HPP
#define SCREEN2D_HPP

#include "types.h"

// total size: 0x40
class clsScreen2D {
public:
    virtual ~clsScreen2D() {}

    clsScreen2D();

    s32 getCenterX() const
    {
        // likely: return m_s32CenterX;
        return m_s32CenterX;
    }
    s32 getCenterY() const
    {
        // likely: return m_s32CenterY;
        return m_s32CenterY;
    }

    s32 m_s32ViewLeft;       // offset 0x4, size 0x4
    s32 m_s32ViewTop;        // offset 0x8, size 0x4
    s32 m_s32ViewRight;      // offset 0xC, size 0x4
    s32 m_s32ViewBottom;     // offset 0x10, size 0x4
    s32 m_s32ScreenW;        // offset 0x14, size 0x4
    s32 m_s32ScreenH;        // offset 0x18, size 0x4
    s32 m_s32SafeAreaWidth;  // offset 0x1C, size 0x4
    s32 m_s32SafeAreaHeight; // offset 0x20, size 0x4
    s32 m_s32SafeAreaLeft;   // offset 0x24, size 0x4
    s32 m_s32SafeAreaTop;    // offset 0x28, size 0x4
    s32 m_s32SafeAreaRight;  // offset 0x2C, size 0x4
    s32 m_s32SafeAreaBottom; // offset 0x30, size 0x4
    s32 m_s32CenterX;        // offset 0x34, size 0x4
    s32 m_s32CenterY;        // offset 0x38, size 0x4
    u8 m_u8CenterMargin;     // offset 0x3C, size 0x1
};

#endif // SCREEN2D_HPP
