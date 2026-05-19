#ifndef SURVIVALBALLPARTS2D_HPP
#define SURVIVALBALLPARTS2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreParts2D.hpp"

class clsScore2D_Task;

// total size: 0x360
class clsSurvivalBallParts2D : public clsScoreParts2D {
public:
    clsSurvivalBallParts2D(clsScore2D_Task* pcParent);
    virtual ~clsSurvivalBallParts2D();

    void drawComPoint();
    void drawRingWindow(s32 s32Param1,
                        s32 s32Param2,
                        stcUnionStatus* psUnionStatus,
                        s32 s32Param4,
                        s32 s32Param5,
                        s32 s32Param6,
                        u32 u32Param7);
};

#endif // SURVIVALBALLPARTS2D_HPP
