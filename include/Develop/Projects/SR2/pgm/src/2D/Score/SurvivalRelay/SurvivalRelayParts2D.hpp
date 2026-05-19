#ifndef SURVIVALRELAYPARTS2D_HPP
#define SURVIVALRELAYPARTS2D_HPP

#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreParts2D.hpp"

// total size: 0x360
class clsSurvivalRelayParts2D : public clsScoreParts2D {
public:
    clsSurvivalRelayParts2D(clsScore2D_Task* pcParent);
    ~clsSurvivalRelayParts2D();
    virtual void draw();
};

#endif // SURVIVALRELAYPARTS2D_HPP
