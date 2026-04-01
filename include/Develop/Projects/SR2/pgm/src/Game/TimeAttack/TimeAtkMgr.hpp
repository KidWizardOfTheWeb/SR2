#ifndef TIMEATKMGR_HPP
#define TIMEATKMGR_HPP

// Enum for TimeAtkMgr start modes
enum enmStartMode {
    START_NORMAL = 0,
    START_GHOST_VS = 1,
    START_WORLD_RANKING = 2,
    START_FORCE_NORMAL = 3,
};

// class clsTimeAtkMgr
class clsTimeAtkMgr {
public:
    enum enmStartMode m_eStartMode;           // offset 0x4, size 0x4
    signed int m_s32StageNo;                  // offset 0x8, size 0x4
    unsigned char m_u8CharaId;                // offset 0xC, size 0x1
    unsigned char m_u8PadNo;                  // offset 0xD, size 0x1
    unsigned char m_u8GearId;                 // offset 0xE, size 0x1
    unsigned char m_bNextWorldRanking;        // offset 0xF, size 0x1
    unsigned char m_bStartWorldRanking;       // offset 0x10, size 0x1
    unsigned char m_bModeWorldRanking;        // offset 0x11, size 0x1
};

#endif // TIMEATKMGR_HPP
