#ifndef LERPPARAM_HPP
#define LERPPARAM_HPP

#include "types.h"

// total size: 0x10
class clsLerpParam {
public:
    clsLerpParam() : m_f32Target(0.0f), m_f32Result(0.0f), m_f32Add(0.0f), m_f32Frame(0.0f) {}

    void startLerp(f32 f32Base, f32 f32Target, f32 f32Frame);
    void update();

    f32 m_f32Target; // offset 0x0, size 0x4
    f32 m_f32Result; // offset 0x4, size 0x4
    f32 m_f32Add;    // offset 0x8, size 0x4
    f32 m_f32Frame;  // offset 0xC, size 0x4
};

#endif // LERPPARAM_HPP
