#ifndef SURVIVALBALL_HPP
#define SURVIVALBALL_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBall/SurvivalBallEffect.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"

class clsGravitySurvivalBallControl;
class clsSe3DControl;
class hkShape;
class clsBallHolder2D_Task;

enum enmSurvivalBallBallMode {
    MOVE_MODE_INIT = 0,
    MOVE_MODE_ADVENT = 1,
    MOVE_MODE_MAIN = 2,
    MOVE_MODE_DEAD = 3,
};

// total size: 0x3C
class _strGyroData {
public:
    NNS_VECTOR sView[4]; // offset 0x0, size 0x30
    NNS_VECTOR sScale;   // offset 0x30, size 0xC
};

// total size: 0xF0
class clsSurvivalBallBallModels {
public:
    clsSurvivalBallBallModels() {}
    ~clsSurvivalBallBallModels() {}

    clsModelType_OB_TX_MO_MA m_cModelBall;   // offset 0x0, size 0x20
    clsModelType_OB_TX_MO_MA m_cModelRange;  // offset 0x20, size 0x20
    clsModelType_OB_TX_MO m_cModelLookOn;    // offset 0x40, size 0x10
    clsModelType_OB_TX_MO_MA m_cModelGyroG;  // offset 0x50, size 0x20
    clsModelType_OB_TX_MO_MA m_cModelGyroR;  // offset 0x70, size 0x20
    clsModelType_OB_TX_MO_MA m_cModelEffect; // offset 0x90, size 0x20
    clsModelType_OB_TX_MO_MA m_cModelBlink;  // offset 0xB0, size 0x20
    clsModelType_OB_TX_MO_MA m_cModelBomb;   // offset 0xD0, size 0x20
};

// total size: 0x8
class clsSurvivalBallBallSetData {
public:
    stcSetDataDetail* m_psSetDataDetail; // offset 0x0, size 0x4
    s32 m_s32SetDataNo;                  // offset 0x4, size 0x4
};

// forward-declared before clsSurvivalBallBallCollision since it's a back-pointer member
class clsSurvivalBallBall_Obj;

// total size: 0x10
class clsSurvivalBallBallCollision : public clsBaseThroughCollision {
public:
    virtual ~clsSurvivalBallBallCollision() {}

    void execute();

    u8 m_u8HitFlag; // offset 0x8, size 0x1
    // gap 0x9–0xB (alignment padding)
    clsSurvivalBallBall_Obj* m_pcSurvivalBallBall_Obj; // offset 0xC, size 0x4
};

// total size: 0x190
class clsSurvivalBallBall_Obj : public clsRigidBodyGimmickObj {
public:
    static _strGyroData gsGyroData[4];
    static clsGravityGimmickParam* t_pocGravityGimmickParam[3];
    static clsGravityGimmickParam t_ocGravityGimmickParamSt01;
    static clsGravityGimmickParam t_ocGravityGimmickParamSt02;
    static clsGravityGimmickParam t_ocGravityGimmickParamSt03;

    clsSurvivalBallBall_Obj();

    virtual ~clsSurvivalBallBall_Obj() {}
    virtual void contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2);
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::SURVIVALBALL_BALL_28010; }
    virtual void reset();
    virtual void init() {}
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void contactInterraction(clsRigidBodyGimmickObj* pParam1);
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rParam1);
    virtual void execute();

    void drawGyro(clsModelType_OB_TX_MO_MA& rParam1, clsModelType_OB_TX_MO_MA& rParam2);
    void drawBall(clsModelType_OB_TX_MO_MA& rParam1, f32 (*)[4][4]);
    void draw(clsSurvivalBallBallModels& rParam1);
    void searchPointRing();

    hkShape* m_pcShape;                               // offset 0xD0, size 0x4
    clsTask* m_psParticle;                            // offset 0xD4, size 0x4
    clsSurvivalBallBallEffect_Task* m_psLookOnEffect; // offset 0xD8, size 0x4
    clsSurvivalBallBallEffect_Task* m_psBomeEffect;   // offset 0xDC, size 0x4
    NNS_VECTORFAST m_sDrawBreakPosVec;                // offset 0xE0, size 0x10
    f32 m_f32Scale;                                   // offset 0xF0, size 0x4
    u8 m_bCheckBallFlag;                              // offset 0xF4, size 0x1
    u8 m_bGravityEffectFlag;                          // offset 0xF5, size 0x1
    u8 m_bBallBombFlag;                               // offset 0xF6, size 0x1
    // gap 0xF7 (alignment padding)
    u32 m_u32RangeEffectFlag;                  // offset 0xF8, size 0x4
    s32 m_as32GyroCount[4];                    // offset 0xFC, size 0x10
    s32 m_s32CountDownFrame;                   // offset 0x10C, size 0x4
    s32 m_s32RebirthFrame;                     // offset 0x110, size 0x4
    u32 m_u32EffectFlag;                       // offset 0x114, size 0x4
    f32 m_f32LostOwnerCount;                   // offset 0x118, size 0x4
    f32 m_f32MatMotionAddFrame;                // offset 0x11C, size 0x4
    enmDrawType m_aeEffectDraw[5];             // offset 0x120, size 0x14
    enmDrawType m_aeOldEffectDraw[5];          // offset 0x134, size 0x14
    clsSurvivalBallBallCollision m_cCollision; // offset 0x148, size 0x10
    enmSurvivalBallBallMode m_eMoveMode;       // offset 0x158, size 0x4
    clsRetPath m_cRetCoursePath;               // offset 0x15C, size 0x20
    clsSe3DControl* m_pcSe3DControl;           // offset 0x17C, size 0x4
    u8 m_bSePlayFlg;                           // offset 0x180, size 0x1
    // gap 0x181–0x183 (alignment padding)
    f32 m_f32SeBlingFrame; // offset 0x184, size 0x4
};

// total size: 0x1A0
class clsSurvivalBallBall_Task : public clsSingleModelGimmick_Task<clsSurvivalBallBall_Task,
                                                                   clsSurvivalBallBall_Obj,
                                                                   clsSurvivalBallBallModels> {
public:
    clsSurvivalBallBall_Task(u32 u32Param1);
    virtual ~clsSurvivalBallBall_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rParam1);

    void setSetDataBall(const stcSetDataDetail& rParam1);
    void searchBallPos(const NNS_VECTORFAST* pParam1,
                       const NNS_VECTORFAST* pParam2,
                       NNS_VECTORFAST* pParam3);

    f32 m_u32MatFrame;                        // offset 0x17C, size 0x4
    clsSurvivalBallBallSetData* m_pcObjArray; // offset 0x180, size 0x4
    clsBallHolder2D_Task* m_pcBallHolder2D;   // offset 0x184, size 0x4
    vector m_vecSetDataArray;                 // offset 0x188, size 0xC
    vector m_vecUnusedSetDataArray;           // offset 0x194, size 0xC
};

#endif // SURVIVALBALL_HPP
