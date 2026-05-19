#ifndef REQUESTARRAY_HPP
#define REQUESTARRAY_HPP

#include "types.h"

// total size: 0x8
struct stcRequestArray {
    u32 u32Id;   // offset 0x0, size 0x4
    f32 f32Dist; // offset 0x4
};

#endif // REQUESTARRAY_HPP
