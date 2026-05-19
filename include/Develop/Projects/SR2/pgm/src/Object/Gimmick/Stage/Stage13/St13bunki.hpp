#ifndef ST13BUNKI_HPP
#define ST13BUNKI_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"

class clsBunki_Obj;
class clsBunkiThroughCollision;
class clsPlayerTask;
class clsSe3DControl;
class hkTransformShape;

// total size: 0xC
class clsBunkiThroughCollision : public clsBaseThroughCollision {
public:
    virtual ~clsBunkiThroughCollision() {}
    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);
    virtual void contactRemoveEvent(clsPlayerTask* pcPlayer);

    clsBunki_Obj* m_pcBunki; // offset 0x8, size 0x4
};

// Enum used by clsBunki_Obj — global scope per DWARF
enum enmBunkiMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

// total size: 0x180
class clsBunki_Obj : public clsRigidBodyGimmickObj {
public:
    clsBunki_Obj() {}
    virtual ~clsBunki_Obj() {}

    // Name collision with other TUs — nested inside class per scaffold rule
    // Note: enmAiMode name collision — other TUs declare different values at global scope
    enum enmAiMode {
        AIMODE_MAIN = 0,
        AIMODE_MOVE = 1,
        AIMODE_WAIT = 2,
        AIMODE_REVERS = 3,
    };

    enmBunkiMode m_eMode;                    // offset 0xD0, size 0x4
    clsBunkiThroughCollision* m_pcCollision; // offset 0xD4, size 0x4
    hkShape* m_pcShape;                      // offset 0xD8, size 0x4
    f32 m_f32ObjAngle;                       // offset 0xDC, size 0x4
    NNS_QUATERNION m_sInitRotQuat;           // offset 0xE0, size 0x10
    f32 m_f32MoveAngle;                      // offset 0xF0, size 0x4
    f32 m_f32MoveFrame;                      // offset 0xF4, size 0x4
    enmAiMode m_eAiMode;                     // offset 0xF8, size 0x4
    f32 m_f32MoveCount;                      // offset 0xFC, size 0x4
    f32 m_f32NodeAngle;                      // offset 0x100, size 0x4
    hkVector4 m_cRotSpeed;                   // offset 0x110, size 0x10
    hkVector4 m_cReversSpeed;                // offset 0x120, size 0x10
    s32 m_s32HitCount;                       // offset 0x130, size 0x4
    clsPlayerTask* m_pcPlayerTask[8];        // offset 0x134, size 0x20
    f32 m_f32StatueAngle_1;                  // offset 0x154, size 0x4
    f32 m_f32StatueAngle_2;                  // offset 0x158, size 0x4
    f32 m_f32StatueRotAngle_1;               // offset 0x15C, size 0x4
    f32 m_f32StatueRotAngle_2;               // offset 0x160, size 0x4
    f32 m_f32WaitFrame;                      // offset 0x164, size 0x4
    f32 m_f32EffectFrame;                    // offset 0x168, size 0x4
    f32 m_f32MatFrame;                       // offset 0x16C, size 0x4
    clsSe3DControl* m_pcSe3DControl;         // offset 0x170, size 0x4

    static f32 tof32ClipSqDist;

    virtual void reset();
    virtual void main();
    virtual void PlayerTurn(clsPlayerTask* pcPlayer);
    virtual void setData();
    virtual void createData();
    virtual void destroyData();

    enmAiMode getAiMode() const { return m_eAiMode; }
    void setAiMode(enmAiMode eMode) { m_eAiMode = eMode; }
    nspPackId::enm getPackId() const { return nspPackId::ST13_BUNKI_23010; }
    void init();
};

// total size: 0xBC
class clsBunki_Task
    : public clsSingleModelGimmick_Task<clsBunki_Task, clsBunki_Obj, clsModelType_OB_TX_MO_MA> {
public:
    clsBunki_Task(u32 u32ObjectAreaNum);
    virtual ~clsBunki_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();

    u16* m_TexIdx;                       // offset 0xAC, size 0x4
    u16* m_TexIdx2;                      // offset 0xB0, size 0x4
    hkTransformShape* m_pcTransShape[2]; // offset 0xB4, size 0x8
};

#endif // ST13BUNKI_HPP
