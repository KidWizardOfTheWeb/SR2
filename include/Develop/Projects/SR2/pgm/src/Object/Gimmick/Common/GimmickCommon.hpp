#ifndef GIMMICKCOMMON_HPP
#define GIMMICKCOMMON_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/GlobalData.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/BaseRace.hpp"

// total size: 0x1
class clsGimmickCommon {
public:
    clsGimmickCommon() : m_bDisableFog(m_toabDisableFog[nspGlobal::sTask.pcBaseRace->getStageNo()])
    {
    }
    static f32 t_of32ClipDistRate;
    static u8 m_toabDisableFog[17];

private:
    u8 m_bDisableFog;
};

#endif // GIMMICKCOMMON_HPP
