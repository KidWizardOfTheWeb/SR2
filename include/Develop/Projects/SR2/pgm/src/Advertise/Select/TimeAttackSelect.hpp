#ifndef TIMEATTACKSELECT_HPP
#define TIMEATTACKSELECT_HPP

#include "Develop/Projects/SR2/pgm/src/Advertise/Select/FreeRaceSelect.hpp"

// total size: 0x5C
class clsTimeAttackSelect_Task : public clsFreeRaceSelect_Task {
public:
    virtual ~clsTimeAttackSelect_Task() {}

    virtual void execRule();
    virtual void drawMainDepend();
    virtual void drawRule();
};

#endif // TIMEATTACKSELECT_HPP
