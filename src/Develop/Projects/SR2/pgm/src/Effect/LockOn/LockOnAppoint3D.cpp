#include "Develop/Projects/SR2/pgm/src/Effect/LockOn/LockOnAppoint3D.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/LockOn/LockOnCharacterColor.hpp"

clsModelType_OB_TX_MO_MA clsLockOnAppoint3D_Task::t_cModel;

void clsLockOnAppoint3D_Task::registModel(stcBinInfo& rsBinInfoI)
{
}

void clsLockOnAppoint3D_Task::execute()
{
}

void clsLockOnAppoint3D_Task::draw()
{
}

void clsLockOnAppoint3D_Task::reset()
{
}

clsLockOnAppoint3D_Task::clsLockOnAppoint3D_Task(u32 u32ViewNo,
                                                 const NNS_VECTORFAST* psPosVecFast,
                                                 u32 u32CharaNo)
{
}

clsLockOnAppoint3D_Task::~clsLockOnAppoint3D_Task()
{
}

enmType clsLockOnAppoint3D_Task::getType() const
{
    return TYPE__APPOINT;
}

void clsLockOnAppoint3D_Task::setCharaNo(u32 u32CharaNo)
{
    m_u32CharaNo = u32CharaNo;
}
