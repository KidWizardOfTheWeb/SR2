#ifndef ST03SECURITYGATE_HPP
#define ST03SECURITYGATE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsSecurityGate_Ctrl;
class clsSe3DControl;
class hkShape;
class hkTransformShape;

// total size: 0xC
class clsSecurityGateCollision : public clsBaseThroughCollision {
public:
    virtual ~clsSecurityGateCollision() {}

    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);
    virtual void contactRemoveEvent(clsPlayerTask* pcPlayer);

    clsSecurityGate_Ctrl* m_pcSecurityGate_Ctrl; // offset 0x8, size 0x4
};

class clsSecurityGateModel {
public:
    clsSecurityGateModel() {}
    ~clsSecurityGateModel() {}

    clsModelType_OB_TX_MO m_cModel; // offset 0x0, size 0x10
    void* m_pvBin;                  // offset 0x10, size 0x4
};

enum enmSecurityGateMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
    MODE_CRASH_WAIT = 2,
};

enum enmSecurityGateState {
    STATE_NOT_NEXT = 0,
    STATE_OPEN = 1,
    STATE_OPEN_WAIT = 2,
    STATE_OPEN_BIGDOOR = 3,
    STATE_CLOSE_BEGIN = 4,
    STATE_CLOSE_BIGDOOR = 5,
    STATE_CLOSE = 6,
    STATE_SLEEP = 7,
};

// total size: 0x140
class clsSecurityGate_Obj : public clsRigidBodyGimmickObj {
public:
    inline clsSecurityGate_Obj() : clsRigidBodyGimmickObj() {}
    virtual ~clsSecurityGate_Obj() {}

    clsSecurityGate_Ctrl* m_pcSecurityGate_Ctrl;   // offset 0xD0, size 0x4
    enmSecurityGateMode m_eSecurityGateMode;       // offset 0xD4, size 0x4
    enmSecurityGateState m_eSecurityGateState;     // offset 0xD8, size 0x4
    enmSecurityGateState m_eNextSecurityGateState; // offset 0xDC, size 0x4
    NNS_QUATERNION m_sOffsetRot;                   // offset 0xE0, size 0x10
    NNS_QUATERNION m_sGateRot;                     // offset 0xF0, size 0x10
    NNS_VECTORFAST m_sGatePos;                     // offset 0x100, size 0x10
    NNS_VECTORFAST m_sAddPos;                      // offset 0x110, size 0x10
    f32 m_f32MotionFrame;                          // offset 0x120, size 0x4
    f32 m_f32AddFrame;                             // offset 0x124, size 0x4
    s32 m_s32Count;                                // offset 0x128, size 0x4
    s32 m_s32BigDoorCount;                         // offset 0x12C, size 0x4
    f32 m_f32DoorAnimeFrameS;                      // offset 0x130, size 0x4
    f32 m_f32DoorAnimeFrameL;                      // offset 0x134, size 0x4
    f32 m_f32BigOpenDoorWait;                      // offset 0x138, size 0x4

    static NNS_VECTORFAST m_osOffsetPos;

    virtual void createData();
    virtual void destroyData();
    virtual void openDoor();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void drawPartsBreakEffect(const NNS_VECTORFAST& rsPosVecFast);
    virtual void contactInterraction(clsRigidBodyGimmickObj* pcObject);
    inline void init() {}
    inline void reset() {}
    inline u8 checkRequestDrawDebris() { return 0; }
    inline nspPackId::enm getPackId() const { return nspPackId::ST03_SECURITY_GATE_13050; }
};

// total size: 0x2F0
class clsSecurityGate_Ctrl : public clsGimmickObj {
public:
    clsSecurityGate_Ctrl() {}
    virtual ~clsSecurityGate_Ctrl() {}

    virtual void createData();
    virtual void destroyData();
    virtual u32 getMultiDrawNum() const { return 6; }

    void reset();
    void openDoor(u32 u32PlayerNo);
    void openDoor();
    void draw(clsModelType_OB_TX_MO& rcModel,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);

    clsRigidBodyGimmickObj* m_pcRigidBodyObject; // offset 0x50, size 0x4
    clsSecurityGateCollision m_cCollision;       // offset 0x54, size 0xC
    clsSecurityGate_Obj m_acObj[2];              // offset 0x60, size 0x280
    u32 m_u32PlayerFlg;                          // offset 0x2E0, size 0x4
    u8 m_u8GateFlg;                              // offset 0x2E4, size 0x1
    clsSe3DControl* m_pcSe3DControl;             // offset 0x2E8, size 0x4
};

// total size: 0xAC
class clsSecurityGate_Task
    : public clsBaseGimmickBody<clsSecurityGate_Task, clsSecurityGate_Ctrl, clsSecurityGateModel> {
public:
    clsSecurityGate_Task(u32 u32ObjectAreaNum);
    virtual ~clsSecurityGate_Task() {}

    hkShape* m_pcPartsShape;             // offset 0xA0, size 0x4
    hkTransformShape* m_pcTransShape[2]; // offset 0xA4, size 0x8

    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI);
    inline f32 getStartMotionFrame() { return 0.0f; }
    inline f32 getEndMotionFrame() { return 0.0f; }
};

#endif // ST03SECURITYGATE_HPP
