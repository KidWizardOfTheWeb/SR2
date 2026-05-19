#ifndef STAGE01_HPP
#define STAGE01_HPP

#include "Develop/Projects/SR2/pgm/src/Stage/DivStage.hpp"

// total size: 0x498
class clsStage01_Task : public clsDivStage_Task {
public:
    clsStage01_Task(stcBinInfo& rsBinInfoI) : clsDivStage_Task(rsBinInfoI) {}
    virtual ~clsStage01_Task() {}
};

#endif // STAGE01_HPP
