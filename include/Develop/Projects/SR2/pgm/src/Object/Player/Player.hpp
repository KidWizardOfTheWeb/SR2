#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Game/BaseRace.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Motion.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/GravityAction/GravityActionManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Performance.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/Gear.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearCtrl.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Path.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Surface.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/LimitTime.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gravity.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/ControlMatrix.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/SlipStream.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Reaction.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Path/PathPoint.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/TrickParam.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/TrickManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Sound/CharaVoice.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOTask.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Postural.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsCharacter;
class clsPlayerPhysic;
class clsPrfm;
class clsGearCtrl;
class clsLap;
class clsBackLineEffectTask;
class clsVaporTrail_Task;
class clsWeather_Task;
class clsBaseEffect_Task;
class clsDashPanel_Obj;
class clsEggConfetti;
class clsNightsAtkEffect;
class clsPlayerTask;
class clsPlaySe_2D;
class clsPlayerKey;
class clsComKey;
class clsUserKey;
class clsPlayerDebug;
class clsPlayerMotion;
struct stcInfo;
class clsThroughCollision;
class hkContactPoint;
class clsModelType_OB_TX_MO_MA;

class clsPack;

// total size: 0x70
struct stcBurnOutEffect {
    u32 u32Num;               // offset 0x0, size 0x4
    u32 u32Size;              // offset 0x4, size 0x4
    NNS_VECTORFAST sBeginSp;  // offset 0x10, size 0x10
    NNS_VECTORFAST sAddSp;    // offset 0x20, size 0x10
    NNS_VECTOR sRandSp;       // offset 0x30, size 0xC
    NNS_VECTOR sLocalPos;     // offset 0x3C, size 0xC
    NNS_VECTOR sLocalPosRand; // offset 0x48, size 0xC
    f32 f32AirK;              // offset 0x54, size 0x4
    f32 f32Mass;              // offset 0x58, size 0x4
    f32 f32LifeFrame;         // offset 0x5C, size 0x4
    f32 f32GroundK;           // offset 0x60, size 0x4
    f32 f32ClipZ;             // offset 0x64, size 0x4
};

namespace nspChara {
enum enmModelType {
    MODEL_TYPE_DEF = 0,
    MODEL_TYPE_SKATE_START = 1,
    MODEL_TYPE_ADS = 1,
    MODEL_TYPE_CVS = 2,
    MODEL_TYPE_RLL = 3,
    MODEL_TYPE_SNB = 4,
    MODEL_TYPE_WTD = 5,
    MODEL_TYPE_MAX = 6,
    MODEL_TYPE_SKATE_END = 5,
};
} // namespace nspChara

enum enmPlayerType {
    PLAYER_TYPE__NORMAL = 0,
    PLAYER_TYPE__GHOST = 1,
};

enum enmStatus {
    STATUS_NULL = 0,
    STATUS_END = 1,
    STATUS_STOP = 2,
    STATUS_BLEND = 4,
    STATUS_UNLOOP = 8,
    STATUS_LINK_ONE = 16,
    STATUS_LINK_SYNC = 32,
    STATUS_NEXT_UNLOOP = 64,
    STATUS_NEXT_STOP = 128,
};

enum enmSystemFlag {
    SYSTEM_FLAG__CLEAR = 0,
    SYSTEM_FLAG__OBJ_PORTAL_FORWARD = 1,
};

template <class T>
class clsFlag {
public:
    clsFlag(T tData) : m_tData(tData) {}
    T getParam() const { return m_tData; }
    void setParam(u32 u32Data, u32 u32Mask)
    {
        m_tData = static_cast<T>((m_tData & ~u32Mask) | (u32Data & u32Mask));
    }

    T m_tData; // offset 0x0, size 0x4
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

namespace nspPlayer {
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
struct stcInitData {
    NNS_VECTORFAST sPosVecFast; // offset 0x0, size 0x10
    NNS_VECTORFAST sUpVecFast;  // offset 0x10, size 0x10
    f32 f32LocalAngleRad;       // offset 0x20, size 0x4
    u32 u32Padding;             // offset 0x24, size 0x4
}; // total size: 0x30
} // namespace nspPlayer
typedef nspPlayer::stcInitData stcInitData;

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

#include "Develop/Projects/SR2/pgm/src/Data/PathData.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/GearChenge/FlyAction.hpp"

// total size: 0x18
class _ActionFuncTbl {
public:
    void (clsPlayerTask::*pfInitAction)(); // offset 0x0, size 0xC
    void (clsPlayerTask::*pfExexAction)(); // offset 0xC, size 0xC
};

// total size: 0x12F0
class clsPlayerTask : public clsObject, public clsTask {
public:
    typedef ::enmFlag enmFlag;
    enum enmStatus {
        STATUS_NULL = 0,
        STATUS_END = 1,
        STATUS_STOP = 2,
        STATUS_BLEND = 4,
        STATUS_UNLOOP = 8,
        STATUS_LINK_ONE = 16,
        STATUS_LINK_SYNC = 32,
        STATUS_NEXT_UNLOOP = 64,
        STATUS_NEXT_STOP = 128,
    };
    typedef ::enmActionType enmActionType;
    typedef ::enmMoveFlag enmMoveFlag;
    typedef f32 (*MtxPtr)[4];
    typedef f32 (*Mtx44Ptr)[4][4];

