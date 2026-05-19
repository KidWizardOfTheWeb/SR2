#include "Develop/Projects/SR2/pgm/src/Effect/Post/GravityWave/PS2_GravityWave.hpp"

namespace nspGravityWave {

u64 tau64GsPacket_Capture_NTSC[11][2];
u64 tau64GsPacket_Capture_PAL[11][2];
u64 tau64GsPacket_DrawNega_NTSC[9][2];
u64 tau64GsPacket_DrawNega_PAL[9][2];

} // namespace nspGravityWave

clsGravityWave_Task::clsGravityWave_Task(u32 u32PrioI, s32 s32FlgI) : clsBaseGravityWave_Task(0, 0)
{
} // [verify params from ASM]

void clsGravityWave_Task::initModel(clsModelType_OB_TX_MO_MA_MF& rcModel, u32 u32Param)
{
}

void clsGravityWave_Task::drawNega(u32 u32v)
{
}

void clsGravityWave_Task::captureFullScreen()
{
}

void clsGravityWave_Task::replaceMorphUV(NNS_OBJECT* psMorphObj, u32 u32v)
{
}

void clsGravityWave_Task::drawOrthoModel(u32 u32v, clsModelType_OB_TX_MO_MA_MF& rcModel)
{
}

void clsGravityWave_Task::execute()
{
}
