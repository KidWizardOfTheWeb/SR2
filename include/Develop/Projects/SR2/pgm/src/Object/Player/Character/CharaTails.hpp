#ifndef CHARATAILS_HPP
#define CHARATAILS_HPP

#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaNodeBase.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "types.h"

struct NNS_MOTION;
class clsPlaySe_2D;

// total size: 0x70
class clsCharaTails : public clsCharaNodeBase {
    // Members
public:
    u8 m_u8BeforeMotNo;         // offset 0x60, size 0x1
    NNS_MOTION* m_psMotionA;    // offset 0x64, size 0x4
    NNS_MOTION* m_psMotionB;    // offset 0x68, size 0x4
    clsPlaySe_2D* m_pcPlaySe2D; // offset 0x6C, size 0x4

    // Static members
public:
    static f32 tof32CollisionRadius;

    // Virtual functions
public:
    virtual ~clsCharaTails();

    f32 getCollisionRadius() const { return tof32CollisionRadius; }
    f32 getDrawOffset() const;

    virtual void draw(u32 u32AddDrawFlagI);
    virtual void behavior();
    virtual void initAttack00();
    virtual void initAttack01();
    virtual void actionAttack00();
    virtual void actionAttack01();
    void loadAdditionalData(stcBinInfo& rsBinInfo);
};

#endif // CHARATAILS_HPP
