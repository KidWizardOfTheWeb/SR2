#ifndef SLERPQUAT_HPP
#define SLERPQUAT_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0x3C
class clsSlerpQuat {
public:
    NNS_QUATERNION m_sBaseQuat;   // offset 0x0, size 0x10
    NNS_QUATERNION m_sSlerpQuat;  // offset 0x10, size 0x10
    NNS_QUATERNION m_sResultQuat; // offset 0x20, size 0x10
    f32 m_f32Rate;                // offset 0x30, size 0x4
    f32 m_f32Add;                 // offset 0x34, size 0x4
    u8 m_bIsSlerp;                // offset 0x38, size 0x1

    void
    startSlerp(const NNS_QUATERNION* psBaseQuat, const NNS_QUATERNION* psSlerpQuat, f32 f32Frame);
    void update();
    u8 isSlerp() { return m_bIsSlerp; }
    const NNS_QUATERNION* getResultQuatPtr() const { return &m_sResultQuat; }
};

#endif // SLERPQUAT_HPP
