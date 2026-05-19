#ifndef GDTRAINDATA_HPP
#define GDTRAINDATA_HPP

#include "types.h"

// total size: 0x5
struct stcGDTrainData {
    u8 bEnableDebug;   // offset 0x0, size 0x1
    u8 u8TrainNo;      // offset 0x1, size 0x1
    u8 u8StartRank[3]; // offset 0x2, size 0x3
};

#endif // GDTRAINDATA_HPP
