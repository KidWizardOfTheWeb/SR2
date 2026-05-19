#ifndef ST08ROADCAR_HPP
#define ST08ROADCAR_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08RoadCarBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

class clsSe3DControl;

// total size: 0x2C0
class clsRoadCar_Obj : public clsRoadCarBase_Obj {
public:
    clsRoadCar_Obj() {}
    virtual ~clsRoadCar_Obj() {}

    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST08_ROAD_CAR_18020; }
    virtual u32 getMultiDrawNum() const { return 4; }
    virtual void reset();
    virtual void init();
    virtual void requestDrawContactEffect(const hkContactPoint* pParam1);
    virtual void requestDrawBreakEffect();
    virtual void requestRunSe() {}
    virtual void requestHorn() {}
    virtual void stopRunSe() {}

    void draw(clsModelType_OB_TX& rcObj,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);

    static f32 m_tof32ClipSqDist;
    static clsGravityGimmickParam t_ocGravityGimmickParam;

    clsSe3DControl* m_pcSe3DControl; // offset 0x2B0, size 0x4
};

class clsRoadCar_Task
    : public clsSingleModelGimmick_Task<clsRoadCar_Task, clsRoadCar_Obj, clsModelType_OB_TX> {
public:
    clsRoadCar_Task(u32 u32ObjectAreaNum);
    virtual ~clsRoadCar_Task() {}

    void reset();
    void execute();
    void draw();
};

#endif // ST08ROADCAR_HPP
