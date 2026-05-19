#ifndef GRINDLINKCONTROL_HPP
#define GRINDLINKCONTROL_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Gravity/GravityActionControl.hpp"

// total size: 0x70
class clsGrindLinkControl : public clsGravityActionControl {
public:
    // Note: enmFlag name collision — multiple enmFlag declarations exist; nested to avoid conflict
    enum enmFlag {
        FLAG_CLEAR = 0,
        FLAG_UPDATE_POSTURAL_QUAT = 1,
        FLAG_UPDATE_BEHAVIOR = 2,
        FLAG_FACE_ROTATE = 4,
        FLAG_SLOPE_SLOWDOWN = 8,
        FLAG_CENTRIFUGAL_FORCE = 16,
        FLAG_REVERSE = 32,
        FLAG_NON_MOVE = 64,
        FLAG_ALL_TIME_ATTACK = 128,
        FLAG_LOSE = 256,
        FLAG_INIT = 59,
    };

    NNS_QUATERNION m_sTargetRotQuat; // offset 0x50, size 0x10
    enmFlag m_eFlag;                 // offset 0x60, size 0x4
    f32 m_f32AutoDiveRateX;          // offset 0x64, size 0x4

    clsGrindLinkControl(clsGimmickRigidBody* pcRigidBody, const clsGravityGimmickParam* pcParam) {
    } // size:128
    virtual ~clsGrindLinkControl() {} // size:96

    virtual void reset();
    virtual void actionGravityDive();

    void updateAdjustPostural(f32 param);
    void calcAdjustPostural();

    static clsGravityGimmickParam t_ocGravityGimmickParam;
    static f32 t_of32AutoAdjustPosturalRate_Link;
};

#endif // GRINDLINKCONTROL_HPP
