#ifndef ST06GLINKELEVATOR_HPP
#define ST06GLINKELEVATOR_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsSe3DControl;
class clsTask;

enum enmMoveDir {
    MOVE_UP = 0,
    MOVE_DOWN = 1,
};

// total size: 0x110
class clsGLinkElevator_Object : public clsBaseGravityLinkObject {
public:
    // Note: enmMode collision with Game.hpp (GAME_MODE___* pParam1) — nested per scaffold rule
    enum enmMode {
        MODE_NONE = 0,
        MODE_CRASH = 1,
        MODE_BREAK = 2,
    };
    // enmMoveMode body from DWARF
    enum enmMoveMode {
        MODE_WAIT = 0,
        MODE_MOVE = 1,
        MODE_STOP = 2,
    };

    clsGLinkElevator_Object() {}
    virtual ~clsGLinkElevator_Object() {}
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const
    {
        return nspPackId::ST06_GLINK_ELEVATOR_16030;
    } // [ASM-derived guess — verify]
    virtual void reset();
    virtual void main();
    virtual void mainGravity();
    virtual void mainCrash();
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rsEventI);
    virtual void drawEffect(clsPlayerTask* pcPlayer);
    virtual NNS_VECTOR* getCollisionHalfSizeVecPtr() const
    {
        return &tosCollisionHalfSizeVec;
    } // [ASM-derived guess — verify]

    enmMode m_eMode;                 // offset 0xE0, size 0x4
    enmMoveMode m_eMoveMode;         // offset 0xE4, size 0x4
    enmMoveDir m_enmMoveDir;         // offset 0xE8, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xEC, size 0x4
    clsTask* m_pcEffectTask;         // offset 0xF0, size 0x4
    f32 m_f32Speed;                  // offset 0xF4, size 0x4
    f32 m_f32DefaultWaitFrame;       // offset 0xF8, size 0x4
    f32 m_f32DefaultMoveFrame;       // offset 0xFC, size 0x4
    f32 m_f32WaitFrame;              // offset 0x100, size 0x4
    s32 m_s32TableNo;                // offset 0x104, size 0x4
    u8 m_bSeFlag;                    // offset 0x108, size 0x1
    u8 m_bFilterChange;              // offset 0x109, size 0x1

    s32 getTableNo() { return m_s32TableNo; } // [ASM-derived guess — verify]
    f32 getSpeed() { return m_f32Speed; }     // [ASM-derived guess — verify]

    static NNS_VECTOR tosCollisionHalfSizeVec;
    static f32 tof32ClipSqDist;
    static clsGravityGimmickParam t_ocSt6GravityGimmickParam;
    static clsGravityGimmickParam t_ocSt14GravityGimmickParam;
};

// total size: 0x98
class clsGLinkElevator_Task : public clsSingleModelGimmick_Task<clsGLinkElevator_Task,
                                                                clsGLinkElevator_Object,
                                                                clsModelType_OB_TX> {
public:
    clsGLinkElevator_Task(u32 u32ObjectAreaNum);
    virtual ~clsGLinkElevator_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();

    hkShape* m_pcPartsShape; // offset 0x94, size 0x4
};

#endif // ST06GLINKELEVATOR_HPP
