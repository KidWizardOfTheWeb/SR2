#ifndef COMAI_HPP
#define COMAI_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/CharaData.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Path/PathPoint.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/TrickParam.hpp"

class clsPlayerTask;

// total size: 0x4
struct stcTimePack {
    u8 u8Minutes; // offset 0x0, size 0x1
    u8 u8Sec;     // offset 0x1, size 0x1
    u16 u16MSec;  // offset 0x2, size 0x2
};

enum enmRunMode {
    COM_RUN_MODE_HIGH = 0,
    COM_RUN_MODE_NORMAL = 1,
    COM_RUN_MODE_LOW = 2,
};

enum enmComMode {
    COM_AI_MODE_PRECE = 0,
    COM_AI_MODE_PULLOUT = 1,
    COM_AI_MODE_KEEP = 2,
    COM_AI_MODE_DINGDONG = 3,
    COM_AI_MODE_CORRECTION = 4,
    MAX_COM_AI_MODE = 5,
    MAX_COM_AI_MODE_LEAD = 2,
};

enum enmComDis {
    COM_DIS_NON = 0,
    COM_DIS_20 = 1,
    COM_DIS_40 = 2,
    COM_DIS_60 = 3,
    COM_DIS_80 = 4,
    MAX_COM_DIS = 4,
};

enum enmRunDelay {
    COM_RUN_STORY_NORMAL = 0,
    COM_RUN_STORY_LEADER = 1,
    COM_RUN_STORY_PLAYER = 2,
};

enum enmDingMode {
    COM_DING_MODE_TIME_SET = 0,
    COM_DING_MODE_SPEED_UP = 1,
    COM_DING_MODE_SPEED_DOWN = 2,
    COM_DING_MODE_NON = 3,
};

enum enmCorrectMode {
    COM_CORRECT_MODE_HIGH_SPEED = 0,
    COM_CORRECT_MODE_LOW_SPEED = 1,
    COM_CORRECT_MODE_END = 2,
};

// total size: 0x110
class clsComAI {
public:
    clsPlayerTask* m_pcPlayer;                // offset 0x4, size 0x4
    NNS_VECTORFAST m_sNextDestination;        // offset 0x10, size 0x10
    clsRetPath m_cRetComPath;                 // offset 0x20, size 0x20
    enmActionType m_eOldActionType;           // offset 0x40, size 0x4
    enmKickerRankZone m_eNextTrickZone;       // offset 0x44, size 0x4
    enmRunMode m_eRunMode;                    // offset 0x48, size 0x4
    u32 m_u32AdjustStates;                    // offset 0x4C, size 0x4
    f32 m_f32CourseAngle;                     // offset 0x50, size 0x4
    u16 m_u16OldLineNo;                       // offset 0x54, size 0x2
    u16 m_u16ComExecMode;                     // offset 0x56, size 0x2
    u16 m_u16NextLine;                        // offset 0x58, size 0x2
    u8 m_u8PlannedRank;                       // offset 0x5A, size 0x1
    u8 m_bWallJumpFlag;                       // offset 0x5B, size 0x1
    s32 m_s32GameMode;                        // offset 0x5C, size 0x4
    enmComType m_eComTypeAI;                  // offset 0x60, size 0x4
    enmComMode m_eComModeAI;                  // offset 0x64, size 0x4
    enmComDis m_eComDisAI;                    // offset 0x68, size 0x4
    u32 m_u32NowTime;                         // offset 0x6C, size 0x4
    u32 m_u32OldTime;                         // offset 0x70, size 0x4
    u32 m_u32RandAI;                          // offset 0x74, size 0x4
    s32 m_s32AddSub;                          // offset 0x78, size 0x4
    s32 m_s32RaceAddSub;                      // offset 0x7C, size 0x4
    enmRunDelay m_eDelayMode;                 // offset 0x80, size 0x4
    enmDingMode m_eDingMode;                  // offset 0x84, size 0x4
    enmDingMode m_eOldDingMode;               // offset 0x88, size 0x4
    enmCorrectMode m_eCorrectMode;            // offset 0x8C, size 0x4
    u32 m_u32ShortTime;                       // offset 0x90, size 0x4
    u32 m_u32LapTimeFreeCnt;                  // offset 0x94, size 0x4
    u32 m_u32LapTimeFreeFrm;                  // offset 0x98, size 0x4
    s32 m_s32AddSubFree;                      // offset 0x9C, size 0x4
    s32 m_s32FreeLapFlag;                     // offset 0xA0, size 0x4
    f32 m_f32OldRankDepth;                    // offset 0xA4, size 0x4
    s32 m_s32SelectAi;                        // offset 0xA8, size 0x4
    f32 m_f32MaxSpeed;                        // offset 0xAC, size 0x4
    f32 m_f32MinSpeed;                        // offset 0xB0, size 0x4
    f32 m_f32CollisionCheckFrame;             // offset 0xB4, size 0x4
    NNS_VECTORFAST m_sOldPosVec;              // offset 0xC0, size 0x10
    u8 m_u8OldPlannedRank;                    // offset 0xD0, size 0x1
    u32 m_u32StoryBestLap;                    // offset 0xD4, size 0x4
    u32 m_u32FreeBestLap;                     // offset 0xD8, size 0x4
    NNS_VECTORFAST* m_psTrickGCtrlConnectPos; // offset 0xDC, size 0x4
    s32 m_s32TrickGCtrlTrickFrame;            // offset 0xE0, size 0x4
    u8 m_bIsTrickGCtrlTry;                    // offset 0xE4, size 0x1
    s8 m_s8BunkiFlag;                         // offset 0xE5, size 0x1
    s32 m_s32HitCount;                        // offset 0xE8, size 0x4
    f32 m_f32BunkiFrame;                      // offset 0xEC, size 0x4
    f32 m_f32BunkiLimitFrame;                 // offset 0xF0, size 0x4
    s32 m_s32WallShortCutFlag;                // offset 0xF4, size 0x4
    f32 m_f32WallShortCutTime;                // offset 0xF8, size 0x4
    stcTimePack m_sRoundTime;                 // offset 0xFC, size 0x4
    stcTimePack m_sRoundOldTime;              // offset 0x100, size 0x4
    stcTimePack m_sDebugCheckTime;            // offset 0x104, size 0x4
    stcTimePack m_sDebugRoundTime;            // offset 0x108, size 0x4
    stcTimePack m_sDebugDelayTime;            // offset 0x10C, size 0x4

