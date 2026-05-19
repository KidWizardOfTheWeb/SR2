#ifndef MINIWAVEGMKAUTORUNOBJ_HPP
#define MINIWAVEGMKAUTORUNOBJ_HPP

#include "Develop/Projects/SR2/pgm/src/Effect/MiniWave/MiniWave.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsGimmickAutoRunObj;

// total size: 0xD20
class clsMiniWaveGmkAutoRunObjEffect_Task : public clsMiniWaveEffect_Task {
public:
    virtual ~clsMiniWaveGmkAutoRunObjEffect_Task();

    virtual void execute();

    void setOffsetVecFast(NNS_VECTORFAST* psOffsetVecFast);

    NNS_VECTORFAST m_sWaveOffsetVec;     // offset 0xD00, size 0x10
    clsGimmickAutoRunObj* m_pAutoRunObj; // offset 0xD10, size 0x4
    u8 m_bDelete;                        // offset 0xD14, size 0x1
};

#endif // MINIWAVEGMKAUTORUNOBJ_HPP
