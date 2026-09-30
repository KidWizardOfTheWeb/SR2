#ifndef POSTURAL_HPP
#define POSTURAL_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Matrix/nnmatrix.h"
#include "usr/local/sega/nn/src/Matrix/nnmakematrix.h"
#include "usr/local/sega/nn/src/Matrix/nnquaternion.h"
#include "Develop/Projects/SR2/pgm/src/Object/SlerpQuat.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/LerpParam.hpp"

#include "Develop/Projects/SR2/pgm/lib/OO/nn/NNUtil.hpp"

// total size: 0xB0
class clsPosturalCtrl {
public:
    typedef f32 (*MtxPtr)[4];

    clsPosturalCtrl()
    {
        clsPosturalCtrl* const& pcThis = this;
        nnMakeUnitMatrix(&pcThis->m_sMtx);
        nnMakeUnitQuaternion(&m_sQuat);
        nnCopyVectorFast(&m_sDirVecFast, &nspNnUtil::tosZVecFast);
    }
    clsPosturalCtrl(const clsPosturalCtrl& rcOther);
    ~clsPosturalCtrl() {}

    MtxPtr getMtxPtr() const;
    const NNS_VECTORFAST* getDirVecFastPtr() const { return &m_sDirVecFast; }
    const NNS_QUATERNION* getQuatPtr() const { return &m_sQuat; }
    const NNS_QUATERNION* getSurfaceQuatPtr() const;
    f32 getRotateRad() const;
    void setRotate(f32 f32Rotate);
    void setRotate(f32 f32Rotate, f32 f32Frame);
    void setRotate(f32 f32X, f32 f32Y, f32 f32Z);
    void setRotateRad(f32 f32Rad);
    void setSurface(const NNS_QUATERNION* psQuat);
    void setSurface(const NNS_QUATERNION* psQuat, f32 f32Frame);
    void update();

    NNS_MATRIX m_sMtx;            // offset 0x0, size 0x40
    NNS_VECTORFAST m_sDirVecFast; // offset 0x40, size 0x10
    NNS_QUATERNION m_sQuat;       // offset 0x50, size 0x10
    clsSlerpQuat m_cSurface;      // offset 0x60, size 0x3C
    clsLerpParam m_cRotate;       // offset 0x9C, size 0x10
};

#endif // POSTURAL_HPP
