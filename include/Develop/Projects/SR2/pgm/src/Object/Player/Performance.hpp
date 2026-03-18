#ifndef PERFORMANCE_HPP
#define PERFORMANCE_HPP

class clsGearCtrl; // forward decl
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

// enum enmGearPrfm was here, should probably be here, but the include errors are wack.

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


class stcAddPrfm {
    // total size: 0x6C
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