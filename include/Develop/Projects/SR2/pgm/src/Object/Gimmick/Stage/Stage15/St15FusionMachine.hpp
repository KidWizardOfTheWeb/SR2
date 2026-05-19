#ifndef ST15FUSIONMACHINE_HPP
#define ST15FUSIONMACHINE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"

class clsBossGravityWave_Task;
class clsSe3DControl;

// total size: 0x30
class clsFusionMachineModels {
public:
    clsFusionMachineModels() {}
    ~clsFusionMachineModels() {}

    clsModelType_OB_TX m_cModel; // offset 0x0, size 0x8
    NNS_MOTION* m_apsMotion[10]; // offset 0x8, size 0x28
};

class clsFusionMachine_Obj;

// total size: 0xD0
class clsFusionMachine_Task : public clsSingleModelGimmick_Task<clsFusionMachine_Task,
                                                                clsFusionMachine_Obj,
                                                                clsFusionMachineModels> {
public:
    clsFusionMachine_Task(u32 packId);
    virtual ~clsFusionMachine_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& param_1);

    u8 m_bDebugReturnStartRateDisp; // offset 0xBC, size 0x1
    u8 m_bDebugReturnEndRateDisp;   // offset 0xBD, size 0x1
    s32 m_s32DebugAttackType;       // offset 0xC0, size 0x4
    u8 m_bDebugAttackRateDisp;      // offset 0xC4, size 0x1
    u8 m_bDebugPosDisp;             // offset 0xC5, size 0x1
    u8 m_bDebugDistanceDisp;        // offset 0xC6, size 0x1
    u8 m_bDebugLengthRateDisp;      // offset 0xC7, size 0x1
    u8 m_bDebugHPDisp;              // offset 0xC8, size 0x1
    u8 m_bDebugBossStop;            // offset 0xC9, size 0x1
    u8 m_bDebugAttackEnable;        // offset 0xCA, size 0x1
    f32 m_f32Count;                 // offset 0xCC, size 0x4
};

// total size: 0x440
class clsFusionMachine_Obj : public clsPhantomGimmickObject {
public:
    enum enmFusionMachineMode {
        MODE_INIT = 0,
        MODE_EMERGENCE = 1,
        MODE_ROAR = 2,
        MODE_MOVE_PATH = 3,
        MODE_MOVE_TO_BASE = 4,
        MODE_GDIVE_START_WAIT = 5,
        MODE_SOUND_WAIT = 6,
        MODE_WAIT = 7,
        MODE_VANISH = 8,
        MODE_EMERGENCE_WAIT = 9,
        MODE_DAMAGE = 10,
        MODE_DEAD = 11,
        MODE_DEAD_EXPLODE_OUT = 12,
        MODE_DEAD_EXPLODE_IN = 13,
        MODE_END = 14,
        MODE_VANISH_END_START = 15,
        MODE_VANISH_END_WAIT = 16,
        MODE_VANISH_EMERGENCE_WAIT = 17,
    };

    enum enmAttackState {
        ATTACK_STATE_NONE = 0,
        ATTACK_STATE_ATTACK_1 = 1,
        ATTACK_STATE_ATTACK_2 = 2,
        ATTACK_STATE_NONE_CHECK = 3,
        ATTACK_STATE_MAX = 4,
    };

    enum enmReturnCheckState {
        RETRUN_CHECK_1 = 0,
        RETRUN_CHECK_2 = 1,
        RETURN_CHECK_MAX = 2,
    };

    enum enmEffectCheckState {
        EFFECT_VANISH_START_CHECK = 0,
        EFFECT_VANISH_TIMING_CHECK = 1,
        EFFECT_VANISH_END_WAIT = 2,
        EFFECT_EMERGENCE_CHECK = 3,
        EFFECT_EMERGENCE_TIMING_CHECK = 4,
        EFFECT_EMERGENCE_END_WAIT = 5,
        EFFECT_CHECK_WAIT = 6,
        EFFECT_CHECK_MAX = 7,
    };

    enum enmAttackMode {
        ATTACK_WAIT = 0,
        ATTACK_POSE = 1,
        ATTACK_CHARGE = 2,
        ATTACK_SHOOT = 3,
        ATTACK_INIT_2 = 0,
        ATTACK_WAIT_2 = 1,
        ATTACK_POSE_2 = 2,
        ATTACK_CHARGE_2 = 3,
        ATTACK_SHOOT_2 = 4,
    };

