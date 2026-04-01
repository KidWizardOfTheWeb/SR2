#ifndef PERFORMANCE_HPP
#define PERFORMANCE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/GravityAction/GravityControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/Game.hpp"

class clsGearCtrl;   // forward decl
class clsCharacter;  // forward decl
class clsPlayerTask; // forward decl

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

// Structs

// total size: 0x2C
struct stcBasePrfm {
    float f32Speed[3];      // 0x00
    float f32Accele[3];     // 0x0C
    float f32RotateSpeed;   // 0x18
    float f32RotateAccele;  // 0x1C
    float f32Grip;          // 0x20
    float f32Durability;    // 0x24
    unsigned int u32Ability;// 0x28
};

class stcAddPrfm {
    // total size: 0x6C
public:
    float f32MaxSpeedRate; // offset 0x0, size 0x4
    float f32AcceleRate; // offset 0x4, size 0x4
    float f32RotateSpeedRate; // offset 0x8, size 0x4
    float f32RotateAcceleRate; // offset 0xC, size 0x4
    float f32GripRate; // offset 0x10, size 0x4
    float f32DurabilityRate; // offset 0x14, size 0x4
    float f32Speed[3]; // offset 0x18, size 0xC
    float f32Accele[3]; // offset 0x24, size 0xC
    float f32RotateSpeed; // offset 0x30, size 0x4
    float f32RotateAccele; // offset 0x34, size 0x4
    float f32Grip; // offset 0x38, size 0x4
    float f32JumpSpeed; // offset 0x3C, size 0x4
    float f32JumpAccele; // offset 0x40, size 0x4
    float f32Durability; // offset 0x44, size 0x4
    unsigned int u32Ability; // offset 0x48, size 0x4
    float f32MaxAgp; // offset 0x4C, size 0x4
    float f32GCtrlDischargeSpeed; // offset 0x50, size 0x4
    float f32GDiveSpeedRate; // offset 0x54, size 0x4
    float f32GPTakeRate; // offset 0x58, size 0x4
    float f32GCtrlGpUseRate; // offset 0x5C, size 0x4
    float f32GDiveGpUseRate; // offset 0x60, size 0x4
    signed int s32AttackEnableFrame; // offset 0x64, size 0x4
    signed short s16RingCapacity; // offset 0x68, size 0x2
    signed char s8TrickRank; // offset 0x6A, size 0x1
    signed char s8ItemRank; // offset 0x6B, size 0x1
};

class clsPrfm {
public:
    struct stcData {
        float f32Speed[3];        // 0x00
        float f32Accele[3];       // 0x0C
        float f32RotateSpeed;     // 0x18
        float f32RotateAccele;    // 0x1C
        float f32Grip;            // 0x20
        float f32JumpSpeed;       // 0x24
        float f32JumpAccele;      // 0x28
        float f32Durability;      // 0x2C
        uint32_t u32Ability;      // 0x30
        float f32MaxAgp;          // 0x34
        float f32GCtrlDischargeSpeed; // 0x38
        float f32GDiveSpeedRate;  // 0x3C
        float f32GPTakeRate;      // 0x40
        float f32GCtrlGpUseRate;  // 0x44
        float f32GDiveGpUseRate;  // 0x48
        int32_t s32AttackEnableFrame; // 0x4C
        int16_t s16RingCapacity;  // 0x50
        int8_t s8TrickRank;       // 0x52
        int8_t s8ItemRank;        // 0x53
    }; // total size: 0x54

    stcData m_sBase;                // 0x00
    stcData m_sWalk;                // 0x54
    stcData m_sData;                // 0xA8
    clsGearCtrl* m_pcGearCtrl;      // 0xFC
    float m_f32WeightRate;          // 0x100
    float m_f32InfiniGpFrame;       // 0x104
    float m_f32AdjustSpeedRate;     // 0x108
    float m_f32AdjustAcceleRate;    // 0x10C

    const stcData* getDataPtr() const;
    void setMaxAgp(float f32MaxAGP);
    void setRingCapacity(signed short s16Ring);
    void reset();
    void setup(clsCharacter* pcChara, clsGearCtrl* pcGearCtrl);
    void updateFrame();
    void updateData();
    void Limit(stcData& rsData);
}; // total size: 0x110

namespace nspChara {
    extern stcBasePrfm osWalkPrfm[MAX_WALK_PRFM_NUM];
    extern stcBasePrfm oasBasePrfm[MAX_BASE_PRFM_NUM];
}
using namespace nspChara;

namespace nspAgp {
    extern float toaf32GpUsedRate[5]; // address: 0x664D80
}

#endif // PERFORMANCE_HPP