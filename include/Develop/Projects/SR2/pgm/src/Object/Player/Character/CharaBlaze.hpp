#ifndef CHARABLAZE_HPP
#define CHARABLAZE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaNodeBase.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsPlaySe_2D;

class clsCharaBlaze : public clsCharaNodeBase {
public:
    virtual ~clsCharaBlaze();

    virtual f32 getCollisionRadius() const;
    virtual f32 getDrawOffset() const;
    virtual void behavior();
    virtual void initAttack00();
    virtual void initAttack01();
    virtual void actionAttack00();
    virtual void actionAttack01();

    void loadAdditionalData(stcBinInfo& rsBinInfo);

    static f32 tof32CollisionRadius;

    // Members
    f32 m_sLMtx[4][4];                 // offset 0x60, size 0x40
    f32 m_sRMtx[4][4];                 // offset 0xA0, size 0x40
    f32 m_sTgtMtx[4][4];               // offset 0xE0, size 0x40
    clsTask* m_apcParticleTask[2];     // offset 0x120, size 0x8
    NNS_VECTORFAST m_asParticlePos[2]; // offset 0x130, size 0x20
    clsPlaySe_2D* m_pcPlaySe2D;        // offset 0x150, size 0x4
    f32 m_f32behaviorTailCnt;          // offset 0x154, size 0x4
};

#endif // CHARABLAZE_HPP
