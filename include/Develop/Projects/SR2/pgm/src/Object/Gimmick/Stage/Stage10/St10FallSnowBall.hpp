#ifndef ST10FALLSNOWBALL_HPP
#define ST10FALLSNOWBALL_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsSe3DControl;

enum enmFallSnowBallMode {
    MODE_START_WAIT = 0,
    MODE_STOP = 1,
    MODE_MOVE = 2,
    MODE_GRAVITY = 3,
};

// total size: 0x140
class clsFallSnowBall_Obj : public clsRigidBodyGimmickObj {
public:
    clsFallSnowBall_Obj();

    virtual ~clsFallSnowBall_Obj() {}
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST10_FALL_SNOWBALL_20020; }
    virtual void init() {}
    virtual void reset();
    virtual void main();
    virtual void requestDrawContactEffect(const hkContactPoint* pcContact);
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent();
    virtual void contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject);
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& cEvent);

    void draw(clsModelType_OB_TX& rcModel,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);
    void drawShadow(clsModelType_OB& model);
    void CheckCount();

    enmFallSnowBallMode m_eFallSnowBallMode; // offset 0xD0, size 0x4
    f32 m_f32Frame;                          // offset 0xD4, size 0x4
    s32 m_s32ContactCount;                   // offset 0xD8, size 0x4
    f32 m_f32Scale;                          // offset 0xDC, size 0x4
    f32 m_f32StartWaitFrame;                 // offset 0xE0, size 0x4
    f32 m_f32TotalFrame;                     // offset 0xE4, size 0x4
    u8 bHitFlag;                             // offset 0xE8, size 0x1
    clsSe3DControl* m_pcSe3DControl;         // offset 0xEC, size 0x4
    u8 bDrawFlag;                            // offset 0xF0, size 0x1
    f32 m_sShadowMtx[4][4];                  // offset 0x100, size 0x40
};

// total size: 0x9C
class clsFallSnowBall_Task : public clsSingleModelGimmick_Task<clsFallSnowBall_Task,
                                                               clsFallSnowBall_Obj,
                                                               clsModelType_OB_TX> {
public:
    clsFallSnowBall_Task(u32 u32ObjectAreaNum);
    virtual ~clsFallSnowBall_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();

    void setShadowModel(const u8* rsBinInfoI);

    clsModelType_OB m_cModel; // offset 0x94, size 0x4
    u8 m_bFlag;               // offset 0x98, size 0x1
};

#endif // ST10FALLSNOWBALL_HPP
