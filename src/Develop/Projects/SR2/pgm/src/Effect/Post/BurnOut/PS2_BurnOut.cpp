#include "Develop/Projects/SR2/pgm/src/Effect/Post/BurnOut/PS2_BurnOut.hpp"

namespace nspBurnOut_Union {
u64 tau64GsPacket_Setting_SpBuf2Fb_NTSC[11][2];
u64 tau64GsPacket_Setting_SpBuf2Fb_PAL[11][2];
u64 tau64GsPacket_Setting_SpBuf2SpBuf_NTSC[11][2];
u64 tau64GsPacket_Setting_SpBuf2SpBuf_PAL[11][2];
u32 tu32FbWidthShiftR6;
} // namespace nspBurnOut_Union

clsBurnOut_Begin_Task::clsBurnOut_Begin_Task() : clsTask(0, 0)
{
}

void clsBurnOut_Begin_Task::execute()
{
}

void clsBurnOut_Begin_Task::draw()
{
}

clsBurnOut_End_Task::clsBurnOut_End_Task() : clsTask(0, 0)
{
}

void clsBurnOut_End_Task::draw()
{
}

clsBurnOut_End_Task::~clsBurnOut_End_Task()
{
}
