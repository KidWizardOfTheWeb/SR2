#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2System.hpp"
#include "usr/local/sce/ee/lib/libcdvd/cdvd000.h"

extern unsigned long pxg_scissor_addr[];

clsPfSystem::clsPfSystem()
{
}

s32 clsPfSystem::tVBlanking_CallBack(s32 s32CaIn)
{
    return 0;
}

void clsPfSystem::getNowDateTime(stcDateTime* psNow)
{
}

void clsPfSystem::VWait()
{
}

void clsPfSystem::setViewPort(u32 u32I)
{
}
