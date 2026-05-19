#ifndef CTRLICONSURVIVALRELAY_HPP
#define CTRLICONSURVIVALRELAY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0x54
class clsCtrlIconSurvivalRelay_Task : public clsTask {
public:
    clsCtrlIconSurvivalRelay_Task();
    virtual ~clsCtrlIconSurvivalRelay_Task();

    virtual void draw();
    void drawNextPlayerSpeed();
};

#endif // CTRLICONSURVIVALRELAY_HPP
