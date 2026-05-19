#ifndef CHARACREAM_HPP
#define CHARACREAM_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaNodeBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0x70
class clsCharaCream : public clsCharaNodeBase {
public:
    clsCharaCream(clsPlayerTask* pcPlayer, u8 u8ModelType);
    virtual ~clsCharaCream() {}

    f32 m_f32behaviorTailCnt; // offset 0x60, size 0x4

    static f32 tof32CollisionRadius;

    virtual void behavior();
    virtual void initAttack00();
    virtual void initAttack01();
    virtual void actionAttack00();
    virtual void actionAttack01();
    virtual void draw(u32 u32AddDrawFlagI);
    virtual void loadAdditionalData(stcBinInfo& rsBinInfo);
    inline f32 getCollisionRadius() const { return tof32CollisionRadius; }
    inline f32 getDrawOffset() const { return 0.0f; }
};

class clsCreamAttackEffectTask : public clsTask {
public:
    clsCreamAttackEffectTask(u32 u32Param1, u32 u32Param2);
    virtual ~clsCreamAttackEffectTask();
    virtual void execute();
    virtual void draw();

    u32 m_u32TgtViewNo;   // offset 0x54, size 0x4
    u32 m_u32TgtPlayerNo; // offset 0x58, size 0x4
    f32 m_f32AliveFrame;  // offset 0x5C, size 0x4
    f32 m_f32Scale;       // offset 0x60, size 0x4
    f32 m_f32UpDownY;     // offset 0x64, size 0x4
    f32 m_f32MotionFrame; // offset 0x68, size 0x4
    u8 m_bSePlayFlg;      // offset 0x6C, size 0x1
};

#endif // CHARACREAM_HPP
