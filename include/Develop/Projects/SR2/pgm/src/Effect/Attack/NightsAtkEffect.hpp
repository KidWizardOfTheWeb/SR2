#ifndef NIGHTSATKEFFECT_HPP
#define NIGHTSATKEFFECT_HPP

#include "types.h"
#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"

class clsPlayerTask;

// total size: 0x90
class clsNightsAtkEffect {
public:
    clsNightsAtkEffect(clsPlayerTask* pcPlayer, f32 f32FrameI);
    virtual ~clsNightsAtkEffect();

    virtual void reset();
    virtual void draw();

    clsPlayerTask* m_pcPlayer;      // offset 0x4, size 0x4
    s16 m_s16Alpha;                 // offset 0x8, size 0x2
    f32 m_f32ScrollSpeed;           // offset 0xC, size 0x4
    f32 m_f32LifeFrame;             // offset 0x10, size 0x4
    u32 m_u32ViewNo;                // offset 0x14, size 0x4
    NNS_PRIM2D_PCT m_sPrimitive[6]; // offset 0x18, size 0x78
};

#endif // NIGHTSATKEFFECT_HPP
