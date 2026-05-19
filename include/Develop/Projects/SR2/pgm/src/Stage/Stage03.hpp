#ifndef STAGE03_HPP
#define STAGE03_HPP

#include "Develop/Projects/SR2/pgm/src/Stage/DivStage.hpp"

// total size: 0x49C
class clsStage03_Task : public clsDivStage_Task {
public:
    clsStage03_Task(stcBinInfo& rsBinInfoI) : clsDivStage_Task(rsBinInfoI) {}
    virtual ~clsStage03_Task() {}

    virtual void execute();

    s32 m_s32SeId; // offset 0x498, size 0x4
};

#endif // STAGE03_HPP
