#ifndef GEARCTRL_HPP
#define GEARCTRL_HPP
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/Gear.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Performance.hpp"

class clsGear; // forward decl

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

// Move to some motion file
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

enum enmInitBoard {
    INIT_BOARD_CASE = 0,
    INIT_BOARD_GEAR = 1,
};

enum enmCtrlMode {
    CTRL_MODE_WALK = 0,
    CTRL_MODE_RIDE = 1,
    CTRL_MODE_CHANGE = 2,
    CTRL_MODE_ADD_PARTS = 3,
    CTRL_MODE_GDIVE = 4,
};
enum enmGearCtrl {
    CTRL_UNKNOWN = -1,
    CTRL_DEF_START = 0,
    CTRL_DEF_SNC = 0,
    CTRL_DEF_TLS = 1,
    CTRL_DEF_KNC = 2,
    CTRL_DEF_AMY = 3,
    CTRL_DEF_JET = 4,
    CTRL_DEF_STM = 5,
    CTRL_DEF_WAV = 6,
    CTRL_DEF_EGG = 7,
    CTRL_DEF_CRM = 8,
    CTRL_DEF_RUG = 9,
    CTRL_DEF_SDW = 10,
    CTRL_DEF_BLZ = 11,
    CTRL_DEF_SLV = 12,
    CTRL_DEF_NIT = 13,
    CTRL_DEF_SAM = 14,
    CTRL_DEF_BLY = 15,
    CTRL_EMPTY_GP = 16,
    CTRL_DEF_END = 17,
    CTRL_EMPTY_SH = 17,
    CTRL_SHOOTING_STAR = 18,
    CTRL_FASTER = 19,
    CTRL_FASTEST = 20,
    CTRL_TURBO_STAR = 21,
    CTRL_LIGHT_BOARD = 22,
    CTRL_COVER_S = 23,
    CTRL_COVER_F = 24,
    CTRL_COVER_P = 25,
    CTRL_ADVANTAGE_S = 26,
    CTRL_ADVANTAGE_F = 27,
    CTRL_ADVANTAGE_P = 28,
    CTRL_WIND_STAR = 29,
    CTRL_ROAD_STAR = 30,
    CTRL_AIR_SHIP = 31,
    CTRL_WHEEL_CUSTOM = 32,
    CTRL_OMNI_TEMPOS = 33,
    CTRL_HYPER_DIVE = 34,
    CTRL_GC_BOOSTER = 35,
    CTRL_GC_MASTER = 36,
    CTRL_LEGEND = 37,
    CTRL_SINOBI = 38,
    CTRL_KUNOICHI = 39,
    CTRL_RAILLINKER = 40,
    CTRL_RING_LINKER = 41,
    CTRL_INFLUENTIAL = 42,
    CTRL_G_SHOT = 43,
    CTRL_MASTER_OFF_ROAD = 44,
    CTRL_RESERVE_TANK = 45,
    CTRL_GP_TANK = 46,
    CTRL_CHAOSEMERALD = 47,
    CTRL_THE_CRAZY = 48,
    CTRL_ANGEL_OR_DEVIL = 49,
    CTRL_THROTTLE = 50,
    CTRL_MONEY_CRISIS = 51,
    CTRL_BEGINNER = 52,
    CTRL_BIG_BANG = 53,
    CTRL_GAMBLER = 54,
    CTRL_BINGO_STAR = 55,
    CTRL_WANTED = 56,
    CTRL_HANG_ON = 57,
    CTRL_MAGIC_BROOME = 58,
    CTRL_MAG = 59,
    CTRL_UNTOUCHABLE = 60,
    CTRL_RAINBOW = 61,
    CTRL_WINDCATCHER = 62,
    CTRL_MAX = 63,
};
enum enmActionMode {
    ACTION_MODE_NON = 0,
    ACTION_MODE_GETTING_ON = 1,
    ACTION_MODE_GETTING_OFF = 2,
};
// total size: 0x50
class clsGearBaseParts : public clsGear {};
// total size: 0x70
// class clsInitialBoard : public clsGearPtnBoard {};
// total size: 0x50
class stcCtrlData {
    // Members
public:
    char ac8Name[16]; // offset 0x0, size 0x10
    char ac8BinName[8]; // offset 0x10, size 0x8
    unsigned int u32UsableBit; // offset 0x18, size 0x4
    float f32Weight; // offset 0x1C, size 0x4
    //enum enmSelectType eSelectType; // offset 0x20, size 0x4
    //enum enmRingTableType eRingTableType; // offset 0x24, size 0x4
    unsigned short u16GearPrice; // offset 0x28, size 0x2
    enum enmGear aeGear[4]; // offset 0x2C, size 0x10
    enum enmGearPrfm aePrfmNo[4]; // offset 0x3C, size 0x10
    unsigned char aIsLockedBit[4]; // offset 0x4C, size 0x4
};

class _Draw2DData {
    // total size: 0x24
public:
    //enum enmDraw2DGearMode aeGearMode[3]; // offset 0x0, size 0xC
    //enum enmDraw2DType aeDrawType[3]; // offset 0xC, size 0xC
    //enum enmLevel eNextChangeGearLv; // offset 0x18, size 0x4
    //enum enmLevel ePrevChangeGearLv; // offset 0x1C, size 0x4
    unsigned char u8DataNum; // offset 0x20, size 0x1
};

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

    // Class funcs
    void behavior();
    void setUnuseGearLevel(enum enmLevel eLevel /* r2 */);
    void changeInitGearModel(enum enmInitBoard eBoard /* r2 */);
    unsigned char getEquipsGearFlags();
    enum enmMotionType getEquipsGearBaseMotionType();
    enum enmGearType getEquipsGearType();
};

#endif // GEARCTRL_HPP