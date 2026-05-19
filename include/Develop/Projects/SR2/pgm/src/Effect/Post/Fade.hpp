#ifndef POST_FADE_HPP
#define POST_FADE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/System/ScissorRect.hpp"

// total size: 0x70
class clsFade_Task : public clsTask {
public:
    enum enmType {
        TYPE_FRONT = 0,
        TYPE_BACK = 1,
    };

    clsFade_Task(u32, f32, enmType, u32, f32, u32, u32) : clsTask(0, 0) {}
    virtual ~clsFade_Task() {}

    virtual void execute();
    virtual void draw();

    f32 m_f32EndFrame;            // offset 0x54, size 0x4
    f32 m_f32LifeFrame;           // offset 0x58, size 0x4
    u32 m_u32RgbCol;              // offset 0x5C, size 0x4
    f32 m_f32MaxAlpha;            // offset 0x60, size 0x4
    enmType m_eType;              // offset 0x64, size 0x4
    stcScissorRect* m_opsScissor; // offset 0x68, size 0x4
    u8 m_bIn_OutIn;               // offset 0x6C, size 0x1
};

#endif // POST_FADE_HPP
