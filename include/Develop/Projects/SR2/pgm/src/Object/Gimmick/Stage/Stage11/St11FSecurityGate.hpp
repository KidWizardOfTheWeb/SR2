#ifndef ST11FSECURITYGATE_HPP
#define ST11FSECURITYGATE_HPP

#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsFSecurityGate_Ctrl;
class clsSe3DControl;

// total size: 0xC
class clsFSecurityGateCollision : public clsBaseThroughCollision {
public:
    virtual ~clsFSecurityGateCollision() {}

    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);
    virtual void contactRemoveEvent(clsPlayerTask* pcPlayer);

    clsFSecurityGate_Ctrl* m_pcFSecurityGate_Ctrl; // offset 0x8, size 0x4
};

class clsFSecurityGateModel {
public:
    clsFSecurityGateModel() {}
    ~clsFSecurityGateModel() {}

    clsModelType_OB_TX_MO_MA m_cModel; // offset 0x0, size 0x20
    void* m_pvBin;                     // offset 0x20, size 0x4
};

enum enmFSecurityGateMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

enum enmFSecurityGateState {
    STATE_NOT_NEXT = 0,
    STATE_OPEN = 1,
    STATE_CLOSE = 2,
    STATE_SLEEP = 3,
};

// total size: 0x150
class clsFSecurityGate_Obj : public clsRigidBodyGimmickObj {
public:
    clsFSecurityGate_Obj() {}
    virtual ~clsFSecurityGate_Obj() {}

    virtual void createData();
    virtual void destroyData();
    virtual void reset() {}
    virtual void init() {}
    virtual void main();
    nspPackId::enm getPackId() const { return nspPackId::ST11_FSECURITY_GATE_21010; }

    static NNS_VECTORFAST m_osOffsetColPos;

    clsFSecurityGate_Ctrl* m_pcFSecurityGate_Ctrl;   // offset 0xD0, size 0x4
    enmFSecurityGateMode m_eFSecurityGateMode;       // offset 0xD4, size 0x4
    enmFSecurityGateState m_eFSecurityGateState;     // offset 0xD8, size 0x4
    enmFSecurityGateState m_eNextFSecurityGateState; // offset 0xDC, size 0x4
    NNS_QUATERNION m_sRotOffset;                     // offset 0xE0, size 0x10
    NNS_QUATERNION m_sRotGate;                       // offset 0xF0, size 0x10
    NNS_VECTORFAST m_sPosGate;                       // offset 0x100, size 0x10
    NNS_VECTORFAST m_sPosColGate;                    // offset 0x110, size 0x10
    NNS_VECTORFAST m_sPosAdd;                        // offset 0x120, size 0x10
    f32 m_f32MotionFrame;                            // offset 0x130, size 0x4
    f32 m_f32MatMotionFrame;                         // offset 0x134, size 0x4
    f32 m_f32AddFrame;                               // offset 0x138, size 0x4
    f32 m_f32AddMatFrame;                            // offset 0x13C, size 0x4
    u8 m_bDrawFlg;                                   // offset 0x140, size 0x1
};

// total size: 0x310
class clsFSecurityGate_Ctrl : public clsGimmickObj {
public:
    clsFSecurityGate_Ctrl() {}
    virtual ~clsFSecurityGate_Ctrl() {}

    virtual void createData();
    virtual void destroyData();

    void reset();
    void draw(clsModelType_OB_TX_MO_MA& rcModel,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);
    void setPlayerFlg(u32 u32Param1) { m_u32PlayerFlg = u32Param1; }
    void setGateFlg(u8 u8Param1) { m_u8GateFlg = u8Param1; }

    clsRigidBodyGimmickObj* m_pcRigidBodyObject; // offset 0x50, size 0x4
    clsFSecurityGateCollision m_cGateCollision;  // offset 0x54, size 0xC
    clsFSecurityGate_Obj m_acGateObj[2];         // offset 0x60, size 0x2A0
    u32 m_u32PlayerFlg;                          // offset 0x300, size 0x4
    clsSe3DControl* m_pcSe3DCtrl;                // offset 0x304, size 0x4
    u8 m_u8GateFlg;                              // offset 0x308, size 0x1
    u8 m_bPlaySe;                                // offset 0x309, size 0x1
};

// total size: 0xB0
class clsFSecurityGate_Task : public clsBaseGimmickBody<clsFSecurityGate_Task,
                                                        clsFSecurityGate_Ctrl,
                                                        clsFSecurityGateModel> {
public:
    clsFSecurityGate_Task(u32 u32ObjectAreaNum);
    virtual ~clsFSecurityGate_Task();

    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI);
    f32 getStartMotionFrame() { return m_cModel.m_cModel.m_psMotion->StartFrame; }
    f32 getEndMotionFrame() { return m_cModel.m_cModel.m_psMotion->EndFrame; }
};

#endif // ST11FSECURITYGATE_HPP
