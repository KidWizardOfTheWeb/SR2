#ifndef CHARAROBOBASE_HPP
#define CHARAROBOBASE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/Character.hpp"

// total size: 0x80
class clsCharaRoboBase : public clsCharacter {
public:
    clsCharaRoboBase(clsPlayerTask* pcPlayer, u8 u8Type, u8 u8ModelType)
        : clsCharacter(pcPlayer, u8Type, u8ModelType)
    {
    }
    virtual ~clsCharaRoboBase() {}

    virtual f32 getCollisionRadius() const;
    virtual f32 getDrawOffset() const;
    virtual void behavior();
    virtual void initAttack00();
    virtual void initAttack01();
    virtual void actionAttack00();
    virtual void actionAttack01();
    virtual void updateModel();
    virtual void reset();
    virtual s8 getNodeIndex(enmCharaBornNo) const;

    void updateLampFrame();
    void updateRoboRotate();
    void updateRoboCurve();

    static f32 tof32CollisionRadius;
    static s8 m_tas8ConvertTable[52];

    // Members (offset 0x60+)
    f32 m_f32LampFrame;   // offset 0x60, size 0x4
    f32 m_f32LampSpeed;   // offset 0x64, size 0x4
    u32 m_u32LampCntNum;  // offset 0x68, size 0x4
    f32 m_f32RotateSpeed; // offset 0x6C, size 0x4
    f32 m_f32CurveRotate; // offset 0x70, size 0x4
    s32 m_s32KeyFlag;     // offset 0x74, size 0x4
    f32 m_f32RotateZ;     // offset 0x78, size 0x4
};

#endif // CHARAROBOBASE_HPP
