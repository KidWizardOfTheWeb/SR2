#ifndef SURVIVALBATTLERACE_HPP
#define SURVIVALBATTLERACE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Game/BaseRace.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/SurvivalBattle/BaseSvlBtlPlayerData.hpp"

class clsPlayerTask;

// total size: 0xCDC
class clsSurvivalBattleRace_Task : public clsBaseRace_Task {
public:
    enum enmRule {
        RULE__POINT = 0,
        RULE__SUDDENDEATH = 1,
    };

    enum enmSetting {
        SETTING__TYPE_00 = 0,
        SETTING__TYPE_01 = 1,
        SETTING__TYPE_02 = 2,
        MAX_SETTING_NUM = 3,
    };

    static f32 tof32PlayerScale;
    static f32 tof32ItemBoxScale;
    static s32 toas32SettingLifeTable[3];
    static s32 toas32SettingTimeTable[3];
    static u32 m_u32BattleCount;
    static u32 m_au32PlayerWinCount[4];

    clsSurvivalBattleRace_Task(enmRule eRule,
                               enmSetting eSetting,
                               s32 s32Param0,
                               s32 s32Param1,
                               s32 s32Param2,
                               const stcSendAdv* pcSendAdv,
                               void** ppvParam,
                               enmMode eMode);

    virtual ~clsSurvivalBattleRace_Task() {}

    virtual void execute();
    virtual u8 packEtc();
    virtual void restart();
    virtual void Main();
    virtual void requestReadEtc();

    s32 getLifeMax();
    void draw();
    void mainSuddenDeathRule();
    void damegeMissile(clsPlayerTask* pcAttacker, clsPlayerTask* pcTarget);
    void damegeBomb(clsPlayerTask* pcAttacker, clsPlayerTask* pcTarget);
    void damegeGimmick(clsPlayerTask* pcTarget);
    void damegeGravity(clsPlayerTask* pcAttacker, clsPlayerTask* pcTarget);
    void damegeFall(clsPlayerTask* pcTarget);

    clsBaseSvlBtlPlayerData* m_pcPlayerData; // offset 0xCB0, size 0x4
    enmRule m_eRule;                         // offset 0xCB4, size 0x4
    enmSetting m_eSetting;                   // offset 0xCB8, size 0x4
    s32 m_s32LimitTimeSec;                   // offset 0xCBC, size 0x4
    u32 m_u32DeshPlayer;                     // offset 0xCC0, size 0x4
    clsTask* m_psWinLose;                    // offset 0xCC4, size 0x4
    u8 m_abPlayerWinFlag[4];                 // offset 0xCC8, size 0x4
    u8 m_bWinDrawFlag;                       // offset 0xCCC, size 0x1
    void* m_pvWinLose2DPackBuffer;           // offset 0xCD0, size 0x4
    void* m_pvSuBattle2DPackBuffer;          // offset 0xCD4, size 0x4
    void* m_pvSuBattleMap2DPackBuffer;       // offset 0xCD8, size 0x4
};

#endif // SURVIVALBATTLERACE_HPP
