#ifndef FLYACTION_HPP
#define FLYACTION_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0x1C
class clsFlyAction {
public:
    clsFlyAction();
    void setFlyPitchAngle(s32 s32FlyPitchAngle) { m_A32FlyPitchAngle = s32FlyPitchAngle; }

    static f32 t_of32DefaultSpeed;

    NNS_QUATERNION m_sFlyQuat; // offset 0x0, size 0x10
    s32 m_A32FlyPitchAngle;    // offset 0x10, size 0x4
    s32 m_A32FlyRollAngle;     // offset 0x14, size 0x4
    s16 m_s16OldRingNo;        // offset 0x18, size 0x2
    s16 m_s16InitType;         // offset 0x1A, size 0x2
};

#endif // FLYACTION_HPP
