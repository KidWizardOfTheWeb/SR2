#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/GravityAction/GravityActionManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Performance.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/Gear.hpp"
#include "usr/local/sega/nn/NNS.hpp"

class clsCharacter;
class clsPlayerPhysic;
class clsPrfm;
class clsGearCtrl;
class clsLap;
class clsObject;
class clsTask;
class clsBackLineEffectTask;
class clsVaporTrail_Task;
class clsWeather_Task;
class clsBaseEffect_Task;
class clsDashPanel_Obj;
class clsEggConfetti;
class clsNightsAtkEffect;
class clsModelType_OB_TX;
class clsPlayerTask;
class clsPlaySe_2D;
class clsPlayerKey;
class clsComKey;
class clsUserKey;
class clsPlayerDebug;
class clsPlayerMotion;
class stcInfo;
class clsThroughCollision;
class hkContactPoint;
class clsModelType_OB_TX_MO_MA;

namespace clsPack {
struct stcSetDataDetail;
}

enum enmPlayerType {
    PLAYER_TYPE__NORMAL = 0,
    PLAYER_TYPE__GHOST  = 1,
};

enum enmStatus {
    STATUS_NULL          = 0,
    STATUS_END           = 1,
    STATUS_STOP          = 2,
    STATUS_BLEND         = 4,
    STATUS_UNLOOP        = 8,
    STATUS_LINK_ONE      = 16,
    STATUS_LINK_SYNC     = 32,
    STATUS_NEXT_UNLOOP   = 64,
    STATUS_NEXT_STOP     = 128,
};

enum enmSystemFlag {
    SYSTEM_FLAG__CLEAR = 0,
    SYSTEM_FLAG__OBJ_PORTAL_FORWARD = 1,
};

class clsFlag {
public:
    enum enmSystemFlag m_tData; // offset 0x0, size 0x4
};

enum enmNo {
    PLAYER_00 = 0,
    PLAYER_01 = 1,
    PLAYER_02 = 2,
    PLAYER_03 = 3,
    PLAYER_04 = 4,
    PLAYER_05 = 5,
    PLAYER_06 = 6,
    PLAYER_07 = 7,
    MAX_PLAYER = 8,
    MAX_COM = 7,
};

enum enmFlag {
    FLAG_CLEAR = 0,
    FLAG_UPDATE_POSTURAL_QUAT = 1,
    FLAG_UPDATE_BEHAVIOR = 2,
    FLAG_FACE_ROTATE = 4,
    FLAG_SLOPE_SLOWDOWN = 8,
    FLAG_CENTRIFUGAL_FORCE = 16,
    FLAG_REVERSE = 32,
    FLAG_NON_MOVE = 64,
    FLAG_ALL_TIME_ATTACK = 128,
    FLAG_LOSE = 256,
    FLAG_INIT = 59,
};

enum enmActionType {
    ACTION_TYPE_NULL = 0,
    ACTION_TYPE_DAMAGE00 = 1,
    ACTION_TYPE_DAMAGE01 = 2,
    ACTION_TYPE_DEMO = 3,
    ACTION_TYPE_WALK_WAIT = 4,
    ACTION_TYPE_WALK_RUN = 5,
    ACTION_TYPE_WALK_BACK = 6,
    ACTION_TYPE_WALK_BRAKE = 7,
    ACTION_TYPE_WALK_FLIGHT = 8,
    ACTION_TYPE_WALK_SPRING = 9,
    ACTION_TYPE_INERTIA = 10,
    ACTION_TYPE_RUN = 11,
    ACTION_TYPE_BRAKE = 12,
    ACTION_TYPE_FLIGHT = 13,
    ACTION_TYPE_JUMP = 14,
    ACTION_TYPE_TRICK = 15,
    ACTION_TYPE_PATH = 16,
    ACTION_TYPE_ATTACK = 17,
    ACTION_TYPE_RAIL = 18,
    ACTION_TYPE_FLY = 19,
    ACTION_TYPE_POWER = 20,
    ACTION_TYPE_GDIVE = 21,
    ACTION_TYPE_GDIVE_AUTO = 22,
    ACTION_TYPE_GCTRL_SLIDE = 23,
    ACTION_TYPE_GCTRL_TRICK = 24,
    ACTION_TYPE_GCTRL_FLIGHT = 25,
    ACTION_TYPE_DIR_REGULATE_RUN = 26,
    ACTION_TYPE_TRANSLATION_MOVE_PATH = 27,
    ACTION_TYPE_WHEELDRIFT = 28,
    ACTION_TYPE_AUTOWALLRUN = 29,
    ACTION_TYPE_FALSE_START = 30,
    ACTION_TYPE_RESTART = 31,
    ACTION_TYPE_ATTACKDAMAGE = 32,
    ACTION_TYPE_BOOST = 33,
    ACTION_TYPE_MAX = 34,
    ACTION_TYPE_ = 35,
};

