#ifndef MISSIONRACE_HPP
#define MISSIONRACE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Game/BaseRace.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOClock.hpp"

class clsMissionTarget;

enum enmTrickA {
    MISSION__TRICK_A_NON = 0,
    MISSION__TRICK_A_GOOD = 1,
    MISSION__TRICK_A_BAD = 2,
};

typedef clsOOClock::stcRecord stcRecord;

// total size: 0x34
struct stcMissionParam {
    f32 f32Agp;             // offset 0x0, size 0x4
    u32 u32Ring;            // offset 0x4, size 0x4
    u32 u32Time;            // offset 0x8, size 0x4
    s32 s32ConditionBronze; // offset 0xC, size 0x4
    s32 s32ConditionSilver; // offset 0x10, size 0x4
    s32 s32ConditionGold;   // offset 0x14, size 0x4
    u8 u8RuleType;          // offset 0x18, size 0x1
    u8 u8CountDownFlag;     // offset 0x19, size 0x1
    s8 as8Chara[8];         // offset 0x1A, size 0x8
    s8 as8Gear[8];          // offset 0x22, size 0x8
    u8 au8GearLevel[8];     // offset 0x2A, size 0x8
    u8 u8Padding[2];        // offset 0x32, size 0x2
};

// total size: 0x8
struct stcMissionRingAgp {
    s16 m_s16Ring; // offset 0x0, size 0x2
    f32 m_f32Agp;  // offset 0x4, size 0x4
};

// total size: 0x4
struct uMissionJudge32 {
    union {
        s32 m_s32MaxLinkCount;
        s32 m_s32TrickPoint;
        u32 m_u32GravityMSec;
        f32 m_f32GravityRemove;
        u32 m_u32GrindPoint;
        u32 m_u32TargetMSec;
        enmTrickA m_eTrickA;
        u32 m_u32AttackCount;
    };
};

// total size: 0x4
struct uMissionCount32 {
    union {
        u32 m_u32StartMSec;
        f32 m_f32AddGravityRemove;
        u32 m_u32GravityLink;
        f32 m_f32TargetDistance;
        u32 m_u32AttackFlag;
    };
};

// total size: 0xD3C
class clsMissionRace_Task : public clsBaseRace_Task {
public:
    static f32 tof32MissionBreakFrame;
    static s32 sos32TrickPoint[7];
    static stcMissionRingAgp scosMissionRingAgp[20];
    static f32 scosAgpPointRate[17];
    static void* m_pvMission2DPackBuffer;
    static void* m_pvMissionStg2DPackBuffer;

    clsMissionRace_Task(s32 s32A, s32 s32B, const stcSendAdv* pcAdv, void** ppv, enmMode eMode);
    virtual ~clsMissionRace_Task() {}
    virtual void execute();
    virtual void draw();
    virtual u8 isStartDash() const { return 0; }
    virtual u32 getStartTimeMilliSec() const { return 0; }
    virtual void start() {}
    virtual u8 packEtc();
    virtual void settingPlayer() {}
    virtual void restart();
    virtual void setPauseScreen(s32 s32A, clsBaseRacePause_Task::enmPadConnectDraw ePad);
    virtual void Main() {}
    virtual void requestReadEtc();
    virtual void setClearUnlock();
    virtual void wakeUpResult();
    virtual u8 isClearRank() const { return 0; }
    virtual u8 checkGoalComPlayer() { return 0; }
    virtual void MissionChack() {}

    u8 isBestScore(u32 u32Idx);
    void setMissionParam(u8* pu8);
    void getAddTime(u32 u32Idx);
    s8 checkCondition();
    void setMissionClearUnlock();
    void LoadTexture(clsGameMgr::enmMode eMode, s32 s32A);

    s32 getMissionNo() const { return m_s32MissionNo; }
    u8 getRuleType() const { return m_sMissionParamTbl.u8RuleType; }

    stcRecord m_sMissionTime;              // offset 0xCB0, size 0x4
    u8 m_bPractice;                        // offset 0xCB4, size 0x1
    s8 m_s8ClearRank;                      // offset 0xCB5, size 0x1
    u8 m_bEndFlag2D;                       // offset 0xCB6, size 0x1
    u8 m_bReadyFlag2D;                     // offset 0xCB7, size 0x1
    s32 m_s32MissionNo;                    // offset 0xCB8, size 0x4
    clsMissionTarget* m_pcMissionTarget;   // offset 0xCBC, size 0x4
    stcMissionParam m_sMissionParamTbl;    // offset 0xCC0, size 0x34
    clsTask* m_pcResult2D;                 // offset 0xCF4, size 0x4
    clsTask* m_pcMission2DMain;            // offset 0xCF8, size 0x4
    clsTask* m_pcMission2DSub;             // offset 0xCFC, size 0x4
    u8 m_bEndFlagTime2D;                   // offset 0xD00, size 0x1
    u8 m_bLoadFlag2D;                      // offset 0xD01, size 0x1
    void* m_pvSurvivalMessage2DPackBuffer; // offset 0xD04, size 0x4
    void* m_pvWinLose2DPackBuffer;         // offset 0xD08, size 0x4
    s32 m_s32DbgGameOverCount;             // offset 0xD0C, size 0x4
    u32 m_u32TargetCount;                  // offset 0xD10, size 0x4
    s32 m_s32OldLinkCount;                 // offset 0xD14, size 0x4
    s32* m_ps32PathPoint;                  // offset 0xD18, size 0x4
    s32 m_s32AttackStartFrame;             // offset 0xD1C, size 0x4
    u16 m_u16PathCount;                    // offset 0xD20, size 0x2
    u8 m_u8StartFlag;                      // offset 0xD22, size 0x1
    s8 m_as8RankCount[7];                  // offset 0xD23, size 0x7
    u8 m_u8PlayerType;                     // offset 0xD2A, size 0x1
    u8 m_u8TargetType;                     // offset 0xD2B, size 0x1
    uMissionJudge32 m_uJudge;              // offset 0xD2C, size 0x4
    uMissionCount32 m_uCount;              // offset 0xD30, size 0x4
    u32 m_u32BestScore;                    // offset 0xD34, size 0x4
    u32 m_u32BestRank;                     // offset 0xD38, size 0x4
};

#endif // MISSIONRACE_HPP
