#ifndef FRAMECONTROL_HPP
#define FRAMECONTROL_HPP

#include "types.h"

// total size: 0x8
class clsFrameControl {
public:
    f32 m_f32Frame;      // offset 0x0, size 0x4
    f32 m_f32CountFrame; // offset 0x4, size 0x4

    void start(f32 param) {}            // size:8
    void update() {}                    // size:92
    u8 isEndCount() const { return 0; } // size:60
};

#endif // FRAMECONTROL_HPP
