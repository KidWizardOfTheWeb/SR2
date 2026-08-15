#ifndef DEBRIPARTSBASE_HPP
#define DEBRIPARTSBASE_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/FrameControl.hpp"

// total size: 0x30
class clsDebriPartsBase {
public:
    NNS_VECTORFAST m_sPosVecFast;                // offset 0x0, size 0x10
    clsFrameControl m_cBreakFrame;               // offset 0x10, size 0x8
    s32 m_s32NodeNo;                             // offset 0x18, size 0x4
    void (*m_pFuncBreakEffect)(NNS_VECTORFAST&); // offset 0x1C, size 0x4
    u8 m_bHide;                                  // offset 0x20, size 0x1

    clsDebriPartsBase() {}
    ~clsDebriPartsBase() {}
    virtual void reset();
    virtual void update() = 0;
    virtual void startBreak(NNS_VECTORFAST* psPosVecFast, NNS_VECTORFAST* psVelocityVecFast) = 0;
    virtual void draw(NNS_OBJECT* psObject, f32 f32ClipSqDist) = 0;
    virtual void draw(NNS_OBJECT* psObject, f32 f32ClipSqDist, NNS_VECTOR* psScaleVec) {}
    virtual void drawAlpha(NNS_OBJECT* psObject, f32 f32ClipSqDist) {}
    virtual void drawAlpha(NNS_OBJECT* psObject, f32 f32ClipSqDist, NNS_VECTOR* psScaleVec) {}
    virtual void drawLocalRotate(NNS_OBJECT* psObject, f32 f32ClipSqDist) {}

    void setInfo(s32 s32NodeNo, f32 f32Frame, void (*pFunc)(const NNS_VECTORFAST&));
    f32 getAlpha();
};

#endif // DEBRIPARTSBASE_HPP
