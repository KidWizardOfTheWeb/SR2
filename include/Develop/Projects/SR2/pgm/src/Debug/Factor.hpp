#ifndef FACTOR_HPP
#define FACTOR_HPP

#include "types.h"

// total size: 0x1C
struct stcFactor {
    c8* m_opc8Name;        // offset 0x0, size 0x4
    f32 m_f32Average;      // offset 0x4, size 0x4
    u32 m_u32ParentsNum;   // offset 0x8, size 0x4
    s16 m_s16OpenNum;      // offset 0xC, size 0x2
    u16 m_u16MineNum;      // offset 0xE, size 0x2
    u32 m_u32BeginTick;    // offset 0x10, size 0x4
    u32 m_u32Tick;         // offset 0x14, size 0x4
    u32 m_u32ChildrenTick; // offset 0x18, size 0x4
};

#endif // FACTOR_HPP
