#ifndef BASERACE_HPP
#define BASERACE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/Game.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/GameData.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOClock.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/Pause/BaseRacePause.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOStl.hpp"
#include "usr/local/sega/nn/src/Camera/nncamera.h"

// Forward declarations
class clsCamCtrl;
class clsReInitGraphics_Task;
class clsGravityGimmickManager;
class clsStageName2D_Task;
class clsBlur_Task;
struct stcBinDataDetail;

// total size: 0x18
class clsGmkManager : public clsSingleton<clsGmkManager> {
public:
    virtual ~clsGmkManager() {}

    clsOOList m_tdpcGimmick; // offset 0x4, size 0x14
};

namespace nspChara {
enum enmCharaType {
    CHARA_SONIC = 0,
    CHARA_TAILS = 1,
    CHARA_KNUCKLES = 2,
    CHARA_AMY = 3,
    CHARA_JET = 4,
    CHARA_STORM = 5,
    CHARA_WAVE = 6,
    CHARA_EGGMAN = 7,
    CHARA_CREAM = 8,
    CHARA_ROUGE = 9,
    CHARA_SHADOW = 10,
    CHARA_BLAZE = 11,
    CHARA_SILVER = 12,
    CHARA_NIGHTS = 13,
    CHARA_SAMBA = 14,
    CHARA_BILLY = 15,
    CHARA_SCR_GP = 16,
    CHARA_SCR_HD = 17,
    CHARA_SUPER_SONIC = 18,
    MAX_CHARA_NUM = 19,
};
} // namespace nspChara

// total size: 0xC
struct stcRankCheck {
    s16 s16PlayerNo;  // offset 0x0, size 0x2
    s16 s16LapNo;     // offset 0x2, size 0x2
    s32 s32TotalMSec; // offset 0x4, size 0x4
    f32 f32RankPoint; // offset 0x8, size 0x4
};

