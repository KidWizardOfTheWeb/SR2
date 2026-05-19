#ifndef CHARASAMBA_HPP
#define CHARASAMBA_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaNodeBase.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsPlaySe_2D;

class clsCharaSamba : public clsCharaNodeBase {
public:
    virtual ~clsCharaSamba();

    virtual f32 getCollisionRadius() const;
    virtual f32 getDrawOffset() const;
    virtual void draw(u32 u32AddDrawFlagI);
    virtual void behavior();
    virtual void initAttack00();
    virtual void initAttack01();
    virtual void actionAttack00();
    virtual void actionAttack01();

    void loadAdditionalData(stcBinInfo& rsBinInfo);

    static f32 tof32CollisionRadius;

    // Members
    clsPlaySe_2D* m_pcPlaySe2D; // offset 0x60, size 0x4
};

#endif // CHARASAMBA_HPP
