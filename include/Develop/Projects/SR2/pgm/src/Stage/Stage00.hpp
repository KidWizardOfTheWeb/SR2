#ifndef STAGE00_HPP
#define STAGE00_HPP

#include "Develop/Projects/SR2/pgm/src/Stage/BaseStage.hpp"

class clsStage00_Task : public clsBaseStage_Task {
public:
    clsStage00_Task(stcBinInfo& rsBinInfoI) : clsBaseStage_Task(rsBinInfoI) {}
    virtual ~clsStage00_Task();

    virtual void init();
};

#endif // STAGE00_HPP
