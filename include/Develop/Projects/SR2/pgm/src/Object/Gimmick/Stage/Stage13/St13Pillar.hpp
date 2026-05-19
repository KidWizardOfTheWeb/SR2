#ifndef ST13PILLAR_HPP
#define ST13PILLAR_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGimmick.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBomb.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/Havok.hpp"

class clsPillar_Obj;
class clsPillarThroughCollision;
class clsPlayerTask;

enum enmPillarMode {
    PILLAR_MODE_INIT = 0,
    PILLAR_MODE_MAIN = 1,
};

enum enmPillarState {
    PILLAR_STATE_MAIN = 0,
    PILLAR_STATE_WAIT = 1,
    PILLAR_STATE_MOVE = 2,
    PILLAR_STATE_MOVE_END = 3,
    PILLAR_STATE_REMOVE = 4,
};

// total size: 0xC
class clsPillarThroughCollision : public clsBaseThroughCollision {
public:
    clsPillarThroughCollision() {}
    virtual ~clsPillarThroughCollision() {}

    virtual void contactRemoveEvent(clsPlayerTask* pParam1);
    virtual void contactTriggerEvent(clsPlayerTask* pParam1);

    clsPillar_Obj* m_pcPillar; // offset 0x8, size 0x4
};

// total size: 0xF0
class clsPillar_Obj : public clsGimmickObj {
public:
    enum enmPillarMode {
        PILLAR_MODE_INIT = 0,
        PILLAR_MODE_MAIN = 1,
    };

    enum enmPillarState {
        PILLAR_STATE_MAIN = 0,
        PILLAR_STATE_WAIT = 1,
        PILLAR_STATE_MOVE = 2,
        PILLAR_STATE_MOVE_END = 3,
        PILLAR_STATE_REMOVE = 4,
    };

    clsPillar_Obj() {}
    virtual ~clsPillar_Obj() {}

    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST13_PILLAR_23070; }
    virtual void setState(enmPillarState);
    virtual enmPillarState getState() const;
    virtual void setMode(enmPillarMode);
    virtual void init();
    virtual enmPillarMode getMode() const;
    virtual void CheckObjRemove();
    virtual void CountUp();
    virtual void createData();
    virtual void setData();
    virtual void reset();

    static f32 tof32ClipSqDist;

    enmPillarMode m_eMode;                    // offset 0x50, size 0x4
    enmPillarState m_eState;                  // offset 0x54, size 0x4
    clsPillarThroughCollision* m_pcCollision; // offset 0x58, size 0x4
    hkShape* m_pcShape;                       // offset 0x5C, size 0x4
    f32 m_f32MotionFrame;                     // offset 0x60, size 0x4
    NNS_VECTOR m_sPosition;                   // offset 0x64, size 0xC
    NNS_QUATERNION m_sRotQuat;                // offset 0x70, size 0x10
    f32 m_f32No;                              // offset 0x80, size 0x4
    f32 m_f32Wait;                            // offset 0x84, size 0x4
    f32 m_f32MoveCount;                       // offset 0x88, size 0x4
    f32 m_f32MoveFrame;                       // offset 0x8C, size 0x4
    f32 m_f32RotY;                            // offset 0x90, size 0x4
    f32 m_f32MoveAngle;                       // offset 0x94, size 0x4
    s16 m_s16Count;                           // offset 0x98, size 0x2
    f32 m_sPosturalMtx[4][4];                 // offset 0xA0, size 0x40
    // gap 0xE0-0xDF (alignment)
    clsSe3DControl* m_pcSe3DControl; // offset 0xE0, size 0x4
};

// total size: 0x48 (own fields after base 0x98)
class clsPillar_Task
    : public clsMultiModelGimmick_Task<clsPillar_Task, clsPillar_Obj, clsMultiObTxModels> {
public:
    clsPillar_Task(u32 u32ObjectAreaNum);
    virtual ~clsPillar_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    clsGmkBurnLight_Task<clsModelType_OB_TX_MO_MA>* m_pcBurnLightTask1; // offset 0x98, size 0x4
    clsGmkBurnLight_Task<clsModelType_OB_TX_MO_MA>* m_pcBurnLightTask2; // offset 0x9C, size 0x4
    clsGmkBurnLight_Task<clsModelType_OB_TX_MO_MA>* m_pcBurnLightTask3; // offset 0xA0, size 0x4
};

#endif // ST13PILLAR_HPP
