#ifndef ST15ENERGYBULLET_HPP
#define ST15ENERGYBULLET_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Path.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBox.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Postural.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// Forward declarations
class clsSe3DControl;

enum enmParamChangeStep {
    STEP_CHECK_CHANGE = 0,
    STEP_CHANGE_PARAM = 1,
    STEP_CHANGED = 2,
};

enum enmEnergyBulletMode {
    MODE_INIT = 0,
    MODE_WAIT = 1,
    MODE_PATH_MOVE_LR_CHECK = 2,
    MODE_PATH_MOVE_LR = 3,
    MODE_PATH_MOVE = 4,
};

// total size: 0x240
class clsEnergyBullet_Obj : public clsRigidBodyGimmickObj {
public:
    clsEnergyBullet_Obj() {}
    virtual ~clsEnergyBullet_Obj() {}
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const
    {
        return nspPackId::ST15_ENERGY_BULLET_25020;
    } // likely: return 25020;  [ASM-derived guess — verify]
    virtual void reset();
    virtual void main();
    virtual void requestDrawBreakEffect();

    enmEnergyBulletMode getMode() const
    {
        return m_eEnergyBulletMode;
    } // likely: return m_eEnergyBulletMode;  [ASM-derived guess — verify]

    void updatePathMove();
    void calcPathMoveLR(f32 of32Distance);
    void initPathMove(const NNS_VECTORFAST* opsBaseVecFast, f32 of32DistanceLR, f32 of32OffsetY);

    clsSe3DControl* m_pcSe3DControl;         // offset 0xD0, size 0x4
    clsPath m_cPath;                         // offset 0xE0, size 0x60
    clsPosturalCtrl m_cPostural;             // offset 0x140, size 0xB0
    NNS_VECTORFAST m_sOldVelocityVecFast;    // offset 0x1F0, size 0x10
    f32 m_f32LRMoveFrame;                    // offset 0x200, size 0x4
    f32 m_f32NextPointFrame;                 // offset 0x204, size 0x4
    f32 m_f32OffsetX;                        // offset 0x208, size 0x4
    f32 m_f32OffsetY;                        // offset 0x20C, size 0x4
    f32 m_f32DefaultOffsetX;                 // offset 0x210, size 0x4
    f32 m_f32DefaultOffsetY;                 // offset 0x214, size 0x4
    u8 m_bRotChange;                         // offset 0x218, size 0x1
    enmParamChangeStep m_enmScaleChangeStep; // offset 0x21C, size 0x4
    enmParamChangeStep m_enmSpeedChangeStep; // offset 0x220, size 0x4
    enmEnergyBulletMode m_eEnergyBulletMode; // offset 0x224, size 0x4
    f32 m_f32MotionFrame;                    // offset 0x228, size 0x4
    f32 m_f32MatMotionFrame;                 // offset 0x22C, size 0x4
    f32 m_f32Scale;                          // offset 0x230, size 0x4
    f32 m_f32Speed;                          // offset 0x234, size 0x4
};

// total size: 0xD4
class clsEnergyBullet_Task : public clsSingleModelGimmick_Task<clsEnergyBullet_Task,
                                                               clsEnergyBullet_Obj,
                                                               clsModelType_OB_TX_MO_MA>,
                             public clsGimmickCommon {
public:
    clsEnergyBullet_Task(u32 u32ObjectAreaNum);
    virtual ~clsEnergyBullet_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();

    void setEnergyBullet(const NNS_VECTORFAST* opsBaseVecFast, f32 of32DistanceLR, f32 of32OffsetY);

    f32 m_f32DebugDefaultBulletSpeed; // offset 0xB0, size 0x4
    f32 m_f32DebugLightR;             // offset 0xB4, size 0x4
    f32 m_f32DebugLightG;             // offset 0xB8, size 0x4
    f32 m_f32DebugLightB;             // offset 0xBC, size 0x4
    f32 m_f32DebugLightA;             // offset 0xC0, size 0x4
    f32 m_f32DebugLightInten;         // offset 0xC4, size 0x4
    f32 m_f32DebugLightFallOffStart;  // offset 0xC8, size 0x4
    f32 m_f32DebugLightFallOffEnd;    // offset 0xCC, size 0x4
    u8 m_bInitFlag;                   // offset 0xD0, size 0x1
};

#endif // ST15ENERGYBULLET_HPP
