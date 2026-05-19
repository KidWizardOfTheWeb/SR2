#ifndef ST11GLINKCYLINDER_HPP
#define ST11GLINKCYLINDER_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsPlayerTask;
class clsGlinkCylinderManager_Obj;

// total size: 0x280
class clsGlinkCylinder_Object : public clsBaseGravityLinkObject {
public:
    enum enmMode {
        MODE_MAIN = 0,
        MODE_WAIT = 1,
    };

    clsGlinkCylinder_Object();
    virtual ~clsGlinkCylinder_Object() {}
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const
    {
        return nspPackId::ST11_GLINK_CYLINDER_21050;
    } // [ASM-derived guess — verify]
    virtual void reset();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rsEvent);
    virtual void drawEffect(clsPlayerTask* pcPlayer);
    virtual NNS_VECTOR* getCollisionHalfSizeVecPtr() const;

    void draw(NNS_OBJECT* psObject,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);
    void stepPathFrame();
    void start();

    static NNS_VECTOR tosCollisionHalfSizeVec;
    static f32 tof32ClipSqDist;
    static clsGravityGimmickParam t_ocGravityGimmickParam;

    enmMode m_eMode;                 // offset 0xE0, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xE4, size 0x4
    clsGimmickPath m_cGimmickPath;   // offset 0xF0, size 0x190
};

// total size: 0x94
class clsGlinkCylinder_Task : public clsSingleModelGimmick_Task<clsGlinkCylinder_Task,
                                                                clsGlinkCylinderManager_Obj,
                                                                clsModelType_OB_TX> {
public:
    clsGlinkCylinder_Task(u32 u32ObjectAreaNum);
    virtual ~clsGlinkCylinder_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST11GLINKCYLINDER_HPP
