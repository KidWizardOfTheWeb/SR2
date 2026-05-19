#ifndef CHARAROUGE_HPP
#define CHARAROUGE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaNodeBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

class clsCharaRouge : public clsCharaNodeBase {
public:
    clsCharaRouge(clsPlayerTask* p0, u8 p1, u8 p2) : clsCharaNodeBase(p0, p1, p2) {}

    virtual ~clsCharaRouge() {}
    virtual f32 getCollisionRadius() const { return 0.0f; }
    virtual f32 getDrawOffset() const { return 0.0f; }

    virtual void behavior();
    virtual void initAttack00();
    virtual void initAttack01();
    virtual void actionAttack00();
    virtual void actionAttack01();
    virtual void draw(u32 p0);
    virtual void loadAdditionalData(stcBinInfo& p0);

    static f32 tof32CollisionRadius;
};

#endif // CHARAROUGE_HPP
