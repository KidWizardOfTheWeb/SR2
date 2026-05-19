#include "Develop/Projects/SR2/pgm/src/Effect/Post/PS2_ColorDrops.hpp"

namespace nspColorDrops {
static u32 otau32ColorDropTbl[3] = {0x14E6FFFF, 0xFAFF41FF, 0xFA1E00FF};
stcPrimitive tsPrimitive[10] = {{0, 0, 0, 0, 0, 0x0D},
                                {0, 0, 0, 0, 0, 0x0D},
                                {0, 0, 0, 0, 0, 0x05},
                                {0, 0, 0, 0, 0, 0x05},
                                {0, 0, 0, 0, 0, 0x05},
                                {0, 0, 0, 0, 0, 0x05},
                                {0, 0, 0, 0, 0, 0x05},
                                {0, 0, 0, 0, 0, 0x05},
                                {0, 0, 0, 0, 0, 0x05},
                                {0, 0, 0, 0, 0, 0x05}};
} // namespace nspColorDrops

void clsColorDrops_Task::reinit()
{
}

void clsColorDrops_Task::reinitView(u8 u8ViewNoI)
{
}

void clsColorDrops_Task::addDetail(
    u32 u32vI, u32 u32NumI, u32 u32ScaleI, f32 f32LifeFrameI, u8 u8Param5)
{
}

void clsColorDrops_Task::addDetail(
    u32 u32vI, u32 u32NumI, u32 u32ScaleI, f32 f32LifeFrameI, u32 bSnowI)
{
}
