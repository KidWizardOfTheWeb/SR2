#ifndef VAPORTRAIL_HPP
#define VAPORTRAIL_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsPlayerTask;

// total size: 0x3C
struct stcPlayStatus {
    f32 f32DefScale;        // offset 0x0, size 0x4
    f32 f32RandScale;       // offset 0x4, size 0x4
    f32 f32AddScale;        // offset 0x8, size 0x4
    f32 f32FadeFrame;       // offset 0xC, size 0x4
    f32 f32Height;          // offset 0x10, size 0x4
    NNS_VECTOR sStartVec;   // offset 0x14, size 0xC
    NNS_VECTOR sPowerScale; // offset 0x20, size 0xC
    f32 f32Speed;           // offset 0x2C, size 0x4
    f32 f32TuStart;         // offset 0x30, size 0x4
    f32 f32TuSize;          // offset 0x34, size 0x4
    f32 f32TuSpeed;         // offset 0x38, size 0x4
};

// total size: 0xC
struct stcBaseStatus {
    u8 u8TexNo;      // offset 0x0, size 0x1
    u8 u8Rand;       // offset 0x1, size 0x1
    u8 u8RotZ;       // offset 0x2, size 0x1
    f32 f32MinSpeed; // offset 0x4, size 0x4
    f32 f32MaxSpeed; // offset 0x8, size 0x4
};

// total size: 0xE40
class clsVaporTrail_Task : public clsTask {
public:
    // total size: 0x160
    struct stcParam {
        u16 u16Flg;               // offset 0x0, size 0x2
        u8 u8Num;                 // offset 0x2, size 0x1
        u8 u8MaxAlpha;            // offset 0x3, size 0x1
        s32 s32No;                // offset 0x4, size 0x4
        s32 s32RotZ;              // offset 0x8, size 0x4
        f32 f32Frame;             // offset 0xC, size 0x4
        f32 f32Tu;                // offset 0x10, size 0x4
        f32 f32TuSize;            // offset 0x14, size 0x4
        NNS_VECTOR sPos;          // offset 0x18, size 0xC
        NNS_VECTOR sScale;        // offset 0x24, size 0xC
        NNS_VECTOR sAddScale;     // offset 0x30, size 0xC
        NNS_VECTOR sVec;          // offset 0x3C, size 0xC
        NNS_VECTOR sPower;        // offset 0x48, size 0xC
        f32 sDrawMtx[4][4];       // offset 0x60, size 0x40
        NNS_VECTOR asDrawPos[16]; // offset 0xA0, size 0xC0
    };

    clsVaporTrail_Task(u32 u32View, u32 u32PlayerNo, s32 s32DataNo);
    virtual ~clsVaporTrail_Task() {}

    virtual void execute();
    virtual void draw();

    void updateNormal();

    static NNS_VECTOR StartPoint;
    static NNS_VECTOR AreaVec;

    stcBaseStatus* m_psBaseStatus; // offset 0x54, size 0x4
    stcPlayStatus* m_psPlayStatus; // offset 0x58, size 0x4
    u8 m_u8Play;                   // offset 0x5C, size 0x1
    u32 m_u32Flg;                  // offset 0x60, size 0x4
    s32 m_s32PlayNum;              // offset 0x64, size 0x4
    s32 m_s32MaxPlayNum;           // offset 0x68, size 0x4
    u32 m_u32View;                 // offset 0x6C, size 0x4
    u32 m_u32PlayUser;             // offset 0x70, size 0x4
    f32 m_f32AddSpeed;             // offset 0x74, size 0x4
    clsPlayerTask* m_pcPlayer;     // offset 0x78, size 0x4
    clsTask* m_pcEffectTask;       // offset 0x7C, size 0x4
    stcParam m_asTrails[10];       // offset 0x80, size 0xDC0
};

#endif // VAPORTRAIL_HPP
