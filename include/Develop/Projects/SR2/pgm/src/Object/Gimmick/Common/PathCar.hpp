#ifndef PATHCAR_HPP
#define PATHCAR_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGimmick.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PathGravityObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsSe3DControl;
class clsBackLineEffectTask;

// total size: 0x280
class clsPathCar_Obj : public clsPathGravityObj_Obj {
public:
    clsPathCar_Obj();
    virtual ~clsPathCar_Obj();

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST01_PUT_CAR_11010; }
    virtual void reset();
    virtual void init();
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rEvent);
    virtual void adminSe();

    u8 draw(clsModelType_OB_TX* pcModels,
            f32 (*psMtxPal)[4][4],
            u32* psNodeStat,
            const f32 (*opaNnViewMtx)[4][4],
            f32 (*psMtxWork)[4][4]);

    static f32 t_of32CLIP_DISTx2;
    static u32 otau32SeTbl[3][3];

    clsSe3DControl* m_pcSe3DControl;         // offset 0x220, size 0x4
    f32 m_sDrawMtx[4][4];                    // offset 0x230, size 0x40
    clsBackLineEffectTask* m_apcLineTask[2]; // offset 0x270, size 0x8
    u8 m_u8ContactSeCount;                   // offset 0x278, size 0x1
    u8 m_u8ModelNo;                          // offset 0x279, size 0x1
};

// total size: 0x9C
class clsPathCar_Task
    : public clsMultiModelGimmick_Task<clsPathCar_Task, clsPathCar_Obj, clsMultiObTxModels> {
public:
    clsPathCar_Task(u32 u32ObjectAreaNum);
    virtual ~clsPathCar_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // PATHCAR_HPP
