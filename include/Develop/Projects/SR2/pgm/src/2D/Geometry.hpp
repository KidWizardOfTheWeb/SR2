#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include "types.h"

// total size: 0x4
struct stcGeometry {
    s8 s8tx; // offset 0x0, size 0x1
    s8 s8ty; // offset 0x1, size 0x1
    s8 s8bx; // offset 0x2, size 0x1
    s8 s8by; // offset 0x3, size 0x1
};

#endif // GEOMETRY_HPP
