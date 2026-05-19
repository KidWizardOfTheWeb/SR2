#ifndef STAGE11_HPP
#define STAGE11_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Stage/DivStage.hpp"

// total size: 0x49C
class clsStage11_Task : public clsDivStage_Task {
public:
    clsStage11_Task(stcBinInfo& rsBinInfoI) : clsDivStage_Task(rsBinInfoI) {}
    virtual ~clsStage11_Task() {}
    void execute();

    s32 m_s32SeId; // offset 0x498, size 0x4
};

#endif // STAGE11_HPP
