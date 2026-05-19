#ifndef ST06SURVEILLANCECAMERA_HPP
#define ST06SURVEILLANCECAMERA_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

enum enmSCameraMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
    MODE_BROKEN = 2,
};

enum enmSCameraStep {
    STEP_TURN = 0,
    STEP_WAIT = 1,
};

// total size: 0xF0
class clsSurveillanceCamera_Obj : public clsRigidBodyGimmickObj {
public:
    clsSurveillanceCamera_Obj();
    virtual ~clsSurveillanceCamera_Obj();
    virtual void init();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const;
    virtual void reset();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual u8 checkRequestDrawDebris();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rParam1);

    clsSe3DControl* m_pcSe3DControl; // offset 0xD0, size 0x4
    enmSCameraMode m_eSCameraMode;   // offset 0xD4, size 0x4
    enmSCameraStep m_eSCameraStep;   // offset 0xD8, size 0x4
    s32 m_s32TurnDir;                // offset 0xDC, size 0x4
    f32 m_f32WaitFrame;              // offset 0xE0, size 0x4
    s32 m_A32MaxRotate;              // offset 0xE4, size 0x4
    s32 m_A32Rotate;                 // offset 0xE8, size 0x4
    s32 m_A32RotateAdd;              // offset 0xEC, size 0x4

    static f32 tof32ClipSqDist;
    static s32 toA32RotateAdd;
    static clsGravityGimmickParam t_ocGravityGimmickParam;
};

// total size: 0x94
class clsSurveillanceCamera_Task : public clsSingleModelGimmick_Task<clsSurveillanceCamera_Task,
                                                                     clsSurveillanceCamera_Obj,
                                                                     clsModelType_OB_TX> {
public:
    clsSurveillanceCamera_Task(u32 u32ObjectAreaNum);
    virtual ~clsSurveillanceCamera_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();
};

#endif // ST06SURVEILLANCECAMERA_HPP
