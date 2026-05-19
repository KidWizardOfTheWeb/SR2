#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/DashRing.hpp"

namespace nspDashRing {
f32 tof32CLIP_DISTx2[17];
} // namespace nspDashRing

void clsDashRing_Obj::createData()
{
}

void clsDashRing_Obj::destroyData()
{
}

void clsDashRing_Obj::draw(clsModelType_OB_TX& rcObj,
                           f32 (*psMtxPal)[4][4],
                           u32* psNodeStat,
                           const f32 (*opaNnViewMtx)[4][4],
                           f32 (*psMtxWork)[4][4])
{
}

void clsDashRing_Obj::contactTriggerEvent(hkContactPoint* pParam1, clsObject* pcObject)
{
}

void clsDashRing_Task::execute()
{
}

void clsDashRing_Task::draw()
{
}

nspPackId::enm clsDashRing_Obj::getPackId() const
{
    return nspPackId::DASH_RING_2040;
}