    enum enmCalcNodePos {
        NODE_POS_SPINE = 0,
        NODE_POS_GRAVITYCTRL = 1,
        NODE_POS_GEAR = 2,
        NODE_POS_RIGHT_HAND = 3,
        NODE_POS_LEFT_HAND = 4,
        NODE_POS_RIGHT_TOE = 5,
        NODE_POS_HEAD_TOP = 6,
        NODE_POS_HIP = 7,
        NODE_POS_MAX = 8,
    };

    // stub (header): clsPlayerTask(const stcSetDataDetail& rParam1) : clsTask(0, 0) {}
    clsPlayerTask(const stcSetDataDetail& rParam1)
        : clsTask(0x18704, 5), m_cCharaVoice(this), m_cSystemFlag(SYSTEM_FLAG__CLEAR)
    {
    }
    // stub (header): clsPlayerTask(u32 u32Param1) : clsTask(0, 0) {}
    clsPlayerTask(u32 u32Param1)
        : clsTask(u32Param1, 5), m_cCharaVoice(this), m_cSystemFlag(SYSTEM_FLAG__CLEAR)
    {
    }
    virtual ~clsPlayerTask();
    virtual enmPlayerType getPlayerType() const { return PLAYER_TYPE__NORMAL; } // vtable slot 0x58
    virtual void reset();
    virtual void draw();
    virtual void execute();

    static f32 t_of32DefaultMinSpeed;
    static f32 t_of32TurbMinSpeed;
    static f32 t_of32TurbMaxSpeed;
    static f32 t_of32SurfaceAdjustScale;
    static f32 t_of32RingRateTime;
    static f32 t_of32RingGravityRateTime;
    static _ActionFuncTbl t_sActionFuncTbl[34];

