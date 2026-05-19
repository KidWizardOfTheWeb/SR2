#ifndef LOCKONTARGET2D_HPP
#define LOCKONTARGET2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Effect/LockOn/BaseLockOn.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/Missile/SvlBtlMissileTask.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0x60
class clsLockOnTarget2D_Task : public clsBaseLockOn_Task {
public:
    clsLockOnTarget2D_Task() {}
    virtual ~clsLockOnTarget2D_Task();

    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual enmType getType() const { return TYPE__TARGET; }

    NNS_VECTORFAST* m_opsPosVecFast; // offset 0x54, size 0x4
    u32 m_u32ViewNo;                 // offset 0x58, size 0x4
    u32 m_u32CharaNo;                // offset 0x5C, size 0x4
};

#endif // LOCKONTARGET2D_HPP
