#ifndef HAVOKBASE_HPP
#define HAVOKBASE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

class clsHavokBase {
public:
    static void initMemory(u32 u32Param1);
    static void resetMemory();
    static void exitMemory();

    static u8 t_cMemoryManager[0xA30];
    static void* t_pcThreadMemory;
};

extern c8 HK_KEYCODE[21];
extern u32 HK_KEYVALUE;
void tErrorReport(c8* msg);

inline void* operator new(unsigned int size, HK_MEMORY_CLASS memoryClass)
{
    void* memory = hkThreadMemory::s_threadMemoryInstance->allocateChunk(size, memoryClass);
    reinterpret_cast<hkReferencedObject*>(memory)->m_memSizeAndFlags = size;
    return memory;
}

#endif // HAVOKBASE_HPP
