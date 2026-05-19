#include "Develop/Projects/SR2/pgm/lib/OO/core/OOHeapFragment.hpp"

s32 clsOOHeapFragment::m_tos32DefAlign = 16;

clsOOHeapFragment::clsOOHeapFragment()
{
}

clsOOHeapFragment::~clsOOHeapFragment()
{
}

void clsOOHeapFragment::Initialize(void* pvAddrLoI, void* pvAddrHiI)
{
}

void* clsOOHeapFragment::_MallocLo(u32 u32SizeI, s32 s32AlignI)
{
    return 0;
}

void* clsOOHeapFragment::_CallocLo(u32 u32SizeI, s32 s32AlignI)
{
    return 0;
}

void* clsOOHeapFragment::_MallocHi(u32 u32SizeI, s32 s32AlignI)
{
    return 0;
}

void clsOOHeapFragment::___FreeLo(void* pvAddrI)
{
}

void clsOOHeapFragment::___FreeHi(void* pvAddrI)
{
}

void* clsOOHeapFragment::_CallocHi(u32 u32SizeI, s32 s32AlignI)
{
    return 0;
}

void* clsOOHeapFragment::_WorstFitMallocHi(u32 u32SizeI, s32 s32AlignI)
{
    return 0;
}

void clsOOHeapFragment::___FreeLoFrame(void* pvFrameAddrLoI)
{
}

void clsOOHeapFragment::AllFree()
{
}

void clsOOHeapFragment::DumpHi_Debug() const
{
}
