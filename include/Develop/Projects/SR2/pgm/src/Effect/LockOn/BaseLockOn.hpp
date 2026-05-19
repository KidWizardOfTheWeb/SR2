#ifndef BASELOCKON_HPP
#define BASELOCKON_HPP

#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

enum enmType {
    TYPE__NONE = 0,
    TYPE__TARGET = 1,
    TYPE__APPOINT = 2,
    TYPE__FIXED = 3,
};

// total size: 0x54
class clsBaseLockOn_Task : public clsTask {
public:
    clsBaseLockOn_Task() : clsTask(0, 0) {}
    virtual ~clsBaseLockOn_Task() {}
};

#endif // BASELOCKON_HPP
