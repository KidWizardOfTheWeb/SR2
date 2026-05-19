#ifndef ST12PUTCANOEMOTION_HPP
#define ST12PUTCANOEMOTION_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "types.h"

#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

class clsPutCanoeMotion_Obj : public clsRigidBodyGimmickObj {
public:
    enum enmPutCarMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    clsPutCanoeMotion_Obj();
    virtual ~clsPutCanoeMotion_Obj();
    virtual void reset();
    virtual void main();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void requestDrawBreakEffect();
    virtual nspPackId::enm getPackId() const;
    virtual void callbackCrashEvent();

    static f32 tof32ClipSqDist;
    static u32 otau32Se_CanoeBreak[2];
    static u32 otau32Se_CanoeExp[2];

private:
    enum enmPutCarMode m_eMode; // offset 0xD0, size 0x4
    u32 m_u32TexIdx;            // offset 0xD4, size 0x4
    f32 m_f32MotionFrame;       // offset 0xD8, size 0x4
    f32 m_f32EndFrame;          // offset 0xDC, size 0x4
};

class clsPutCanoeMotion_Task : public clsSingleModelGimmick_Task<clsPutCanoeMotion_Task,
                                                                 clsPutCanoeMotion_Obj,
                                                                 clsModelType_OB_TX_MO> {
public:
    clsPutCanoeMotion_Task(u32 u32ObjectAreaNum);
    virtual ~clsPutCanoeMotion_Task();
    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rParam1);
    virtual void setSetData(const stcSetDataDetail& rParam1);

private:
    u16* m_TexIdx;                                                     // offset 0x9C, size 0x4
    u16* m_TexIdx2;                                                    // offset 0xA0, size 0x4
    clsGmkBurnLight_Task<clsModelType_OB_TX_MO_MA>* m_pcBurnLightTask; // offset 0xA4, size 0x4
};

#endif // ST12PUTCANOEMOTION_HPP
