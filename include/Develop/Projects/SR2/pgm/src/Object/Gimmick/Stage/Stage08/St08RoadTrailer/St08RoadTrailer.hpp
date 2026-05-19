#ifndef ST08ROADTRAILER_HPP
#define ST08ROADTRAILER_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGimmick.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08RoadCarBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08RoadTrailer/St08RoadContainer.hpp"
#include "types.h"

class hkShape;
class clsSe3DControl;

// total size: 0x3C0
class clsRoadTrailer_Obj : public clsRoadCarBase_Obj {
public:
    clsRoadTrailer_Obj() {}
    virtual ~clsRoadTrailer_Obj() {}

    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void init();
    virtual void requestDrawBreakEffect();
    virtual void execute();
    virtual void resetObject();
    virtual void eventStartMove();
    virtual void eventStopMove();
    virtual void eventSetPosition();
    virtual void requestRunSe() {}
    virtual void requestHorn() {}
    virtual void stopRunSe() {}

    void draw(clsModelType_OB_TX& rcObj,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);
    nspPackId::enm getPackId() const { return nspPackId::ST08_ROAD_TRAILER_18040; }

    static f32 m_tof32ClipSqDist;
    static clsGravityGimmickParam t_ocGravityGimmickParam;

    clsRoadContainer_Obj m_cContainer; // offset 0x2B0, size 0x100
    clsSe3DControl* m_pcSe3DControl;   // offset 0x3B0, size 0x4
};

// total size: 0x9C
class clsRoadTrailer_Task : public clsMultiModelGimmick_Task<clsRoadTrailer_Task,
                                                             clsRoadTrailer_Obj,
                                                             clsMultiObTxModels> {
public:
    clsRoadTrailer_Task(u32 u32ObjectAreaNum);
    virtual ~clsRoadTrailer_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    hkShape* m_pcContainerShape; // offset 0x98, size 0x4
};

#endif // ST08ROADTRAILER_HPP
