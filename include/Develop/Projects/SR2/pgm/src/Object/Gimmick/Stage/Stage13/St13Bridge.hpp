#ifndef ST13BRIDGE_HPP
#define ST13BRIDGE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsBridgeThroughCollision;
class clsBridge_Obj;
class clsSe3DControl;
class hkShape;

// total size: 0xC
class clsBridgeThroughCollision : public clsBaseThroughCollision {
public:
    virtual ~clsBridgeThroughCollision() {}
    virtual void contactTriggerEvent(clsPlayerTask* pParam1);
    virtual void contactRemoveEvent(clsPlayerTask* pParam1);

    clsBridge_Obj* m_pcBridge; // offset 0x8, size 0x4
};

// total size: 0xE0
class clsBridge_Obj : public clsGimmickObj {
public:
    enum enmBridgeMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enum enmBridgeState {
        STATE_WAIT = 0,
        STATE_MOVE = 1,
        STATE_MOVE_END = 2,
        STATE_REMOVE = 3,
    };

    clsBridge_Obj() {}
    virtual ~clsBridge_Obj() {}

    enmBridgeMode m_eMode;                    // offset 0x50, size 0x4
    enmBridgeState m_eState;                  // offset 0x54, size 0x4
    clsBridgeThroughCollision* m_pcCollision; // offset 0x58, size 0x4
    hkShape* m_pcShape;                       // offset 0x5C, size 0x4
    f32 m_f32MotionFrame;                     // offset 0x60, size 0x4
    NNS_VECTOR m_sPosition;                   // offset 0x64, size 0xC
    NNS_QUATERNION m_sRotQuat;                // offset 0x70, size 0x10
    f32 m_sScale;                             // offset 0x80, size 0x4
    f32 m_f32Wait;                            // offset 0x84, size 0x4
    s16 m_s16Count;                           // offset 0x88, size 0x2
    f32 m_sPosturalMtx[4][4];                 // offset 0x90, size 0x40
    clsSe3DControl* m_pcSe3DControl;          // offset 0xD0, size 0x4

    static f32 tof32ClipSqDist;

    enmBridgeMode getMode() const { return m_eMode; }
    enmBridgeState getState() const { return m_eState; }
    void setMode(enmBridgeMode eMode) { m_eMode = eMode; }
    void setState(enmBridgeState eState) { m_eState = eState; }
    void init() {}

    virtual void reset();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST13_BRIDGE_23050; }
    u8 stepMotionFrame();
};

// total size: 0xA0
class clsBridge_Task
    : public clsSingleModelGimmick_Task<clsBridge_Task, clsBridge_Obj, clsModelType_OB_TX_MO> {
public:
    clsBridge_Task(u32 u32ObjectAreaNum);
    virtual ~clsBridge_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();
};

#endif // ST13BRIDGE_HPP
