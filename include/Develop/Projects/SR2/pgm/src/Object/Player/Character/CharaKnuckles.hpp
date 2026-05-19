#ifndef CHARAKNUCKLES_HPP
#define CHARAKNUCKLES_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaNodeBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

// total size: 0x70
class clsCharaKnuckles : public clsCharaNodeBase {
public:
    clsCharaKnuckles(clsPlayerTask* pcTask, u8 u8Param1);
    virtual ~clsCharaKnuckles();

    virtual f32 getCollisionRadius() const { return 0.6f; }
    virtual f32 getDrawOffset() const { return m_f32OffsetPosition - tof32CollisionRadius; }

    virtual void behavior();
    virtual void initAttack00();
    virtual void initAttack01();
    virtual void actionAttack00();
    virtual void actionAttack01();
    virtual void loadAdditionalData(stcBinInfo& rsBinInfo);

    static stcParam sKnucklesLineParam;
    static f32 tof32CollisionRadius;

    clsBackLineEffectTask* m_pcLineTask; // offset 0x60, size 0x4
    f32 m_f32behaviorTailCnt;            // offset 0x64, size 0x4
};

#endif // CHARAKNUCKLES_HPP
