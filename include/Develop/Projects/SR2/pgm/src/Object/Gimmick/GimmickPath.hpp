#ifndef GIMMICKPATH_HPP
#define GIMMICKPATH_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Path.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Postural.hpp"

class clsRigidBody;

// total size: 0x78
class clsGravityGimmickParam {
public:
    NNS_VECTOR m_osGCtrlRiseRandRotSpeed;  // offset 0x0, size 0xC
    NNS_VECTOR m_osGCtrlMoveRandRotSpeed;  // offset 0xC, size 0xC
    f32 m_of32GCtrlRiseRandDelayFrame;     // offset 0x18, size 0x4
    f32 m_of32GCtrlRiseBaseHeight;         // offset 0x1C, size 0x4
    f32 m_of32GCtrlRiseRandHeight;         // offset 0x20, size 0x4
    f32 m_of32GCtrlRiseFrame;              // offset 0x24, size 0x4
    f32 m_of32GCtrlFlightTrackRate;        // offset 0x28, size 0x4
    f32 m_of32GCtrlMoveSpeed;              // offset 0x2C, size 0x4
    f32 m_of32GCtrlMoveBaseFrame;          // offset 0x30, size 0x4
    f32 m_of32GCtrlMoveRandFrame;          // offset 0x34, size 0x4
    NNS_VECTOR m_osGDiveRiseRandRotSpeed;  // offset 0x38, size 0xC
    NNS_VECTOR m_osGDiveMoveRandRotSpeed;  // offset 0x44, size 0xC
    NNS_VECTOR m_osGDiveRangeRandRotSpeed; // offset 0x50, size 0xC
    f32 m_of32GDiveRiseBaseHeight;         // offset 0x5C, size 0x4
    f32 m_of32GDiveRiseRandHeight;         // offset 0x60, size 0x4
    f32 m_of32GDiveMoveSpeed;              // offset 0x64, size 0x4
    f32 m_of32GDiveMoveFrame;              // offset 0x68, size 0x4
    f32 m_of32GDiveMoveDist;               // offset 0x6C, size 0x4
    s32 m_oa32GLinkAdjustRotate;           // offset 0x70, size 0x4
    f32 m_of32GLinkAdjustSlerp;            // offset 0x74, size 0x4
};

// total size: 0x190
class clsGimmickPath {
public:
    // Note: nested to avoid global MODE_* enum collisions; DWARF stores this enum globally.
    enum enmGimmickPathMode {
        MODE_STARTWAIT = 0,
        MODE_MAIN = 1,
        MODE_WAIT = 2,
    };

    virtual ~clsGimmickPath() {}

    clsPosturalCtrl m_cPostural;            // offset 0x10, size 0xB0
    clsPath m_cPath;                        // offset 0xC0, size 0x60
    f32 m_f32Speed;                         // offset 0x120, size 0x4
    f32 m_f32TotalFrame;                    // offset 0x124, size 0x4
    f32 m_f32StartWaitFrame;                // offset 0x128, size 0x4
    f32 m_f32EventFrame;                    // offset 0x12C, size 0x4
    enmGimmickPathMode m_enGimmickPathMode; // offset 0x130, size 0x4
    NNS_QUATERNION m_sInitRotQuat;          // offset 0x134, size 0x10
    NNS_VECTORFAST m_sInitPosVecFast;       // offset 0x150, size 0x10
    u32 m_u32HitFlg;                        // offset 0x160, size 0x4
    u8 m_bPathPointChange;                  // offset 0x164, size 0x1
    u8 m_bObjRotChange;                     // offset 0x165, size 0x1
    NNS_VECTORFAST m_sVelocityOld;          // offset 0x170, size 0x10
    f32 m_f32SpeedOld;                      // offset 0x180, size 0x4
    NNS_VECTOR m_sAngleVelocityOld;         // offset 0x184, size 0xC

    void
    init(u32 u32PathNo, u32 u32DirFlag, f32 f32Speed, f32 f32TotalFrame, f32 f32StartWaitFrame);
    void reset();
    void updatePosition(f32 f32SlerpAddRate, clsRigidBody* pcRigid);
    void updatePosition(f32 f32SlerpAddRate);
    void updatePosition_BSpline(f32 f32Param1);
    void setSpeed(f32 f32Param1) { m_f32Speed = f32Param1; }
    clsPath& getPathRef() const { return const_cast<clsPath&>(m_cPath); }
    f32 getSpeed() const { return m_f32Speed; }
    NNS_VECTORFAST& getInitPosVecFastRef() const
    {
        return const_cast<NNS_VECTORFAST&>(m_sInitPosVecFast);
    }
    NNS_VECTORFAST& getMoveVecFastRef() const
    {
        return const_cast<NNS_VECTORFAST&>(m_cPath.m_sMoveVecFast);
    }
    NNS_QUATERNION& getInitRotQuatRef() const
    {
        return const_cast<NNS_QUATERNION&>(m_sInitRotQuat);
    }
    NNS_QUATERNION& getResultQuatRef() const
    {
        return const_cast<NNS_QUATERNION&>(m_cPostural.m_cSurface.m_sResultQuat);
    }
    u32 getHitBit() const { return m_cPath.m_u16HitBit; }
    enmGimmickPathMode getMode() const { return m_enGimmickPathMode; }
    s16 getPathNo() const { return m_cPath.m_s16PathNo; }
    u8 checkPathEnd() { return m_enGimmickPathMode == MODE_WAIT; }
};

#endif // GIMMICKPATH_HPP
