#ifndef GEAR_HPP
#define GEAR_HPP
#include "usr/local/sega/nn/NNS.hpp"

class clsGearCtrl; // forward decl

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

// For now, we assume this to be the correctly associated enum
enum enmRet {
    VISIBLE_CLIP = 0,
    VISIBLE = 1,
    OUT_VISIBLE = 2,
    OUT_PORTAL = 3,
    OUT_FAR = 4,
};

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
/*
    Compile unit: C:\Develop\Projects\SR2\pgm\src\Object\Player\Gear\Gear.cpp
    Producer: MW MIPS C Compiler
    Language: C++
*/
unsigned int * tpsNnNodeStatus; // size: 0x4, address: 0x707DF8
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
unsigned int oau32DebugColor[16]; // size: 0x40, address: 0x655010
char * oapc8Str1[2]; // size: 0x8, address: 0x5F2198 // NOTE: all 4 of these were called "oapc8Str", so I differentiated them. PAY ATTENTION.
char * oapc8Str2[2]; // size: 0x8, address: 0x0
char * oapc8Str3[2]; // size: 0x8, address: 0x0
char * oapc8Str4[2]; // size: 0x8, address: 0x5F21B0
unsigned char oau8Mask[2]; // size: 0x2, address: 0x0
unsigned short oau16Mask[2]; // size: 0x4, address: 0x0
unsigned int oau32Mask[2]; // size: 0x8, address: 0x655050
unsigned int oau32Col[2]; // size: 0x8, address: 0x655058
// total size: 0x50

// THIS IS PURE FICTION
// Until we know what's at the start of clsGear, this is padding
class clsGearBase {
public:
    virtual void someVirtualFunction(); // vtable pointer at 0x0
    int padding; // or another member at 0x4
};

class clsGear : clsGearBase {
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

    // funcs

    void draw(float (* psGearMtx)[4][4] /* r2 */, float f32Alpha /* r20 */, unsigned int u32AddDrawFlagI /* r19 */);
    virtual void clearChangeActionParam(); // Used by all gear part classes in their own way, so it's virtual

};

#endif // GEAR_HPP


