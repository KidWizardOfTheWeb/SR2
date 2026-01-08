#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearCtrl.hpp"
// total size: 0xC
class NNS_ROTATE_A32 {
    // Members
public:
    signed int x; // offset 0x0, size 0x4
    signed int y; // offset 0x4, size 0x4
    signed int z; // offset 0x8, size 0x4
};
// total size: 0x80
class clsOOSystem {
    // Members
public:
    enum enmSoundMode m_eSoundMode; // offset 0x4, size 0x4
    enum enmLanguage m_eMessageLanguage; // offset 0x8, size 0x4
    enum enmLanguage m_eVoiceLanguage; // offset 0xC, size 0x4
    float m_f32FrameRate; // offset 0x10, size 0x4
    float m_f32FrameRateAdd; // offset 0x14, size 0x4
    float m_f32FrameRateAdd2; // offset 0x18, size 0x4
    float m_f32FrameRateAddCount; // offset 0x1C, size 0x4
    float m_f32FrameRateAddCount2; // offset 0x20, size 0x4
    signed int m_s32FrameRateMaxMicroSec; // offset 0x24, size 0x4
    unsigned int m_u32VblankCnt; // offset 0x28, size 0x4
    unsigned int m_u32VblankCntOld; // offset 0x2C, size 0x4
    unsigned int m_u32GameCnt; // offset 0x30, size 0x4
    unsigned int m_eState; // offset 0x34, size 0x4
    class stcViewRect * m_apsViewRect[5]; // offset 0x38, size 0x14
    class stcScissorRect * m_apsScissorRect[5]; // offset 0x4C, size 0x14
    class stcScissorRect * m_apsScissorRect_NTSC[5]; // offset 0x60, size 0x14
    unsigned char m_u8FrameRateDef; // offset 0x74, size 0x1
    unsigned char m_u8VblankNum; // offset 0x75, size 0x1
    signed char m_s8ViewportNum; // offset 0x76, size 0x1
    signed char m_s8BackUpViewportNum; // offset 0x77, size 0x1
    signed char m_s8MaxViewportNum; // offset 0x78, size 0x1
    unsigned char m_bPause; // offset 0x79, size 0x1
    unsigned char m_bUnPause; // offset 0x7A, size 0x1
    unsigned char m_bEnablePauseWorks; // offset 0x7B, size 0x1
    unsigned char m_bDisablePauseCancel; // offset 0x7C, size 0x1
    unsigned char m_bDisablePauseDraw; // offset 0x7D, size 0x1
    unsigned char m_bNextPause; // offset 0x7E, size 0x1
};
// total size: 0x4
class clsSingleton {};
// total size: 0x84
class clsPfSystem : public clsSingleton, public clsOOSystem {};
// total size: 0x10
class NNS_VECTORFAST {
    // Members
public:
    float x; // offset 0x0, size 0x4
    float y; // offset 0x4, size 0x4
    float z; // offset 0x8, size 0x4
    float w; // offset 0xC, size 0x4
};
// total size: 0x30
class stcTask {
    // Members
public:
    class clsBaseRace_Task * pcBaseRace; // offset 0x0, size 0x4
    class clsPlayerTask * apcPlayer[8]; // offset 0x4, size 0x20
    class clsBaseStage_Task * pcBaseStage; // offset 0x24, size 0x4
    class clsScript_Task * pcBaseScript; // offset 0x28, size 0x4
    class clsScore2D_Task * pcScore2D; // offset 0x2C, size 0x4
};
// total size: 0x10
class NNS_MATRIXSTACK {
    // Members
public:
    unsigned int nMtx; // offset 0x0, size 0x4
    unsigned int StackIdx; // offset 0x4, size 0x4
    float (* pStackTop)[4][4]; // offset 0x8, size 0x4
    float (* pCurrent)[4][4]; // offset 0xC, size 0x4
};
class NNS_VECTOR {
    // Members
public:
    float x; // offset 0x0, size 0x4
    float y; // offset 0x4, size 0x4
    float z; // offset 0x8, size 0x4
};
// total size: 0x10
class Fuid {
    // Members
public:
    unsigned int m_0; // offset 0x0, size 0x4
    unsigned int m_1; // offset 0x4, size 0x4
    unsigned int m_2; // offset 0x8, size 0x4
    unsigned int m_3; // offset 0xC, size 0x4
};
/*
    Compile unit: C:\Develop\Projects\SR2\pgm\src\Object\Player\Gear\GearChildren.cpp
    Producer: MW MIPS C Compiler
    Language: C++
*/
static unsigned char g_au8ParticleTextureDrawType[8]; // size: 0x8, address: 0x0
static unsigned char g_au8ParticleConfigDrawType[8]; // size: 0x8, address: 0x0
static class NNS_VECTORFAST g_tosTestVelocity; // size: 0x10, address: 0x0
// total size: 0x4C
struct /* @anon7 */ {} __vt__19clsGearSpGpInfinity; // size: 0x4C, address: 0x6BDD70
// total size: 0x44
struct /* @anon9 */ {} __vt__7clsGear; // size: 0x44, address: 0x6BC6E0
// total size: 0x4C
struct /* @anon12 */ {} __vt__16clsGearBaseParts; // size: 0x4C, address: 0x6C3C20
// total size: 0x4C
struct /* @anon14 */ {} __vt__19clsGearPtnModelPart; // size: 0x4C, address: 0x6C3870
class clsTaskManager * m_tpcSingletonTaskManager; // size: 0x4, address: 0x6E69D0
unsigned int * tpsNnNodeStatus; // size: 0x4, address: 0x707DF8
class clsPfSystem * m_tpcSingletonPfSystem; // size: 0x4, address: 0x6E69B8
class clsGameMgr * m_tpcSingletonGameMgr; // size: 0x4, address: 0x6E6980
class stcTask sTask; // size: 0x30, address: 0xB0A900
class clsMagBarrier_Task * m_tpcSingleton; // size: 0x4, address: 0xB0B8C0
signed char aos8ChangeRingTbl[18][4]; // size: 0x48, address: 0x68FA60
class NNS_MATRIXSTACK tsNnMtxStack; // size: 0x10, address: 0x707DD0
float (* tpsNnMtxPal)[4][4]; // size: 0x4, address: 0x707DF0
// total size: 0x4C
struct /* @anon8 */ {} __vt__17clsGearSpThrottle; // size: 0x4C, address: 0x6BDDC0
// total size: 0x4C
struct /* @anon17 */ {} __vt__20clsGearPtnEffectPart; // size: 0x4C, address: 0x6C3820
// total size: 0x4C
struct /* @anon10 */ {} __vt__18clsGearSpSpeedTrap; // size: 0x4C, address: 0x6BDE10
// total size: 0x4C
struct /* @anon16 */ {} __vt__17clsGearSpCtrlTrap; // size: 0x4C, address: 0x6BDE60
// total size: 0x4C
struct /* @anon3 */ {} __vt__17clsGearSpViewTrap; // size: 0x4C, address: 0x6BDEB0
// total size: 0x4C
struct /* @anon1 */ {} __vt__19clsGearSpMagBarrier; // size: 0x4C, address: 0x6BDF00
// total size: 0x4C
struct /* @anon5 */ {} __vt__13clsGearSpTank; // size: 0x4C, address: 0x6BDF50
// total size: 0x7C
struct /* @anon19 */ {} __vt__25clsGearAngelOrDevilChange; // size: 0x7C, address: 0x6BDFA0
// total size: 0x7C
struct /* @anon13 */ {} __vt__20clsGearBasePrototype; // size: 0x7C, address: 0x6C3BA0
// total size: 0x7C
struct /* @anon18 */ {} __vt__17clsGearPtnAirride; // size: 0x7C, address: 0x6BCC00
// total size: 0x7C
struct /* @anon2 */ {} __vt__19clsGearAngelOrDevil; // size: 0x7C, address: 0x6BE020
// total size: 0x7C
struct /* @anon4 */ {} __vt__18clsGearReserveTank; // size: 0x7C, address: 0x6BE0A0
// total size: 0x7C
struct /* @anon6 */ {} __vt__14clsGearPtnBike; // size: 0x7C, address: 0x6BCC80
// total size: 0x7C
struct /* @anon11 */ {} __vt__15clsGearThrottle; // size: 0x7C, address: 0x6BE120
// total size: 0x7C
struct /* @anon0 */ {} __vt__15clsGearPtnBoard; // size: 0x7C, address: 0x6BCB80
// total size: 0x7C
struct /* @anon15 */ {} __vt__10clsGearMag; // size: 0x7C, address: 0x6BE1A0
static float FLYACTION_DESCENT_PITCH_GRAVITY; // size: 0x4, address: 0x0
static float FLYACTION_FALL_PITCH_GRAVITY; // size: 0x4, address: 0x0
static float FLYACTION_DEFAULT_PITCH_GRAVITY; // size: 0x4, address: 0x0
static float FLYACTION_MIN_PITCH; // size: 0x4, address: 0x0
static float FLYACTION_MAX_PITCH; // size: 0x4, address: 0x0
static float FLYACTION_LEFT_RIGHT_ROT; // size: 0x4, address: 0x0
static float FLYACTION_UP_DOWN_ROT; // size: 0x4, address: 0x0
static float toaf32GpUsedRate[5]; // size: 0x14, address: 0x0
static float toaf32ItemBox[3]; // size: 0xC, address: 0x0
static float toaf32BonusGLink[3]; // size: 0xC, address: 0x0
static float toaf32BonusPower[6]; // size: 0x18, address: 0x0
static float toaf32BonusFly[3]; // size: 0xC, address: 0x0
static float toaf32BonusSpeed[3]; // size: 0xC, address: 0x0
static float toaf32BonusTrick[7]; // size: 0x1C, address: 0x0
enum enmRet aoeRet[3]; // size: 0xC, address: 0x655000
static unsigned char ChkComUseData[1]; // size: 0x1, address: 0x0
static unsigned char ChkCourseUseData[1]; // size: 0x1, address: 0x0
static unsigned char chk__enum__enmMotion_nakawatari_SizeOver[1]; // size: 0x1, address: 0x0
static unsigned char chk__enum__notSkateModelType_nakawatari_NotEqual[1]; // size: 0x1, address: 0x0
static unsigned char chk__enum__enmMotionType_nakawatari_SizeOver[1]; // size: 0x1, address: 0x0
static unsigned char chk__enum__enmLevel_nakawatari_SizeOver[1]; // size: 0x1, address: 0x0
static float tosUnitMatrix[4][4]; // size: 0x40, address: 0x0
static class NNS_VECTOR tosUnitScaleVec; // size: 0xC, address: 0x0
static class NNS_VECTOR tosZVec; // size: 0xC, address: 0x0
static class NNS_VECTOR tosYVec; // size: 0xC, address: 0x0
static class NNS_VECTOR tosXVec; // size: 0xC, address: 0x0
static class NNS_VECTOR tosZeroVec; // size: 0xC, address: 0x0
static class NNS_VECTORFAST tosUnitScaleVecFast; // size: 0x10, address: 0x0
static class NNS_VECTORFAST tosZVecFast; // size: 0x10, address: 0x0
static class NNS_VECTORFAST tosYVecFast; // size: 0x10, address: 0x0
static class NNS_VECTORFAST tosXVecFast; // size: 0x10, address: 0x0
static class NNS_VECTORFAST tosZeroVecFast; // size: 0x10, address: 0x0
unsigned int oau32DebugColor[16]; // size: 0x40, address: 0x655010
char * oapc8Str[2]; // size: 0x8, address: 0x5F2198
char * oapc8Str[2]; // size: 0x8, address: 0x0
char * oapc8Str[2]; // size: 0x8, address: 0x0
char * oapc8Str[2]; // size: 0x8, address: 0x5F21B0
unsigned char oau8Mask[2]; // size: 0x2, address: 0x0
unsigned short oau16Mask[2]; // size: 0x4, address: 0x0
unsigned int oau32Mask[2]; // size: 0x8, address: 0x655050
unsigned int oau32Col[2]; // size: 0x8, address: 0x655058
class Fuid fuid; // size: 0x10, address: 0x0
// total size: 0x14
class __cdeque_deleter : public __cdeque_deleter_common {};
enum enmColCheckType {
    COL_CHECK_NULL = 0,
    COL_CHECK_NORMAL = 1,
    COL_CHECK_CHARA_UP = 2,
    COL_CHECK_UNDER = 3,
    COL_CHECK_VELOCITY = 4,
};
// total size: 0x14
class __list_imp : private __list_deleter {};
// total size: 0x8
class hkCdPointCollector {
    // Members
public:
    float m_earlyOutDistance; // offset 0x4, size 0x4
};
// total size: 0x90
class NNS_NODE {
    // Members
public:
    unsigned int fType; // offset 0x0, size 0x4
    signed short iMatrix; // offset 0x4, size 0x2
    signed short iParent; // offset 0x6, size 0x2
    signed short iChild; // offset 0x8, size 0x2
    signed short iSibling; // offset 0xA, size 0x2
    class NNS_VECTOR Translation; // offset 0xC, size 0xC
    class NNS_ROTATE_A32 Rotation; // offset 0x18, size 0xC
    class NNS_VECTOR Scaling; // offset 0x24, size 0xC
    float InvInitMtx[4][4]; // offset 0x30, size 0x40
    class NNS_VECTOR Center; // offset 0x70, size 0xC
    float Radius; // offset 0x7C, size 0x4
    unsigned int User; // offset 0x80, size 0x4
    union { // inferred
        float SIIKBoneLength; // offset 0x84, size 0x4
        float BoundingBoxX; // offset 0x84, size 0x4
    };
    float BoundingBoxY; // offset 0x88, size 0x4
    float BoundingBoxZ; // offset 0x8C, size 0x4
};
// total size: 0x2
class hkConstraintAtom {
    // Members
public:
    class hkEnum m_type; // offset 0x0, size 0x2
};

// total size: 0x4
class hkPadSpu {
    // Members
public:
    class PotentialInfo * m_storage; // offset 0x0, size 0x4
};
// total size: 0x8
class compressed_pair_imp {
    // Members
public:
    class clsOOStlAllocator first_; // offset 0x0, size 0x4
    unsigned int second_; // offset 0x4, size 0x4
};
// total size: 0x7C
struct /* @anon0 */ {};

