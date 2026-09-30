#ifndef OBJECTEFFECT_HPP
#define OBJECTEFFECT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Effect/BaseEffect.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0xE0
class clsObjectEffect_Task : public clsBaseEffect_Task {
public:
    clsObjectEffect_Task(u32 u32TpI,
                         s32 s32TypeI,
                         clsModelType_OB_TX_MO_MA* pcModelI,
                         u32 eFlagI,
                         const NNS_VECTORFAST* opsFollowPosFast,
                         const NNS_MATRIX* opsFollowMtx,
                         u32 u32ViewNo,
                         f32 f32WaitFrame);
    virtual ~clsObjectEffect_Task();

    virtual void draw();

    void setDrawFlg(bool bDraw) { m_bDraw = bDraw; }

    u8 m_bDraw;                                  // offset 0xD0, size 0x1
    const NNS_MATRIX* m_opsFollowMatrix;         // offset 0xD4
    const NNS_VECTORFAST* m_opsFollowPosVecFast; // offset 0xD8, size 0x4
};

#endif // OBJECTEFFECT_HPP
