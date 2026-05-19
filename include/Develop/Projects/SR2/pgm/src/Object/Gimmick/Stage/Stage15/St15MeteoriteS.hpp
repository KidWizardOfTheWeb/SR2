#ifndef ST15METEORITES_HPP
#define ST15METEORITES_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBox.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

enum enmMeteoriteSMode {
    MODE_INIT = 0,
    MODE_WAIT = 1,
    MODE_ENTRY_WAIT = 2,
    MODE_STOP_MOVE = 3,
    MODE_MOVE = 4,
    MODE_SHOOT_WAIT = 5,
    MODE_SHOOT = 6,
};

// total size: 0x1B0
class clsMeteoriteS_Obj : public clsRigidBodyGimmickObj {
public:
    clsMeteoriteS_Obj() {}
    virtual ~clsMeteoriteS_Obj() {}
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST15_METEORITE_S_25040; }
    virtual void reset() {}
    virtual void main() {}
    virtual void requestDrawContactEffect(const hkContactPoint* pcContact);
    virtual void requestDrawBreakEffect();

    enmMeteoriteSMode getMode() const { return m_eMeteoriteSMode; }
    void startDrawMeteoriteS(u32 ou32No);
    void attackMeteoriteS();

    clsSe3DControl* m_pcSe3DControl;     // offset 0xD0, size 0x4
    NNS_VECTORFAST m_sOffsetVecFast;     // offset 0xE0, size 0x10
    enmMeteoriteSMode m_eMeteoriteSMode; // offset 0xF0, size 0x4
    f32 m_f32OffsetScale;                // offset 0xF4, size 0x4
    f32 m_f32UpdateRate;                 // offset 0xF8, size 0x4
    f32 m_f32TimeLagCount;               // offset 0xFC, size 0x4
    f32 m_f32EntryLagCount;              // offset 0x100, size 0x4
    f32 m_f32StopMoveCount;              // offset 0x104, size 0x4
    f32 m_f32EffectFrame;                // offset 0x108, size 0x4
    f32 m_f32RotDeg;                     // offset 0x10C, size 0x4
    f32 m_f32RotAddDeg;                  // offset 0x110, size 0x4
    u32 m_u32ParentObjNo;                // offset 0x114, size 0x4
    f32 m_sOrbitMtx[4][4];               // offset 0x120, size 0x40
    f32 m_sEffectMtx[4][4];              // offset 0x160, size 0x40
    clsTask* m_psEffectTask;             // offset 0x1A0, size 0x4
};

// total size: 0xA0
class clsMeteoriteS_Task
    : public clsSingleModelGimmick_Task<clsMeteoriteS_Task, clsMeteoriteS_Obj, clsModelType_OB_TX>,
      public clsGimmickCommon {
public:
    clsMeteoriteS_Task(u32 u32ObjectAreaNum);
    virtual ~clsMeteoriteS_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();

    void setMeteoriteS(u32 ou32Type, u32 ou32ObjNo);

    f32 m_f32MeteoSAttackHeight; // offset 0x98, size 0x4
    u8 m_bInitFlag;              // offset 0x9C, size 0x1
};

#endif // ST15METEORITES_HPP