    // --- vtable ---
    virtual ~clsComAI();
    virtual u8 controlGoalTime(s8 s8Lever);
    virtual u8 controlRoundTime();
    virtual s8 execPrece(s8 s8Reserve);
    virtual s8 execPullOut(s8 s8Reserve);
    virtual s8 execKeep(s8 s8Reserve);
    virtual s8 execDingDong(s8 s8Reserve);
    virtual s8 execCorrection(s8 s8Param1);

    // --- non-weak non-virtual methods ---
    u8 updateAILine(u32 u32DisableRoot);
    void EstimatePath();
    void calcPlayerDirectionToPoint(const f32 (*psBaseMtx)[4][4],
                                    const NNS_VECTORFAST* psEndPoint,
                                    f32* pf32AngleDiffX,
                                    f32* pf32AngleDiffY);
    void selectLine(clsRetPath& rcRetPath, u16 u16PlannedLine);
    f32 getEnableLineAttributeRate(u16 u16LineAttr);
    void updateNextTrickRank();
    void DivergenceSt13();
    void updateTime();
    void setPlannedRank(u8 u8Rank);
    void clearData();

    // --- statics ---
    static u32 t_ou32ComGrindAccessWaitFirst;
    static u32 t_ou32ComGrindAccessWaitDefault;
    static u32 t_ou32ComGDiveTryAgpVal;
    static u32 t_ou32ComGCtrlMaxRestFrame;
    static u32 t_ou32ComGCtrlHighRestFrame;
    static u32 t_ou32ComGCtrlMinRestFrame;
    static u32 t_ou32ComWallRunTrickFrame;
    static u32 t_ou32ComWallRunGCtrlMaxFrame;
    static u32 t_ou32ComWheelDriftMaxFrame;
    static f32 t_of32ComCollisionCheckFrame;
    static f32 t_of32ComPositionCheck;
    static f32 t_of32St6SubMainLength;
    static f32 t_of32St13SubMainLength;
    // t_pfExecAI is a function pointer table (size 60 = 15 entries)
    // exact type unclear from DWARF, declared as void* array
    static void* t_pfExecAI[];
};

#endif // COMAI_HPP
