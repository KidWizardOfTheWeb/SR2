#ifndef GAME_HPP
#define GAME_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/Story/StoryMgr.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/WorldGp/WorldGpMgr.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/TimeAttack/TimeAtkMgr.hpp"

// Enum for game modes
enum enmMode {
    GAME_MODE___NONE = 0,
    GAME_MODE___ADVERTISE = 1,
    GAME_MODE___TITLE_DEMO = 2,
    GAME_MODE___FREE_RACE = 3,
    GAME_MODE___TIME_ATTACK = 4,
    GAME_MODE___STORY = 5,
    GAME_MODE___WORLD_GP = 6,
    GAME_MODE___MISSION = 7,
    GAME_MODE___TUTORIAL = 8,
    GAME_MODE___SURVIVAL_RELAY = 9,
    GAME_MODE___SURVIVAL_BALL = 10,
    GAME_MODE___SURVIVAL_BATTLE = 11,
    GAME_MODE___EVENT = 12,
    GAME_MODE___CREDIT = 13,
    GAME_MODE___EASY_MENU = 14,
    GAME_MODE___MODEL_VIEWER = 15,
    GAME_MODE___MAX = 16,
};

// class stcSendAdv - used by stcSendNextModeData
class stcSendAdv {
public:
    unsigned int u5CharaId : 5;  // offset 0x0, size 0x4
    unsigned int u2PadNo : 2;    // offset 0x0, size 0x4
    unsigned int u1Paddin : 1;   // offset 0x0, size 0x4
    unsigned int u8GearCtrlNo : 8; // offset 0x0, size 0x4
    unsigned int u8Padding1 : 8; // offset 0x0, size 0x4
    unsigned int u8Padding2 : 8; // offset 0x0, size 0x4
};

// class stcSendNextModeData - used by clsGameMgr
class stcSendNextModeData {
public:
    class stcSendAdv sSendAdv[8]; // offset 0x0, size 0x20
    enum enmMode eNextMode;       // offset 0x20, size 0x4
    signed char s8StageNo;        // offset 0x24, size 0x1
    signed char s8PlayerNum;      // offset 0x25, size 0x1
    signed char s8UserNum;        // offset 0x26, size 0x1
    signed char s8UniqueData;     // offset 0x27, size 0x1
};

// class clsGameMgr
class clsGameMgr : public clsSingleton<clsGameMgr> {
public:
    class stcSendNextModeData m_sSendNextModeData; // offset 0x4, size 0x28
    class clsStoryMgr cStoryMgr;                  // offset 0x2C, size 0x14
    class clsWorldGpMgr cWorldGpMgr;              // offset 0x40, size 0x28
    class clsTimeAtkMgr cTimeAtkMgr;              // offset 0x68, size 0x14
    unsigned char * m_pu8MapBuffer;               // offset 0x7C, size 0x4
    enum enmMode m_eMode;                         // offset 0x80, size 0x4
    unsigned int m_u32EtcUnlock;                  // offset 0x84, size 0x4
    unsigned char m_eResultSelect;                // offset 0x88, size 0x1
    signed char m_s8TitleDemoNo;                  // offset 0x89, size 0x1
    signed char m_s8SecretTrickType;              // offset 0x8A, size 0x1
    signed char m_s8SecretCommnadCount[2];        // offset 0x8B, size 0x2
    unsigned char m_bLogoSkip;                    // offset 0x8D, size 0x1
    unsigned char m_bStartLoad;                   // offset 0x8E, size 0x1
    unsigned char m_bStartTutorial;               // offset 0x8F, size 0x1
    unsigned char m_abMissionUnLock[16][4];       // offset 0x90, size 0x40
    unsigned char m_abStageUnLock[16];            // offset 0xD0, size 0x10
    unsigned char m_abCharaUnLock[11];            // offset 0xE0, size 0xB
    unsigned char m_bEnableRenderNowLodingExpand; // offset 0xEB, size 0x1

    signed int getFreeAgp_Option() const;
    signed int getRelayAgp_Option() const;
};

#endif // GAME_HPP
