#ifndef POST_NEGA_HPP
#define POST_NEGA_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Effect/Post/GravityWave/PS2_GravityWave.hpp"

class clsNega_Task : public clsGravityWave_Task {
public:
    clsNega_Task(u32 u32Param1,
                 u8 u8Param2,
                 u32 u32Param3,
                 f32 f32Param4,
                 f32 f32Param5,
                 f32 f32Param6,
                 f32 f32Param7);
    virtual ~clsNega_Task() {}

    void execute();
    void draw();

    u32 m_u32ViewNo;    // offset 0xD0, size 0x4
    u8 m_u8Type;        // offset 0xD4, size 0x1
    u32 m_u32Rgb[4];    // offset 0xD8, size 0x10
    f32 m_f32Frame;     // offset 0xE8, size 0x4
    f32 m_f32SubFrame;  // offset 0xEC, size 0x4
    f32 m_f32EndFrame;  // offset 0xF0, size 0x4
    f32 m_f32WaitFrame; // offset 0xF4, size 0x4
};

#endif // POST_NEGA_HPP
