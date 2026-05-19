#ifndef GAME_HPP
#define GAME_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOLight.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/Story/StoryMgr.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/WorldGp/WorldGpMgr.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/TimeAttack/TimeAtkMgr.hpp"

#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

#ifndef ENM_MODE_DECLARED
#define ENM_MODE_DECLARED
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
#endif

// class clsGameMgr
class clsGameMgr : public clsSingleton<clsGameMgr> {
public:
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

    struct stcSendAdv {
        u32 u5CharaId : 5;    // offset 0x0, size 0x4
        u32 u2PadNo : 2;      // offset 0x0, size 0x4
        u32 u1Paddin : 1;     // offset 0x0, size 0x4
        u32 u8GearCtrlNo : 8; // offset 0x0, size 0x4
        u32 u8Padding1 : 8;   // offset 0x0, size 0x4
        u32 u8Padding2 : 8;   // offset 0x0, size 0x4
    };

    // total size: 0x28

    struct stcSendNextModeData {
        stcSendAdv sSendAdv[8]; // offset 0x0, size 0x20
        enmMode eNextMode;      // offset 0x20, size 0x4
        s8 s8StageNo;           // offset 0x24, size 0x1
        s8 s8PlayerNum;         // offset 0x25, size 0x1
        s8 s8UserNum;           // offset 0x26, size 0x1
        s8 s8UniqueData;        // offset 0x27, size 0x1
    };

    clsGameMgr() {}
    virtual ~clsGameMgr() {}

    static s32 MIN_LAP_NUM;
    static s32 MAX_LAP_NUM;
    static c8* m_toac8HbModeName_Debug[2];
    static c8* m_toac8GameModeName_Debug[16];

    stcSendNextModeData m_sSendNextModeData; // offset 0x4, size 0x28
    clsStoryMgr cStoryMgr;                   // offset 0x2C, size 0x14
    clsWorldGpMgr cWorldGpMgr;               // offset 0x40, size 0x28
    clsTimeAtkMgr cTimeAtkMgr;               // offset 0x68, size 0x14
    u8* m_pu8MapBuffer;                      // offset 0x7C, size 0x4
    enum enmMode m_eMode;                    // offset 0x80, size 0x4
    u32 m_u32EtcUnlock;                      // offset 0x84, size 0x4
    u8 m_eResultSelect;                      // offset 0x88, size 0x1
    s8 m_s8TitleDemoNo;                      // offset 0x89, size 0x1
    s8 m_s8SecretTrickType;                  // offset 0x8A, size 0x1
    s8 m_s8SecretCommnadCount[2];            // offset 0x8B, size 0x2
    u8 m_bLogoSkip;                          // offset 0x8D, size 0x1
    u8 m_bStartLoad;                         // offset 0x8E, size 0x1
    u8 m_bStartTutorial;                     // offset 0x8F, size 0x1
    u8 m_abMissionUnLock[16][4];             // offset 0x90, size 0x40
    u8 m_abStageUnLock[16];                  // offset 0xD0, size 0x10
    u8 m_abCharaUnLock[11];                  // offset 0xE0, size 0xB
    u8 m_bEnableRenderNowLodingExpand;       // offset 0xEB, size 0x1

    void reinit();
    void reinitUnlockInfo();
    void setSendNextModeData(enmMode eNextModeI,
                             s32 s32StageNoI,
                             s32 s32PlayerNumI,
                             s32 s32UserNumI,
                             const stcSendAdv* psSendAdvI,
                             s32 s32UniqueDataI);
    s32 getDefaultLapNum(s32 s32StageNoI) const;
    void loadStage(nspPackId::enm eTypeIdI, s32 s32No0I, s32 s32No1I);
    void tRegistRandomCOM(enmMode eModeI,
                          s32 s32UserNumI,
                          s32 s32PlayerNumI,
                          stcSendAdv* posSendAdvI,
                          u32 bGearRandI);
    void startResist();
    void checkSecretTrickTitle();

    void setStoryHint_Option(s8 s8Bool);
    void setFreeLap_Option(s8 s8Lap);
    void setFreeAgp_Option(s8 s8Agp);
    void setFreeHint_Option(s8 s8Bool);
    void setTimeAttackGhost_Option(s8 s8Bool);
    void setWorldGPHint_Option(s8 s8Bool);
    void setRelayLap_Option(s8 s8Lap);
    void setRelayAgp_Option(s8 s8Agp);
    void setBallLimit_Option(s8 s8Limit);
    void setBallPoint_Option(s8 s8Point);
    void setBattleMode_Option(s8 s8Mode);
    void setBattleHP_Option(s8 s8HitPoint);
    void setBattleLimit_Option(s8 s8Limit);

    s32 getStoryHint_Option() const;
    s32 getFreeLap_Option() const;
    s32 getFreeAgp_Option() const;
    s32 getFreeHint_Option() const;
    s32 getTimeAttackGhost_Option() const;
    s32 getWorldGPHint_Option() const;
    s32 getRelayLap_Option() const;
    s32 getRelayAgp_Option() const;
    s32 getBallLimit_Option() const;
    s32 getBallPoint_Option() const;
    s32 getBattleHP_Option() const;
    s32 getBattleLimit_Option() const;

    enmMode getGameMode() const { return m_eMode; }
    u8 getStartLoad() const { return m_bStartLoad; }
    void initSecretTrick() { m_s8SecretTrickType = 0; }
    s8 getSecretTrickType() const { return m_s8SecretTrickType; }
    void resetTitleDemo() { m_s8TitleDemoNo = 0; }
    clsStoryMgr* getStoryMgr() { return &cStoryMgr; }
};

typedef clsGameMgr::stcSendAdv stcSendAdv;
typedef clsGameMgr::stcSendNextModeData stcSendNextModeData;

#endif // GAME_HPP