    u8 isDemo() const;
    void setBoardMtx(u32 u32Param1, s32 s32Param2);
    void setRingNum(s32 s32Param1);
    void updateLightNo();
    void deleteLightCollision(clsThroughCollision* pParam1);
    void registLightCollision(clsThroughCollision* pParam1);
    u8 isReverse();
    void contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2);
    void changeUserToCom();
    void calcNodePos();
    void stopSlipStreamEffect();
    void updateSlipStreamEffect();
    void setSlipStreamEffect();
    void setStartDemoEffect();
    void setDrawBackLineFlg();
    void demoMotionWeather();
    void setWeather(u8 u8Param1);
    u8 checkLoopEffect(u8 u8Param1);
    void stopLoopEffect(u8 u8Param1);
    u8 setLoopEffect(u8 u8Param1, clsTask* pParam2);
    u8 setLoopEffect(u8 u8Param1, u32 u32Param2, clsModelType_OB_TX_MO_MA* pParam3, u32 u32Param4);
    void stopLoopParticle(u8 u8Param1);
    u8 setLoopParticle(u8 u8Param1, u32 u32Param2, u32 u32Param3, u8 u8Param4);
    void setVaporTrail(bool bParam1);
    void setFalseStartAction(s32 s32Param1, s32 s32Param2);
    void setGoalComPlayer();
    u8 GoalPlayer();
    void changeCameraRq(u32 u32Param1);
    void changeTrickCameraRq(u8 u8Param1, nspTrick::enmKicker eKicker);
    void reconfigurationVelocity(const NNS_VECTORFAST* pParam1);
    void setInertia(const NNS_VECTORFAST* pParam1, f32 f32Param2, f32 f32Param3);
    void createGear(nspGear::enmGearCtrl eGearCtrlNo, u32 u32InitEquipsGears);
    void createChara(nspChara::enmCharaType eCharaType, nspChara::enmModelType eModelType);
    void initKey(nspPlayer::enmNo u8PadNo, enPlayerCtrlType sParam2, u8 u8Param3);
    void initCamera(enPlayerCtrlType eCtrlType, u32 u32CharaNo);
    void init(nspPlayer::enmNo ePlayerNo,
              enPlayerCtrlType eCtrlType,
              u32 u32CharaNo,
              nspGear::enmGearCtrl eGearCtrlNo,
              u32 u32GearLevel,
              u8 u8PadNo);
    void createMothion(nspChara::enmCharaType enCharaType);
    void setClearStatus(clsPlayerTask::enmStatus eStatus);
    void setAndStatus(clsPlayerTask::enmStatus eStatus);
    void clearPlayerCondition();
    void setNightsAtkEffectStatus(f32 f32Frame);
    void setEggConfettiStatus(f32 f32Frame);
    void setSpeedDownStatus(f32 f32Frame);
    void setTrapPartsLockStatus(f32 f32Frame);
    void setTrapColorBallStatus(f32 f32Frame);
    void setInvincibilityStatus(f32 f32Frame);
    void setDamageStatus(f32 f32Frame);
    void update();
    void calcVelocity(NNS_VECTORFAST* psVelocityVecFast);
    void physic();
    void quakeCamera(s32 s32Index, f32 f32Frame);
    void restrictTurbRun();
    void setSetData(const clsPack::stcSetDataDetail* opsSetDataDetailI);
    f32 getStageMinimumHeight(u32 u32StageNo) const;
    void actionDemo();
    void initDemo();
    void cancelGearAttack();
    void actionGearAttack();
    void initGearAttack();
    void actionGearFlight();
    void initGearFlight();
    void actionGearGCtrlFlight();
    void initGearGCtrlFlight();
    void actionGearGCtrlSlide();
    void initGearGCtrlSlide();
    void actionGearGDive();
    void initGearGDive();
    void actionGearInertia();
    void initGearInertia();
    void actionGearJump();
    void initGearJump();
    void actionGearPath();
    void initGearPath();
    void actionGearRail();
    void initGearRail();
    void actionGearRun();
    void initGearRun();
    void setTrickXEffect();
    void actionGearTrick();
    void initGearTrick();
    void actionWalkBack();
    void initWalkBack();
    void actionWalkBrake();
    void initWalkBrake();
    void actionWalkFlight();
    void initWalkFlight();
    void actionWalkRun();
    void initWalkRun();
    void actionWalkWait();
    void initWalkWait();
    void useRingGear();
    void updateObstacle();
    void breakObstacle();
    void clearMoveSubParam();
    void checkDirectionRegulation();
    void clearCollisionFilterWalk();
    void setCollisionFilterWalk();
    u32 checkRailAction();
    void curveWalk(f32 f32Ratio);
    void acceleWalk();
    void endMovePath();
    void actionRateAccele(const clsPathData::stcLine* opsLine);
    void actionFrameAccele(const clsPathData::stcLine* opsLine);
    void actionFreeAccele(const clsPathData::stcLine* pParam1);
    void actionFixedSpeed(const clsPathData::stcLine* pParam1);
    void initRateAccele(const clsPathData::stcLine* opsLine);
    void initFrameAccele(const clsPathData::stcLine* opsLine);
    void initFreeAccele(const clsPathData::stcLine* opsLine);
    void initFixedSpeed(const clsPathData::stcLine* opsLine);
    void requestJumpOrTrick();
    void requestFlightAction();
    void checkGearChange();
    void checkGCtrlFlight();
    void checkGCtrlTrick();
    void checkGCtrlSlide();
    void checkGDive();
    void checkBrake();
    void registanceFlightFloating(f32 f32Accele);
    void registanceFlightSpeed();
    void vibrationCurve();
    void vibrationLanding();
    void initCommonFlight();
    void initCommonRun();
    void updateAction();
    void setActionType(clsPlayerTask::enmActionType eType);
    void actionGearFly();
    void initGearFly();
    void endGearFly();
    void cancelGearFly();
    void actionGearPower();
    void initGearPower();
    void actionFalseStart();
    void initFalseStart();
    void initData_Restart();
    void actionReStart();
    void initReStart();
    void actionDamage00();
    void initDamage00();
    void actionGearDirRegulateRun();
    void initGearDirRegulateRun();
    void actionGearBrake();
    void initGearBrake();
    void actionGearTranslationMovePath();
    void initGearTranslationMovePath();
    void actionGearGDiveAuto();
    void initGearGDiveAuto();
    void actionGearGCtrlTrick();
    void initGearGCtrlTrick();
    void actionAttackDamage();
    void setCancelAttackDamage();
    void initAttackDamage();
    void actionWalkSpring();
    void initWalkSpring();
    void actionWheelDrift();
    void initWheelDrift();
    void actionDamage01();
    void initDamage01();
    void actionBoost();
    void initBoost();
    void actionAutoWallRun();
    void initAutoWallRun();

    virtual enmType getObjectType() const;

