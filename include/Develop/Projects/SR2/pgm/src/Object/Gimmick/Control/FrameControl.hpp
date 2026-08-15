#ifndef FRAMECONTROL_HPP
#define FRAMECONTROL_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2System.hpp"

// total size: 0x8
class clsFrameControl {
public:
    f32 m_f32Frame;      // offset 0x0, size 0x4
    f32 m_f32CountFrame; // offset 0x4, size 0x4

    u8 isEndCount() const { return m_f32Frame == -1.0f || m_f32Frame == 0.0f; }

    void start(f32 f32Frame) { m_f32Frame = f32Frame; }
    f32 getFrame() const { return m_f32Frame; }

    void update()
    {
        if (getFrame() > 0.0f) {
            m_f32Frame -= clsPfSystem::GS()->getFrameRateAdd();
            if (m_f32Frame < 0.0f) {
                m_f32Frame = 0.0f;
            }
        } else if (getFrame() == 0.0f) {
            m_f32Frame = -1.0f;
        }
    }
};

#endif // FRAMECONTROL_HPP
