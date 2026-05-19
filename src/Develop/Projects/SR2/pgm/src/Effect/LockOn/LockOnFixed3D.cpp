#include "Develop/Projects/SR2/pgm/src/Effect/LockOn/LockOnFixed3D.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/LockOn/LockOnCharacterColor.hpp"

clsModelType_OB_TX_MO_MA clsLockOnFixed3D_Task::t_cModel;

void clsLockOnFixed3D_Task::registModel(stcBinInfo& rsBinInfoI)
{
}

void clsLockOnFixed3D_Task::execute()
{
}

void clsLockOnFixed3D_Task::draw()
{
}

void clsLockOnFixed3D_Task::reset()
{
}

clsLockOnFixed3D_Task::clsLockOnFixed3D_Task(u32 u32ViewNo,
                                             const NNS_VECTORFAST* psPosVecFast,
                                             u32 u32CharaNo)
{
}

clsLockOnFixed3D_Task::~clsLockOnFixed3D_Task()
{
}

enmType clsLockOnFixed3D_Task::getType() const
{
    return TYPE__FIXED;
}

void clsLockOnFixed3D_Task::setCharaNo(u32 u32CharaNo)
{
    m_u32CharaNo = u32CharaNo;
}
