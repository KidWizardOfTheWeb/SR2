#include "Develop/Projects/SR2/pgm/src/System/NewDelete.hpp"

static void* tNew(u32 u32SizeI, s32 s32AlignI, u32 u32NewFlagI);

void* operator new(u32 u32SizeI)
{
    return 0;
}

void* operator new(u32 u32SizeI, u32 u32NewFlagI)
{
    return 0;
}

void* operator new(u32 u32SizeI, s32 s32AlignI, u32 u32NewFlagI, u32 u32Param4)
{
    return 0;
}

void* operator new[](u32 u32SizeI)
{
    return 0;
}

void* operator new[](u32 u32SizeI, u32 u32NewFlagI)
{
    return 0;
}

static void* tNew(u32 u32SizeI, s32 s32AlignI, u32 u32NewFlagI)
{
    return 0;
}

void* operator new[](u32 u32SizeI, s32 s32AlignI, u32 u32NewFlagI, u32 u32Param4)
{
    return 0;
}

void operator delete(void* pv)
{
}

void operator delete[](void* pv)
{
}
