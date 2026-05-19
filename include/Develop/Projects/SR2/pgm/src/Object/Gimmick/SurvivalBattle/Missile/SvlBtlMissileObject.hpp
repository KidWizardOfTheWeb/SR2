#ifndef SVLBTLMISSILEOBJECT_HPP
#define SVLBTLMISSILEOBJECT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsBackLineEffectTask;

// total size: 0x150
class clsSvlBtlMissile_Object : public clsRigidBodyGimmickObj {
public:
    enum enmMode {
        MODE__READY = 0,
        MODE__WAIT = 1,
        MODE__CHARGE = 2,
        MODE__READY_SHOOT = 3,
        MODE__SHOOT = 4,
        MODE__CRUISE = 5,
        MODE__BLAST = 6,
    };

    static NNS_VECTOR tosCollisionHalfSizeVec;
    static f32 tof32ClipSqDist;
    static NNS_VECTOR tosOffsetVec_1st;
    static NNS_VECTOR tosAccurcayVec_1st;
    static NNS_VECTOR tosOffsetVec_2nd;
    static NNS_VECTOR tosAccurcayVec_2nd;

    f32 m_sDrawMtx[4][4];                   // offset 0xD0, size 0x40
    NNS_VECTOR m_sAccurcayVec;              // offset 0x110, size 0xC
    clsBackLineEffectTask* m_pcLineTask[2]; // offset 0x11C, size 0x8
    enmMode m_eMode;                        // offset 0x124, size 0x4
    s32 m_s32PlayerNo;                      // offset 0x128, size 0x4
    s32 m_s32LockOnNo;                      // offset 0x12C, size 0x4
    s32 m_s32PositionNo;                    // offset 0x130, size 0x4
    f32 m_f32FrameCount;                    // offset 0x134, size 0x4
    f32 m_f32Speed;                         // offset 0x138, size 0x4
    u32 m_u32HormingMode;                   // offset 0x13C, size 0x4
    f32 m_f32HormingRate;                   // offset 0x140, size 0x4
    s32 m_s32SeId;                          // offset 0x144, size 0x4
    s32 m_bSePlayFlg;                       // offset 0x148, size 0x4

    clsSvlBtlMissile_Object();
    virtual ~clsSvlBtlMissile_Object();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void contactTriggerCallback(hkContactPointConfirmedEvent& cEvent);
    virtual void reset();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void callbackBreakEvent();

    void
    draw(NNS_OBJECT* p1, f32 (*p2)[4][4], u32* p3, const f32 (*p4)[4][4], f32 (*p5)[4][4], u32 p6);
    void checkHitPlayer();
    void shoot(s32 s32LockOnNo, f32 f32Frame);
    void charge();
    void setup(s32 s32PlayerNo, s32 s32PositionNo);

    clsPlayerTask* getPlayerPtr();
    void calcHomingRad(const NNS_VECTORFAST* param_1, f32 param_2, NNS_QUATERNION& param_3);
};

#endif // SVLBTLMISSILEOBJECT_HPP
