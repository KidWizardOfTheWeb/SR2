#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2Misc.hpp"

extern "C" s32 scePrintf(const c8* pc8Fmt);
extern "C" s32 vsprintf(c8* pc8Dst, const c8* pc8Fmt, c8* sVlist);

static c8 tac8UnionVargBuff[256];

void OrF32(c8* pc8FmtIn, ...)
{
    c8* sVlist = reinterpret_cast<c8*>(&pc8FmtIn) + 4;
    vsprintf(tac8UnionVargBuff, pc8FmtIn, sVlist);
    scePrintf(tac8UnionVargBuff);
}
