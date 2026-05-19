#ifndef RAILWAY_HPP
#define RAILWAY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

// total size: 0x50
class clsRailWay_Obj : public clsGimmickObj {
public:
    clsRailWay_Obj() {}
    virtual ~clsRailWay_Obj() {}
    virtual nspPackId::enm getPackId() const { return nspPackId::RAIL_WAY_START_2230; }
    u8 draw(clsModelType_OB_TX& rcModel,
            f32 (*psMtxPal)[4][4],
            u32* psNodeStat,
            const f32 (*opaNnViewMtx)[4][4],
            f32 (*psMtxWork)[4][4],
            u32 u32ViewNo);

    static f32 m_tof32CLIP_DISTx2;
};

// total size: 0x94
class clsRailWayEnd_Task
    : public clsSingleModelGimmick_Task<clsRailWayEnd_Task, clsRailWay_Obj, clsModelType_OB_TX> {
public:
    clsRailWayEnd_Task(u32 u32Param1)
        : clsSingleModelGimmick_Task<clsRailWayEnd_Task, clsRailWay_Obj, clsModelType_OB_TX>(0, 0)
    {
    }
    virtual ~clsRailWayEnd_Task() {}

    virtual void execute();
    virtual void draw();
};

// total size: 0x94
class clsRailWayStart_Task
    : public clsSingleModelGimmick_Task<clsRailWayStart_Task, clsRailWay_Obj, clsModelType_OB_TX> {
public:
    clsRailWayStart_Task(u32 u32Param1)
        : clsSingleModelGimmick_Task<clsRailWayStart_Task, clsRailWay_Obj, clsModelType_OB_TX>(0, 0)
    {
    }
    virtual ~clsRailWayStart_Task() {}

    virtual void execute();
    virtual void draw();
};

#endif // RAILWAY_HPP