// total size: 0x704
class clsResidenceEffect {
public:
    _NNS_TEXLIST* m_psResidence_TexList;                 // offset 0x0, size 0x4
    clsModelType_OB_TX_MO_MA m_cGravity_Model;           // offset 0x4, size 0x20
    clsModelType_OB_TX_MO_MA m_cGravityEmpty_Model;      // offset 0x24, size 0x20
    clsModelType_OB_TX_MO_MA m_cGravityLocal_Model;      // offset 0x44, size 0x20
    clsModelType_OB_TX_MO_MA_MF m_acGravity_Model2[4];   // offset 0x64, size 0xD0
    clsModelType_OB_TX_MO_MA_MF m_acGravity_Model3[4];   // offset 0x134, size 0xD0
    clsModelType_OB_TX_MO_MA m_cLandig_Model;            // offset 0x204, size 0x20
    clsModelType_OB_TX_MO_MA m_cCurve_Model;             // offset 0x224, size 0x20
    clsModelType_OB_TX_MO_MA m_cCrash_Model;             // offset 0x244, size 0x20
    clsModelType_OB_TX_MO_MA m_cDash_Model;              // offset 0x264, size 0x20
    clsModelType_OB_TX_MO_MA m_cGetAGP_Model;            // offset 0x284, size 0x20
    clsModelType_OB_TX_MO_MA m_cCrashCrara_Model;        // offset 0x2A4, size 0x20
    clsModelType_OB_TX_MO_MA m_cBadTrack_Model;          // offset 0x2C4, size 0x20
    clsModelType_OB_TX_MO_MA m_cGearChenge01_Model;      // offset 0x2E4, size 0x20
    clsModelType_OB_TX_MO_MA m_cGearChenge02_Model;      // offset 0x304, size 0x20
    clsModelType_OB_TX_MO_MA m_cGearChenge03_Model;      // offset 0x324, size 0x20
    clsModelType_OB_TX_MO_MA m_cGearChengeRt_Model;      // offset 0x344, size 0x20
    clsModelType_OB_TX_MO_MA m_cFalseStart00_Model;      // offset 0x364, size 0x20
    clsModelType_OB_TX_MO_MA m_cFalseStart01_Model;      // offset 0x384, size 0x20
    clsModelType_OB_TX_MO_MA m_cGravityCtrl00_Model;     // offset 0x3A4, size 0x20
    clsModelType_OB_TX_MO_MA m_cGravityCtrl01_Model;     // offset 0x3C4, size 0x20
    clsModelType_OB_TX_MO_MA m_cGravityCtrl02_Model;     // offset 0x3E4, size 0x20
    clsModelType_OB_TX_MO_MA m_cPowerHit_Model;          // offset 0x404, size 0x20
    clsModelType_OB_TX_MO_MA m_cTrickXFlashLine_Model;   // offset 0x424, size 0x20
    clsModelType_OB_TX_MO_MA m_cTrickXRing_Model;        // offset 0x444, size 0x20
    clsModelType_OB_TX_MO_MA m_cGearTypeChange_Model;    // offset 0x464, size 0x20
    clsModelType_OB_TX_MO_MA m_cRoboCurv_Model;          // offset 0x484, size 0x20
    clsModelType_OB_TX_MO_MA m_cSidaRide_Model;          // offset 0x4A4, size 0x20
    clsModelType_OB_TX_MO_MA m_cLandingWaterTrick_Model; // offset 0x4C4, size 0x20
    clsModelType_OB_TX_MO_MA m_cLandingWaterJump_Model;  // offset 0x4E4, size 0x20
    clsModelType_OB_TX_MO_MA m_cMeteoriteFall_Model;     // offset 0x504, size 0x20
    clsModelType_OB_TX_MO_MA m_cDiveEffect_Model;        // offset 0x524, size 0x20
    clsModelType_OB_TX_MO_MA m_cMeteoExplode_Model;      // offset 0x544, size 0x20
    clsModelType_OB_TX_MO_MA m_cBossCrush_Model;         // offset 0x564, size 0x20
    clsModelType_OB_TX_MO_MA m_cBossCrush2_Model;        // offset 0x584, size 0x20
    clsModelType_OB_TX_MO_MA m_cBossAppear_Model;        // offset 0x5A4, size 0x20
    clsModelType_OB_TX_MO_MA m_cBornRing_Model;          // offset 0x5C4, size 0x20
    clsModelType_OB_TX_MO_MA m_cSt07PTObj_Model;         // offset 0x5E4, size 0x20
    clsModelType_OB_TX_MO_MA m_cSt07Floor_Model;         // offset 0x604, size 0x20
    clsModelType_OB_TX_MO_MA m_cSt07FloorG_Model;        // offset 0x624, size 0x20
    clsModelType_OB_TX_MO_MA m_cBornSpring_Model;        // offset 0x644, size 0x20
    clsModelType_OB_TX_MO_MA m_cBornItemBox_Model;       // offset 0x664, size 0x20
    clsModelType_OB_TX_MO_MA m_cBornDPanel_Model;        // offset 0x684, size 0x20
    clsModelType_OB_TX_MO_MA m_cSt14FanL_Model;          // offset 0x6A4, size 0x20
    clsModelType_OB_TX_MO_MA m_cSt14FanS_Model;          // offset 0x6C4, size 0x20
    clsModelType_OB_TX_MO_MA m_cSt07FloorHole_Model;     // offset 0x6E4, size 0x20

    clsModelType_OB_TX_MO_MA* getCrashModel() { return &m_cCrash_Model; }
    clsModelType_OB_TX_MO_MA* getLandingModel() { return &m_cLandig_Model; }
    clsModelType_OB_TX_MO_MA* getLandingWaterJumpModel() { return &m_cLandingWaterJump_Model; }
    clsModelType_OB_TX_MO_MA* getLandingWaterTrickModel() { return &m_cLandingWaterTrick_Model; }
    void copyMorphMotObj(clsModelType_OB_TX_MO_MA_MF* pcParam1, clsPack::stcBinInfo* psParam2) {}
    clsModelType_OB_TX_MO_MA* getDashModel() { return &m_cDash_Model; }
    clsModelType_OB_TX_MO_MA* getBossAppearModel() { return &m_cBossAppear_Model; }
    clsModelType_OB_TX_MO_MA* getRoboCurvModel() { return &m_cRoboCurv_Model; }
};

// total size: 0x34
struct stcMotionCam1 {
    NNS_VECTOR sAddPos;       // offset 0x0, size 0xC
    NNS_QUATERNION sAddQuat;  // offset 0xC, size 0x10
    NNS_CAMERAPTR* psBaseCam; // offset 0x1C, size 0x4
    NNS_MOTION* psCamMotion;  // offset 0x20, size 0x4
    f32 f32StartFrame;        // offset 0x24, size 0x4
    f32 f32PlayFrame;         // offset 0x28, size 0x4
    f32 f32EndFrame;          // offset 0x2C, size 0x4
    f32 f32SpeedRate;         // offset 0x30, size 0x4
};

