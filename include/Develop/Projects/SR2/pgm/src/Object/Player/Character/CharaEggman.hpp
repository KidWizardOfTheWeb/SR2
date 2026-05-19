#ifndef CHARAEGGMAN_HPP
#define CHARAEGGMAN_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/Character.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

// total size: 0xD0
class clsCharaEggman : public clsCharacter {
public:
    clsCharaEggman(clsPlayerTask* pcPlayer, u8 u8ModelType);
    virtual ~clsCharaEggman() {}
    virtual f32 getCollisionRadius() const { return tof32CollisionRadius; }
    virtual f32 getDrawOffset() const { return 0.0f; }
    virtual void draw(u32 u32AddDrawFlagI);
    virtual void behavior();
    virtual void initAttack00();
    virtual void initAttack01();
    virtual void actionAttack00();
    virtual void actionAttack01();
    virtual s8 getNodeIndex(clsCharacter::enmCharaBornNo eIndex) const;

    void loadAdditionalData(stcBinInfo& rsBinInfo);

    f32 m_sMtx[4][4];                  // offset 0x60, size 0x40
    NNS_VECTORFAST m_asParticlePos[2]; // offset 0xA0, size 0x20
    s32 m_a32BaseRot;                  // offset 0xC0, size 0x4

    static f32 tof32CollisionRadius; // 0x664DA8, value: 0.6f
};

#endif // CHARAEGGMAN_HPP
