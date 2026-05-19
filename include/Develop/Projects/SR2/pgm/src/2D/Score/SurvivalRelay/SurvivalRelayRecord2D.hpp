#ifndef SURVIVALRELAYRECORD2D_HPP
#define SURVIVALRELAYRECORD2D_HPP

#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreRecord2D.hpp"

// total size: 0x180
class clsSurvivalRelayRecord2D : public clsScoreRecord2D {
public:
    clsSurvivalRelayRecord2D(clsScore2D_Task* pcParent);
    virtual ~clsSurvivalRelayRecord2D();
    void draw();
};

#endif // SURVIVALRELAYRECORD2D_HPP
