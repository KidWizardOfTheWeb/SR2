#ifndef ATTRINFO_HPP
#define ATTRINFO_HPP

#include "types.h"

// total size: 0x8
struct stcAttrInfo {
    s32 m_s32PartsNum;  // offset 0x0, size 0x4
    s32 m_s32VertexNum; // offset 0x4, size 0x4
};

#endif // ATTRINFO_HPP
