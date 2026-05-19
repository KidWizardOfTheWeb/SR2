#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08RoadSignal.hpp"

f32 clsRoadSignal_Obj::m_tof32CLIP_DISTx2 = 0.0f;

void clsRoadSignal_Obj::execute()
{
}

void clsRoadSignal_Obj::draw(clsModelType_OB_TX_MO& rParam1,
                             f32 (*psMtxPal)[4][4],
                             u32* pParam3,
                             const f32 (*opaNnViewMtx)[4][4],
                             f32 (*psMtxWork)[4][4],
                             u32 u32Param6)
{
}

void clsRoadSignal_Task::reset()
{
}

void clsRoadSignal_Task::execute()
{
}

void clsRoadSignal_Task::draw()
{
}

clsRoadSignal_Obj::clsRoadSignal_Obj() : clsGimmickObj()
{
}

clsRoadSignal_Obj::~clsRoadSignal_Obj()
{
}

nspPackId::enm clsRoadSignal_Obj::getPackId() const
{
    return nspPackId::ST08_ROAD_SIGNAL_18010;
}
