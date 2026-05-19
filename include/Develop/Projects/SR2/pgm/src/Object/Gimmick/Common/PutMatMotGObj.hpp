#ifndef PUTMATMOTGOBJ_HPP
#define PUTMATMOTGOBJ_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PutGravityObj2.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsSe3DControl;

// total size: 0xE0
class clsPutMatMotGObj_Obj : public clsRigidBodyGimmickObj {
public:
    enum enmPutMatMotGObjMode {
        // Note: name collision with enmPutGravityObjMode (same values, different type)
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    clsPutMatMotGObj_Obj() {}
    virtual ~clsPutMatMotGObj_Obj() {}

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::PUT_MATMOTGOBJ_2101; }
    virtual void reset();
    virtual void init();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void contactInterraction(clsRigidBodyGimmickObj* pcRigidBodyGimmickObj);
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rEvent) {}

    void draw(clsModelType_OB_TX_MO_MA* pcModels,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);

    static f32 m_tof32CLIP_DISTx2;
    static clsGravityGimmickParam t_ocGravityGimmickParam;

    enmPutMatMotGObjMode m_ePutMatMotGObjMode; // offset 0xD0, size 0x4
    clsSe3DControl* m_pcSe3DControl;           // offset 0xD4, size 0x4
    f32 m_f32MatMotEndFrame;                   // offset 0xD8, size 0x4
    f32 m_f32MatMotFrame;                      // offset 0xDC, size 0x4
};

class clsPutMatMotGObj_Task : public clsMultiShape,
                              public clsMultiModelGimmick_Task<clsPutMatMotGObj_Task,
                                                               clsPutMatMotGObj_Obj,
                                                               clsMultiObjTxMaModels> {
public:
    clsPutMatMotGObj_Task(u32 u32Param1) : clsMultiModelGimmick_Task(0, 0) {}
    virtual ~clsPutMatMotGObj_Task() {}
    virtual void reset();
    virtual void execute();
    virtual void draw();
};

#endif // PUTMATMOTGOBJ_HPP
