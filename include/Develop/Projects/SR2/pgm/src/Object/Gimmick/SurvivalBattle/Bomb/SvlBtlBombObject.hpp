#ifndef SVLBTLBOMBOBJECT_HPP
#define SVLBTLBOMBOBJECT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"

// total size: 0xF0
class clsSvlBtlBomb_Object : public clsRigidBodyGimmickObj {
public:
    // Note: enmMode collision with Game.hpp (GAME_MODE___* pParam1) — nested here
    enum enmMode {
        MODE_START = 0,
        MODE_MAIN = 1,
        MODE_WAIT = 2,
    };

    enmMode m_eMode;       // offset 0xD0, size 0x4
    s32 m_s32PlayerNo;     // offset 0xD4, size 0x4
    s32 m_s32AttackerNo;   // offset 0xD8, size 0x4
    s32 m_s32LockOnNo;     // offset 0xDC, size 0x4
    f32 m_f32FrameCount;   // offset 0xE0, size 0x4
    f32 m_f32LimitFrame;   // offset 0xE4, size 0x4
    f32 m_f32FormingFrame; // offset 0xE8, size 0x4
    f32 m_f32SeBlingFrame; // offset 0xEC, size 0x4

    static NNS_VECTORFAST t_osOffsetPosVecFastTable;
    static f32 t_f32SphereRadius;
    static f32 t_of32ClipSqDist;
    static f32 t_of32LimitFrame;

    clsSvlBtlBomb_Object();
    void lockon();
    void shoot();
    void charge();
    void draw(NNS_OBJECT* pParam1,
              f32 (*)[4][4],
              u32* pParam3,
              const f32 (*)[4][4],
              f32 (*)[4][4],
              u32 u32Param6);

    virtual ~clsSvlBtlBomb_Object();
    virtual void contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2);
    virtual void contactTriggerCallback(hkContactPointConfirmedEvent& rParam1);
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();
    virtual void requestDrawBreakEffect();
};

#endif // SVLBTLBOMBOBJECT_HPP
