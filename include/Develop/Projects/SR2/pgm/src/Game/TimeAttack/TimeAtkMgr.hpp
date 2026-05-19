#ifndef TIMEATKMGR_HPP
#define TIMEATKMGR_HPP
#include "types.h"

// total size: 0x14
class clsTimeAtkMgr {
public:
    enum enmStartMode {
        START_NORMAL = 0,
        START_GHOST_VS = 1,
        START_WORLD_RANKING = 2,
        START_FORCE_NORMAL = 3,
    };

    virtual ~clsTimeAtkMgr() {}

    void startResist();
    void reinit(enmStartMode enStartMode, s32 s32StageNo);

    enmStartMode m_eStartMode; // offset 0x4, size 0x4
    s32 m_s32StageNo;          // offset 0x8, size 0x4
    u8 m_u8CharaId;            // offset 0xC, size 0x1
    u8 m_u8PadNo;              // offset 0xD, size 0x1
    u8 m_u8GearId;             // offset 0xE, size 0x1
    u8 m_bNextWorldRanking;    // offset 0xF, size 0x1
    u8 m_bStartWorldRanking;   // offset 0x10, size 0x1
    u8 m_bModeWorldRanking;    // offset 0x11, size 0x1
};

#endif // TIMEATKMGR_HPP
