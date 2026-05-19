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

void clsGearPtnSkate::draw(const f32 (*pParam1)[4][4], f32 f32Param2, u32 u32Param3)
{
    m_pcBurnLight_Task->m_s16DrawNum =
        *(u8*)((u8*)clsSingleton<clsPfSystem>::m_tpcSingleton + 0x7E);
}
