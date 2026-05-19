#ifndef OORANDOM_HPP
#define OORANDOM_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "types.h"

// total size: 0x1C
class clsOORandom : public clsSingleton<clsOORandom> {
public:
    clsOORandom();
    virtual ~clsOORandom();

    u32 reinitRand_DependGame(u32 u32SeedI);
    u32 rand_DependGame();
    f32 frandPM(f32 f32Param1) const { return 0.0f; }
    u32 rand_DependGame(u32 u32Param1) { return 0; }
    u32 rand(u32 u32Param1) const { return 0; }
    f32 frand(f32 f32Param1) const { return 0.0f; }
    f32 frandPM_DependGame(f32 f32Param1) { return 0.0f; }

    s32 m_s32Seed_DependGame;          // offset 0x4, size 0x4
    u32 m_u32Seed_CompTime_DependGame; // offset 0x8, size 0x4
    s32 m_s32Gen1_DependGame;          // offset 0xC, size 0x4
    s32 m_s32Gen2_DependGame;          // offset 0x10, size 0x4
    u32 m_u32GameRandCount;            // offset 0x14, size 0x4
    u8 m_bIsPossibleGameRand;          // offset 0x18, size 0x1
};

#endif // OORANDOM_HPP