// total size: 0xC
class __vector_imp : private __vector_pod, private compile_assert {};
// total size: 0x8
class compressed_pair_imp {
    // Members
public:
    class clsOOStlAllocator first_; // offset 0x0, size 0x4
    unsigned int second_; // offset 0x4, size 0x4
};
// total size: 0x4C
struct /* @anon1 */ {};
// total size: 0x80
class clsGearAngelOrDevilChange : public clsGearPtnAirride {
    // Members
public:
    enum enmDraw2DType m_eDraw2DType; // offset 0x60, size 0x4
    unsigned int m_u32SelectNo; // offset 0x64, size 0x4
    float m_f32SelectFrame; // offset 0x68, size 0x4
    enum enmType m_eType; // offset 0x6C, size 0x4
    class clsModelType_OB_TX * m_apcModel[3]; // offset 0x70, size 0xC
};
// total size: 0x4
class hkPhantomListener {};
// total size: 0x30
class stcSeed {
    // Members
public:
    class NNS_VECTOR sPosVec; // offset 0x0, size 0xC
    class NNS_VECTOR sScale; // offset 0xC, size 0xC
    class NNS_VECTOR sSpeedVec; // offset 0x18, size 0xC
    float f32Gravity; // offset 0x24, size 0x4
    signed int s32Frame; // offset 0x28, size 0x4
    signed int s32Rot; // offset 0x2C, size 0x4
};
// total size: 0x70
class clsMagBarrier_Obj : public clsGimmickObj {
    // Members
public:
    enum enmMode m_eMode; // offset 0x50, size 0x4
    class clsPlayerTask * m_pcPlayer; // offset 0x54, size 0x4
    class hkSimpleShapePhantom * m_pcPhantom; // offset 0x58, size 0x4
    float m_f32Scale; // offset 0x5C, size 0x4
    unsigned int m_u32NodeNo; // offset 0x60, size 0x4
    unsigned char m_bInfinity; // offset 0x64, size 0x1
    class clsFrameControl m_cFrameControl; // offset 0x68, size 0x8
};
// total size: 0x8
class sceGsTex0 {
    // Members
public:
    unsigned long TBP0 : 14; // offset 0x0, size 0x4
    unsigned long TBW : 6; // offset 0x0, size 0x4
    unsigned long PSM : 6; // offset 0x0, size 0x4
    unsigned long TW : 4; // offset 0x0, size 0x4
    unsigned long TH : 4; // offset 0x0, size 0x4
    unsigned long TCC : 1; // offset 0x0, size 0x4
    unsigned long TFX : 2; // offset 0x0, size 0x4
    unsigned long CBP : 14; // offset 0x0, size 0x4
    unsigned long CPSM : 4; // offset 0x0, size 0x4
    unsigned long CSM : 1; // offset 0x0, size 0x4
    unsigned long CSA : 5; // offset 0x0, size 0x4
    unsigned long CLD : 3; // offset 0x0, size 0x4
};
// total size: 0x4
class hkPadSpu {
    // Members
public:
    class hkConvexListFilter * m_storage; // offset 0x0, size 0x4
};
// total size: 0x70
class hkSimulationIsland : public hkConstraintOwner {
    // Members
public:
    class hkWorld * m_world; // offset 0x18, size 0x4
    signed int m_numConstraints; // offset 0x1C, size 0x4
    unsigned short m_storageIndex; // offset 0x20, size 0x2
    unsigned short m_dirtyListIndex; // offset 0x22, size 0x2
    unsigned char m_splitCheckFrameCounter; // offset 0x24, size 0x1
    unsigned char m_highFrequencyDeactivationCounter; // offset 0x25, size 0x1
    unsigned char m_lowFrequencyDeactivationCounter; // offset 0x26, size 0x1
    unsigned char m_splitCheckRequested : 2; // offset 0x27, size 0x1
    unsigned char m_sparseEnabled : 2; // offset 0x27, size 0x1
    unsigned char m_actionListCleanupNeeded : 2; // offset 0x27, size 0x1
    unsigned char m_allowIslandLocking : 2; // offset 0x27, size 0x1
    unsigned char m_isInActiveIslandsArray : 2; // offset 0x28, size 0x1
    unsigned char m_active : 2; // offset 0x28, size 0x1
    unsigned char m_inIntegrateJob : 2; // offset 0x28, size 0x1
    class hkMultiThreadCheck m_multiThreadCheck; // offset 0x2C, size 0x8
    float m_timeSinceLastHighFrequencyCheck; // offset 0x34, size 0x4
    float m_timeSinceLastLowFrequencyCheck; // offset 0x38, size 0x4
    class hkArray m_actions; // offset 0x3C, size 0xC
    float m_timeOfDeactivation; // offset 0x48, size 0x4
    class hkInplaceArray m_entities; // offset 0x4C, size 0x10
    class hkAgentNnTrack m_agentTrack; // offset 0x5C, size 0x14
};
// total size: 0x50
class clsGearSpSpeedTrap : public clsGearPtnEffectPart {};
// total size: 0x0
class hkWorldMemoryWatchDog {};
// total size: 0x4
class clsSpinTrickAction : public clsBaseTrickAction {};
enum enm {
    NONE = -1,
    CHARA_0 = 0,
    ENTRY_CHARA_1 = 1,
    CHARA_SUPER_SONIC_MODEL_3 = 3,
    GEAR_10 = 10,
    ENTRY_GEAR_11 = 11,
    MAP_100 = 100,
    MAP_MISSION_101 = 101,
    MAP_SURVIVALBALL_102 = 102,
    MAP_TUTORIAL_103 = 103,
    MAP_SURVIVALBATTLE_104 = 104,
    MAP_SURVIVALRELAY_105 = 105,
    REFLECT_MAP_110 = 110,
    REFLECT_DIVMAP_111 = 111,
    MAP_BURN_LIGHT_150 = 150,
    SKY_200 = 200,
    SKY_THUNDER_250 = 250,
    START_CAMERA_MOTION_300 = 300,
    START_CAMERA_MOTION_301 = 301,
    SET_DATA_1000 = 1000,
    MISSION_DATA_1010 = 1010,
    TUTORIAL_DATA_1011 = 1011,
    GAME_2D_1020 = 1020,
    GAME_2D_1025 = 1025,
    GAME_2D_1026 = 1026,
    GAME_2D_1027 = 1027,
    MISSION_2D_1028 = 1028,
    SUVIVALBALL_2D_1029 = 1029,
    TUTORIAL_2D_1030 = 1030,
    NETRANKING_2D_1031 = 1031,
    SUVIVALBATTLE_2D_1032 = 1032,
    TIMEATTACK_2D_1033 = 1033,
    SURVIVALMESSAGE_2D_1034 = 1034,
    SUVIVALBATTLE_MAP2D_1035 = 1035,
    MISSION_STAGE_2D_1036 = 1036,
    ETC_BINARY_STAGE_DATA_1050 = 1050,
    OBJ_PORTAL_1090 = 1090,
    PATH__PLAYER_1100 = 1100,
    PATH__GIMMICK_1101 = 1101,
    PATH__RAIL_1102 = 1102,
    PATH__TRICK_1103 = 1103,
    PATH__GRAVITY_1104 = 1104,
    PATH__RANK_1105 = 1105,
    PATH__DIVE_1106 = 1106,
    PATH__COURSE_1110 = 1110,
    PATH__COM_1111 = 1111,
    TUTORIAL_GHOST_1200 = 1200,
    SET_SE_3D_1900 = 1900,
    SET_SE_2D_1901 = 1901,
    START_GIMMICK = 2000,
    START_UNION_GIMMICK = 2000,
    RING_2000 = 2000,
    ITEM_BOX_2010 = 2010,
    ITEM_BOX_AIR_2011 = 2011,
    DASH_PANEL_2020 = 2020,
    SPRING_2030 = 2030,
    DASH_RING_2040 = 2040,
    START_GATE_2050 = 2050,
    GOAL_LINE_2060 = 2060,
    TYPE_2070 = 2070,
    PT_DOOR_2080 = 2080,
    PT_DOOR_2081 = 2081,
    PT_ONLY_2082 = 2082,
    PUT_FIXEDOBJECT_2090 = 2090,
    PUT_FIXEDMOTOBJ_2091 = 2091,
    PUT_FIXEDMOTMATOBJ_2092 = 2092,
    PUT_FIXEDBURNOBJ_2093 = 2093,
    PUT_FIXEDMATOBJ_2094 = 2094,
    PUT_GRAVITYOBJ_2100 = 2100,
    PUT_MATMOTGOBJ_2101 = 2101,
    PUT_GRAVITYOBJ2_2102 = 2102,
    PUT_PARALLAX_2103 = 2103,
    PUT_GRAVITYOBJ3_2104 = 2104,
    PUT_ARROW_2105 = 2105,
    PUT_MOTIONOBJ_2110 = 2110,
    WALL_OBJ_2120 = 2120,
    CATAPULT_2130 = 2130,
    PATH_GARVITYOBJ_2140 = 2140,
    GRAVITY_RING_2150 = 2150,
    HIDE_KICKER_2160 = 2160,
    WALL_GIMMICK_2170 = 2170,
    PLAY_AROUND_SE_2180 = 2180,
    ADJUST_GCTRL_2190 = 2190,
    PLAY_LOOP_SE_2200 = 2200,
    AUTO_WALLRUN_2210 = 2210,
    MAG_BARRIRER_2220 = 2220,
    RAIL_WAY_START_2230 = 2230,
    RAIL_WAY_END_2231 = 2231,
    SPEED_DOWN_2240 = 2240,
    END_UNION_GIMMICK = 2241,
    START_GIMMICK_ST00 = 10000,
    END_GIMMICK_ST00 = 10001,
    START_GIMMICK_ST01 = 11000,
    ST01_PATH_CAR_11000 = 11000,
    ST01_PUT_CAR_11010 = 11010,
    ST01_PATH_TRAIN_11040 = 11040,
    ST01_PRODUCTION_ROBO_11050 = 11050,
    ST01_SECURITY_ROBO_11060 = 11060,
    ST01_TAXI_11080 = 11080,
    ST01_CHAIR_A_11190 = 11190,
    ST01_CHAIR_B_11191 = 11191,
    ST01_GARBAGE_BOX_11192 = 11192,
    ST01_GUIDE_BOARD_11193 = 11193,
    ST01_CONE_11194 = 11194,
    ST01_GLINK_TRAIN_11200 = 11200,
    ST01_GLINK_TRAIN_OBJECT_11201 = 11201,
    ST01_TURB_COL_11210 = 11210,
    ST01_GCTRL_TRAIN_11220 = 11220,
    ST01_GCTRL_TRAIN_OBJECT_11221 = 11221,
    END_GIMMICK_ST01 = 11222,
    START_GIMMICK_ST02 = 12000,
    ST02_IVY_12000 = 12000,
    ST02_BEE_ROBO_12010 = 12010,
    ST02_KUKI_12020 = 12020,
    ST02_PLANT_12030 = 12030,
    ST02_PLANT_12031 = 12031,
    ST02_SIDA_12040 = 12040,
    ST02_PATH_BEE_12050 = 12050,
    ST02_BUTTERFLY_12060 = 12060,
    ST02_RUN_BEE_12070 = 12070,
    END_GIMMICK_ST02 = 12071,
    START_GIMMICK_ST03 = 13000,
    ST03_COGWHEEL_13000 = 13000,
    ST03_PRESS_13010 = 13010,
    ST03_EXTRALAMP_13020 = 13020,
    ST03_PUT_ROBO_13030 = 13030,
    ST03_PUT_CONTAINER_13040 = 13040,
    ST03_SECURITY_GATE_13050 = 13050,
    ST03_POWER_BREAK_13060 = 13060,
    ST03_MACROSS_13070 = 13070,
    ST03_PATH_ROBO_13090 = 13090,
    END_GIMMICK_ST03 = 13091,
    START_GIMMICK_ST04 = 14000,
    ST04_AUTORUN_CANOE_14000 = 14000,
    ST04_GLINK_WATERSPHERE_14010 = 14010,
    ST04_FOUNTAIN_14020 = 14020,
    ST04_STRAIGHT_FOUNTAIN_14030 = 14030,
    ST04_PATH_CANOE_14040 = 14040,
    ST04_WATER_TURBULENCE_14050 = 14050,
    ST04_PUT_CANOE_14060 = 14060,
    ST04_SMALL_WATERSPHERE_14070 = 14070,
    END_GIMMICK_ST04 = 14071,
    START_GIMMICK_ST05 = 15000,
    ST05_ROT_GROUND_15000 = 15000,
    ST05_ROT_FALL_MANAGER_15010 = 15010,
    ST05_ROT_FALL_OBJECT_15011 = 15011,
    ST05_FIRE_15020 = 15020,
    ST05_SPAIN_15030 = 15030,
    ST05_DOMINO_15040 = 15040,
    ST05_ROT_FALL_GLINK_MANAGER_15050 = 15050,
    ST05_ROT_FALL_GLINK_OBJECT_15051 = 15051,
    ST05_DETENTION_15060 = 15060,
    ST05_BREAK_RAILING_15070 = 15070,
    END_GIMMICK_ST05 = 15071,
    START_GIMMICK_ST06 = 16000,
    ST06_SURVEILLANCE_CAMERA_16000 = 16000,
    ST06_BLOCKADEOBJ_16010 = 16010,
    ST06_LASER_16020 = 16020,
    ST06_GLINK_ELEVATOR_16030 = 16030,
    ST06_ELEVATOR_16040 = 16040,
    END_GIMMICK_ST06 = 16041,
    START_GIMMICK_ST07 = 17000,
    ST07_FLOOR_S_17000 = 17000,
    ST07_FLOOR_B_17001 = 17001,
    ST07_FLOOR_SWITCH_17002 = 17002,
    ST07_FLOOR_CHANGE_17003 = 17003,
    ST07_FLOOR_KICKER_17004 = 17004,
    ST07_FLOOR_GRAVITY_17005 = 17005,
    ST07_FLOOR_GLINK_17006 = 17006,
    ST07_JOINT00_17010 = 17010,
    ST07_JOINT01_17011 = 17011,
    ST07_JOINT02_17012 = 17012,
    ST07_JOINT03_17013 = 17013,
    ST07_GUARDRAIL00_17020 = 17020,
    ST07_GUARDRAIL01_17021 = 17021,
    ST07_GIMMICKWALL00_17030 = 17030,
    ST07_GIMMICKWALL01_17031 = 17031,
    ST07_GATE_17050 = 17050,
    ST07_WALL_THROUGH_17060 = 17060,
    ST07_POWER_BREAK_17070 = 17070,
    ST07_SOLAR_17080 = 17080,
    END_GIMMICK_ST07 = 17081,
    START_GIMMICK_ST08 = 18000,
    ST08_ROAD_18000 = 18000,
    ST08_ROAD_SIGNAL_18010 = 18010,
    ST08_ROAD_CAR_18020 = 18020,
    ST08_ROAD_GLINK_BUS_18030 = 18030,
    ST08_ROAD_TRAILER_18040 = 18040,
    ST08_ROAD_CONTAINER_18041 = 18041,
    ST08_UFOCATCHER_18050 = 18050,
    ST08_FZONE_ENEMY_18060 = 18060,
    END_GIMMICK_ST08 = 18061,
    START_GIMMICK_ST09 = 19000,
    END_GIMMICK_ST09 = 19001,
    START_GIMMICK_ST10 = 20000,
    ST10_SNOWBALL_20010 = 20010,
    ST10_FALL_SNOWBALL_20020 = 20020,
    ST10_SNOWMAN_20030 = 20030,
    ST10_LIFT_20040 = 20040,
    END_GIMMICK_ST10 = 20041,
    START_GIMMICK_ST11 = 21000,
    ST11_ENERGY_CYLINDER_21000 = 21000,
    ST11_FSECURITY_GATE_21010 = 21010,
    ST11_PATH_SECURITY_ROBO_21020 = 21020,
    ST11_FAN_21030 = 21030,
    ST11_CRANE_21040 = 21040,
    ST11_GLINK_CYLINDER_21050 = 21050,
    ST11_LINE_OBJ_21060 = 21060,
    END_GIMMICK_ST11 = 21061,
    START_GIMMICK_ST12 = 22000,
    ST12_GLINK_BRIDGE_22010 = 22010,
    ST12_PUT_CANOE_22020 = 22020,
    ST12_PATH_CANOE_22030 = 22030,
    ST12_MOTIONOBJ_22040 = 22040,
    END_GIMMICK_ST12 = 22041,
    START_GIMMICK_ST13 = 23000,
    ST13_BUNKI_23010 = 23010,
    ST13_CATAPULT_23020 = 23020,
    ST13_COLOSSUS_23030 = 23030,
    ST13_GLINK_COLOSSUS_23040 = 23040,
    ST13_BRIDGE_23050 = 23050,
    ST13_GATE_23060 = 23060,
    ST13_PILLAR_23070 = 23070,
    ST13_PT_OBJ_23080 = 23080,
    ST13_HIKARI_23090 = 23090,
    ST13_SIGNBOARD_23100 = 23100,
    ST13_SIGNBOARD_B_23110 = 23110,
    ST13_PT_WALL_23120 = 23120,
    END_GIMMICK_ST13 = 23121,
    START_GIMMICK_ST14 = 24000,
    ST14_FAN_24000 = 24000,
    ST14_OBJ_CRANE_24010 = 24010,
    ST14_LASER_24020 = 24020,
    ST14_BIG_FAN_24030 = 24030,
    ST14_STEEL_FRAME_24040 = 24040,
    END_GIMMICK_ST14 = 24041,
    START_GIMMICK_ST15 = 25000,
    ST15_CORE_BASE_25000 = 25000,
    ST15_FUSION_MACHINE_25010 = 25010,
    ST15_ENERGY_BULLET_25020 = 25020,
    ST15_METEORITE_L_25030 = 25030,
    ST15_METEORITE_S_25040 = 25040,
    ST15_BLACK_HOLE_25050 = 25050,
    ST15_GLINK_FLOOR_BOARD_25060 = 25060,
    ST15_BREAK_FLOOR_25070 = 25070,
    ST15_FLOATING_METEORITE_25080 = 25080,
    ST15_FLOATING_METEO_TRIG_25090 = 25090,
    ST15_SAFE_TRAMPOLINE_25100 = 25100,
    END_GIMMICK_ST15 = 25101,
    START_GIMMICK_ST16 = 26000,
    ST16_HELICOPTER_26000 = 26000,
    ST16_HELICOPTER_OBJ_26001 = 26001,
    ST16_GLINK_SIGNBOARD_26010 = 26010,
    ST16_BREAK_SIGNBOARD_26020 = 26020,
    ST16_AUTORUN_HELI_26030 = 26030,
    END_GIMMICK_ST16 = 26031,
    START_GIMMICK_MISSION = 27000,
    MISSION_PATH_TARGET_27000 = 27000,
    MISSION_TIME_GATE_27010 = 27010,
    MISSION_MARK_27011 = 27011,
    MISSION_PATH_ROBO_27020 = 27020,
    MISSION_FIXED_LINK_27030 = 27030,
    MISSION_GLINK_COLOSSUS_27040 = 27040,
    END_GIMMICK_MISSION = 27041,
    START_GIMMICK_SURVIVALBALL = 28000,
    SURVIVALBALL_GOALRING_28000 = 28000,
    SURVIVALBALL_BALL_28010 = 28010,
    SURVIVALBALL_POLE_28020 = 28020,
    SURVIVALBALL_START_28030 = 28030,
    SURVIVALBALL_PUT_OBJ_28040 = 28040,
    END_GIMMICK_SURVIVALBALL = 28041,
    START_GIMMICK_SURVIVALRELAY = 28500,
    SURVIVALRELAY_WALKRUN_28500 = 28500,
    END_GIMMICK_SURVIVALRELAY = 28501,
    START_GIMMICK_SURVIVALBATTLE = 29000,
    SURVIVALBATTLE_MISSILE_29000 = 29000,
    SURVIVALBATTLE_BOMB_29010 = 29010,
    SURVIVALBATTLE_BLOCK_29020 = 29020,
    SURVIVALBATTLE_POLE_29030 = 29030,
    SURVIVALBATTLE_BARRIER_29040 = 29040,
    SURVIVALBATTLE_EXPLOSION_29050 = 29050,
    END_GIMMICK_SURVIVALBATTLE = 29051,
    END_GIMMICK = 29052,
    EFFECT_30000 = 30000,
    EFFECT_GRAVITY_30010 = 30010,
    EFFECT_GRAVITY_30020 = 30020,
    EFFECT_GRAVITY2_30021 = 30021,
    EFFECT_SUNLENZ_30030 = 30030,
    EFFECT_LANDING_30040 = 30040,
    EFFECT_CURVEAIR_30050 = 30050,
    EFFECT_CRASH_30060 = 30060,
    EFFECT_DASH_30070 = 30070,
    EFFECT_GETAGP_30080 = 30080,
    EFFECT_FLLWLINE_30090 = 30090,
    EFFECT_CRASHC_30100 = 30100,
    EFFECT_BADTRK_30110 = 30110,
    EFFECT_GEARCH01_30120 = 30120,
    EFFECT_GEARCH02_30130 = 30130,
    EFFECT_GEARCH03_30140 = 30140,
    EFFECT_GEARCHRT_30150 = 30150,
    EFFECT_FALSESTART00_30170 = 30170,
    EFFECT_FALSESTART01_30180 = 30180,
    EFFECT_GCTRL_00_30190 = 30190,
    EFFECT_GCTRL_01_30200 = 30200,
    EFFECT_GCTRL_02_30210 = 30210,
    EFFECT_MIST_30230 = 30230,
    EFFECT_ST02_SIDARIDE_30240 = 30240,
    EFFECT_ST01_ROBOCURV_30250 = 30250,
    EFFECT_MINIWAVE_30260 = 30260,
    EFFECT_BACKRIBBON_30270 = 30270,
    EFFECT_GIMICKLINE_30280 = 30280,
    EFFECT_LANDINGWATERTRICK_30290 = 30290,
    EFFECT_LANDINGWATERTRICK_30300 = 30300,
    EFFECT_WAVYTEXTURE_30310 = 30310,
    EFFECT_ST11_DISELECTRIC_30320 = 30320,
    EFFECT_REFRECT_PLANE_START_30330 = 30330,
    EFFECT_REFRECT_PLANE_END_30339 = 30339,
    EFFECT_ST15_METEOFALL_30340 = 30340,
    EFFECT_ST15_DIVEEFFECT_30350 = 30350,
    EFFECT_ST15_METEO_EXPLODE_30360 = 30360,
    EFFECT_ST15_BOSS_CRUSH_30370 = 30370,
    EFFECT_ST15_BOSS_CRUSH2_30371 = 30371,
    EFFECT_POWER_HIT_30380 = 30380,
    EFFECT_ST15_BOSS_APPEAR_30390 = 30390,
    EFFECT_TRICK_X_FLASHLINE_30400 = 30400,
    EFFECT_TRICK_X_RING_30410 = 30410,
    EFFECT_ST07_BORN_RING_30420 = 30420,
    EFFECT_ST07_PTOBJ_30430 = 30430,
    EFFECT_ST07_FLOOR_30440 = 30440,
    EFFECT_ST07_FLOOR_G_30450 = 30450,
    EFFECT_ST07_BORN_SPRING_30460 = 30460,
    EFFECT_ST14_FAN_L_EFFECT_30470 = 30470,
    EFFECT_ST14_FAN_S_EFFECT_30480 = 30480,
    EFFECT_ST07_BORN_ITEMBOX_30490 = 30490,
    EFFECT_ST07_BORN_DPANEL_30500 = 30500,
    EFFECT_GC_EMPTY_EFFECT_30510 = 30510,
    EFFECT_ST07_FLOOR_HOLE_30520 = 30520,
    EFFECT_LOCKON_MOT = 30530,
    EFFECT_LOCKON_MATMOT = 30531,
    EFFECT_GRAVITY_LO_30540 = 30540,
    EFFECT_ATTACK_BOOST_30610 = 30610,
    EFFECT_GEARCH_TYPE_30620 = 30620,
    PARTICLE_32000 = 32000,
    PARTICLE_32001 = 32001,
    PARTICLE_32100 = 32100,
    PARTICLE_UNION_32100 = 32100,
    PARTICLE_32999 = 32999,
    PARTICLE_GAME_32500 = 32500,
    PARTICLE_MODE_32550 = 32550,
    PARTICLE_SET_33000 = 33000,
    PARTICLE_33000 = 33000,
    PARTICLE_33999 = 33999,
    SCRIPT_SURVIVAL_DATA_START = 34000,
    SURVIVAL_DATA_BALLPOS_34000 = 34000,
    SCRIPT_SURVIVAL_DATA_END = 34001,
    SCRIPT_BINARY_START = 35000,
    SCRIPT_BINARY_35000 = 35000,
    SCRIPT_BINARY_END = 35049,
    SCRIPT_MODEL_START = 35050,
    SCRIPT_MODEL_35050 = 35050,
    SCRIPT_MODEL_MOT_35060 = 35060,
    SCRIPT_MODEL_MAT_35070 = 35070,
    SCRIPT_MODEL_MOT_MAT_35080 = 35080,
    SCRIPT_MODEL_MAT_MOF_35090 = 35090,
    SCRIPT_MODEL_MOT_MAT_MOF_35100 = 35100,
    SCRIPT_MODEL_MOF_35110 = 35110,
    SCRIPT_MODEL_FRAMETEX_35120 = 35120,
    SCRIPT_MODEL_MOTIONDATA_35130 = 35130,
    SCRIPT_MODEL_MATMOTIONDATA_35140 = 35140,
    SCRIPT_MODEL_MORFMOTIONDATA_35150 = 35150,
    SCRIPT_NT_MODEL_35160 = 35160,
    SCRIPT_NT_MODEL_MOT_35170 = 35170,
    SCRIPT_NT_MODEL_MAT_35180 = 35180,
    SCRIPT_NT_MODEL_MOT_MAT_35190 = 35190,
    SCRIPT_MODEL_END = 35249,
    SCRIPT_CAMERA_START = 35250,
    SCRIPT_CAMERAMOTIOM_35250 = 35250,
    SCRIPT_FRAMETEX_CAM_MOTION_35260 = 35260,
    SCRIPT_LIGHTMOTIOM_35270 = 35270,
    SCRIPT_CAMERA_END = 35299,
    SCRIPT_EFFECT_START = 35300,
    SCRIPT_DATA_EFFECT_35300 = 35300,
    SCRIPT_DATA_EFFECT_MAT_35310 = 35310,
    SCRIPT_SHADOW_35320 = 35320,
    SCRIPT_SHADOW_35321 = 35321,
    SCRIPT_EFFECT_GRAVITY_35330 = 35330,
    SCRIPT_DATA_SUNLENZ_35340 = 35340,
    SCRIPT_EFFECT_END = 37499,
    SCRIPT_ETC_START = 37500,
    SCRIPT_2D_37510 = 37510,
    SCRIPT_FONT_DATA_37520 = 37520,
    SCRIPT_ETC_END = 37999,
    NONSETOBJECT_START = 38000,
    ITEMTRAP_BOMB_38001 = 38001,
    NONSETOBJECT_END = 38999,
    STORY_LOADING_45000 = 45000,
    STORY_2D_45001 = 45001,
    TITLE_SELECT_50000 = 50000,
    FONT_DATA_50010 = 50010,
    FONT_MISSION_DATA_50020 = 50020,
    FONT_MENUDATA_50030 = 50030,
    FONT_USERNAME_DATA_50040 = 50040,
    FONT_BTN_DATA_50050 = 50050,
    FONT__DATA_PECULIAR_50060 = 50060,
    ADVERTISE_FLASH_TEXTURE_52000 = 52000,
    ADVERTISE_FLASH_DATA_52005 = 52005,
    ADVERTISE_BG_MODEL_52006 = 52006,
    ADVERTISE_CS_GEARPARTS_52010 = 52010,
    CHARACTER_SELECT_FLASHTEX_52020 = 52020,
    CHARACTER_SELECT_FLASH_52025 = 52025,
    MAIN_MENU_SELECT_FLASHTEX_52030 = 52030,
    MAIN_MENU_SELECT_FLASH_52035 = 52035,
    TITLE_FLASHTEX_52040 = 52040,
    TITLE_FLASH_52045 = 52045,
    ENTRY_MODEL_UNI_MOT_52050 = 52050,
    ENTRY_MODEL_EGG_MOT_52060 = 52060,
    ENTRY_MODEL_ROBO_MOT_52070 = 52070,
    EXTRA_MENU_SELECT_FLASHTEX_52080 = 52080,
    EXTRA_MENU_SELECT_FLASH_52085 = 52085,
    EXTRA_MENU_UNION_FLASH_52086 = 52086,
    OPTION_MENU_SELECT_FLASHTEX_52090 = 52090,
    OPTION_MENU_SELECT_FLASHTEX_52091 = 52091,
    OPTION_MENU_SELECT_FLASHTEX_52092 = 52092,
    OPTION_MENU_SELECT_FLASHTEX_52093 = 52093,
    OPTION_MENU_SELECT_FLASHTEX_52094 = 52094,
    OPTION_MENU_SELECT_FLASHTEX_52095 = 52095,
    OPTION_MENU_BACK_FLASH_52098 = 52098,
    OPTION_MENU_SELECT_FLASH_52099 = 52099,
    TITLE_LOGO_52100 = 52100,
    SAVEDATA_52110 = 52110,
    SAVEDATA_52111 = 52111,
    SAVEDATA_52112 = 52112,
    SAVEDATA_52113 = 52113,
    SAVEDATA_52114 = 52114,
    SAVEDATA_52115 = 52115,
    SHOPDATA_52120 = 52120,
    SHOPCHAO_52130 = 52130,
    SHOPOBJ_52140 = 52140,
    GEARGALLERY_52150 = 52150,
    KEYBOARD_2D_53000 = 53000,
    SAVE_DATA_FILE_53100 = 53100,
    SAVE_DATA_FILE_53101 = 53101,
    TEST = 60000,
    SHADOW_TEST_60010 = 60010,
    ___DUMMY__MOTION = 65500,
    DUMMY_DATA = 65501,
};
// total size: 0xC
class __vector_imp : private __vector_pod, private compile_assert {};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkProperty * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
enum enmFlag {
    FLAG_CLEAR = 0,
    FLAG_VIBRATION = 1,
    FLAG_AUTORETURN = 2,
    FLAG_SCALING = 4,
    FLAG_INIT = 7,
};
// total size: 0x14
class AgentFuncs {
    // Members
public:
    class hkCollisionAgent * (* m_createFunc)(class hkCdBody &, class hkCdBody &, class hkCollisionInput &, class hkContactMgr *); // offset 0x0, size 0x4
    void (* m_getPenetrationsFunc)(class hkCdBody &, class hkCdBody &, class hkCollisionInput &, class hkCdBodyPairCollector &); // offset 0x4, size 0x4
    void (* m_getClosestPointFunc)(class hkCdBody &, class hkCdBody &, class hkCollisionInput &, class hkCdPointCollector &); // offset 0x8, size 0x4
    void (* m_linearCastFunc)(class hkCdBody &, class hkCdBody &, class hkLinearCastCollisionInput &, class hkCdPointCollector &, class hkCdPointCollector *); // offset 0xC, size 0x4
    class hkBool m_isFlipped; // offset 0x10, size 0x1
    class hkBool m_isPredictive; // offset 0x11, size 0x1
};
// total size: 0x12F0
class clsPlayerTask : public clsObject, public clsTask {
    // Members
public:
    signed int m_s32EnableMovePathDebug; // offset 0x58, size 0x4
    class stcLine m_sDebugLine; // offset 0x5C, size 0x30
    unsigned char m_bEnableFlyDebug; // offset 0x8C, size 0x1
    float m_f32Debug_StiffFrame; // offset 0x90, size 0x4
    float m_f32Debug_StallSpeed; // offset 0x94, size 0x4
    float m_f32Debug_AirResist; // offset 0x98, size 0x4
    float m_f32Debug_UpDownAccele; // offset 0x9C, size 0x4
    float m_f32Debug_FallAccele; // offset 0xA0, size 0x4
    float m_f32Debug_DescentAccele; // offset 0xA4, size 0x4
    float m_f32Debug_RollSpeed; // offset 0xA8, size 0x4
    float m_f32Debug_PitchSpeed; // offset 0xAC, size 0x4
    float m_f32Debug_UpPitch_Limit; // offset 0xB0, size 0x4
    float m_f32Debug_DownPitch_Limit; // offset 0xB4, size 0x4
    float m_af32Debug_PitchGravityTable[3]; // offset 0xB8, size 0xC
    unsigned char m_bDispReturnPoint; // offset 0xC4, size 0x1
    unsigned char m_bDispCoursePoint; // offset 0xC5, size 0x1
    class clsPlayerDebug * m_pcDebug; // offset 0xC8, size 0x4
    signed int m_s32SfId[23]; // offset 0xCC, size 0x5C
    float m_sDrawMtx[2][4][4]; // offset 0x130, size 0x80
    float m_sEffMtx[4][4]; // offset 0x1B0, size 0x40
    float m_asBoardMtx[4][4][4]; // offset 0x1F0, size 0x100
    float m_sGearDrawMtx[4][4]; // offset 0x2F0, size 0x40
    class NNS_VECTORFAST m_sPosVecFast[2]; // offset 0x330, size 0x20
    class NNS_VECTORFAST m_sUpVecFast; // offset 0x350, size 0x10
    class NNS_VECTORFAST m_sPreUpVecFast; // offset 0x360, size 0x10
    class NNS_VECTORFAST m_sVelocityVecFast; // offset 0x370, size 0x10
    class NNS_VECTORFAST m_sSpeedVecFast; // offset 0x380, size 0x10
    class NNS_VECTORFAST m_sAirVecFast; // offset 0x390, size 0x10
    class NNS_VECTORFAST m_sVectorMoveVecFast; // offset 0x3A0, size 0x10
    class NNS_VECTORFAST m_sPathMoveVecFast; // offset 0x3B0, size 0x10
    class NNS_VECTORFAST m_sContactCharaDirVecFast; // offset 0x3C0, size 0x10
    class NNS_VECTORFAST m_sInertiaVecFast; // offset 0x3D0, size 0x10
    class NNS_VECTORFAST m_sInertiaDecayVecFast; // offset 0x3E0, size 0x10
    class NNS_VECTORFAST m_sFaceDirVecFast; // offset 0x3F0, size 0x10
    class NNS_VECTORFAST m_sContactVecFast; // offset 0x400, size 0x10
    class NNS_VECTORFAST m_sRelativeVecFast; // offset 0x410, size 0x10
    class NNS_VECTORFAST m_sExCamTargetPosVecFast; // offset 0x420, size 0x10
    class NNS_VECTORFAST m_sOffsetDrawVecFast; // offset 0x430, size 0x10
    class NNS_VECTORFAST m_sMoveNrmVecFast; // offset 0x440, size 0x10
    class stcInitData m_sInitData; // offset 0x450, size 0x30
    class stcInitData m_sBackUpData; // offset 0x480, size 0x30
    class clsPrfm m_cPrfm; // offset 0x4B0, size 0x110
    class clsPlayerMotion * m_pcMotion; // offset 0x5C0, size 0x4
    class clsSurface m_cSurface; // offset 0x5D0, size 0x20
    class clsGravity m_cGravity; // offset 0x5F0, size 0x130
    class clsGravity m_cBackUpGravity; // offset 0x720, size 0x130
    class clsPosturalCtrl m_cVelocity; // offset 0x850, size 0xB0
    class clsPosturalCtrl m_cPostural; // offset 0x900, size 0xB0
    class clsTrickManager m_cTrick; // offset 0x9B0, size 0x160
    class clsGravityActionManager m_cGravityActionManager; // offset 0xB10, size 0x50
    class clsControlMatrix m_cControlMatrix; // offset 0xB60, size 0x110
    class clsReaction m_cReaction; // offset 0xC70, size 0x40
    class clsPath m_cPath; // offset 0xCB0, size 0x60
    class clsFlyAction m_cFlyAction; // offset 0xD10, size 0x1C
    class clsRetPath m_cRetCoursePath; // offset 0xD2C, size 0x20
    class clsSlipStream m_cSlipStream; // offset 0xD50, size 0xD0
    class clsPlayerKey * m_pcKey; // offset 0xE20, size 0x4
    class clsComKey * m_pcAutoRunKey; // offset 0xE24, size 0x4
    class clsUserKey * m_pcUserKeyTmp; // offset 0xE28, size 0x4
    class clsCharacter * m_pcCharacter; // offset 0xE2C, size 0x4
    class clsGearCtrl * m_pcGearCtrl; // offset 0xE30, size 0x4
    class clsPlayerPhysic * m_pcPhysic; // offset 0xE34, size 0x4
    class clsLap * m_pcLap; // offset 0xE38, size 0x4
    class clsObject * m_pcGroundObject; // offset 0xE3C, size 0x4
    class clsOOList m_lstLightCollision; // offset 0xE40, size 0x14
    class clsFlag m_cSystemFlag; // offset 0xE54, size 0x4
    enum enmNo m_ePlayerNo; // offset 0xE58, size 0x4
    enum enmFlag m_eFlag; // offset 0xE5C, size 0x4
    enum enmStatus m_eStatus; // offset 0xE60, size 0x4
    enum enmStatus m_eStatusOld; // offset 0xE64, size 0x4
    enum enmStatus m_eStatusTrigger; // offset 0xE68, size 0x4
    enum enmStatus m_eStatusRemove; // offset 0xE6C, size 0x4
    enum enmActionType m_eActionType; // offset 0xE70, size 0x4
    enum enmActionType m_eOldActionType; // offset 0xE74, size 0x4
    enum enmMoveFlag m_eMoveFlag; // offset 0xE78, size 0x4
    float m_f32FrameRate; // offset 0xE7C, size 0x4
    float m_f32CurveRotateRate; // offset 0xE80, size 0x4
    float m_f32CurveMotionRate; // offset 0xE84, size 0x4
    float m_f32CurveRad; // offset 0xE88, size 0x4
    float m_f32CurveWaitFrame; // offset 0xE8C, size 0x4
    float m_f32vibrationCurveRate; // offset 0xE90, size 0x4
    float m_f32CurveFrame; // offset 0xE94, size 0x4
    float m_f32CentrifugalForce; // offset 0xE98, size 0x4
    float m_f32MinSpeed; // offset 0xE9C, size 0x4
    float m_f32MaxSpeed; // offset 0xEA0, size 0x4
    float m_f32Speed; // offset 0xEA4, size 0x4
    float m_f32Accele; // offset 0xEA8, size 0x4
    float m_f32SpeedRate; // offset 0xEAC, size 0x4
    float m_f32AdjustAcceleRate; // offset 0xEB0, size 0x4
    float m_f32AdjustMaxSpeed; // offset 0xEB4, size 0x4
    signed int m_s32NodeVibCycle; // offset 0xEB8, size 0x4
    float m_f32FaceRotateRate; // offset 0xEBC, size 0x4
    signed int m_s32RingNum; // offset 0xEC0, size 0x4
    signed int m_s32GoalRingNum; // offset 0xEC4, size 0x4
    float m_f32GoalRingRate; // offset 0xEC8, size 0x4
    signed int m_s32LinkCount; // offset 0xECC, size 0x4
    enum enmLinkType m_eLinkType; // offset 0xED0, size 0x4
    float m_f32Val; // offset 0xED4, size 0x4
    float m_f32ApproachVal; // offset 0xED8, size 0x4
    float m_af32ActionVal[3]; // offset 0xEDC, size 0xC
    float m_f32ObstacleFrame; // offset 0xEE8, size 0x4
    float m_f32InertiaDecayFrame; // offset 0xEEC, size 0x4
    signed int m_s32ActionMode; // offset 0xEF0, size 0x4
    enum enPlayerCtrlType m_eCtrlType; // offset 0xEF4, size 0x4
    enum enPlayerCtrlType m_eDefaultCtrlType; // offset 0xEF8, size 0x4
    signed char m_s8BaseMotionNo; // offset 0xEFC, size 0x1
    unsigned char m_u8CurrentDrawMtxNo; // offset 0xEFD, size 0x1
    unsigned char m_u8BadTrackCnt; // offset 0xEFE, size 0x1
    signed char m_s8Ranking; // offset 0xEFF, size 0x1
    signed int m_s32FalseStartShockFrame; // offset 0xF00, size 0x4
    signed int m_s32FalseStartDamageFrame; // offset 0xF04, size 0x4
    float m_f32DamageFrame; // offset 0xF08, size 0x4
    float m_f32InvincibilityFrame; // offset 0xF0C, size 0x4
    float m_f32TrapColorBallFrame; // offset 0xF10, size 0x4
    float m_f32TrapColorBallDropFrame; // offset 0xF14, size 0x4
    unsigned int m_u32TrapColorBallDropCnt; // offset 0xF18, size 0x4
    unsigned int m_u32TrapColorBallDropMaxCnt; // offset 0xF1C, size 0x4
    float m_f32TrapPartsLockFrame; // offset 0xF20, size 0x4
    float m_f32EggConfettiFrame; // offset 0xF24, size 0x4
    float m_f32EggConfettiDropFrame; // offset 0xF28, size 0x4
    float m_f32NightsAtkEffectFrame; // offset 0xF2C, size 0x4
    float m_f32NightsAtkEffectDropFrame; // offset 0xF30, size 0x4
    unsigned int m_u32NightsAtkEffectDropCnt; // offset 0xF34, size 0x4
    float m_f32DriftSideSign; // offset 0xF38, size 0x4
    float m_f32DriftOffsetPosturalRotate; // offset 0xF3C, size 0x4
    float m_f32DriftStartSpeed; // offset 0xF40, size 0x4
    float m_f32DriftLimitSpeed; // offset 0xF44, size 0x4
    float m_f32DriftDashSpeed; // offset 0xF48, size 0x4
    float m_f32DriftHandlingRate; // offset 0xF4C, size 0x4
    float m_f32DriftFrame; // offset 0xF50, size 0x4
    unsigned int m_u32DriftDashType; // offset 0xF54, size 0x4
    float m_f32ReverseRestartCountFrame; // offset 0xF58, size 0x4
    float m_f32ReverseStartCountFrame; // offset 0xF5C, size 0x4
    class clsTask * m_apcLoopParticle[4]; // offset 0xF60, size 0x10
    class clsTask * m_apcLoopEffect[4]; // offset 0xF70, size 0x10
    class NNS_VECTORFAST m_asNodePos[8]; // offset 0xF80, size 0x80
    float m_asNodeMatrix[8][4][4]; // offset 0x1000, size 0x200
    class clsBackLineEffectTask * m_pcBackLineTask; // offset 0x1200, size 0x4
    class clsVaporTrail_Task * m_pcVaporTrailTask; // offset 0x1204, size 0x4
    class clsVaporTrail_Task * m_pcSlipStreamTask; // offset 0x1208, size 0x4
    class clsWeather_Task * m_pcWeatherTask; // offset 0x120C, size 0x4
    class clsCharaVoice m_cCharaVoice; // offset 0x1210, size 0x10
    enum enmRet m_aeClipperRet[4]; // offset 0x1220, size 0x10
    float m_of32DrawClipDistx2; // offset 0x1230, size 0x4
    float m_of32MotionClipDistx1; // offset 0x1234, size 0x4
    float m_f32CamMostDistRet; // offset 0x1238, size 0x4
    float m_f32RandMotionFrame; // offset 0x123C, size 0x4
    float m_f32RankChangeMotionFrame; // offset 0x1240, size 0x4
    unsigned int m_u32CamDelayRqType; // offset 0x1244, size 0x4
    float m_f32CamDelayRqTime; // offset 0x1248, size 0x4
    float m_f32AttackFrame; // offset 0x124C, size 0x4
    float m_f32FlightFrame; // offset 0x1250, size 0x4
    float m_f32SystemScale; // offset 0x1254, size 0x4
    class clsModelType_OB_TX * m_opcResidenceTexModel_PS2; // offset 0x1258, size 0x4
    unsigned short m_u16ReturnLineNo; // offset 0x125C, size 0x2
    unsigned char m_bForcedUpdateFlag; // offset 0x125E, size 0x1
    unsigned char m_bDrawVisible; // offset 0x125F, size 0x1
    unsigned char m_bMotionVisible; // offset 0x1260, size 0x1
    unsigned char m_bDrawFlag; // offset 0x1261, size 0x1
    signed char m_s8Channel_ICS; // offset 0x1262, size 0x1
    signed char m_s8FollowNum; // offset 0x1263, size 0x1
    unsigned char m_u8BaseLightNo; // offset 0x1264, size 0x1
    unsigned char m_u8LightNo; // offset 0x1265, size 0x1
    unsigned char m_u8BackUpLightNo; // offset 0x1266, size 0x1
    unsigned char m_u8BackUpFogNo; // offset 0x1267, size 0x1
    signed char m_s8OldPathNo; // offset 0x1268, size 0x1
    unsigned char m_bDisableFog; // offset 0x1269, size 0x1
    signed char m_s8CameraNo; // offset 0x126A, size 0x1
    signed char m_s8ViewNo; // offset 0x126B, size 0x1
    unsigned char m_u8JumpCount; // offset 0x126C, size 0x1
    signed char m_s8CurAttackTarget; // offset 0x126D, size 0x1
    float m_f32Attack_Speed; // offset 0x1270, size 0x4
    float m_f32Attack_Accele; // offset 0x1274, size 0x4
    float m_f32Attack_SpeedRate; // offset 0x1278, size 0x4
    enum enmAttackLR m_eTargetSide; // offset 0x127C, size 0x4
    unsigned char m_bDamageFlag; // offset 0x1280, size 0x1
    class clsBaseEffect_Task * m_pcDmgEffectTask; // offset 0x1284, size 0x4
    class clsBaseEffect_Task * m_pcDmgEffectTask2; // offset 0x1288, size 0x4
    unsigned char m_bIsAttackDmgScale; // offset 0x128C, size 0x1
    float m_f32AttackDmgScale; // offset 0x1290, size 0x4
    signed int m_s32SuperSonic; // offset 0x1294, size 0x4
    enum enmComType m_eComType; // offset 0x1298, size 0x4
    float m_f32BoostAttackFrame; // offset 0x129C, size 0x4
    float m_f32GpRateEffectCnt; // offset 0x12A0, size 0x4
    float m_f32TrickXNegaWaitFrame; // offset 0x12A4, size 0x4
    unsigned char m_bTrickXNegaFlg; // offset 0x12A8, size 0x1
    signed int m_s32GoalMotionRequest; // offset 0x12AC, size 0x4
    class clsLimitTime m_cRingLimitTime; // offset 0x12B0, size 0x14
    class clsLimitTime m_cRingGravityLimitTime; // offset 0x12C4, size 0x14
    float m_f32ItemFrame; // offset 0x12D8, size 0x4
    signed int m_s32ReplayCamIdx; // offset 0x12DC, size 0x4
    signed int m_s32AutoWallRunPathNo; // offset 0x12E0, size 0x4
    class clsDashPanel_Obj * m_pcDashPanel; // offset 0x12E4, size 0x4
    class clsEggConfetti * m_pcEggConfetti; // offset 0x12E8, size 0x4
    class clsNightsAtkEffect * m_pcNightsAtkEffect; // offset 0x12EC, size 0x4
};
// total size: 0x4
class _stcEndPosList {
    // Members
public:
    unsigned short u16EndPointNo; // offset 0x0, size 0x2
    unsigned short u16LineNo; // offset 0x2, size 0x2
};
enum enmGearPrfm {
    PRFM_EMPTY = 0,
    PRFM_D_SONIC = 1,
    PRFM_D_TAILS = 2,
    PRFM_D_KNUCKLES = 3,
    PRFM_D_AMY = 4,
    PRFM_D_JET = 5,
    PRFM_D_STORM = 6,
    PRFM_D_WAVE = 7,
    PRFM_D_EGGMAN = 8,
    PRFM_D_CREAM = 9,
    PRFM_D_ROUGE = 10,
    PRFM_D_SHADOW = 11,
    PRFM_D_BRAZE = 12,
    PRFM_D_SILVER = 13,
    PRFM_D_NIGHTS = 14,
    PRFM_D_AMIGO = 15,
    PRFM_D_BILLY = 16,
    PRFM_D_ZAKOROBO = 17,
    PRFM_D_LEADERROBO = 18,
    PRFM_D_SHOOTINGSTAR = 19,
    PRFM_D_FASTER = 20,
    PRFM_D_FASTEST = 21,
    PRFM_D_TURBOSTAR = 22,
    PRFM_D_LIGHTBOARD = 23,
    PRFM_D_COVERS = 24,
    PRFM_D_COVERF = 25,
    PRFM_D_COVERP = 26,
    PRFM_D_ADV_S = 27,
    PRFM_D_ADV_F = 28,
    PRFM_D_ADV_P = 29,
    PRFM_D_WINDSTAR = 30,
    PRFM_D_ROADSTAR = 31,
    PRFM_D_AIRSHIP = 32,
    PRFM_D_WHEELCUSTOM = 33,
    PRFM_D_OMNITENPOS = 34,
    PRFM_D_HIPERDIVE = 35,
    PRFM_D_GCBOOSTER = 36,
    PRFM_D_GCMASTER = 37,
    PRFM_D_REGEND = 38,
    PRFM_D_SHINOBI = 39,
    PRFM_D_KUNOICHI = 40,
    PRFM_D_RAILLINKER = 41,
    PRFM_D_GPGETTER = 42,
    PRFM_D_SKILUPPER = 43,
    PRFM_D_GSHOT = 44,
    PRFM_D_MASTEROFFROAD = 45,
    PRFM_D_RISERVETANK = 46,
    PRFM_D_GPTANK = 47,
    PRFM_D_CHAOSEMELARD = 48,
    PRFM_D_THECRAZY = 49,
    PRFM_D_ANGELDEVIL = 50,
    PRFM_D_SLOTTOL = 51,
    PRFM_D_MONEYCRISIS = 52,
    PRFM_D_BEGINNER = 53,
    PRFM_D_BIGBAN = 54,
    PRFM_D_GAMBLER = 55,
    PRFM_D_BINGOSTAR = 56,
    PRFM_D_WANTED = 57,
    PRFM_D_HANGON = 58,
    PRFM_D_MAGICBLOOM = 59,
    PRFM_D_MAG = 60,
    PRFM_D_UNTACHABLE = 61,
    PRFM_D_RAINBOW = 62,
    PRFM_D_WINDCATHER = 63,
    PRFM_P_ZEROPARAM = 64,
    PRFM_P_GRIND = 65,
    PRFM_P_AIRRIDE = 66,
    PRFM_P_BIKE = 67,
    PRFM_P_WHEEL = 68,
    PRFM_P_YOTCH = 69,
    PRFM_P_MAXSPEED_PLUS1 = 70,
    PRFM_P_MAXSPEED_PLUS2 = 71,
    PRFM_P_MAXSPEED_PLUS3 = 72,
    PRFM_P_MAXSPEED_PLUS4 = 73,
    PRFM_P_MAXSPEED_PLUS5 = 74,
    PRFM_1ST_SPEED_01 = 75,
    PRFM_1ST_SPEED_02 = 76,
    PRFM_1ST_SPEED_03 = 77,
    PRFM_P_ENDU_PLUS30 = 78,
    PRFM_P_ENDU_PLUS50 = 79,
    PRFM_P_ENDU_PLUS100 = 80,
    PRFM_AGP_01 = 81,
    PRFM_AGP_02 = 82,
    PRFM_GC_SPEED_01 = 83,
    PRFM_GC_SPEED_02 = 84,
    PRFM_GC_SPEED_03 = 85,
    PRFM_P_TRICK_PLUS1 = 86,
    PRFM_P_AGPRATE_PLUS05 = 87,
    PRFM_P_RINGCAP_PLUS25 = 88,
    PRFM_P_RINGCAP_PLUS50 = 89,
    PRFM_P_RINGCAP_PLUS100 = 90,
    PRFM_P_RINGCAP_PLUS150 = 91,
    PRFM_P_ITEMRANK_PLUS1 = 92,
    PRFM_P_ATTIME_PLUS120 = 93,
    PRFM_P_ALL_PARAMUP = 94,
    PRFM_P_GP_INFINIT = 95,
    PRFM_MAX = 96,
};
enum enmType {
    TYPE_NORAML = 0,
    TYPE_ANGEL = 1,
    TYPE_DEVIL = 2,
    TYPE_MAX = 3,
};
// total size: 0x1008
class PotentialInfo {
    // Members
public:
    class ContactRef * m_firstFreePotentialContact; // offset 0x0, size 0x4
    class hkProcessCdPoint * * m_firstFreeRepresentativeContact; // offset 0x4, size 0x4
    class hkProcessCdPoint * m_representativeContacts[256]; // offset 0x8, size 0x400
    class ContactRef m_potentialContacts[256]; // offset 0x408, size 0xC00
};
enum enmSelectType {
    SELECT_NORMAL = 0,
    SELECT_NO_PRFM_MERGE = 1,
    SELECT_INFINITY = 2,
};
// total size: 0x8
class NNS_TEXCOORD {
    // Members
public:
    float u; // offset 0x0, size 0x4
    float v; // offset 0x4, size 0x4
};
// total size: 0x20
class __deque_deleter_common : private __deque_buf {
    // Members
public:
    class compressed_pair buf_; // offset 0x0, size 0x18
    unsigned int start_; // offset 0x18, size 0x4
    unsigned int size_; // offset 0x1C, size 0x4
};
// total size: 0x4
class clsOOStlAllocator {
    // Members
public:
    class clsOOHeapFragment * m_pcHeap; // offset 0x0, size 0x4
};
// total size: 0x24
class stcData {
    // Members
public:
    char ac8Name_Debug[16]; // offset 0x0, size 0x10
    float f32Height; // offset 0x10, size 0x4
    float f32Weight; // offset 0x14, size 0x4
    unsigned char u8Style; // offset 0x18, size 0x1
    unsigned char u8SkillType; // offset 0x19, size 0x1
    unsigned char u8BaseType; // offset 0x1A, size 0x1
    unsigned char u8Reserve[1]; // offset 0x1B, size 0x1
    float f32AttackLFrame; // offset 0x1C, size 0x4
    float f32AttackRFrame; // offset 0x20, size 0x4
};
// total size: 0x48
class stcPlayData {
    // Members
public:
    enum enmPriority ePriority; // offset 0x0, size 0x4
    signed int s32TableNo; // offset 0x4, size 0x4
    class stcPlayTable asTable[4]; // offset 0x8, size 0x40
};
// total size: 0x4
class clsCamIvBase {};
// total size: 0x18
class hkConstraintOwner : public hkReferencedObject {
    // Members
public:
    class hkConstraintInfo m_constraintInfo; // offset 0x8, size 0x10
};
// total size: 0x4
class clsSingleton {};
// total size: 0x1
class hkCriticalSection {};
// total size: 0x30
class NNS_TRS {
    // Members
public:
    class NNS_VECTORFAST Translation; // offset 0x0, size 0x10
    class NNS_QUATERNION Rotation; // offset 0x10, size 0x10
    class NNS_VECTORFAST Scaling; // offset 0x20, size 0x10
};
// total size: 0x8
class clsModelType_OB_TX {
    // Members
public:
    class NNS_OBJECT * m_psObject; // offset 0x0, size 0x4
    class _NNS_TEXLIST * m_psTexList; // offset 0x4, size 0x4
};
// total size: 0x120
class hkMotion : public hkReferencedObject {
    // Members
public:
    class hkEnum m_type; // offset 0x8, size 0x1
    unsigned char m_deactivationIntegrateCounter; // offset 0x9, size 0x1
    unsigned short m_deactivationNumInactiveFrames[2]; // offset 0xA, size 0x4
    class hkMotionState m_motionState; // offset 0x10, size 0xC0
    class hkVector4 m_inertiaAndMassInv; // offset 0xD0, size 0x10
    class hkVector4 m_linearVelocity; // offset 0xE0, size 0x10
    class hkVector4 m_angularVelocity; // offset 0xF0, size 0x10
    class hkVector4 m_deactivationRefPosition[2]; // offset 0x100, size 0x20
};
enum hkStepResult {
    HK_STEP_RESULT_SUCCESS = 0,
    HK_STEP_RESULT_MEMORY_FAILURE_BEFORE_INTEGRATION = 1,
    HK_STEP_RESULT_MEMORY_FAILURE_DURING_COLLIDE = 2,
    HK_STEP_RESULT_MEMORY_FAILURE_DURING_TOI_SOLVE = 3,
};
// total size: 0x5C
class clsMotion {
    // Members
public:
    class NNS_OBJECT * m_psObject; // offset 0x0, size 0x4
    float (* m_psMtxPal)[4][4]; // offset 0x4, size 0x4
    class NNS_TRS * m_apsTrs[2]; // offset 0x8, size 0x8
    unsigned int * m_psNodeStatus; // offset 0x10, size 0x4
    class NNS_MOTION * m_psMotion; // offset 0x14, size 0x4
    class NNS_MOTION * m_psLinkMotion; // offset 0x18, size 0x4
    class NNS_MOTION * m_psBlendMotion; // offset 0x1C, size 0x4
    enum enmStatus m_eStatus; // offset 0x20, size 0x4
    signed int m_s32CurrentTrsNo; // offset 0x24, size 0x4
    signed int m_s32CurrentChangeFlag; // offset 0x28, size 0x4
    float m_f32AllFrameRate; // offset 0x2C, size 0x4
    float m_f32FrameRate; // offset 0x30, size 0x4
    float m_f32BlendFrameRate; // offset 0x34, size 0x4
    float m_f32LinkFrameRate; // offset 0x38, size 0x4
    float m_f32Frame; // offset 0x3C, size 0x4
    float m_f32LinkFrame; // offset 0x40, size 0x4
    float m_f32BlendFrame; // offset 0x44, size 0x4
    float m_f32LinkRatio; // offset 0x48, size 0x4
    float m_f32LinkAddRatio; // offset 0x4C, size 0x4
    float m_f32BlendRatio; // offset 0x50, size 0x4
    float m_f32BlendAddRatio; // offset 0x54, size 0x4
};
// total size: 0x8
class clsPathBase {
    // Members
public:
    class clsBaseStage_Task * m_pcOwnerStage; // offset 0x4, size 0x4
};
// total size: 0x4
class hkPadSpu {
    // Members
public:
    class hkContactMgr * m_storage; // offset 0x0, size 0x4
};
// total size: 0x20
class clsOODeque : public deque {};
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
// total size: 0x0
class hkConvexListFilter {};
enum enmKickerRankZone {
    FAILURE__ZONE = 0,
    RANK_B__ZONE = 1,
    RANK_A__ZONE = 2,
    RANK_S__ZONE = 3,
    ZONE_MAX = 4,
};
// total size: 0x5C
class clsRigidBodyCollectorInfo : public clsCollectorInfo {};
// total size: 0x1
class hkEnum {
    // Members
public:
    signed char m_storage; // offset 0x0, size 0x1
};
// total size: 0x3C
class hkCollisionQualityInfo {
    // Members
public:
    float m_keepContact; // offset 0x0, size 0x4
    float m_create4dContact; // offset 0x4, size 0x4
    float m_createContact; // offset 0x8, size 0x4
    float m_manifoldTimDistance; // offset 0xC, size 0x4
    class hkBool m_useContinuousPhysics; // offset 0x10, size 0x1
    float m_minSeparation; // offset 0x14, size 0x4
    float m_minExtraSeparation; // offset 0x18, size 0x4
    float m_minSafeDeltaTime; // offset 0x1C, size 0x4
    float m_minAbsoluteSafeDeltaTime; // offset 0x20, size 0x4
    float m_toiSeparation; // offset 0x24, size 0x4
    float m_toiExtraSeparation; // offset 0x28, size 0x4
    float m_toiAccuracy; // offset 0x2C, size 0x4
    float m_maxContraintViolation; // offset 0x30, size 0x4
    float m_minToiDeltaTime; // offset 0x34, size 0x4
    unsigned short m_constraintPriority; // offset 0x38, size 0x2
    class hkBool m_enableToiWeldRejection; // offset 0x3A, size 0x1
};
// total size: 0x0
class clsAdjustGravityAction_Object {};
// total size: 0x0
class hkActionListener {};
// total size: 0x14
class __cdeque_deleter_common {
    // Members
public:
    class compressed_pair capacity_; // offset 0x0, size 0x8
    unsigned int size_; // offset 0x8, size 0x4
    unsigned int start_; // offset 0xC, size 0x4
    unsigned int * data_; // offset 0x10, size 0x4
};
// total size: 0x3060
class hkProcessCollisionOutput : public hkProcessCollisionData {
    // Members
public:
    class hkPadSpu m_potentialContacts; // offset 0x3050, size 0x4
};
// total size: 0x1
class binary_function {};
// total size: 0x4
class compressed_pair : private compressed_pair_imp {};
// total size: 0x80
class clsGearThrottle : public clsGearPtnBoard {
    // Members
public:
    class clsGearSpThrottle * m_pcGearOldThrottle; // offset 0x70, size 0x4
};
// total size: 0x50
class clsGearPtnEffectPart : public clsGearBaseParts {};
// total size: 0x1
class hkEnum {
    // Members
public:
    unsigned char m_storage; // offset 0x0, size 0x1
};
// total size: 0x0
class clsDashPanel_Obj {};
// total size: 0xC
class stcBaseStatus {
    // Members
public:
    unsigned char u8TexNo; // offset 0x0, size 0x1
    unsigned char u8Rand; // offset 0x1, size 0x1
    unsigned char u8RotZ; // offset 0x2, size 0x1
    float f32MinSpeed; // offset 0x4, size 0x4
    float f32MaxSpeed; // offset 0x8, size 0x4
};
// total size: 0x130
class hkMaxSizeMotion : public hkKeyframedRigidMotion {};
// total size: 0x2
class hkEnum {
    // Members
public:
    unsigned short m_storage; // offset 0x0, size 0x2
};
// total size: 0x8
class hkCdBodyPairCollector {
    // Members
public:
    class hkBool m_earlyOut; // offset 0x4, size 0x1
};
// total size: 0x7C
struct /* @anon2 */ {};
// total size: 0x2C
class hkConstraintInstance : public hkReferencedObject {
    // Members
public:
    class hkConstraintOwner * m_owner; // offset 0x8, size 0x4
    class hkConstraintData * m_data; // offset 0xC, size 0x4
    class hkModifierConstraintAtom * m_constraintModifiers; // offset 0x10, size 0x4
    class hkEntity * m_entities[2]; // offset 0x14, size 0x8
    class hkEnum m_priority; // offset 0x1C, size 0x1
    class hkBool m_wantRuntime; // offset 0x1D, size 0x1
    char * m_name; // offset 0x20, size 0x4
    unsigned int m_userData; // offset 0x24, size 0x4
    class hkConstraintInternal * m_internal; // offset 0x28, size 0x4
};
// total size: 0x60
class clsCharacter {
    // Members
public:
    class clsModelType_OB_TX * m_pcModel; // offset 0x0, size 0x4
    class stcData * m_posData; // offset 0x4, size 0x4
    class clsPlayerTask * m_pcPlayer; // offset 0x8, size 0x4
    float m_f32OffsetPosition; // offset 0xC, size 0x4
    unsigned char m_u8Type; // offset 0x10, size 0x1
    enum enmBaseType m_eBaseType; // offset 0x14, size 0x4
    enum enmWalkType m_eWalkType; // offset 0x18, size 0x4
    unsigned char m_u8ModelType; // offset 0x1C, size 0x1
    float m_f32DrawAlpha; // offset 0x20, size 0x4
    float m_f32behaviorCnt; // offset 0x24, size 0x4
    class clsDrawAttackEffect_Task * m_pcDrawEffTsk; // offset 0x28, size 0x4
    class NNS_VECTORFAST m_sFollowOffsetVF; // offset 0x30, size 0x10
    class NNS_VECTORFAST m_sFollowVF; // offset 0x40, size 0x10
    unsigned int m_u32FollowCalcNodeIdx; // offset 0x50, size 0x4
};
// total size: 0x0
class clsRigidBodyGimmickObj {};
// total size: 0x3050
class hkProcessCollisionData {
    // Members
public:
    class hkPadSpu m_firstFreeContactPoint; // offset 0x0, size 0x4
    class hkPadSpu m_constraintOwner; // offset 0x4, size 0x4
    class hkProcessCdPoint m_contactPoints[256]; // offset 0x10, size 0x3000
    class ToiInfo m_toi; // offset 0x3010, size 0x40
};
// total size: 0xC
class vector : private __vector_imp {};
// total size: 0x30
class clsVerticalTrickAction : public clsBaseTrickAction {
    // Members
public:
    class NNS_VECTORFAST m_sUpVecFast; // offset 0x10, size 0x10
    float m_f32UpAccele; // offset 0x20, size 0x4
};
// total size: 0x1C
class clsFlyAction {
    // Members
public:
    class NNS_QUATERNION m_sFlyQuat; // offset 0x0, size 0x10
    signed int m_A32FlyPitchAngle; // offset 0x10, size 0x4
    signed int m_A32FlyRollAngle; // offset 0x14, size 0x4
    signed short m_s16OldRingNo; // offset 0x18, size 0x2
    signed short m_s16InitType; // offset 0x1A, size 0x2
};
// total size: 0x68
class clsBaseGimmickHead : public clsTask {
    // Members
public:
    enum enm m_ePackId; // offset 0x54, size 0x4
    unsigned int m_u32ObjectMax; // offset 0x58, size 0x4
    class hkShape * m_pcPhantomShape; // offset 0x5C, size 0x4
    class hkShape * m_pcRigidShape; // offset 0x60, size 0x4
    unsigned char m_bIsLoadBinary; // offset 0x64, size 0x1
};
// total size: 0x4
class clsOOSemaphore {};
// total size: 0x10
class stcSpeedPath {
    // Members
public:
    signed short s16MaxSpeed; // offset 0x0, size 0x2
    signed short s16MinSpeed; // offset 0x2, size 0x2
    signed short s16Type; // offset 0x4, size 0x2
    signed short as16Reserve[5]; // offset 0x6, size 0xA
};
// total size: 0x50
class clsGearSpViewTrap : public clsGearPtnEffectPart {};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkRootCdPoint * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x70
class hkAgent3ProcessInput : public hkAgent3Input {
    // Members
public:
    class hkPadSpu m_distAtT1; // offset 0x50, size 0x4
    class hkPadSpu m_offsetPpuSectorMinusSpuSector; // offset 0x54, size 0x4
    class hkVector4 m_linearTimInfo; // offset 0x60, size 0x10
};
// total size: 0xC
class hkMaterial {
    // Members
public:
    class hkEnum m_responseType; // offset 0x0, size 0x1
    float m_friction; // offset 0x4, size 0x4
    float m_restitution; // offset 0x8, size 0x4
};
enum enmAction {
    ACTION_NULL = 0,
    ACTION_DIVE = 1,
    ACTION_CTRL = 2,
    MAX_ACTION_NUM = 3,
};
// total size: 0x0
class node {};
// total size: 0x18
class __tree : private __red_black_tree {
    // Members
public:
    class compressed_pair alloc_; // offset 0x0, size 0x8
    class compressed_pair node_alloc_; // offset 0x8, size 0x8
    class compressed_pair comp_; // offset 0x10, size 0x8
};
// total size: 0x5C
class clsCollectorInfo {
    // Members
public:
    class hkArray m_apcCollidable[2]; // offset 0x0, size 0x18
    class hkArray m_cCollidableTrig; // offset 0x18, size 0xC
    class hkArray m_cContactTrig; // offset 0x24, size 0xC
    class hkArray m_cCollidableAlways; // offset 0x30, size 0xC
    class hkArray m_cContactAlways; // offset 0x3C, size 0xC
    class hkArray m_cCollidableRemove; // offset 0x48, size 0xC
    signed int m_s32CurrentNo; // offset 0x54, size 0x4
};
// total size: 0x14
class hkAgentNnTrack {
    // Members
public:
    unsigned int m_bytesUsedInLastSector; // offset 0x0, size 0x4
    class hkInplaceArray m_sectors; // offset 0x4, size 0x10
};
enum enmMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
    MODE_DEAD = 2,
};
// total size: 0x4
class hkPadSpu {
    // Members
public:
    class hkCollisionDispatcher * m_storage; // offset 0x0, size 0x4
};
// total size: 0x4
class compressed_pair_imp : private allocator {
    // Members
public:
    unsigned int second_; // offset 0x0, size 0x4
};
// total size: 0x1
class __deque_buf {};
// total size: 0x138
class clsOOTaskManager {
    // Members
public:
    class clsOOHeapFragment & m_rcMainWorkHeap; // offset 0x4, size 0x4
    class clsOOHeapFragment m_cHeapStlList_4; // offset 0x8, size 0x34
    class clsOOHeapFragment m_cHeapStlMap_4_4; // offset 0x3C, size 0x34
    class clsOOHeapFragment m_cDefaultWorkHeap; // offset 0x70, size 0x34
    void * m_pvWorkStartAddr; // offset 0xA4, size 0x4
    class clsOOList m_lstTask; // offset 0xA8, size 0x14
    class clsOOList m_lstTaskNewcomer; // offset 0xBC, size 0x14
    class clsOOMap m_mapExecList; // offset 0xD0, size 0x18
    class clsOOList m_lstFirstTask; // offset 0xE8, size 0x14
    class clsOOMMap m_mmapReservedDeadTask; // offset 0xFC, size 0x18
    class clsOOList m_lstDeadTask; // offset 0x114, size 0x14
    class clsOOTask * m_pcCurrentTask; // offset 0x128, size 0x4
    unsigned int m_u32PauseFlags; // offset 0x12C, size 0x4
    unsigned char m_u8AllDeadMode; // offset 0x130, size 0x1
    unsigned char m_au8LoopUpdate[5]; // offset 0x131, size 0x5
};
// total size: 0x50
class stcCtrlData {
    // Members
public:
    char ac8Name[16]; // offset 0x0, size 0x10
    char ac8BinName[8]; // offset 0x10, size 0x8
    unsigned int u32UsableBit; // offset 0x18, size 0x4
    float f32Weight; // offset 0x1C, size 0x4
    enum enmSelectType eSelectType; // offset 0x20, size 0x4
    enum enmRingTableType eRingTableType; // offset 0x24, size 0x4
    unsigned short u16GearPrice; // offset 0x28, size 0x2
    enum enmGear aeGear[4]; // offset 0x2C, size 0x10
    enum enmGearPrfm aePrfmNo[4]; // offset 0x3C, size 0x10
    unsigned char aIsLockedBit[4]; // offset 0x4C, size 0x4
};
// total size: 0x4
class clsBaseTrickAction {};
// total size: 0x8
class hkSmallArray {
    // Members
public:
    class hkCollisionListener * * m_data; // offset 0x0, size 0x4
    unsigned short m_size; // offset 0x4, size 0x2
    unsigned short m_capacityAndFlags; // offset 0x6, size 0x2
};
// total size: 0x30
class hkRootCdPoint {
    // Members
public:
    class hkContactPoint m_contact; // offset 0x0, size 0x20
    class hkCollidable * m_rootCollidableA; // offset 0x20, size 0x4
    unsigned int m_shapeKeyA; // offset 0x24, size 0x4
    class hkCollidable * m_rootCollidableB; // offset 0x28, size 0x4
    unsigned int m_shapeKeyB; // offset 0x2C, size 0x4
};
// total size: 0x4
class stcTimePack {
    // Members
public:
    unsigned char u8Minutes; // offset 0x0, size 0x1
    unsigned char u8Sec; // offset 0x1, size 0x1
    unsigned short u16MSec; // offset 0x2, size 0x2
};
enum enmStartType {
    START_TYPE__JUMP = 0,
    START_TYPE__FLIGHT = 1,
};
// total size: 0x10
class stcPlayTable {
    // Members
public:
    float f32StartFrame; // offset 0x0, size 0x4
    float f32LinkFrame; // offset 0x4, size 0x4
    enum enmStatus eStatus; // offset 0x8, size 0x4
    signed char s8MotionNo; // offset 0xC, size 0x1
    signed char s8MotionType; // offset 0xD, size 0x1
    unsigned char au8Reserve[2]; // offset 0xE, size 0x2
};
// total size: 0x4
class clsSingleton {};
// total size: 0x8
class compressed_pair : private compressed_pair_imp {};
// total size: 0xC
class hkArray {
    // Members
public:
    class CollisionEntry * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x50
class clsGearBaseParts : public clsGear {};
enum enmType {
    TYPE_NULL = 0,
    TYPE_NORMAL = 1,
    TYPE_GCTRL = 2,
    TYPE_STEEP = 3,
};
// total size: 0x8
class compressed_pair : private compressed_pair_imp {};
// total size: 0x4C
struct /* @anon3 */ {};
enum enmStartMode {
    START_NORMAL = 0,
    START_GHOST_VS = 1,
    START_WORLD_RANKING = 2,
    START_FORCE_NORMAL = 3,
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
// total size: 0x4
class clsFlag {
    // Members
public:
    enum enmSystemFlag m_tData; // offset 0x0, size 0x4
};
// total size: 0xC
class stcCamCtrlStock {
    // Members
public:
    unsigned int u32CamCtrlType; // offset 0x0, size 0x4
    class clsCamCtrl * pacCamCtrl[2]; // offset 0x4, size 0x8
};
// total size: 0x40
class _LineData {
    // Members
public:
    unsigned short u16StartPointNo; // offset 0x0, size 0x2
    unsigned short u16EndPointNo; // offset 0x2, size 0x2
    unsigned short u16TypeAttr; // offset 0x4, size 0x2
    unsigned short u16LineAttr; // offset 0x6, size 0x2
    float f32Radius; // offset 0x8, size 0x4
    float f32Length; // offset 0xC, size 0x4
    float f32SLength; // offset 0x10, size 0x4
    unsigned int u32GravityPathNo; // offset 0x14, size 0x4
    unsigned int u32Reserved[2]; // offset 0x18, size 0x8
    unsigned int au32UserData[8]; // offset 0x20, size 0x20
};
enum enmType {
    TYPE_NULL = 0,
    TYPE_DIVE = 1,
    TYPE_CTRL_SLIDE = 2,
    TYPE_CTRL_TRICK = 3,
    TYPE_CTRL_FLIGHT = 4,
    MAX_TYPE_NUM = 5,
};
// total size: 0x4
class generic_iterator {
    // Members
public:
    class node * node_; // offset 0x0, size 0x4
};
// total size: 0x60
class clsGearPtnBike : public clsGearBasePrototype {};
// total size: 0x40
class clsLap {
    // Members
public:
    unsigned int m_u32GoalNum; // offset 0x4, size 0x4
    class clsPlayerTask * m_pcPlayer; // offset 0x8, size 0x4
    class stcRecord * m_pasLapTime; // offset 0xC, size 0x4
    class stcRecord m_sRecord; // offset 0x10, size 0x4
    class stcRecord m_sTimeAttackRecord; // offset 0x14, size 0x4
    class stcRecord m_sTimeAttackTime; // offset 0x18, size 0x4
    unsigned int m_u32LastLapTimeMSec; // offset 0x1C, size 0x4
    signed int m_s32Lap; // offset 0x20, size 0x4
    signed int m_s32OldLap; // offset 0x24, size 0x4
    signed int m_s32LapNum; // offset 0x28, size 0x4
    signed int m_s32LapOld; // offset 0x2C, size 0x4
    signed int m_s32DefLap; // offset 0x30, size 0x4
    float * m_paf32OldGoalLineDotProduct; // offset 0x34, size 0x4
    float m_f32RankingPoint; // offset 0x38, size 0x4
    signed int m_s32MaxLap; // offset 0x3C, size 0x4
};

// total size: 0x80
class clsPathCourse : public clsPathPoint {
    // Members
public:
    class NNS_VECTORFAST m_sGoalLinePos; // offset 0x20, size 0x10
    class NNS_VECTORFAST m_sGoalLineDir; // offset 0x30, size 0x10
    class NNS_VECTORFAST m_sLastLineDir; // offset 0x40, size 0x10
    class NNS_VECTORFAST m_sStartLinePos; // offset 0x50, size 0x10
    class NNS_VECTORFAST m_sStartLineDir; // offset 0x60, size 0x10
    class NNS_VECTORFAST m_sFirstLineDir; // offset 0x70, size 0x10
};
// total size: 0x1C60
class hkCollisionDispatcher : public hkReferencedObject {
    // Members
public:
    class hkCollisionAgent * (* m_defaultCollisionAgent)(class hkCdBody &, class hkCdBody &, class hkCollisionInput &, class hkContactMgr *); // offset 0x8, size 0x4
    class hkContactMgrFactory * m_contactMgrFactory[8][8]; // offset 0xC, size 0x100
    unsigned int m_hasAlternateType[32]; // offset 0x110, size 0x80
    signed int m_numAgent2Types; // offset 0x190, size 0x4
    unsigned char m_agent2Types[32][32]; // offset 0x1A0, size 0x400
    unsigned char m_agent2TypesPred[32][32]; // offset 0x5A0, size 0x400
    class AgentFuncs m_agent2Func[64]; // offset 0x9A0, size 0x500
    signed int m_numAgent3Types; // offset 0xEA0, size 0x4
    unsigned char m_agent3Types[32][32]; // offset 0xEB0, size 0x400
    unsigned char m_agent3TypesPred[32][32]; // offset 0x12B0, size 0x400
    class Agent3FuncsIntern m_agent3Func[16]; // offset 0x16B0, size 0x340
    signed char m_collisionQualityTable[9][9]; // offset 0x19F0, size 0x51
    class hkCollisionQualityInfo m_collisionQualityInfo[8]; // offset 0x1A50, size 0x1E0
    class hkBool m_collisionAgentRegistered; // offset 0x1C30, size 0x1
    class hkBool m_agent3Registered; // offset 0x1C31, size 0x1
    class hkBool m_checkEnabled; // offset 0x1C32, size 0x1
    class hkArray m_shapeInheritance; // offset 0x1C34, size 0xC
    class DebugEntry (* m_debugAgent2Table)[32][32]; // offset 0x1C40, size 0x4
    class DebugEntry (* m_debugAgent2TablePred)[32][32]; // offset 0x1C44, size 0x4
    class DebugEntry (* m_debugAgent3Table)[32][32]; // offset 0x1C48, size 0x4
    class DebugEntry (* m_debugAgent3TablePred)[32][32]; // offset 0x1C4C, size 0x4
    float m_expectedMaxLinearVelocity; // offset 0x1C50, size 0x4
    float m_expectedMinPsiDeltaTime; // offset 0x1C54, size 0x4
};
// total size: 0x8
class CollisionEntry {
    // Members
public:
    class hkAgentNnEntry * m_agentEntry; // offset 0x0, size 0x4
    class hkLinkedCollidable * m_partner; // offset 0x4, size 0x4
};
enum hkShapeType {
    HK_SHAPE_INVALID = 0,
    HK_SHAPE_CONVEX = 1,
    HK_FIRST_SHAPE_TYPE = 1,
    HK_SHAPE_COLLECTION = 2,
    HK_SHAPE_SPHERE = 3,
    HK_SHAPE_CYLINDER = 4,
    HK_SHAPE_TRIANGLE = 5,
    HK_SHAPE_BOX = 6,
    HK_SHAPE_CAPSULE = 7,
    HK_SHAPE_CONVEX_VERTICES = 8,
    HK_SHAPE_PACKED_CONVEX_VERTICES = 9,
    HK_SHAPE_LIST = 10,
    HK_SHAPE_MOPP = 11,
    HK_SHAPE_MOPP_EMBEDDED = 12,
    HK_SHAPE_CONVEX_TRANSLATE = 13,
    HK_SHAPE_CONVEX_TRANSFORM = 14,
    HK_SHAPE_EXTENDED_MESH = 15,
    HK_SHAPE_MAX_ID_SPU = 16,
    HK_SHAPE_CONVEX_PIECE = 17,
    HK_SHAPE_MULTI_SPHERE = 18,
    HK_SHAPE_CONVEX_LIST = 19,
    HK_SHAPE_TRIANGLE_COLLECTION = 20,
    HK_SHAPE_BV_TREE = 21,
    HK_SHAPE_MULTI_RAY = 22,
    HK_SHAPE_HEIGHT_FIELD = 23,
    HK_SHAPE_SAMPLED_HEIGHT_FIELD = 24,
    HK_SHAPE_TRI_PATCH = 25,
    HK_SHAPE_SPHERE_REP = 26,
    HK_SHAPE_BV = 27,
    HK_SHAPE_PLANE = 28,
    HK_SHAPE_TRANSFORM = 29,
    HK_SHAPE_PHANTOM_CALLBACK = 30,
    HK_SHAPE_USER0 = 31,
    HK_SHAPE_USER1 = 32,
    HK_SHAPE_USER2 = 33,
    HK_SHAPE_MAX_ID = 34,
    HK_SHAPE_ALL = -1,
};
enum LastProcessingStep {
    INTEGRATE = 0,
    COLLIDE = 1,
};
// total size: 0x4
class hkPadSpu {
    // Members
public:
    class hkProcessCdPoint * m_storage; // offset 0x0, size 0x4
};
// total size: 0x4
class GskFlags {
    // Members
public:
    unsigned char m_cylinderAgentFlags; // offset 0x0, size 0x1
    unsigned char m_enableContactTims; // offset 0x1, size 0x1
    unsigned char m_convexListInGskMode; // offset 0x2, size 0x1
    unsigned char m_processFunctionCalled; // offset 0x3, size 0x1
};
// total size: 0x90
class clsNightsAtkEffect {
    // Members
public:
    class clsPlayerTask * m_pcPlayer; // offset 0x4, size 0x4
    signed short m_s16Alpha; // offset 0x8, size 0x2
    float m_f32ScrollSpeed; // offset 0xC, size 0x4
    float m_f32LifeFrame; // offset 0x10, size 0x4
    unsigned int m_u32ViewNo; // offset 0x14, size 0x4
    class NNS_PRIM2D_PCT m_sPrimitive[6]; // offset 0x18, size 0x78
};
// total size: 0x58
class NNS_OBJECT {
    // Members
public:
    class NNS_VECTOR Center; // offset 0x0, size 0xC
    float Radius; // offset 0xC, size 0x4
    signed int nMaterial; // offset 0x10, size 0x4
    class NNS_MATERIALPTR * pMatPtrList; // offset 0x14, size 0x4
    signed int nVtxList; // offset 0x18, size 0x4
    class NNS_VTXLISTPTR * pVtxListPtrList; // offset 0x1C, size 0x4
    signed int nPrimList; // offset 0x20, size 0x4
    class NNS_PRIMLISTPTR * pPrimListPtrList; // offset 0x24, size 0x4
    signed int nNode; // offset 0x28, size 0x4
    signed int MaxNodeDepth; // offset 0x2C, size 0x4
    union { // inferred
        class NNS_NODE * pNodeList; // offset 0x30, size 0x4
        class NNS_NODEEXPTR * pNodeExPtrList; // offset 0x30, size 0x4
    };
    signed int nMtxPal; // offset 0x34, size 0x4
    signed int nSubobj; // offset 0x38, size 0x4
    class NNS_SUBOBJ * pSubobjList; // offset 0x3C, size 0x4
    signed int nTex; // offset 0x40, size 0x4
    unsigned int fType; // offset 0x44, size 0x4
    signed int Version; // offset 0x48, size 0x4
    float BoundingBoxX; // offset 0x4C, size 0x4
    float BoundingBoxY; // offset 0x50, size 0x4
    float BoundingBoxZ; // offset 0x54, size 0x4
};
// total size: 0x1
class hkEnum {
    // Members
public:
    unsigned char m_storage; // offset 0x0, size 0x1
};
// total size: 0x14
class clsOOList : public list {};
// total size: 0x24
class hkConstraintInternal {
    // Members
public:
    class hkConstraintInstance * m_constraint; // offset 0x0, size 0x4
    class hkEntity * m_entities[2]; // offset 0x4, size 0x8
    class hkConstraintAtom * m_atoms; // offset 0xC, size 0x4
    unsigned short m_atomsSize; // offset 0x10, size 0x2
    unsigned char m_callbackRequest; // offset 0x12, size 0x1
    class hkEnum m_priority; // offset 0x13, size 0x1
    unsigned short m_sizeOfSchemas; // offset 0x14, size 0x2
    unsigned short m_numSolverResults; // offset 0x16, size 0x2
    unsigned short m_numSolverElemTemps; // offset 0x18, size 0x2
    unsigned char m_whoIsMaster; // offset 0x1A, size 0x1
    class hkBool m_isNormalType; // offset 0x1B, size 0x1
    void * m_runtime; // offset 0x1C, size 0x4
    unsigned short m_runtimeSize; // offset 0x20, size 0x2
    unsigned short m_slaveIndex; // offset 0x22, size 0x2
};
// total size: 0x8
class compressed_pair_imp {
    // Members
public:
    class clsOOStlAllocator first_; // offset 0x0, size 0x4
    unsigned int second_; // offset 0x4, size 0x4
};
// total size: 0x8
class compressed_pair : private compressed_pair_imp {};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkAgentNnSector * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
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
// total size: 0x10
class hkShape : public hkReferencedObject {
    // Members
public:
    unsigned int m_userData; // offset 0x8, size 0x4
    class hkEnum m_type; // offset 0xC, size 0x4
};
// total size: 0x8
class _NNS_TEXLIST {
    // Members
public:
    signed int nTex; // offset 0x0, size 0x4
    class _NNS_TEXINFO * pTexInfoList; // offset 0x4, size 0x4
};
enum enmSystemFlag {
    SYSTEM_FLAG__CLEAR = 0,
    SYSTEM_FLAG__OBJ_PORTAL_FORWARD = 1,
};
// total size: 0x30
class hkLinkedCollidable : public hkCollidable {
    // Members
public:
    class hkArray m_collisionEntries; // offset 0x24, size 0xC
};
// total size: 0x4
class clsSingleton {};

// total size: 0xC0
class hkMotionState {
    // Members
public:
    class hkTransform m_transform; // offset 0x0, size 0x40
    class hkSweptTransform m_sweptTransform; // offset 0x40, size 0x50
    class hkVector4 m_deltaAngle; // offset 0x90, size 0x10
    float m_objectRadius; // offset 0xA0, size 0x4
    float m_maxLinearVelocity; // offset 0xA4, size 0x4
    float m_maxAngularVelocity; // offset 0xA8, size 0x4
    float m_linearDamping; // offset 0xAC, size 0x4
    float m_angularDamping; // offset 0xB0, size 0x4
    unsigned short m_deactivationClass; // offset 0xB4, size 0x2
    unsigned short m_deactivationCounter; // offset 0xB6, size 0x2
    unsigned int m_deactivationRefOrientation[2]; // offset 0xB8, size 0x8
};
// total size: 0x200
class hkAgentNnSector {
    // Members
public:
    unsigned char m_data[512]; // offset 0x0, size 0x200
};
// total size: 0x8
class hkEntityDeactivator : public hkReferencedObject {};
enum enmGear {
    GEAR_NON = -1,
    GEAR_USE_MODEL_START = 0,
    GEAR_BOARD_START = 0,
    GEAR_DUMMY_BOARD = 0,
    GEAR_BOARD = 1,
    GEAR_SUPER_BOARD = 2,
    GEAR_MAG = 3,
    GEAR_THROTTLE = 4,
    GEAR_GSHOT = 5,
    GEAR_GAMBLER = 6,
    GEAR_GC_BOOSTER = 7,
    GEAR_LEGEND = 8,
    GEAR_OMNITEMPOS_BOARD = 9,
    GEAR_BIKE_START = 10,
    GEAR_BIKE = 10,
    GEAR_SUPER_HANGON = 11,
    GEAR_RESERVE_TANK = 12,
    GEAR_MASTER_OFF_ROAD = 13,
    GEAR_OMNITEMPOS_BIKE = 14,
    GEAR_AIRRIDE_START = 15,
    GEAR_AIRRIDE = 15,
    GEAR_ANGELDEVIL = 16,
    GEAR_OMNITEMPOS_AIRRIDE = 17,
    GEAR_ANGELDEVIL_CHANGE = 18,
    GEAR_SURFING_START = 19,
    GEAR_SURFING = 19,
    GEAR_BINGO_STAR = 20,
    GEAR_WINDCATCHER = 21,
    GEAR_WHEEL_START = 22,
    GEAR_WHEEL = 22,
    GEAR_MONEY_CRISIS = 23,
    GEAR_BIG_BANG = 24,
    GEAR_MASTER_OFF_ROAD_WHELL = 25,
    GEAR_SPECIAL_START = 26,
    GEAR_SP_DURABILITY = 26,
    GEAR_SP_ALL_PARAM_UP = 27,
    GEAR_SP_ATTACK_TIME_UP = 28,
    GEAR_SP_GP_INFINITY = 29,
    GEAR_EFFECT_PARTS_START = 30,
    GEAR_SP_AGP = 30,
    GEAR_SP_MAX_SPEED = 31,
    GEAR_SP_1ST_SPEED = 32,
    GEAR_SP_GC_SPEED = 33,
    GEAR_SP_ADD_TRICK = 34,
    GEAR_SP_GHOST = 35,
    GEAR_SP_AUTO_WALL_RUN = 36,
    GEAR_SP_RING_CAPACITY = 37,
    GEAR_SP_MAG_BARRIER = 38,
    GEAR_SP_ITEM_RANK_UP = 39,
    GEAR_SP_SOUND_CHANGE = 40,
    GEAR_SP_TRAP_VIEW = 41,
    GEAR_SP_TRAP_CTRL = 42,
    GEAR_SP_TRAP_SPEED = 43,
    GEAR_SP_GP_GET_RATE = 44,
    GEAR_SP_THROTTLE = 45,
    GEAR_SP_TANK = 46,
    GEAR_SKATE_START = 47,
    GEAR_SKATE = 47,
    GEAR_RAILLINKER = 48,
    GEAR_WANTED = 49,
    GEAR_GRIND_START = 50,
    GEAR_GRIND = 50,
    GEAR_OMNITEMPOS_GRIND = 51,
    GEAR_EMPTY_START = 52,
    GEAR_EMPTY_GP = 52,
    GEAR_EMPTY_HD = 53,
    GEAR_MAX = 54,
    GEAR_BOARD_END = 9,
    GEAR_BIKE_END = 14,
    GEAR_AIRRIDE_END = 18,
    GEAR_SURFING_END = 21,
    GEAR_WHEEL_END = 25,
    GEAR_SPECIAL_END = 46,
    GEAR_EFFECT_PARTS_END = 46,
    GEAR_SKATE_END = 49,
    GEAR_GRIND_END = 51,
    GEAR_EMPTY_END = 53,
    GEAR_USE_MODEL_END = 29,
};
// total size: 0x7AD0
class clsPfCamera : public clsOOCamera {
    // Members
public:
    class clsOOCameraDebug m_cCamDebug; // offset 0x8, size 0x7814
    float m_sViewMtx[4][4]; // offset 0x7820, size 0x40
    float m_sBillBoardMtx[4][4]; // offset 0x7860, size 0x40
    float m_sYBillBoardMtx[4][4]; // offset 0x78A0, size 0x40
    float m_sPrjMtx[4][4]; // offset 0x78E0, size 0x40
    float m_sOrthoMtx[4][4]; // offset 0x7920, size 0x40
    float m_sClipMtx[4][4]; // offset 0x7960, size 0x40
    class NNS_CAMERA_TARGET_UPVECTOR m_sCamera; // offset 0x79A0, size 0x38
    class clsCamMixer * m_pcMixer; // offset 0x79D8, size 0x4
    class NNS_VECTORFAST m_sAxisX; // offset 0x79E0, size 0x10
    class NNS_VECTORFAST m_sAxisY; // offset 0x79F0, size 0x10
    class NNS_VECTORFAST m_sAxisZ; // offset 0x7A00, size 0x10
    class NNS_VECTORFAST m_sCameraPosVF; // offset 0x7A10, size 0x10
    float m_sBkupViewMtx[4][4]; // offset 0x7A20, size 0x40
    float m_sBkupPrjMtx44[4][4]; // offset 0x7A60, size 0x40
    float m_f32Left; // offset 0x7AA0, size 0x4
    float m_f32Right; // offset 0x7AA4, size 0x4
    float m_f32Top; // offset 0x7AA8, size 0x4
    float m_f32Bottom; // offset 0x7AAC, size 0x4
    float m_f32CamDist; // offset 0x7AB0, size 0x4
    float m_f32CamHeight; // offset 0x7AB4, size 0x4
    unsigned char m_u8DebugSetCamFlg; // offset 0x7AB8, size 0x1
    unsigned char m_u8LookPlayer; // offset 0x7AB9, size 0x1
    unsigned char m_u8DomeCamera; // offset 0x7ABA, size 0x1
    float m_f32DomeDist; // offset 0x7ABC, size 0x4
    signed int m_s32DomeRotY; // offset 0x7AC0, size 0x4
    signed int m_s32DomeRotX; // offset 0x7AC4, size 0x4
};
enum enmSoundStatus {
    SOUND_STATUS_NULL = 0,
    SOUND_STATUS_START = 1,
    SOUND_STATUS_CANCEL = 2,
    SOUND_STATUS_MOVE = 3,
    SOUND_STATUS_END = 4,
};
// total size: 0x4
class clsFlag {
    // Members
public:
    enum enmFlag m_tData; // offset 0x0, size 0x4
};
// total size: 0x8
class compressed_pair_imp {
    // Members
public:
    class value_compare first_; // offset 0x0, size 0x1
    class node * second_; // offset 0x4, size 0x4
};
// total size: 0x8
class hkSmallArray {
    // Members
public:
    class hkAction * * m_data; // offset 0x0, size 0x4
    unsigned short m_size; // offset 0x4, size 0x2
    unsigned short m_capacityAndFlags; // offset 0x6, size 0x2
};
// total size: 0x1
class allocator {};
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
// total size: 0x20
class clsModelType_OB_TX_MO_MA {
    // Members
public:
    class NNS_OBJECT * m_psObject; // offset 0x0, size 0x4
    class _NNS_TEXLIST * m_psTexList; // offset 0x4, size 0x4
    class NNS_MOTION * m_psMotion; // offset 0x8, size 0x4
    float m_f32MotionFrame; // offset 0xC, size 0x4
    class NNS_OBJECT * m_psMatMotObj; // offset 0x10, size 0x4
    class NNS_MOTION * m_psMatMotion; // offset 0x14, size 0x4
    unsigned int * m_psMatStatus; // offset 0x18, size 0x4
    float m_f32MatMotionFrame; // offset 0x1C, size 0x4
};
enum enmLinkType {
    LINK_TYPE_NULL = 0,
    LINK_TYPE_SPEED = 1,
    LINK_TYPE_FLY = 2,
    LINK_TYPE_POWER = 3,
};
// total size: 0x10
class hkInplaceArray : public hkArray {
    // Members
public:
    class hkAgentNnSector * m_storage[1]; // offset 0xC, size 0x4
};
// total size: 0x60
class clsPath {
    // Members
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
};
// total size: 0x20
class hkContactPoint {
    // Members
public:
    class hkVector4 m_position; // offset 0x0, size 0x10
    class hkVector4 m_separatingNormal; // offset 0x10, size 0x10
};
enum enmComType {
    COM_AI_TYPE_LEADER = 0,
    COM_AI_TYPE_NORMAL = 1,
    MAX_COM_AI_TYPE = 2,
};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkIslandPostCollideListener * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0xD0
class clsBaseEffect_Task : public clsTask {
    // Members
public:
    float m_sTrsMtx[4][4]; // offset 0x60, size 0x40
    float m_f32MotionFrame; // offset 0xA0, size 0x4
    float m_f32MatMotionFrame; // offset 0xA4, size 0x4
    float m_f32WaitFrame; // offset 0xA8, size 0x4
    float m_f32DrawScale; // offset 0xAC, size 0x4
    class clsModelType_OB_TX_MO_MA * m_pcModel; // offset 0xB0, size 0x4
    unsigned int m_eFlag; // offset 0xB4, size 0x4
    enum enmNo m_ePlayerNo; // offset 0xB8, size 0x4
    enum enmCalcNodePos m_eBornNo; // offset 0xBC, size 0x4
    unsigned int m_u32ViewNo; // offset 0xC0, size 0x4
    signed int m_s32RotZ; // offset 0xC4, size 0x4
};
// total size: 0x54
class stcData {
    // Members
public:
    float f32Speed[3]; // offset 0x0, size 0xC
    float f32Accele[3]; // offset 0xC, size 0xC
    float f32RotateSpeed; // offset 0x18, size 0x4
    float f32RotateAccele; // offset 0x1C, size 0x4
    float f32Grip; // offset 0x20, size 0x4
    float f32JumpSpeed; // offset 0x24, size 0x4
    float f32JumpAccele; // offset 0x28, size 0x4
    float f32Durability; // offset 0x2C, size 0x4
    unsigned int u32Ability; // offset 0x30, size 0x4
    float f32MaxAgp; // offset 0x34, size 0x4
    float f32GCtrlDischargeSpeed; // offset 0x38, size 0x4
    float f32GDiveSpeedRate; // offset 0x3C, size 0x4
    float f32GPTakeRate; // offset 0x40, size 0x4
    float f32GCtrlGpUseRate; // offset 0x44, size 0x4
    float f32GDiveGpUseRate; // offset 0x48, size 0x4
    signed int s32AttackEnableFrame; // offset 0x4C, size 0x4
    signed short s16RingCapacity; // offset 0x50, size 0x2
    signed char s8TrickRank; // offset 0x52, size 0x1
    signed char s8ItemRank; // offset 0x53, size 0x1
};
// total size: 0x10
class hkStepInfo {
    // Members
public:
    class hkPadSpu m_startTime; // offset 0x0, size 0x4
    class hkPadSpu m_endTime; // offset 0x4, size 0x4
    class hkPadSpu m_deltaTime; // offset 0x8, size 0x4
    class hkPadSpu m_invDeltaTime; // offset 0xC, size 0x4
};
// total size: 0x50
class clsGearSpTank : public clsGearPtnEffectPart {};
// total size: 0x20
class clsRetPath {
    // Members
public:
    unsigned short m_u16LineNo[8]; // offset 0x0, size 0x10
    unsigned short m_u16LineNum; // offset 0x10, size 0x2
    unsigned short m_u16ActiveLineNo; // offset 0x12, size 0x2
    unsigned short m_u16OldLineNo; // offset 0x14, size 0x2
    float m_f32DotPro; // offset 0x18, size 0x4
    float m_f32DotPro_Deg; // offset 0x1C, size 0x4
};
// total size: 0x4
class clsFlipTrickAction : public clsBaseTrickAction {};
enum enmFlag {
    FLAG_INFINI_CTRL = 1,
    FLAG_INFINI_DIVE = 2,
    FLAG_CLEAR = 0,
    FLAG_FULL = -1,
};
// total size: 0x7814
class clsOOCameraDebug {
    // Members
public:
    class NNS_VECTOR m_asCamPosV[512]; // offset 0x4, size 0x1800
    class NNS_VECTOR m_asTargetV[512][2]; // offset 0x1804, size 0x3000
    class NNS_VECTOR m_asCamUpV[512][2]; // offset 0x4804, size 0x3000
    signed int m_s32CurIdx; // offset 0x7804, size 0x4
    unsigned int m_u32DrawFlag; // offset 0x7808, size 0x4
    unsigned char m_u8No; // offset 0x780C, size 0x1
    unsigned int m_u32ActiveNum; // offset 0x7810, size 0x4
};
// total size: 0x10
class hkProperty {
    // Members
public:
    unsigned int m_key; // offset 0x0, size 0x4
    unsigned int m_alignmentPadding; // offset 0x4, size 0x4
    class hkPropertyValue m_value; // offset 0x8, size 0x8
};
// total size: 0xC
class vector : private __vector_imp {};
// total size: 0x14
class NNS_PRIM2D_PCT {
    // Members
public:
    class NNS_VECTOR2D Pos; // offset 0x0, size 0x8
    unsigned int Col; // offset 0x8, size 0x4
    class NNS_TEXCOORD Tex; // offset 0xC, size 0x8
};
// total size: 0x10
class hkCdBody {
    // Members
public:
    class hkShape * m_shape; // offset 0x0, size 0x4
    unsigned int m_shapeKey; // offset 0x4, size 0x4
    void * m_motion; // offset 0x8, size 0x4
    class hkCdBody * m_parent; // offset 0xC, size 0x4
};
// total size: 0x130
class hkShapePhantom : public hkPhantom {
    // Members
public:
    class hkMotionState m_motionState; // offset 0x70, size 0xC0
};
// total size: 0x10
class hkConstraintInfo {
    // Members
public:
    signed int m_maxSizeOfSchema; // offset 0x0, size 0x4
    signed int m_sizeOfSchemas; // offset 0x4, size 0x4
    signed int m_numSolverResults; // offset 0x8, size 0x4
    signed int m_numSolverElemTemps; // offset 0xC, size 0x4
};
// total size: 0x60
class clsGearSpThrottle : public clsGearPtnEffectPart {
    // Members
public:
    enum enmLevel m_eLevel; // offset 0x50, size 0x4
    enum enmDraw2DType m_eDraw2DType; // offset 0x54, size 0x4
    unsigned int m_u32SelectNo; // offset 0x58, size 0x4
    float m_f32SelectFrame; // offset 0x5C, size 0x4
};
// total size: 0x70
class clsInitialBoard : public clsGearPtnBoard {};
enum enmActionStatus {
    ACTION_STATUS_NULL = 0,
    ACTION_STATUS_INIT = 1,
    ACTION_STATUS_READY = 2,
    ACTION_STATUS_START = 3,
    ACTION_STATUS_MOVE = 4,
    ACTION_STATUS_FALL = 5,
};
// total size: 0x4
class stcBingoControl {
    // Members
public:
    signed char as8Rank[3]; // offset 0x0, size 0x3
    signed char s8RankNo; // offset 0x3, size 0x1
};
// total size: 0x8
class NNS_PRIMLISTPTR {
    // Members
public:
    unsigned int fType; // offset 0x0, size 0x4
    void * pPrimList; // offset 0x4, size 0x4
};
// total size: 0xC
class ContactRef {
    // Members
public:
    class hkProcessCdPoint * m_contactPoint; // offset 0x0, size 0x4
    class hkAgentEntry * m_agentEntry; // offset 0x4, size 0x4
    void * m_agentData; // offset 0x8, size 0x4
};
enum enmColUpdateType {
    COL_UPDATE_ALLFRAME = 0,
    COL_UPDATE_ONEFRAME = 1,
    COL_UPDATE_NOT_ONEFRAME = 2,
};
// total size: 0x50
class clsGravityActionManager {
    // Members
public:
    class clsPlayerTask * m_pcPlayer; // offset 0x0, size 0x4
    class hkSimpleShapePhantom * m_pcPhantom; // offset 0x4, size 0x4
    class clsBaseGravityAction * m_pcActions[3]; // offset 0x8, size 0xC
    class clsAdjustGravityAction_Object * m_pcAdjustGravityAction; // offset 0x14, size 0x4
    enum enmAction m_eAction; // offset 0x18, size 0x4
    enum enmType m_eType; // offset 0x1C, size 0x4
    enum enmSoundStatus m_eSoundStatus; // offset 0x20, size 0x4
    enum enmActionStatus m_eActionStatus; // offset 0x24, size 0x4
    class clsFlag m_cFlag; // offset 0x28, size 0x4
    float m_f32Point; // offset 0x2C, size 0x4
    float m_f32LinkBonusPoint; // offset 0x30, size 0x4
    float m_f32DrawPoint; // offset 0x34, size 0x4
    signed int m_s32LinkNum; // offset 0x38, size 0x4
    signed int m_s32BreakNum; // offset 0x3C, size 0x4
    float m_f32Radius; // offset 0x40, size 0x4
    float m_f32CtrlFrame; // offset 0x44, size 0x4
    float m_f32InvalidGCtrlFrame; // offset 0x48, size 0x4
    float m_f32DefaultInvalidGCtrlFrame; // offset 0x4C, size 0x4
};
// total size: 0x58
class clsDrawAttackEffect_Task : public clsTask {
    // Members
public:
    class clsCharacter * m_pcChara; // offset 0x54, size 0x4
};
// total size: 0xC
class vector : private __vector_imp {};
// total size: 0x4
class clsFlag {
    // Members
public:
    enum enmInfo m_tData; // offset 0x0, size 0x4
};
// total size: 0x50
class _NNS_TEXINFO {
    // Members
public:
    class NVS_SVROBJ SvrObj; // offset 0x0, size 0x30
    void * pMainMemory; // offset 0x30, size 0x4
    void * pLocalMemory; // offset 0x34, size 0x4
    unsigned int nLocalBytes; // offset 0x38, size 0x4
    unsigned int nDmaTagBytes; // offset 0x3C, size 0x4
    unsigned int GlobalIndex; // offset 0x40, size 0x4
    unsigned int Bank; // offset 0x44, size 0x4
    unsigned short MinFilter; // offset 0x48, size 0x2
    unsigned short MagFilter; // offset 0x4A, size 0x2
    unsigned int Flag; // offset 0x4C, size 0x4
};
enum enmRestartMode {
    RESTART_NORMAL = 0,
    RESTART_REPLAY = 1,
};
// total size: 0x8
class sceGsTex1 {
    // Members
public:
    unsigned long LCM : 1; // offset 0x0, size 0x4
    unsigned long pad01 : 1; // offset 0x0, size 0x4
    unsigned long MXL : 3; // offset 0x0, size 0x4
    unsigned long MMAG : 1; // offset 0x0, size 0x4
    unsigned long MMIN : 3; // offset 0x0, size 0x4
    unsigned long MTBA : 1; // offset 0x0, size 0x4
    unsigned long pad10 : 9; // offset 0x0, size 0x4
    unsigned long L : 2; // offset 0x0, size 0x4
    unsigned long pad21 : 11; // offset 0x0, size 0x4
    unsigned long K : 12; // offset 0x0, size 0x4
    unsigned long pad44 : 20; // offset 0x0, size 0x4
};
// total size: 0x110
class clsPrfm {
    // Members
public:
    class stcData m_sBase; // offset 0x0, size 0x54
    class stcData m_sWalk; // offset 0x54, size 0x54
    class stcData m_sData; // offset 0xA8, size 0x54
    class clsGearCtrl * m_pcGearCtrl; // offset 0xFC, size 0x4
    float m_f32WeightRate; // offset 0x100, size 0x4
    float m_f32InfiniGpFrame; // offset 0x104, size 0x4
    float m_f32AdjustSpeedRate; // offset 0x108, size 0x4
    float m_f32AdjustAcceleRate; // offset 0x10C, size 0x4
};
// total size: 0x7C
struct /* @anon4 */ {};
// total size: 0x4
class hkPadSpu {
    // Members
public:
    signed int m_storage; // offset 0x0, size 0x4
};
// total size: 0x3
class DebugEntry {
    // Members
public:
    char m_typeA; // offset 0x0, size 0x1
    char m_typeB; // offset 0x1, size 0x1
    char m_priority; // offset 0x2, size 0x1
};
// total size: 0x70
class clsGearReserveTank : public clsGearPtnBike {
    // Members
public:
    unsigned char m_u8RestRankCnt; // offset 0x60, size 0x1
};
// total size: 0x18
class map {
    // Members
public:
    class __tree tree_; // offset 0x0, size 0x18
};
// total size: 0x4C
struct /* @anon5 */ {};
// total size: 0x140
class hkSimpleShapePhantom : public hkShapePhantom {
    // Members
public:
    class hkArray m_collisionDetails; // offset 0x130, size 0xC
};
// total size: 0x60
class clsGearBasePrototype : public clsGear {
    // Members
public:
    signed int m_s32OldRunSeNo; // offset 0x50, size 0x4
    float m_f32RideChageFrame; // offset 0x54, size 0x4
    unsigned char m_u8CurveSeFlag; // offset 0x58, size 0x1
};
// total size: 0x18
class compressed_pair : private compressed_pair_imp {};
// total size: 0x34
class stcSetDataDetail {
    // Members
public:
    unsigned short u16Type; // offset 0x0, size 0x2
    union { // inferred
        unsigned char uniu8ViewportNum; // offset 0x2, size 0x1
        unsigned char uniu8MissionStageNo; // offset 0x2, size 0x1
    };
    unsigned char u8PortalType; // offset 0x3, size 0x1
    unsigned int u32GameModeSwitch; // offset 0x4, size 0x4
    unsigned int u32Attr; // offset 0x8, size 0x4
    class NNS_VECTOR sPosVec; // offset 0xC, size 0xC
    class NNS_VECTOR sRotVec; // offset 0x18, size 0xC
    class NNS_VECTOR sScaleVec; // offset 0x24, size 0xC
    unsigned int u32GroupNum; // offset 0x30, size 0x4
};
// total size: 0x0
class hkWorldMaintenanceMgr {};
// total size: 0x200
class hkEntity : public hkWorldObject {
    // Members
public:
    class hkMaterial m_material; // offset 0x58, size 0xC
    void * m_breakOffPartsUtil; // offset 0x64, size 0x4
    unsigned int m_solverData; // offset 0x68, size 0x4
    unsigned short m_storageIndex; // offset 0x6C, size 0x2
    unsigned short m_processContactCallbackDelay; // offset 0x6E, size 0x2
    class hkSmallArray m_constraintsMaster; // offset 0x70, size 0x8
    class hkArray m_constraintsSlave; // offset 0x78, size 0xC
    class hkArray m_constraintRuntime; // offset 0x84, size 0xC
    class hkEntityDeactivator * m_deactivator; // offset 0x90, size 0x4
    class hkSimulationIsland * m_simulationIsland; // offset 0x94, size 0x4
    signed char m_autoRemoveLevel; // offset 0x98, size 0x1
    unsigned int m_uid; // offset 0x9C, size 0x4
    class hkMaxSizeMotion m_motion; // offset 0xA0, size 0x130
    class hkSmallArray m_collisionListeners; // offset 0x1D0, size 0x8
    class hkSmallArray m_activationListeners; // offset 0x1D8, size 0x8
    class hkSmallArray m_entityListeners; // offset 0x1E0, size 0x8
    class hkSmallArray m_actions; // offset 0x1E8, size 0x8
    class SpuCollisionCallback m_spuCollisionCallback; // offset 0x1F0, size 0x8
};
// total size: 0xC
class compressed_pair : private compressed_pair_imp {};
// total size: 0xEC
class clsMagBarrier_Task : public clsSingleModelGimmick_Task {
    // Members
public:
    class clsOODeque m_tddqUseObj; // offset 0xAC, size 0x20
    class clsOODeque m_tddqUnUseObj; // offset 0xCC, size 0x20
};
// total size: 0x50
class clsGearSpCtrlTrap : public clsGearPtnEffectPart {};
// total size: 0xC
class __vector_imp : private __vector_deleter {};
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
// total size: 0xE40
class clsVaporTrail_Task : public clsTask {
    // Members
public:
    class stcBaseStatus * m_psBaseStatus; // offset 0x54, size 0x4
    class stcPlayStatus * m_psPlayStatus; // offset 0x58, size 0x4
    unsigned char m_u8Play; // offset 0x5C, size 0x1
    unsigned int m_u32Flg; // offset 0x60, size 0x4
    signed int m_s32PlayNum; // offset 0x64, size 0x4
    signed int m_s32MaxPlayNum; // offset 0x68, size 0x4
    unsigned int m_u32View; // offset 0x6C, size 0x4
    unsigned int m_u32PlayUser; // offset 0x70, size 0x4
    float m_f32AddSpeed; // offset 0x74, size 0x4
    class clsPlayerTask * m_pcPlayer; // offset 0x78, size 0x4
    class clsTask * m_pcEffectTask; // offset 0x7C, size 0x4
    class stcParam m_asTrails[10]; // offset 0x80, size 0xDC0
};
// total size: 0xC
class __vector_imp : private __vector_deleter {};

// total size: 0x110
class clsGearCtrl {
    // Members
public:
    class clsGear * m_apcGear[4]; // offset 0x4, size 0x10
    class clsInitialBoard * m_pcInitBoardGear; // offset 0x14, size 0x4
    unsigned char m_abIsAlreadyUsed[4]; // offset 0x18, size 0x4
    unsigned char m_abIsLocked[4]; // offset 0x1C, size 0x4
    float m_af32CloseWaitFrame[4]; // offset 0x20, size 0x10
    class clsGear * m_apcEquipsGears[5]; // offset 0x30, size 0x14
    class clsGear * m_pcOldChangeGear; // offset 0x44, size 0x4
    class clsGearBaseParts * m_pcOldParts; // offset 0x48, size 0x4
    class clsGearBaseParts * m_pcNewParsGear; // offset 0x4C, size 0x4
    class stcCtrlData * m_posData; // offset 0x50, size 0x4
    enum enmGearCtrl m_eCtrlNo; // offset 0x54, size 0x4
    unsigned int m_u32InitEquipsGears; // offset 0x58, size 0x4
    class stcAddPrfm m_sAddPrfmData; // offset 0x5C, size 0x6C
    class clsPlayerTask * m_pcPlayer; // offset 0xC8, size 0x4
    enum enmCtrlMode m_eCtrlMode; // offset 0xCC, size 0x4
    enum enmActionMode m_eActionMode; // offset 0xD0, size 0x4
    float m_f32DrawAlpha; // offset 0xD4, size 0x4
    unsigned char m_u8MaxGearNum; // offset 0xD8, size 0x1
    signed char m_s8RunChannel_ICS; // offset 0xD9, size 0x1
    signed char m_s8MonumentFlyChannel_ICS; // offset 0xDA, size 0x1
    unsigned char m_bIsPlayMonumentFly; // offset 0xDB, size 0x1
    unsigned char m_bSeWalkFlag; // offset 0xDC, size 0x1
    unsigned char m_bIsDrawActiveGear; // offset 0xDD, size 0x1
    unsigned char m_bIsDrawBurnLight; // offset 0xDE, size 0x1
    unsigned int m_u32EffectType; // offset 0xE0, size 0x4
    float m_f32EffectFrameEx; // offset 0xE4, size 0x4
    class _Draw2DData m_sDraw2DData; // offset 0xE8, size 0x24
    class clsModelType_OB_TX * m_pcInitBoardGearModel; // offset 0x10C, size 0x4
};
enum enmInfo {
    TYPE_NULL = 0,
    TYPE_GROUND = 1,
    TYPE_THROUGH = 2,
    TYPE_PLAYER = 4,
    TYPE_ITEM = 8,
    TYPE_RING = 16,
    TYPE_GIMMICK = 32,
    TYPE_GIMMICK_WALL = 64,
    TYPE_GIMMICK_CLOG = 128,
    TYPE_GRAVITY = 256,
    TYPE_GLINK = 512,
    TYPE_WALL_WALK = 1024,
    TYPE_WALL_GRAVITY = 2048,
    TYPE_DEAD = 4096,
    FILTER_NULL = 0,
    FILTER_GROUND = 65536,
    FILTER_THROUGH = 131072,
    FILTER_PLAYER = 262144,
    FILTER_ITEM = 524288,
    FILTER_RING = 1048576,
    FILTER_GIMMICK = 2097152,
    FILTER_GIMMICK_WALL = 4194304,
    FILTER_GIMMICK_CLOG = 8388608,
    FILTER_GRAVITY = 16777216,
    FILTER_GLINK = 33554432,
    FILTER_WALL_GRAVITY = 134217728,
    FILTER_WALL_WALK = 67108864,
    FILTER_DEAD = 268435456,
    TYPE_MASK = 65535,
    FILTER_MASK = -65536,
    FULL_MASK = -1,
    CLEAR_MASK = 0,
    TYPE_GIMMICK_MASK = 33554728,
    DEFAULT_PLAYER = 352256004,
    DEFAULT_COM = 352256004,
    CLIP_COM = 342294532,
    DEFAULT_GROUND = 1,
    DEFAULT_THROUGH = 262146,
    SAME_NONHIT_GIMMICK = 16842784,
    DEFAULT_GIMMICK = 14745632,
    DEFAULT_GIMMICK_WALL = 14745664,
    DEFAULT_GIMMICK_CLOG = 14745728,
    DEFAULT_GRAVITY_GIMMICK = 18939936,
    DEFAULT_GLINK_GIMMICK = 35717632,
};
// total size: 0xC
class hkGskCache {
    // Members
public:
    unsigned short m_vertices[4]; // offset 0x0, size 0x8
    unsigned char m_dimA; // offset 0x8, size 0x1
    unsigned char m_dimB; // offset 0x9, size 0x1
    unsigned char m_maxDimA; // offset 0xA, size 0x1
    unsigned char m_maxDimB; // offset 0xB, size 0x1
};
// total size: 0x50
class clsPortal {
    // Members
public:
    class stcPortalBin * m_psPortalBin; // offset 0x4, size 0x4
    class stcPortalBelongType m_asPortalBelongType[4]; // offset 0x8, size 0x10
    enum enmPortalType m_ePortalType; // offset 0x18, size 0x4
    unsigned int m_abEnableFrontBack[4]; // offset 0x1C, size 0x10
    unsigned int m_abDisableFrontBack[4]; // offset 0x2C, size 0x10
    unsigned int m_abEnableBackIs3[4]; // offset 0x3C, size 0x10
    unsigned char m_bReverse; // offset 0x4C, size 0x1
};
// total size: 0x4
class clsPartsTrickAction : public clsFreeTrickAction {};
// total size: 0x14
class NNS_SUBOBJ {
    // Members
public:
    unsigned int fType; // offset 0x0, size 0x4
    signed int nMeshset; // offset 0x4, size 0x4
    class NNS_MESHSET * pMeshsetList; // offset 0x8, size 0x4
    signed int nTex; // offset 0xC, size 0x4
    signed int * pTexNumList; // offset 0x10, size 0x4
};
// total size: 0x14
class clsOOList : public list {};
// total size: 0x4
class clsSingleton {};
// total size: 0x160
class clsTrickManager {
    // Members
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
};
// total size: 0x18
class map {
    // Members
public:
    class __tree tree_; // offset 0x0, size 0x18
};
// total size: 0x8
class compressed_pair_imp {
    // Members
public:
    class clsOOStlAllocator first_; // offset 0x0, size 0x4
    class anchor second_; // offset 0x4, size 0x4
};
// total size: 0x8
class hkSmallArray {
    // Members
public:
    class hkEntityListener * * m_data; // offset 0x0, size 0x4
    unsigned short m_size; // offset 0x4, size 0x2
    unsigned short m_capacityAndFlags; // offset 0x6, size 0x2
};
// total size: 0xC
class compressed_pair_imp {
    // Members
public:
    class clsOOStlAllocator first_; // offset 0x0, size 0x4
    class node_base second_; // offset 0x4, size 0x8
};
// total size: 0x20
class stcGimickSubParam {
    // Members
public:
    class NNS_VECTORFAST sStartFast; // offset 0x0, size 0x10
    class NNS_VECTORFAST sPowerFast; // offset 0x10, size 0x10
};
// total size: 0x18
class clsGmkManager : public clsSingleton {
    // Members
public:
    class clsOOList m_tdpcGimmick; // offset 0x4, size 0x14
};
// total size: 0x60
class clsGearAngelOrDevil : public clsGearPtnAirride {};
// total size: 0x30
class hkCollisionFilter : public hkReferencedObject, public hkCollidableCollidableFilter, public hkShapeCollectionFilter, public hkRayShapeCollectionFilter, public hkRayCollidableFilter {
    // Members
public:
    class hkEnum m_type; // offset 0x20, size 0x4
    unsigned int m_pad[3]; // offset 0x24, size 0xC
};
// total size: 0x20
class hkModifierConstraintAtom : public hkConstraintAtom {
    // Members
public:
    unsigned short m_modifierAtomSize; // offset 0x10, size 0x2
    unsigned short m_childSize; // offset 0x12, size 0x2
    class hkConstraintAtom * m_child; // offset 0x14, size 0x4
    unsigned int m_pad[2]; // offset 0x18, size 0x8
};
// total size: 0x8
class NNS_MORPHTARGETLIST {
    // Members
public:
    signed int nMorphTarget; // offset 0x0, size 0x4
    class NNS_MORPHTARGETPTR * pMorphTargetPtrList; // offset 0x4, size 0x4
};
// total size: 0x24
class hkCollidable : public hkCdBody {
    // Members
public:
    signed char m_ownerOffset; // offset 0x10, size 0x1
    unsigned char m_forceCollideOntoPpu; // offset 0x11, size 0x1
    unsigned short m_shapeSizeOnSpu; // offset 0x12, size 0x2
    class hkTypedBroadPhaseHandle m_broadPhaseHandle; // offset 0x14, size 0xC
    float m_allowedPenetrationDepth; // offset 0x20, size 0x4
};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkIslandPostIntegrateListener * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x7C
struct /* @anon6 */ {};
// total size: 0x4
class hkEnum {
    // Members
public:
    unsigned int m_storage; // offset 0x0, size 0x4
};
// total size: 0x4
class hkEntityListener {};
// total size: 0x8
class NNS_VECTOR2D {
    // Members
public:
    float x; // offset 0x0, size 0x4
    float y; // offset 0x4, size 0x4
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
// total size: 0x30
class hkProcessCdPoint {
    // Members
public:
    class hkContactPoint m_contact; // offset 0x0, size 0x20
    class hkPadSpu m_contactPointId; // offset 0x20, size 0x4
};
// total size: 0x14
class list : private __list_imp {};
// total size: 0x260
class clsPlayerStartPointCollector : public hkAllCdPointCollector {
    // Members
public:
    class clsRigidBodyCollectorInfo m_cRigidBodyInfo; // offset 0x1A0, size 0x5C
    class clsPhantomCollectorInfo m_cPhantomInfo; // offset 0x1FC, size 0x5C
    class clsPlayerTask * m_pcPlayer; // offset 0x258, size 0x4
};
// total size: 0xC
class __vector_deleter {
    // Members
public:
    class compressed_pair capacity_; // offset 0x0, size 0x4
    unsigned int size_; // offset 0x4, size 0x4
    class clsGravityGimmickCalculation * data_; // offset 0x8, size 0x4
};
enum Type {
    TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR = 0,
    TYPE_REPORT_CONTACT_MGR = 1,
    TYPE_CONVEX_LIST_CONTACT_MGR = 2,
    TYPE_NULL_CONTACT_MGR = 3,
    TYPE_USER_CONTACT_MGR = 4,
    TYPE_MAX = 5,
};
// total size: 0x8
class hkSmallArray {
    // Members
public:
    class hkEntityActivationListener * * m_data; // offset 0x0, size 0x4
    unsigned short m_size; // offset 0x4, size 0x2
    unsigned short m_capacityAndFlags; // offset 0x6, size 0x2
};
// total size: 0x0
class hkIslandPostIntegrateListener {};
// total size: 0x4C
struct /* @anon7 */ {};
// total size: 0x4
class clsOOStlAllocator {
    // Members
public:
    class clsOOHeapFragment * m_pcHeap; // offset 0x0, size 0x4
};
// total size: 0x150
class clsSimpleShapePhantom : public hkSimpleShapePhantom {
    // Members
public:
    void * m_pvUserData01; // offset 0x140, size 0x4
};
// total size: 0xC
class __vector_deleter {
    // Members
public:
    class compressed_pair capacity_; // offset 0x0, size 0x4
    unsigned int size_; // offset 0x4, size 0x4
    class _KeyBuf * data_; // offset 0x8, size 0x4
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
// total size: 0x50
class hkSweptTransform {
    // Members
public:
    class hkVector4 m_centerOfMass0; // offset 0x0, size 0x10
    class hkVector4 m_centerOfMass1; // offset 0x10, size 0x10
    class hkQuaternion m_rotation0; // offset 0x20, size 0x10
    class hkQuaternion m_rotation1; // offset 0x30, size 0x10
    class hkVector4 m_centerOfMassLocal; // offset 0x40, size 0x10
};
// total size: 0x8
class NNS_VTXLISTPTR {
    // Members
public:
    unsigned int fType; // offset 0x0, size 0x4
    void * pVtxList; // offset 0x4, size 0x4
};
// total size: 0x8C
class clsReInitGraphics_Task : public clsTask {
    // Members
public:
    unsigned char m_au8FogNo[4]; // offset 0x54, size 0x4
    class stcBinDataDetail * m_aopsBinDataDetail_FogNow[4]; // offset 0x58, size 0x10
    class stcBinDataDetail * m_aopsBinDataDetail_FogDst[4]; // offset 0x68, size 0x10
    float m_af32ChangeFogTime[4]; // offset 0x78, size 0x10
    unsigned int bDisableChangeFog; // offset 0x88, size 0x4
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
// total size: 0x8
class hkPropertyValue {
    // Members
public:
    unsigned long m_data; // offset 0x0, size 0x4
};
// total size: 0x0
class hkEntityActivationListener {};
// total size: 0xC
class clsGravityGimmickCalculation {
    // Members
public:
    class clsRigidBodyGimmickObj * m_pcObject; // offset 0x0, size 0x4
    enum enmType m_eType; // offset 0x4, size 0x4
    float m_f32Distance; // offset 0x8, size 0x4
};
// total size: 0x98C0
class clsPlayerDebug {
    // Members
public:
    float m_sDrawSphereMtx[4][4]; // offset 0x0, size 0x40
    class NNS_VECTORFAST m_sFixPosVecFast; // offset 0x40, size 0x10
    class NNS_VECTORFAST m_sDistVecFast[2]; // offset 0x50, size 0x20
    class NNS_VECTOR m_asNrmLineBuff[512][2]; // offset 0x70, size 0x3000
    class NNS_VECTOR m_asPstLineBuff[512][2]; // offset 0x3070, size 0x3000
    class NNS_VECTOR m_asVlcLineBuff[512][2]; // offset 0x6070, size 0x3000
    class NNS_VECTOR m_asDrawLine[2]; // offset 0x9070, size 0x18
    class clsPlayerTask * m_pcPlayer; // offset 0x9088, size 0x4
    enum enmMode m_eMode; // offset 0x908C, size 0x4
    enum enmFlag m_eFlag; // offset 0x9090, size 0x4
    float m_f32Speed; // offset 0x9094, size 0x4
    float m_f32Distance; // offset 0x9098, size 0x4
    float m_f32TimerMin; // offset 0x909C, size 0x4
    float m_f32TimerSec; // offset 0x90A0, size 0x4
    float m_f32TimerMSec; // offset 0x90A4, size 0x4
    float m_f32JumpHeight; // offset 0x90A8, size 0x4
    signed int m_s32ActiveLineBuffNo; // offset 0x90AC, size 0x4
    unsigned int m_u32DrawLineColor; // offset 0x90B0, size 0x4
    signed int m_s32MaxSpeed; // offset 0x90B4, size 0x4
    signed int m_s32Accele; // offset 0x90B8, size 0x4
    float m_f32GripRate; // offset 0x90BC, size 0x4
    float m_f32CountFrame; // offset 0x90C0, size 0x4
    unsigned int m_u32SphereColor; // offset 0x90C4, size 0x4
    float m_f32DrawSphereFrame; // offset 0x90C8, size 0x4
    signed char m_s8JumpFlag; // offset 0x90CC, size 0x1
    unsigned char m_bIsSelectRestart; // offset 0x90CD, size 0x1
    signed char m_s8GearAlpha; // offset 0x90CE, size 0x1
    class vector m_vecDrawSphere; // offset 0x90D0, size 0xC
    class vector m_vecDrawSphereOld; // offset 0x90DC, size 0xC
    class _DebugDrawSphere m_sDrawSphere[100]; // offset 0x90E8, size 0x7D0
};
// total size: 0x18
class stcViewRect {
    // Members
public:
    float f32wd; // offset 0x0, size 0x4
    float f32hw; // offset 0x4, size 0x4
    float f32OffsetX; // offset 0x8, size 0x4
    float f32OffsetY; // offset 0xC, size 0x4
    float f32Width; // offset 0x10, size 0x4
    float f32Height; // offset 0x14, size 0x4
};
enum enmRank {
    RANK_FAILED = -1,
    RANK_AUTO = 0,
    RANK_C = 0,
    RANK_B = 1,
    RANK_A = 2,
    RANK_AA = 3,
    RANK_S = 4,
    RANK_SS = 5,
    RANK_X = 6,
    RANK_MAX = 7,
};
// total size: 0x24
class clsGravityGimmickManager : public clsSingleton {
    // Members
public:
    signed int m_s32MaxNum; // offset 0x4, size 0x4
    signed int m_s32MinNum; // offset 0x8, size 0x4
    class vector m_vecCalcArray; // offset 0xC, size 0xC
    class vector m_vecDeleteArray; // offset 0x18, size 0xC
};
// total size: 0x18
class clsOOMMap : public multimap {};
// total size: 0xD0
class clsSlipStream {
    // Members
public:
    class stcData m_sData[4]; // offset 0x0, size 0xC0
    enum enmStatus m_eStatus; // offset 0xC0, size 0x4
    float m_f32UpdateCount; // offset 0xC4, size 0x4
    unsigned int m_u32PointNo; // offset 0xC8, size 0x4
};
// total size: 0x80
class clsGearMag : public clsGearPtnBoard {
    // Members
public:
    class NNS_VECTOR * m_psTranslation; // offset 0x70, size 0x4
};
// total size: 0x24
class _Draw2DData {
    // Members
public:
    enum enmDraw2DGearMode aeGearMode[3]; // offset 0x0, size 0xC
    enum enmDraw2DType aeDrawType[3]; // offset 0xC, size 0xC
    enum enmLevel eNextChangeGearLv; // offset 0x18, size 0x4
    enum enmLevel ePrevChangeGearLv; // offset 0x1C, size 0x4
    unsigned char u8DataNum; // offset 0x20, size 0x1
};
// total size: 0x4
class compressed_pair : private compressed_pair_imp {};
// total size: 0x18
class stcBinDataDetail {
    // Members
public:
    float f32Near; // offset 0x0, size 0x4
    float f32Far; // offset 0x4, size 0x4
    float f32r; // offset 0x8, size 0x4
    float f32g; // offset 0xC, size 0x4
    float f32b; // offset 0x10, size 0x4
    float f32InertiaK; // offset 0x14, size 0x4
};
// total size: 0x30
class stcLine {
    // Members
public:
    class NNS_CAPSULE * psCapsule; // offset 0x0, size 0x4
    class NNS_VECTORFAST * psPointVec; // offset 0x4, size 0x4
    class NNS_VECTORFAST * psNormalVec; // offset 0x8, size 0x4
    class NNS_SPHERE sLimitSph; // offset 0xC, size 0x10
    unsigned short u16Num; // offset 0x1C, size 0x2
    unsigned short u16Attr; // offset 0x1E, size 0x2
    // total size: 0x10
    class /* @class */ {
        // Members
    public:
        union { // inferred
            signed char s8Data[16]; // offset 0x0, size 0x10
            class stcSpeedPath sSpeed; // offset 0x0, size 0x10
            class stcGravityPath sGravity; // offset 0x0, size 0x10
            class stcGDivePath sGDive; // offset 0x0, size 0x10
        };
    } uniData; // offset 0x20, size 0x10
};
// total size: 0x1
class hkPadSpu {
    // Members
public:
    class hkBool m_storage; // offset 0x0, size 0x1
};
// total size: 0x10
class stcInfo {
    // Members
public:
    unsigned char u8Effect; // offset 0x0, size 0x1
    unsigned char u8Attr; // offset 0x1, size 0x1
    unsigned char u8Filter; // offset 0x2, size 0x1
    signed char s8Grip; // offset 0x3, size 0x1
    unsigned char u8Union[4]; // offset 0x4, size 0x4
    float f32Param; // offset 0x8, size 0x4
    unsigned int u32Reserved; // offset 0xC, size 0x4
};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkCollisionDetail * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x4
class compressed_pair : private compressed_pair_imp {};
// total size: 0x130
class hkKeyframedRigidMotion : public hkMotion {
    // Members
public:
    class hkMaxSizeMotion * m_savedMotion; // offset 0x120, size 0x4
    signed int m_savedQualityTypeIndex; // offset 0x124, size 0x4
};

// total size: 0xC
class hkArray {
    // Members
public:
    class hkWorldPostCollideListener * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x14
class clsPathCom : public clsPathPoint {};
// total size: 0x14
class list : private __list_imp {};
// total size: 0xD0
class clsTrickParam {
    // Members
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
    enum enmKicker m_eKickerType; // offset 0x64, size 0x4
    enum enmStartType m_eStartType; // offset 0x68, size 0x4
    enum enmRank m_eBaseRank; // offset 0x6C, size 0x4
    enum enmRank m_eRank; // offset 0x70, size 0x4
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
    enum enmKicker m_eDebugKickerType; // offset 0xB8, size 0x4
    enum enmRank m_eDebugTrickRank; // offset 0xBC, size 0x4
    signed char m_s8DebugKeyDir; // offset 0xC0, size 0x1
};
// total size: 0x28
class hkSimulation : public hkReferencedObject {
    // Members
public:
    class hkWorld * m_world; // offset 0x8, size 0x4
    enum LastProcessingStep m_lastProcessingStep; // offset 0xC, size 0x4
    float m_currentTime; // offset 0x10, size 0x4
    float m_currentPsiTime; // offset 0x14, size 0x4
    float m_physicsDeltaTime; // offset 0x18, size 0x4
    float m_simulateUntilTime; // offset 0x1C, size 0x4
    float m_frameMarkerPsiSnap; // offset 0x20, size 0x4
    enum hkStepResult m_previousStepResult; // offset 0x24, size 0x4
};
// total size: 0x24
class NNS_MESHSET {
    // Members
public:
    class NNS_VECTOR Center; // offset 0x0, size 0xC
    float Radius; // offset 0xC, size 0x4
    signed int iNode; // offset 0x10, size 0x4
    signed int iMatrix; // offset 0x14, size 0x4
    signed int iMaterial; // offset 0x18, size 0x4
    signed int iVtxList; // offset 0x1C, size 0x4
    signed int iPrimList; // offset 0x20, size 0x4
};
// total size: 0x40
class hkTransform {
    // Members
public:
    class hkRotation m_rotation; // offset 0x0, size 0x30
    class hkVector4 m_translation; // offset 0x30, size 0x10
};
// total size: 0x0
class hkDebugInfoOnPendingOperationQueues {};
// total size: 0xC
class hkArray {
    // Members
public:
    class ShapeInheritance * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x18
class clsOOMap : public map {};
// total size: 0x8
class NNS_MORPHTARGETPTR {
    // Members
public:
    signed int nVtxList; // offset 0x0, size 0x4
    class NNS_VTXLISTPTR * pMorphTarget; // offset 0x4, size 0x4
};
// total size: 0x1
class value_compare : public binary_function {
    // Members
public:
    class less comp; // offset 0x0, size 0x1
};
// total size: 0x160
class stcParam {
    // Members
public:
    unsigned short u16Flg; // offset 0x0, size 0x2
    unsigned char u8Num; // offset 0x2, size 0x1
    unsigned char u8MaxAlpha; // offset 0x3, size 0x1
    signed int s32No; // offset 0x4, size 0x4
    signed int s32RotZ; // offset 0x8, size 0x4
    float f32Frame; // offset 0xC, size 0x4
    float f32Tu; // offset 0x10, size 0x4
    float f32TuSize; // offset 0x14, size 0x4
    class NNS_VECTOR sPos; // offset 0x18, size 0xC
    class NNS_VECTOR sScale; // offset 0x24, size 0xC
    class NNS_VECTOR sAddScale; // offset 0x30, size 0xC
    class NNS_VECTOR sVec; // offset 0x3C, size 0xC
    class NNS_VECTOR sPower; // offset 0x48, size 0xC
    float sDrawMtx[4][4]; // offset 0x60, size 0x40
    class NNS_VECTOR asDrawPos[16]; // offset 0xA0, size 0xC0
};
// total size: 0x8
class node_base {
    // Members
public:
    class node * prev_; // offset 0x0, size 0x4
    class node * next_; // offset 0x4, size 0x4
};
// total size: 0x70
class hkPhantom : public hkWorldObject {
    // Members
public:
    class hkArray m_overlapListeners; // offset 0x58, size 0xC
    class hkArray m_phantomListeners; // offset 0x64, size 0xC
};
enum enmSoundMode {
    SOUND_MODE___MONAURAL = 0,
    SOUND_MODE___STEREO = 1,
    SOUND_MODE___DOLBY_PROLOGIC2 = 2,
    SOUND_MODE___DOLBY_DIGITAL = 3,
    SOUND___MAX = 4,
};
// total size: 0x50
class clsGearSpMagBarrier : public clsGearPtnEffectPart {};
// total size: 0x18
class stcWaterDropStatus {
    // Members
public:
    signed int s32NextDataNo; // offset 0x0, size 0x4
    unsigned char bSnow; // offset 0x4, size 0x1
    float f32Frame; // offset 0x8, size 0x4
    float f32EndFrame; // offset 0xC, size 0x4
    unsigned int u32Num; // offset 0x10, size 0x4
    float f32LifeFrame; // offset 0x14, size 0x4
};
// total size: 0x4
class compressed_pair_imp : private allocator {
    // Members
public:
    unsigned int second_; // offset 0x0, size 0x4
};
// total size: 0x4
class clsOOStlAllocator {
    // Members
public:
    class clsOOHeapFragment * m_pcHeap; // offset 0x0, size 0x4
};
// total size: 0x14
class clsLimitTime {
    // Members
public:
    class stcRateTime m_sRateTime; // offset 0x0, size 0x10
    float m_f32LimitTime; // offset 0x10, size 0x4
};
// total size: 0xC
class vector : private __vector_imp {};
// total size: 0x30
class NVS_SVROBJ {
    // Members
public:
    class NVS_GBIXHEADER gbixh; // offset 0x0, size 0x8
    class NVS_SVRHEADER svrh; // offset 0x8, size 0x8
    class PXS_TEXOBJ texobj; // offset 0x10, size 0x20
};
// total size: 0x1
class binary_function {};
// total size: 0x6C
class clsGmkBurnLight_Task : public clsTask {
    // Members
public:
    float (* m_psMtxWork_Mutable)[4][4]; // offset 0x54, size 0x4
    float * m_pf32MotionFrame; // offset 0x58, size 0x4
    float * m_pf32MatMotionFrame; // offset 0x5C, size 0x4
    class clsModelType_OB_TX_MO_MA & m_rcModel; // offset 0x60, size 0x4
    signed short m_16ObjectNum; // offset 0x64, size 0x2
    signed short m_s16DrawNum; // offset 0x66, size 0x2
    signed char m_s8DrawNodeNo; // offset 0x68, size 0x1
};
enum enmPortalType {
    MAP = 0,
    OBJ = 1,
};
enum enmLevel {
    LV_ERROR = -1,
    LV_BASE = 0,
    LV_01 = 1,
    LV_02 = 2,
    LV_03 = 3,
    MAX_LV_NUM = 4,
    MAX_LV_TABLE_NUM = 4,
    MAX_MODELS = 9,
};
// total size: 0x4
class hkPadSpu {
    // Members
public:
    class hkProcessCollisionInput * m_storage; // offset 0x0, size 0x4
};
enum enmFlag {
    FLAG_CLEAR = 0,
    FLAG_NOT_GRAVITY = 1,
};
// total size: 0x8
class compressed_pair : private compressed_pair_imp {};
// total size: 0x34
class clsPlayerKey {
    // Members
public:
    class _KeyBuf m_sKeyData; // offset 0x0, size 0x8
    unsigned int m_u32OldState; // offset 0x8, size 0x4
    unsigned int m_u32KeyMask; // offset 0xC, size 0x4
    float m_f32StiffFrame; // offset 0x10, size 0x4
    signed char m_s8OldLeverX; // offset 0x14, size 0x1
    signed char m_s8OldLeverY; // offset 0x15, size 0x1
    enum enmStiffType m_eStiffType; // offset 0x18, size 0x4
    unsigned char m_bValidFlag; // offset 0x1C, size 0x1
    class stcExtensionData m_sExtension; // offset 0x20, size 0x10
};
// total size: 0x2E0
class clsPlayerPhysic {
    // Members
public:
    class clsPlayerTask * m_pcPlayer; // offset 0x0, size 0x4
    class hkCharacterProxy * m_pcProxy; // offset 0x4, size 0x4
    class hkSimpleShapePhantom * m_pcPhantom; // offset 0x8, size 0x4
    class hkShape * m_pcShape; // offset 0xC, size 0x4
    class clsSimpleShapePhantom * m_pcAttackPhantom; // offset 0x10, size 0x4
    class clsPlayerStartPointCollector m_cStartPointCollect; // offset 0x20, size 0x260
    class stcInfo m_sColInfo[2]; // offset 0x280, size 0x20
    class stcInfo m_sPreviousColInfo; // offset 0x2A0, size 0x10
    enum enmColCheckType m_eCollisionCheckType; // offset 0x2B0, size 0x4
    float m_f32AttackRadius; // offset 0x2B4, size 0x4
    float m_f32Radius; // offset 0x2B8, size 0x4
    unsigned int m_u32HitFlg; // offset 0x2BC, size 0x4
    float m_f32InvalidFrame; // offset 0x2C0, size 0x4
    unsigned char m_bIsAttack; // offset 0x2C4, size 0x1
    unsigned char m_u8ColInfoNo; // offset 0x2C5, size 0x1
    class clsFlag m_cMaskColFilter; // offset 0x2C8, size 0x4
    enum enmColUpdateType m_enColUpdateType; // offset 0x2CC, size 0x4
    class hkVector4 m_cBackupVelocity; // offset 0x2D0, size 0x10
};
// total size: 0xC
class __vector_deleter {
    // Members
public:
    class compressed_pair capacity_; // offset 0x0, size 0x4
    unsigned int size_; // offset 0x4, size 0x4
    class stcCamCtrlStock * data_; // offset 0x8, size 0x4
};
enum enmWallType {
    WALL_TYPE__NORMAL = 0,
    WALL_TYPE__WII = 1,
    WALL_TYPE__SPECIAL = 2,
    WALL_TYPE__VERTICAL = 3,
};
// total size: 0x4
class hkPadSpu {
    // Members
public:
    class hkConstraintOwner * m_storage; // offset 0x0, size 0x4
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
// total size: 0xC
class node : public node_base {
    // Members
public:
    void * data_; // offset 0x8, size 0x4
};
// total size: 0x10
class hkVector4 {
    // Members
public:
    float x; // offset 0x0, size 0x4
    float y; // offset 0x4, size 0x4
    float z; // offset 0x8, size 0x4
    float w; // offset 0xC, size 0x4
};
// total size: 0x8
class stcMotionTable {
    // Members
public:
    unsigned int u32Num; // offset 0x0, size 0x4
    unsigned int u32FileSize; // offset 0x4, size 0x4
    class NNS_MOTION * aspTable[]; // offset 0x8, size 0x0
};
// total size: 0x4
class clsObject {};
// total size: 0x34
class clsOOHeapFragment {
    // Members
public:
    class stcFree * m_psAddrLo; // offset 0x4, size 0x4
    class stcFree * m_psDefaultAddrLo; // offset 0x8, size 0x4
    class stcFree * m_psAddrHi; // offset 0xC, size 0x4
    class stcFree * m_psDefaultAddrHi; // offset 0x10, size 0x4
    signed int m_s32AllRestSize; // offset 0x14, size 0x4
    signed int m_s32AllocSizeLo; // offset 0x18, size 0x4
    signed int m_s32AllocSizeHi; // offset 0x1C, size 0x4
    class clsPfSemaphore m_cOOSemaphore; // offset 0x20, size 0x8
    class clsPfSemaphore m_cOOSemaphoreUpperNest; // offset 0x28, size 0x8
    unsigned short m_u16LoCnt_Debug; // offset 0x30, size 0x2
    unsigned short m_u16HiCnt_Debug; // offset 0x32, size 0x2
};
// total size: 0x1C
class NNS_CAPSULE {
    // Members
public:
    class NNS_VECTOR c1; // offset 0x0, size 0xC
    class NNS_VECTOR c2; // offset 0xC, size 0xC
    float r; // offset 0x18, size 0x4
};
// total size: 0x1
class allocator {};
// total size: 0xC
class __vector_imp : private __vector_pod, private compile_assert {};
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
// total size: 0xF5D0
class clsCamMixer {
    // Members
public:
    class clsPfCamera * m_pcBaseCamera; // offset 0x4, size 0x4
    class vector m_vecsCamCtrlStock; // offset 0x8, size 0xC
    class clsCamCtrl * m_pacCamCtrl[2]; // offset 0x14, size 0x8
    class clsPfCamera m_acCamera[2]; // offset 0x20, size 0xF5A0
    class clsCamIvBase * m_pcCamIv; // offset 0xF5C0, size 0x4
    unsigned char m_u8Mode; // offset 0xF5C4, size 0x1
    unsigned char m_u8IsLock; // offset 0xF5C5, size 0x1
    unsigned char m_u8HasNum; // offset 0xF5C6, size 0x1
    unsigned int m_u32Ratio; // offset 0xF5C8, size 0x4
    unsigned int m_u32Time; // offset 0xF5CC, size 0x4
};
// total size: 0x4
class stcPortalBelongType {
    // Members
public:
    unsigned char u8Next; // offset 0x0, size 0x1
    unsigned char u8Current; // offset 0x1, size 0x1
    unsigned char u8Back; // offset 0x2, size 0x1
    unsigned char u8Paddin; // offset 0x3, size 0x1
};
enum enmLanguage {
    LANGUAGE___JAPANESE = 0,
    LANGUAGE___ENGLISH = 1,
    LANGUAGE___GERMAN = 2,
    LANGUAGE___FRENCH = 3,
    LANGUAGE___SPANISH = 4,
    LANGUAGE___ITALIAN = 5,
    LANGUAGE___DUTCH = 6,
    LANGUAGE___PORTUGUESE = 7,
    LANGUAGE___SIMP_CHINESE = 8,
    LANGUAGE___TRAD_CHINESE = 9,
    LANGUAGE___KOREAN = 10,
    LANGUAGE___MAX = 11,
};
// total size: 0xB0
class clsPosturalCtrl {
    // Members
public:
    float m_sMtx[4][4]; // offset 0x0, size 0x40
    class NNS_VECTORFAST m_sDirVecFast; // offset 0x40, size 0x10
    class NNS_QUATERNION m_sQuat; // offset 0x50, size 0x10
    class clsSlerpQuat m_cSurface; // offset 0x60, size 0x3C
    class clsLerpParam m_cRotate; // offset 0x9C, size 0x10
};
// total size: 0x40
class hkProcessCollisionInput : public hkCollisionInput {
    // Members
public:
    class hkStepInfo m_stepInfo; // offset 0x20, size 0x10
    class hkPadSpu m_collisionQualityInfo; // offset 0x30, size 0x4
    void * m_dynamicsInfo; // offset 0x34, size 0x4
    unsigned char m_enableDeprecatedWelding; // offset 0x38, size 0x1
    class hkCollisionAgentConfig * m_config; // offset 0x3C, size 0x4
};
// total size: 0x8
class NNS_MATERIALPTR {
    // Members
public:
    unsigned int fType; // offset 0x0, size 0x4
    void * pMaterial; // offset 0x4, size 0x4
};
// total size: 0x8
class hkAgentEntry {
    // Members
public:
    unsigned char m_streamCommand; // offset 0x0, size 0x1
    unsigned char m_agentType; // offset 0x1, size 0x1
    unsigned char m_numContactPoints; // offset 0x2, size 0x1
    unsigned char m_size; // offset 0x3, size 0x1
    class UserData m_extraData; // offset 0x4, size 0x4
};
// total size: 0x8
class compressed_pair_imp {
    // Members
public:
    class value_compare first_; // offset 0x0, size 0x1
    class node * second_; // offset 0x4, size 0x4
};
// total size: 0x8
class hkContactPointMaterial {
    // Members
public:
    void * m_userData; // offset 0x0, size 0x4
    class hkUFloat8 m_friction; // offset 0x4, size 0x1
    unsigned char m_restitution; // offset 0x5, size 0x1
    class hkUFloat8 m_maxImpulse; // offset 0x6, size 0x1
    unsigned char m_flags; // offset 0x7, size 0x1
};
// total size: 0x38
class NNS_CAMERA_TARGET_UPVECTOR {
    // Members
public:
    unsigned int User; // offset 0x0, size 0x4
    signed int Fovy; // offset 0x4, size 0x4
    float Aspect; // offset 0x8, size 0x4
    float ZNear; // offset 0xC, size 0x4
    float ZFar; // offset 0x10, size 0x4
    class NNS_VECTOR Position; // offset 0x14, size 0xC
    class NNS_VECTOR Target; // offset 0x20, size 0xC
    class NNS_VECTOR UpVector; // offset 0x2C, size 0xC
};
// total size: 0x4
class hkRayShapeCollectionFilter {};
// total size: 0x58
class clsTemporary2D_Task : public clsTask {
    // Members
public:
    float m_f32Frame; // offset 0x54, size 0x4
};
// total size: 0x19C0
class clsWeather_Task : public clsTask {
    // Members
public:
    float m_sWindMtx[4][4]; // offset 0x60, size 0x40
    float m_sSpdMtx[4][4]; // offset 0xA0, size 0x40
    class stcStatus m_sStatus; // offset 0xE0, size 0x68
    class stcWaterDropStatus * m_opsWaterDrop; // offset 0x148, size 0x4
    unsigned char m_u8Weather; // offset 0x14C, size 0x1
    unsigned int m_u32View; // offset 0x150, size 0x4
    float m_f32WaterDropFrame; // offset 0x154, size 0x4
    float m_f32WaterDropPlayFrame; // offset 0x158, size 0x4
    signed int m_s32RotX; // offset 0x15C, size 0x4
    signed int m_s32RotY; // offset 0x160, size 0x4
    unsigned int m_u32Col; // offset 0x164, size 0x4
    float m_sDrawMtx[4][4]; // offset 0x170, size 0x40
    class stcSeed m_asSeed[128]; // offset 0x1B0, size 0x1800
    class clsPlaySe_2D * m_pcPlaySe2D; // offset 0x19B0, size 0x4
};
// total size: 0x8
class NVS_SVRHEADER {
    // Members
public:
    unsigned short type; // offset 0x0, size 0x2
    unsigned short miplevel; // offset 0x2, size 0x2
    unsigned short width; // offset 0x4, size 0x2
    unsigned short height; // offset 0x6, size 0x2
};
enum SimulationType {
    SIMULATION_TYPE_INVALID = 0,
    SIMULATION_TYPE_DISCRETE = 1,
    SIMULATION_TYPE_CONTINUOUS = 2,
    SIMULATION_TYPE_MULTITHREADED = 3,
};
// total size: 0x10
class hkInplaceArray : public hkArray {
    // Members
public:
    class hkEntity * m_storage[1]; // offset 0xC, size 0x4
};
// total size: 0x0
class hkWorldOperationQueue {};
// total size: 0x30
class hkRotation : public hkMatrix3 {};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkPhantomOverlapListener * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkWorldPostIntegrateListener * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x8
class ShapeInheritance {
    // Members
public:
    enum hkShapeType m_primaryType; // offset 0x0, size 0x4
    enum hkShapeType m_alternateType; // offset 0x4, size 0x4
};
// total size: 0x140
class clsTaskManager : public clsSingleton, public clsOOTaskManager {
    // Members
public:
    unsigned int m_u32CurViewNo; // offset 0x13C, size 0x4
};
enum enmCorrectMode {
    COM_CORRECT_MODE_HIGH_SPEED = 0,
    COM_CORRECT_MODE_LOW_SPEED = 1,
    COM_CORRECT_MODE_END = 2,
};
// total size: 0x8
class clsPlaySe_2D {
    // Members
public:
    signed int m_s32SeId; // offset 0x0, size 0x4
    unsigned char m_bIsPlayWait; // offset 0x4, size 0x1
    unsigned char m_u8PlayWaitTimeOut; // offset 0x5, size 0x1
};
// total size: 0x0
class hkWorldDeletionListener {};
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
// total size: 0x20
class PXS_TEXOBJ {
    // Members
public:
    class PXS_TEXREG texReg; // offset 0x0, size 0x20
};
// total size: 0x70
class clsGearPtnBoard : public clsGearBasePrototype {
    // Members
public:
    float m_f32UpMove; // offset 0x60, size 0x4
    float m_f32SideMov; // offset 0x64, size 0x4
};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkEntity * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x60
class clsGearSpGpInfinity : public clsGearPtnModelPart {};
// total size: 0x0
class node {};
enum enmDraw2DGearMode {
    GEAR_DRAW_2D_MODE_OPEN = 0,
    GEAR_DRAW_2D_MODE_CLOSE = 1,
    GEAR_DRAW_2D_MODE_LOCKED = 2,
};
// total size: 0x40
class clsReaction {
    // Members
public:
    class NNS_VECTORFAST m_sWallVecFast; // offset 0x0, size 0x10
    class clsPlayerTask * m_pcPlayer; // offset 0x10, size 0x4
    class clsPlaySe_2D * m_pcPlaySe2D; // offset 0x14, size 0x4
    float m_f32EffectFrame; // offset 0x18, size 0x4
    float m_f32EffectSubFrame; // offset 0x1C, size 0x4
    enum enmWallType m_eWallType; // offset 0x20, size 0x4
    enum enmGDiveType m_eGDiveType; // offset 0x24, size 0x4
    signed char m_s8WallHitCount; // offset 0x28, size 0x1
    class vector m_vecColInfo; // offset 0x2C, size 0xC
};
// total size: 0x10
class stcRateTime {
    // Members
public:
    signed int s32Sec; // offset 0x0, size 0x4
    signed int s32PassageSec; // offset 0x4, size 0x4
    float f32MSec; // offset 0x8, size 0x4
    float f32PassageMSec; // offset 0xC, size 0x4
};
// total size: 0x4
class hkPhantomOverlapListener {};
// total size: 0xEC
class clsGameMgr : public clsSingleton {
    // Members
public:
    class stcSendNextModeData m_sSendNextModeData; // offset 0x4, size 0x28
    class clsStoryMgr cStoryMgr; // offset 0x2C, size 0x14
    class clsWorldGpMgr cWorldGpMgr; // offset 0x40, size 0x28
    class clsTimeAtkMgr cTimeAtkMgr; // offset 0x68, size 0x14
    unsigned char * m_pu8MapBuffer; // offset 0x7C, size 0x4
    enum enmMode m_eMode; // offset 0x80, size 0x4
    unsigned int m_u32EtcUnlock; // offset 0x84, size 0x4
    unsigned char m_eResultSelect; // offset 0x88, size 0x1
    signed char m_s8TitleDemoNo; // offset 0x89, size 0x1
    signed char m_s8SecretTrickType; // offset 0x8A, size 0x1
    signed char m_s8SecretCommnadCount[2]; // offset 0x8B, size 0x2
    unsigned char m_bLogoSkip; // offset 0x8D, size 0x1
    unsigned char m_bStartLoad; // offset 0x8E, size 0x1
    unsigned char m_bStartTutorial; // offset 0x8F, size 0x1
    unsigned char m_abMissionUnLock[16][4]; // offset 0x90, size 0x40
    unsigned char m_abStageUnLock[16]; // offset 0xD0, size 0x10
    unsigned char m_abCharaUnLock[11]; // offset 0xE0, size 0xB
    unsigned char m_bEnableRenderNowLodingExpand; // offset 0xEB, size 0x1
};
// total size: 0x1
class value_compare : public binary_function {
    // Members
public:
    class less comp; // offset 0x0, size 0x1
};
// total size: 0x0
class hkWorldPostIntegrateListener {};
// total size: 0x14
class __list_deleter {
    // Members
public:
    class compressed_pair size_; // offset 0x0, size 0x8
    class compressed_pair end_; // offset 0x8, size 0xC
};
// total size: 0x40
class stcParam {
    // Members
public:
    signed char s8Interval; // offset 0x0, size 0x1
    unsigned char u8TexNo; // offset 0x1, size 0x1
    unsigned char u8StAlpha; // offset 0x2, size 0x1
    unsigned char u8EdAlpha; // offset 0x3, size 0x1
    signed short s16NodeNo; // offset 0x4, size 0x2
    signed short s16DataNum; // offset 0x6, size 0x2
    unsigned int u32Color; // offset 0x8, size 0x4
    float f32StTu; // offset 0xC, size 0x4
    float f32EdTu; // offset 0x10, size 0x4
    class NNS_VECTORFAST sSizeFast; // offset 0x20, size 0x10
    class NNS_VECTORFAST sOffsetFast; // offset 0x30, size 0x10
};
// total size: 0x1
class value_compare : public binary_function {
    // Members
public:
    class less comp; // offset 0x0, size 0x1
};
// total size: 0x14
class cdeque : private __cdeque_imp {};
// total size: 0x11C
class clsPlayerMotion : public clsMotion {
    // Members
public:
    class stcMotionTable * m_apsMotionTable[8]; // offset 0x5C, size 0x20
    class stcPlayData m_sPlayData[2]; // offset 0x7C, size 0x90
    signed char m_s8PlayDataNo; // offset 0x10C, size 0x1
    signed char m_s8BaseMotionType; // offset 0x10D, size 0x1
    signed char m_s8OldBaseMotionType; // offset 0x10E, size 0x1
    signed char m_s8MotionNo; // offset 0x10F, size 0x1
    signed char m_s8LinkMotionNo; // offset 0x110, size 0x1
    signed char m_s8BlendMotionNo; // offset 0x111, size 0x1
    signed char m_s8MotionType; // offset 0x112, size 0x1
    signed char m_s8LinkMotionType; // offset 0x113, size 0x1
    signed char m_s8BlendMotionType; // offset 0x114, size 0x1
    unsigned char m_bRoboFlag; // offset 0x115, size 0x1
    class clsPlayerTask * m_pcPlayer; // offset 0x118, size 0x4
};
// total size: 0x50
class clsGear {
    // Members
public:
    class clsGearCtrl * m_pcGearCtrl; // offset 0x4, size 0x4
    class stcGearData & m_rsGearData; // offset 0x8, size 0x4
    class stcAddPrfm & m_rsGearPrfm; // offset 0xC, size 0x4
    class clsModelType_OB_TX m_sModel; // offset 0x10, size 0x8
    class clsModelType_OB m_sShadowModel; // offset 0x18, size 0x4
    class NNS_VECTORFAST m_sActionTrans; // offset 0x20, size 0x10
    class NNS_ROTATE m_sActionRot; // offset 0x30, size 0xC
    class NNS_VECTOR m_sActionScale; // offset 0x3C, size 0xC
    float m_f32ActionAlpha; // offset 0x48, size 0x4
    unsigned int m_u32ActionCnt; // offset 0x4C, size 0x4
};
// total size: 0x10
class /* @class */ {
    // Members
public:
    union { // inferred
        signed char s8Data[16]; // offset 0x0, size 0x10
        class stcSpeedPath sSpeed; // offset 0x0, size 0x10
        class stcGravityPath sGravity; // offset 0x0, size 0x10
        class stcGDivePath sGDive; // offset 0x0, size 0x10
    };
};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkPhantomListener * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x4C0
class clsBackLineEffectTask : public clsTask {
    // Members
public:
    class stcStatus m_sStatus; // offset 0x60, size 0x20
    class stcGimickParam m_sGimickParam; // offset 0x80, size 0x14
    unsigned int m_u32LineColor; // offset 0x94, size 0x4
    float m_f32GctrlWaitFrame; // offset 0x98, size 0x4
    class NNS_VECTORFAST m_sNoMovePosFast; // offset 0xA0, size 0x10
    class NNS_VECTORFAST m_sLastBasePosFast; // offset 0xB0, size 0x10
    class NNS_VECTORFAST * m_opsNoMovePosFastAdr; // offset 0xC0, size 0x4
    class NNS_VECTORFAST * m_opsCompPosFastAdr; // offset 0xC4, size 0x4
    float (* m_opsNoMoveMtx)[4][4]; // offset 0xC8, size 0x4
    class stcParam * m_opsParam; // offset 0xCC, size 0x4
    class stcTrickSubParam * m_opsTrickSubParam; // offset 0xD0, size 0x4
    class stcGimickSubParam * m_opsGimickSubParam; // offset 0xD4, size 0x4
    class NNS_VECTOR m_asPoint[82]; // offset 0xD8, size 0x3D8
    class _NNS_TEXLIST * m_psTexList; // offset 0x4B0, size 0x4
};
enum enmDingMode {
    COM_DING_MODE_TIME_SET = 0,
    COM_DING_MODE_SPEED_UP = 1,
    COM_DING_MODE_SPEED_DOWN = 2,
    COM_DING_MODE_NON = 3,
};
// total size: 0x1
class binary_function {};
// total size: 0x8
class compressed_pair : private compressed_pair_imp {};
// total size: 0x0
class hkContactMgrFactory {};
// total size: 0x4
class hkPadSpu {
    // Members
public:
    float m_storage; // offset 0x0, size 0x4
};
// total size: 0x8
class stcGearData {
    // Members
public:
    unsigned int u32AttributeBits; // offset 0x0, size 0x4
    unsigned int u32AddAbility; // offset 0x4, size 0x4
};
// total size: 0x4
class UserData {
    // Members
public:
    union { // inferred
        class GskFlags m_gskFlags; // offset 0x0, size 0x4
        class hkCollisionAgent * m_bridgeChildAgent; // offset 0x0, size 0x4
    };
};
// total size: 0x704
class clsResidenceEffect {
    // Members
public:
    class _NNS_TEXLIST * m_psResidence_TexList; // offset 0x0, size 0x4
    class clsModelType_OB_TX_MO_MA m_cGravity_Model; // offset 0x4, size 0x20
    class clsModelType_OB_TX_MO_MA m_cGravityEmpty_Model; // offset 0x24, size 0x20
    class clsModelType_OB_TX_MO_MA m_cGravityLocal_Model; // offset 0x44, size 0x20
    class clsModelType_OB_TX_MO_MA_MF m_acGravity_Model2[4]; // offset 0x64, size 0xD0
    class clsModelType_OB_TX_MO_MA_MF m_acGravity_Model3[4]; // offset 0x134, size 0xD0
    class clsModelType_OB_TX_MO_MA m_cLandig_Model; // offset 0x204, size 0x20
    class clsModelType_OB_TX_MO_MA m_cCurve_Model; // offset 0x224, size 0x20
    class clsModelType_OB_TX_MO_MA m_cCrash_Model; // offset 0x244, size 0x20
    class clsModelType_OB_TX_MO_MA m_cDash_Model; // offset 0x264, size 0x20
    class clsModelType_OB_TX_MO_MA m_cGetAGP_Model; // offset 0x284, size 0x20
    class clsModelType_OB_TX_MO_MA m_cCrashCrara_Model; // offset 0x2A4, size 0x20
    class clsModelType_OB_TX_MO_MA m_cBadTrack_Model; // offset 0x2C4, size 0x20
    class clsModelType_OB_TX_MO_MA m_cGearChenge01_Model; // offset 0x2E4, size 0x20
    class clsModelType_OB_TX_MO_MA m_cGearChenge02_Model; // offset 0x304, size 0x20
    class clsModelType_OB_TX_MO_MA m_cGearChenge03_Model; // offset 0x324, size 0x20
    class clsModelType_OB_TX_MO_MA m_cGearChengeRt_Model; // offset 0x344, size 0x20
    class clsModelType_OB_TX_MO_MA m_cFalseStart00_Model; // offset 0x364, size 0x20
    class clsModelType_OB_TX_MO_MA m_cFalseStart01_Model; // offset 0x384, size 0x20
    class clsModelType_OB_TX_MO_MA m_cGravityCtrl00_Model; // offset 0x3A4, size 0x20
    class clsModelType_OB_TX_MO_MA m_cGravityCtrl01_Model; // offset 0x3C4, size 0x20
    class clsModelType_OB_TX_MO_MA m_cGravityCtrl02_Model; // offset 0x3E4, size 0x20
    class clsModelType_OB_TX_MO_MA m_cPowerHit_Model; // offset 0x404, size 0x20
    class clsModelType_OB_TX_MO_MA m_cTrickXFlashLine_Model; // offset 0x424, size 0x20
    class clsModelType_OB_TX_MO_MA m_cTrickXRing_Model; // offset 0x444, size 0x20
    class clsModelType_OB_TX_MO_MA m_cGearTypeChange_Model; // offset 0x464, size 0x20
    class clsModelType_OB_TX_MO_MA m_cRoboCurv_Model; // offset 0x484, size 0x20
    class clsModelType_OB_TX_MO_MA m_cSidaRide_Model; // offset 0x4A4, size 0x20
    class clsModelType_OB_TX_MO_MA m_cLandingWaterTrick_Model; // offset 0x4C4, size 0x20
    class clsModelType_OB_TX_MO_MA m_cLandingWaterJump_Model; // offset 0x4E4, size 0x20
    class clsModelType_OB_TX_MO_MA m_cMeteoriteFall_Model; // offset 0x504, size 0x20
    class clsModelType_OB_TX_MO_MA m_cDiveEffect_Model; // offset 0x524, size 0x20
    class clsModelType_OB_TX_MO_MA m_cMeteoExplode_Model; // offset 0x544, size 0x20
    class clsModelType_OB_TX_MO_MA m_cBossCrush_Model; // offset 0x564, size 0x20
    class clsModelType_OB_TX_MO_MA m_cBossCrush2_Model; // offset 0x584, size 0x20
    class clsModelType_OB_TX_MO_MA m_cBossAppear_Model; // offset 0x5A4, size 0x20
    class clsModelType_OB_TX_MO_MA m_cBornRing_Model; // offset 0x5C4, size 0x20
    class clsModelType_OB_TX_MO_MA m_cSt07PTObj_Model; // offset 0x5E4, size 0x20
    class clsModelType_OB_TX_MO_MA m_cSt07Floor_Model; // offset 0x604, size 0x20
    class clsModelType_OB_TX_MO_MA m_cSt07FloorG_Model; // offset 0x624, size 0x20
    class clsModelType_OB_TX_MO_MA m_cBornSpring_Model; // offset 0x644, size 0x20
    class clsModelType_OB_TX_MO_MA m_cBornItemBox_Model; // offset 0x664, size 0x20
    class clsModelType_OB_TX_MO_MA m_cBornDPanel_Model; // offset 0x684, size 0x20
    class clsModelType_OB_TX_MO_MA m_cSt14FanL_Model; // offset 0x6A4, size 0x20
    class clsModelType_OB_TX_MO_MA m_cSt14FanS_Model; // offset 0x6C4, size 0x20
    class clsModelType_OB_TX_MO_MA m_cSt07FloorHole_Model; // offset 0x6E4, size 0x20
};
// total size: 0x1
class less : public binary_function {};
// total size: 0x28
class stcSendNextModeData {
    // Members
public:
    class stcSendAdv sSendAdv[8]; // offset 0x0, size 0x20
    enum enmMode eNextMode; // offset 0x20, size 0x4
    signed char s8StageNo; // offset 0x24, size 0x1
    signed char s8PlayerNum; // offset 0x25, size 0x1
    signed char s8UserNum; // offset 0x26, size 0x1
    signed char s8UniqueData; // offset 0x27, size 0x1
};
// total size: 0x4
class compressed_pair_imp : private allocator {
    // Members
public:
    unsigned int second_; // offset 0x0, size 0x4
};
// total size: 0x4C
struct /* @anon8 */ {};
enum enmKicker {
    KICKER_FF = 0,
    KICKER_BF = 1,
    KICKER_SPIN = 2,
    KICKER_PIPE = 3,
    KICKER_FREE = 4,
    KICKER_WALL = 5,
    KICKER_TURB = 6,
    KICKER_VERTICAL = 7,
    KICKER_PARTS = 8,
    KICKER_TYPE_MAX = 9,
};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkWorldPostSimulationListener * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x0
class hkMultithreadedSimulationJobData {};
enum enmStatus {
    STATUS__NONE = 0,
    STATUS__RANGE_IN = 1,
    STATUS__RANGE_ALWAYS = 2,
    STATUS__RANGE_OUT = 3,
};
// total size: 0x0
class hkWorldPostSimulationListener {};
// total size: 0x18
class hkAction : public hkReferencedObject {
    // Members
public:
    class hkWorld * m_world; // offset 0x8, size 0x4
    class hkSimulationIsland * m_island; // offset 0xC, size 0x4
    unsigned int m_userData; // offset 0x10, size 0x4
    char * m_name; // offset 0x14, size 0x4
};
// total size: 0x4
class clsWallTrickAction : public clsBaseTrickAction {};
// total size: 0x44
struct /* @anon9 */ {};
// total size: 0x20
class DeactivationInfo {
    // Members
public:
    float m_linearVelocityThresholdInv; // offset 0x0, size 0x4
    float m_angularVelocityThresholdInv; // offset 0x4, size 0x4
    float m_slowObjectVelocityMultiplier; // offset 0x8, size 0x4
    float m_relativeSleepVelocityThreshold; // offset 0xC, size 0x4
    unsigned short m_stepsToDeactivate; // offset 0x10, size 0x2
    float m_maxDistSqrd[2]; // offset 0x14, size 0x8
    class hkHalf m_maxRotSqrd[2]; // offset 0x1C, size 0x4
};
// total size: 0x4
class hkCollisionDetail {
    // Members
public:
    class hkCollidable * m_collidable; // offset 0x0, size 0x4
};
// total size: 0x8
class compressed_pair_imp {
    // Members
public:
    class clsOOStlAllocator first_; // offset 0x0, size 0x4
    unsigned int second_; // offset 0x4, size 0x4
};
// total size: 0x30
class stcInitData {
    // Members
public:
    class NNS_VECTORFAST sPosVecFast; // offset 0x0, size 0x10
    class NNS_VECTORFAST sUpVecFast; // offset 0x10, size 0x10
    float f32LocalAngleRad; // offset 0x20, size 0x4
    unsigned int u32Padding; // offset 0x24, size 0x4
};
// total size: 0x50
class hkAgent3Input {
    // Members
public:
    class hkPadSpu m_bodyA; // offset 0x0, size 0x4
    class hkPadSpu m_bodyB; // offset 0x4, size 0x4
    class hkPadSpu m_input; // offset 0x8, size 0x4
    class hkPadSpu m_contactMgr; // offset 0xC, size 0x4
    class hkTransform m_aTb; // offset 0x10, size 0x40
};
// total size: 0x20
class PXS_TEXREG {
    // Members
public:
    class sceGsTex1 tex1; // offset 0x0, size 0x8
    class sceGsTex0 tex0; // offset 0x8, size 0x8
    class sceGsMiptbp1 miptbp1; // offset 0x10, size 0x8
    class sceGsMiptbp2 miptbp2; // offset 0x18, size 0x8
};
// total size: 0x8
class _KeyBuf {
    // Members
public:
    unsigned int u32KeyState; // offset 0x0, size 0x4
    signed char s8LeverX; // offset 0x4, size 0x1
    signed char s8LeverY; // offset 0x5, size 0x1
    unsigned char u8ExtType; // offset 0x6, size 0x1
    unsigned char u8Padding; // offset 0x7, size 0x1
};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkPhantom * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x4
class stcRecord {
    // Members
public:
    unsigned char u8Minite; // offset 0x0, size 0x1
    unsigned char u8Second; // offset 0x1, size 0x1
    unsigned short u16MiliSecond; // offset 0x2, size 0x2
};
// total size: 0x8
class stcPortalBin {
    // Members
public:
    unsigned short u16Num; // offset 0x0, size 0x2
    unsigned char u8BeginType; // offset 0x2, size 0x1
    unsigned char u8EndType; // offset 0x3, size 0x1
    class stcPortalMtx * psMtxHeap; // offset 0x4, size 0x4
    class stcPortalDetail asDetail[]; // offset 0x8, size 0x0
};
// total size: 0x4
class NNS_NODEEXPTR {
    // Members
public:
    class _NNS_NODEEX * pNodeEx; // offset 0x0, size 0x4
};
// total size: 0x10
class clsCharaVoice {
    // Members
public:
    class clsPlayerTask * m_pcPlayer; // offset 0x4, size 0x4
    float m_f32VoiceDelayFrameRunPast; // offset 0x8, size 0x4
    float m_f32VoiceDelayFrameAttack; // offset 0xC, size 0x4
};
// total size: 0x14
class stcGimickParam {
    // Members
public:
    class NNS_OBJECT * opsObject; // offset 0x0, size 0x4
    class NNS_MOTION * opsMotion; // offset 0x4, size 0x4
    float (* opsMatrix)[4][4]; // offset 0x8, size 0x4
    float * opf32Frame; // offset 0xC, size 0x4
    float f32Scale; // offset 0x10, size 0x4
};
enum enmGDiveType {
    GDIVE_TYPE__NORMAL = 0,
    GDIVE_TYPE__CANCEL = 1,
    GDIVE_TYPE__REFLECTION = 2,
};
// total size: 0x18
class multimap {
    // Members
public:
    class __tree tree_; // offset 0x0, size 0x18
};
enum enmRunDelay {
    COM_RUN_STORY_NORMAL = 0,
    COM_RUN_STORY_LEADER = 1,
    COM_RUN_STORY_PLAYER = 2,
};
// total size: 0x4
class hkShapeCollectionFilter {};
// total size: 0x4
class hkPadSpu {
    // Members
public:
    class hkShapeCollectionFilter * m_storage; // offset 0x0, size 0x4
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
// total size: 0x8
class SpuCollisionCallback {
    // Members
public:
    class hkSpuCollisionCallbackUtil * m_util; // offset 0x0, size 0x4
    unsigned short m_capacity; // offset 0x4, size 0x2
    unsigned char m_eventFilter; // offset 0x6, size 0x1
    unsigned char m_userFilter; // offset 0x7, size 0x1
};
// total size: 0x4C
struct /* @anon10 */ {};
// total size: 0x8
class clsFrameControl {
    // Members
public:
    float m_f32Frame; // offset 0x0, size 0x4
    float m_f32CountFrame; // offset 0x4, size 0x4
};
// total size: 0x8
class NVS_GBIXHEADER {
    // Members
public:
    unsigned int globalIndex; // offset 0x0, size 0x4
    unsigned int bank; // offset 0x4, size 0x4
};
// total size: 0x0
class hkBroadPhaseBorderListener {};
// total size: 0x4
class hkBaseObject {};
// total size: 0xC
class hkArray {
    // Members
public:
    unsigned char * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x110
class clsComAI {
    // Members
public:
    class clsPlayerTask * m_pcPlayer; // offset 0x4, size 0x4
    class NNS_VECTORFAST m_sNextDestination; // offset 0x10, size 0x10
    class clsRetPath m_cRetComPath; // offset 0x20, size 0x20
    enum enmActionType m_eOldActionType; // offset 0x40, size 0x4
    enum enmKickerRankZone m_eNextTrickZone; // offset 0x44, size 0x4
    enum enmRunMode m_eRunMode; // offset 0x48, size 0x4
    unsigned int m_u32AdjustStates; // offset 0x4C, size 0x4
    float m_f32CourseAngle; // offset 0x50, size 0x4
    unsigned short m_u16OldLineNo; // offset 0x54, size 0x2
    unsigned short m_u16ComExecMode; // offset 0x56, size 0x2
    unsigned short m_u16NextLine; // offset 0x58, size 0x2
    unsigned char m_u8PlannedRank; // offset 0x5A, size 0x1
    unsigned char m_bWallJumpFlag; // offset 0x5B, size 0x1
    signed int m_s32GameMode; // offset 0x5C, size 0x4
    enum enmComType m_eComTypeAI; // offset 0x60, size 0x4
    enum enmComMode m_eComModeAI; // offset 0x64, size 0x4
    enum enmComDis m_eComDisAI; // offset 0x68, size 0x4
    unsigned int m_u32NowTime; // offset 0x6C, size 0x4
    unsigned int m_u32OldTime; // offset 0x70, size 0x4
    unsigned int m_u32RandAI; // offset 0x74, size 0x4
    signed int m_s32AddSub; // offset 0x78, size 0x4
    signed int m_s32RaceAddSub; // offset 0x7C, size 0x4
    enum enmRunDelay m_eDelayMode; // offset 0x80, size 0x4
    enum enmDingMode m_eDingMode; // offset 0x84, size 0x4
    enum enmDingMode m_eOldDingMode; // offset 0x88, size 0x4
    enum enmCorrectMode m_eCorrectMode; // offset 0x8C, size 0x4
    unsigned int m_u32ShortTime; // offset 0x90, size 0x4
    unsigned int m_u32LapTimeFreeCnt; // offset 0x94, size 0x4
    unsigned int m_u32LapTimeFreeFrm; // offset 0x98, size 0x4
    signed int m_s32AddSubFree; // offset 0x9C, size 0x4
    signed int m_s32FreeLapFlag; // offset 0xA0, size 0x4
    float m_f32OldRankDepth; // offset 0xA4, size 0x4
    signed int m_s32SelectAi; // offset 0xA8, size 0x4
    float m_f32MaxSpeed; // offset 0xAC, size 0x4
    float m_f32MinSpeed; // offset 0xB0, size 0x4
    float m_f32CollisionCheckFrame; // offset 0xB4, size 0x4
    class NNS_VECTORFAST m_sOldPosVec; // offset 0xC0, size 0x10
    unsigned char m_u8OldPlannedRank; // offset 0xD0, size 0x1
    unsigned int m_u32StoryBestLap; // offset 0xD4, size 0x4
    unsigned int m_u32FreeBestLap; // offset 0xD8, size 0x4
    class NNS_VECTORFAST * m_psTrickGCtrlConnectPos; // offset 0xDC, size 0x4
    signed int m_s32TrickGCtrlTrickFrame; // offset 0xE0, size 0x4
    unsigned char m_bIsTrickGCtrlTry; // offset 0xE4, size 0x1
    signed char m_s8BunkiFlag; // offset 0xE5, size 0x1
    signed int m_s32HitCount; // offset 0xE8, size 0x4
    float m_f32BunkiFrame; // offset 0xEC, size 0x4
    float m_f32BunkiLimitFrame; // offset 0xF0, size 0x4
    signed int m_s32WallShortCutFlag; // offset 0xF4, size 0x4
    float m_f32WallShortCutTime; // offset 0xF8, size 0x4
    class stcTimePack m_sRoundTime; // offset 0xFC, size 0x4
    class stcTimePack m_sRoundOldTime; // offset 0x100, size 0x4
    class stcTimePack m_sDebugCheckTime; // offset 0x104, size 0x4
    class stcTimePack m_sDebugRoundTime; // offset 0x108, size 0x4
    class stcTimePack m_sDebugDelayTime; // offset 0x10C, size 0x4
};
// total size: 0x40
class clsUserKey : public clsPlayerKey {
    // Members
public:
    unsigned int m_u32PadNo; // offset 0x34, size 0x4
    class clsReplayKey * m_pcReplayKey; // offset 0x38, size 0x4
    class clsPlayerTask * m_pcPlayer; // offset 0x3C, size 0x4
};
// total size: 0x24
class clsOOClock {
    // Members
public:
    signed int m_s32Minute; // offset 0x4, size 0x4
    signed int m_s32Sec; // offset 0x8, size 0x4
    float m_f32MSec; // offset 0xC, size 0x4
    signed int m_s32MinuteUpLimit; // offset 0x10, size 0x4
    signed int m_s32SecUpLimit; // offset 0x14, size 0x4
    signed int m_s32MSecUpLimit; // offset 0x18, size 0x4
    unsigned int m_eCountType; // offset 0x1C, size 0x4
    unsigned char m_bOverFlow; // offset 0x20, size 0x1
    unsigned char m_bCountStop; // offset 0x21, size 0x1
};
// total size: 0x18
class __tree : private __red_black_tree {
    // Members
public:
    class compressed_pair alloc_; // offset 0x0, size 0x8
    class compressed_pair node_alloc_; // offset 0x8, size 0x8
    class compressed_pair comp_; // offset 0x10, size 0x8
};
// total size: 0x4
class clsOOStlAllocator {
    // Members
public:
    class clsOOHeapFragment * m_pcHeap; // offset 0x0, size 0x4
};
// total size: 0x7C
struct /* @anon11 */ {};
// total size: 0x8
class NNS_CAMERAPTR {
    // Members
public:
    unsigned int fType; // offset 0x0, size 0x4
    void * pCamera; // offset 0x4, size 0x4
};
// total size: 0x14
class _DebugDrawSphere {
    // Members
public:
    class NNS_VECTOR sPos; // offset 0x0, size 0xC
    unsigned int u32Color; // offset 0xC, size 0x4
    float f32Size; // offset 0x10, size 0x4
};
// total size: 0xC
class hkCollisionAgent : public hkReferencedObject {
    // Members
public:
    class hkContactMgr * m_contactMgr; // offset 0x8, size 0x4
};
// total size: 0x8
class clsOOCamera {
    // Members
public:
    unsigned int m_u32CamNo; // offset 0x4, size 0x4
};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkEntityListener * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x130
class clsGravity {
    // Members
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
    enum enmFlag m_eFlag; // offset 0x118, size 0x4
    enum enmType m_eType; // offset 0x11C, size 0x4
    float m_f32ChangeFrame; // offset 0x120, size 0x4
};
// total size: 0x190
class clsComKey : public clsPlayerKey, public clsComAI {
    // Members
public:
    unsigned short m_u16GrindJumpLineNo; // offset 0x150, size 0x2
    signed short m_s16GrindAccessWaitCnt; // offset 0x152, size 0x2
    unsigned char m_bIsGrindFirstJump; // offset 0x154, size 0x1
    unsigned char m_bIsGDiveTry; // offset 0x155, size 0x1
    unsigned char m_bIsTrickRailLinkTry; // offset 0x156, size 0x1
    unsigned char m_bIsStartReverOn; // offset 0x157, size 0x1
    unsigned char m_u8OldTrickKey; // offset 0x158, size 0x1
    signed char m_s8OldCurveLever; // offset 0x159, size 0x1
    class NNS_VECTORFAST m_sOffsetEndPoint; // offset 0x160, size 0x10
    signed int m_s32OffsetSign; // offset 0x170, size 0x4
    float m_f32OffsetPointPos; // offset 0x174, size 0x4
    unsigned char m_bIsGCtrlTry; // offset 0x178, size 0x1
    class NNS_VECTORFAST * m_psGCtrlEndPos; // offset 0x17C, size 0x4
    signed int m_s32GCtrlRestFrame; // offset 0x180, size 0x4
};
// total size: 0x8
class compressed_pair : private compressed_pair_imp {};
// total size: 0xC
class NNS_ROTATE {
    // Members
public:
    float x; // offset 0x0, size 0x4
    float y; // offset 0x4, size 0x4
    float z; // offset 0x8, size 0x4
};
// total size: 0x0
class hkEntityEntityBroadPhaseListener {};
// total size: 0x0
class hkWorldPostCollideListener {};
// total size: 0x4C
struct /* @anon12 */ {};
// total size: 0x4
class hkPadSpu {
    // Members
public:
    unsigned int m_storage; // offset 0x0, size 0x4
};
enum enmActionMode {
    ACTION_MODE_NON = 0,
    ACTION_MODE_GETTING_ON = 1,
    ACTION_MODE_GETTING_OFF = 2,
};
// total size: 0x0
class node {};
// total size: 0x110
class clsControlMatrix {
    // Members
public:
    float m_sMtx[4][4]; // offset 0x0, size 0x40
    class NNS_ROTATE_A32 m_sAutoRotA32; // offset 0x40, size 0xC
    class NNS_ROTATE_A32 m_sAutoRotRetAddA32; // offset 0x4C, size 0xC
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
    enum enmFlag m_eFlag; // offset 0x100, size 0x4
};
// total size: 0x10
class stcScissorRect {
    // Members
public:
    unsigned int u32OffsetX; // offset 0x0, size 0x4
    unsigned int u32OffsetY; // offset 0x4, size 0x4
    unsigned int u32Right; // offset 0x8, size 0x4
    unsigned int u32Bottom; // offset 0xC, size 0x4
};
enum enmAttackLR {
    TARGET_LEFT = 0,
    TARGET_RIGHT = 1,
};
// total size: 0x54
class clsTask : public clsOOTask {};
// total size: 0x8
class sceGsMiptbp2 {
    // Members
public:
    unsigned long TBP4 : 14; // offset 0x0, size 0x4
    unsigned long TBW4 : 6; // offset 0x0, size 0x4
    unsigned long TBP5 : 14; // offset 0x0, size 0x4
    unsigned long TBW5 : 6; // offset 0x0, size 0x4
    unsigned long TBP6 : 14; // offset 0x0, size 0x4
    unsigned long TBW6 : 6; // offset 0x0, size 0x4
    unsigned long pad60 : 4; // offset 0x0, size 0x4
};
// total size: 0x4
class hkCollidableCollidableFilter {};
enum enmStiffType {
    STIFF_TYPE__ALL = 0,
    STIFF_TYPE__LEVER = 1,
};
// total size: 0x330
class hkWorld : public hkReferencedObject {
    // Members
public:
    class hkSimulation * m_simulation; // offset 0x8, size 0x4
    class hkVector4 m_gravity; // offset 0x10, size 0x10
    class hkSimulationIsland * m_fixedIsland; // offset 0x20, size 0x4
    class hkRigidBody * m_fixedRigidBody; // offset 0x24, size 0x4
    class hkArray m_activeSimulationIslands; // offset 0x28, size 0xC
    class hkArray m_inactiveSimulationIslands; // offset 0x34, size 0xC
    class hkArray m_dirtySimulationIslands; // offset 0x40, size 0xC
    class hkWorldMaintenanceMgr * m_maintenanceMgr; // offset 0x4C, size 0x4
    class hkWorldMemoryWatchDog * m_memoryWatchDog; // offset 0x50, size 0x4
    class hkBroadPhase * m_broadPhase; // offset 0x54, size 0x4
    class hkTypedBroadPhaseDispatcher * m_broadPhaseDispatcher; // offset 0x58, size 0x4
    class hkPhantomBroadPhaseListener * m_phantomBroadPhaseListener; // offset 0x5C, size 0x4
    class hkEntityEntityBroadPhaseListener * m_entityEntityBroadPhaseListener; // offset 0x60, size 0x4
    class hkBroadPhaseBorderListener * m_broadPhaseBorderListener; // offset 0x64, size 0x4
    class hkMultithreadedSimulationJobData * m_multithreadedSimulationJobData; // offset 0x68, size 0x4
    class hkProcessCollisionInput * m_collisionInput; // offset 0x6C, size 0x4
    class hkCollisionFilter * m_collisionFilter; // offset 0x70, size 0x4
    class hkCollisionDispatcher * m_collisionDispatcher; // offset 0x74, size 0x4
    class hkConvexListFilter * m_convexListFilter; // offset 0x78, size 0x4
    class hkWorldOperationQueue * m_pendingOperations; // offset 0x7C, size 0x4
    signed int m_pendingOperationsCount; // offset 0x80, size 0x4
    signed int m_criticalOperationsLockCount; // offset 0x84, size 0x4
    signed int m_criticalOperationsLockCountForPhantoms; // offset 0x88, size 0x4
    class hkBool m_blockExecutingPendingOperations; // offset 0x8C, size 0x1
    class hkBool m_criticalOperationsAllowed; // offset 0x8D, size 0x1
    class hkDebugInfoOnPendingOperationQueues * m_pendingOperationQueues; // offset 0x90, size 0x4
    signed int m_pendingOperationQueueCount; // offset 0x94, size 0x4
    class hkMultiThreadCheck m_multiThreadCheck; // offset 0x98, size 0x8
    class hkBool m_processActionsInSingleThread; // offset 0xA0, size 0x1
    unsigned int m_minDesiredIslandSize; // offset 0xA4, size 0x4
    class hkCriticalSection * m_modifyConstraintCriticalSection; // offset 0xA8, size 0x4
    class hkCriticalSection * m_worldLock; // offset 0xAC, size 0x4
    class hkCriticalSection * m_islandDirtyListCriticalSection; // offset 0xB0, size 0x4
    class hkCriticalSection * m_propertyMasterLock; // offset 0xB4, size 0x4
    class hkArray m_propertyLocks; // offset 0xB8, size 0xC
    class hkBool m_wantSimulationIslands; // offset 0xC4, size 0x1
    float m_snapCollisionToConvexEdgeThreshold; // offset 0xC8, size 0x4
    float m_snapCollisionToConcaveEdgeThreshold; // offset 0xCC, size 0x4
    class hkBool m_enableToiWeldRejection; // offset 0xD0, size 0x1
    class hkBool m_wantDeactivation; // offset 0xD1, size 0x1
    class hkBool m_wantOldStyleDeactivation; // offset 0xD2, size 0x1
    class hkBool m_shouldActivateOnRigidBodyTransformChange; // offset 0xD3, size 0x1
    float m_highFrequencyDeactivationPeriod; // offset 0xD4, size 0x4
    float m_lowFrequencyDeactivationPeriod; // offset 0xD8, size 0x4
    float m_deactivationReferenceDistance; // offset 0xDC, size 0x4
    float m_toiCollisionResponseRotateNormal; // offset 0xE0, size 0x4
    enum SimulationType m_simulationType; // offset 0xE4, size 0x4
    unsigned int m_lastEntityUid; // offset 0xE8, size 0x4
    class hkArray m_phantoms; // offset 0xEC, size 0xC
    class hkArray m_actionListeners; // offset 0xF8, size 0xC
    class hkArray m_entityListeners; // offset 0x104, size 0xC
    class hkArray m_phantomListeners; // offset 0x110, size 0xC
    class hkArray m_constraintListeners; // offset 0x11C, size 0xC
    class hkArray m_worldDeletionListeners; // offset 0x128, size 0xC
    class hkArray m_islandActivationListeners; // offset 0x134, size 0xC
    class hkArray m_worldPostSimulationListeners; // offset 0x140, size 0xC
    class hkArray m_worldPostIntegrateListeners; // offset 0x14C, size 0xC
    class hkArray m_worldPostCollideListeners; // offset 0x158, size 0xC
    class hkArray m_islandPostIntegrateListeners; // offset 0x164, size 0xC
    class hkArray m_islandPostCollideListeners; // offset 0x170, size 0xC
    class hkArray m_collisionListeners; // offset 0x17C, size 0xC
    class hkArray m_contactImpulseLimitBreachedListeners; // offset 0x188, size 0xC
    class hkBroadPhaseBorder * m_broadPhaseBorder; // offset 0x194, size 0x4
    class hkWorldDynamicsStepInfo m_dynamicsStepInfo; // offset 0x1A0, size 0x150
    class hkVector4 m_broadPhaseExtents[2]; // offset 0x2F0, size 0x20
    signed int m_broadPhaseNumMarkers; // offset 0x310, size 0x4
    signed int m_sizeOfToiEventQueue; // offset 0x314, size 0x4
    signed int m_broadPhaseQuerySize; // offset 0x318, size 0x4
    signed int m_broadPhaseUpdateSize; // offset 0x31C, size 0x4
    class hkEnum m_contactPointGeneration; // offset 0x320, size 0x1
};
// total size: 0x140
class clsBaseStage_Task : public clsTask {
    // Members
public:
    class clsModelType_OB_TX_MO_MA m_cModel; // offset 0x54, size 0x20
    class clsPortal m_cObjPortal_Camera; // offset 0x74, size 0x50
    class clsPortal m_cObjPortal_Player; // offset 0xC4, size 0x50
    class clsPathCourse * m_pcCoursePath; // offset 0x114, size 0x4
    class clsPathCom m_cComPath; // offset 0x118, size 0x14
    class stcBinDataDetail * m_opsBinDataDetail_Fog; // offset 0x12C, size 0x4
    class clsRainDrops_Task * m_pcRainDrops_Task; // offset 0x130, size 0x4
    class clsColorDrops_Task * m_pcColorDrops_Task; // offset 0x134, size 0x4
    unsigned char m_abShimmer[4]; // offset 0x138, size 0x4
    class stcEtcBinaryStageData * m_opsEtcBinaryStageData; // offset 0x13C, size 0x4
};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkIslandActivationListener * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkContactPoint * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x7E4
class clsColorDrops_Task : public clsRainDrops_Task {
    // Members
public:
    class stcDetail m_sDetail[64]; // offset 0x2E4, size 0x500
};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkActionListener * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x90
class _NNS_NODEEX {
    // Members
public:
    unsigned int fNodeExType; // offset 0x0, size 0x4
    unsigned int fNodeType; // offset 0x4, size 0x4
    signed short iMatrix; // offset 0x8, size 0x2
    signed short iNode; // offset 0xA, size 0x2
    class _NNS_NODEEX * pParent; // offset 0xC, size 0x4
    class _NNS_NODEEX * pChild; // offset 0x10, size 0x4
    class _NNS_NODEEX * pSibling; // offset 0x14, size 0x4
    class NNS_VECTOR Translation; // offset 0x18, size 0xC
    class NNS_ROTATE_A32 Rotation; // offset 0x24, size 0xC
    class NNS_VECTOR Scaling; // offset 0x30, size 0xC
    unsigned int User; // offset 0x3C, size 0x4
    float InvInitMtx[4][4]; // offset 0x40, size 0x40
    unsigned int reserved; // offset 0x80, size 0x4
};
// total size: 0x8
class compressed_pair_imp {
    // Members
public:
    class clsOOStlAllocator first_; // offset 0x0, size 0x4
    class anchor second_; // offset 0x4, size 0x4
};
// total size: 0x40
class hkLinearCastCollisionInput : public hkCollisionInput {
    // Members
public:
    class hkVector4 m_path; // offset 0x20, size 0x10
    float m_maxExtraPenetration; // offset 0x30, size 0x4
    float m_cachedPathLength; // offset 0x34, size 0x4
    class hkCollisionAgentConfig * m_config; // offset 0x38, size 0x4
};
// total size: 0x10
class NNS_SPHERE {
    // Members
public:
    class NNS_VECTOR c; // offset 0x0, size 0xC
    float r; // offset 0xC, size 0x4
};
// total size: 0x1C
class stcPortalDetail {
    // Members
public:
    signed short s16Sx; // offset 0x0, size 0x2
    signed short s16Sy; // offset 0x2, size 0x2
    signed short s16Sz; // offset 0x4, size 0x2
    signed short s16Ex; // offset 0x6, size 0x2
    signed short s16Ey; // offset 0x8, size 0x2
    signed short s16Ez; // offset 0xA, size 0x2
    unsigned char u8Type; // offset 0xC, size 0x1
    signed char s8MtxNo; // offset 0xD, size 0x1
    unsigned char u8Paddin[2]; // offset 0xE, size 0x2
    signed int a32RotX; // offset 0x10, size 0x4
    signed int a32RotY; // offset 0x14, size 0x4
    signed int a32RotZ; // offset 0x18, size 0x4
};
// total size: 0x18
class clsBaseGravityAction {
    // Members
public:
    class clsGravityActionManager * m_pcManager; // offset 0x0, size 0x4
    float m_f32Range; // offset 0x4, size 0x4
    float m_f32UsedRate; // offset 0x8, size 0x4
    float m_f32DefaultRange; // offset 0xC, size 0x4
    float m_f32DefaultUsedRate; // offset 0x10, size 0x4
};
// total size: 0x0
class hkPhantomBroadPhaseListener {};
// total size: 0x7C
struct /* @anon13 */ {};
// total size: 0xC

// total size: 0x1
class allocator {};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkAction * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x0
class hkIslandActivationListener {};
// total size: 0x54
class clsOOTask {
    // Members
public:
    unsigned int m_u32ExecFlags; // offset 0x4, size 0x4
    unsigned int m_u32EnablePauseFlags; // offset 0x8, size 0x4
    unsigned int m_u32Priority; // offset 0xC, size 0x4
    unsigned char m_u8Mode; // offset 0x10, size 0x1
    unsigned int m_u32TaskDepth; // offset 0x14, size 0x4
    class clsOOTask * m_pcParentTask; // offset 0x18, size 0x4
    class clsOOList m_lstChildTask; // offset 0x1C, size 0x14
    unsigned char m_bIsDead; // offset 0x30, size 0x1
    class generic_iterator m_itParentList; // offset 0x34, size 0x4
    class generic_iterator m_itMgrList; // offset 0x38, size 0x4
    class clsOOMap m_mapMgrExecListIt; // offset 0x3C, size 0x18
};
enum enmStatus {
    STATUS_CLEAR = 0,
    STATUS_GROUND = 1,
    STATUS_WALL = 2,
    STATUS_LANDING = 4,
    STATUS_START = 8,
    STATUS_GOAL = 16,
    STATUS_ON_WATER = 32,
    STATUS_WEATHER = 64,
    STATUS_REVERSE = 128,
    STATUS_INVINCIBILITY = 256,
    STATUS_DAMAGE = 512,
    STATUS_ON_SNOW = 1024,
    STATUS_THROUGH_WALLOBJ = 2048,
    STATUS_SEARCH_RAIL = 4096,
    STATUS_ATTACKDAMAGE = 8192,
    STATUS_ON_TURB = 16384,
    STATUS_TRAP_COLORBALL = 32768,
    STATUS_TRAP_PARTSLOCK = 65536,
    STATUS_SPEED_DOWN = 131072,
    STATUS_EGGCONFETTI = 262144,
    STATUS_NIGHTSEFFECT = 524288,
    STATUS_NONE_RIDE = 1048576,
    STATUS_MASK_UPDATE = 2080639,
    STATUS_MASK_CONDITION = 1015808,
};
// total size: 0x10
class hkQuaternion {
    // Members
public:
    class hkVector4 m_vec; // offset 0x0, size 0x10
};
// total size: 0xC
class __vector_imp : private __vector_pod, private compile_assert {};
// total size: 0x5C
class clsPhantomCollectorInfo : public clsCollectorInfo {};
enum enmCtrlMode {
    CTRL_MODE_WALK = 0,
    CTRL_MODE_RIDE = 1,
    CTRL_MODE_CHANGE = 2,
    CTRL_MODE_ADD_PARTS = 3,
    CTRL_MODE_GDIVE = 4,
};
// total size: 0x34
class Agent3FuncsIntern : public Agent3Funcs {
    // Members
public:
    enum Symmetric m_symmetric; // offset 0x30, size 0x4
};
// total size: 0x1
class binary_function {};
// total size: 0x10
class stcExtensionData {
    // Members
public:
    class stcExtensionGDive sGDive; // offset 0x0, size 0x8
    class stcExtensionFlyAction sFly; // offset 0x8, size 0x8
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
// total size: 0x30
class Agent3Funcs {
    // Members
public:
    void * (* m_createFunc)(class hkAgent3Input &, class hkAgentEntry *, void *); // offset 0x0, size 0x4
    void (* m_destroyFunc)(class hkAgentEntry *, void *, class hkContactMgr *, class hkConstraintOwner &, class hkCollisionDispatcher *); // offset 0x4, size 0x4
    void * (* m_cleanupFunc)(class hkAgentEntry *, void *, class hkContactMgr *, class hkConstraintOwner &); // offset 0x8, size 0x4
    void (* m_removePointFunc)(class hkAgentEntry *, void *, unsigned short); // offset 0xC, size 0x4
    void (* m_commitPotentialFunc)(class hkAgentEntry *, void *, unsigned short); // offset 0x10, size 0x4
    void (* m_createZombieFunc)(class hkAgentEntry *, void *, unsigned short); // offset 0x14, size 0x4
    void (* m_updateFilterFunc)(class hkAgentEntry *, void *, class hkCdBody &, class hkCdBody &, class hkCollisionInput &, class hkContactMgr *, class hkConstraintOwner &); // offset 0x18, size 0x4
    void (* m_invalidateTimFunc)(class hkAgentEntry *, void *, class hkCollisionInput &); // offset 0x1C, size 0x4
    void (* m_warpTimeFunc)(class hkAgentEntry *, void *, float, float, class hkCollisionInput &); // offset 0x20, size 0x4
    void (* m_sepNormalFunc)(class hkAgent3Input &, class hkAgentEntry *, void *, class hkVector4 &); // offset 0x24, size 0x4
    void * (* m_processFunc)(class hkAgent3ProcessInput &, class hkAgentEntry *, void *, class hkVector4 *, class hkProcessCollisionOutput &); // offset 0x28, size 0x4
    class hkBool m_isPredictive; // offset 0x2C, size 0x1
    class hkBool m_ignoreSymmetricVersion; // offset 0x2D, size 0x1
};
// total size: 0x14
class clsStoryMgr {
    // Members
public:
    class _NNS_TEXLIST * m_psTexList_Loading; // offset 0x4, size 0x4
    unsigned int m_u32VictoryLimitMilliSec; // offset 0x8, size 0x4
    class stcFormer m_sFormer; // offset 0xC, size 0x4
    unsigned char m_eVictoryType; // offset 0x10, size 0x1
    unsigned char m_eHbMode; // offset 0x11, size 0x1
    signed char m_s8StoryNo; // offset 0x12, size 0x1
    signed char m_s8DetailNo; // offset 0x13, size 0x1
};
// total size: 0x4
class clsOOStlAllocator {
    // Members
public:
    class clsOOHeapFragment * m_pcHeap; // offset 0x0, size 0x4
};
// total size: 0x60
class stcAddPrfm {
    // Members
public:
    float f32MaxSpeedRate; // offset 0x0, size 0x4
    float f32AcceleRate; // offset 0x4, size 0x4
    float f32RotateSpeedRate; // offset 0x8, size 0x4
    float f32RotateAcceleRate; // offset 0xC, size 0x4
    float f32GripRate; // offset 0x10, size 0x4
    float f32DurabilityRate; // offset 0x14, size 0x4
    float af32MaxSpeed[3]; // offset 0x18, size 0xC
    float af32Accele[3]; // offset 0x24, size 0xC
    float f32RotateSpeed; // offset 0x30, size 0x4
    float f32RotateAccele; // offset 0x34, size 0x4
    float f32Grip; // offset 0x38, size 0x4
    float f32Durability; // offset 0x3C, size 0x4
    float f32Agp; // offset 0x40, size 0x4
    float f32GCtrlDischargeSpeed; // offset 0x44, size 0x4
    float f32GDiveSpeedRate; // offset 0x48, size 0x4
    float f32GPTakeRate; // offset 0x4C, size 0x4
    float f32GCtrlGpUseRate; // offset 0x50, size 0x4
    float f32GDiveGpUseRate; // offset 0x54, size 0x4
    signed int s32AttackEnableFrame; // offset 0x58, size 0x4
    signed short s16RingCapacity; // offset 0x5C, size 0x2
    signed char s8TrickRank; // offset 0x5E, size 0x1
    signed char s8ItemRank; // offset 0x5F, size 0x1
};
enum enmBaseType {
    BASE_PRFM_SPEED = 0,
    BASE_PRFM_FLY = 1,
    BASE_PRFM_POWER = 2,
    BASE_PRFM_SVBALL = 3,
    BASE_PRFM_SVBATTLE = 4,
    MAX_BASE_PRFM_NUM = 5,
};
// total size: 0xC
class hkTypedBroadPhaseHandle : public hkBroadPhaseHandle {
    // Members
public:
    signed char m_type; // offset 0x4, size 0x1
    signed char m_ownerOffset; // offset 0x5, size 0x1
    unsigned short m_objectQualityType; // offset 0x6, size 0x2
    unsigned int m_collisionFilterInfo; // offset 0x8, size 0x4
};
// total size: 0x1
class hkUFloat8 {
    // Members
public:
    unsigned char m_value; // offset 0x0, size 0x1
};
// total size: 0x0
class hkSpuCollisionCallbackUtil {};
// total size: 0x20
class deque : private __deque_imp {};
// total size: 0x14
class clsPathPoint : public clsPathBase {
    // Members
public:
    class _BinData * m_pPathData; // offset 0x8, size 0x4
    class NNS_CAPSULE * m_calculated_capsule; // offset 0xC, size 0x4
    signed int m_s32FilseSize_Debug; // offset 0x10, size 0x4
};
// total size: 0x208
class clsEggConfetti {
    // Members
public:
    class stcEggDetail m_sEggDetail[32]; // offset 0x4, size 0x200
    unsigned char m_u8EggDetailLoopNo; // offset 0x204, size 0x1
};
// total size: 0x68
class stcStatus {
    // Members
public:
    unsigned int u32Flg; // offset 0x0, size 0x4
    unsigned char u8Windy; // offset 0x4, size 0x1
    unsigned char u8WindWay; // offset 0x5, size 0x1
    signed int s32Num; // offset 0x8, size 0x4
    unsigned char u8RandApr; // offset 0xC, size 0x1
    float f32Up; // offset 0x10, size 0x4
    float f32Frame; // offset 0x14, size 0x4
    float f32Speed; // offset 0x18, size 0x4
    float f32RandSpeed; // offset 0x1C, size 0x4
    float f32FallSpeed; // offset 0x20, size 0x4
    float f32RandFallSpeed; // offset 0x24, size 0x4
    signed int s32TexNo; // offset 0x28, size 0x4
    unsigned char u8r; // offset 0x2C, size 0x1
    unsigned char u8g; // offset 0x2D, size 0x1
    unsigned char u8b; // offset 0x2E, size 0x1
    unsigned char u8a; // offset 0x2F, size 0x1
    signed int s32WindUnit; // offset 0x30, size 0x4
    float f32SpeedInfl; // offset 0x34, size 0x4
    class NNS_VECTOR sStartArea; // offset 0x38, size 0xC
    class NNS_VECTOR sScale; // offset 0x44, size 0xC
    class NNS_VECTOR sRandScale; // offset 0x50, size 0xC
    class NNS_VECTOR sOfsVec; // offset 0x5C, size 0xC
};
// total size: 0x4
class clsOOStlAllocator {
    // Members
public:
    class clsOOHeapFragment * m_pcHeap; // offset 0x0, size 0x4
};
// total size: 0x30
class hkMatrix3 {
    // Members
public:
    class hkVector4 m_col0; // offset 0x0, size 0x10
    class hkVector4 m_col1; // offset 0x10, size 0x10
    class hkVector4 m_col2; // offset 0x20, size 0x10
};
// total size: 0x0
class hkTypedBroadPhaseDispatcher {};
// total size: 0x0
class hkIslandPostCollideListener {};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkConstraintInstance * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x4
class clsModelType_OB {
    // Members
public:
    class NNS_OBJECT * m_psObject; // offset 0x0, size 0x4
};
// total size: 0x20
class stcStatus {
    // Members
public:
    unsigned char u8Type; // offset 0x0, size 0x1
    signed char s8Count; // offset 0x1, size 0x1
    signed short s16SubNo; // offset 0x2, size 0x2
    unsigned short u16Flg; // offset 0x4, size 0x2
    signed short s16CurNum; // offset 0x6, size 0x2
    class NNS_VECTORFAST sLastPosFast; // offset 0x10, size 0x10
};
// total size: 0x4
class hkBroadPhaseHandle {
    // Members
public:
    unsigned int m_id; // offset 0x0, size 0x4
};
// total size: 0xC
class hkContactMgr : public hkReferencedObject {
    // Members
public:
    enum Type m_type; // offset 0x8, size 0x4
};
// total size: 0x20
class NNS_MOTION {
    // Members
public:
    unsigned int fType; // offset 0x0, size 0x4
    float StartFrame; // offset 0x4, size 0x4
    float EndFrame; // offset 0x8, size 0x4
    signed int nSubmotion; // offset 0xC, size 0x4
    class NNS_SUBMOTION * pSubmotion; // offset 0x10, size 0x4
    float FrameRate; // offset 0x14, size 0x4
    unsigned int Reserved0; // offset 0x18, size 0x4
    unsigned int Reserved1; // offset 0x1C, size 0x4
};
// total size: 0x60
class clsGearPtnAirride : public clsGearBasePrototype {};
// total size: 0x2E4
class clsRainDrops_Task : public clsTask {
    // Members
public:
    class stcDetail m_sDetail[32]; // offset 0x54, size 0x280
    unsigned char m_u8DetailLoopNo; // offset 0x2D4, size 0x1
    unsigned long long * m_pu64GsPacket_DrawRainDrops; // offset 0x2D8, size 0x4
    unsigned int m_u32MY; // offset 0x2DC, size 0x4
    float m_f32GSDH; // offset 0x2E0, size 0x4
};
// total size: 0x14
class __cdeque_imp : public __cdeque_deleter, private compile_assert {};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkWorldDeletionListener * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x2
class hkHalf {
    // Members
public:
    signed short m_value; // offset 0x0, size 0x2
};
// total size: 0x40
class ToiInfo {
    // Members
public:
    class hkContactPoint m_contactPoint; // offset 0x0, size 0x20
    class hkPadSpu m_time; // offset 0x20, size 0x4
    class hkPadSpu m_seperatingVelocity; // offset 0x24, size 0x4
    class hkGskCache16 m_gskCache; // offset 0x28, size 0xC
    class hkContactPointMaterial16 m_material; // offset 0x34, size 0x8
};
// total size: 0xC
class stcTrickSubParam {
    // Members
public:
    signed short s16DataNum; // offset 0x0, size 0x2
    float f32Width; // offset 0x4, size 0x4
    float f32Scale; // offset 0x8, size 0x4
};
// total size: 0x1
class compile_assert {};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkCharacterProxyListener * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x2C4
class stcEtcBinaryStageData {
    // Members
public:
    unsigned char u8Bg___r_Top; // offset 0x0, size 0x1
    unsigned char u8Bg___g; // offset 0x1, size 0x1
    unsigned char u8Bg___b; // offset 0x2, size 0x1
    unsigned char u8Bg___a; // offset 0x3, size 0x1
    float f32Clip___Near_1View_Top; // offset 0x4, size 0x4
    float f32Clip___Far__1View; // offset 0x8, size 0x4
    float f32Clip___Near_2View; // offset 0xC, size 0x4
    float f32Clip___Far__2View; // offset 0x10, size 0x4
    float f32Clip___Near_3View; // offset 0x14, size 0x4
    float f32Clip___Far__3View; // offset 0x18, size 0x4
    float f32Clip___Near_4View; // offset 0x1C, size 0x4
    float f32Clip___Far__4View; // offset 0x20, size 0x4
    float f32Fog___Near0_Top; // offset 0x24, size 0x4
    float f32Fog___Far0; // offset 0x28, size 0x4
    float f32Fog___r0; // offset 0x2C, size 0x4
    float f32Fog___g0; // offset 0x30, size 0x4
    float f32Fog___b0; // offset 0x34, size 0x4
    float f32Fog___InertiaK0; // offset 0x38, size 0x4
    float f32Fog___Near1; // offset 0x3C, size 0x4
    float f32Fog___Far1; // offset 0x40, size 0x4
    float f32Fog___r1; // offset 0x44, size 0x4
    float f32Fog___g1; // offset 0x48, size 0x4
    float f32Fog___b1; // offset 0x4C, size 0x4
    float f32Fog___InertiaK1; // offset 0x50, size 0x4
    float f32Fog___Near2; // offset 0x54, size 0x4
    float f32Fog___Far2; // offset 0x58, size 0x4
    float f32Fog___r2; // offset 0x5C, size 0x4
    float f32Fog___g2; // offset 0x60, size 0x4
    float f32Fog___b2; // offset 0x64, size 0x4
    float f32Fog___InertiaK2; // offset 0x68, size 0x4
    float f32Fog___Near3; // offset 0x6C, size 0x4
    float f32Fog___Far3; // offset 0x70, size 0x4
    float f32Fog___r3; // offset 0x74, size 0x4
    float f32Fog___g3; // offset 0x78, size 0x4
    float f32Fog___b3; // offset 0x7C, size 0x4
    float f32Fog___InertiaK3; // offset 0x80, size 0x4
    float f32Fog___Near4; // offset 0x84, size 0x4
    float f32Fog___Far4; // offset 0x88, size 0x4
    float f32Fog___r4; // offset 0x8C, size 0x4
    float f32Fog___g4; // offset 0x90, size 0x4
    float f32Fog___b4; // offset 0x94, size 0x4
    float f32Fog___InertiaK4; // offset 0x98, size 0x4
    float f32Fog___Near5; // offset 0x9C, size 0x4
    float f32Fog___Far5; // offset 0xA0, size 0x4
    float f32Fog___r5; // offset 0xA4, size 0x4
    float f32Fog___g5; // offset 0xA8, size 0x4
    float f32Fog___b5; // offset 0xAC, size 0x4
    float f32Fog___InertiaK5; // offset 0xB0, size 0x4
    float f32Fog___Near6; // offset 0xB4, size 0x4
    float f32Fog___Far6; // offset 0xB8, size 0x4
    float f32Fog___r6; // offset 0xBC, size 0x4
    float f32Fog___g6; // offset 0xC0, size 0x4
    float f32Fog___b6; // offset 0xC4, size 0x4
    float f32Fog___InertiaK6; // offset 0xC8, size 0x4
    float f32Sky___RotNode1_Top; // offset 0xCC, size 0x4
    float f32Sky___RotNode2; // offset 0xD0, size 0x4
    float f32Sky___RotNode3; // offset 0xD4, size 0x4
    float f32Lit___AmbientR0_Top; // offset 0xD8, size 0x4
    float f32Lit___AmbientG0; // offset 0xDC, size 0x4
    float f32Lit___AmbientB0; // offset 0xE0, size 0x4
    float f32Lit___ParallelR0; // offset 0xE4, size 0x4
    float f32Lit___ParallelG0; // offset 0xE8, size 0x4
    float f32Lit___ParallelB0; // offset 0xEC, size 0x4
    float f32Lit___ParallelA0; // offset 0xF0, size 0x4
    float f32Lit___ParallelInten0; // offset 0xF4, size 0x4
    float f32Lit___ParallelDirX0; // offset 0xF8, size 0x4
    float f32Lit___ParallelDirY0; // offset 0xFC, size 0x4
    float f32Lit___ParallelDirZ0; // offset 0x100, size 0x4
    float f32Lit___ParallelPosX0; // offset 0x104, size 0x4
    float f32Lit___ParallelPosY0; // offset 0x108, size 0x4
    float f32Lit___ParallelPosZ0; // offset 0x10C, size 0x4
    float f32Lit___SpecularR0; // offset 0x110, size 0x4
    float f32Lit___SpecularG0; // offset 0x114, size 0x4
    float f32Lit___SpecularB0; // offset 0x118, size 0x4
    float f32Lit___SpecularA0; // offset 0x11C, size 0x4
    float f32Lit___SpecularDirX0; // offset 0x120, size 0x4
    float f32Lit___SpecularDirY0; // offset 0x124, size 0x4
    float f32Lit___SpecularDirZ0; // offset 0x128, size 0x4
    float f32Lit___AmbientR1; // offset 0x12C, size 0x4
    float f32Lit___AmbientG1; // offset 0x130, size 0x4
    float f32Lit___AmbientB1; // offset 0x134, size 0x4
    float f32Lit___ParallelR1; // offset 0x138, size 0x4
    float f32Lit___ParallelG1; // offset 0x13C, size 0x4
    float f32Lit___ParallelB1; // offset 0x140, size 0x4
    float f32Lit___ParallelA1; // offset 0x144, size 0x4
    float f32Lit___ParallelInten1; // offset 0x148, size 0x4
    float f32Lit___ParallelDirX1; // offset 0x14C, size 0x4
    float f32Lit___ParallelDirY1; // offset 0x150, size 0x4
    float f32Lit___ParallelDirZ1; // offset 0x154, size 0x4
    float f32Lit___ParallelPosX1; // offset 0x158, size 0x4
    float f32Lit___ParallelPosY1; // offset 0x15C, size 0x4
    float f32Lit___ParallelPosZ1; // offset 0x160, size 0x4
    float f32Lit___SpecularR1; // offset 0x164, size 0x4
    float f32Lit___SpecularG1; // offset 0x168, size 0x4
    float f32Lit___SpecularB1; // offset 0x16C, size 0x4
    float f32Lit___SpecularA1; // offset 0x170, size 0x4
    float f32Lit___SpecularDirX1; // offset 0x174, size 0x4
    float f32Lit___SpecularDirY1; // offset 0x178, size 0x4
    float f32Lit___SpecularDirZ1; // offset 0x17C, size 0x4
    float f32Lit___AmbientR2; // offset 0x180, size 0x4
    float f32Lit___AmbientG2; // offset 0x184, size 0x4
    float f32Lit___AmbientB2; // offset 0x188, size 0x4
    float f32Lit___ParallelR2; // offset 0x18C, size 0x4
    float f32Lit___ParallelG2; // offset 0x190, size 0x4
    float f32Lit___ParallelB2; // offset 0x194, size 0x4
    float f32Lit___ParallelA2; // offset 0x198, size 0x4
    float f32Lit___ParallelInten2; // offset 0x19C, size 0x4
    float f32Lit___ParallelDirX2; // offset 0x1A0, size 0x4
    float f32Lit___ParallelDirY2; // offset 0x1A4, size 0x4
    float f32Lit___ParallelDirZ2; // offset 0x1A8, size 0x4
    float f32Lit___ParallelPosX2; // offset 0x1AC, size 0x4
    float f32Lit___ParallelPosY2; // offset 0x1B0, size 0x4
    float f32Lit___ParallelPosZ2; // offset 0x1B4, size 0x4
    float f32Lit___SpecularR2; // offset 0x1B8, size 0x4
    float f32Lit___SpecularG2; // offset 0x1BC, size 0x4
    float f32Lit___SpecularB2; // offset 0x1C0, size 0x4
    float f32Lit___SpecularA2; // offset 0x1C4, size 0x4
    float f32Lit___SpecularDirX2; // offset 0x1C8, size 0x4
    float f32Lit___SpecularDirY2; // offset 0x1CC, size 0x4
    float f32Lit___SpecularDirZ2; // offset 0x1D0, size 0x4
    float f32Lit___AmbientR3; // offset 0x1D4, size 0x4
    float f32Lit___AmbientG3; // offset 0x1D8, size 0x4
    float f32Lit___AmbientB3; // offset 0x1DC, size 0x4
    float f32Lit___ParallelR3; // offset 0x1E0, size 0x4
    float f32Lit___ParallelG3; // offset 0x1E4, size 0x4
    float f32Lit___ParallelB3; // offset 0x1E8, size 0x4
    float f32Lit___ParallelA3; // offset 0x1EC, size 0x4
    float f32Lit___ParallelInten3; // offset 0x1F0, size 0x4
    float f32Lit___ParallelDirX3; // offset 0x1F4, size 0x4
    float f32Lit___ParallelDirY3; // offset 0x1F8, size 0x4
    float f32Lit___ParallelDirZ3; // offset 0x1FC, size 0x4
    float f32Lit___ParallelPosX3; // offset 0x200, size 0x4
    float f32Lit___ParallelPosY3; // offset 0x204, size 0x4
    float f32Lit___ParallelPosZ3; // offset 0x208, size 0x4
    float f32Lit___SpecularR3; // offset 0x20C, size 0x4
    float f32Lit___SpecularG3; // offset 0x210, size 0x4
    float f32Lit___SpecularB3; // offset 0x214, size 0x4
    float f32Lit___SpecularA3; // offset 0x218, size 0x4
    float f32Lit___SpecularDirX3; // offset 0x21C, size 0x4
    float f32Lit___SpecularDirY3; // offset 0x220, size 0x4
    float f32Lit___SpecularDirZ3; // offset 0x224, size 0x4
    float f32Lit___AmbientR4; // offset 0x228, size 0x4
    float f32Lit___AmbientG4; // offset 0x22C, size 0x4
    float f32Lit___AmbientB4; // offset 0x230, size 0x4
    float f32Lit___ParallelR4; // offset 0x234, size 0x4
    float f32Lit___ParallelG4; // offset 0x238, size 0x4
    float f32Lit___ParallelB4; // offset 0x23C, size 0x4
    float f32Lit___ParallelA4; // offset 0x240, size 0x4
    float f32Lit___ParallelInten4; // offset 0x244, size 0x4
    float f32Lit___ParallelDirX4; // offset 0x248, size 0x4
    float f32Lit___ParallelDirY4; // offset 0x24C, size 0x4
    float f32Lit___ParallelDirZ4; // offset 0x250, size 0x4
    float f32Lit___ParallelPosX4; // offset 0x254, size 0x4
    float f32Lit___ParallelPosY4; // offset 0x258, size 0x4
    float f32Lit___ParallelPosZ4; // offset 0x25C, size 0x4
    float f32Lit___SpecularR4; // offset 0x260, size 0x4
    float f32Lit___SpecularG4; // offset 0x264, size 0x4
    float f32Lit___SpecularB4; // offset 0x268, size 0x4
    float f32Lit___SpecularA4; // offset 0x26C, size 0x4
    float f32Lit___SpecularDirX4; // offset 0x270, size 0x4
    float f32Lit___SpecularDirY4; // offset 0x274, size 0x4
    float f32Lit___SpecularDirZ4; // offset 0x278, size 0x4
    char c8IgnoreResidencePortal_0_0_Top; // offset 0x27C, size 0x1
    char c8IgnoreResidencePortal_0_1; // offset 0x27D, size 0x1
    char c8IgnoreResidencePortal_0_2; // offset 0x27E, size 0x1
    char c8IgnoreResidencePortal_0_3; // offset 0x27F, size 0x1
    char c8IgnoreResidencePortal_0_4; // offset 0x280, size 0x1
    char c8IgnoreResidencePortal_0_5; // offset 0x281, size 0x1
    char c8IgnoreResidencePortal_0_6; // offset 0x282, size 0x1
    char c8IgnoreResidencePortal_0_7; // offset 0x283, size 0x1
    char c8IgnoreResidencePortal_0_8; // offset 0x284, size 0x1
    char c8IgnoreResidencePortal_0_9; // offset 0x285, size 0x1
    char c8IgnoreResidencePortal_0_10; // offset 0x286, size 0x1
    char c8IgnoreResidencePortal_0_11; // offset 0x287, size 0x1
    char c8IgnoreResidencePortal_0_12; // offset 0x288, size 0x1
    char c8IgnoreResidencePortal_0_13; // offset 0x289, size 0x1
    char c8IgnoreResidencePortal_0_14; // offset 0x28A, size 0x1
    char c8IgnoreResidencePortal_0_15; // offset 0x28B, size 0x1
    char c8IgnoreResidencePortal_0_16; // offset 0x28C, size 0x1
    char c8IgnoreResidencePortal_0_17; // offset 0x28D, size 0x1
    char c8IgnoreResidencePortal_1_0; // offset 0x28E, size 0x1
    char c8IgnoreResidencePortal_1_1; // offset 0x28F, size 0x1
    char c8IgnoreResidencePortal_1_2; // offset 0x290, size 0x1
    char c8IgnoreResidencePortal_1_3; // offset 0x291, size 0x1
    char c8IgnoreResidencePortal_1_4; // offset 0x292, size 0x1
    char c8IgnoreResidencePortal_1_5; // offset 0x293, size 0x1
    char c8IgnoreResidencePortal_1_6; // offset 0x294, size 0x1
    char c8IgnoreResidencePortal_1_7; // offset 0x295, size 0x1
    char c8IgnoreResidencePortal_1_8; // offset 0x296, size 0x1
    char c8IgnoreResidencePortal_1_9; // offset 0x297, size 0x1
    char c8IgnoreResidencePortal_1_10; // offset 0x298, size 0x1
    char c8IgnoreResidencePortal_1_11; // offset 0x299, size 0x1
    char c8IgnoreResidencePortal_1_12; // offset 0x29A, size 0x1
    char c8IgnoreResidencePortal_1_13; // offset 0x29B, size 0x1
    char c8IgnoreResidencePortal_1_14; // offset 0x29C, size 0x1
    char c8IgnoreResidencePortal_1_15; // offset 0x29D, size 0x1
    char c8IgnoreResidencePortal_1_16; // offset 0x29E, size 0x1
    char c8IgnoreResidencePortal_1_17; // offset 0x29F, size 0x1
    char c8IgnoreResidencePortal_2_0; // offset 0x2A0, size 0x1
    char c8IgnoreResidencePortal_2_1; // offset 0x2A1, size 0x1
    char c8IgnoreResidencePortal_2_2; // offset 0x2A2, size 0x1
    char c8IgnoreResidencePortal_2_3; // offset 0x2A3, size 0x1
    char c8IgnoreResidencePortal_2_4; // offset 0x2A4, size 0x1
    char c8IgnoreResidencePortal_2_5; // offset 0x2A5, size 0x1
    char c8IgnoreResidencePortal_2_6; // offset 0x2A6, size 0x1
    char c8IgnoreResidencePortal_2_7; // offset 0x2A7, size 0x1
    char c8IgnoreResidencePortal_2_8; // offset 0x2A8, size 0x1
    char c8IgnoreResidencePortal_2_9; // offset 0x2A9, size 0x1
    char c8IgnoreResidencePortal_2_10; // offset 0x2AA, size 0x1
    char c8IgnoreResidencePortal_2_11; // offset 0x2AB, size 0x1
    char c8IgnoreResidencePortal_2_12; // offset 0x2AC, size 0x1
    char c8IgnoreResidencePortal_2_13; // offset 0x2AD, size 0x1
    char c8IgnoreResidencePortal_2_14; // offset 0x2AE, size 0x1
    char c8IgnoreResidencePortal_2_15; // offset 0x2AF, size 0x1
    char c8IgnoreResidencePortal_2_16; // offset 0x2B0, size 0x1
    char c8IgnoreResidencePortal_2_17; // offset 0x2B1, size 0x1
    char c8IgnoreResidencePortal_3_0; // offset 0x2B2, size 0x1
    char c8IgnoreResidencePortal_3_1; // offset 0x2B3, size 0x1
    char c8IgnoreResidencePortal_3_2; // offset 0x2B4, size 0x1
    char c8IgnoreResidencePortal_3_3; // offset 0x2B5, size 0x1
    char c8IgnoreResidencePortal_3_4; // offset 0x2B6, size 0x1
    char c8IgnoreResidencePortal_3_5; // offset 0x2B7, size 0x1
    char c8IgnoreResidencePortal_3_6; // offset 0x2B8, size 0x1
    char c8IgnoreResidencePortal_3_7; // offset 0x2B9, size 0x1
    char c8IgnoreResidencePortal_3_8; // offset 0x2BA, size 0x1
    char c8IgnoreResidencePortal_3_9; // offset 0x2BB, size 0x1
    char c8IgnoreResidencePortal_3_10; // offset 0x2BC, size 0x1
    char c8IgnoreResidencePortal_3_11; // offset 0x2BD, size 0x1
    char c8IgnoreResidencePortal_3_12; // offset 0x2BE, size 0x1
    char c8IgnoreResidencePortal_3_13; // offset 0x2BF, size 0x1
    char c8IgnoreResidencePortal_3_14; // offset 0x2C0, size 0x1
    char c8IgnoreResidencePortal_3_15; // offset 0x2C1, size 0x1
    char c8IgnoreResidencePortal_3_16; // offset 0x2C2, size 0x1
    char c8IgnoreResidencePortal_3_17; // offset 0x2C3, size 0x1
};
// total size: 0x28
class clsWorldGpMgr {
    // Members
public:
    unsigned int m_u32TotalTime; // offset 0x4, size 0x4
    unsigned char m_eHbMode; // offset 0x8, size 0x1
    unsigned char m_au8Points[8]; // offset 0x9, size 0x8
    unsigned char m_au8Ranking[8]; // offset 0x11, size 0x8
    unsigned char m_au8RankingPlayer[8]; // offset 0x19, size 0x8
    unsigned char m_u8TopComCharacterId; // offset 0x21, size 0x1
    signed char m_s8WorldGpStageNo; // offset 0x22, size 0x1
    signed char m_s8DetailNo; // offset 0x23, size 0x1
    unsigned char m_u8PlannedTopComId; // offset 0x24, size 0x1
};
// total size: 0x14
class stcDetail {
    // Members
public:
    float f32LifeFrame; // offset 0x0, size 0x4
    unsigned short u16x; // offset 0x4, size 0x2
    unsigned short u16y; // offset 0x6, size 0x2
    unsigned char u8r; // offset 0x8, size 0x1
    unsigned char u8rShift1; // offset 0x9, size 0x1
    signed char s8Uv; // offset 0xA, size 0x1
    unsigned char u8ViewportNo; // offset 0xB, size 0x1
    float f32Alpha; // offset 0xC, size 0x4
    unsigned short u16ColorNo; // offset 0x10, size 0x2
};
// total size: 0x6C
class stcAddPrfm {
    // Members
public:
    float f32MaxSpeedRate; // offset 0x0, size 0x4
    float f32AcceleRate; // offset 0x4, size 0x4
    float f32RotateSpeedRate; // offset 0x8, size 0x4
    float f32RotateAcceleRate; // offset 0xC, size 0x4
    float f32GripRate; // offset 0x10, size 0x4
    float f32DurabilityRate; // offset 0x14, size 0x4
    float f32Speed[3]; // offset 0x18, size 0xC
    float f32Accele[3]; // offset 0x24, size 0xC
    float f32RotateSpeed; // offset 0x30, size 0x4
    float f32RotateAccele; // offset 0x34, size 0x4
    float f32Grip; // offset 0x38, size 0x4
    float f32JumpSpeed; // offset 0x3C, size 0x4
    float f32JumpAccele; // offset 0x40, size 0x4
    float f32Durability; // offset 0x44, size 0x4
    unsigned int u32Ability; // offset 0x48, size 0x4
    float f32MaxAgp; // offset 0x4C, size 0x4
    float f32GCtrlDischargeSpeed; // offset 0x50, size 0x4
    float f32GDiveSpeedRate; // offset 0x54, size 0x4
    float f32GPTakeRate; // offset 0x58, size 0x4
    float f32GCtrlGpUseRate; // offset 0x5C, size 0x4
    float f32GDiveGpUseRate; // offset 0x60, size 0x4
    signed int s32AttackEnableFrame; // offset 0x64, size 0x4
    signed short s16RingCapacity; // offset 0x68, size 0x2
    signed char s8TrickRank; // offset 0x6A, size 0x1
    signed char s8ItemRank; // offset 0x6B, size 0x1
};
// total size: 0x14
class hkBroadPhase : public hkReferencedObject {
    // Members
public:
    class hkMultiThreadCheck m_multiThreadCheck; // offset 0x8, size 0x8
    class hkCriticalSection * m_criticalSection; // offset 0x10, size 0x4
};
enum enmDraw2DType {
    TYPE_2D_BOARD = 0,
    TYPE_2D_BIKE = 1,
    TYPE_2D_SKATE = 2,
    TYPE_2D_AIRRIDE = 3,
    TYPE_2D_WHEEL = 4,
    TYPE_2D_SURFING = 5,
    TYPE_2D_GRIND = 6,
    TYPE_2D_SP_DURABILITY = 7,
    TYPE_2D_SP_AGP = 8,
    TYPE_2D_SP_MAX_SPEED = 9,
    TYPE_2D_SP_1ST_SPEED = 10,
    TYPE_2D_SP_GC_SPEED = 11,
    TYPE_2D_SP_ADD_TRICK = 12,
    TYPE_2D_SP_GHOST = 13,
    TYPE_2D_SP_AUTO_WALL_RUN = 14,
    TYPE_2D_SP_RING_CAPACITY = 15,
    TYPE_2D_SP_TANK = 16,
    TYPE_2D_SP_MAG_BARRIER = 17,
    TYPE_2D_SP_ANGEL_OR_DEVIL = 18,
    TYPE_2D_SP_ITEM_RANK_UP = 19,
    TYPE_2D_SP_SOUND_CHANGE = 20,
    TYPE_2D_SP_TRAP_VIEW = 21,
    TYPE_2D_SP_TRAP_CTRL = 22,
    TYPE_2D_SP_TRAP_SPEED = 23,
    TYPE_2D_SP_ALL_PARAM_UP = 24,
    TYPE_2D_SP_ATTACK_TIME_UP = 25,
    TYPE_2D_SP_GP_INFINITY = 26,
    TYPE_2D_SP_GP_GET_RATE = 27,
    TYPE_2D_SP_ANGEL = 28,
    TYPE_2D_SP_DEVIL = 29,
    TYPE_2D_SP_THROTTLE = 30,
    TYPE_2D_MAX = 31,
    TYPE_2D_EMPTY = 32,
};
// total size: 0x150
class hkWorldDynamicsStepInfo {
    // Members
public:
    class hkStepInfo m_stepInfo; // offset 0x0, size 0x10
    class hkSolverInfo m_solverInfo; // offset 0x10, size 0x140
};
// total size: 0x18
class clsOOMap : public map {};
// total size: 0x1C
class hkAgentNnEntry : public hkAgentEntry {
    // Members
public:
    unsigned short m_agentIndexOnCollidable[2]; // offset 0x8, size 0x4
    class hkContactMgr * m_contactMgr; // offset 0xC, size 0x4
    unsigned char m_collisionQualityIndex; // offset 0x10, size 0x1
    unsigned char m_forceCollideOntoPpu; // offset 0x11, size 0x1
    unsigned char m_padding[2]; // offset 0x12, size 0x2
    class hkLinkedCollidable * m_collidable[2]; // offset 0x14, size 0x8
};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkCollidable * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0xC
class __vector_pod {
    // Members
public:
    class compressed_pair capacity_; // offset 0x0, size 0x4
    unsigned int size_; // offset 0x4, size 0x4
    unsigned int * data_; // offset 0x8, size 0x4
};
// total size: 0x4
class hkCharacterProxyListener {};
// total size: 0x0
class clsScore2D_Task {};
// total size: 0x8
class compressed_pair : private compressed_pair_imp {};
// total size: 0xC
class hkArray {
    // Members
public:
    class PropertyLock * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x1
class hkEnum {
    // Members
public:
    signed char m_storage; // offset 0x0, size 0x1
};
// total size: 0x8
class stcExtensionFlyAction {
    // Members
public:
    class stcExtensionLeverRate sLever; // offset 0x0, size 0x8
};
// total size: 0x4C
struct /* @anon14 */ {};
// total size: 0x1A0
class hkAllCdPointCollector : public hkCdPointCollector {
    // Members
public:
    class hkInplaceArray m_hits; // offset 0x10, size 0x190
};
// total size: 0x4
class clsTurbTrickAction : public clsBaseTrickAction {};
// total size: 0x0
class hkContactImpulseLimitBreachedListener {};
enum enmType {
    TYPE_FRONT = 0,
    TYPE_BACK = 1,
};
enum enmRunMode {
    COM_RUN_MODE_HIGH = 0,
    COM_RUN_MODE_NORMAL = 1,
    COM_RUN_MODE_LOW = 2,
};
// total size: 0xC
class PropertyLock {
    // Members
public:
    unsigned int m_key; // offset 0x0, size 0x4
    class hkMultiThreadCheck m_multiThreadCheck; // offset 0x4, size 0x8
};

enum enmMotionType {
    MOTION_WALK = 0,
    MOTION_BOARD = 1,
    MOTION_BIKE = 2,
    MOTION_SKATE = 3,
    MOTION_AIRRIDE = 4,
    MOTION_WHEEL = 5,
    MOTION_SURFING = 6,
    MOTION_DUMMY_SKATE_WALK = 7,
    MAX_MOTION = 8,
    MOTION_EMPTY = -1,
};
// total size: 0x34
class stcMotionCam1 {
    // Members
public:
    class NNS_VECTOR sAddPos; // offset 0x0, size 0xC
    class NNS_QUATERNION sAddQuat; // offset 0xC, size 0x10
    class NNS_CAMERAPTR * psBaseCam; // offset 0x1C, size 0x4
    class NNS_MOTION * psCamMotion; // offset 0x20, size 0x4
    float f32StartFrame; // offset 0x24, size 0x4
    float f32PlayFrame; // offset 0x28, size 0x4
    float f32EndFrame; // offset 0x2C, size 0x4
    float f32SpeedRate; // offset 0x30, size 0x4
};
// total size: 0x4
class hkRayCollidableFilter {};
// total size: 0x4
class clsOOStlAllocator {
    // Members
public:
    class clsOOHeapFragment * m_pcHeap; // offset 0x0, size 0x4
};
// total size: 0x34
class clsModelType_OB_TX_MO_MA_MF {
    // Members
public:
    class NNS_OBJECT * m_psObject; // offset 0x0, size 0x4
    class _NNS_TEXLIST * m_psTexList; // offset 0x4, size 0x4
    class NNS_MOTION * m_psMotion; // offset 0x8, size 0x4
    float m_f32MotionFrame; // offset 0xC, size 0x4
    class NNS_OBJECT * m_psMatMotObj; // offset 0x10, size 0x4
    class NNS_MOTION * m_psMatMotion; // offset 0x14, size 0x4
    unsigned int * m_psMatStatus; // offset 0x18, size 0x4
    float m_f32MatMotionFrame; // offset 0x1C, size 0x4
    class NNS_OBJECT * m_psMorphObj; // offset 0x20, size 0x4
    class NNS_MORPHTARGETLIST * m_psMorphTargetList; // offset 0x24, size 0x4
    class NNS_MOTION * m_psMorphMotion; // offset 0x28, size 0x4
    float * m_pf32MorphWaitPallet; // offset 0x2C, size 0x4
    float m_f32MorphMotionFrame; // offset 0x30, size 0x4
};
enum enmComDis {
    COM_DIS_NON = 0,
    COM_DIS_20 = 1,
    COM_DIS_40 = 2,
    COM_DIS_60 = 3,
    COM_DIS_80 = 4,
    MAX_COM_DIS = 4,
};
// total size: 0x8
class hkReferencedObject : public hkBaseObject {
    // Members
public:
    unsigned short m_memSizeAndFlags; // offset 0x4, size 0x2
    signed short m_referenceCount; // offset 0x6, size 0x2
};
// total size: 0x4
class clsPipeTrickAction : public clsBaseTrickAction {};
// total size: 0x50
class clsGimmickObj : public clsObject {
    // Members
public:
    class NNS_VECTORFAST m_sPosVecFast; // offset 0x10, size 0x10
    class NNS_QUATERNION m_sRotQuat; // offset 0x20, size 0x10
    class NNS_VECTOR m_sScaleVec; // offset 0x30, size 0xC
    class stcSetDataDetail * m_psSetDataDetail; // offset 0x3C, size 0x4
    unsigned int m_u32Attr; // offset 0x40, size 0x4
    enum enmRet m_enClipRet; // offset 0x44, size 0x4
    unsigned int m_u32State; // offset 0x48, size 0x4
    unsigned char m_u8PortalNo; // offset 0x4C, size 0x1
    unsigned char m_u8DrawFlg; // offset 0x4D, size 0x1
    unsigned char m_bEffective; // offset 0x4E, size 0x1
};
// total size: 0x1
class __red_black_tree {};
// total size: 0x0
class clsScript_Task {};
// total size: 0x1C
class clsCamCtrl {
    // Members
public:
    unsigned short m_u16Priority; // offset 0x4, size 0x2
    float m_f32AliveTime; // offset 0x8, size 0x4
    unsigned short m_u16TblIdx; // offset 0xC, size 0x2
    unsigned int (* m_pfPreIntervention)(class clsPfCamera *); // offset 0x10, size 0x4
    unsigned int (* m_pfPostIntervention)(class clsPfCamera *); // offset 0x14, size 0x4
    unsigned int m_u32UniqNo; // offset 0x18, size 0x4
};
// total size: 0x4
class compressed_pair : private compressed_pair_imp {};
// total size: 0x8
class compressed_pair_imp {
    // Members
public:
    class value_compare first_; // offset 0x0, size 0x1
    class node * second_; // offset 0x4, size 0x4
};
// total size: 0x10
class stcEggDetail {
    // Members
public:
    float f32LifeFrame; // offset 0x0, size 0x4
    unsigned short u16x; // offset 0x4, size 0x2
    unsigned short u16y; // offset 0x6, size 0x2
    unsigned char u8Size; // offset 0x8, size 0x1
    unsigned char u8ColorNo; // offset 0x9, size 0x1
    signed char s8Uv; // offset 0xA, size 0x1
    unsigned char u8ViewportNo; // offset 0xB, size 0x1
    unsigned short s16Alpha; // offset 0xC, size 0x2
    signed short s16Rot; // offset 0xE, size 0x2
};
// total size: 0x0
class hkCollisionAgentConfig {};
// total size: 0x10
class clsLerpParam {
    // Members
public:
    float m_f32Target; // offset 0x0, size 0x4
    float m_f32Result; // offset 0x4, size 0x4
    float m_f32Add; // offset 0x8, size 0x4
    float m_f32Frame; // offset 0xC, size 0x4
};
// total size: 0x4
class hkPadSpu {
    // Members
public:
    class hkCdBody * m_storage; // offset 0x0, size 0x4
};
// total size: 0x20
class __deque_imp : public __deque_deleter, private compile_assert {};
// total size: 0x4
class stcFormer {
    // Members
public:
    unsigned char u8StoryNo; // offset 0x0, size 0x1
    unsigned char u8StageNo; // offset 0x1, size 0x1
    unsigned char u8EventNo; // offset 0x2, size 0x1
    unsigned char u8MovieNo; // offset 0x3, size 0x1
};
// total size: 0x8
class hkContactPointMaterial16 : public hkContactPointMaterial {};
// total size: 0x8
class compressed_pair_imp {
    // Members
public:
    class clsOOStlAllocator first_; // offset 0x0, size 0x4
    class anchor second_; // offset 0x4, size 0x4
};
enum enmRingTableType {
    RING_TABLE_0 = 0,
    RING_TABLE_50 = 1,
    RING_TABLE_100 = 2,
    RING_TABLE_20_40 = 3,
    RING_TABLE_50_70 = 4,
    RING_TABLE_50_80 = 5,
    RING_TABLE_50_100 = 6,
    RING_TABLE_10_20_50 = 7,
    RING_TABLE_20_40_50 = 8,
    RING_TABLE_20_40_60 = 9,
    RING_TABLE_20_40_70 = 10,
    RING_TABLE_20_40_100 = 11,
    RING_TABLE_20_50_70 = 12,
    RING_TABLE_30_40_50 = 13,
    RING_TABLE_40_50_70 = 14,
    RING_TABLE_50_70_100 = 15,
    RING_TABLE_40_60_80 = 16,
    RING_TABLE_50_100_100 = 17,
    MAX_RING_TABLE_NUM = 18,
};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkRigidBody * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x4
class anchor {
    // Members
public:
    class node_base * left_; // offset 0x0, size 0x4
};
// total size: 0x8
class hkSmallArray {
    // Members
public:
    class hkConstraintInternal * m_data; // offset 0x0, size 0x4
    unsigned short m_size; // offset 0x4, size 0x2
    unsigned short m_capacityAndFlags; // offset 0x6, size 0x2
};
// total size: 0x60
class clsGearPtnModelPart : public clsGearBaseParts {
    // Members
public:
    float m_f32AddY; // offset 0x50, size 0x4
};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkConstraintListener * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x7C
struct /* @anon15 */ {};
// total size: 0xAC
class clsSingleModelGimmick_Task : public clsBaseGimmickBody {};
// total size: 0x8
class sceGsMiptbp1 {
    // Members
public:
    unsigned long TBP1 : 14; // offset 0x0, size 0x4
    unsigned long TBW1 : 6; // offset 0x0, size 0x4
    unsigned long TBP2 : 14; // offset 0x0, size 0x4
    unsigned long TBW2 : 6; // offset 0x0, size 0x4
    unsigned long TBP3 : 14; // offset 0x0, size 0x4
    unsigned long TBW3 : 6; // offset 0x0, size 0x4
    unsigned long pad60 : 4; // offset 0x0, size 0x4
};
// total size: 0x7C
class clsBlur_Task : public clsTask {
    // Members
public:
    float m_af32GravityFrame[4]; // offset 0x54, size 0x10
    unsigned long long * m_pu64GsPacket_Capture; // offset 0x64, size 0x4
    unsigned long long * m_pu64GsPacket_DrawBlur; // offset 0x68, size 0x4
    unsigned int m_u32FbDrawHeightx16; // offset 0x6C, size 0x4
    unsigned int m_u32WY_TEXHx16; // offset 0x70, size 0x4
    unsigned short m_u16DrawBlur_BaseW; // offset 0x74, size 0x2
    unsigned short m_u16DrawBlur_BaseH0; // offset 0x76, size 0x2
    unsigned short m_u16DrawBlur_BaseH1; // offset 0x78, size 0x2
};
// total size: 0x28
class NNS_SUBMOTION {
    // Members
public:
    unsigned int fType; // offset 0x0, size 0x4
    unsigned int fIPType; // offset 0x4, size 0x4
    union { // inferred
        signed int Id; // offset 0x8, size 0x4
        struct { // inferred
            signed short Id0; // offset 0x8, size 0x2
            signed short Id1; // offset 0xA, size 0x2
        };
    };
    float StartFrame; // offset 0xC, size 0x4
    float EndFrame; // offset 0x10, size 0x4
    float StartKeyFrame; // offset 0x14, size 0x4
    float EndKeyFrame; // offset 0x18, size 0x4
    signed int nKeyFrame; // offset 0x1C, size 0x4
    signed int KeySize; // offset 0x20, size 0x4
    void * pKeyList; // offset 0x24, size 0x4
};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkContactImpulseLimitBreachedListener * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x18
class __tree : private __red_black_tree {
    // Members
public:
    class compressed_pair alloc_; // offset 0x0, size 0x8
    class compressed_pair node_alloc_; // offset 0x8, size 0x8
    class compressed_pair comp_; // offset 0x10, size 0x8
};
// total size: 0x4
class compressed_pair_imp : private allocator {
    // Members
public:
    unsigned int second_; // offset 0x0, size 0x4
};
// total size: 0x14
class stcDetail {
    // Members
public:
    float f32LifeFrame; // offset 0x0, size 0x4
    unsigned short u16x; // offset 0x4, size 0x2
    unsigned short u16y; // offset 0x6, size 0x2
    unsigned char u8r; // offset 0x8, size 0x1
    unsigned char u8rShift1; // offset 0x9, size 0x1
    signed char s8Uv; // offset 0xA, size 0x1
    unsigned char u8ViewportNo; // offset 0xB, size 0x1
    float f32Alpha; // offset 0xC, size 0x4
    class NNS_VECTORFAST * psGrowAndPosVF; // offset 0x10, size 0x4
};
// total size: 0x4
class stcSendAdv {
    // Members
public:
    unsigned int u5CharaId : 5; // offset 0x0, size 0x4
    unsigned int u2PadNo : 2; // offset 0x0, size 0x4
    unsigned int u1Paddin : 1; // offset 0x0, size 0x4
    unsigned int u8GearCtrlNo : 8; // offset 0x0, size 0x4
    unsigned int u8Padding1 : 8; // offset 0x0, size 0x4
    unsigned int u8Padding2 : 8; // offset 0x0, size 0x4
};
// total size: 0x200
class hkRigidBody : public hkEntity {};
// total size: 0xC
class hkGskCache16 : public hkGskCache {};
// total size: 0x14
class hkCollisionInput {
    // Members
public:
    class hkPadSpu m_dispatcher; // offset 0x0, size 0x4
    class hkPadSpu m_tolerance; // offset 0x4, size 0x4
    class hkPadSpu m_filter; // offset 0x8, size 0x4
    class hkPadSpu m_convexListFilter; // offset 0xC, size 0x4
    class hkPadSpu m_createPredictiveAgents; // offset 0x10, size 0x1
};
// total size: 0x0
class hkBroadPhaseBorder {};
enum Symmetric {
    IS_SYMMETRIC = 0,
    IS_NOT_SYMMETRIC = 1,
    IS_NOT_SYMMETRIC_AND_FLIPPED = 2,
};
// total size: 0x10
class stcGDivePath {
    // Members
public:
    signed short s16MaxSpeed; // offset 0x0, size 0x2
    signed short s16MinSpeed; // offset 0x2, size 0x2
    signed short s16Flag; // offset 0x4, size 0x2
    signed short as16Reserve[5]; // offset 0x6, size 0xA
};
// total size: 0x8
class stcExtensionLeverRate {
    // Members
public:
    float f32LeverRateX; // offset 0x0, size 0x4
    float f32LeverRateY; // offset 0x4, size 0x4
};
// total size: 0x190
class hkInplaceArray : public hkArray {
    // Members
public:
    class hkRootCdPoint m_storage[8]; // offset 0x10, size 0x180
};
// total size: 0x0
class hkConstraintListener {};
// total size: 0x10
class NNS_QUATERNION {
    // Members
public:
    float x; // offset 0x0, size 0x4
    float y; // offset 0x4, size 0x4
    float z; // offset 0x8, size 0x4
    float w; // offset 0xC, size 0x4
};
enum enmPriority {
    PRI_LV_00 = 0,
    PRI_LV_01 = 1,
    PRI_LV_02 = 2,
    PRI_LV_03 = 3,
    PRI_LV_04 = 4,
    PRI_LV_05 = 5,
    PRI_LV_06 = 6,
    PRI_HIGHT = 5,
    PRI_MID_HIGHT = 4,
    PRI_NORMAL = 3,
    PRI_MID_LOW = 2,
    PRI_LOW = 1,
};
// total size: 0x4C
struct /* @anon16 */ {};
// total size: 0xC
class vector : private __vector_imp {};
enum enmRet {
    VISIBLE_CLIP = 0,
    VISIBLE = 1,
    OUT_VISIBLE = 2,
    OUT_PORTAL = 3,
    OUT_FAR = 4,
};
// total size: 0x18
class compressed_pair_imp {
    // Members
public:
    class clsOOStlAllocator first_; // offset 0x0, size 0x4
    class cdeque second_; // offset 0x4, size 0x14
};
enum enmGearType {
    GEAR_TYPE_BOARD = 0,
    GEAR_TYPE_BIKE = 1,
    GEAR_TYPE_AIRRIDE = 2,
    GEAR_TYPE_SKATE = 3,
    GEAR_TYPE_WHEEL = 4,
    GEAR_TYPE_SURFING = 5,
    GEAR_TYPE_EMPTY = 6,
    GEAR_PROTOTYPE_MAX = 7,
    GEAR_TYPE_EFFECT_PART = 7,
    GEAR_TYPE_MODEL_PART = 8,
};
// total size: 0xCB0
class clsBaseRace_Task : public clsTask {
    // Members
public:
    class clsResidenceEffect cResidenceEffect; // offset 0x54, size 0x704
    class stcSendAdv m_sSendAdv[8]; // offset 0x758, size 0x20
    void * m_pvStagePackBuffer; // offset 0x778, size 0x4
    signed int m_s32PlayerNum; // offset 0x77C, size 0x4
    signed int m_s32UserNum; // offset 0x780, size 0x4
    signed int m_s32ComNum; // offset 0x784, size 0x4
    signed int m_s32ViewNum; // offset 0x788, size 0x4
    signed int m_s32LapNum; // offset 0x78C, size 0x4
    void * m_pavCharaPackBuffer[8]; // offset 0x790, size 0x20
    void * m_pvUnion2DPackBuffer; // offset 0x7B0, size 0x4
    void * m_pvStage2DPackBuffer; // offset 0x7B4, size 0x4
    class clsReInitGraphics_Task * m_pcReInitGraphics_Task; // offset 0x7B8, size 0x4
    unsigned int m_u32LoadCnt; // offset 0x7BC, size 0x4
    unsigned int m_u32GearLoadCnt; // offset 0x7C0, size 0x4
    unsigned int m_u32CharaLoadNum; // offset 0x7C4, size 0x4
    unsigned int m_au32LoadedCharaIndex[19]; // offset 0x7C8, size 0x4C
    class clsOOClock m_cClock_CountDown; // offset 0x814, size 0x24
    class clsOOClock m_cClock_RaceTime; // offset 0x838, size 0x24
    void * * m_appvMotLoadBufAddr[64]; // offset 0x85C, size 0x100
    enum enmRestartMode m_eRestartMode; // offset 0x95C, size 0x4
    enum enmDraw2DAttr m_eDraw2DAttr; // offset 0x960, size 0x4
    enum enmJudgmentAttr m_eJudgmentAttr; // offset 0x964, size 0x4
    signed int m_s32StageNo; // offset 0x968, size 0x4
    unsigned int m_u32GameRandSeed; // offset 0x96C, size 0x4
    class clsGmkManager * m_pcGmkManager; // offset 0x970, size 0x4
    class clsGravityGimmickManager * m_pcGravityGimmickManager; // offset 0x974, size 0x4
    class NNS_CAMERAPTR * m_apsBaseCam[4]; // offset 0x978, size 0x10
    class NNS_MOTION * m_apsCamMotion[4]; // offset 0x988, size 0x10
    signed int m_s32StartCamCnt; // offset 0x998, size 0x4
    float m_f32StartVoiceFrame; // offset 0x99C, size 0x4
    class clsCamCtrl * m_pcStartCamCtrl; // offset 0x9A0, size 0x4
    class stcMotionCam1 m_sStartCamData; // offset 0x9A4, size 0x34
    class clsStageName2D_Task * m_psStageNameTask; // offset 0x9D8, size 0x4
    class stcMotionTable * m_apsUnionMotionTable[8]; // offset 0x9DC, size 0x20
    class stcMotionTable * m_apsCharaMotionTable[19][8]; // offset 0x9FC, size 0x260
    signed int m_s32GoalCounter; // offset 0xC5C, size 0x4
    float m_f32SkillAgpPoint; // offset 0xC60, size 0x4
    signed char m_s8OmoteUraStageNo; // offset 0xC64, size 0x1
    unsigned char m_u8MotLoadNum; // offset 0xC65, size 0x1
    unsigned char m_bUra; // offset 0xC66, size 0x1
    unsigned char m_bIsSetComPlannedRank; // offset 0xC67, size 0x1
    unsigned char m_abIsPlayerKeyValid[8]; // offset 0xC68, size 0x8
    unsigned char m_bStartCamera; // offset 0xC70, size 0x1
    unsigned char m_bEnableUpdateBurnOutEffect; // offset 0xC71, size 0x1
    unsigned char m_bDisableBlur; // offset 0xC72, size 0x1
    unsigned char m_bStoryStartEvent; // offset 0xC73, size 0x1
    unsigned char m_u8LoadSe_Mode; // offset 0xC74, size 0x1
    signed char m_s8LoadSe_PortNo; // offset 0xC75, size 0x1
    signed char m_s8LoadSe_PlayerNo; // offset 0xC76, size 0x1
    float m_f32FlyAgpBonusPoint; // offset 0xC78, size 0x4
    float m_f32SpeedAgpBonusPoint; // offset 0xC7C, size 0x4
    float m_f32PowerAgpBonusPoint; // offset 0xC80, size 0x4
    class clsTask * m_pcEffectWrist_Task; // offset 0xC84, size 0x4
    class clsTask * m_pcEffectLine_Task; // offset 0xC88, size 0x4
    class clsTask * m_pcEffectCharge_Task; // offset 0xC8C, size 0x4
    enum enmStoryProductionMode m_eProductionMode; // offset 0xC90, size 0x4
    unsigned char m_bSeWalkFlag; // offset 0xC94, size 0x1
    class clsBlur_Task * m_pcBlurTask; // offset 0xC98, size 0x4
    signed int m_eRacePauseRet; // offset 0xC9C, size 0x4
    class clsTask * m_psStartCountDownTask; // offset 0xCA0, size 0x4
    class clsTask * m_psResult2DTask; // offset 0xCA4, size 0x4
    enum enmRaceInfo m_eRaceInfo; // offset 0xCA8, size 0x4
    enum enmRaceInfo m_eRaceInfo_Old; // offset 0xCAC, size 0x4
};
// total size: 0x8
class compressed_pair : private compressed_pair_imp {};
// total size: 0x4
class hkPadSpu {
    // Members
public:
    class hkCollisionQualityInfo * m_storage; // offset 0x0, size 0x4
};
// total size: 0xC
class hkConstraintData : public hkReferencedObject {
    // Members
public:
    unsigned int m_userData; // offset 0x8, size 0x4
};
// total size: 0x4
class clsOOStlAllocator {
    // Members
public:
    class clsOOHeapFragment * m_pcHeap; // offset 0x0, size 0x4
};
// total size: 0x28
class _BinData {
    // Members
public:
    char c8Type[4]; // offset 0x0, size 0x4
    signed int s32Ver; // offset 0x4, size 0x4
    class NNS_VECTORFAST * psVector; // offset 0x8, size 0x4
    class _LineData * psLine; // offset 0xC, size 0x4
    class _stcEndPosList * psEPList; // offset 0x10, size 0x4
    float f32MaxLineDepth; // offset 0x14, size 0x4
    float f32MainLength; // offset 0x18, size 0x4
    signed int s32PointNum; // offset 0x1C, size 0x4
    signed int s32LineNum; // offset 0x20, size 0x4
    unsigned char u8LineType; // offset 0x24, size 0x1
    unsigned char u8PathType; // offset 0x25, size 0x1
    unsigned char u8Padding[2]; // offset 0x26, size 0x2
};
// total size: 0x3C
class stcPlayStatus {
    // Members
public:
    float f32DefScale; // offset 0x0, size 0x4
    float f32RandScale; // offset 0x4, size 0x4
    float f32AddScale; // offset 0x8, size 0x4
    float f32FadeFrame; // offset 0xC, size 0x4
    float f32Height; // offset 0x10, size 0x4
    class NNS_VECTOR sStartVec; // offset 0x14, size 0xC
    class NNS_VECTOR sPowerScale; // offset 0x20, size 0xC
    float f32Speed; // offset 0x2C, size 0x4
    float f32TuStart; // offset 0x30, size 0x4
    float f32TuSize; // offset 0x34, size 0x4
    float f32TuSpeed; // offset 0x38, size 0x4
};
// total size: 0xC
class node_base : public anchor {
    // Members
public:
    class node_base * right_; // offset 0x4, size 0x4
    class __pointer_plus_bit parent_; // offset 0x8, size 0x4
};
// total size: 0x5C
class clsStageName2D_Task : public clsTemporary2D_Task {
    // Members
public:
    unsigned char m_bEndFlag; // offset 0x58, size 0x1
};
// total size: 0x14
class clsOOList : public list {};
// total size: 0x50
class stcPortalMtx {
    // Members
public:
    float aInvMtx[4][4]; // offset 0x0, size 0x40
    signed short s16LocalSx; // offset 0x40, size 0x2
    signed short s16LocalSy; // offset 0x42, size 0x2
    signed short s16LocalSz; // offset 0x44, size 0x2
    signed short s16LocalEx; // offset 0x46, size 0x2
    signed short s16LocalEy; // offset 0x48, size 0x2
    signed short s16LocalEz; // offset 0x4A, size 0x2
    unsigned char u8PaddinPS2[4]; // offset 0x4C, size 0x4
};
// total size: 0x4
class clsSingleton {};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkSimulationIsland * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x3C
class clsSlerpQuat {
    // Members
public:
    class NNS_QUATERNION m_sBaseQuat; // offset 0x0, size 0x10
    class NNS_QUATERNION m_sSlerpQuat; // offset 0x10, size 0x10
    class NNS_QUATERNION m_sResultQuat; // offset 0x20, size 0x10
    float m_f32Rate; // offset 0x30, size 0x4
    float m_f32Add; // offset 0x34, size 0x4
    unsigned char m_bIsSlerp; // offset 0x38, size 0x1
};
// total size: 0x1
class allocator {};
// total size: 0x1
class hkBool {
    // Members
public:
    char m_bool; // offset 0x0, size 0x1
};
// total size: 0xC
class __vector_imp : private __vector_deleter {};
// total size: 0x4C
struct /* @anon17 */ {};
// total size: 0x8
class compressed_pair_imp {
    // Members
public:
    class clsOOStlAllocator first_; // offset 0x0, size 0x4
    unsigned int second_; // offset 0x4, size 0x4
};
// total size: 0x4
class hkEnum {
    // Members
public:
    unsigned int m_storage; // offset 0x0, size 0x4
};
// total size: 0xC
class vector : private __vector_imp {};
// total size: 0x4
class clsFreeTrickAction : public clsBaseTrickAction {};
// total size: 0x140
class hkSolverInfo {
    // Members
public:
    float m_one; // offset 0x0, size 0x4
    float m_tau; // offset 0x4, size 0x4
    float m_damping; // offset 0x8, size 0x4
    float m_frictionTau; // offset 0xC, size 0x4
    class hkVector4 m_globalAccelerationPerSubStep; // offset 0x10, size 0x10
    class hkVector4 m_globalAccelerationPerStep; // offset 0x20, size 0x10
    class hkVector4 m_integrateVelocityFactor; // offset 0x30, size 0x10
    class hkVector4 m_invIntegrateVelocityFactor; // offset 0x40, size 0x10
    float m_dampDivTau; // offset 0x50, size 0x4
    float m_tauDivDamp; // offset 0x54, size 0x4
    float m_dampDivFrictionTau; // offset 0x58, size 0x4
    float m_frictionTauDivDamp; // offset 0x5C, size 0x4
    float m_contactRestingVelocity; // offset 0x60, size 0x4
    class DeactivationInfo m_deactivationInfo[6]; // offset 0x64, size 0xC0
    float m_deltaTime; // offset 0x124, size 0x4
    float m_invDeltaTime; // offset 0x128, size 0x4
    signed int m_numSteps; // offset 0x12C, size 0x4
    signed int m_numMicroSteps; // offset 0x130, size 0x4
    float m_invNumMicroSteps; // offset 0x134, size 0x4
    float m_invNumSteps; // offset 0x138, size 0x4
    class hkBool m_forceCoherentConstraintOrderingInSolver; // offset 0x13C, size 0x1
    unsigned char m_deactivationNumInactiveFramesSelectFlag[2]; // offset 0x13D, size 0x2
    unsigned char m_deactivationIntegrateCounter; // offset 0x13F, size 0x1
};
enum enmMode {
    MODE_NORMAL = 0,
    MODE_CURVE_CHECK = 1,
    MAX_MODE_NUM = 2,
};
// total size: 0xAC
class clsBaseGimmickBody : public clsBaseGimmickHead, public clsSingleton {
    // Members
public:
    class clsMagBarrier_Obj * m_pcObjArray; // offset 0x6C, size 0x4
    class vector m_vecGmkObjArray; // offset 0x70, size 0xC
    class vector m_vecUnusedGmkObjArray; // offset 0x7C, size 0xC
    class clsModelType_OB_TX_MO_MA m_cModel; // offset 0x88, size 0x20
    class clsGmkBurnLight_Task * pcGmkBurnLight_Task; // offset 0xA8, size 0x4
};
// total size: 0x4
class __pointer_plus_bit {
    // Members
public:
    class node_base * ptr_; // offset 0x0, size 0x4
};
// total size: 0x30
class stcData {
    // Members
public:
    class NNS_VECTORFAST sPosVecFast; // offset 0x0, size 0x10
    class NNS_VECTORFAST sDirVecFast; // offset 0x10, size 0x10
    float f32Speed; // offset 0x20, size 0x4
    float f32Accele; // offset 0x24, size 0x4
    float f32Reserved[2]; // offset 0x28, size 0x8
};
// total size: 0x4
class generic_iterator {
    // Members
public:
    class generic_iterator i_; // offset 0x0, size 0x4
};
// total size: 0x7C
struct /* @anon18 */ {};
// total size: 0xC
class hkArray {
    // Members
public:
    class hkCollisionListener * * m_data; // offset 0x0, size 0x4
    signed int m_size; // offset 0x4, size 0x4
    signed int m_capacityAndFlags; // offset 0x8, size 0x4
};
// total size: 0x8
class compressed_pair : private compressed_pair_imp {};
enum enmFlag {
    FLAG_NULL = 0,
    FLAG_DRAW_COL = 1,
    FLAG_DRAW_MOV_LINE = 2,
    FLAG_DRAW_PST_LINE = 4,
    FLAG_DRAW_VLC_LINE = 8,
    FLAG_DRAW_GRAVITY = 16,
    FLAG_DRAW_GRID = 32,
    FLAG_INFINI_AGP = 64,
    FLAG_FREE_GEARCHANGE = 128,
    FLAG_CHANGE_COM = 256,
    FLAG_STOP = 512,
    FLAG_UPDATE_TIMER = 268435456,
    FLAG_DEFAULT = 0,
};
// total size: 0x8
class compressed_pair : private compressed_pair_imp {};
// total size: 0x4
class clsOOStlAllocator {
    // Members
public:
    class clsOOHeapFragment * m_pcHeap; // offset 0x0, size 0x4
};
// total size: 0x58
class hkWorldObject : public hkReferencedObject {
    // Members
public:
    class hkWorld * m_world; // offset 0x8, size 0x4
    void * m_userData; // offset 0xC, size 0x4
    class hkLinkedCollidable m_collidable; // offset 0x10, size 0x30
    class hkMultiThreadCheck m_multiThreadCheck; // offset 0x40, size 0x8
    char * m_name; // offset 0x48, size 0x4
    class hkArray m_properties; // offset 0x4C, size 0xC
};
// total size: 0x7C
struct /* @anon19 */ {};
// total size: 0x8
class stcExtensionGDive {
    // Members
public:
    class stcExtensionLeverRate sLever; // offset 0x0, size 0x8
};
// total size: 0x20
class __deque_deleter : public __deque_deleter_common {};
// total size: 0x8
class hkMultiThreadCheck {
    // Members
public:
    unsigned int m_threadId; // offset 0x0, size 0x4
    signed short m_markCount; // offset 0x4, size 0x2
    unsigned short m_markBitStack; // offset 0x6, size 0x2
};
// total size: 0x20
class clsSurface {
    // Members
public:
    class NNS_QUATERNION m_sQuat; // offset 0x0, size 0x10
    class NNS_VECTORFAST m_sUpVecFast; // offset 0x10, size 0x10
};
// total size: 0x14
class clsTimeAtkMgr {
    // Members
public:
    enum enmStartMode m_eStartMode; // offset 0x4, size 0x4
    signed int m_s32StageNo; // offset 0x8, size 0x4
    unsigned char m_u8CharaId; // offset 0xC, size 0x1
    unsigned char m_u8PadNo; // offset 0xD, size 0x1
    unsigned char m_u8GearId; // offset 0xE, size 0x1
    unsigned char m_bNextWorldRanking; // offset 0xF, size 0x1
    unsigned char m_bStartWorldRanking; // offset 0x10, size 0x1
    unsigned char m_bModeWorldRanking; // offset 0x11, size 0x1
};
// total size: 0x4
class hkCollisionListener {};
// total size: 0x14
class list : private __list_imp {};
// total size: 0xC
class vector : private __vector_imp {};
// total size: 0x8
class compressed_pair : private compressed_pair_imp {};
// total size: 0xC0
class hkCharacterProxy : public hkReferencedObject, public hkEntityListener, public hkPhantomListener {
    // Members
public:
    class hkVector4 m_velocity; // offset 0x10, size 0x10
    class hkVector4 m_oldDisplacement; // offset 0x20, size 0x10
    class hkShapePhantom * m_shapePhantom; // offset 0x30, size 0x4
    float m_dynamicFriction; // offset 0x34, size 0x4
    float m_staticFriction; // offset 0x38, size 0x4
    class hkVector4 m_up; // offset 0x40, size 0x10
    float m_extraUpStaticFriction; // offset 0x50, size 0x4
    float m_extraDownStaticFriction; // offset 0x54, size 0x4
    float m_keepDistance; // offset 0x58, size 0x4
    float m_keepContactTolerance; // offset 0x5C, size 0x4
    float m_contactAngleSensitivity; // offset 0x60, size 0x4
    signed int m_userPlanes; // offset 0x64, size 0x4
    float m_maxCharacterSpeedForSolver; // offset 0x68, size 0x4
    float m_characterStrength; // offset 0x6C, size 0x4
    float m_characterMass; // offset 0x70, size 0x4
    class hkArray m_manifold; // offset 0x74, size 0xC
    class hkArray m_listeners; // offset 0x80, size 0xC
    class hkArray m_bodies; // offset 0x8C, size 0xC
    class hkArray m_phantoms; // offset 0x98, size 0xC
    float m_maxSlopeCosine; // offset 0xA4, size 0x4
    float m_penetrationRecoverySpeed; // offset 0xA8, size 0x4
    signed int m_maxCastIterations; // offset 0xAC, size 0x4
    unsigned char m_refreshManifoldInCheckSupport; // offset 0xB0, size 0x1
};
// total size: 0x8
class clsPfSemaphore : public clsOOSemaphore {
    // Members
public:
    signed int m_s32Id; // offset 0x4, size 0x4
};
// total size: 0x10
class stcFree {
    // Members
public:
    class stcFree * m_psBackAddr; // offset 0x0, size 0x4
    class stcFree * m_psNextAddr; // offset 0x4, size 0x4
    unsigned int m_u32FreeSize; // offset 0x8, size 0x4
    unsigned int m_u32PreGap; // offset 0xC, size 0x4
};
// total size: 0x48
class clsReplayKey : public clsPlayerKey {
    // Members
public:
    class vector m_vecKeyBuf; // offset 0x34, size 0xC
    signed int m_s32BufPos; // offset 0x40, size 0x4
    class clsPlayerTask * m_pcPlayer; // offset 0x44, size 0x4
};
// total size: 0x10
class stcGravityPath {
    // Members
public:
    signed short s16MaxSpeed; // offset 0x0, size 0x2
    signed short s16MinSpeed; // offset 0x2, size 0x2
    signed short s16Flag; // offset 0x4, size 0x2
    signed short as16Reserve[5]; // offset 0x6, size 0xA
};
enum enmWalkType {
    WALK_PRFM_NORMAL = 0,
    WALK_PRFM_SVLRACE_FAST = 1,
    WALK_PRFM_SVLRACE_USUALLY = 2,
    WALK_PRFM_SVLRACE_SLOW = 3,
    MAX_WALK_PRFM_NUM = 4,
};

// Range: 0x34F0D0 -> 0x34F364
// this: r21
void clsGearSpGpInfinity::draw(float (* psGearMtx)[4][4] /* r2 */, float f32Alpha /* r20 */, unsigned int u32AddDrawFlagI /* r20 */) {
    /* anonymous block */ {
        // Range: 0x34F0D0 -> 0x34F364
        float sMtx[4][4]; // r29+0xC0
        float sTrsMtx[4][4]; // r29+0x80
        class NNS_OBJECT * psObject; // r19
        unsigned int * psNodeStat; // r18
        unsigned int u32DrawFlag; // r17
    }
}


// Range: 0x34F370 -> 0x34F394
// this: r2
void clsGearSpThrottle::copy(class clsGearSpThrottle * pcGear /* r2 */) {
    /* anonymous block */ {
        // Range: 0x34F370 -> 0x34F394
    }
}


// Range: 0x34F3A0 -> 0x34F3C8
// this: r2
float clsGearSpThrottle::getDraw2DRate() {
    /* anonymous block */ {
        // Range: 0x34F3A0 -> 0x34F3C8
    }
}


// Range: 0x34F3D0 -> 0x34F410
// this: r2
class stcAddPrfm & clsGearSpThrottle::getPrfm() {
    /* anonymous block */ {
        // Range: 0x34F3D0 -> 0x34F410
        class stcAddPrfm * oasPrfm[3]; // r29
    }
}


// Range: 0x34F410 -> 0x34F454
// this: r2
void clsGearSpThrottle::eventGearChange() {
    /* anonymous block */ {
        // Range: 0x34F410 -> 0x34F454
    }
}


// Range: 0x34F460 -> 0x34F7C4
// this: r2
void clsGearSpSpeedTrap::eventGearChange() {
    /* anonymous block */ {
        // Range: 0x34F460 -> 0x34F7C4
        class clsPlayerTask * * apcPlayer; // r18
        unsigned int u32i; // r17
        class clsPlayerTask * pcPlayer; // r2
    }
}


// Range: 0x34F7D0 -> 0x34FB34
// this: r2
void clsGearSpCtrlTrap::eventGearChange() {
    /* anonymous block */ {
        // Range: 0x34F7D0 -> 0x34FB34
        class clsPlayerTask * * apcPlayer; // r18
        unsigned int u32i; // r17
        class clsPlayerTask * pcPlayer; // r2
    }
}


// Range: 0x34FB40 -> 0x34FEA4
// this: r2
void clsGearSpViewTrap::eventGearChange() {
    /* anonymous block */ {
        // Range: 0x34FB40 -> 0x34FEA4
        class clsPlayerTask * * apcPlayer; // r18
        unsigned int u32i; // r17
        class clsPlayerTask * pcPlayer; // r2
    }
}


// Range: 0x34FEB0 -> 0x34FEC8
// this: r2
void clsGearSpMagBarrier::eventGearChange() {
    /* anonymous block */ {
        // Range: 0x34FEB0 -> 0x34FEC8
    }
}


// Range: 0x34FED0 -> 0x34FF30
// this: r17
void clsGearSpTank::eventGearChange() {
    /* anonymous block */ {
        // Range: 0x34FED0 -> 0x34FF30
    }
}


// Range: 0x34FF30 -> 0x34FF58
// this: r2
float clsGearAngelOrDevilChange::getDraw2DRate() {
    /* anonymous block */ {
        // Range: 0x34FF30 -> 0x34FF58
    }
}


// Range: 0x34FF60 -> 0x34FFEC
// this: r2
void clsGearAngelOrDevilChange::eventGearChange() {
    /* anonymous block */ {
        // Range: 0x34FF60 -> 0x34FFEC
    }
}


// Range: 0x34FFF0 -> 0x3500D4
// this: r2
void clsGearAngelOrDevilChange::behavior() {
    /* anonymous block */ {
        // Range: 0x34FFF0 -> 0x3500D4
    }
}


// Range: 0x3500E0 -> 0x3501C8
// this: r2
void clsGearAngelOrDevil::behavior() {
    /* anonymous block */ {
        // Range: 0x3500E0 -> 0x3501C8
        class clsGearAngelOrDevilChange * pcGear; // r2
    }
}


// Range: 0x3501D0 -> 0x350208
// this: r2
void clsGearAngelOrDevil::clearChangeActionParam() {
    /* anonymous block */ {
        // Range: 0x3501D0 -> 0x350208
        class clsGearAngelOrDevilChange * pcGear; // r2
    }
}


// Range: 0x350210 -> 0x35024C
// this: r2
void clsGearReserveTank::setHideNodeStatus(unsigned int * psNodeStat /* r2 */) {
    /* anonymous block */ {
        // Range: 0x350210 -> 0x35024C
    }
}


// Range: 0x350250 -> 0x350288
// this: r2
void clsGearReserveTank::clearChangeActionParam() {
    /* anonymous block */ {
        // Range: 0x350250 -> 0x350288
        unsigned int u32Num; // r6
        unsigned char * pbUsed; // r2
    }
}


// Range: 0x350290 -> 0x3503B4
// this: r2
void clsGearThrottle::behavior() {
    /* anonymous block */ {
        // Range: 0x350290 -> 0x3503B4
        unsigned int u32GearNum; // r2
        unsigned int u32RingNum; // r2
        unsigned int u32Level; // r10
        unsigned int u32i; // r9
        class clsGearSpThrottle * pcGear; // r2
    }
}


// Range: 0x3503C0 -> 0x350414
// this: r2
void clsGearThrottle::clearChangeActionParam() {
    /* anonymous block */ {
        // Range: 0x3503C0 -> 0x350414
        class clsGearCtrl * pcGearCtrl; // r2
        unsigned int u32GearNum; // r7
        class clsGearSpThrottle * pcGear; // r2
    }
}


// Range: 0x350420 -> 0x350628
// this: r21
void clsGearMag::draw(float (* psGearMtx)[4][4] /* r2 */, float f32Alpha /* r20 */, unsigned int u32AddDrawFlagI /* r20 */) {
    /* anonymous block */ {
        // Range: 0x350420 -> 0x350628
        float sMtx[4][4]; // r29+0x80
        class NNS_OBJECT * psObject; // r19
        unsigned int * psNodeStat; // r18
        float (* psMtxPal)[4][4]; // r17
        unsigned int u32DrawFlag; // r16
    }
}


// Range: 0x350630 -> 0x3506D0
// this: r16
void clsGearMag::behavior() {
    /* anonymous block */ {
        // Range: 0x350630 -> 0x3506D0
    }
}


// Range: 0x3506D0 -> 0x350708
// this: r2
void clsGearMag::setHideNodeStatus(unsigned int * psNodeStat /* r16 */) {
    /* anonymous block */ {
        // Range: 0x3506D0 -> 0x350708
    }
}


// Range: 0x350710 -> 0x350740
// this: r2
void clsGearMag::clearChangeActionParam() {
    /* anonymous block */ {
        // Range: 0x350710 -> 0x350740
        class NNS_NODE * psNode; // r2
    }
}


// Range: 0x350740 -> 0x35089C
// this: r21
void clsInitialBoard::drawNonAction(float (* psGearMtx)[4][4] /* r20 */, float f32Alpha /* r20 */, unsigned int u32AddDrawFlagI /* r19 */) {
    /* anonymous block */ {
        // Range: 0x350740 -> 0x35089C
        class NNS_OBJECT * psObject; // r18
        unsigned int * psNodeStat; // r17
        unsigned int u32DrawFlag; // r16
    }
}


