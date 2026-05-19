#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2Peripheral.hpp"

f32 MAX_PAD_ANALOG;

namespace {

static s8 toas8MultiPadConnectTbl[4][8] = {
    {0, -1, -1, -1, 1, -1, -1, -1},
    {0, -1, -1, -1, 1, -1, -1, -1},
    {0, -1, -1, -1, 1, 2, 3, -1},
    {0, -1, -1, -1, 1, 2, 3, -1},
};
static u8 toau8RumblePattern[2][2] = {
    {0, 0},
    {1, 140},
};
static u8 tau8ScePadBuf[2][4][32];
static u8 (*tpu8ScePadBuf)[32];
static u8 (*tpu8ScePadBufLast)[32];
static __int128 tau128ScePadDmaBuf[8][16];

} // namespace

::stcPeripheral clsPfPeripheral::m_asPeripheral[4];

clsPfPeripheral::clsPfPeripheral()
{
}

void clsPfPeripheral::reinit()
{
}

void clsPfPeripheral::destroy()
{
}

void clsPfPeripheral::read()
{
}

void clsPfPeripheral::setRumble(u32 u32NoI, u32 u32FrameIn)
{
}

void clsPfPeripheral::setAllRumble(u32 u32FrameI, s32 s32PadNumI)
{
}

void clsPfPeripheral::setConfigueDisableAllRumble(bool bI)
{
}

u8 clsPfPeripheral::getConfigueDisableAllRumble()
{
    return 0;
}

u8 clsPfPeripheral::isCheckingAll()
{
    return 0;
}

s32 clsPfPeripheral::getActiveTrigNo(u32 u32PI)
{
    return 0;
}