enum enmRestartMode {
    RESTART_REPLAY = 1,
};

enum enmDraw2DAttr {
    DRAW2DATTR_RANKING = 1,
    DRAW2DATTR_RECORD = 2,
    DRAW2DATTR_LAP = 4,
    DRAW2DATTR_GEAR = 8,
    DRAW2DATTR_RING = 16,
    DRAW2DATTR_MAP_BG = 32,
    DRAW2DATTR_MAP_MAP = 64,
    DRAW2DATTR_START_MAP = 128,
    DRAW2DATTR_BUTTON_HELP = 256,
    DRAW2DATTR_ATENTIONATTACK = 512,
    DRAW2DATTR_GEAR_EFFECT_NEXT = 1024,
    DRAW2DATTR_GEAR_EFFECT_SET = 2048,
    DRAW2DATTR_GEAR_EFFECT = 3072,
    DRAW2DATTR_ALL = 4095,
};

enum enmJudgmentAttr {
    JUDGMENTATTR_STATUS_REVERSE = 1,
    JUDGMENTATTR_STATUS_LIMIT_DIVE = 2,
    JUDGMENTATTR_RESTART = 4,
    JUDGMENTATTR_RESET_RING = 8,
    JUDGMENTATTR_CATAPULT_COUNT = 16,
    JUDGMENTATTR_RING_REVIVAL = 32,
    JUDGMENTATTR_GEAR_RIDE = 64,
    JUDGMENTATTR_ALL = 63,
};

enum enmStoryProductionMode {
    PRODUCTION_INIT = 0,
    PRODUCTION_SETMOTION = 1,
    PRODUCTION_SETEFFECT = 2,
    PRODUCTION_DELETENAME = 3,
    PRODUCTION_PROGRESS = 4,
    PRODUCTION_DELETEEFFECT = 5,
    PRODUCTION_RUN = 6,
    PRODUCTION_END = 7,
};

enum enmRaceInfo {
    RACE_INFO___NON = 0,
    RACE_INFO___INIT = 1,
    RACE_INFO___START = 2,
    RACE_INFO___RESTART = 3,
    RACE_INFO___MOVE_CAMERA = 4,
    RACE_INFO___COUNT_DOWN_WAIT = 5,
    RACE_INFO___COUNT_DOWN = 6,
    RACE_INFO___START_GATE_CHECK = 7,
    RACE_INFO___RACE = 8,
    RACE_INFO___GOAL = 9,
    RACE_INFO___RESULT_MENU = 10,
    RACE_INFO___RESULT_MENU_SELECT = 11,
};

enum enmCamMotionNo {
    CAMMOTION_START_01 = 0,
    CAMMOTION_START_02 = 1,
    CAMMOTION_START_CHARA_01 = 2,
    CAMMOTION_START_CHARA_02 = 3,
    CAMMOTION_START_MAX_NUM = 4,
    CAMMOTION_MAX_NUM = 4,
};

