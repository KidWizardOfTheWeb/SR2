#include "Develop/Projects/SR2/pgm/src/Effect/Post/PS2_Blur.hpp"

namespace nspBlur {

u64 tau64GsPacket_Capture_NTSC[12][2];
u64 tau64GsPacket_Capture_PAL[12][2];
u64 tau64GsPacket_DrawBlur_NTSC[11][2];
u64 tau64GsPacket_DrawBlur_PAL[11][2];

} // namespace nspBlur

clsBlur_Task::clsBlur_Task(u32 u32a, s32 s32b) : clsTask(u32a, s32b)
{
}

void clsBlur_Task::captureFullScreen()
{
}

void clsBlur_Task::drawNormal(u32 u32a, u8 u8b, f32 f32c)
{
}

void clsBlur_Task::drawGravity(u32 u32a, bool b)
{
}

void clsBlur_Task::execute()
{
}

void clsBlur_Task::draw()
{
}
