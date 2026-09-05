#ifndef CHARASILVER_HPP
#define CHARASILVER_HPP

#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaNodeBase.hpp"
#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsRainDrops_Task;

// total size: 0x140
class clsCharaSilver : public clsCharaNodeBase {
public:
    clsCharaSilver(clsPlayerTask* pcPlayer, u8 u8ModelType);
    virtual ~clsCharaSilver() {}

    virtual f32 getCollisionRadius() const { return tof32CollisionRadius; }
    virtual f32 getDrawOffset() const { return 0.0f; }
    virtual void behavior();
    virtual void initAttack00();
    virtual void initAttack01();
    virtual void actionAttack00();
    virtual void actionAttack01();

    void loadAdditionalData(stcBinInfo& rsBinInfo);

    static clsBackLineEffectTask::stcParam sSilverLineParam;
    static f32 tof32CollisionRadius;

    clsBackLineEffectTask* m_pcLineTask;  // offset 0x60, size 0x4
    f32 m_sLMtx[4][4];                    // offset 0x70, size 0x40
    f32 m_sRMtx[4][4];                    // offset 0xB0, size 0x40
    NNS_VECTORFAST m_asParticlePos[2];    // offset 0xF0, size 0x20
    NNS_VECTORFAST m_asDFieldPosVF[2];    // offset 0x110, size 0x20
    clsTask* m_apcParticleTask[2];        // offset 0x130, size 0x8
    f32 m_f32behaviorTailCnt;             // offset 0x138, size 0x4
    clsRainDrops_Task* m_pcRainDrop_Task; // offset 0x13C, size 0x4
};

#endif // CHARASILVER_HPP
