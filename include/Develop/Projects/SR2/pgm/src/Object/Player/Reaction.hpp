#ifndef REACTION_HPP
#define REACTION_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/GroundCollision.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsPlayerTask;
class clsPlaySe_2D;

enum enmWallType {
    WALL_TYPE__NORMAL = 0,
    WALL_TYPE__WII = 1,
    WALL_TYPE__SPECIAL = 2,
    WALL_TYPE__VERTICAL = 3,
};

enum enmGDiveType {
    GDIVE_TYPE__NORMAL = 0,
    GDIVE_TYPE__CANCEL = 1,
    GDIVE_TYPE__REFLECTION = 2,
};

// total size: 0x40
class clsReaction {
public:
    clsReaction() {}
    clsReaction(clsPlayerTask* pcParam1) : m_pcPlayer(pcParam1) {}

    enum enmColEfefctType {
        COL_EFFECT_GROUND = 0,
        COL_EFFECT_WALL = 1,
    };

    NNS_VECTORFAST m_sWallVecFast; // offset 0x0, size 0x10
    clsPlayerTask* m_pcPlayer;     // offset 0x10, size 0x4
    clsPlaySe_2D* m_pcPlaySe2D;    // offset 0x14, size 0x4
    f32 m_f32EffectFrame;          // offset 0x18, size 0x4
    f32 m_f32EffectSubFrame;       // offset 0x1C, size 0x4
    enmWallType m_eWallType;       // offset 0x20, size 0x4
    enmGDiveType m_eGDiveType;     // offset 0x24, size 0x4
    s8 m_s8WallHitCount;           // offset 0x28, size 0x1
    vector m_vecColInfo;           // offset 0x2C, size 0xC

    void alwaysChangeSpeed();
    void triggerDead();
    void rideonPlayer();
    void triggerPathMove();
    void triggerSlowDown();
    void triggerBadRoad();
    void triggerChangeGravity();
    void alwaysStream();
    void removeChangeSpeed();
    void alwaysBadRoad();
    void updateWall();
    void removeBadRoad();
    void updateGround();
    void requestGroundEffect(const clsGroundCollision::stcInfo* opcColInfo, enmColEfefctType eType);
    void initSe();
    void actionWallHitGravityDive();
    void actionWallHitGravityDiveAuto();
    void actionWallHitGravityControl();
    void actionWallHitWheelDrift();
    void actionWallHitGround();
    void actionWallHitFlight();
    void actionCommonWallHitSide();
    void actionCommonWallHitFloor();

    static u32 otau32Se_Trees[2];
};

#endif // REACTION_HPP
