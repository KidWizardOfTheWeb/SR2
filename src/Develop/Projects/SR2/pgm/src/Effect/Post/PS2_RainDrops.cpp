#include "Develop/Projects/SR2/pgm/src/Effect/Post/PS2_RainDrops.hpp"

namespace nspRainDrops {

u64 tau64GsPacket_DrawRainDrops_NTSC[10][2];
u64 tau64GsPacket_DrawRainDrops_PAL[10][2];
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

} // namespace nspRainDrops

clsRainDrops_Task::clsRainDrops_Task(u32 u32Tp, s32 s32Flg) : clsTask(u32Tp, s32Flg)
{
}

void clsRainDrops_Task::reinit()
{
}

void clsRainDrops_Task::addDetail(
    u32 u32vI, u32 u32NumI, u32 bSnowI, f32 f32LifeFrameI, u8 u8IsGrowType)
{
}

void clsRainDrops_Task::drawBegin()
{
}

void clsRainDrops_Task::draw()
{
}
