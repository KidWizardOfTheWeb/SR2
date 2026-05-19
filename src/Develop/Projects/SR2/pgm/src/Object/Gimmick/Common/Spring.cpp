#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/Spring.hpp"

namespace nspSpring {
static u32 toau32NodeStateNoneData[3][2] = {{1, 8}, {3, 8}, {5, 12}};
static u32 tou32SetGravityUp = 0x1BFFB;
static u32 ou32UpdateUpVec = 0x1BFFF;
} // namespace nspSpring

f32 clsSpring_Obj::m_tof32CLIP_DISTx2 = 0.0f;
u8 clsSpring_Obj::m_toau8TopNodeNo[3] = {2, 4, 6};

void clsSpring_Obj::createData()
{
}

void clsSpring_Obj::setData()
{
}

void clsSpring_Obj::destroyData()
{
}

void clsSpring_Obj::contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2)
{
}

void clsSpring_Task::stopSpringSe(clsPlayerTask* pcPlayer)
{
}

void clsSpring_Task::playSpringSe(clsPlayerTask* pcPlayer)
{
}

void clsSpring_Task::execute()
{
}

void clsSpring_Task::draw()
{
}
