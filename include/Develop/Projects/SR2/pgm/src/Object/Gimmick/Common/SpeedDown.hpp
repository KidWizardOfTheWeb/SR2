#ifndef SPEEDDOWN_HPP
#define SPEEDDOWN_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGimmick.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/MagBarrier.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/hkArray.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsPlayerTask;
class clsMultiObTxModels;
class clsGimmickRigidBody;
class hkBallSocketChainData;
class hkConstraintChainInstance;
class hkContactImpulseLimitBreachedListener;

struct stcChainBallData {
    NNS_VECTORFAST sPosVecFast;   // offset 0x0, size 0x10
    NNS_QUATERNION sRotQuat;      // offset 0x10, size 0x10
    NNS_VECTORFAST sSpeedVecFast; // offset 0x20, size 0x10
};

class clsSpeedDown_Obj : public clsGimmickObj {
public:
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
        MODE_MAIN_COM = 2,
        MODE_DEAD = 3,
    };

    clsSpeedDown_Obj() {}
    virtual ~clsSpeedDown_Obj() {}

    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::SPEED_DOWN_2240; }

    void createChain();
    void
    setLimit(clsGimmickRigidBody* pcRigidBodyA, clsGimmickRigidBody* pcRigidBodyB, f32 f32MaxAngle);
    void execute();
    void draw(clsMultiObTxModels& rcObj,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);

    enmMode m_eMode;                                                  // offset 0x50, size 0x4
    clsPlayerTask* m_pcPlayer;                                        // offset 0x54, size 0x4
    clsFrameControl m_cFrameControl;                                  // offset 0x58, size 0x8
    stcChainBallData m_asChainBallData[11];                           // offset 0x60, size 0x210
    NNS_VECTORFAST* m_psOffsetPosVecFast;                             // offset 0x270, size 0x4
    u32 m_u32NodeNo;                                                  // offset 0x274, size 0x4
    f32 m_f32BehaviorCnt;                                             // offset 0x278, size 0x4
    f32 m_f32MaxSpeed;                                                // offset 0x27C, size 0x4
    hkArray<hkContactImpulseLimitBreachedListener*> m_vctpcRigidBody; // offset 0x280, size 0xC
    hkConstraintChainInstance* m_pcChainInstance;                     // offset 0x28C, size 0x4
    hkBallSocketChainData* m_pcChainData;                             // offset 0x290, size 0x4
};

class clsSpeedDown_Task
    : public clsMultiModelGimmick_Task<clsSpeedDown_Task, clsSpeedDown_Obj, clsMultiObTxModels> {
public:
    clsSpeedDown_Task(const stcSetDataDetail& rParam);
    virtual ~clsSpeedDown_Task();

    virtual void execute();
    virtual void draw();
    virtual void reset();

    clsOODeque m_tddqUseObj;   // offset 0x98, size 0x20
    clsOODeque m_tddqUnUseObj; // offset 0xB8, size 0x20

    void regist(clsPlayerTask* pcPlayer, f32 f32Param);
    virtual void setSetData(const stcSetDataDetail& rParam);
};

#endif // SPEEDDOWN_HPP