// total size: 0xCB0
class clsBaseRace_Task : public clsTask {
public:
    enum enmCamMotionNo {
        CAMMOTION_START_01 = 0,
        CAMMOTION_START_02 = 1,
        CAMMOTION_START_CHARA_01 = 2,
        CAMMOTION_START_CHARA_02 = 3,
        CAMMOTION_START_MAX_NUM = 4,
        CAMMOTION_MAX_NUM = 4,
    };
    clsResidenceEffect cResidenceEffect;                   // offset 0x54, size 0x704
    stcSendAdv m_sSendAdv[8];                              // offset 0x758, size 0x20
    void* m_pvStagePackBuffer;                             // offset 0x778, size 0x4
    s32 m_s32PlayerNum;                                    // offset 0x77C, size 0x4
    s32 m_s32UserNum;                                      // offset 0x780, size 0x4
    s32 m_s32ComNum;                                       // offset 0x784, size 0x4
    s32 m_s32ViewNum;                                      // offset 0x788, size 0x4
    s32 m_s32LapNum;                                       // offset 0x78C, size 0x4
    void* m_pavCharaPackBuffer[8];                         // offset 0x790, size 0x20
    void* m_pvUnion2DPackBuffer;                           // offset 0x7B0, size 0x4
    void* m_pvStage2DPackBuffer;                           // offset 0x7B4, size 0x4
    clsReInitGraphics_Task* m_pcReInitGraphics_Task;       // offset 0x7B8, size 0x4
    u32 m_u32LoadCnt;                                      // offset 0x7BC, size 0x4
    u32 m_u32GearLoadCnt;                                  // offset 0x7C0, size 0x4
    u32 m_u32CharaLoadNum;                                 // offset 0x7C4, size 0x4
    u32 m_au32LoadedCharaIndex[19];                        // offset 0x7C8, size 0x4C
    clsOOClock m_cClock_CountDown;                         // offset 0x814, size 0x24
    clsOOClock m_cClock_RaceTime;                          // offset 0x838, size 0x24
    void** m_appvMotLoadBufAddr[64];                       // offset 0x85C, size 0x100
    enmRestartMode m_eRestartMode;                         // offset 0x95C, size 0x4
    enmDraw2DAttr m_eDraw2DAttr;                           // offset 0x960, size 0x4
    enmJudgmentAttr m_eJudgmentAttr;                       // offset 0x964, size 0x4
    s32 m_s32StageNo;                                      // offset 0x968, size 0x4
    u32 m_u32GameRandSeed;                                 // offset 0x96C, size 0x4
    clsGmkManager* m_pcGmkManager;                         // offset 0x970, size 0x4
    clsGravityGimmickManager* m_pcGravityGimmickManager;   // offset 0x974, size 0x4
    NNS_CAMERAPTR* m_apsBaseCam[4];                        // offset 0x978, size 0x10
    NNS_MOTION* m_apsCamMotion[4];                         // offset 0x988, size 0x10
    s32 m_s32StartCamCnt;                                  // offset 0x998, size 0x4
    f32 m_f32StartVoiceFrame;                              // offset 0x99C, size 0x4
    clsCamCtrl* m_pcStartCamCtrl;                          // offset 0x9A0, size 0x4
    stcMotionCam1 m_sStartCamData;                         // offset 0x9A4, size 0x34
    clsStageName2D_Task* m_psStageNameTask;                // offset 0x9D8, size 0x4
    nspGame::stcMotionTable* m_apsUnionMotionTable[8];     // offset 0x9DC, size 0x20
    nspGame::stcMotionTable* m_apsCharaMotionTable[19][8]; // offset 0x9FC, size 0x260
    s32 m_s32GoalCounter;                                  // offset 0xC5C, size 0x4
    f32 m_f32SkillAgpPoint;                                // offset 0xC60, size 0x4
    s8 m_s8OmoteUraStageNo;                                // offset 0xC64, size 0x1
    u8 m_u8MotLoadNum;                                     // offset 0xC65, size 0x1
    u8 m_bUra;                                             // offset 0xC66, size 0x1
    u8 m_bIsSetComPlannedRank;                             // offset 0xC67, size 0x1
    u8 m_abIsPlayerKeyValid[8];                            // offset 0xC68, size 0x8
    u8 m_bStartCamera;                                     // offset 0xC70, size 0x1
    u8 m_bEnableUpdateBurnOutEffect;                       // offset 0xC71, size 0x1
    u8 m_bDisableBlur;                                     // offset 0xC72, size 0x1
    u8 m_bStoryStartEvent;                                 // offset 0xC73, size 0x1
    u8 m_u8LoadSe_Mode;                                    // offset 0xC74, size 0x1
    s8 m_s8LoadSe_PortNo;                                  // offset 0xC75, size 0x1
    s8 m_s8LoadSe_PlayerNo;                                // offset 0xC76, size 0x1
    f32 m_f32FlyAgpBonusPoint;                             // offset 0xC78, size 0x4
    f32 m_f32SpeedAgpBonusPoint;                           // offset 0xC7C, size 0x4
    f32 m_f32PowerAgpBonusPoint;                           // offset 0xC80, size 0x4
    clsTask* m_pcEffectWrist_Task;                         // offset 0xC84, size 0x4
    clsTask* m_pcEffectLine_Task;                          // offset 0xC88, size 0x4
    clsTask* m_pcEffectCharge_Task;                        // offset 0xC8C, size 0x4
    enmStoryProductionMode m_eProductionMode;              // offset 0xC90, size 0x4
    u8 m_bSeWalkFlag;                                      // offset 0xC94, size 0x1
    clsBlur_Task* m_pcBlurTask;                            // offset 0xC98, size 0x4
    s32 m_eRacePauseRet;                                   // offset 0xC9C, size 0x4
    clsTask* m_psStartCountDownTask;                       // offset 0xCA0, size 0x4
    clsTask* m_psResult2DTask;                             // offset 0xCA4, size 0x4
    enmRaceInfo m_eRaceInfo;                               // offset 0xCA8, size 0x4
    enmRaceInfo m_eRaceInfo_Old;                           // offset 0xCAC, size 0x4

