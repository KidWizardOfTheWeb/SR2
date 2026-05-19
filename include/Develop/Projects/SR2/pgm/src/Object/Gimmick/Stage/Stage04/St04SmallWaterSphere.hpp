#ifndef ST04SMALLWATERSPHERE_HPP
#define ST04SMALLWATERSPHERE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsPlayerTask;
class clsSe3DControl;
class clsGravityGimmickParam;
class hkShape;

// total size: 0xF0
class clsSmallWaterSphere_Object : public clsRigidBodyGimmickObj {
public:
    clsSmallWaterSphere_Object();
    virtual ~clsSmallWaterSphere_Object() {}

    enum enmMode {
        MODE_INIT = 0,
        MODE_WAIT = 1,
        MODE_RISE = 2,
        MODE_FLOAT = 3,
        MODE_MOVE_INIT = 4,
        MODE_MOVE = 5,
        MODE_END = 6,
    };

    static NNS_VECTOR tosCollisionHalfSizeVec;
    static f32 tof32ClipSqDist;
    static clsGravityGimmickParam t_ocGravityGimmickParam;

    NNS_OBJECT* m_psMorphObject;     // offset 0xD0, size 0x4
    enmMode m_eMode;                 // offset 0xD4, size 0x4
    f32 m_f32MatFrame;               // offset 0xD8, size 0x4
    f32 m_f32MorphFrame;             // offset 0xDC, size 0x4
    f32 m_f32Scale;                  // offset 0xE0, size 0x4
    f32 m_f32MaxScale;               // offset 0xE4, size 0x4
    f32 m_f32EffectFrame;            // offset 0xE8, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xEC, size 0x4

    virtual void reset();
    virtual void main();
    virtual void mainGravity();
    virtual void mainCrash();
    virtual void requestDrawBreakEffect();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void draw(clsModelType_OB_TX_MO_MA& rcModel,
                      f32 (*psMtxPal)[4][4],
                      u32* psNodeStat,
                      const f32 (*opaNnViewMtx)[4][4],
                      f32 (*psMtxWork)[4][4],
                      u32 u32Seed,
                      u32 u32ViewNo);
    virtual void playSe(clsPlayerTask* pParam1);
    virtual void drawEffect(clsPlayerTask* pParam1);
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rParam1);
    virtual void callbackCrashEvent();
    virtual NNS_VECTOR* getCollisionHalfSizeVecPtr() const;
    virtual nspPackId::enm getPackId() const;
};

// total size: 0xB0
class clsSmallWaterSphere_Task : public clsSingleModelGimmick_Task<clsSmallWaterSphere_Task,
                                                                   clsSmallWaterSphere_Object,
                                                                   clsModelType_OB_TX_MO_MA> {
public:
    clsSmallWaterSphere_Task(u32 u32ObjectAreaNum);
    virtual ~clsSmallWaterSphere_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    hkShape* m_pcPartsShape; // offset 0xAC, size 0x4
};

#endif // ST04SMALLWATERSPHERE_HPP
