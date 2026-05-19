#ifndef WORLDGPMGR_HPP
#define WORLDGPMGR_HPP
#include "types.h"

// total size: 0x28
class clsWorldGpMgr {
public:
    virtual ~clsWorldGpMgr() {}

    void startResist();
    void updateRanking();
    void destroy();
    u32 getRankPoints(u32 u32I);
    void setPoints();
    void setHbMode(u32 eHbModeI);
    void reinit(u32 eHbModeI);

    u32 m_u32TotalTime;       // offset 0x4, size 0x4
    u8 m_eHbMode;             // offset 0x8, size 0x1
    u8 m_au8Points[8];        // offset 0x9, size 0x8
    u8 m_au8Ranking[8];       // offset 0x11, size 0x8
    u8 m_au8RankingPlayer[8]; // offset 0x19, size 0x8
    u8 m_u8TopComCharacterId; // offset 0x21, size 0x1
    s8 m_s8WorldGpStageNo;    // offset 0x22, size 0x1
    s8 m_s8DetailNo;          // offset 0x23, size 0x1
    u8 m_u8PlannedTopComId;   // offset 0x24, size 0x1
};

#endif // WORLDGPMGR_HPP
