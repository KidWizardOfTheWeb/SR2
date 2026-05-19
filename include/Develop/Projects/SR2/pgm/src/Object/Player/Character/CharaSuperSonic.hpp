#ifndef CHARASUPERSONIC_HPP
#define CHARASUPERSONIC_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaNodeBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

enum enmSChara {
    TYPE_SONIC = 0,
    TYPE_SUPER_SONIC = 1,
};

enum enmSAction {
    ACTION_RUN = 1,
    ACTION_BOOST = 2,
    ACTION_BOOST_ATTACK = 3,
};

// total size: 0xB0
class clsCharaSuperSonic : public clsCharaNodeBase {
public:
    // total size: 0x10
    struct stcRingRateTime {
        s32 s32Sec;         // offset 0x0, size 0x4
        s32 s32PassageSec;  // offset 0x4, size 0x4
        f32 f32MSec;        // offset 0x8, size 0x4
        f32 f32PassageMSec; // offset 0xC, size 0x4
    };

    clsCharaSuperSonic(clsPlayerTask* pParam1, u8 u8Param2);
    virtual ~clsCharaSuperSonic() {}
    virtual f32 getCollisionRadius() const { return tof32CollisionRadius; }
    virtual f32 getDrawOffset() const { return m_f32OffsetPosition; }
    virtual void draw(u32 u32Param1);
    virtual void drawAttackEffect();
    virtual void behavior();
    virtual void initAttack00();
    virtual void initAttack01();
    virtual void actionAttack00();
    virtual void actionAttack01();
    virtual void reset();

    void loadAdditionalData(stcBinInfo& rParam1); // TODO: verify — mangled as clsPack::stcBinInfo
                                                  // but likely global stcBinInfo
    void updateGravity();
    void updateAction();
    s32 updateLimitTime(f32 f32Param1, stcRingRateTime* pParam2);

    static f32 tof32CollisionRadius;          // = 0.6f
    static s32 SUPER_SONIC_RATE_START_BONUS;  // = 0
    static f32 SUPER_SONIC_RATE_SPEED;        // = 5.0f / 6.0f
    static f32 SUPER_SONIC_RATE_ATTACK_FRAME; // = 600.0f

    enmSChara m_eSonicType;                   // offset 0x60, size 0x4
    enmSAction m_eSonicAction;                // offset 0x64, size 0x4
    f32 m_f32MatCnt;                          // offset 0x68, size 0x4
    stcRingRateTime m_sTimeNormal;            // offset 0x6C, size 0x10
    stcRingRateTime m_sTimeBoost;             // offset 0x7C, size 0x10
    stcRingRateTime m_sTimeGravity;           // offset 0x8C, size 0x10
    f32 m_f32behaviorCnt;                     // offset 0x9C, size 0x4
    clsDrawAttackEffect_Task* m_pcDrawEffTsk; // offset 0xA0, size 0x4
    u32 u32GsTexS;                            // offset 0xA4, size 0x4
    u32 u32GsTexD;                            // offset 0xA8, size 0x4
};

#endif // CHARASUPERSONIC_HPP
