#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnGraphics.hpp"

u32 u32Size;

namespace {

static u8 su8PushBuffer[3145856];
static u8 sau8CbBuf[64];
static u8 saTexDmaTagPushBuf[1048576];

} // namespace

c8* clsOOGraphics_Consumer::m_toac8ScreenModeName_Debug[14];
sceGsDBuffDc clsPfGraphics::m_tsGsDBuffDc;

clsPfGraphics::clsPfGraphics()
{
}

s32 clsPfGraphics::tVifEndCB_Debug(s32 s32Param1)
{
    return 0;
}

void clsPfGraphics::resetTextureBuffer(s32 s32SizeI, s32 s32ResidenceSizeI)
{
}

void clsPfGraphics::setVideoMode(enmScreenMode eScreenModeI)
{
}

void clsPfGraphics::updateFrameBuffer()
{
}

void clsPfGraphics::exit()
{
}

void clsPfGraphics::updatePalParam()
{
}

void clsOOGraphics_Consumer::clip2Screen(nspOOMisc::stcPoint2D_s16& rDst,
                                         const NNS_VECTOR& rSrc,
                                         s32 param) const
{
}

void clsOOGraphics_Consumer::updatePalParam()
{
}

void clsOOGraphics_Consumer::setScreenMode(enmScreenMode mode)
{
}
