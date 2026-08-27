#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2Misc.hpp"
#include "usr/local/sce/ee/gcc/ee/lib/libc/vsprintfr.h"
#include "usr/local/sce/ee/lib/libkernl/kprintf2.h"

static c8 tac8UnionVargBuff[256];

void OrF32(c8* pc8FmtIn, ...)
{
    c8* sVlist = reinterpret_cast<c8*>(&pc8FmtIn) + 4;
    vsprintf(tac8UnionVargBuff, pc8FmtIn, sVlist);
    scePrintf(tac8UnionVargBuff);
}
