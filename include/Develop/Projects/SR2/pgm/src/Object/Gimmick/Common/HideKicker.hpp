#ifndef HIDEKICKER_HPP
#define HIDEKICKER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBox.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/PlayerMotion.hpp"

class clsHideKicker_Obj;

// total size: 0xC
class clsHideKickerThroughCol : public clsBaseThroughCollision {
public:
    virtual ~clsHideKickerThroughCol() {}

    virtual void contactAlwaysEvent(clsPlayerTask* pParam1);

    clsHideKicker_Obj* m_pcObj; // offset 0x8, size 0x4
};

// total size: 0xA0
class clsHideKicker_Task : public clsSingleModelGimmick_Task<clsHideKicker_Task,
                                                             clsHideKicker_Obj,
                                                             clsModelType_OB_TX_MO>,
                           public clsGimmickCommon {
public:
    clsHideKicker_Task(u32 u32ObjectAreaNum);
    virtual ~clsHideKicker_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

// total size: 0x130
class clsHideKicker_Obj : public clsRigidBodyGimmickObj {
public:
    // Note: enmState has multiple DWARF variants with no Q2 owner; this open/close variant matches
    // HideKicker behavior.
    enum enmState {
        STATE_NULL = 0,
        STATE_OPEN_INIT = 1,
        STATE_OPEN = 2,
        STATE_CLOSE_INIT = 3,
        STATE_CLOSE = 4,
    };

    clsHideKicker_Obj();
    virtual ~clsHideKicker_Obj();

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const;
    virtual void contactTriggerEvent(hkContactPoint* pcParam1, clsObject* pcParam2);
    virtual void contactAlwaysEvent(hkContactPoint* pcParam1, clsObject* pcParam2);

    void init();
    void reset();
    void main();

    enmMode m_eMode;                     // offset 0xD0, size 0x4
    enmState m_eState;                   // offset 0xD4, size 0x4
    f32 m_f32RotSpeed;                   // offset 0xD8, size 0x4
    hkShape* m_pcShape;                  // offset 0xDC, size 0x4
    clsHideKickerThroughCol m_ThrougCol; // offset 0xE0, size 0xC
    f32 m_f32RotCount;                   // offset 0xEC, size 0x4
    hkVector4 m_cOpenAngleVel;           // offset 0xF0, size 0x10
    hkVector4 m_cCloseAngleVel;          // offset 0x100, size 0x10
    hkQuaternion m_cMaxAngleQuat;        // offset 0x110, size 0x10
    u8 m_bContact;                       // offset 0x120, size 0x1
    u8 m_bFix;                           // offset 0x121, size 0x1

    static f32 m_tof32ClipSqDist;
};

#endif // HIDEKICKER_HPP
