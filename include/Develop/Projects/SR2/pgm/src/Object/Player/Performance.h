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

// Enums
typedef enum {
    CTRL_MODE_WALK = 0,
    CTRL_MODE_NORMAL = 1
} enmCtrlMode;

typedef enum {
    GEAR_CTRL_0 = 0
} enmGearCtrl;

typedef enum {
    ACTION_MODE_0 = 0
} enmActionMode;

// Structs
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

class clsGearCtrl {
public:
    uint8_t pad[0xCC];          // 0x00 - 0xCB
    enmCtrlMode m_eCtrlMode;    // 0xCC
    uint8_t pad2[0x44];         // 0xD0 - 0x10F (rest of struct)
}; // total size: 0x110

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
}; // total size: 0x110