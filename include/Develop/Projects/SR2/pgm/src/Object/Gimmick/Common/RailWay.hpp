#ifndef RAILWAY_HPP
#define RAILWAY_HPP

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GmkBurnLight.hpp"

class clsRailWayEnd_Task;
class clsRailWayStart_Task;

// total size: 0x50
class clsRailWay_Obj : public clsGimmickObj {
public:
    clsRailWay_Obj() {}
    virtual ~clsRailWay_Obj() { destroyData(); }
    virtual nspPackId::enm getPackId() const { return nspPackId::RAIL_WAY_START_2230; }
    u8 draw(clsModelType_OB_TX& rcModel,
            NNS_MATRIX* psMtxPal,
            u32* psNodeStat,
            const NNS_MATRIX* opaNnViewMtx,
            NNS_MATRIX* psMtxWork,
            u32 u32ViewNo);

    static f32 m_tof32CLIP_DISTx2;
};

// total size: 0x94
class clsRailWayEnd_Task
    : public clsSingleModelGimmick_Task<clsRailWayEnd_Task, clsRailWay_Obj, clsModelType_OB_TX> {
public:
    clsRailWayEnd_Task(u32 u32Param1)
        : clsSingleModelGimmick_Task<clsRailWayEnd_Task, clsRailWay_Obj, clsModelType_OB_TX>(
              u32Param1, 101010)
    {
        clsModelType_OB_TX& rcModel = m_cModel;
        pcGmkBurnLight_Task = new (16, 2, (u32Param1 + 1) * 64)
            clsGmkBurnLight_Task<clsModelType_OB_TX>(rcModel, u32Param1 + 1, 1);
    }
    virtual ~clsRailWayEnd_Task();

    virtual void execute();
    virtual void draw();
};

// total size: 0x94
class clsRailWayStart_Task
    : public clsSingleModelGimmick_Task<clsRailWayStart_Task, clsRailWay_Obj, clsModelType_OB_TX> {
public:
    clsRailWayStart_Task(u32 u32Param1)
        : clsSingleModelGimmick_Task<clsRailWayStart_Task, clsRailWay_Obj, clsModelType_OB_TX>(
              u32Param1, 101010)
    {
        clsModelType_OB_TX& rcModel = m_cModel;
        pcGmkBurnLight_Task = new (16, 2, (u32Param1 + 1) * 64)
            clsGmkBurnLight_Task<clsModelType_OB_TX>(rcModel, u32Param1 + 1, 1);
    }
    virtual ~clsRailWayStart_Task();

    virtual void execute();
    virtual void draw();
};

inline clsRailWayEnd_Task::~clsRailWayEnd_Task()
{
}
inline clsRailWayStart_Task::~clsRailWayStart_Task()
{
}

#endif // RAILWAY_HPP
