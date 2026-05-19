#ifndef STAGE07_HPP
#define STAGE07_HPP

#include "Develop/Projects/SR2/pgm/src/Stage/DivStage.hpp"

// total size: 0x498
class clsStage07_Task : public clsDivStage_Task {
public:
    clsStage07_Task(stcBinInfo& rsBinInfoI);
    virtual ~clsStage07_Task() {}

    void changeDrawParts(u32 ou32OnOff, u32 ou32UserDataNo);
};

#endif // STAGE07_HPP
