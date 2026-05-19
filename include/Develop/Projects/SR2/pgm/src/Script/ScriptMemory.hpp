#ifndef SCRIPTMEMORY_HPP
#define SCRIPTMEMORY_HPP

#include "types.h"

class clsScriptMemory {
public:
    void init();
    ~clsScriptMemory();
    void initHeap();
    void setInitEndHeap();
    void setHeapType(u32 u32CutNo);
    void* HeapMallocFlag(u32 u32Size);
    void HeapFreeFlag(void* pvBuf, bool bNormal);

    void* getMainFile() { return MainFile; }
    void* getSubFile(u8 u8Param1) { return SubFile[u8Param1]; }
    void* getFontFile() { return FontFile; }
    void** getMainFileAdr() { return &MainFile; }
    void** getSubFileAdr(u8 u8Param1) { return &SubFile[u8Param1]; }
    void** getFontFileAdr() { return &FontFile; }

    static u8 HeapType;
    static u8 HeapUsed;
    static void* MainFile;
    static void* FontFile;
    static void* MainHeapLoStart;
    static void* MainHeapFileEnd;
    static void* MainHeapInitEnd;
    static void* SubFile[2];
    static void* SubHeapLoStart;
    static void* SubHeapFileEnd;
    static void* SubHeapInitEnd;
};

#endif // SCRIPTMEMORY_HPP
