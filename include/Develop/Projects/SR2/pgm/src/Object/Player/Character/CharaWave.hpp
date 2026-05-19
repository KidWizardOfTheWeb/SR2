#ifndef CHARAWAVE_HPP
#define CHARAWAVE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaNodeBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

class clsPlayerTask;
class clsBackLineEffectTask;

// total size: 0x70
class clsCharaWave : public clsCharaNodeBase {
public:
    clsCharaWave(clsPlayerTask* pcPlayer, u8 u8ModelType);
    virtual ~clsCharaWave() {}

    f32 m_f32behaviorTailCnt;            // offset 0x60, size 0x4
    clsBackLineEffectTask* m_pcLineTask; // offset 0x64, size 0x4

    static stcParam sWaveLineParam;
    static f32 tof32CollisionRadius;

    virtual f32 getCollisionRadius() const;
    virtual f32 getDrawOffset() const;
    virtual void draw(u32 u32AddDrawFlagI);
    virtual void behavior();
    virtual void initAttack00();
    virtual void initAttack01();
    virtual void actionAttack00();
    virtual void actionAttack01();
    void loadAdditionalData(stcBinInfo& rsBinInfo);
};

#endif // CHARAWAVE_HPP
