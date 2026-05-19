#ifndef DEBRIPARTSBASE_HPP
#define DEBRIPARTSBASE_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/FrameControl.hpp"

// total size: 0x30
class clsDebriPartsBase {
public:
    clsDebriPartsBase() {}
    virtual ~clsDebriPartsBase() {}
    virtual void reset();
    virtual void update() = 0;
    virtual void startBreak(NNS_VECTORFAST* pParam1, NNS_VECTORFAST* pParam2) = 0;
    virtual void draw(NNS_OBJECT* pParam1, f32 f32Param2) = 0;
    virtual void draw(NNS_OBJECT* pParam1, f32 f32Param2, NNS_VECTOR* pParam3) {}
    virtual void drawAlpha(NNS_OBJECT* pParam1, f32 f32Param2) {}
    virtual void drawAlpha(NNS_OBJECT* pParam1, f32 f32Param2, NNS_VECTOR* pParam3) {}
    virtual void drawLocalRotate(NNS_OBJECT* pParam1, f32 f32Param2) {}

    void setInfo(s32 s32Param1, f32 f32Param2, void (*)(const NNS_VECTORFAST&));
    f32 getAlpha();

    NNS_VECTORFAST m_sPosVecFast;                // offset 0x0, size 0x10
    clsFrameControl m_cBreakFrame;               // offset 0x10, size 0x8
    s32 m_s32NodeNo;                             // offset 0x18, size 0x4
    void (*m_pFuncBreakEffect)(NNS_VECTORFAST&); // offset 0x1C, size 0x4
    u8 m_bHide;                                  // offset 0x20, size 0x1
};

#endif // DEBRIPARTSBASE_HPP
