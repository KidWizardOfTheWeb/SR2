#ifndef GEARCHENGE_HPP
#define GEARCHENGE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Effect/ObjectEffect.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0xF0
class clsGearChengeEffect_Task : public clsBaseEffect_Task {
public:
    ~clsGearChengeEffect_Task();

    virtual void execute();

    virtual void draw();

    NNS_VECTORFAST m_sPosVecFast; // offset 0xD0, size 0x10
    u32 m_u32Lv;                  // offset 0xE0, size 0x4
};

#endif // GEARCHENGE_HPP
