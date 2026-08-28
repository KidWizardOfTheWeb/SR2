#ifndef PERFORMANCE_HPP
#define PERFORMANCE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/GravityAction/GravityControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/Game.hpp"

class clsGearCtrl;
class clsCharacter;

enum enmBaseType {
    BASE_PRFM_SPEED = 0,
    BASE_PRFM_FLY = 1,
    BASE_PRFM_POWER = 2,
    BASE_PRFM_SVBALL = 3,
    BASE_PRFM_SVBATTLE = 4,
    MAX_BASE_PRFM_NUM = 5,
};

enum enmWalkType {
    WALK_PRFM_NORMAL = 0,
    WALK_PRFM_SVLRACE_FAST = 1,
    WALK_PRFM_SVLRACE_USUALLY = 2,
    WALK_PRFM_SVLRACE_SLOW = 3,
    MAX_WALK_PRFM_NUM = 4,
};

// Reconstructed ability flags from nspGear::oasGearData; names are not present in DWARF.
enum enmAbility {
    ABILITY_GP_INFINITY = 8,
    ABILITY_AUTO_WALL_RUN = 16,
    ABILITY_GHOST = 32,
    ABILITY_MAG_BARRIER = 64,
};

// Structs

// total size: 0x2C
struct stcBasePrfm {
    f32 f32Speed[3];     // offset 0x0, size 0xC
    f32 f32Accele[3];    // offset 0xC, size 0xC
    f32 f32RotateSpeed;  // offset 0x18, size 0x4
    f32 f32RotateAccele; // offset 0x1C, size 0x4
    f32 f32Grip;         // offset 0x20, size 0x4
    f32 f32Durability;   // offset 0x24, size 0x4
    u32 u32Ability;      // offset 0x28, size 0x4
};

struct stcAddPrfm {
    f32 f32MaxSpeedRate;        // offset 0x0, size 0x4
    f32 f32AcceleRate;          // offset 0x4, size 0x4
    f32 f32RotateSpeedRate;     // offset 0x8, size 0x4
    f32 f32RotateAcceleRate;    // offset 0xC, size 0x4
    f32 f32GripRate;            // offset 0x10, size 0x4
    f32 f32DurabilityRate;      // offset 0x14, size 0x4
    f32 f32Speed[3];            // offset 0x18, size 0xC
    f32 f32Accele[3];           // offset 0x24, size 0xC
    f32 f32RotateSpeed;         // offset 0x30, size 0x4
    f32 f32RotateAccele;        // offset 0x34, size 0x4
    f32 f32Grip;                // offset 0x38, size 0x4
    f32 f32JumpSpeed;           // offset 0x3C, size 0x4
    f32 f32JumpAccele;          // offset 0x40, size 0x4
    f32 f32Durability;          // offset 0x44, size 0x4
    u32 u32Ability;             // offset 0x48, size 0x4
    f32 f32MaxAgp;              // offset 0x4C, size 0x4
    f32 f32GCtrlDischargeSpeed; // offset 0x50, size 0x4
    f32 f32GDiveSpeedRate;      // offset 0x54, size 0x4
    f32 f32GPTakeRate;          // offset 0x58, size 0x4
    f32 f32GCtrlGpUseRate;      // offset 0x5C, size 0x4
    f32 f32GDiveGpUseRate;      // offset 0x60, size 0x4
    s32 s32AttackEnableFrame;   // offset 0x64, size 0x4
    s16 s16RingCapacity;        // offset 0x68, size 0x2
    s8 s8TrickRank;             // offset 0x6A, size 0x1
    s8 s8ItemRank;              // offset 0x6B, size 0x1
};

class clsPrfm {
public:
    struct stcData {
        f32 f32Speed[3];            // offset 0x0, size 0xC
        f32 f32Accele[3];           // offset 0xC, size 0xC
        f32 f32RotateSpeed;         // offset 0x18, size 0x4
        f32 f32RotateAccele;        // offset 0x1C, size 0x4
        f32 f32Grip;                // offset 0x20, size 0x4
        f32 f32JumpSpeed;           // offset 0x24, size 0x4
        f32 f32JumpAccele;          // offset 0x28, size 0x4
        f32 f32Durability;          // offset 0x2C, size 0x4
        u32 u32Ability;             // offset 0x30, size 0x4
        f32 f32MaxAgp;              // offset 0x34, size 0x4
        f32 f32GCtrlDischargeSpeed; // offset 0x38, size 0x4
        f32 f32GDiveSpeedRate;      // offset 0x3C, size 0x4
        f32 f32GPTakeRate;          // offset 0x40, size 0x4
        f32 f32GCtrlGpUseRate;      // offset 0x44, size 0x4
        f32 f32GDiveGpUseRate;      // offset 0x48, size 0x4
        s32 s32AttackEnableFrame;   // offset 0x4C, size 0x4
        s16 s16RingCapacity;        // offset 0x50, size 0x2
        s8 s8TrickRank;             // offset 0x52, size 0x1
        s8 s8ItemRank;              // offset 0x53, size 0x1
    };

    clsPrfm() {}

    const stcData* getGearDataPtr() const { return &m_sData; }
    u32 getGearAbility() const { return m_sData.u32Ability; }
    u32 getAbility() const { return m_sData.u32Ability | m_sBase.u32Ability; }

    stcData* getDataPtr() const;
    void setMaxAgp(f32 f32MaxAGP);
    void setRingCapacity(s16 s16Ring);
    void setup(clsCharacter* pcChara, clsGearCtrl* pcGearCtrl);
    void updateFrame();
    void updateData();
    void Limit(stcData& rsData);
    void reset();

    static f32 t_of32FLightMaxSpeed;         // address: 0x00664D50
    static f32 t_of32FlightMinSpeed;         // address: 0x00664D58
    static f32 t_of32FlightResistanceRate;   // address: 0x00664D60
    static f32 t_of32FlightFloatingBaseRate; // address: 0x00664D68
    static f32 t_of32FlightFloatingDiffRate; // address: 0x00664D70
    static f32 t_of32InfiniGpCheckNotUse;    // address: 0x00664D78

    stcData m_sBase;           // offset 0x0, size 0x54
    stcData m_sWalk;           // offset 0x54, size 0x54
    stcData m_sData;           // offset 0xA8, size 0x54
    clsGearCtrl* m_pcGearCtrl; // offset 0xFC, size 0x4
    f32 m_f32WeightRate;       // offset 0x100, size 0x4
    f32 m_f32InfiniGpFrame;    // offset 0x104, size 0x4
    f32 m_f32AdjustSpeedRate;  // offset 0x108, size 0x4
    f32 m_f32AdjustAcceleRate; // offset 0x10C, size 0x4
}; // total size: 0x110

#endif // PERFORMANCE_HPP
