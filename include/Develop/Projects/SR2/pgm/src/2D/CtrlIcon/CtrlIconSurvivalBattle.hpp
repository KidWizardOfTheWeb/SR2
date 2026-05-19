#ifndef CTRLICONSURVIVALBATTLE_HPP
#define CTRLICONSURVIVALBATTLE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0x54
class clsCtrlIconSurvivalBattle_Task : public clsTask {
public:
    virtual ~clsCtrlIconSurvivalBattle_Task();

    virtual void draw();

    void drawMissile();
    void drawBomb();
};

#endif // CTRLICONSURVIVALBATTLE_HPP
