#ifndef DEBUGTASK_HPP
#define DEBUGTASK_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2CamCtrl.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0xC
struct stcColGroupNo {
    u32 u32Enable;  // offset 0x0, size 0x4
    u32 u32No;      // offset 0x4, size 0x4
    u32 u32GroupNo; // offset 0x8, size 0x4
};

// total size: 0x30
struct stcTriangle {
    NNS_PRIM3D_PC sPoint[3]; // offset 0x0, size 0x30
};

// total size: 0x70
class clsDebugColliTask_Task : public clsSingleton<clsDebugColliTask_Task>, public clsTask {
public:
    vector m_vecvecsTriangle; // offset 0x58, size 0xC
    vector m_vecsGroup;       // offset 0x64, size 0xC
};

// total size: 0x70
class clsDebugLineTask : public clsTask {
public:
    NNS_VECTOR m_asVec[2]; // offset 0x54, size 0x18
    u32 m_u32Color;        // offset 0x6C, size 0x4
};

// total size: 0x90
class clsDebugLineTask_Task : public clsTask {
public:
    NNS_VECTORFAST m_asLineVF[2]; // offset 0x60, size 0x20
    u32 m_u32Color;               // offset 0x80, size 0x4
    f32 m_f32AliveFrame;          // offset 0x84, size 0x4
    u8 m_u8IsDrawSphere;          // offset 0x88, size 0x1
};

// total size: 0xB0
class clsDebugTaskCam_Task : public clsTask {
public:
    NNS_VECTORFAST m_sPos;                // offset 0x60, size 0x10
    NNS_CAMERA_TARGET_UPVECTOR m_sCamera; // offset 0x70, size 0x38
    u32 m_u32Counter;                     // offset 0xA8, size 0x4
    u32 m_u32Color;                       // offset 0xAC, size 0x4
};

class clsDebugTask_Task : public clsTask {
public:
    enum enmFlash {
        NON_FLASH = 0,
        FLASH = 1,
    };

    clsDebugTask_Task(s32 s32xI,
                      s32 s32yI,
                      u32 u32FrameI,
                      u32 u32DpColorI,
                      u32 u32BgColorI,
                      enmFlash eFlashI,
                      c8* pc8FmtI,
                      ...);
    clsDebugTask_Task(s32 s32xI,
                      s32 s32yI,
                      u32 u32FrameI,
                      u32 u32DpColorI,
                      u32 u32BgColorI,
                      enmFlash eFlashI,
                      const c8* opc8StrI);
    virtual ~clsDebugTask_Task() {}

    void execute();
    void draw();

public:
    s16 s16x_;       // offset 0x54, size 0x2
    s16 s16y_;       // offset 0x56, size 0x2
    f32 f32Frame_;   // offset 0x58, size 0x4
    u32 u32DpColor_; // offset 0x5C, size 0x4
    u32 u32BgColor_; // offset 0x60, size 0x4
    c8 ac8Str_[256]; // offset 0x64, size 0x100
    u8 bFlash_;      // offset 0x164, size 0x1
};

#endif // DEBUGTASK_HPP