    static c8* m_toac8StageName_Debug[];

    clsBaseRace_Task(s32 s32StageNoI,
                     s32 s32PlayerNumI,
                     s32 s32UserNumI,
                     s32 s32ViewNumI,
                     s32 s32LapNumI,
                     const stcSendAdv* opsSendAdvI,
                     void** ppvMapBufferI,
                     enmMode eModeI,
                     s32 s32LoadNo);
    virtual ~clsBaseRace_Task();
    virtual void execute();
    // [4] clsTask::draw() inherited
    // [5-11] clsOOTask/clsTask slots inherited
    virtual void endDemoSetting();
    virtual u8 isStartDash() const { return 1; }
    virtual u32 getStartTimeMilliSec() const { return 0; }
    virtual void init();
    virtual void start();
    virtual void updateRanking();
    virtual u8 packMap();
    virtual u8 packEtc();
    virtual u8 checkGoalPlayer();
    virtual void settingPlayer();
    virtual void restart();
    virtual void initStartCamMotion();
    virtual void endStartCamMotion();
    virtual void checkPause(s32 bOnI);
    virtual void checkPauseResult(s32 bOnI);
    virtual void setPauseScreen(s32 s32PushPausePadNo,
                                clsBaseRacePause_Task::enmPadConnectDraw enConnectDraw);
    virtual void setPauseReslutScreen(s32 s32PushPausePadNo);
    virtual void addReadChara(
        oostd::clsOOSet<u32, std::less<u32>, oostd::clsOOStlAllocator<u32> >* pcParam1);
    virtual void addReadGear(
        oostd::clsOOSet<u32, std::less<u32>, oostd::clsOOStlAllocator<u32> >* pcParam1,
        u32* pu32Param2);
    virtual void addReadCharaMotion(
        std::vector<const clsGameMgr::stcSendAdv*, std::allocator<const clsGameMgr::stcSendAdv*> >*
            pcParam1);
    virtual void execGoal();
    virtual void setBestTime();
    virtual void selectedPauseMenu_RET___RESTART();
    virtual void selectedPauseMenu_RET___EXIT();
    virtual void selectedPauseMenu_RET___CANCEL();
    virtual void selectedPauseMenu_RET___ADD_EXT() {}
    virtual void setFreeRaceUnlock();
    virtual void init_PS2() {}
    virtual void start_PS2() {}
    virtual void Main() {}
    virtual void requestReadEtc();

    void setStoryUnlock();
    void setComPlannedRank();
    void setGoalComPlayer();
    u8 updateStartCamMotion();
    void setPlayerStartCamData(u32 u32PlayerNum);
    void setStartCamMotion(clsBaseRace_Task::enmCamMotionNo enCamMotionNo,
                           const NNS_VECTORFAST* posAddPos,
                           const NNS_QUATERNION* posAddQuat);
    void copyCharaMotionTable(nspChara::enmCharaType eCharaType,
                              nspGame::stcMotionTable* (&rapsDstChrTable)[8]);
    s8 chkPadConnect(u32* pu32PadNo);
    void setSendAdv(const stcSendAdv* opsSendAdvI);
    void setRaceTime(u32 p1, s32 p2, s32 p3, s32 p4, s32 p5, s32 p6, s32 p7);
    u8 countDown();
    u8 setSeData();
    u8 packMotion();
    void requestReadCharaMotion();
    void requestReadGear();
    void requestReadChara();
    void LoadStageData(s32 s32LoadNo);

    clsReInitGraphics_Task* getReInitGraphics_Task() const { return m_pcReInitGraphics_Task; }
    s32 getStageNo() const { return m_s32StageNo; }
    enmJudgmentAttr getJudgmentAttr() const { return m_eJudgmentAttr; }
    s32 getUserNum() const { return m_s32UserNum; }
    s32 getPlayerNum() const { return m_s32PlayerNum; }
    s8 getOmoteUraStageNo() const { return m_s8OmoteUraStageNo; }
    bool isUra() const { return m_bUra; }
    clsOOClock* getClock_CountDown() { return &m_cClock_CountDown; }
    s32 getCountDownMaxSecond() { return 5; }
    enmRaceInfo getRaceInfo() const { return m_eRaceInfo; }
    s32 getViewNum() const { return m_s32ViewNum; }
};

#endif // BASERACE_HPP