enum enmMoveFlag {
    MOVE_FLAG_NULL = 0,
    MOVE_FLAG_SPEED = 1,
    MOVE_FLAG_GRAVITY = 2,
    MOVE_FLAG_JUMP = 4,
    MOVE_FLAG_VECTOR = 8,
    MOVE_FLAG_PATH = 16,
    MOVE_FLAG_SURFACE_ADJUST = 32,
    DEFAULT_FLAG = 47,
};

enum enmLinkType {
    LINK_TYPE_NULL = 0,
    LINK_TYPE_SPEED = 1,
    LINK_TYPE_FLY = 2,
    LINK_TYPE_POWER = 3,
};

class clsOOList {
public:
    unsigned int m_u32Data[5]; // size 0x14
};

enum enmAttackLR {
    TARGET_LEFT = 0,
    TARGET_RIGHT = 1,
};

enum enmComType {
    COM_AI_TYPE_LEADER = 0,
    COM_AI_TYPE_NORMAL = 1,
    MAX_COM_AI_TYPE = 2,
};

enum enPlayerCtrlType {
    CTRL_TYPE_1P = 0,
    CTRL_TYPE_2P = 1,
    CTRL_TYPE_3P = 2,
    CTRL_TYPE_4P = 3,
    CTRL_TYPE_COM = 4,
    CTRL_TYPE_REPLAY = 5,
    CTRL_TYPE_GHOST = 6,
};

class stcRateTime {
public:
    signed int s32Sec; // offset 0x0, size 0x4
    signed int s32PassageSec; // offset 0x4, size 0x4
    float f32MSec; // offset 0x8, size 0x4
    float f32PassageMSec; // offset 0xC, size 0x4
};

class clsLimitTime {
public:
    class stcRateTime m_sRateTime; // offset 0x0, size 0x10
    float m_f32LimitTime; // offset 0x10, size 0x4
};

class clsCharaVoice {
public:
    class clsPlayerTask * m_pcPlayer; // offset 0x4, size 0x4
    float m_f32VoiceDelayFrameRunPast; // offset 0x8, size 0x4
    float m_f32VoiceDelayFrameAttack; // offset 0xC, size 0x4
};

class stcSpeedPath {
public:
    signed short s16MaxSpeed; // offset 0x0, size 0x2
    signed short s16MinSpeed; // offset 0x2, size 0x2
    signed short s16Type; // offset 0x4, size 0x2
    signed short as16Reserve[5]; // offset 0x6, size 0xA
}; // total size: 0x10

class stcGravityPath {
public:
    signed short s16MaxSpeed; // offset 0x0, size 0x2
    signed short s16MinSpeed; // offset 0x2, size 0x2
    signed short s16Flag; // offset 0x4, size 0x2
    signed short as16Reserve[5]; // offset 0x6, size 0xA
}; // total size: 0x10

class stcGDivePath {
public:
    signed short s16MaxSpeed; // offset 0x0, size 0x2
    signed short s16MinSpeed; // offset 0x2, size 0x2
    signed short s16Flag; // offset 0x4, size 0x2
    signed short as16Reserve[5]; // offset 0x6, size 0xA
}; // total size: 0x10

class stcLine {
public:
    class NNS_CAPSULE * psCapsule; // offset 0x0, size 0x4
    class NNS_VECTORFAST * psPointVec; // offset 0x4, size 0x4
    class NNS_VECTORFAST * psNormalVec; // offset 0x8, size 0x4
    class NNS_SPHERE sLimitSph; // offset 0xC, size 0x10
    unsigned short u16Num; // offset 0x1C, size 0x2
    unsigned short u16Attr; // offset 0x1E, size 0x2
    union {
        signed char s8Data[16];
        class stcSpeedPath sSpeed;
        class stcGravityPath sGravity;
        class stcGDivePath sGDive;
    } uniData; // offset 0x20, size 0x10
}; // total size: 0x30

class clsPath {
public:
    class NNS_VECTORFAST m_sUpVecFast; // offset 0x0, size 0x10
    class NNS_VECTORFAST m_sDirVecFast; // offset 0x10, size 0x10
    class NNS_VECTORFAST m_sCrossVecFast; // offset 0x20, size 0x10
    class NNS_VECTORFAST m_sMoveVecFast; // offset 0x30, size 0x10
    class stcLine * m_psLine; // offset 0x40, size 0x4
    float m_f32LengthRate; // offset 0x44, size 0x4
    float m_f32Length; // offset 0x48, size 0x4
    float m_f32DistanceLR; // offset 0x4C, size 0x4
    unsigned short m_u16HitBit; // offset 0x50, size 0x2
    unsigned short m_u16PointNo; // offset 0x52, size 0x2
    signed short m_s16PathNo; // offset 0x54, size 0x2
    unsigned short m_u16SearchHitBit; // offset 0x56, size 0x2
}; // total size: 0x60

class clsFlyAction {
public:
    class NNS_QUATERNION m_sFlyQuat; // offset 0x0, size 0x10
    signed int m_A32FlyPitchAngle; // offset 0x10, size 0x4
    signed int m_A32FlyRollAngle; // offset 0x14, size 0x4
    signed short m_s16OldRingNo; // offset 0x18, size 0x2
    signed short m_s16InitType; // offset 0x1A, size 0x2
}; // total size: 0x1C

