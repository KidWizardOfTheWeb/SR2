#ifndef PLAYERDEBUG_HPP
#define PLAYERDEBUG_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsPlayerTask;

// total size: 0x14
class _DebugDrawSphere {
public:
    NNS_VECTOR sPos; // offset 0x0
    u32 u32Color;    // offset 0xC
    f32 f32Size;     // offset 0x10
};

class clsPlayerDebug {
public:
    enum enmMode {
        MODE_NORMAL = 0,
        MODE_CURVE_CHECK = 1,
        MAX_MODE_NUM = 2,
    };

    enum enmFlag {
        FLAG_CLEAR = 0,
        FLAG_NOT_GRAVITY = 1,
    };

    clsPlayerDebug(clsPlayerTask* param_1);
    ~clsPlayerDebug();

    void execute();
    void update();
    void draw();
    void test();

    clsPlayerTask* getPlayerTaskPtr();

private:
    f32 m_sDrawSphereMtx[4][4];          // offset 0x0, size 0x40
    NNS_VECTORFAST m_sFixPosVecFast;     // offset 0x40, size 0x10
    NNS_VECTORFAST m_sDistVecFast[2];    // offset 0x50, size 0x20
    NNS_VECTOR m_asNrmLineBuff[512][2];  // offset 0x70, size 0x3000
    NNS_VECTOR m_asPstLineBuff[512][2];  // offset 0x3070, size 0x3000
    NNS_VECTOR m_asVlcLineBuff[512][2];  // offset 0x6070, size 0x3000
    NNS_VECTOR m_asDrawLine[2];          // offset 0x9070, size 0x18
    clsPlayerTask* m_pcPlayer;           // offset 0x9088, size 0x4
    enmMode m_eMode;                     // offset 0x908C, size 0x4
    enmFlag m_eFlag;                     // offset 0x9090, size 0x4
    f32 m_f32Speed;                      // offset 0x9094, size 0x4
    f32 m_f32Distance;                   // offset 0x9098, size 0x4
    f32 m_f32TimerMin;                   // offset 0x909C, size 0x4
    f32 m_f32TimerSec;                   // offset 0x90A0, size 0x4
    f32 m_f32TimerMSec;                  // offset 0x90A4, size 0x4
    f32 m_f32JumpHeight;                 // offset 0x90A8, size 0x4
    s32 m_s32ActiveLineBuffNo;           // offset 0x90AC, size 0x4
    u32 m_u32DrawLineColor;              // offset 0x90B0, size 0x4
    s32 m_s32MaxSpeed;                   // offset 0x90B4, size 0x4
    s32 m_s32Accele;                     // offset 0x90B8, size 0x4
    f32 m_f32GripRate;                   // offset 0x90BC, size 0x4
    f32 m_f32CountFrame;                 // offset 0x90C0, size 0x4
    u32 m_u32SphereColor;                // offset 0x90C4, size 0x4
    f32 m_f32DrawSphereFrame;            // offset 0x90C8, size 0x4
    s8 m_s8JumpFlag;                     // offset 0x90CC, size 0x1
    u8 m_bIsSelectRestart;               // offset 0x90CD, size 0x1
    s8 m_s8GearAlpha;                    // offset 0x90CE, size 0x1
    vector m_vecDrawSphere;              // offset 0x90D0, size 0xC
    vector m_vecDrawSphereOld;           // offset 0x90DC, size 0xC
    _DebugDrawSphere m_sDrawSphere[100]; // offset 0x90E8, size 0x7D0

    static enmFlag m_eAllFlag;
};

#endif // PLAYERDEBUG_HPP
