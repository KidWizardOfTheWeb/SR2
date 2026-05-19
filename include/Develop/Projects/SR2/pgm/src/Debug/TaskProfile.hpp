#ifndef TASKPROFILE_HPP
#define TASKPROFILE_HPP

#include "types.h"

// total size: 0x14
struct stcTaskProfile {
    s32 s32CurrentPos; // offset 0x0, size 0x4
    s32 s32SortType;   // offset 0x4, size 0x4
    s32 s32DownLimit;  // offset 0x8, size 0x4
    s32 s32OldNum;     // offset 0xC, size 0x4
    s32 s32PageNo;     // offset 0x10, size 0x4
};

#endif // TASKPROFILE_HPP
