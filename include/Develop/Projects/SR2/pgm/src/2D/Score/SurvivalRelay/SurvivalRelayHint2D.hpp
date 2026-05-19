#ifndef SURVIVALRELAYHINT2D_HPP
#define SURVIVALRELAYHINT2D_HPP

#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreHint2D.hpp"

// total size: 0x54
class clsSurvivalRelayHint2D : public clsScoreHint2D {
public:
    clsSurvivalRelayHint2D(clsScore2D_Task* pcParent);
    virtual ~clsSurvivalRelayHint2D();
    virtual void draw();
};

#endif // SURVIVALRELAYHINT2D_HPP
