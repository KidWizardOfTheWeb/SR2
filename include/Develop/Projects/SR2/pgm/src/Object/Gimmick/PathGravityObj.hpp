#ifndef PATHGRAVITYOBJ_HPP
#define PATHGRAVITYOBJ_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Postural.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Path.hpp"

enum enmPathMode {
    MODE_INIT = 0,
    MODE_START_WAIT = 1,
    MODE_MAIN = 2,
    MODE_BLINK_WAIT = 3,
    MODE_NOT_DISP = 4,
    MODE_WAIT = 5,
};

// total size: 0x220
class clsPathGravityObj_Obj : public clsRigidBodyGimmickObj {
public:
    clsPathGravityObj_Obj() {}
    virtual ~clsPathGravityObj_Obj() {}

    virtual void reset();
    virtual void init();
    virtual void main();
    virtual void mainGravity();
    virtual void mainDead();
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::PATH_GARVITYOBJ_2140; }
    virtual void adminSe();
    virtual void calcPathPostural();

    void initParameter();
    void resetRigidBody();
    void timeUpdate();
    void startWait();
    void path_main();
    void wait();
    void checkAction();
    void blink_wait();

    NNS_QUATERNION m_sInitRotQuat; // offset 0xD0, size 0x10
    enmPathMode m_enPathCarMode;   // offset 0xE0, size 0x4
    clsPosturalCtrl m_cPostural;   // offset 0xF0, size 0xB0
    clsPath m_cPath;               // offset 0x1A0, size 0x60
    f32 m_f32Speed;                // offset 0x200, size 0x4
    f32 m_f32TotalFrame;           // offset 0x204, size 0x4
    f32 m_f32StartWaitFrame;       // offset 0x208, size 0x4
    f32 m_f32EventFrame;           // offset 0x20C, size 0x4
    u8 m_bObjRotChange;            // offset 0x210, size 0x1
    u8 m_bPathChanged;             // offset 0x211, size 0x1
    u8 m_bGravityFlag;             // offset 0x212, size 0x1
    s32 m_s32LoopSe;               // offset 0x214, size 0x4
    u32 m_u32Attr;                 // offset 0x218, size 0x4
};

// total size: 0x98
class clsPathGravityObj_Task : public clsSingleModelGimmick_Task<clsPathGravityObj_Task,
                                                                 clsPathGravityObj_Obj,
                                                                 clsModelType_OB_TX> {
public:
    clsPathGravityObj_Task(u32 u32ObjectAreaNum);
    virtual ~clsPathGravityObj_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // PATHGRAVITYOBJ_HPP
