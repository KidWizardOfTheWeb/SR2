#ifndef SURVIVALRELAYATENTIONATTACK2D_HPP
#define SURVIVALRELAYATENTIONATTACK2D_HPP

#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreAtentionAttack2D.hpp"

// total size: 0x3C
class clsSurvivalRelayAttentionAttack2D : public clsScoreAttentionAttack2D {
public:
    clsSurvivalRelayAttentionAttack2D(clsScore2D_Task* pcParent);
    virtual ~clsSurvivalRelayAttentionAttack2D();
    virtual void draw();
};

#endif // SURVIVALRELAYATENTIONATTACK2D_HPP