    void actionGearRail_drawBurnOut();
    void actionGearWheelDrift_drawBurnOutEffect();
    void backupPosition();
    void backupPosition(NNS_VECTORFAST* psVecFast);
    void backupUp();
    void behaviorMtxList();
    void behaviorMtxPal();
    void behaviorTrs();
    void enableFog();
    f32 getAccele() const;
    s32 getActionMode() const;
    enmActionType getActionType() const;
    f32 getActionVal(u32 u32Index) const;
    NNS_VECTORFAST* getAirVecFastRef();
    u8 getBackUpFogNo() const;
    u8 getBackUpLightNo() const;
    s8 getCameraNo() const;
    f32 getCentrifugalForce() const;
    clsCharacter* getCharacterRef();
    NNS_VECTORFAST* getContactVecFastRef();
    clsControlMatrix* getControlMatrixRef();
    enPlayerCtrlType getCtrlType() const;
    f32 getCurveRad() const;
    f32 getCurveRotateRate() const;
    Mtx44Ptr getDrawMtxRef();
    MtxPtr getEffMtxRef();
    enmFlag getFlag() const;
    f32* getFlightFrameRef();
    clsFlyAction* getFlyActionRef();
    s8 getFollowNum() const;
    clsGearCtrl* getGearCtrlRef();
    clsGravityActionManager* getGravityActionManagerRef();
    clsGravity* getGravityRef();
    clsPlayerKey* getKeyRef();
    clsLap* getLapPtr();
    u8 getLightNo() const;
    f32 getMaxSpeed() const;
    f32 getMinSpeed() const;
    clsPlayerMotion* getMotionRef();
    enmMoveFlag getMoveFlag() const;
    NNS_VECTORFAST* getMoveNrmVecFastPtr() const;
    const NNS_VECTORFAST* getNodePos(u8 u8NodeNo) const;
    enmActionType getOldActionType() const;
    Mtx44Ptr getOldDrawMtxRef();
    NNS_VECTORFAST* getOldPosVecFastPtr() const;
    u8 getOnSnow() const;
    u8 getOnSnowOld() const;
    u8 getOnWater() const;
    u8 getOnWaterOld() const;
    NNS_VECTORFAST* getPathMoveVecFastRef();
    clsPath* getPathRef();
    clsPlayerPhysic* getPhysicRef();
    nspPlayer::enmNo getPlayerNo() const;
    NNS_VECTORFAST* getPosVecFastPtr() const;
    NNS_VECTORFAST* getPosVecFastRef();
    MtxPtr getPosturalMtxPtr() const;
    NNS_VECTORFAST* getPosturalNrmVecFastPtr() const;
    f32 getPosturalRad() const;
    clsPosturalCtrl* getPosturalRef();
    clsPrfm* getPrfmRef();
    NNS_VECTORFAST* getRelativeVecFastRef();
    clsRetPath* getRetCoursePathRef();
    u16 getReturnLineNo() const;
    s32 getRingNum() const;
    s32 getSfId(s32 s32SfId);
    f32 getSpeed() const;
    f32 getSpeedRate() const;
    enmStatus getStatus() const;
    enmStatus getStatusTrigger() const;
    clsSurface* getSurfaceRef();
    clsTrickManager* getTrickRef();
    NNS_VECTORFAST* getUpVecFastPtr() const;
    NNS_VECTORFAST* getUpVecFastRef();
    NNS_VECTORFAST* getVectorMoveVecFastRef();
    MtxPtr getVelocityMtxPtr() const;
    NNS_VECTORFAST* getVelocityNrmVecFastPtr() const;
    NNS_QUATERNION* getVelocityQuatPtr() const;
    f32 getVelocityRad() const;
    clsPosturalCtrl* getVelocityRef();
    NNS_VECTORFAST* getVelocityVecFastPtr() const;
    NNS_VECTORFAST* getVelocityVecFastRef();
    clsCharaVoice* getVoiceRef();
    u8 isAttackDmgScale() const;
    u8 isCom() const;
    u8 isDefaultUser() const;
    u8 isDemoCom() const;
    u8 isMotionVisibleAllView() const;
    u8 isReplay() const;
    u8 isUser() const;
    void setAccele(f32 f32Accele);
    void setActionMode(s32 s32ActionMode);
    void setActionVal(u32 u32Index, f32 f32Val);
    void setAllFrameRate(f32 f32FrameRate);
    void setBackUpFogNo(u8 u8FogNo);
    void setBackUpLightNo(u8 u8LightNo);
    void setBaseLightNo(u8 u8LightNo);
    void setCentrifugalForce(f32 f32CentrifugalForce);
    void setClearFlag(enmFlag eFlag);
    void setClearMoveFlag(enmMoveFlag eMoveFlag);
    void setCurveRotateRate(f32 f32CurveRotateRate);
    void setFollowNum(s8 s8FollowNum);
    void setFrameRate(f32 f32FrameRate);
    void setGroundEffect();
    void setGroundObject(clsObject* pcObject);
    void setJumpSpeed(f32 f32JumpSpeed, u32 u32Param2);
    void setLightNo(u8 u8LightNo);
    void setMaxSpeed(f32 f32MaxSpeed);
    void setMinSpeed(f32 f32MinSpeed);
    void setMoveFlag(enmMoveFlag eMoveFlag);
    void setOrFlag(enmFlag eFlag);
    void setOrMoveFlag(enmMoveFlag eMoveFlag);
    void setOrStatus(enmStatus eStatus);
    void setPosVecFast(const NNS_VECTORFAST* psVecFast);
    void setPosturalRad(f32 f32Rad);
    void setReturnLineNo(u16 u16LineNo);
    void setSpeed(f32 f32Speed);
    void setSpeedRate(f32 f32SpeedRate);
    void setStiffFrame(f32 f32Frame, s32 eStiffType);
    void setVelocityRad(f32 f32Rad);
    void updatePosturalQuat();
    void updateVelocityQuat();

