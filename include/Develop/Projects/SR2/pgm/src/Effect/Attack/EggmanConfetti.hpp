#ifndef EGGMANCONFETTI_HPP
#define EGGMANCONFETTI_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Effect/EggDetail.hpp"

// total size: 0x208
class clsEggConfetti {
public:
    clsEggConfetti(u32 u32vI, u32 u32NumI, u32 u32Flg, f32 f32LifeFrameI);
    virtual ~clsEggConfetti() {}

    void addDetail(u32 u32vI, u32 u32NumI, u32 f32LifeFrameI, f32 f32Param4);
    void draw();

    stcEggDetail m_sEggDetail[32]; // offset 0x4, size 0x200
    u8 m_u8EggDetailLoopNo;        // offset 0x204, size 0x1
};

#endif // EGGMANCONFETTI_HPP
