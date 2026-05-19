#ifndef CHARAJET_HPP
#define CHARAJET_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaNodeBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

class clsPlayerTask;

// total size: 0x70
class clsCharaJet : public clsCharaNodeBase {
public:
    clsCharaJet(clsPlayerTask* pcPlayer, u8 u8ModelType);
    virtual ~clsCharaJet() {}

    f32 m_f32behaviorTailCnt;            // offset 0x60, size 0x4
    clsBackLineEffectTask* m_pcLineTask; // offset 0x64, size 0x4

    static stcParam sJetLineParam;
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

#endif // CHARAJET_HPP
