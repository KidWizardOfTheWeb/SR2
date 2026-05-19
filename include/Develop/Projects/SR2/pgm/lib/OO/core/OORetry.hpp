#ifndef OORETRY_HPP
#define OORETRY_HPP

#include "types.h"

// total size: 0x10
class clsOORetry {
public:
    virtual ~clsOORetry() {}

    f32 m_f32WaitFrame_Max; // offset 0x4, size 0x4
    f32 m_f32WaitFrame;     // offset 0x8, size 0x4
    s8 m_s8Num_Max;         // offset 0xC, size 0x1
    s8 m_s8Num;             // offset 0xD, size 0x1
};

#endif // OORETRY_HPP
