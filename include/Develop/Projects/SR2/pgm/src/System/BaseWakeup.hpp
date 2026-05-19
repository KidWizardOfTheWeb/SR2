#ifndef BASEWAKEUP_HPP
#define BASEWAKEUP_HPP

#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0x54
class clsBaseWakeup_Task : public clsTask {
public:
    clsBaseWakeup_Task() : clsTask(0, 0) {}
    virtual ~clsBaseWakeup_Task() {}

    virtual void executeExit();
};

#endif // BASEWAKEUP_HPP
