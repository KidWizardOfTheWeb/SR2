#ifndef LOCKONFIXED3D_HPP
#define LOCKONFIXED3D_HPP

#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/LockOn/BaseLockOn.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/Missile/SvlBtlMissileTask.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsLockOnFixed3D_Task : public clsBaseLockOn_Task {
public:
    clsLockOnFixed3D_Task(u32 u32ViewNo, const NNS_VECTORFAST* psPosVecFast, u32 u32CharaNo);
    virtual ~clsLockOnFixed3D_Task();
    virtual void reset();
    virtual void execute();
    virtual void draw();
    virtual void registModel(stcBinInfo& rsBinInfoI);
    virtual enmType getType() const;

    void setCharaNo(u32 u32CharaNo);

    // Members
    NNS_VECTORFAST* m_opsPosVecFast; // offset 0x54, size 0x4
    u32 m_u32ViewNo;                 // offset 0x58, size 0x4
    f32 m_f32MotFrame;               // offset 0x5C, size 0x4
    u32 m_u32CharaNo;                // offset 0x60, size 0x4

    static clsModelType_OB_TX_MO_MA t_cModel;
};

#endif // LOCKONFIXED3D_HPP
