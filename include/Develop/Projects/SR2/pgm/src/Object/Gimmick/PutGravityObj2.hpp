#ifndef PUTGRAVITYOBJ2_HPP
#define PUTGRAVITYOBJ2_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGimmick.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/MultiShape.hpp"

class clsSe3DControl;
class clsPutGravityObj2_Task;
class hkShape;

#ifndef ENM_PUT_GRAVITY_OBJ_MODE_DECLARED
#define ENM_PUT_GRAVITY_OBJ_MODE_DECLARED
enum enmPutGravityObjMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};
#endif

// total size: 0xF0
class clsPutGravityObj2_Obj : public clsRigidBodyGimmickObj {
public:
    clsPutGravityObj2_Obj() {}
    virtual ~clsPutGravityObj2_Obj() {}

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::PUT_GRAVITYOBJ2_2102; }
    virtual void reset();
    virtual void init();
    virtual void main();
    virtual void requestDrawContactEffect(const hkContactPoint* pcContact);
    virtual void requestDrawBreakEffect();
    virtual void contactInterraction(clsRigidBodyGimmickObj* pcObject);
    virtual void callbackGravityEvent();
    virtual void callbackBreakEvent();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& param_1) {}
    virtual hkShape* getShape();
    virtual f32 getMass();
    virtual f32 getRestitution();
    virtual f32 getFriction();
    virtual void createSe();

    void draw(clsModelType_OB_TX* pcModels,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo,
              clsPutGravityObj2_Task* pcTask);
    void createDebris(NNS_OBJECT* psObject, u32 u32DebrisStartNodeNum, f32 f32LimitFrame);

    static f32 m_tof32CLIP_DISTx2;
    static clsGravityGimmickParam t_ocGravityGimmickParam;

    enmPutGravityObjMode m_ePutGravityObjMode; // offset 0xD0, size 0x4
    clsTask* m_psFloatingParticle;             // offset 0xD4, size 0x4
    clsSe3DControl* m_pcSe3DControl;           // offset 0xD8, size 0x4
    NNS_VECTOR m_sObjScaleVec;                 // offset 0xDC, size 0xC
    f32 m_f32SeDelayFrame;                     // offset 0xE8, size 0x4
    u32 m_u32ParticleType;                     // offset 0xEC, size 0x4
};

// total size: 0xA8
class clsPutGravityObj2_Task : public clsMultiShape,
                               public clsMultiModelGimmick_Task<clsPutGravityObj2_Task,
                                                                clsPutGravityObj2_Obj,
                                                                clsMultiObTxModels> {
public:
    clsPutGravityObj2_Task(u32 param);
    virtual ~clsPutGravityObj2_Task();

    virtual void init();
    virtual void reset();
    virtual void execute();
    virtual void draw();
};

#endif // PUTGRAVITYOBJ2_HPP
