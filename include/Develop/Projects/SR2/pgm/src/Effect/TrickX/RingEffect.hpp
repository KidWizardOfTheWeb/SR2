#ifndef RINGEFFECT_HPP
#define RINGEFFECT_HPP

#include "Develop/Projects/SR2/pgm/src/Effect/ObjectEffect.hpp"
#include "usr/local/sega/nn/src/Matrix/nnquaternion.h"

// total size: 0xF0
class clsTrickXRingEffect_Task : public clsBaseEffect_Task {
public:
    virtual ~clsTrickXRingEffect_Task();

    virtual void execute();

    virtual void draw();

    u32 m_u32ViewNo;           // offset 0xD0, size 0x4
    enmNo m_ePlayerNo;         // offset 0xD4, size 0x4
    NNS_QUATERNION m_sRotQuat; // offset 0xD8, size 0x10
};

#endif // RINGEFFECT_HPP
