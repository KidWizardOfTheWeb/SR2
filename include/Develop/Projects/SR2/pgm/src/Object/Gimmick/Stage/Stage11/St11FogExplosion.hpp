#ifndef ST11FOGEXPLOSION_HPP
#define ST11FOGEXPLOSION_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/FrameControl.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0x90
class clsFogExplosion_Task : public clsTask {
public:
    virtual ~clsFogExplosion_Task();

    virtual void execute();

    NNS_VECTORFAST m_sPosVecFast;    // offset 0x60, size 0x10
    clsFrameControl m_cFrameControl; // offset 0x70, size 0x8
    f32 m_f32Light;                  // offset 0x78, size 0x4
    f32 m_f32DownK;                  // offset 0x7C, size 0x4
    u8 m_u8PortalType;               // offset 0x80, size 0x1

    static f32 m_tof32RequestFrame;
};

#endif // ST11FOGEXPLOSION_HPP
