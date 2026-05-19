#ifndef SURVIVALRELAYINFO2D_HPP
#define SURVIVALRELAYINFO2D_HPP

#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreInfo2D.hpp"

// total size: 0x70
class clsSurvivalRelayInfo2D : public clsScoreInfo2D {
public:
    clsSurvivalRelayInfo2D(clsScore2D_Task* pcParent);
    virtual ~clsSurvivalRelayInfo2D();
    virtual void draw();
    virtual void RankMain();
};

#endif // SURVIVALRELAYINFO2D_HPP
