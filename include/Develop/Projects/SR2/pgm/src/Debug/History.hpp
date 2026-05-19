#ifndef HISTORY_HPP
#define HISTORY_HPP

#include "types.h"

// total size: 0xC
struct stcHistory {
    u32 m_u32Average; // offset 0x0, size 0x4
    c8* m_opc8Name;   // offset 0x4, size 0x4
    u32 m_u32Count;   // offset 0x8, size 0x4
};

#endif // HISTORY_HPP
