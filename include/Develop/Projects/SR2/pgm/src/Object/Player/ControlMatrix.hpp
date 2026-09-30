#ifndef CONTROLMATRIX_HPP
#define CONTROLMATRIX_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/nn/NNUtil.hpp"
#include "usr/local/sega/nn/src/Matrix/nnmakematrix.h"
#include "usr/local/sce/ee/gcc/ee/lib/libc/memset.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0x110
class clsControlMatrix {
public:
    enum enmFlag {
        FLAG_CLEAR = 0,
        FLAG_VIBRATION = 1,
        FLAG_AUTORETURN = 2,
        FLAG_SCALING = 4,
        FLAG_INIT = 7,
    };

    clsControlMatrix() : m_f32TrsDecayRate(0.0f), m_f32RotDecayRate(0.0f), m_eFlag(FLAG_INIT)
    {
        nnMakeUnitMatrix(&m_sMtx);
        nnCopyVectorFast(&m_sVibTrsVecFast, &nspNnUtil::tosZeroVecFast);
        nnCopyVectorFast(&m_sVibTrsSyncVecFast, &nspNnUtil::tosZeroVecFast);
        nnCopyVectorFast(&m_sVibTrsSyncAddVecFast, &nspNnUtil::tosZeroVecFast);
        nnCopyVectorFast(&m_sVibRotVecFast, &nspNnUtil::tosZeroVecFast);
        nnCopyVectorFast(&m_sVibRotSyncVecFast, &nspNnUtil::tosZeroVecFast);
        nnCopyVectorFast(&m_sVibRotSyncAddVecFast, &nspNnUtil::tosZeroVecFast);
        nnCopyVectorFast(&m_sVibRotAxisVecFast, &nspNnUtil::tosZeroVecFast);
        m_f32TrsDecayRate = 0.0f;
        m_f32RotDecayRate = 0.0f;
        memset(&m_sAutoRotA32, 0, sizeof(m_sAutoRotA32));
        memset(&m_sAutoRotRetAddA32, 0, sizeof(m_sAutoRotRetAddA32));
        nnCopyVectorFast(&m_sAutoRotAxisVecFast, &nspNnUtil::tosZeroVecFast);
    }

    void reset();
    void update();
    NNS_MATRIX* getMtxRef() { return &m_sMtx; }
    NNS_ROTATE_A32* getAutoRotRetAddA32Ref() { return &m_sAutoRotRetAddA32; }
    NNS_ROTATE_A32* getAutoRotA32Ref() { return &m_sAutoRotA32; }
    void setRotDecayRate(f32 f32Param1) { m_f32RotDecayRate = f32Param1; }
    void setTrsDecayRate(f32 f32Param1) { m_f32TrsDecayRate = f32Param1; }
    NNS_VECTORFAST* getVibRotAxisVecFastRef() { return &m_sVibRotAxisVecFast; }
    NNS_VECTORFAST* getAutoRotAxisVecFastRef() { return &m_sAutoRotAxisVecFast; }
    NNS_VECTORFAST* getScaleVecFastRef() { return &m_sScaleVecFast; }

    NNS_MATRIX m_sMtx;                      // offset 0x0, size 0x40
    NNS_ROTATE_A32 m_sAutoRotA32;           // offset 0x40, size 0xC
    NNS_ROTATE_A32 m_sAutoRotRetAddA32;     // offset 0x4C, size 0xC
    NNS_VECTORFAST m_sAutoRotAxisVecFast;   // offset 0x60, size 0x10
    NNS_VECTORFAST m_sVibTrsVecFast;        // offset 0x70, size 0x10
    NNS_VECTORFAST m_sVibTrsSyncVecFast;    // offset 0x80, size 0x10
    NNS_VECTORFAST m_sVibTrsSyncAddVecFast; // offset 0x90, size 0x10
    NNS_VECTORFAST m_sVibRotVecFast;        // offset 0xA0, size 0x10
    NNS_VECTORFAST m_sVibRotSyncVecFast;    // offset 0xB0, size 0x10
    NNS_VECTORFAST m_sVibRotSyncAddVecFast; // offset 0xC0, size 0x10
    NNS_VECTORFAST m_sVibRotAxisVecFast;    // offset 0xD0, size 0x10
    f32 m_f32TrsDecayRate;                  // offset 0xE0, size 0x4
    f32 m_f32RotDecayRate;                  // offset 0xE4, size 0x4
    NNS_VECTORFAST m_sScaleVecFast;         // offset 0xF0, size 0x10
    enmFlag m_eFlag;                        // offset 0x100, size 0x4
};

#endif // CONTROLMATRIX_HPP
