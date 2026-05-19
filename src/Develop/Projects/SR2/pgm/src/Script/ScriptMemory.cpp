#include "Develop/Projects/SR2/pgm/src/Script/ScriptMemory.hpp"

u8 clsScriptMemory::HeapType;
u8 clsScriptMemory::HeapUsed;
void* clsScriptMemory::MainFile;
void* clsScriptMemory::FontFile;
void* clsScriptMemory::MainHeapLoStart;
void* clsScriptMemory::MainHeapFileEnd;
void* clsScriptMemory::MainHeapInitEnd;
void* clsScriptMemory::SubFile[2];
void* clsScriptMemory::SubHeapLoStart;
void* clsScriptMemory::SubHeapFileEnd;
void* clsScriptMemory::SubHeapInitEnd;

void clsScriptMemory::init()
{
}

clsScriptMemory::~clsScriptMemory()
{
}

void clsScriptMemory::initHeap()
{
}

void clsScriptMemory::setInitEndHeap()
{
}

void clsScriptMemory::setHeapType(u32 u32CutNo)
{
}

void* clsScriptMemory::HeapMallocFlag(u32 u32Size)
{
    return 0;
}

void clsScriptMemory::HeapFreeFlag(void* pvBuf, bool bNormal)
{
}
