#ifndef MAIN_HPP
#define MAIN_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOProfile.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/Factor.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/History.hpp"
#include "types.h"

namespace nspLoadingData {
// total size: 0xC
struct stcVecS32 {
    s32 x; // offset 0x0, size 0x4
    s32 y; // offset 0x4, size 0x4
    s32 z; // offset 0x8, size 0x4
};

// total size: 0x28
struct stcLoadingCircle {
    stcVecS32 sCurRot;  // offset 0x0, size 0xC
    stcVecS32 sAddRot;  // offset 0xC, size 0xC
    stcVecS32 sBaseRot; // offset 0x18, size 0xC
    f32 f32Scale;       // offset 0x24, size 0x4
};

// total size: 0x4
struct stcNowLoadingText {
    u8 u8DrawNum; // offset 0x0, size 0x1
    u8 u8MaxNum;  // offset 0x1, size 0x1
    u8 u8DrawCnt; // offset 0x2, size 0x1
    u8 u8MaxCnt;  // offset 0x3, size 0x1
};

void tRenderNowLoading_CallBack();
void tRenderNowLoadingCircle(stcLoadingCircle* psParam1,
                             u32 u32Param2,
                             f32 f32Param3,
                             f32 f32Param4,
                             f32 f32Param5,
                             s32 s32Param6);

extern stcLoadingCircle asLoadingCircle[3];
} // namespace nspLoadingData

#endif // MAIN_HPP
