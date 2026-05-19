#ifndef SRSYSTEM_HPP
#define SRSYSTEM_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"

// total size: 0xC
class clsSrPlatform : public clsSingleton<clsSrPlatform> {
public:
    clsSrPlatform() {}
    virtual ~clsSrPlatform() {}

    f32 getPosOffsetRatio_setPS2() const { return m_f32PosOffsetRatio_setPS2; }
    f32 getPosOffsetRatio_setPS2(f32 f32Param1) const
    {
        return f32Param1 * m_f32PosOffsetRatio_setPS2;
    }
    f32 getPosOffsetRatio_setPS2_PAL(f32 f32Param1) const { return f32Param1; }

    s32 getSafeFrame_Width();
    s32 getSafeFrame_Height();

    f32 m_f32PosOffsetRatio_setPS2; // offset 0x4, size 0x4
    f32 m_f32PosOffsetRatio_setWii; // offset 0x8, size 0x4
};

#endif // SRSYSTEM_HPP
