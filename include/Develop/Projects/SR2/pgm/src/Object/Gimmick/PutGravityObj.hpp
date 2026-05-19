#ifndef PUTGRAVITYOBJ_HPP
#define PUTGRAVITYOBJ_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PutGravityObj2.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

class clsSe3DControl;
class clsPutGravityObj_Task;
class clsPutGravityObj_Obj;

// NOTE: same values as enmPutGravityObjMode in PutGravityObj2.hpp
#ifndef ENM_PUT_GRAVITY_OBJ_MODE_DECLARED
#define ENM_PUT_GRAVITY_OBJ_MODE_DECLARED
enum enmPutGravityObjMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};
#endif

// total size: 0xE0
class clsPutGravityObj_Obj : public clsRigidBodyGimmickObj {
public:
    clsPutGravityObj_Obj() {}
    virtual ~clsPutGravityObj_Obj() {}
    virtual nspPackId::enm getPackId() const
    {
        return nspPackId::PUT_GRAVITYOBJ_2100;
    } // likely: return 2100; [ASM-derived guess — verify]
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void init();
    virtual void main();
    virtual void requestDrawContactEffect(const hkContactPoint* pcContact);
    virtual void requestDrawBreakEffect();
    virtual void contactInterraction(clsRigidBodyGimmickObj* pParam1);
    virtual void callbackGravityEvent();
    virtual void callbackBreakEvent();

    void draw(clsModelType_OB_TX* pcModels,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo,
              clsPutGravityObj_Task* pcTask);

    enum enmPutGravityObjMode m_ePutGravityObjMode; // offset 0xD0, size 0x4
    clsTask* m_psFloatingParticle;                  // offset 0xD4, size 0x4
    clsSe3DControl* m_pcSe3DControl;                // offset 0xD8, size 0x4

    static clsGravityGimmickParam* t_apocGravityGimmickParams[17];
    static f32 m_tof32CLIP_DISTx2;
    static clsGravityGimmickParam t_ocGravityGimmickParam;
};

class clsPutGravityObj_Task : public clsMultiShape,
                              public clsMultiModelGimmick_Task<clsPutGravityObj_Task,
                                                               clsPutGravityObj_Obj,
                                                               clsMultiObTxModels> {
public:
    clsPutGravityObj_Task(u32 u32ObjectAreaNum)
        : clsMultiShape(), clsMultiModelGimmick_Task<clsPutGravityObj_Task,
                                                     clsPutGravityObj_Obj,
                                                     clsMultiObTxModels>(u32ObjectAreaNum, 0)
    {
    }
    virtual ~clsPutGravityObj_Task() {}

    void createModel(stcBinInfo& rParam1);

    virtual void reset();
    virtual void execute();
    virtual void draw();
};

#endif // PUTGRAVITYOBJ_HPP
