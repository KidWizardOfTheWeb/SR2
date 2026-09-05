#ifndef CHARAAMY_HPP
#define CHARAAMY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaNodeBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

class clsPlayerTask;

class clsCharaAmy : public clsCharaNodeBase {
public:
    clsCharaAmy(clsPlayerTask* pcPlayer, u8 u8Arg);
    virtual ~clsCharaAmy();

    virtual void draw(u32 u32Arg);
    virtual void behavior();
    virtual void initAttack00();
    virtual void initAttack01();
    virtual void actionAttack00();
    virtual void actionAttack01();

    void loadAdditionalData(stcBinInfo& rParam);

    f32 getCollisionRadius() const { return 0.0f; }
    f32 getDrawOffset() const { return 0.0f; }

    static clsBackLineEffectTask::stcParam sAmyLineParam;
    static f32 tof32CollisionRadius;

    // Members
    clsBackLineEffectTask* m_pcLineTask; // offset 0x60, size 0x4
};

#endif // CHARAAMY_HPP
