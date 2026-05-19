#ifndef COMDATA_HPP
#define COMDATA_HPP

#include "types.h"

namespace nspCom {

// total size: 0x8
class _ComStartParam {
public:
    s32 s32DelayFrame60; // offset 0x0, size 0x4
    f32 f32Accel;        // offset 0x4, size 0x4
};

extern _ComStartParam oasComStartParam[7];

} // namespace nspCom

#endif // COMDATA_HPP