class clsRetPath {
public:
    unsigned short m_u16LineNo[8]; // offset 0x0, size 0x10
    unsigned short m_u16LineNum; // offset 0x10, size 0x2
    unsigned short m_u16ActiveLineNo; // offset 0x12, size 0x2
    unsigned short m_u16OldLineNo; // offset 0x14, size 0x2
    float m_f32DotPro; // offset 0x18, size 0x4
    float m_f32DotPro_Deg; // offset 0x1C, size 0x4
}; // total size: 0x20

class clsSlipStream {
public:
    class stcData {
    public:
        class NNS_VECTORFAST sPosVecFast; // offset 0x0, size 0x10
        class NNS_VECTORFAST sDirVecFast; // offset 0x10, size 0x10
        float f32Speed; // offset 0x20, size 0x4
        float f32Accele; // offset 0x24, size 0x4
        float f32Reserved[2]; // offset 0x28, size 0x8
    }; // total size: 0x30

    class stcData m_sData[4]; // offset 0x0, size 0xC0
    signed int m_eStatus; // offset 0xC0, size 0x4
    float m_f32UpdateCount; // offset 0xC4, size 0x4
    unsigned int m_u32PointNo; // offset 0xC8, size 0x4
}; // total size: 0xD0

class clsReaction {
public:
    class NNS_VECTORFAST m_sWallVecFast; // offset 0x0, size 0x10
    class clsPlayerTask * m_pcPlayer; // offset 0x10, size 0x4
    class clsPlaySe_2D * m_pcPlaySe2D; // offset 0x14, size 0x4
    float m_f32EffectFrame; // offset 0x18, size 0x4
    float m_f32EffectSubFrame; // offset 0x1C, size 0x4
    signed int m_eWallType; // offset 0x20, size 0x4
    signed int m_eGDiveType; // offset 0x24, size 0x4
    signed char m_s8WallHitCount; // offset 0x28, size 0x1
    unsigned char m_au8ColInfo[0xC]; // offset 0x2C, size 0xC
}; // total size: 0x40

class clsControlMatrix {
public:
    float m_sMtx[4][4]; // offset 0x0, size 0x40
    struct NNS_ROTATE_A32 m_sAutoRotA32; // offset 0x40, size 0xC
    struct NNS_ROTATE_A32 m_sAutoRotRetAddA32; // offset 0x4C, size 0xC
    class NNS_VECTORFAST m_sAutoRotAxisVecFast; // offset 0x60, size 0x10
    class NNS_VECTORFAST m_sVibTrsVecFast; // offset 0x70, size 0x10
    class NNS_VECTORFAST m_sVibTrsSyncVecFast; // offset 0x80, size 0x10
    class NNS_VECTORFAST m_sVibTrsSyncAddVecFast; // offset 0x90, size 0x10
    class NNS_VECTORFAST m_sVibRotVecFast; // offset 0xA0, size 0x10
    class NNS_VECTORFAST m_sVibRotSyncVecFast; // offset 0xB0, size 0x10
    class NNS_VECTORFAST m_sVibRotSyncAddVecFast; // offset 0xC0, size 0x10
    class NNS_VECTORFAST m_sVibRotAxisVecFast; // offset 0xD0, size 0x10
    float m_f32TrsDecayRate; // offset 0xE0, size 0x4
    float m_f32RotDecayRate; // offset 0xE4, size 0x4
    class NNS_VECTORFAST m_sScaleVecFast; // offset 0xF0, size 0x10
    signed int m_eFlag; // offset 0x100, size 0x4
}; // total size: 0x110

class stcInitData {
public:
    class NNS_VECTORFAST sPosVecFast; // offset 0x0, size 0x10
    class NNS_VECTORFAST sUpVecFast; // offset 0x10, size 0x10
    float f32LocalAngleRad; // offset 0x20, size 0x4
    unsigned int u32Padding; // offset 0x24, size 0x4
}; // total size: 0x30

class clsLerpParam {
public:
    float m_f32Target; // offset 0x0, size 0x4
    float m_f32Result; // offset 0x4, size 0x4
    float m_f32Add; // offset 0x8, size 0x4
    float m_f32Frame; // offset 0xC, size 0x4
}; // total size: 0x10

class clsSlerpQuat {
public:
    class NNS_QUATERNION m_sBaseQuat; // offset 0x0, size 0x10
    class NNS_QUATERNION m_sSlerpQuat; // offset 0x10, size 0x10
    class NNS_QUATERNION m_sResultQuat; // offset 0x20, size 0x10
    float m_f32Rate; // offset 0x30, size 0x4
    float m_f32Add; // offset 0x34, size 0x4
    unsigned char m_bIsSlerp; // offset 0x38, size 0x1
}; // total size: 0x3C

