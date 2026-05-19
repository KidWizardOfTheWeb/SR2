#ifndef SRPAD_HPP
#define SRPAD_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOPeripheral.hpp"

// total size: 0x30
struct stcPeripheral {
    clsOOPeripheral::stcPeripheral sOO; // offset 0x0, size 0x20
    s8 m_s8X1;                          // offset 0x20, size 0x1
    s8 m_s8Y1;                          // offset 0x21, size 0x1
    s8 m_s8X2;                          // offset 0x22, size 0x1
    s8 m_s8Y2;                          // offset 0x23, size 0x1
    u16 m_u16RumbleFrame;               // offset 0x24, size 0x2
    u16 m_u16RumbleFrameOld;            // offset 0x26, size 0x2
    u8 m_u8L1;                          // offset 0x28, size 0x1
    u8 m_u8R1;                          // offset 0x29, size 0x1
    u8 m_u8L2;                          // offset 0x2A, size 0x1
    u8 m_u8R2;                          // offset 0x2B, size 0x1
    u8 m_su8PadInitFlag;                // offset 0x2C, size 0x1
    u8 m_u8RetryCnt;                    // offset 0x2D, size 0x1
    u8 m_bDisableRumble;                // offset 0x2E, size 0x1
    u8 m_bConfigueDisableRumble;        // offset 0x2F, size 0x1
};

#endif // SRPAD_HPP
