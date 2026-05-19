#ifndef ST05DETENTION_HPP
#define ST05DETENTION_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

class clsDetention_Obj;
class clsPlayerTask;

// total size: 0xC
class clsDetentionThroughCol : public clsBaseThroughCollision {
public:
    virtual ~clsDetentionThroughCol() {}
    virtual void contactTriggerEvent(clsPlayerTask* pParam1);

    clsDetention_Obj* m_pcObj; // offset 0x8, size 0x4
};

// total size: 0xE0
class clsDetention_Obj : public clsRigidBodyGimmickObj {
public:
    clsDetention_Obj() {}
    virtual ~clsDetention_Obj() {}

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST05_DETENTION_15060; }
    virtual void reset();
    virtual void init();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rParam1);

    void start();

    static f32 m_tof32ClipSqDist;

    enmMode m_eMode;                      // offset 0xD0, size 0x4
    clsDetentionThroughCol m_cThroughCol; // offset 0xD4, size 0xC
};

// total size: 0x94
class clsDetention_Task
    : public clsBaseGimmickBody<clsDetention_Task, clsDetention_Obj, clsModelType_OB_TX> {
public:
    clsDetention_Task(u32 u32ObjectAreaNum);
    virtual ~clsDetention_Task();

    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI);
};

#endif // ST05DETENTION_HPP