class clsPosturalCtrl {
public:
    float m_sMtx[4][4]; // offset 0x0, size 0x40
    class NNS_VECTORFAST m_sDirVecFast; // offset 0x40, size 0x10
    class NNS_QUATERNION m_sQuat; // offset 0x50, size 0x10
    class clsSlerpQuat m_cSurface; // offset 0x60, size 0x3C
    class clsLerpParam m_cRotate; // offset 0x9C, size 0x10
}; // total size: 0xB0

class clsSurface {
public:
    class NNS_QUATERNION m_sQuat; // offset 0x0, size 0x10
    class NNS_VECTORFAST m_sUpVecFast; // offset 0x10, size 0x10
}; // total size: 0x20

class clsGravity {
public:
    float m_sMtx[4][4]; // offset 0x0, size 0x40
    class NNS_VECTORFAST m_sVecFast; // offset 0x40, size 0x10
    class NNS_VECTORFAST m_sUpVecFast; // offset 0x50, size 0x10
    class clsPlayerTask * m_pcPlayer; // offset 0x60, size 0x4
    class clsPath m_cPath; // offset 0x70, size 0x60
    class clsSlerpQuat m_cSlerpQuat; // offset 0xD0, size 0x3C
    float m_f32Speed; // offset 0x10C, size 0x4
    float m_f32Accele; // offset 0x110, size 0x4
    float m_f32FrameRate; // offset 0x114, size 0x4
    signed int m_eFlag; // offset 0x118, size 0x4
    signed int m_eType; // offset 0x11C, size 0x4
    float m_f32ChangeFrame; // offset 0x120, size 0x4
}; // total size: 0x130

class clsObject {
public:
    unsigned int m_u32VTable; // offset 0x0, size 0x4
}; // total size: 0x4

class clsTask {
public:
    unsigned char m_au8TaskData[0x54]; // offset 0x0, size 0x54
}; // total size: 0x54

class stcBingoControl {
public:
    signed char as8Rank[3]; // offset 0x0, size 0x3
    signed char s8RankNo; // offset 0x3, size 0x1
}; // total size: 0x4

class clsBaseTrickAction {
public:
    unsigned int m_u32Dummy;
}; // total size: 0x4

class clsFlipTrickAction : public clsBaseTrickAction {};
class clsSpinTrickAction : public clsBaseTrickAction {};
class clsPipeTrickAction : public clsBaseTrickAction {};
class clsFreeTrickAction : public clsBaseTrickAction {};
class clsWallTrickAction : public clsBaseTrickAction {};
class clsTurbTrickAction : public clsBaseTrickAction {};
class clsPartsTrickAction : public clsFreeTrickAction {};

class clsVerticalTrickAction : public clsBaseTrickAction {
public:
    class NNS_VECTORFAST m_sUpVecFast; // offset 0x10, size 0x10
    float m_f32UpAccele; // offset 0x20, size 0x4
}; // total size: 0x30

class clsTrickParam {
public:
    class NNS_VECTORFAST m_sDirVecFast; // offset 0x10, size 0x10
    class stcBingoControl m_sBingoControl; // offset 0x20, size 0x4
    class clsPlayerTask * m_pcPlayer; // offset 0x24, size 0x4
    void * m_pvTrickMotionData; // offset 0x28, size 0x4
    class stcInfo * m_psColInfo; // offset 0x2C, size 0x4
    class clsRetPath m_cRetCoursePath; // offset 0x30, size 0x20
    float m_f32UpAccele; // offset 0x50, size 0x4
    float m_f32Frame; // offset 0x54, size 0x4
    float m_f32RotRadRate; // offset 0x58, size 0x4
    float m_f32StepFrame; // offset 0x5C, size 0x4
    float m_f32QuickSlowRate; // offset 0x60, size 0x4
    signed int m_eKickerType; // offset 0x64, size 0x4
    signed int m_eStartType; // offset 0x68, size 0x4
    signed int m_eBaseRank; // offset 0x6C, size 0x4
    signed int m_eRank; // offset 0x70, size 0x4
    signed char m_s8MotionStep; // offset 0x74, size 0x1
    signed char m_s8RotDir; // offset 0x75, size 0x1
    signed char m_as8KeyDir[4]; // offset 0x76, size 0x4
    signed char m_s8KeySaveCount; // offset 0x7A, size 0x1
    float m_f32BonusSpeed; // offset 0x7C, size 0x4
    unsigned char m_bEnableKickerDebug; // offset 0x80, size 0x1
    float m_f32DebugSpeed; // offset 0x84, size 0x4
    float m_f32DebugGravity; // offset 0x88, size 0x4
    float m_f32DebugJump; // offset 0x8C, size 0x4
    signed int m_s32EnableAcceleKickerDebug; // offset 0x90, size 0x4
    float m_f32DebugUpSpeed; // offset 0x94, size 0x4
    float m_f32DebugUpAccele; // offset 0x98, size 0x4
    float m_f32DebugDownSpeed; // offset 0x9C, size 0x4
    float m_f32DebugDownAccele; // offset 0xA0, size 0x4
    float m_f32DebugVelocityY; // offset 0xA4, size 0x4
    float m_f32DebugUpGravityAccele; // offset 0xA8, size 0x4
    float m_f32DebugDownGravityAccele; // offset 0xAC, size 0x4
    float m_f32DebugFrame; // offset 0xB0, size 0x4
    unsigned char m_bEnableTrickDebug; // offset 0xB4, size 0x1
    unsigned char m_bTrickRecordDispDebug; // offset 0xB5, size 0x1
    signed int m_eDebugKickerType; // offset 0xB8, size 0x4
    signed int m_eDebugTrickRank; // offset 0xBC, size 0x4
    signed char m_s8DebugKeyDir; // offset 0xC0, size 0x1
}; // total size: 0xD0

