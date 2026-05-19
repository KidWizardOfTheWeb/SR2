#ifndef WORLDMANAGER_HPP
#define WORLDMANAGER_HPP

#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsWorldManagerTask : public clsTask {
public:
    clsWorldManagerTask(clsTask* pcParam1);
    virtual ~clsWorldManagerTask();
    virtual void execute();
};

#endif // WORLDMANAGER_HPP
