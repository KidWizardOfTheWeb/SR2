#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearPtnSkate.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2System.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearBurnLight.hpp"

void clsGearPtnSkate::clearChangeActionParam()
{
}

void clsGearPtnSkate::behavior()
{
}

void clsGearPtnSkate::behavior_NodeMtx()
{
}

void clsGearPtnSkate::controlMotion()
{
}

void clsGearPtnSkate::controlMotionCurve00()
{
}

void clsGearPtnSkate::draw(const NNS_MATRIX* pParam1, f32 f32Param2, u32 u32Param3)
{
    m_pcBurnLight_Task->m_s16DrawNum = clsPfSystem::GS()->m_bUnPause;
}