class clsTrickManager {
public:
    class clsBaseTrickAction * m_apcActionTable[9]; // offset 0x0, size 0x24
    class clsTrickParam m_cParam; // offset 0x30, size 0xD0
    class clsFlipTrickAction m_cFlipTrickAction; // offset 0x100, size 0x4
    class clsSpinTrickAction m_cSpinTrickAction; // offset 0x104, size 0x4
    class clsPipeTrickAction m_cPipeTrickAction; // offset 0x108, size 0x4
    class clsFreeTrickAction m_cFreeTrickAction; // offset 0x10C, size 0x4
    class clsWallTrickAction m_cWallTrickAction; // offset 0x110, size 0x4
    class clsVerticalTrickAction m_cVerticalTrickAction; // offset 0x120, size 0x30
    class clsTurbTrickAction m_cTurbTrickAction; // offset 0x150, size 0x4
    class clsPartsTrickAction m_cPartsTrickAction; // offset 0x154, size 0x4
}; // total size: 0x160

// total size: 0x12F0
class clsPlayerTask : public clsObject, public clsTask {
public:
    virtual ~clsPlayerTask();
    virtual void reset();
    virtual void draw();
    virtual void execute();
    virtual int getPlayerType() const { return PLAYER_TYPE__NORMAL; } // vtable slot 0x58

    bool isDemo() const;
    void setBoardMtx(unsigned int, int);
    void setRingNum(int);
    void updateLightNo();
    void deleteLightCollision(clsThroughCollision *);
    void registLightCollision(clsThroughCollision *);
    bool isReverse();
    void contactTriggerEvent(hkContactPoint *, clsObject *);
    void changeUserToCom();
    void calcNodePos();
    void stopSlipStreamEffect();
    void updateSlipStreamEffect();
    void setSlipStreamEffect();
    void setStartDemoEffect();
    void setDrawBackLineFlg();
    void demoMotionWeather();
    void setWeather(unsigned char);
    bool checkLoopEffect(unsigned char);
    void stopLoopEffect(unsigned char);
    void setLoopEffect(unsigned char, clsTask *);
    void setLoopEffect(unsigned char, unsigned int, clsModelType_OB_TX_MO_MA *, unsigned int);
    void stopLoopParticle(unsigned char);
    void setLoopParticle(unsigned char, unsigned int, unsigned int, unsigned char);
    void setVaporTrail(bool);
    void setFalseStartAction(int, int);
    void setGoalComPlayer();
    void GoalPlayer();
    void changeCameraRq(unsigned int);
    void changeTrickCameraRq(unsigned char, int);
    void reconfigurationVelocity(const NNS_VECTORFAST *);
    void setInertia(const NNS_VECTORFAST *, float, float);

