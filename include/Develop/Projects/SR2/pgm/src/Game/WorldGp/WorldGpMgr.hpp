#ifndef WORLDGPMGR_HPP
#define WORLDGPMGR_HPP

// class clsWorldGpMgr
class clsWorldGpMgr {
public:
    unsigned int m_u32TotalTime;               // offset 0x4, size 0x4
    unsigned char m_eHbMode;                   // offset 0x8, size 0x1
    unsigned char m_au8Points[8];              // offset 0x9, size 0x8
    unsigned char m_au8Ranking[8];             // offset 0x11, size 0x8
    unsigned char m_au8RankingPlayer[8];       // offset 0x19, size 0x8
    unsigned char m_u8TopComCharacterId;       // offset 0x21, size 0x1
    signed char m_s8WorldGpStageNo;            // offset 0x22, size 0x1
    signed char m_s8DetailNo;                  // offset 0x23, size 0x1
    unsigned char m_u8PlannedTopComId;         // offset 0x24, size 0x1
};

#endif // WORLDGPMGR_HPP
