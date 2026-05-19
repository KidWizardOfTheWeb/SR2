#ifndef STORYMGR_HPP
#define STORYMGR_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Texture/nntexture.h"

// struct stcFormer - used by clsStoryMgr
struct stcFormer {
    u8 u8StoryNo; // offset 0x0, size 0x1
    u8 u8StageNo; // offset 0x1, size 0x1
    u8 u8EventNo; // offset 0x2, size 0x1
    u8 u8MovieNo; // offset 0x3, size 0x1
};

// total size: 0x2
struct stcDetailData {
    u8 eDetailType;  // offset 0x0, size 0x1
    u8 u8TypeExecNo; // offset 0x1, size 0x1
};

// total size: 0x2
struct stcDetailRaceChara {
    s8 s8CharaId;    // offset 0x0, size 0x1
    u8 u8GearCtrlNo; // offset 0x1, size 0x1
};

// total size: 0x16
struct stcDetailRace {
    s8 s8StageNo;                             // offset 0x0, size 0x1
    u8 u8VictoryType;                         // offset 0x1, size 0x1
    u8 u8VictoryLimitMin;                     // offset 0x2, size 0x1
    u8 u8VictoryLimitSec;                     // offset 0x3, size 0x1
    stcDetailRaceChara oasDetailRaceChara[9]; // offset 0x4, size 0x12
};

// class clsStoryMgr
class clsStoryMgr {
public:
    virtual ~clsStoryMgr() {}

    s8 getTopComCharaId(s32 s32StageNo);
    void startResist();
    void destroy();
    void setStoryUnlock();
    void reinit(s32 s32StoryNoI);
    s8 getNo() const { return m_s8StoryNo; }
    _NNS_TEXLIST* getTexList_Loading_p() { return m_psTexList_Loading; }

    _NNS_TEXLIST* m_psTexList_Loading; // offset 0x4, size 0x4
    u32 m_u32VictoryLimitMilliSec;     // offset 0x8, size 0x4
    stcFormer m_sFormer;               // offset 0xC, size 0x4
    u8 m_eVictoryType;                 // offset 0x10, size 0x1
    u8 m_eHbMode;                      // offset 0x11, size 0x1
    s8 m_s8StoryNo;                    // offset 0x12, size 0x1
    s8 m_s8DetailNo;                   // offset 0x13, size 0x1
};

#endif // STORYMGR_HPP
