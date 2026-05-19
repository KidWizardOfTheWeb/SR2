#ifndef PS2_SHIMMER_HPP
#define PS2_SHIMMER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Effect/Post/Shimmer/BaseShimmer.hpp"

// total size: 0xBC
class clsPfShimmer_Task : public clsBaseShimmer_Task {
public:
    clsPfShimmer_Task();
    virtual ~clsPfShimmer_Task() {}

    virtual void drawGeometry(u32 u32vI);

    u64* m_pu64Packet; // offset 0xB0, size 0x4
    s32 m_s32y;        // offset 0xB4, size 0x4
    f32 m_f32v;        // offset 0xB8, size 0x4
};

#endif // PS2_SHIMMER_HPP
