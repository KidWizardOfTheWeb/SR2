#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Performance.hpp"

class clsModelType_OB_TX;
class clsDrawAttackEffect_Task;
class clsPlayerTask;

// total size: 0x24
class stcData {
public:
    char     ac8Name_Debug[16]; // offset 0x00, size 0x10
    float    f32Height;         // offset 0x10, size 0x4
    float    f32Weight;         // offset 0x14, size 0x4
    unsigned char u8Style;      // offset 0x18, size 0x1
    unsigned char u8SkillType;  // offset 0x19, size 0x1
    unsigned char u8BaseType;   // offset 0x1A, size 0x1
    unsigned char u8Reserve[1]; // offset 0x1B, size 0x1
    float    f32AttackLFrame;   // offset 0x1C, size 0x4
    float    f32AttackRFrame;   // offset 0x20, size 0x4
};

// total size: 0x60
class clsCharacter {
public:
    clsModelType_OB_TX*       m_pcModel;               // 0x00, size 0x4
    stcData*                  m_posData;               // 0x04, size 0x4
    clsPlayerTask*            m_pcPlayer;              // 0x08, size 0x4
    float                     m_f32OffsetPosition;     // 0x0C, size 0x4
    unsigned char             m_u8Type;                // 0x10, size 0x1
    enmBaseType               m_eBaseType;             // 0x14, size 0x4
    enmWalkType               m_eWalkType;             // 0x18, size 0x4
    unsigned char             m_u8ModelType;           // 0x1C, size 0x1
    float                     m_f32DrawAlpha;          // 0x20, size 0x4
    float                     m_f32behaviorCnt;        // 0x24, size 0x4
    clsDrawAttackEffect_Task* m_pcDrawEffTsk;          // 0x28, size 0x4
    float                     m_sFollowOffsetVF[4];    // 0x30, size 0x10 (NNS_VECTORFAST)
    float                     m_sFollowVF[4];          // 0x40, size 0x10 (NNS_VECTORFAST)
    unsigned int              m_u32FollowCalcNodeIdx;  // 0x50, size 0x4
};

#endif // CHARACTER_HPP
