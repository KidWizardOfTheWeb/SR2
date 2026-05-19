#ifndef BASEGRAVITYWAVE_HPP
#define BASEGRAVITYWAVE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0xC0
class clsBaseGravityWave_Task : public clsTask {
public:
    virtual ~clsBaseGravityWave_Task() {}
    clsBaseGravityWave_Task(u32 param_1, u32 param_2)
        : clsTask(param_1, 0) {} // [verify params from ASM]

    virtual void draw();

    void cancel(u32 param_1) {}
    void start(u32 param_1, u32 param_2) {}
    u8 isStart(u32 param_1) const { return 0; }

    f32 m_sOrthoMtx[4][4];   // offset 0x60, size 0x40
    f32 m_af32InterColor[4]; // offset 0xA0, size 0x10
    u8 m_eMode[4];           // offset 0xB0, size 0x4
    u8 m_eType[4];           // offset 0xB4, size 0x4
};

#endif // BASEGRAVITYWAVE_HPP
