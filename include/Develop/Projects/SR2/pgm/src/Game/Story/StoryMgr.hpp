#ifndef STORYMGR_HPP
#define STORYMGR_HPP

#include "usr/local/sega/nn/NNS.hpp"

class _NNS_TEXLIST;

// struct stcFormer - used by clsStoryMgr
struct stcFormer {
    unsigned char u8StoryNo;     // offset 0x0, size 0x1
    unsigned char u8StageNo;     // offset 0x1, size 0x1
    unsigned char u8EventNo;     // offset 0x2, size 0x1
    unsigned char u8MovieNo;     // offset 0x3, size 0x1
};

// class clsStoryMgr
class clsStoryMgr {
public:
    class _NNS_TEXLIST * m_psTexList_Loading; // offset 0x4, size 0x4
    unsigned int m_u32VictoryLimitMilliSec;   // offset 0x8, size 0x4
    struct stcFormer m_sFormer;                // offset 0xC, size 0x4
    unsigned char m_eVictoryType;             // offset 0x10, size 0x1
    unsigned char m_eHbMode;                  // offset 0x11, size 0x1
    signed char m_s8StoryNo;                  // offset 0x12, size 0x1
    signed char m_s8DetailNo;                 // offset 0x13, size 0x1
};

#endif // STORYMGR_HPP
