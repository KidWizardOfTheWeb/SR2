#ifndef CHARASTORM_HPP
#define CHARASTORM_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaNodeBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

// total size: 0x70
class clsCharaStorm : public clsCharaNodeBase {
public:
    clsCharaStorm(clsPlayerTask* pcPlayer, u8 u8Param2);
    virtual ~clsCharaStorm();

    virtual inline f32 getCollisionRadius() const;
    virtual f32 getDrawOffset() const;

    void behavior();
    void initAttack00();
    void initAttack01();
    void actionAttack00();
    void actionAttack01();
    void loadAdditionalData(stcBinInfo& rsBinInfo);

    static stcParam sStormLineParam;
    static f32 tof32CollisionRadius;

    clsBackLineEffectTask* m_pcLineTask; // offset 0x60, size 0x4
};

#endif // CHARASTORM_HPP