    s32 m_s32EnableMovePathDebug;                    // offset 0x58, size 0x4
    clsPathData::stcLine m_sDebugLine;               // offset 0x5C, size 0x30
    u8 m_bEnableFlyDebug;                            // offset 0x8C, size 0x1
    f32 m_f32Debug_StiffFrame;                       // offset 0x90, size 0x4
    f32 m_f32Debug_StallSpeed;                       // offset 0x94, size 0x4
    f32 m_f32Debug_AirResist;                        // offset 0x98, size 0x4
    f32 m_f32Debug_UpDownAccele;                     // offset 0x9C, size 0x4
    f32 m_f32Debug_FallAccele;                       // offset 0xA0, size 0x4
    f32 m_f32Debug_DescentAccele;                    // offset 0xA4, size 0x4
    f32 m_f32Debug_RollSpeed;                        // offset 0xA8, size 0x4
    f32 m_f32Debug_PitchSpeed;                       // offset 0xAC, size 0x4
    f32 m_f32Debug_UpPitch_Limit;                    // offset 0xB0, size 0x4
    f32 m_f32Debug_DownPitch_Limit;                  // offset 0xB4, size 0x4
    f32 m_af32Debug_PitchGravityTable[3];            // offset 0xB8, size 0xC
    u8 m_bDispReturnPoint;                           // offset 0xC4, size 0x1
    u8 m_bDispCoursePoint;                           // offset 0xC5, size 0x1
    clsPlayerDebug* m_pcDebug;                       // offset 0xC8, size 0x4
    s32 m_s32SfId[23];                               // offset 0xCC, size 0x5C
    f32 m_sDrawMtx[2][4][4];                         // offset 0x130, size 0x80
    f32 m_sEffMtx[4][4];                             // offset 0x1B0, size 0x40
    f32 m_asBoardMtx[4][4][4];                       // offset 0x1F0, size 0x100
    f32 m_sGearDrawMtx[4][4];                        // offset 0x2F0, size 0x40
    NNS_VECTORFAST m_sPosVecFast[2];                 // offset 0x330, size 0x20
    NNS_VECTORFAST m_sUpVecFast;                     // offset 0x350, size 0x10
    NNS_VECTORFAST m_sPreUpVecFast;                  // offset 0x360, size 0x10
    NNS_VECTORFAST m_sVelocityVecFast;               // offset 0x370, size 0x10
    NNS_VECTORFAST m_sSpeedVecFast;                  // offset 0x380, size 0x10
    NNS_VECTORFAST m_sAirVecFast;                    // offset 0x390, size 0x10
    NNS_VECTORFAST m_sVectorMoveVecFast;             // offset 0x3A0, size 0x10
    NNS_VECTORFAST m_sPathMoveVecFast;               // offset 0x3B0, size 0x10
    NNS_VECTORFAST m_sContactCharaDirVecFast;        // offset 0x3C0, size 0x10
    NNS_VECTORFAST m_sInertiaVecFast;                // offset 0x3D0, size 0x10
    NNS_VECTORFAST m_sInertiaDecayVecFast;           // offset 0x3E0, size 0x10
    NNS_VECTORFAST m_sFaceDirVecFast;                // offset 0x3F0, size 0x10
    NNS_VECTORFAST m_sContactVecFast;                // offset 0x400, size 0x10
    NNS_VECTORFAST m_sRelativeVecFast;               // offset 0x410, size 0x10
    NNS_VECTORFAST m_sExCamTargetPosVecFast;         // offset 0x420, size 0x10
    NNS_VECTORFAST m_sOffsetDrawVecFast;             // offset 0x430, size 0x10
    NNS_VECTORFAST m_sMoveNrmVecFast;                // offset 0x440, size 0x10
    stcInitData m_sInitData;                         // offset 0x450, size 0x30
    stcInitData m_sBackUpData;                       // offset 0x480, size 0x30
    clsPrfm m_cPrfm;                                 // offset 0x4B0, size 0x110
    clsPlayerMotion* m_pcMotion;                     // offset 0x5C0, size 0x4
    clsSurface m_cSurface;                           // offset 0x5D0, size 0x20
    clsGravity m_cGravity;                           // offset 0x5F0, size 0x130
    clsGravity m_cBackUpGravity;                     // offset 0x720, size 0x130
    clsPosturalCtrl m_cVelocity;                     // offset 0x850, size 0xB0
    clsPosturalCtrl m_cPostural;                     // offset 0x900, size 0xB0
    clsTrickManager m_cTrick;                        // offset 0x9B0, size 0x160
    clsGravityActionManager m_cGravityActionManager; // offset 0xB10, size 0x50
    clsControlMatrix m_cControlMatrix;               // offset 0xB60, size 0x110
    clsReaction m_cReaction;                         // offset 0xC70, size 0x40
    clsPath m_cPath;                                 // offset 0xCB0, size 0x60
    clsFlyAction m_cFlyAction;                       // offset 0xD10, size 0x1C
    clsRetPath m_cRetCoursePath;                     // offset 0xD2C, size 0x20
    clsSlipStream m_cSlipStream;                     // offset 0xD50, size 0xD0
    clsPlayerKey* m_pcKey;                           // offset 0xE20, size 0x4
    clsComKey* m_pcAutoRunKey;                       // offset 0xE24, size 0x4
    clsUserKey* m_pcUserKeyTmp;                      // offset 0xE28, size 0x4
    clsCharacter* m_pcCharacter;                     // offset 0xE2C, size 0x4
    clsGearCtrl* m_pcGearCtrl;                       // offset 0xE30, size 0x4
    clsPlayerPhysic* m_pcPhysic;                     // offset 0xE34, size 0x4
    clsLap* m_pcLap;                                 // offset 0xE38, size 0x4
    clsObject* m_pcGroundObject;                     // offset 0xE3C, size 0x4
    clsOOList m_lstLightCollision;                   // offset 0xE40, size 0x14
    clsFlag<enmSystemFlag> m_cSystemFlag;            // offset 0xE54, size 0x4
    enum enmNo m_ePlayerNo;                          // offset 0xE58, size 0x4
    enmFlag m_eFlag;                                 // offset 0xE5C, size 0x4
    enmStatus m_eStatus;                             // offset 0xE60, size 0x4
    enmStatus m_eStatusOld;                          // offset 0xE64, size 0x4
    enmStatus m_eStatusTrigger;                      // offset 0xE68, size 0x4
    enmStatus m_eStatusRemove;                       // offset 0xE6C, size 0x4
    enmActionType m_eActionType;                     // offset 0xE70, size 0x4
    enmActionType m_eOldActionType;                  // offset 0xE74, size 0x4
    enmMoveFlag m_eMoveFlag;                         // offset 0xE78, size 0x4
    f32 m_f32FrameRate;                              // offset 0xE7C, size 0x4
    f32 m_f32CurveRotateRate;                        // offset 0xE80, size 0x4
    f32 m_f32CurveMotionRate;                        // offset 0xE84, size 0x4
    f32 m_f32CurveRad;                               // offset 0xE88, size 0x4
    f32 m_f32CurveWaitFrame;                         // offset 0xE8C, size 0x4
    f32 m_f32vibrationCurveRate;                     // offset 0xE90, size 0x4
    f32 m_f32CurveFrame;                             // offset 0xE94, size 0x4
    f32 m_f32CentrifugalForce;                       // offset 0xE98, size 0x4
    f32 m_f32MinSpeed;                               // offset 0xE9C, size 0x4
    f32 m_f32MaxSpeed;                               // offset 0xEA0, size 0x4
    f32 m_f32Speed;                                  // offset 0xEA4, size 0x4
    f32 m_f32Accele;                                 // offset 0xEA8, size 0x4
    f32 m_f32SpeedRate;                              // offset 0xEAC, size 0x4
    f32 m_f32AdjustAcceleRate;                       // offset 0xEB0, size 0x4
    f32 m_f32AdjustMaxSpeed;                         // offset 0xEB4, size 0x4
    s32 m_s32NodeVibCycle;                           // offset 0xEB8, size 0x4
    f32 m_f32FaceRotateRate;                         // offset 0xEBC, size 0x4
    s32 m_s32RingNum;                                // offset 0xEC0, size 0x4
    s32 m_s32GoalRingNum;                            // offset 0xEC4, size 0x4
    f32 m_f32GoalRingRate;                           // offset 0xEC8, size 0x4
    s32 m_s32LinkCount;                              // offset 0xECC, size 0x4
    enum enmLinkType m_eLinkType;                    // offset 0xED0, size 0x4
    f32 m_f32Val;                                    // offset 0xED4, size 0x4
    f32 m_f32ApproachVal;                            // offset 0xED8, size 0x4
    f32 m_af32ActionVal[3];                          // offset 0xEDC, size 0xC
    f32 m_f32ObstacleFrame;                          // offset 0xEE8, size 0x4
    f32 m_f32InertiaDecayFrame;                      // offset 0xEEC, size 0x4
    s32 m_s32ActionMode;                             // offset 0xEF0, size 0x4
    enum enPlayerCtrlType m_eCtrlType;               // offset 0xEF4, size 0x4
    enum enPlayerCtrlType m_eDefaultCtrlType;        // offset 0xEF8, size 0x4
    s8 m_s8BaseMotionNo;                             // offset 0xEFC, size 0x1
    u8 m_u8CurrentDrawMtxNo;                         // offset 0xEFD, size 0x1
    u8 m_u8BadTrackCnt;                              // offset 0xEFE, size 0x1
    s8 m_s8Ranking;                                  // offset 0xEFF, size 0x1
    s32 m_s32FalseStartShockFrame;                   // offset 0xF00, size 0x4
    s32 m_s32FalseStartDamageFrame;                  // offset 0xF04, size 0x4
    f32 m_f32DamageFrame;                            // offset 0xF08, size 0x4
    f32 m_f32InvincibilityFrame;                     // offset 0xF0C, size 0x4
    f32 m_f32TrapColorBallFrame;                     // offset 0xF10, size 0x4
    f32 m_f32TrapColorBallDropFrame;                 // offset 0xF14, size 0x4
    u32 m_u32TrapColorBallDropCnt;                   // offset 0xF18, size 0x4
    u32 m_u32TrapColorBallDropMaxCnt;                // offset 0xF1C, size 0x4
    f32 m_f32TrapPartsLockFrame;                     // offset 0xF20, size 0x4
    f32 m_f32EggConfettiFrame;                       // offset 0xF24, size 0x4
    f32 m_f32EggConfettiDropFrame;                   // offset 0xF28, size 0x4
    f32 m_f32NightsAtkEffectFrame;                   // offset 0xF2C, size 0x4
    f32 m_f32NightsAtkEffectDropFrame;               // offset 0xF30, size 0x4
    u32 m_u32NightsAtkEffectDropCnt;                 // offset 0xF34, size 0x4
    f32 m_f32DriftSideSign;                          // offset 0xF38, size 0x4
    f32 m_f32DriftOffsetPosturalRotate;              // offset 0xF3C, size 0x4
    f32 m_f32DriftStartSpeed;                        // offset 0xF40, size 0x4
    f32 m_f32DriftLimitSpeed;                        // offset 0xF44, size 0x4
    f32 m_f32DriftDashSpeed;                         // offset 0xF48, size 0x4
    f32 m_f32DriftHandlingRate;                      // offset 0xF4C, size 0x4
    f32 m_f32DriftFrame;                             // offset 0xF50, size 0x4
    u32 m_u32DriftDashType;                          // offset 0xF54, size 0x4
    f32 m_f32ReverseRestartCountFrame;               // offset 0xF58, size 0x4
    f32 m_f32ReverseStartCountFrame;                 // offset 0xF5C, size 0x4
    clsTask* m_apcLoopParticle[4];                   // offset 0xF60, size 0x10
    clsTask* m_apcLoopEffect[4];                     // offset 0xF70, size 0x10
    NNS_VECTORFAST m_asNodePos[8];                   // offset 0xF80, size 0x80
    f32 m_asNodeMatrix[8][4][4];                     // offset 0x1000, size 0x200
    clsBackLineEffectTask* m_pcBackLineTask;         // offset 0x1200, size 0x4
    clsVaporTrail_Task* m_pcVaporTrailTask;          // offset 0x1204, size 0x4
    clsVaporTrail_Task* m_pcSlipStreamTask;          // offset 0x1208, size 0x4
    clsWeather_Task* m_pcWeatherTask;                // offset 0x120C, size 0x4
    clsCharaVoice m_cCharaVoice;                     // offset 0x1210, size 0x10
    enum enmRet m_aeClipperRet[4];                   // offset 0x1220, size 0x10
    f32 m_of32DrawClipDistx2;                        // offset 0x1230, size 0x4
    f32 m_of32MotionClipDistx1;                      // offset 0x1234, size 0x4
    f32 m_f32CamMostDistRet;                         // offset 0x1238, size 0x4
    f32 m_f32RandMotionFrame;                        // offset 0x123C, size 0x4
    f32 m_f32RankChangeMotionFrame;                  // offset 0x1240, size 0x4
    u32 m_u32CamDelayRqType;                         // offset 0x1244, size 0x4
    f32 m_f32CamDelayRqTime;                         // offset 0x1248, size 0x4
    f32 m_f32AttackFrame;                            // offset 0x124C, size 0x4
    f32 m_f32FlightFrame;                            // offset 0x1250, size 0x4
    f32 m_f32SystemScale;                            // offset 0x1254, size 0x4
    clsModelType_OB_TX* m_opcResidenceTexModel_PS2;  // offset 0x1258, size 0x4
    u16 m_u16ReturnLineNo;                           // offset 0x125C, size 0x2
    u8 m_bForcedUpdateFlag;                          // offset 0x125E, size 0x1
    u8 m_bDrawVisible;                               // offset 0x125F, size 0x1
    u8 m_bMotionVisible;                             // offset 0x1260, size 0x1
    u8 m_bDrawFlag;                                  // offset 0x1261, size 0x1
    s8 m_s8Channel_ICS;                              // offset 0x1262, size 0x1
    s8 m_s8FollowNum;                                // offset 0x1263, size 0x1
    u8 m_u8BaseLightNo;                              // offset 0x1264, size 0x1
    u8 m_u8LightNo;                                  // offset 0x1265, size 0x1
    u8 m_u8BackUpLightNo;                            // offset 0x1266, size 0x1
    u8 m_u8BackUpFogNo;                              // offset 0x1267, size 0x1
    s8 m_s8OldPathNo;                                // offset 0x1268, size 0x1
    u8 m_bDisableFog;                                // offset 0x1269, size 0x1
    s8 m_s8CameraNo;                                 // offset 0x126A, size 0x1
    s8 m_s8ViewNo;                                   // offset 0x126B, size 0x1
    u8 m_u8JumpCount;                                // offset 0x126C, size 0x1
    s8 m_s8CurAttackTarget;                          // offset 0x126D, size 0x1
    f32 m_f32Attack_Speed;                           // offset 0x1270, size 0x4
    f32 m_f32Attack_Accele;                          // offset 0x1274, size 0x4
    f32 m_f32Attack_SpeedRate;                       // offset 0x1278, size 0x4
    enum enmAttackLR m_eTargetSide;                  // offset 0x127C, size 0x4
    u8 m_bDamageFlag;                                // offset 0x1280, size 0x1
    clsBaseEffect_Task* m_pcDmgEffectTask;           // offset 0x1284, size 0x4
    clsBaseEffect_Task* m_pcDmgEffectTask2;          // offset 0x1288, size 0x4
    u8 m_bIsAttackDmgScale;                          // offset 0x128C, size 0x1
    f32 m_f32AttackDmgScale;                         // offset 0x1290, size 0x4
    s32 m_s32SuperSonic;                             // offset 0x1294, size 0x4
    enum enmComType m_eComType;                      // offset 0x1298, size 0x4
    f32 m_f32BoostAttackFrame;                       // offset 0x129C, size 0x4
    f32 m_f32GpRateEffectCnt;                        // offset 0x12A0, size 0x4
    f32 m_f32TrickXNegaWaitFrame;                    // offset 0x12A4, size 0x4
    u8 m_bTrickXNegaFlg;                             // offset 0x12A8, size 0x1
    s32 m_s32GoalMotionRequest;                      // offset 0x12AC, size 0x4
    clsLimitTime m_cRingLimitTime;                   // offset 0x12B0, size 0x14
    clsLimitTime m_cRingGravityLimitTime;            // offset 0x12C4, size 0x14
    f32 m_f32ItemFrame;                              // offset 0x12D8, size 0x4
    s32 m_s32ReplayCamIdx;                           // offset 0x12DC, size 0x4
    s32 m_s32AutoWallRunPathNo;                      // offset 0x12E0, size 0x4
    clsDashPanel_Obj* m_pcDashPanel;                 // offset 0x12E4, size 0x4
    clsEggConfetti* m_pcEggConfetti;                 // offset 0x12E8, size 0x4
    clsNightsAtkEffect* m_pcNightsAtkEffect;         // offset 0x12EC, size 0x4
};

#endif // PLAYER_HPP
