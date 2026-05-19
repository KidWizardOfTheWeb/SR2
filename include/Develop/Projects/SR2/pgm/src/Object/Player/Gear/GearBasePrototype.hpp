#ifndef GEARBASEPROTOTYPE_HPP
#define GEARBASEPROTOTYPE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/Gear.hpp"

// TODO: WALK variant of enmMotion (WALK_RUN_A=0..WALK_START_DEMO_ST1=23) also
// appears in DWARF under the name enmMotion — confirm its scope and home header
// during implementation.
namespace nspMotion {
enum enmMotion {
    GEAR_RUN_A = 0,
    GEAR_RUN_B = 1,
    GEAR_RUN_R = 2,
    GEAR_CURVE_R1 = 3,
    GEAR_CURVE_R2 = 4,
    GEAR_CURVE_L1 = 5,
    GEAR_CURVE_L2 = 6,
    GEAR_JUMP = 7,
    GEAR_JUMP_FALL = 8,
    GEAR_TRICK_FALL = 9,
    GEAR_JUMP_LAND1 = 10,
    GEAR_JUMP_LAND2 = 11,
    GEAR_TRICK_LAND1 = 12,
    GEAR_TRICK_LAND2 = 13,
    GEAR_GETON = 14,
    GEAR_GETOFF = 15,
    GEAR_GDIVE_START = 16,
    GEAR_GDIVE_MOVE = 17,
    GEAR_GDIVE_END = 18,
    GEAR_GCTRL_START = 19,
    GEAR_GCTRL_MOVE = 20,
    GEAR_GCTRL_END = 21,
    GEAR_RESTART = 22,
    GEAR_DASH = 23,
    GEAR_PANIC_BADROAD = 24,
    GEAR_PANIC_CLASH = 25,
    GEAR_CHANGE = 26,
    GEAR_OVERTAKE1 = 27,
    GEAR_FALLASTERN1 = 28,
    GEAR_FALLASTERN2 = 29,
    GEAR_FALLASTERN3 = 30,
    GEAR_GOAL_WIN = 31,
    GEAR_GOAL_LOSE = 32,
    GEAR_RUN_WAIT = 33,
    GEAR_TRUB_REG_R = 34,
    GEAR_TRUB_REG_L = 35,
    GEAR_ATTACK_ON = 36,
    GEAR_ATTACK_OFF = 37,
    GEAR_TRICK_ALL = 38,
    GEAR_RAIL_RUN1 = 39,
    GEAR_RAIL_RUN2 = 40,
    GEAR_RAIL_LAND1 = 41,
    GEAR_RAIL_LAND2 = 42,
    GEAR_FLY = 43,
    GEAR_FLY_R = 44,
    GEAR_FLY_L = 45,
    GEAR_HOLD_OBJ = 46,
    GEAR_POWER1 = 47,
    GEAR_POWER2 = 48,
    GEAR_ATTACK1 = 49,
    GEAR_ATTACK2 = 50,
    GEAR_ATTACK_DAMAGE_DEF = 51,
    GEAR_ATTACK_DAMAGE_WALL = 52,
    GEAR_DAMAGE1 = 53,
    GEAR_DAMAGE2 = 54,
    GEAR_DAMAGE3 = 55,
    GEAR_GDIVE_RUN = 56,
    GEAR_DAMAGE_REVERBERATION = 57,
    GEAR_TRICK_X = 58,
    GEAR_PANIC_CHARA_HIT = 59,
    GEAR_PANIC_DAMAGE = 60,
    GEAR_BRAKE_R = 61,
    GEAR_BRAKE_L = 62,
    GEAR_GETON_LAND = 63,
    GEAR_MOTION_MAX = 64,
};
} // namespace nspMotion

enum enmChangeRes {
    CTRL_RES_CONTINUE = 0,
    CTRL_RES_END = 1,
};

class clsGear;

// total size: 0x60
class clsGearBasePrototype : public clsGear {
public:
    clsGearBasePrototype(clsGearCtrl* pcGearCtrl,
                         const stcGearData& rsGearData,
                         const stcAddPrfm& rsGearPrfm)
        : clsGear(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }

    virtual ~clsGearBasePrototype();

    virtual void clearChangeActionParam();

    virtual s32 getGearFlySeNo() const;

    virtual u8 isUseModel() const;

    virtual enmChangeRes initRideChangeAction(clsGear** pParam1, clsGear* pParam2);

    virtual enmChangeRes execRideChangeAction(clsGear** pParam1, clsGear* pParam2);

    virtual enmChangeRes initWalkChangeAction(clsGear** pParam1);

    virtual enmChangeRes execWalkChangeAction(clsGear** pParam1);

    virtual enmChangeRes initGearChange(clsGear** pcOldGear, clsGear* pParam2);

    virtual enmChangeRes execGearChange(clsGear** pcOldGear, clsGear* pParam2);

    virtual void controlMotion();

    virtual void controlMotionCurve00();

    virtual void controlMotionCurve01();

    virtual void controlMotionFlyCurve();

    virtual f32 calcCurveRadResult(f32 f32Rate);

    virtual void Curve(f32 f32Ratio);

    virtual void setCurveEffect();

    virtual void Accele();

    virtual void Brake();

    virtual enmChangeRes changeRide(clsGear** ppcPartsGears,
                                    clsGear* pcBaseGear,
                                    f32 f32LinkFrame,
                                    nspMotion::enmMotion eMotion);

    virtual enmChangeRes
    changeWalk(clsGear** apcEquipsGears, f32 f32LinkFrame, nspMotion::enmMotion eMotion);

    virtual enmChangeRes changeHideWalk(clsGear** apcEquipsGears);

    virtual void rebuildGearRunSe();

    virtual u8 rebuildGearFlySe();

    s32 m_s32OldRunSeNo;     // offset 0x50, size 0x4
    f32 m_f32RideChageFrame; // offset 0x54, size 0x4
    u8 m_u8CurveSeFlag;      // offset 0x58, size 0x1
};

#endif // GEARBASEPROTOTYPE_HPP
