#ifndef BASESVLBTLPLAYERDATA_HPP
#define BASESVLBTLPLAYERDATA_HPP

#include "types.h"

// total size: 0xC
class clsBaseSvlBtlPlayerData {
public:
    virtual ~clsBaseSvlBtlPlayerData() {}

    static u32 t_u32DefaulLife;

    u32 m_u32Life;  // offset 0x4, size 0x4
    u32 m_u32Point; // offset 0x8, size 0x4
};

#endif // BASESVLBTLPLAYERDATA_HPP
