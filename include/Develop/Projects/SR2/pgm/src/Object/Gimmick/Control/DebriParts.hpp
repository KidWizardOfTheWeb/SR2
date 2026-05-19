#ifndef DEBRIPARTS_HPP
#define DEBRIPARTS_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/DebriPartsBase.hpp"

// total size: 0x60
class clsDebriParts : public clsDebriPartsBase {
public:
    clsDebriParts() {}
    virtual ~clsDebriParts() {}

    virtual void reset();
    virtual void update();
    virtual void startBreak(NNS_VECTORFAST* pParam1, NNS_VECTORFAST* pParam2);
    virtual void draw(NNS_OBJECT* pParam1, f32 f32Param2);
    virtual void draw(NNS_OBJECT* pParam1, f32 f32Param2, NNS_VECTOR* pParam3);
    virtual void drawLocalRotate(NNS_OBJECT* pParam1, f32 f32Param2);
    virtual void drawAlpha(NNS_OBJECT* pParam1, f32 f32Param2);
    virtual void drawAlpha(NNS_OBJECT* pParam1, f32 f32Param2, NNS_VECTOR* pParam3);

    NNS_VECTORFAST m_sAngleVecFast;      // offset 0x30, size 0x10
    NNS_VECTORFAST m_sVelocityFast;      // offset 0x40, size 0x10
    NNS_VECTORFAST m_sAngleVelocityFast; // offset 0x50, size 0x10
};

#endif // DEBRIPARTS_HPP
