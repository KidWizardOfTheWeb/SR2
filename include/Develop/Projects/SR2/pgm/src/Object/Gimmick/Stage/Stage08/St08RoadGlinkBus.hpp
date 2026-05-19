#ifndef ST08ROADGLINKBUS_HPP
#define ST08ROADGLINKBUS_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08RoadCarBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"

class clsRoadGlinkBus_Task;
class clsPlayerTask;
struct hkContactPointConfirmedEvent;
class clsClipper;

class clsRoadGlinkBus_Obj : public clsRoadGlinkCarBase_Obj {
public:
    // Members
public:
    clsSe3DControl* m_pcSe3DControl; // offset 0x2C0, size 0x4

    // Static members
    static f32 m_tof32ClipSqDist;
    static NNS_VECTOR t_osCollisionHalfSizeVec;
    static clsGravityGimmickParam t_ocGravityGimmickParam;

    // Constructors / Destructor
    clsRoadGlinkBus_Obj();
    virtual ~clsRoadGlinkBus_Obj();

    // Override from base classes
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void init();
    virtual nspPackId::enm getPackId() const;
    virtual void requestDrawBreakEffect();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rParam1);
    virtual void drawEffect(clsPlayerTask* pcPlayer);
    virtual void draw(clsModelType_OB_TX& rcObj,
                      f32 (*psMtxPal)[4][4],
                      u32* psNodeStat,
                      const f32 (*opaNnViewMtx)[4][4],
                      f32 (*psMtxWork)[4][4],
                      u32 u32ViewNo);

    // New virtual slots (inline weak functions)
    NNS_VECTOR* getCollisionHalfSizeVecPtr() const { return &t_osCollisionHalfSizeVec; }
    void requestRunSe() {}
    void stopSunSe() {}
};

class clsRoadGlinkBus_Task : public clsSingleModelGimmick_Task<clsRoadGlinkBus_Task,
                                                               clsRoadGlinkBus_Obj,
                                                               clsModelType_OB_TX> {
public:
    clsRoadGlinkBus_Task(u32 u32ObjectAreaNum);
    virtual ~clsRoadGlinkBus_Task() {}

    void reset();
    void execute();
    void draw();
};

#endif // ST08ROADGLINKBUS_HPP
