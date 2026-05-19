#ifndef ST12PATHCANOEMOTION_HPP
#define ST12PATHCANOEMOTION_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage04/St04PathCanoe.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsSe3DControl;
class clsModelType_OB_TX_MO;

// total size: 0x250
class clsPathCanoeMotion_Obj : public clsRigidBodyGimmickObj {
public:
    static f32 tof32ClipSqDist;
    static u32 otau32Se_CanoeBreak[2];
    static u32 otau32Se_CanoeExp[2];
    static u32 otau32Se_CanoeL[2];

    NNS_QUATERNION m_sInitRotQuat;      // offset 0xD0, size 0x10
    enmPathCanoeMode m_enPathCanoeMode; // offset 0xE0, size 0x4
    clsPosturalCtrl m_cPostural;        // offset 0xF0, size 0xB0
    clsPath m_cPath;                    // offset 0x1A0, size 0x60
    f32 m_f32Speed;                     // offset 0x200, size 0x4
    f32 m_f32TotalFrame;                // offset 0x204, size 0x4
    f32 m_f32StartWaitFrame;            // offset 0x208, size 0x4
    f32 m_f32EventFrame;                // offset 0x20C, size 0x4
    u8 m_bObjRotChange;                 // offset 0x210, size 0x1
    u8 m_bPathChanged;                  // offset 0x211, size 0x1
    f32 m_f32Alpha;                     // offset 0x214, size 0x4
    s32 m_s32LoopSe;                    // offset 0x218, size 0x4
    u32 m_u32Attr;                      // offset 0x21C, size 0x4
    f32 m_f32EffectFrame;               // offset 0x220, size 0x4
    f32 m_f32MaxSpeed;                  // offset 0x224, size 0x4
    f32 m_f32SpeedOld;                  // offset 0x228, size 0x4
    NNS_VECTORFAST m_sOldUpVecFast;     // offset 0x230, size 0x10
    u32 m_u32TexIdx;                    // offset 0x240, size 0x4
    f32 m_f32MotionFrame;               // offset 0x244, size 0x4
    f32 m_f32EndFrame;                  // offset 0x248, size 0x4
    clsSe3DControl* m_pcSe3DControl;    // offset 0x24C, size 0x4

    clsPathCanoeMotion_Obj() {}
    virtual ~clsPathCanoeMotion_Obj() {}
    virtual nspPackId::enm getPackId() const { return nspPackId::ST04_PATH_CANOE_14040; }

    virtual void contactTriggerEvent(hkContactPoint* p, clsObject* o);
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void callbackGravityEvent();
    virtual void callbackCrashEvent();
    virtual void requestDrawBreakEffect();
    virtual void boundAction(clsPlayerTask* p);
    virtual void reset();
    virtual void init();
    virtual void main();

    void initParameter();
    void path_main();
    u8 draw(clsModelType_OB_TX_MO& m,
            f32 (*a)[4][4],
            u32* b,
            const f32 (*c)[4][4],
            f32 (*d)[4][4],
            u32 e,
            f32* f);
};

// total size: 0xA8
class clsPathCanoeMotion_Task : public clsSingleModelGimmick_Task<clsPathCanoeMotion_Task,
                                                                  clsPathCanoeMotion_Obj,
                                                                  clsModelType_OB_TX_MO> {
public:
    clsPathCanoeMotion_Task(u32 u32ObjectAreaNum);
    virtual ~clsPathCanoeMotion_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();

    clsGmkBurnLight_Task<clsModelType_OB_TX_MO_MA>* m_pcBurnLightTask; // offset 0x9C, size 0x4
    u16* m_TexIdx;                                                     // offset 0xA0, size 0x4
    u16* m_TexIdx2;                                                    // offset 0xA4, size 0x4
};

#endif // ST12PATHCANOEMOTION_HPP
