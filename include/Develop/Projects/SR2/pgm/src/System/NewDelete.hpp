#ifndef NEWDELETE_HPP
#define NEWDELETE_HPP

#include "types.h"

inline void* operator new(u32, void* ptr)
{
    return ptr;
}

void* operator new(u32 u32SizeI);
void* operator new(u32 u32SizeI, u32 u32NewFlagI);
void* operator new(u32 u32SizeI, s32 s32AlignI, u32 u32NewFlagI, u32 u32Param4);
void* operator new[](u32 u32SizeI);
void* operator new[](u32 u32SizeI, u32 u32NewFlagI);
void* operator new[](u32 u32SizeI, s32 s32AlignI, u32 u32NewFlagI, u32 u32Param4);
void operator delete(void* pv);
void operator delete[](void* pv);

#endif // NEWDELETE_HPP
