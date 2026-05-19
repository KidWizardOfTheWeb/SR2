#ifndef CURVEAIR_HPP
#define CURVEAIR_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Effect/ObjectEffect.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0xF0
class clsCurveAirEffect_Task : public clsBaseEffect_Task {
public:
    ~clsCurveAirEffect_Task();

    virtual void execute();

    virtual void draw();

    void initVisible();

    u8 getVisible(nspPlayer::enmNo eNo);

    NNS_VECTORFAST m_sPosVecFast; // offset 0xD0, size 0x10
    f32 m_f32Cnt;                 // offset 0xE0, size 0x4
    u32 m_u32Type;                // offset 0xE4, size 0x4
};

#endif // CURVEAIR_HPP
