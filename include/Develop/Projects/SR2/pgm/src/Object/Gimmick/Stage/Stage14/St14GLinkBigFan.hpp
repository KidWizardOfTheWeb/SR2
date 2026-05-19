#ifndef ST14GLINKBIGFAN_HPP
#define ST14GLINKBIGFAN_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsPlayerTask;
class clsGLinkFan_Object;
class clsGLinkFanModel;

// total size: 0x10
class clsGLinkFanModel {
public:
    clsGLinkFanModel() {}
    ~clsGLinkFanModel() {}

    clsModelType_OB_TX m_cModelWick;  // offset 0x0, size 0x8
    clsModelType_OB_TX m_cModelBlade; // offset 0x8, size 0x8
};

// total size: 0xA0
class clsGLinkFan_Task
    : public clsBaseGimmickBody<clsGLinkFan_Task, clsGLinkFan_Object, clsGLinkFanModel> {
public:
    clsGLinkFan_Task(u32 u32ObjectAreaNum);
    virtual ~clsGLinkFan_Task();

    virtual void execute();
    virtual void draw();
    virtual void reset();
    void createModel(stcBinInfo& rsBinInfoI);

    clsGmkBurnLight_Task<clsModelType_OB_TX_MO_MA>* m_pcBurnLightTask; // offset 0x9C, size 0x4
};

enum enmStateType {
    TYPE_UPPER = 0,
    TYPE_LOWER = 1,
};

// total size: 0x160
class clsGLinkFan_Blade : public clsBaseGravityLinkObject {
public:
    // Note: enmMode collision with Game.hpp — nested here for disambiguation
    enum enmMode {
        MODE_NONE = 0,
        MODE_CRASH = 1,
        MODE_BREAK = 2,
    };

    clsGLinkFan_Blade() {}
    virtual ~clsGLinkFan_Blade() {}
    virtual void contactTriggerCallback(hkContactPointConfirmedEvent& cEvent);
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();
    virtual void mainGravity();
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rsEvent) {}
    virtual NNS_VECTOR* getCollisionHalfSizeVecPtr() const { return &tosCollisionHalfSizeVec; }

    u8 draw(NNS_OBJECT* psObject,
            f32 (*psMtxPal)[4][4],
            u32* psNodeStat,
            const f32 (*opaNnViewMtx)[4][4],
            f32 (*psMtxWork)[4][4],
            u32 u32ViewNo);
    void initParam();

    static NNS_VECTOR tosCollisionHalfSizeVec;
    static f32 tof32ClipSqDist;
    static clsGravityGimmickParam t_ocSt14GravityGimmickParam;

    clsGLinkFan_Object* m_pcFanObj;  // offset 0xE0, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xE4, size 0x4
    NNS_QUATERNION m_sBaseQuat;      // offset 0xE8, size 0x10
    u32 m_u32PartsNo;                // offset 0xF8, size 0x4
    enmMode m_eMode;                 // offset 0xFC, size 0x4
    enmStateType m_eStateType;       // offset 0x100, size 0x4
    u8 m_bFilterChangeGravity;       // offset 0x104, size 0x1
    u8 m_bFilterChangeGround;        // offset 0x105, size 0x1
    u8 m_bFilterChange;              // offset 0x106, size 0x1
    u8 m_bSeFlag;                    // offset 0x107, size 0x1
    u8 m_bGravityFlag;               // offset 0x108, size 0x1
    f32 m_sEffectMatrix[4][4];       // offset 0x110, size 0x40
    clsTask* m_pcEffectTask;         // offset 0x150, size 0x4
};

// total size: 0x4A0
class clsGLinkFan_Object : public clsGimmickObj {
public:
    // TODO: enmFanMode also used by clsFan_Obj — may need to be shared
    enum enmFanMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    clsGLinkFan_Object() {}
    virtual ~clsGLinkFan_Object() {}
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST14_BIG_FAN_24030; }

    void draw(clsModelType_OB_TX* psModel,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);

    static f32 tof32ClipSqDist;

    clsGLinkFan_Blade m_acBlade[3];      // offset 0x50, size 0x420
    NNS_VECTORFAST m_sBaseUpVecFast;     // offset 0x470, size 0x10
    NNS_VECTORFAST m_sAngleVelocityFast; // offset 0x480, size 0x10
    clsSe3DControl* m_pcSe3DControl;     // offset 0x490, size 0x4
    s32 m_A32RotateSpeed;                // offset 0x494, size 0x4
    enmFanMode m_eFanMode;               // offset 0x498, size 0x4
};

#endif // ST14GLINKBIGFAN_HPP
