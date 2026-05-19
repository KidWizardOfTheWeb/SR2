#ifndef ST07GATE_HPP
#define ST07GATE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsSt07Gate_Obj;
class clsSt07GateThroughCollision;
class clsSe3DControl;

// total size: 0xC
class clsSt07GateThroughCollision : public clsBaseThroughCollision {
public:
    virtual ~clsSt07GateThroughCollision() {}
    virtual void contactTriggerEvent(clsPlayerTask* pParam1);
    virtual void contactRemoveEvent(clsPlayerTask* pParam1);

    clsSt07Gate_Obj* m_pcGate; // offset 0x8, size 0x4
};

// total size: 0x120
class clsSt07Gate_Parts : public clsRigidBodyGimmickObj {
public:
    // Note: enmMode name collision with Game.hpp; nested per scaffold rule.
    enum enmMode {
        MODE_MAIN = 0,
        MODE_STANDBY = 1,
        MODE_OPEN = 2,
        MODE_WAIT = 3,
        MDOE_CLOSE = 4,
        MODE_DIE = 5,
    };

    clsSt07Gate_Parts() {}
    virtual ~clsSt07Gate_Parts() {}

    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();

    void reInit() {}
    void setOpen();
    void setClose();

    enmMode m_eMode;                  // offset 0xD0, size 0x4
    clsSt07Gate_Obj* m_pcGateObj;     // offset 0xD4, size 0x4
    u32 m_u32PartsNo;                 // offset 0xD8, size 0x4
    f32 m_f32MoveCount;               // offset 0xDC, size 0x4
    f32 m_f32MoveFrame;               // offset 0xE0, size 0x4
    f32 m_f32WaitFrame;               // offset 0xE4, size 0x4
    hkVector4 m_cMoveSpeed;           // offset 0xF0, size 0x10
    f32 m_f32MovePos;                 // offset 0x100, size 0x4
    NNS_VECTORFAST m_sInitPosVecFast; // offset 0x110, size 0x10
};

// total size: 0xC80
class clsSt07Gate_Obj : public clsRigidBodyGimmickObj {
public:
    // Note: enmGateMode name collision with St13Gate.hpp; nested per scaffold rule.
    enum enmGateMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    // Note: enmAiMode name collision with Catapult.hpp; nested per scaffold rule.
    enum enmAiMode {
        AIMODE_MAIN = 0,
        AIMODE_MOVE = 1,
        AIMODE_WAIT = 2,
        AIMODE_REVERS = 3,
    };

    clsSt07Gate_Obj() {}
    virtual ~clsSt07Gate_Obj() {}

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST07_GATE_17050; }
    virtual void reset();
    virtual void init() {}
    virtual void main();

    enmGateMode getMode() const { return m_eMode; }
    enmAiMode getAiMode() const { return m_eAiMode; }
    void setAiMode(enmAiMode eAiMode) { m_eAiMode = eAiMode; }
    u8 stepMotionFrame();

    static f32 tof32ClipSqDist;

    enmGateMode m_eMode;                        // offset 0xD0, size 0x4
    clsSt07GateThroughCollision* m_pcCollision; // offset 0xD4, size 0x4
    hkShape* m_pcShape;                         // offset 0xD8, size 0x4
    f32 m_f32ObjPosY;                           // offset 0xDC, size 0x4
    f32 m_f32MovePos;                           // offset 0xE0, size 0x4
    f32 m_f32MoveFrame;                         // offset 0xE4, size 0x4
    enmAiMode m_eAiMode;                        // offset 0xE8, size 0x4
    f32 m_f32MoveCount;                         // offset 0xEC, size 0x4
    hkVector4 m_cRotSpeed;                      // offset 0xF0, size 0x10
    s16 m_s16HitCount;                          // offset 0x100, size 0x2
    NNS_VECTORFAST m_sInitPosVecFast;           // offset 0x110, size 0x10
    f32 m_f32MotionFrame;                       // offset 0x120, size 0x4
    clsSt07Gate_Parts m_acParts[10];            // offset 0x130, size 0xB40
    clsSe3DControl* m_pcSe3DControl;            // offset 0xC70, size 0x4
};

// total size: 0x98
class clsSt07Gate_Task
    : public clsSingleModelGimmick_Task<clsSt07Gate_Task, clsSt07Gate_Obj, clsModelType_OB_TX_MO> {
public:
    clsSt07Gate_Task(u32 u32ObjectAreaNum);
    virtual ~clsSt07Gate_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST07GATE_HPP
