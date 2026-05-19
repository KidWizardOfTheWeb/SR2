#ifndef ST10SNOWBALL_HPP
#define ST10SNOWBALL_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsSe3DControl;
struct hkContactPointConfirmedEvent;

enum enmSnowBallMode {
    MODE_STOP = 0,
    MODE_MOVE = 1,
    MODE_GRAVITY = 2,
};

// total size: 0x130
class clsSnowBall_Obj : public clsRigidBodyGimmickObj {
public:
    virtual ~clsSnowBall_Obj() {}
    virtual nspPackId::enm getPackId() const
    {
        return nspPackId::ST10_SNOWBALL_20010;
    } // likely: return 20010; [ASM-derived guess — verify]
    virtual void init();
    virtual void contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject);
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();
    virtual void requestDrawContactEffect(const hkContactPoint* pcContact);
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent();
    virtual void callbackBreakEvent();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& cEvent);

    void draw(clsModelType_OB_TX& rcModel,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);
    void drawShadow(clsModelType_OB& rcModel);

    clsSnowBall_Obj();

    enum enmSnowBallMode m_eSnowBallMode; // offset 0xD0, size 0x4
    f32 m_f32Frame;                       // offset 0xD4, size 0x4
    s32 m_s32ContactCount;                // offset 0xD8, size 0x4
    f32 m_f32Scale;                       // offset 0xDC, size 0x4
    clsSe3DControl* m_pcSe3DControl;      // offset 0xE0, size 0x4
    u8 m_bDrawFlag;                       // offset 0xE4, size 0x1
    f32 m_sShadowMtx[4][4];               // offset 0xF0, size 0x40
};

// total size: 0x9C
class clsSnowBall_Task
    : public clsSingleModelGimmick_Task<clsSnowBall_Task, clsSnowBall_Obj, clsModelType_OB_TX> {
public:
    clsSnowBall_Task(u32 u32ObjectAreaNum);
    virtual ~clsSnowBall_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();

    void setShadowModel(const u8* rsBinInfoI);

    clsModelType_OB m_cModel; // offset 0x94, size 0x4
    u8 m_bFlag;               // offset 0x98, size 0x1
};

#endif // ST10SNOWBALL_HPP
