#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage05/St05RotGround.hpp"

static f32 m_tof32ClipDist;

NNS_VECTORFAST clsRotGround_Obj::m_tosColiPosVecFast = {
    -64079.0f / 399.0f, -31260.0f / 41.0f, -38265.0f / 674.0f, 1.0f};
f32 clsRotGround_Obj::m_tof32ColiRot;

namespace nspRotGround {
f32 toaf32BaseRot[10] = {0.0f,
                         5.4720864f,
                         12.692548f,
                         21.184381f,
                         30.711838f,
                         41.128796f,
                         52.333836f,
                         64.251526f,
                         76.823082f,
                         90.001099f};
f32 toaf32DiffRot[10] = {0.0f,
                         5.4720864f,
                         7.2204614f,
                         8.4918327f,
                         9.5274563f,
                         10.416959f,
                         11.205041f,
                         11.917692f,
                         12.571553f,
                         13.178014f};
} // namespace nspRotGround

void clsRotGroundThroughCollision::contactTriggerEvent(clsPlayerTask* pcPlayer)
{
}

void clsRotGroundThroughCollision::contactRemoveEvent(clsPlayerTask* pcPlayer)
{
}

void clsRotGround_Obj::createData()
{
}

void clsRotGround_Obj::destroyData()
{
}

f32 clsRotGround_Obj::getLengthRate(const NNS_VECTORFAST& rsPosVecFast)
{
    return 0.0f;
}

void clsRotGround_Obj::execute()
{
}

void clsRotGround_Obj::draw(clsModelType_OB_TX& rcModel)
{
}

void clsRotGround_Task::reset()
{
}

void clsRotGround_Task::execute()
{
}

void clsRotGround_Task::draw()
{
}
