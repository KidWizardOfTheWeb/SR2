#ifndef ST13GATE_HPP
#define ST13GATE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBomb.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsGateThroughCollision;

// total size: 0x180
class clsGate_Obj : public clsRigidBodyGimmickObj {
public:
    inline clsGate_Obj() : clsRigidBodyGimmickObj() {}
    virtual ~clsGate_Obj() {}

    enum enmGateMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enum enmAiMode {
        AIMODE_MAIN = 0,
        AIMODE_MOVE = 1,
        AIMODE_WAIT = 2,
        AIMODE_REVERS = 3,
    };

    enmGateMode m_eMode;                    // offset 0xD0, size 0x4
    clsGateThroughCollision* m_pcCollision; // offset 0xD4, size 0x4
    hkShape* m_pcShape;                     // offset 0xD8, size 0x4
    f32 m_f32ObjPosY;                       // offset 0xDC, size 0x4
    NNS_QUATERNION m_sInitRotQuat;          // offset 0xE0, size 0x10
    f32 m_f32MovePos;                       // offset 0xF0, size 0x4
    f32 m_f32MoveFrame;                     // offset 0xF4, size 0x4
    enmAiMode m_eAiMode;                    // offset 0xF8, size 0x4
    f32 m_f32MoveCount;                     // offset 0xFC, size 0x4
    f32 m_f32NodeAngle;                     // offset 0x100, size 0x4
    hkVector4 m_cRotSpeed;                  // offset 0x110, size 0x10
    hkVector4 m_cReversSpeed;               // offset 0x120, size 0x10
    s16 m_s16HitCount;                      // offset 0x130, size 0x2
    clsPlayerTask* m_pcPlayerTask[8];       // offset 0x134, size 0x20
    f32 m_f32WaitFrame;                     // offset 0x154, size 0x4
    f32 m_f32EffectFrame;                   // offset 0x158, size 0x4
    NNS_VECTORFAST m_sInitPosVecFast;       // offset 0x160, size 0x10
    f32 m_f32Scale;                         // offset 0x170, size 0x4
    clsSe3DControl* m_pcSe3DControl;        // offset 0x174, size 0x4

    static f32 tof32ClipSqDist;

    virtual void reset();
    virtual void main();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    inline void init() {}
    inline void setAiMode(enmAiMode) {}
    inline enmAiMode getAiMode() const { return AIMODE_MAIN; }
    inline nspPackId::enm getPackId() const { return nspPackId::ST13_GATE_23060; }
};

// total size: 0xC
class clsGateThroughCollision : public clsBaseThroughCollision {
public:
    virtual ~clsGateThroughCollision() {}

    clsGate_Obj* m_pcGate; // offset 0x8, size 0x4

    virtual void contactAlwaysEvent(clsPlayerTask* pParam1);
    virtual void contactRemoveEvent(clsPlayerTask* pParam1);
};

// total size: 0x9C
class clsGate_Task
    : public clsSingleModelGimmick_Task<clsGate_Task, clsGate_Obj, clsModelType_OB_TX> {
public:
    clsGate_Task(u32 u32ObjectAreaNum);
    virtual ~clsGate_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    u16* m_TexIdx;  // offset 0x94, size 0x4
    u16* m_TexIdx2; // offset 0x98, size 0x4
};

#endif // ST13GATE_HPP
