#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08FZoneEnemy/St08FZoneEnemy.hpp"

struct stcPointData {
    NNS_VECTORFAST sPointVecFast;
    f32 f32WaitFrame;
};

f32 clsFZoneEnemy_Obj::m_tof32CLIP_DISTx2;

namespace nspSt08FZoneEnemy {
static stcPointData tosPoint00[2] = {
    {{-420.0f, 60.0f, 245.0f, 1.0f}, 10.0f},
    {{-420.0f, 40.0f, 245.0f, 1.0f}, 10.0f},
};

static stcPointData tosPoint01[2] = {
    {{-354.3f, 63.9f, 252.6f, 1.0f}, 10.0f},
    {{-354.3f, 54.9f, 252.6f, 1.0f}, 10.0f},
};

static stcPointData* toapsPointTbl[2] = {tosPoint00, tosPoint01};
static u8 toau8PointArrayNumTbl[2] = {2, 2};
} // namespace nspSt08FZoneEnemy

void clsFZoneEnemy_Obj::init()
{
}

void clsFZoneEnemy_Obj::reset()
{
}

void clsFZoneEnemy_Obj::setData()
{
}

void clsFZoneEnemy_Obj::createData()
{
}

void clsFZoneEnemy_Obj::destroyData()
{
}

void clsFZoneEnemy_Obj::setVelocityAndFrame(f32 f32LengthRate, f32 f32Speed)
{
}

void clsFZoneEnemy_Obj::contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject)
{
}

void clsFZoneEnemy_Obj::requestDrawBreakEffect()
{
}

void clsFZoneEnemy_Obj::main()
{
}

void clsFZoneEnemy_Obj::mainCrash()
{
}

void clsFZoneEnemy_Obj::draw(clsModelType_OB_TX_MO& rcModel,
                             f32 (*psMtxPal)[4][4],
                             u32* psNodeStat,
                             const f32 (*opaNnViewMtx)[4][4],
                             f32 (*psMtxWork)[4][4],
                             u32 u32ViewNo)
{
}

void clsFZoneEnemy_Task::reset()
{
}

void clsFZoneEnemy_Task::execute()
{
}

void clsFZoneEnemy_Task::draw()
{
}
