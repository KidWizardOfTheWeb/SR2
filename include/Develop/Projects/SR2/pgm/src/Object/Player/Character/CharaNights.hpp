#ifndef CHARANIGHTS_HPP
#define CHARANIGHTS_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaNodeBase.hpp"

class clsTask;
class clsBackLineEffectTask;
class clsPlaySe_2D;

// total size: 0x120
class clsCharaNights : public clsCharaNodeBase {
public:
    clsCharaNights(clsPlayerTask* pcPlayer, u8 u8ModelType);
    virtual ~clsCharaNights();

    virtual f32 getCollisionRadius() const;
    virtual f32 getDrawOffset() const;
    virtual void behavior();
    virtual void initAttack00();
    virtual void initAttack01();
    virtual void actionAttack00();
    virtual void actionAttack01();

    void loadAdditionalData(stcBinInfo& rParam1);

    static clsBackLineEffectTask::stcParam asNightsLineParam[2];
    static f32 tof32CollisionRadius;

    f32 m_sLMtx[4][4];                       // offset 0x60, size 0x40
    f32 m_sRMtx[4][4];                       // offset 0xA0, size 0x40
    NNS_VECTORFAST m_asParticlePos[2];       // offset 0xE0, size 0x20
    clsTask* m_apcParticleTask[2];           // offset 0x100, size 0x8
    clsBackLineEffectTask* m_apcLineTask[2]; // offset 0x108, size 0x8
    clsPlaySe_2D* m_pcPlaySe2D;              // offset 0x110, size 0x4
};

#endif // CHARANIGHTS_HPP
