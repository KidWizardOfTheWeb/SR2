#ifndef PUTGRAVITYOBJ_HPP
#define PUTGRAVITYOBJ_HPP

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PutGravityObj2.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

class clsSe3DControl;
class clsPutGravityObj_Task;

// total size: 0xE0
class clsPutGravityObj_Obj : public clsRigidBodyGimmickObj {
public:
    enum enmPutGravityObjMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    clsPutGravityObj_Obj()
        : m_ePutGravityObjMode(MODE_INIT), m_psFloatingParticle(NULL), m_pcSe3DControl(NULL)
    {
    }
    virtual ~clsPutGravityObj_Obj() { destroyData(); }
    virtual nspPackId::enm getPackId() const
    {
        return nspPackId::PUT_GRAVITYOBJ_2100;
    } // RECONSTRUCTED.
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
              NNS_MATRIX* psMtxPal,
              u32* psNodeStat,
              const NNS_MATRIX* opaNnViewMtx,
              NNS_MATRIX* psMtxWork,
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
        : clsMultiShape(u32ObjectAreaNum),
          clsMultiModelGimmick_Task<clsPutGravityObj_Task,
                                    clsPutGravityObj_Obj,
                                    clsMultiObTxModels>(u32ObjectAreaNum, 101000)
    {
    }
    virtual ~clsPutGravityObj_Task();

    void createModel(stcBinInfo& rParam1);

    virtual void reset();
    virtual void execute();
    virtual void draw();
};

inline clsPutGravityObj_Task::~clsPutGravityObj_Task()
{
}

#endif // PUTGRAVITYOBJ_HPP