    signed int                 m_s32EnableMovePathDebug;     // 0x58, size 0x4
    class stcLine              m_sDebugLine;                 // 0x5C, size 0x30
    unsigned char              m_bEnableFlyDebug;            // 0x8C, size 0x1
    float                      m_f32Debug_StiffFrame;        // 0x90, size 0x4
    float                      m_f32Debug_StallSpeed;        // 0x94, size 0x4
    float                      m_f32Debug_AirResist;         // 0x98, size 0x4
    float                      m_f32Debug_UpDownAccele;      // 0x9C, size 0x4
    float                      m_f32Debug_FallAccele;        // 0xA0, size 0x4
    float                      m_f32Debug_DescentAccele;     // 0xA4, size 0x4
    float                      m_f32Debug_RollSpeed;         // 0xA8, size 0x4
    float                      m_f32Debug_PitchSpeed;        // 0xAC, size 0x4
    float                      m_f32Debug_UpPitch_Limit;     // 0xB0, size 0x4
    float                      m_f32Debug_DownPitch_Limit;   // 0xB4, size 0x4
    float                      m_af32Debug_PitchGravityTable[3]; // 0xB8, size 0xC
    unsigned char              m_bDispReturnPoint;           // 0xC4, size 0x1
    unsigned char              m_bDispCoursePoint;           // 0xC5, size 0x1
    class clsPlayerDebug *     m_pcDebug;                    // 0xC8, size 0x4
    signed int                 m_s32SfId[23];                // 0xCC, size 0x5C
    float                      m_sDrawMtx[2][4][4];          // 0x130, size 0x80
    float                      m_sEffMtx[4][4];              // 0x1B0, size 0x40
    float                      m_asBoardMtx[4][4][4];        // 0x1F0, size 0x100
    float                      m_sGearDrawMtx[4][4];         // 0x2F0, size 0x40
    class NNS_VECTORFAST       m_sPosVecFast[2];             // 0x330, size 0x20
    class NNS_VECTORFAST       m_sUpVecFast;                 // 0x350, size 0x10
    class NNS_VECTORFAST       m_sPreUpVecFast;              // 0x360, size 0x10
    class NNS_VECTORFAST       m_sVelocityVecFast;           // 0x370, size 0x10
    class NNS_VECTORFAST       m_sSpeedVecFast;              // 0x380, size 0x10
    class NNS_VECTORFAST       m_sAirVecFast;                // 0x390, size 0x10
    class NNS_VECTORFAST       m_sVectorMoveVecFast;         // 0x3A0, size 0x10
    class NNS_VECTORFAST       m_sPathMoveVecFast;           // 0x3B0, size 0x10
    class NNS_VECTORFAST       m_sContactCharaDirVecFast;    // 0x3C0, size 0x10
    class NNS_VECTORFAST       m_sInertiaVecFast;            // 0x3D0, size 0x10
    class NNS_VECTORFAST       m_sInertiaDecayVecFast;       // 0x3E0, size 0x10
    class NNS_VECTORFAST       m_sFaceDirVecFast;            // 0x3F0, size 0x10
    class NNS_VECTORFAST       m_sContactVecFast;            // 0x400, size 0x10
    class NNS_VECTORFAST       m_sRelativeVecFast;           // 0x410, size 0x10
    class NNS_VECTORFAST       m_sExCamTargetPosVecFast;     // 0x420, size 0x10
    class NNS_VECTORFAST       m_sOffsetDrawVecFast;         // 0x430, size 0x10
    class NNS_VECTORFAST       m_sMoveNrmVecFast;            // 0x440, size 0x10
    class stcInitData          m_sInitData;                  // 0x450, size 0x30
    class stcInitData          m_sBackUpData;                // 0x480, size 0x30
    class clsPrfm              m_cPrfm;                      // 0x4B0, size 0x110
    class clsPlayerMotion *    m_pcMotion;                   // 0x5C0, size 0x4
    class clsSurface           m_cSurface;                   // 0x5D0, size 0x20
    class clsGravity           m_cGravity;                   // 0x5F0, size 0x130
    class clsGravity           m_cBackUpGravity;             // 0x720, size 0x130
    class clsPosturalCtrl      m_cVelocity;                  // 0x850, size 0xB0
    class clsPosturalCtrl      m_cPostural;                  // 0x900, size 0xB0
    class clsTrickManager      m_cTrick;                     // 0x9B0, size 0x160
    clsGravityActionManager    m_cGravityActionManager;      // 0xB10, size 0x50
    class clsControlMatrix     m_cControlMatrix;             // 0xB60, size 0x110
    class clsReaction          m_cReaction;                  // 0xC70, size 0x40
    class clsPath              m_cPath;                      // 0xCB0, size 0x60
    class clsFlyAction         m_cFlyAction;                 // 0xD10, size 0x1C
    class clsRetPath           m_cRetCoursePath;             // 0xD2C, size 0x20
    class clsSlipStream        m_cSlipStream;                // 0xD50, size 0xD0
    class clsPlayerKey*        m_pcKey;                      // 0xE20, size 0x4
    class clsComKey*           m_pcAutoRunKey;               // 0xE24, size 0x4
    class clsUserKey*          m_pcUserKeyTmp;               // 0xE28, size 0x4
    class clsCharacter*        m_pcCharacter;                // 0xE2C, size 0x4
    class clsGearCtrl*         m_pcGearCtrl;                 // 0xE30, size 0x4
    class clsPlayerPhysic*     m_pcPhysic;                   // 0xE34, size 0x4
    class clsLap*              m_pcLap;                      // 0xE38, size 0x4
    class clsObject*           m_pcGroundObject;             // 0xE3C, size 0x4
    class clsOOList            m_lstLightCollision;          // 0xE40, size 0x14
    class clsFlag              m_cSystemFlag;                // 0xE54, size 0x4
    enum enmNo                 m_ePlayerNo;                  // 0xE58, size 0x4
    enum enmFlag               m_eFlag;                      // 0xE5C, size 0x4
    enum enmStatus             m_eStatus;                    // 0xE60, size 0x4
    enum enmStatus             m_eStatusOld;                 // 0xE64, size 0x4
    enum enmStatus             m_eStatusTrigger;             // 0xE68, size 0x4
    enum enmStatus             m_eStatusRemove;              // 0xE6C, size 0x4
    enum enmActionType         m_eActionType;                // 0xE70, size 0x4
    enum enmActionType         m_eOldActionType;             // 0xE74, size 0x4
    enum enmMoveFlag           m_eMoveFlag;                  // 0xE78, size 0x4
    float                      m_f32FrameRate;               // 0xE7C, size 0x4
    float                      m_f32CurveRotateRate;         // 0xE80, size 0x4
    float                      m_f32CurveMotionRate;         // 0xE84, size 0x4
    float                      m_f32CurveRad;                // 0xE88, size 0x4
    float                      m_f32CurveWaitFrame;          // 0xE8C, size 0x4
    float                      m_f32vibrationCurveRate;      // 0xE90, size 0x4
    float                      m_f32CurveFrame;              // 0xE94, size 0x4
    float                      m_f32CentrifugalForce;        // 0xE98, size 0x4
    float                      m_f32MinSpeed;                // 0xE9C, size 0x4
    float                      m_f32MaxSpeed;                // 0xEA0, size 0x4
    float                      m_f32Speed;                   // 0xEA4, size 0x4
    float                      m_f32Accele;                  // 0xEA8, size 0x4
    float                      m_f32SpeedRate;               // 0xEAC, size 0x4
    float                      m_f32AdjustAcceleRate;        // 0xEB0, size 0x4
    float                      m_f32AdjustMaxSpeed;          // 0xEB4, size 0x4
    signed int                 m_s32NodeVibCycle;            // 0xEB8, size 0x4
    float                      m_f32FaceRotateRate;          // 0xEBC, size 0x4
    signed int                 m_s32RingNum;                 // 0xEC0, size 0x4
    signed int                 m_s32GoalRingNum;             // 0xEC4, size 0x4
    float                      m_f32GoalRingRate;            // 0xEC8, size 0x4
    signed int                 m_s32LinkCount;               // 0xECC, size 0x4
    enum enmLinkType           m_eLinkType;                  // 0xED0, size 0x4
    float                      m_f32Val;                     // 0xED4, size 0x4
    float                      m_f32ApproachVal;             // 0xED8, size 0x4
    float                      m_af32ActionVal[3];           // 0xEDC, size 0xC
    float                      m_f32ObstacleFrame;           // 0xEE8, size 0x4
    float                      m_f32InertiaDecayFrame;       // 0xEEC, size 0x4
    signed int                 m_s32ActionMode;              // 0xEF0, size 0x4
    enum enPlayerCtrlType      m_eCtrlType;                  // 0xEF4, size 0x4
    enum enPlayerCtrlType      m_eDefaultCtrlType;           // 0xEF8, size 0x4
    signed char                m_s8BaseMotionNo;             // 0xEFC, size 0x1
    unsigned char              m_u8CurrentDrawMtxNo;         // 0xEFD, size 0x1
    unsigned char              m_u8BadTrackCnt;              // 0xEFE, size 0x1
    signed char                m_s8Ranking;                  // 0xEFF, size 0x1
    signed int                 m_s32FalseStartShockFrame;    // 0xF00, size 0x4
    signed int                 m_s32FalseStartDamageFrame;   // 0xF04, size 0x4
    float                      m_f32DamageFrame;             // 0xF08, size 0x4
    float                      m_f32InvincibilityFrame;      // 0xF0C, size 0x4
    float                      m_f32TrapColorBallFrame;      // 0xF10, size 0x4
    float                      m_f32TrapColorBallDropFrame;  // 0xF14, size 0x4
    unsigned int               m_u32TrapColorBallDropCnt;    // 0xF18, size 0x4
    unsigned int               m_u32TrapColorBallDropMaxCnt; // 0xF1C, size 0x4
    float                      m_f32TrapPartsLockFrame;      // 0xF20, size 0x4
    float                      m_f32EggConfettiFrame;        // 0xF24, size 0x4
    float                      m_f32EggConfettiDropFrame;    // 0xF28, size 0x4
    float                      m_f32NightsAtkEffectFrame;    // 0xF2C, size 0x4
    float                      m_f32NightsAtkEffectDropFrame; // 0xF30, size 0x4
    unsigned int               m_u32NightsAtkEffectDropCnt;  // 0xF34, size 0x4
    float                      m_f32DriftSideSign;           // 0xF38, size 0x4
    float                      m_f32DriftOffsetPosturalRotate; // 0xF3C, size 0x4
    float                      m_f32DriftStartSpeed;         // 0xF40, size 0x4
    float                      m_f32DriftLimitSpeed;         // 0xF44, size 0x4
    float                      m_f32DriftDashSpeed;          // 0xF48, size 0x4
    float                      m_f32DriftHandlingRate;       // 0xF4C, size 0x4
    float                      m_f32DriftFrame;              // 0xF50, size 0x4
    unsigned int               m_u32DriftDashType;           // 0xF54, size 0x4
    float                      m_f32ReverseRestartCountFrame; // 0xF58, size 0x4
    float                      m_f32ReverseStartCountFrame;  // 0xF5C, size 0x4
    class clsTask *            m_apcLoopParticle[4];         // 0xF60, size 0x10
    class clsTask *            m_apcLoopEffect[4];           // 0xF70, size 0x10
    class NNS_VECTORFAST       m_asNodePos[8];               // 0xF80, size 0x80
    float                      m_asNodeMatrix[8][4][4];      // 0x1000, size 0x200
    class clsBackLineEffectTask * m_pcBackLineTask;          // 0x1200, size 0x4
    class clsVaporTrail_Task * m_pcVaporTrailTask;           // 0x1204, size 0x4
    class clsVaporTrail_Task * m_pcSlipStreamTask;           // 0x1208, size 0x4
    class clsWeather_Task *    m_pcWeatherTask;              // 0x120C, size 0x4
    class clsCharaVoice        m_cCharaVoice;                // 0x1210, size 0x10
    enum enmRet                m_aeClipperRet[4];            // 0x1220, size 0x10
    float                      m_of32DrawClipDistx2;         // 0x1230, size 0x4
    float                      m_of32MotionClipDistx1;       // 0x1234, size 0x4
    float                      m_f32CamMostDistRet;          // 0x1238, size 0x4
    float                      m_f32RandMotionFrame;         // 0x123C, size 0x4
    float                      m_f32RankChangeMotionFrame;   // 0x1240, size 0x4
    unsigned int               m_u32CamDelayRqType;          // 0x1244, size 0x4
    float                      m_f32CamDelayRqTime;          // 0x1248, size 0x4
    float                      m_f32AttackFrame;             // 0x124C, size 0x4
    float                      m_f32FlightFrame;             // 0x1250, size 0x4
    float                      m_f32SystemScale;             // 0x1254, size 0x4
    class clsModelType_OB_TX * m_opcResidenceTexModel_PS2;   // 0x1258, size 0x4
    unsigned short             m_u16ReturnLineNo;            // 0x125C, size 0x2
    unsigned char              m_bForcedUpdateFlag;          // 0x125E, size 0x1
    unsigned char              m_bDrawVisible;               // 0x125F, size 0x1
    unsigned char              m_bMotionVisible;             // 0x1260, size 0x1
    unsigned char              m_bDrawFlag;                  // 0x1261, size 0x1
    signed char                m_s8Channel_ICS;              // 0x1262, size 0x1
    signed char                m_s8FollowNum;                // 0x1263, size 0x1
    unsigned char              m_u8BaseLightNo;              // 0x1264, size 0x1
    unsigned char              m_u8LightNo;                  // 0x1265, size 0x1
    unsigned char              m_u8BackUpLightNo;            // 0x1266, size 0x1
    unsigned char              m_u8BackUpFogNo;              // 0x1267, size 0x1
    signed char                m_s8OldPathNo;                // 0x1268, size 0x1
    unsigned char              m_bDisableFog;                // 0x1269, size 0x1
    signed char                m_s8CameraNo;                 // 0x126A, size 0x1
    signed char                m_s8ViewNo;                   // 0x126B, size 0x1
    unsigned char              m_u8JumpCount;                // 0x126C, size 0x1
    signed char                m_s8CurAttackTarget;          // 0x126D, size 0x1
    float                      m_f32Attack_Speed;            // 0x1270, size 0x4
    float                      m_f32Attack_Accele;           // 0x1274, size 0x4
    float                      m_f32Attack_SpeedRate;        // 0x1278, size 0x4
    enum enmAttackLR           m_eTargetSide;                // 0x127C, size 0x4
    unsigned char              m_bDamageFlag;                // 0x1280, size 0x1
    class clsBaseEffect_Task * m_pcDmgEffectTask;            // 0x1284, size 0x4
    class clsBaseEffect_Task * m_pcDmgEffectTask2;           // 0x1288, size 0x4
    unsigned char              m_bIsAttackDmgScale;          // 0x128C, size 0x1
    float                      m_f32AttackDmgScale;          // 0x1290, size 0x4
    signed int                 m_s32SuperSonic;              // 0x1294, size 0x4
    enum enmComType            m_eComType;                   // 0x1298, size 0x4
    float                      m_f32BoostAttackFrame;        // 0x129C, size 0x4
    float                      m_f32GpRateEffectCnt;         // 0x12A0, size 0x4
    float                      m_f32TrickXNegaWaitFrame;     // 0x12A4, size 0x4
    unsigned char              m_bTrickXNegaFlg;             // 0x12A8, size 0x1
    signed int                 m_s32GoalMotionRequest;       // 0x12AC, size 0x4
    class clsLimitTime         m_cRingLimitTime;             // 0x12B0, size 0x14
    class clsLimitTime         m_cRingGravityLimitTime;      // 0x12C4, size 0x14
    float                      m_f32ItemFrame;               // 0x12D8, size 0x4
    signed int                 m_s32ReplayCamIdx;            // 0x12DC, size 0x4
    signed int                 m_s32AutoWallRunPathNo;       // 0x12E0, size 0x4
    class clsDashPanel_Obj *   m_pcDashPanel;                // 0x12E4, size 0x4
    class clsEggConfetti *     m_pcEggConfetti;              // 0x12E8, size 0x4
    class clsNightsAtkEffect * m_pcNightsAtkEffect;          // 0x12EC, size 0x4
};

#endif // PLAYER_HPP
