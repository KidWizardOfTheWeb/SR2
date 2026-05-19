#ifndef ST07SOLAR_HPP
#define ST07SOLAR_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PathGravityObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

// total size: 0x2A0
class clsSolar_Obj : public clsPathGravityObj_Obj {
public:
    clsSe3DControl* m_pcSe3DControl;         // offset 0x220, size 0x4
    f32 m_sDrawMtx[4][4];                    // offset 0x230, size 0x40
    clsBackLineEffectTask* m_apcLineTask[2]; // offset 0x270, size 0x8
    u8 m_u8ContactSeCount;                   // offset 0x278, size 0x1
    u8 m_u8ModelNo;                          // offset 0x279, size 0x1
    f32 m_f32MatMotionFrame;                 // offset 0x27C, size 0x4
    f32 m_f32MotionFrame;                    // offset 0x280, size 0x4
    NNS_VECTORFAST m_sPosVec;                // offset 0x290, size 0x10

    static f32 t_of32CLIP_DISTx2;

    clsSolar_Obj();
    virtual ~clsSolar_Obj() {}
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST07_SOLAR_17080; }
    virtual void reset();
    virtual void init();
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rParam1);
    virtual void adminSe();

    void draw(clsModelType_OB_TX_MO_MA& rParam1,
              f32 (*psMtxPal)[4][4],
              u32* pParam3,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4]);
};

// total size: 0x98
class clsSolar_Task
    : public clsSingleModelGimmick_Task<clsSolar_Task, clsSolar_Obj, clsModelType_OB_TX_MO_MA> {
public:
    clsSolar_Task(u32 u32ObjectAreaNum);
    virtual ~clsSolar_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST07SOLAR_HPP
