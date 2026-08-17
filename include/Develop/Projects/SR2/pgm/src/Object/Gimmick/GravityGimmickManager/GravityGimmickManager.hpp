#ifndef GRAVITYGIMMICKMANAGER_HPP
#define GRAVITYGIMMICKMANAGER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"

class clsRigidBodyGimmickObj;

// total size: 0xC
class clsGravityGimmickCalculation {
public:
    enum enmType {
        TYPE_FRONT = 0,
        TYPE_BACK = 1,
    };

    clsRigidBodyGimmickObj* m_pcObject; // offset 0x0, size 0x4
    enmType m_eType;                    // offset 0x4, size 0x4
    f32 m_f32Distance;                  // offset 0x8, size 0x4
};

// total size: 0x24
class clsGravityGimmickManager : public clsSingleton<clsGravityGimmickManager> {
public:
    enum enmBreakType {
        BREAK_TYPE_0 = 4,
        BREAK_TYPE_1,
        BREAK_TYPE_2,
    };

    clsGravityGimmickManager() {}
    virtual ~clsGravityGimmickManager() {}

    virtual void requestCrash(clsRigidBodyGimmickObj* pParam1, enmBreakType sParam2);
    virtual void regist(clsRigidBodyGimmickObj* pParam1);
    virtual void execute();

    s32 m_s32MaxNum;         // offset 0x4, size 0x4
    s32 m_s32MinNum;         // offset 0x8, size 0x4
    vector m_vecCalcArray;   // offset 0xC, size 0xC
    vector m_vecDeleteArray; // offset 0x18, size 0xC
};

#endif // GRAVITYGIMMICKMANAGER_HPP
