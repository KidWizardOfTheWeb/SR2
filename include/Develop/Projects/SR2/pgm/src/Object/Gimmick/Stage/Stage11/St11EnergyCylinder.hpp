#ifndef ST11ENERGYCYLINDER_HPP
#define ST11ENERGYCYLINDER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// Forward declarations
class clsSe3DControl;
class clsTask;

// Decode from ELF; 6 * 0x24 = 0xD8
struct stcThroughColInfo {
    NNS_VECTOR sPosVec;   // offset 0x0, size 0xC
    NNS_VECTOR sRotVec;   // offset 0xC, size 0xC
    NNS_VECTOR sScaleVec; // offset 0x18, size 0xC
};

// total size: 0x100
class clsEnergyCylinder_Obj : public clsRigidBodyGimmickObj {
public:
    // Note: enmMode collision with Game.hpp (GAME_MODE___* pParam1) — nested per scaffold rule
    enum enmMode {
        MODE_NONE = 0,
        MODE_EXECUTE = 1,
        MODE_BREAK = 2,
    };
    // Note: enmState name collision possible — nested here
    enum enmState {
        STATE_MAIN = 0,
        STATE_ACTION = 1,
        STATE_WAIT = 2,
        STATE_STOP = 3,
    };

    clsEnergyCylinder_Obj() {}
    virtual ~clsEnergyCylinder_Obj() {}
    virtual nspPackId::enm getPackId() const { return nspPackId::ST11_ENERGY_CYLINDER_21000; }
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void init();
    virtual void main();
    virtual void requestDrawContactEffect(const hkContactPoint* pcContact);
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rParam1);

    enmMode getMode() const { return m_eMode; }
    void setNear(u32 u32Flg, f32 f32Rate);
    void draw(clsModelType_OB_TX* pcModel,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4]);

    enmMode m_eMode;                 // offset 0xD0, size 0x4
    enmState m_eState;               // offset 0xD4, size 0x4
    f32 m_f32WaitFrame;              // offset 0xD8, size 0x4
    f32 m_f32MatMotionFrame;         // offset 0xDC, size 0x4
    u32 m_u32PlayerFlg;              // offset 0xE0, size 0x4
    u32 m_u32DrawFlg;                // offset 0xE4, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xE8, size 0x4
    f32 m_f32Frame;                  // offset 0xEC, size 0x4
    u8 m_u8ModelNum;                 // offset 0xF0, size 0x1
    s8 m_s8Rank;                     // offset 0xF1, size 0x1
    clsTask* m_pcSpark;              // offset 0xF4, size 0x4

    static f32 m_tof32LowPolyDist;
    static f32 m_tof32ClipSqDist;
};

// total size: 0x40
class clsEnergyCylinderModels {
public:
    clsEnergyCylinderModels() {}
    ~clsEnergyCylinderModels() {}

    clsModelType_OB_TX m_acModels[8]; // offset 0x0, size 0x40
};

// total size: 0x1C
class clsEnergyThroughCol : public clsBaseThroughCollision {
public:
    clsEnergyThroughCol() {}
    virtual ~clsEnergyThroughCol() {}
    virtual void contactAlwaysEvent(clsPlayerTask* pcPlayer);
    virtual void contactRemoveEvent(clsPlayerTask* pcPlayer);

    clsOOVector m_vctpcCylinderObj; // offset 0x8, size 0x10
    u8 m_u8Rank;                    // offset 0x18, size 0x1
};

// total size: 0x20C
class clsEnergyCylinder_Task : public clsBaseGimmickBody<clsEnergyCylinder_Task,
                                                         clsEnergyCylinder_Obj,
                                                         clsEnergyCylinderModels> {
public:
    clsEnergyCylinder_Task(u32 u32ObjectAreaNum);
    virtual ~clsEnergyCylinder_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI);

    void init();

    void setDraw(u32 param_1, clsEnergyCylinder_Obj* param_2); // inline weak

    clsEnergyThroughCol m_acThroughCol[6]; // offset 0xCC, size 0xA8
    clsOOVector m_vctLeftHiPolyDrawOn;     // offset 0x174, size 0x10
    clsOOVector m_vctLeftHiPolyDrawOff;    // offset 0x184, size 0x10
    clsOOVector m_vctLeftLowPolyDrawOn;    // offset 0x194, size 0x10
    clsOOVector m_vctLeftLowPolyDrawOff;   // offset 0x1A4, size 0x10
    clsOOVector m_vctRightHiPolyDrawOn;    // offset 0x1B4, size 0x10
    clsOOVector m_vctRightHiPolyDrawOff;   // offset 0x1C4, size 0x10
    clsOOVector m_vctRightLowPolyDrawOn;   // offset 0x1D4, size 0x10
    clsOOVector m_vctRightLowPolyDrawOff;  // offset 0x1E4, size 0x10
    clsOOVector m_vctPolyDraw;             // offset 0x1F4, size 0x10
    f32* m_pf32LeftTexCoordV;              // offset 0x204, size 0x4
    f32* m_pf32RightTexCoordV;             // offset 0x208, size 0x4

    static stcThroughColInfo m_toasThroughColInfo[6];
};

#endif // ST11ENERGYCYLINDER_HPP
