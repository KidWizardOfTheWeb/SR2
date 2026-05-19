#ifndef SURVIVALBALLRACE_HPP
#define SURVIVALBALLRACE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Game/BaseRace.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/Game.hpp"

// total size: 0x20
struct _strSurvivalBallData {
    f32 f32CameraAddPos;                  // offset 0x0, size 0x4
    f32 f32CameraFovy;                    // offset 0x4, size 0x4
    f32 f32AdjustGctrlSlideslowdownFrame; // offset 0x8, size 0x4
    f32 f32AdjustGctrlMinSpeed;           // offset 0xC, size 0x4
    f32 f32AdjustGctrlMaxSpeed;           // offset 0x10, size 0x4
    f32 f32GDiveUsedRate;                 // offset 0x14, size 0x4
    f32 f32GCtrlUsedRate;                 // offset 0x18, size 0x4
    f32 f32GctrlNextGC_Frame;             // offset 0x1C, size 0x4
};

// total size: 0x10
struct _strSurvivalBallRuleData {
    u32 u32Minite;     // offset 0x0, size 0x4
    u32 u32Second;     // offset 0x4, size 0x4
    u32 u32MiliSecond; // offset 0x8, size 0x4
    u32 u32MaxPoint;   // offset 0xC, size 0x4
};

// total size: 0xD00
class clsSurvivalBallRace_Task : public clsBaseRace_Task {
public:
    clsSurvivalBallRace_Task(s32 s32StageNoI,
                             u32 u32RuleTimeType,
                             u32 u32RulePointType,
                             s32 s32PlayerNumI,
                             s32 s32UserNumI,
                             s32 s32LapNumI,
                             const stcSendAdv* opsSendAdvI,
                             void** ppvMapBufferI,
                             enmMode eModeI);
    virtual ~clsSurvivalBallRace_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void updateRanking();
    virtual u8 packEtc();
    virtual void restart();
    virtual void Main();
    virtual void requestReadEtc();

    void addPlayerPoint(u32 u32PlayerNo, s32 s32Point);
    u32 getMaxPoint();

    static f32 tof32ItemBoxScale;
    static _strSurvivalBallData scosSurvivalBallData[4];
    static _strSurvivalBallData m_sDbgSurvivalBallData;
    static u32 m_u32BattleCount;
    static u32 m_au32PlayerWinCount[4];

    _strSurvivalBallRuleData m_sSurvivalBallRuleData; // offset 0xCB0, size 0x10
    u32 m_u32DefaultSurvivalBallType;                 // offset 0xCC0, size 0x4
    s32 m_s32SurvivalBallType;                        // offset 0xCC4, size 0x4
    s32 m_as32MaxLap[4];                              // offset 0xCC8, size 0x10
    s32 m_s32DbgGameOverCount;                        // offset 0xCD8, size 0x4
    s32 m_as32PlayerPoint[4];                         // offset 0xCDC, size 0x10
    void* m_pvWinLose2DPackBuffer;                    // offset 0xCEC, size 0x4
    void* m_pvSurvival2DPackBuffer;                   // offset 0xCF0, size 0x4
    clsTask* m_psWinLose;                             // offset 0xCF4, size 0x4
    u8 m_abPlayerWinFlag[4];                          // offset 0xCF8, size 0x4
    u8 m_bWinDrawFlag;                                // offset 0xCFC, size 0x1
};

#endif // SURVIVALBALLRACE_HPP
