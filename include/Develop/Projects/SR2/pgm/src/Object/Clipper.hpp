#ifndef CLIPPER_HPP
#define CLIPPER_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "types.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"

struct stcBinDataDetail;

// total size: 0x14
class clsClipper : public clsSingleton<clsClipper> {
public:
    clsClipper();
    virtual ~clsClipper() {}

    u8 check(u32 u32Param1,
             const NNS_OBJECT& rsParam2,
             const f32 (&rsParam3)[4][4],
             u8 u8Param4,
             f32 f32Param5,
             f32* pf32Param6)
    {
        return 0;
    }

    static f32 MIN_Z;
    static f32 MAX_Z;

    f32 m_f32NnClipNear;                  // offset 0x4, size 0x4
    f32 m_f32NnClipFar;                   // offset 0x8, size 0x4
    stcBinDataDetail* m_opsBinDataDetail; // offset 0xC, size 0x4
    u32* m_pu32DebugDisableCilp;          // offset 0x10, size 0x4
};

#endif // CLIPPER_HPP
