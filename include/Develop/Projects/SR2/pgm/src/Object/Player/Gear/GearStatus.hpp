#ifndef GEARSTATUS_HPP
#define GEARSTATUS_HPP

#include "types.h"

// total size: 0x8
struct stcGearStatus {
    u16 u16Dash;  // offset 0x0, size 0x2
    u16 u16Limit; // offset 0x2, size 0x2
    u16 u16Power; // offset 0x4, size 0x2
    u16 u16Curve; // offset 0x6, size 0x2
};

#endif // GEARSTATUS_HPP
