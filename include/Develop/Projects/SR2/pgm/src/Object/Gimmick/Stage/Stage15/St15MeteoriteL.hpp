#ifndef ST15METEORITEL_HPP
#define ST15METEORITEL_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBox.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

enum enmMeteoriteLMode {
    MODE_INIT = 0,
    MODE_WAIT = 1,
    MODE_STANDBY = 2,
    MODE_MOVE = 3,
    MODE_SHOOT_WAIT = 4,
    MODE_SHOOT = 5,
};

// total size: 0x180
class clsMeteoriteL_Obj : public clsRigidBodyGimmickObj {
public:
    clsMeteoriteL_Obj() {}
    virtual ~clsMeteoriteL_Obj() {}
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST15_METEORITE_L_25030; }
    virtual void reset() {}
    virtual void main() {}
    virtual void requestDrawContactEffect(const hkContactPoint* pcContact);
    virtual void requestDrawBreakEffect();

    enmMeteoriteLMode getMode() const { return m_eMeteoriteLMode; }
    void timelagAttackMeteoriteL();
    void attackMeteoriteL();

    clsSe3DControl* m_pcSe3DControl;     // offset 0xD0, size 0x4
    f32 m_f32Count;                      // offset 0xD4, size 0x4
    s32 m_s32AttackNum;                  // offset 0xD8, size 0x4
    NNS_VECTORFAST m_sDirVecFast;        // offset 0xE0, size 0x10
    enmMeteoriteLMode m_eMeteoriteLMode; // offset 0xF0, size 0x4
    f32 m_f32Speed;                      // offset 0xF4, size 0x4
    s32 m_s32ObjNo;                      // offset 0xF8, size 0x4
    u8 m_bDrawFlag;                      // offset 0xFC, size 0x1
    f32 m_sEffectMtx[4][4];              // offset 0x100, size 0x40
    NNS_VECTORFAST m_sEffectBombPos;     // offset 0x140, size 0x10
    NNS_VECTORFAST m_sEffectBombUpVec;   // offset 0x150, size 0x10
    NNS_QUATERNION m_sEffectQuat;        // offset 0x160, size 0x10
    clsTask* m_psEffectTask;             // offset 0x170, size 0x4
};

// total size: 0xB8
class clsMeteoriteL_Task
    : public clsSingleModelGimmick_Task<clsMeteoriteL_Task, clsMeteoriteL_Obj, clsModelType_OB_TX>,
      public clsGimmickCommon {
public:
    clsMeteoriteL_Task(u32 u32ObjectAreaNum);
    virtual ~clsMeteoriteL_Task() {}

    hkShape* m_pcShape;             // offset 0x60, size 0x4
    clsMeteoriteL_Obj* m_pcObjects; // offset 0x64, size 0x4
    stcSetDataDetail* m_psSetData;  // offset 0x68, size 0x4
    u32 m_u32ObjNum;                // offset 0x6C, size 0x4
    // Note: inherited/base layout accounts for 0x70–0x94
    u8 m_bDebugTargetPosDisp;       // offset 0x95, size 0x1
    s32 m_s32DebugDispZoneNo;       // offset 0x98, size 0x4
    f32 m_f32DebugOffsetY;          // offset 0x9C, size 0x4
    f32 m_f32DebugFallTime;         // offset 0xA0, size 0x4
    f32 m_f32DebugQuakeDistance;    // offset 0xA4, size 0x4
    f32 m_f32DebugQuakeFrame;       // offset 0xA8, size 0x4
    f32 m_f32DebugQuakeRumbleFrame; // offset 0xAC, size 0x4
    u8 m_bInitFlag;                 // offset 0xB0, size 0x1
    s32 m_s32SeId;                  // offset 0xB4, size 0x4

    virtual void setMeteoriteL(s32 s32Param1);
    virtual void reset();
    virtual void draw();
    virtual void execute();
};

#endif // ST15METEORITEL_HPP
