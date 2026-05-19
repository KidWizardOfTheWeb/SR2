#ifndef BGCOLOR_HPP
#define BGCOLOR_HPP

#include "types.h"

// total size: 0x4
struct stcBgColor {
    u8 m_u8a; // offset 0x0, size 0x1
    u8 m_u8b; // offset 0x1, size 0x1
    u8 m_u8g; // offset 0x2, size 0x1
    u8 m_u8r; // offset 0x3, size 0x1
};

#endif // BGCOLOR_HPP
