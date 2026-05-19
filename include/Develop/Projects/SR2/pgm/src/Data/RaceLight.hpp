#ifndef RACELIGHT_HPP
#define RACELIGHT_HPP

#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0x54
class clsRaceLight_Task : public clsTask {
public:
    clsRaceLight_Task();
    virtual ~clsRaceLight_Task() {}
    virtual void draw();
};

#endif // RACELIGHT_HPP
