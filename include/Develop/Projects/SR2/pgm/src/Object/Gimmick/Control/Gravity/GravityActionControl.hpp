#ifndef GRAVITYACTIONCONTROL_HPP
#define GRAVITYACTIONCONTROL_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/FrameControl.hpp"

class clsGimmickRigidBody;

enum enmRiseType {
    RISE_TYPE_NORMAL = 0,
    RISE_TYPE_MOVE = 1,
};

// total size: 0x50
class clsGravityActionControl {
public:
    // Note: enmType name collision with GravityDive.hpp (first value TYPE_FRONT); nested to avoid
    // conflict
    enum enmType {
        TYPE_NULL = 0,
        TYPE_DIVE = 1,
        TYPE_CTRL = 2,
    };

    // TODO: enmMode MWCC scoping mismatch with global enmMode in Game.hpp; verify during
    // implementation
    enum enmMode {
        MODE_NONE = 0,
        MODE_EXECUTE = 1,
        MODE_BREAK = 2,
    };

    NNS_VECTORFAST m_sSpeedVecFast;                  // offset 0x0, size 0x10
    NNS_VECTORFAST m_sAcceleVecFast;                 // offset 0x10, size 0x10
    clsPlayerTask* m_pcPlayer;                       // offset 0x20, size 0x4
    clsGimmickRigidBody* m_pcRigidBody;              // offset 0x24, size 0x4
    clsFrameControl m_cFrameControl;                 // offset 0x28, size 0x8
    enmType m_eType;                                 // offset 0x30, size 0x4
    enmMode m_eMode;                                 // offset 0x34, size 0x4
    enmStatus m_eStatus;                             // offset 0x38, size 0x4
    clsGravityGimmickParam* m_pcGravityGimmickParam; // offset 0x3C, size 0x4
    u32 m_u32DestroyPriority;                        // offset 0x40, size 0x4
    u32 m_u32RiseClearFilter;                        // offset 0x44, size 0x4
    enmRiseType m_eRiseType;                         // offset 0x48, size 0x4

    virtual ~clsGravityActionControl() {} // size:76
    virtual void reset();
    virtual void gctrlInit();
    virtual void gctrlWait();
    virtual void gctrlRise();
    virtual void gctrlFloat();
    virtual void gctrlMove();
    virtual void actionGravityDive();

    void gctrlMoveInit();
    void manageDestroy();
    void contactGravityActionRangeEvent(clsPlayerTask* pcPlayer);
    void actionGravity();

    enmMode getMode() const { return m_eMode; }      // likely: return m_eMode;
    void setMode(enmMode eMode) { m_eMode = eMode; } // likely: m_eMode = param;

    static clsGravityGimmickParam t_ocGravityGimmickParam;
};

#endif // GRAVITYACTIONCONTROL_HPP
