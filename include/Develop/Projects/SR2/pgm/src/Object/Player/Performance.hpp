#ifndef PERFORMANCE_HPP
#define PERFORMANCE_HPP

typedef signed char      int8_t;
typedef short            int16_t;
typedef int              int32_t;
typedef long long        int64_t;

typedef unsigned char    uint8_t;
typedef unsigned short   uint16_t;
typedef unsigned int     uint32_t;
typedef unsigned long long uint64_t;

typedef uint8_t     uchar;
typedef uint16_t    ushort;
typedef uint32_t    uint;

typedef uchar   undefined1;
typedef ushort  undefined2;
typedef uint    undefined4;

#ifdef _WIN32
    typedef unsigned long ulong;
#else
    typedef unsigned int ulong;
#endif

typedef ulong   undefined8;

typedef int32_t s32;
typedef unsigned int size_t;

class clsGearCtrl; // forward decl

// Enums
//typedef enum {
    //CTRL_MODE_WALK = 0,
    //CTRL_MODE_NORMAL = 1
//} enmCtrlMode;

// typedef enum {
//    GEAR_CTRL_0 = 0
//} enmGearCtrl;

//typedef enum {
    //ACTION_MODE_0 = 0
//} enmActionMode;

// Structs

// Move this later to performance
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

typedef struct stcData {
    float f32Speed[3];        // 0x00
    float f32Accele[3];       // 0x0C
    float f32RotateSpeed;     // 0x18
    float f32RotateAccele;    // 0x1C
    float f32Grip;            // 0x20
    float f32JumpSpeed;       // 0x24
    float f32JumpAccele;      // 0x28
    float f32Durability;      // 0x2C
    uint32_t u32Ability;      // 0x30
    float f32MaxAgp;          // 0x34
    float f32GCtrlDischargeSpeed; // 0x38
    float f32GDiveSpeedRate;  // 0x3C
    float f32GPTakeRate;      // 0x40
    float f32GCtrlGpUseRate;  // 0x44
    float f32GDiveGpUseRate;  // 0x48
    int32_t s32AttackEnableFrame; // 0x4C
    int16_t s16RingCapacity;  // 0x50
    int8_t s8TrickRank;       // 0x52
    int8_t s8ItemRank;        // 0x53
} stcData; // total size: 0x54

//class clsGearCtrl {
//public:
    //uint8_t pad[0xCC];          // 0x00 - 0xCB
    //enmCtrlMode m_eCtrlMode;    // 0xCC
    //uint8_t pad2[0x44];         // 0xD0 - 0x10F (rest of struct)
//}; // total size: 0x110

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

class clsPrfm {
public:
    stcData m_sBase;                // 0x00
    stcData m_sWalk;                // 0x54
    stcData m_sData;                // 0xA8
    clsGearCtrl* m_pcGearCtrl;      // 0xFC
    float m_f32WeightRate;          // 0x100
    float m_f32InfiniGpFrame;       // 0x104
    float m_f32AdjustSpeedRate;     // 0x108
    float m_f32AdjustAcceleRate;    // 0x10C
    
    stcData* getDataPtr();
    void setMaxAgp(float f32MaxAGP);
    void setRingCapacity(signed short s16Ring);
}; // total size: 0x110

#endif // PERFORMANCE_HPP