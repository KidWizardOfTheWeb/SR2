#ifndef SURVIVALRELAYMETER2D_HPP
#define SURVIVALRELAYMETER2D_HPP

#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreMeter2D.hpp"

// total size: 0x10C
class clsSurvivalRelayMeter2D : public clsScoreMeter2D {
public:
    clsSurvivalRelayMeter2D(clsScore2D_Task* pcParent);
    virtual ~clsSurvivalRelayMeter2D();
    virtual void draw();
    virtual void executeMeter(u32 u32View, u32 u32PlayerNo);
};

#endif // SURVIVALRELAYMETER2D_HPP
