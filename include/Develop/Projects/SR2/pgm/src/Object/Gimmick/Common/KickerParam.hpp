#ifndef KICKERPARAM_HPP
#define KICKERPARAM_HPP

#include "types.h"

// total size: 0xC
struct stcKickerParam {
    f32 f32Speed;   // offset 0x0, size 0x4
    f32 f32Gravity; // offset 0x4, size 0x4
    f32 f32Jump;    // offset 0x8, size 0x4
};

#endif // KICKERPARAM_HPP
