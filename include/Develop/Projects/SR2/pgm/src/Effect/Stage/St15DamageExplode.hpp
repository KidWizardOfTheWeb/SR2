#ifndef ST15DAMAGEEXPLODE_HPP
#define ST15DAMAGEEXPLODE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Matrix/nnquaternion.h"

// total size: 0xB0
class clsSt15DamageExplode_Task : public clsTask {
public:
    ~clsSt15DamageExplode_Task();

    clsSt15DamageExplode_Task(f32 f32MaxFrame,
                              const NNS_VECTORFAST* opsPosFast,
                              const NNS_QUATERNION* opsQuat);

    virtual void execute();

    NNS_VECTORFAST* m_opsPosFast; // offset 0x54, size 0x4
    f32 m_sOfsMatrix[4][4];       // offset 0x60, size 0x40
    u32 m_u32Count;               // offset 0xA0, size 0x4
    f32 m_f32Frame;               // offset 0xA4, size 0x4
    f32 m_f32HappenFrame;         // offset 0xA8, size 0x4
    f32 m_f32WaitFrame;           // offset 0xAC, size 0x4
};

#endif // ST15DAMAGEEXPLODE_HPP
