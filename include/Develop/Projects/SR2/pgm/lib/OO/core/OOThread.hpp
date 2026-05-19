#ifndef OOTHREAD_HPP
#define OOTHREAD_HPP
#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOSemaphore.hpp"

// total size: 0x28
class clsOOThread {
public:
    // total size: 0x8
    class _EntryArg {
    public:
        clsOOThread* pcExecThread; // offset 0x0, size 0x4
        void* pvArg;               // offset 0x4, size 0x4
    };

    clsOOThread();
    virtual ~clsOOThread() {}
    virtual void wait(u32 u32Param1) {}

    void deleteInstance(clsOOThread* pcParam1) {}
    static void delayThread(u32 u32Param1) {}

    static clsOOThread* (*s_pfCreateFunc)();
    static void (*s_pfDelayFunc)(u32);
    static void (*s_pfSleepFunc)();

    void* (*m_pfEntry)(class _EntryArg*); // offset 0x4, size 0x4
    void* m_pvArg;                        // offset 0x8, size 0x4
    void* m_pvRet;                        // offset 0xC, size 0x4
    u8* m_pu8StackAddr;                   // offset 0x10, size 0x4
    s32 m_s32StackSize;                   // offset 0x14, size 0x4
    s32 m_s32Priority;                    // offset 0x18, size 0x4
    u8 m_bIsCreate;                       // offset 0x1C, size 0x1
    clsOOSemaphore* m_pcSema;             // offset 0x20, size 0x4
    u8 m_bIsRun;                          // offset 0x24, size 0x1
};

#endif // OOTHREAD_HPP
