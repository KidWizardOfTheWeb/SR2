#ifndef MISSIONPARTS2D_HPP
#define MISSIONPARTS2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreParts2D.hpp"

class clsMissionParts2D : public clsScoreParts2D {
public:
    virtual ~clsMissionParts2D() {}
    virtual void drawGearWindow(s32 s32PlayerNo,
                                s32 s32View,
                                stcUnionStatus* psUnionSt,
                                s32 s32PosX,
                                s32 s32PosY,
                                s32 s32Dir,
                                u32 ou32CharaColor);
    virtual void drawRingWindow(s32 s32PlayerNo,
                                s32 s32View,
                                stcUnionStatus* psUnionSt,
                                s32 s32PosX,
                                s32 s32PosY,
                                s32 s32Dir,
                                u32 ou32CharaColor);
};

#endif // MISSIONPARTS2D_HPP