    clsFusionMachine_Obj();
    virtual ~clsFusionMachine_Obj() {}
    virtual void contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject);
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const
    {
        return nspPackId::ST15_FUSION_MACHINE_25010;
    } // likely

    void checkDistortionField();
    void debugDead();
    void init();
    void reset();
    s32 getFirstPlayerNo();
    void damage();
    void setLineParam();

    NNS_VECTORFAST* getOffsetVecFastPtr() { return &m_sOffsetVecFast; }
    f32 getMotionFrame() const { return m_f32MotionFrame; }
    s32 getMotionNo() const { return m_s32MotionNo; }
    enmFusionMachineMode getMode() const { return m_eFusionMachineMode; }
    void upDateLightData() {}
    void stopLoopParticle(u8 u8Param1) {}
    void moveDamageAction() {}
    void setAttackState(enmAttackState param_1) { m_eAttackState = param_1; }
    void checkBGMChange() {}
    void endBlackHoleTime() {}
    void checkAutoGDiveStart() {}
    void checkReturn() {}
    void setPhotonEffectPos() {}
    void actionAttack2() {}
    void actionAttack1() {}
    void stopGravityWave() {}
    u8 updateMotion() { return 0; }
    void checkAttack() {}
    enmAttackState getAttackState() const { return m_eAttackState; }
    void checkReturnStart() {}
    void updatePathMove() {}
    void updateSpeedNormal() {}
    void initPathMove() {}
    void setPhotonEffect() {}
    void setMotionNo(s32 s32Param1) {}
    void setMode(enmFusionMachineMode param_1) { m_eFusionMachineMode = param_1; }
    s32 getHP() const { return m_s32HP; }
    u8 updateCount() { return 0; }
    u32 getMainGroup() const { return m_u32MainGroup; }

    u8 m_bEnableDebug;                            // offset 0x60, size 0x1
    s32 m_s32DebugReturnRateNum;                  // offset 0x64, size 0x4
    f32 m_af32DebugReturnStartRate[2];            // offset 0x68, size 0x8
    f32 m_af32DebugReturnEndRate[2];              // offset 0x70, size 0x8
    s32 m_s32DebugAttackType;                     // offset 0x78, size 0x4
    s32 m_s32DebugAttackRateNum;                  // offset 0x7C, size 0x4
    f32 m_af32DebugAttackRate[2][4];              // offset 0x80, size 0x20
    f32 m_af32DebugBossDistance[4];               // offset 0xA0, size 0x10
    f32 m_f32DebugUpDownRange;                    // offset 0xB0, size 0x4
    f32 m_f32DebugUpDownRate;                     // offset 0xB4, size 0x4
    f32 m_f32DebugOffsetY;                        // offset 0xB8, size 0x4
    f32 m_f32DebugAddSpeed;                       // offset 0xBC, size 0x4
    f32 m_f32DebugLimitSpeed;                     // offset 0xC0, size 0x4
    f32 m_f32DebugDefaultSpeed;                   // offset 0xC4, size 0x4
    f32 m_f32DebugReturnSpeed;                    // offset 0xC8, size 0x4
    f32 m_f32DebugStartDistance;                  // offset 0xCC, size 0x4
    f32 m_f32DebugReturnDistance;                 // offset 0xD0, size 0x4
    f32 m_f32DebugBulletChargeFrame;              // offset 0xD4, size 0x4
    f32 m_f32DebugMeteoChargeFrame;               // offset 0xD8, size 0x4
    f32 m_f32DebugBlackHoleTime;                  // offset 0xDC, size 0x4
    f32 m_f32DebugDamageBurstSpeed;               // offset 0xE0, size 0x4
    s32 m_s32DebugMotionNo;                       // offset 0xE4, size 0x4
    f32 m_f32DebugEffectFrame;                    // offset 0xE8, size 0x4
    f32 m_f32DebugEffectVal;                      // offset 0xEC, size 0x4
    enmFusionMachineMode m_eFusionMachineMode;    // offset 0xF0, size 0x4
    enmReturnCheckState m_eReturnCheckState;      // offset 0xF4, size 0x4
    enmAttackState m_eAttackState;                // offset 0xF8, size 0x4
    enmEffectCheckState m_eEffectCheckState;      // offset 0xFC, size 0x4
    enmAttackMode m_eAttackMode;                  // offset 0x100, size 0x4
    clsOOVector m_vecLapMark;                     // offset 0x104, size 0x10
    clsPosturalCtrl m_cPostural;                  // offset 0x120, size 0xB0
    clsPath m_cPath;                              // offset 0x1D0, size 0x60
    f32 m_sProjMtx44[4][4];                       // offset 0x230, size 0x40
    clsBossGravityWave_Task* m_pcBossGravityWave; // offset 0x270, size 0x4
    clsSe3DControl* m_pcSe3DControl;              // offset 0x274, size 0x4
    NNS_VECTORFAST m_sDirVecFast;                 // offset 0x280, size 0x10
    NNS_VECTORFAST m_sOffsetVecFast;              // offset 0x290, size 0x10
    NNS_VECTORFAST m_asParallelDir[2];            // offset 0x2A0, size 0x20
    NNS_VECTORFAST m_asParallelPos[2];            // offset 0x2C0, size 0x20
    NNS_VECTORFAST m_asSpecularDir[2];            // offset 0x2E0, size 0x20
    f32* m_opf32ReturnCheckTable;                 // offset 0x300, size 0x4
    f32* m_opf32AttackCheckTable;                 // offset 0x304, size 0x4
    f32 m_f32BaseCount;                           // offset 0x308, size 0x4
    f32 m_f32Count;                               // offset 0x30C, size 0x4
    f32 m_f32Speed;                               // offset 0x310, size 0x4
    f32 m_f32MotionFrame;                         // offset 0x314, size 0x4
    f32 m_f32MotionEndFrame;                      // offset 0x318, size 0x4
    f32 m_f32MoveOffsetLR;                        // offset 0x31C, size 0x4
    f32 m_f32MoveOffsetSpeed;                     // offset 0x320, size 0x4
    f32 m_f32MoveOffsetCount;                     // offset 0x324, size 0x4
    f32 m_af32PlayerFlyCount[8];                  // offset 0x328, size 0x20
    s32 m_s32SeId1;                               // offset 0x348, size 0x4
    s32 m_s32SeId2;                               // offset 0x34C, size 0x4
    s32 m_s32HP;                                  // offset 0x350, size 0x4
    s32 m_s32TotalMaxLap;                         // offset 0x354, size 0x4
    s32 m_s32AttackCount;                         // offset 0x358, size 0x4
    s32 m_s32AttackOrder;                         // offset 0x35C, size 0x4
    s32 m_s32MotionNo;                            // offset 0x360, size 0x4
    u8 m_bEffectFlag;                             // offset 0x364, size 0x1
    u8 m_bDrawFlag;                               // offset 0x365, size 0x1
    u8 m_bMotionChangeFlag;                       // offset 0x366, size 0x1
    u8 m_bEmergenceFlag;                          // offset 0x367, size 0x1
    u32 m_u32TopPlayerNo;                         // offset 0x368, size 0x4
    u32 m_u32MainGroup;                           // offset 0x36C, size 0x4
    u32 m_u32AutoGDiveCheck;                      // offset 0x370, size 0x4
    u32 m_u32LightNo;                             // offset 0x374, size 0x4
    s8 m_s8AttackCheckStep;                       // offset 0x378, size 0x1
    s8 m_s8AttackCheckMax;                        // offset 0x379, size 0x1
    s8 m_s8DamagePoint;                           // offset 0x37A, size 0x1
    u8 m_u8PathNo;                                // offset 0x37B, size 0x1
    NNS_VECTORFAST m_sEffectFollowPos;            // offset 0x380, size 0x10
    NNS_VECTORFAST m_sEffectFollowPos2;           // offset 0x390, size 0x10
    f32 m_sEffectMtx[4][4];                       // offset 0x3A0, size 0x40
    clsTask* m_apcLoopParticle[3];                // offset 0x3E0, size 0xC
    f32 m_sLineDrawMtx[4][4];                     // offset 0x3F0, size 0x40
    clsBackLineEffectTask* m_apcLineTask[2];      // offset 0x430, size 0x8
};

#endif // ST15FUSIONMACHINE_HPP
