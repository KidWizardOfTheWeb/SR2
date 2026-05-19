#ifndef ST14OBJCRANE_HPP
#define ST14OBJCRANE_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage14/St14GPFan.hpp"

class clsPlayerTask;
class hkShape;

// total size: 0x110
class clsObjCrane_Object : public clsRigidBodyGimmickObj {
public:
    // Note: enmMode collision with Game.hpp — nested here for disambiguation
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    // Note: enmMoveMode collision with St06GLinkElevator.hpp (first value: MODE_WAIT) — nested
    enum enmMoveMode {
        MODE_WAIT = 0,
        MODE_MOVE = 1,
        MODE_STOP = 2,
    };

    // Note: enmMoveDir collision with St06GLinkElevator.hpp — nested here for disambiguation
    enum enmMoveDir {
        MOVE_UP = 0,
        MOVE_DOWN = 1,
    };

    clsObjCrane_Object();
    virtual ~clsObjCrane_Object() {}
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const
    {
        return nspPackId::ST14_OBJ_CRANE_24010;
    } // [ASM-derived guess — verify]
    virtual void reset();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent() {}
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rsEvent) {}
    virtual hkShape* getShape();

    s32 getTableNo() { return m_s32TableNo; } // [ASM-derived guess — verify]
    f32 getSpeed() { return m_f32Speed; }     // [ASM-derived guess — verify]

    void draw(NNS_OBJECT* psObject,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);

    static f32 tof32ClipSqDist;
    static clsGravityGimmickParam t_ocGravityGimmickParam;

    enmMode m_eMode;                  // offset 0xD0, size 0x4
    enmMoveMode m_eMoveMode;          // offset 0xD4, size 0x4
    enmMoveDir m_enmMoveDir;          // offset 0xD8, size 0x4
    clsSe3DControl* m_pcSe3DControl;  // offset 0xDC, size 0x4
    NNS_VECTORFAST m_sBaseDirVecFast; // offset 0xE0, size 0x10
    f32 m_f32Speed;                   // offset 0xF0, size 0x4
    f32 m_f32DefaultWaitFrame;        // offset 0xF4, size 0x4
    f32 m_f32DefaultMoveFrame;        // offset 0xF8, size 0x4
    f32 m_f32WaitFrame;               // offset 0xFC, size 0x4
    s32 m_s32TableNo;                 // offset 0x100, size 0x4
    u8 m_bSeFlag;                     // offset 0x104, size 0x1
};

// total size: 0xA8
class clsObjCrane_Task
    : public clsMultiShape,
      public clsSingleModelGimmick_Task<clsObjCrane_Task, clsObjCrane_Object, clsModelType_OB_TX> {
public:
    clsObjCrane_Task(u32 u32ObjectAreaNum);
    virtual ~clsObjCrane_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    hkShape* m_pcPartsShape; // offset 0xA4, size 0x4
};

#endif // ST14OBJCRANE_HPP
