#ifndef CONTROLMATRIX_HPP
#define CONTROLMATRIX_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0x110
class clsControlMatrix {
public:
    // Note: enmFlag collides with other headers; nested here for disambiguation.
    enum enmFlag {
        FLAG_NULL = 0,
        FLAG_DRAW_COL = 1,
        FLAG_DRAW_MOV_LINE = 2,
        FLAG_DRAW_PST_LINE = 4,
        FLAG_DRAW_VLC_LINE = 8,
        FLAG_DRAW_GRAVITY = 16,
        FLAG_DRAW_GRID = 32,
        FLAG_INFINI_AGP = 64,
        FLAG_FREE_GEARCHANGE = 128,
        FLAG_CHANGE_COM = 256,
        FLAG_STOP = 512,
        FLAG_UPDATE_TIMER = 268435456,
        FLAG_DEFAULT = 0,
    };

    clsControlMatrix() {}

    void reset();
    void update();
    f32* getMtxRef() { return &m_sMtx[0][0]; }
    NNS_ROTATE_A32* getAutoRotRetAddA32Ref() { return &m_sAutoRotRetAddA32; }
    NNS_ROTATE_A32* getAutoRotA32Ref() { return &m_sAutoRotA32; }
    void setRotDecayRate(f32 f32Param1) { m_f32RotDecayRate = f32Param1; }
    void setTrsDecayRate(f32 f32Param1) { m_f32TrsDecayRate = f32Param1; }
    NNS_VECTORFAST* getVibRotAxisVecFastRef() { return &m_sVibRotAxisVecFast; }
    NNS_VECTORFAST* getAutoRotAxisVecFastRef() { return &m_sAutoRotAxisVecFast; }
    NNS_VECTORFAST* getScaleVecFastRef() { return &m_sScaleVecFast; }

    f32 m_sMtx[4][4];                       // offset 0x0, size 0x40
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
