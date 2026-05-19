#ifndef ST04PATHCANOE_HPP
#define ST04PATHCANOE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"

class clsSe3DControl;

enum enmPathCanoeMode {
    MODE_INIT = 0,
    MODE_START_WAIT = 1,
    MODE_MAIN = 2,
    MODE_BLINK_WAIT = 3,
    MODE_NOT_DISP = 4,
    MODE_WAIT = 5,
};

class clsPathCanoe_Obj;

// total size: 0x9C
class clsPathCanoe_Task
    : public clsSingleModelGimmick_Task<clsPathCanoe_Task, clsPathCanoe_Obj, clsModelType_OB_TX> {
public:
    clsPathCanoe_Task(u32 packId);

    virtual ~clsPathCanoe_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();

    u16* m_TexIdx;  // offset 0x94, size 0x4
    u16* m_TexIdx2; // offset 0x98, size 0x4
};

// total size: 0x260
class clsPathCanoe_Obj : public clsRigidBodyGimmickObj {
public:
    static f32 tof32ClipSqDist;
    static u32 otau32Se_CanoeBreak[2];
    static u32 otau32Se_CanoeExp[2];
    static u32 otau32Se_CanoeL[2];

    clsPathCanoe_Obj() : clsRigidBodyGimmickObj() {}
    virtual ~clsPathCanoe_Obj() {}
    virtual void contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2);
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST04_PATH_CANOE_14040; }
    virtual void reset();
    virtual void init();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent();
    virtual void callbackCrashEvent();
    virtual void boundAction(clsPlayerTask* pParam1);

    u8 draw(clsModelType_OB_TX& rParam1,
            f32 (*)[4][4],
            u32* pParam3,
            const f32 (*)[4][4],
            f32 (*)[4][4],
            u32 u32Param6);
    void chackAction(u32 u32Param1);
    void path_main();
    void initParameter();

    NNS_QUATERNION m_sInitRotQuat;      // offset 0xD0, size 0x10
    enmPathCanoeMode m_enPathCanoeMode; // offset 0xE0, size 0x4
    // gap 0xE4-0xEF (alignment padding before clsPosturalCtrl)
    clsPosturalCtrl m_cPostural; // offset 0xF0, size 0xB0
    clsPath m_cPath;             // offset 0x1A0, size 0x60
    f32 m_f32Speed;              // offset 0x200, size 0x4
    f32 m_f32TotalFrame;         // offset 0x204, size 0x4
    f32 m_f32StartWaitFrame;     // offset 0x208, size 0x4
    f32 m_f32EventFrame;         // offset 0x20C, size 0x4
    u8 m_bObjRotChange;          // offset 0x210, size 0x1
    u8 m_bPathChanged;           // offset 0x211, size 0x1
    // gap 0x212-0x213 (alignment padding)
    f32 m_f32Alpha;             // offset 0x214, size 0x4
    s32 m_s32LoopSe;            // offset 0x218, size 0x4
    u32 m_u32Attr;              // offset 0x21C, size 0x4
    f32 m_f32EffectFrame;       // offset 0x220, size 0x4
    f32 m_f32MaxSpeed;          // offset 0x224, size 0x4
    f32 m_f32MimSpeed;          // offset 0x228, size 0x4
    f32 m_f32SlowPathRateStart; // offset 0x22C, size 0x4
    f32 m_f32SpeedOld;          // offset 0x230, size 0x4
    // gap 0x234-0x23F (alignment padding before NNS_VECTORFAST)
    NNS_VECTORFAST m_sOldUpVecFast; // offset 0x240, size 0x10
    u8 m_bTurbulenceDsp;            // offset 0x250, size 0x1
    // gap 0x251-0x253 (alignment padding)
    u32 m_u32ObjectNum;              // offset 0x254, size 0x4
    u32 m_u32TexIdx;                 // offset 0x258, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0x25C, size 0x4
};

#endif // ST04PATHCANOE_HPP
