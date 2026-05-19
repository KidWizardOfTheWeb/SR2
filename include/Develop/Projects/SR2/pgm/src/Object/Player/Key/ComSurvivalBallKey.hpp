#ifndef COMSURVIVALBALLKEY_HPP
#define COMSURVIVALBALLKEY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Key/ComKey.hpp"

// total size: 0x190
class clsComSurvivalBallKey : public clsComKey {
public:
    virtual ~clsComSurvivalBallKey() {}
    virtual enmComGearChangeMode getGearChangeMode() const { return GEAR_CHANGE_MODE_RACE; }
    virtual u32 execNull() { return 0; }
    virtual u32 execDamage00() { return 0; }
    virtual u32 execDemo() { return 0; }
    virtual u32 execWalk();
    virtual u32 execIntertia() { return 0; }
    virtual u32 execRun();
    virtual u32 execBrake() { return 0; }
    virtual u32 execFlight() { return 0; }
    virtual u32 execJump() { return 0; }
    virtual u32 execTrick() { return 0; }
    virtual u32 execPath() { return 0; }
    virtual u32 execAttack00();
    virtual u32 execRail() { return 0; }
    virtual u32 execFly() { return 0; }
    virtual u32 execPower() { return 0; }
    virtual u32 execGDive() { return 0; }
    virtual u32 execGCtrlSlide();
    virtual u32 execGCtrlFlight() { return 0; }
    virtual u32 execWheelDrift() { return 0; }
    virtual u32 execFalseStart() { return 0; }
    virtual u32 execDirRegulateRun() { return 0; }
    virtual u32 execTranslationMovePath() { return 0; }
    virtual u32 execReStart() { return 0; }
    virtual u32 execGimmickMove() { return 0; }
    virtual u32 execAttackDamage() { return 0; }
    virtual u8 controlGoalTime(s8 param);

    static u8 m_toaGoalLineObjNo[3];
};

#endif // COMSURVIVALBALLKEY_HPP
