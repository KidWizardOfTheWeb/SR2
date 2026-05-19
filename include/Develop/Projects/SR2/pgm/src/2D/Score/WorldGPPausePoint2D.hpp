#ifndef WORLDGPPAUSEPOINT2D_HPP
#define WORLDGPPAUSEPOINT2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ResultRanking.hpp"

class clsWorldGpPausePoint2D_Task : public clsResultRanking2D_Task {
public:
    clsWorldGpPausePoint2D_Task(u32 u32Arg);
    virtual ~clsWorldGpPausePoint2D_Task();

    virtual void execute();
    virtual void init();
};

#endif // WORLDGPPAUSEPOINT2D_HPP
