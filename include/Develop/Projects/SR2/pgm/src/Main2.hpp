#ifndef MAIN2_HPP
#define MAIN2_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOHeapFragment.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Flash/OOFlashMgr.hpp"

// total size: 0x10
class clsMain {
public:
    clsMain() {}
    ~clsMain() {}

    void setReset();
    void setFreeLoFrame(void* p) {}
    void** getFreeLoFrame() { return &m_pvLocalFreeLoFrame; }
    void setTaskManWorkHeap(clsOOHeapFragment* p) {}
    void init() {}
    void reinit() const {}
    void init_Debug() const {}
    void loop() {}
    void respawn() const {}

    void* m_pvLocalFreeLoFrame;             // offset 0x0, size 0x4
    clsOOHeapFragment* m_pcTaskManWorkHeap; // offset 0x4, size 0x4
    u32 m_bSoftResetLateDone;               // offset 0x8, size 0x4
    u32 m_bSoftReset;                       // offset 0xC, size 0x4
};

// total size: 0x4
class clsOOCameraMgr {
public:
    virtual ~clsOOCameraMgr() {}
};

// total size: 0x10
class clsOODebugPrint {
public:
    virtual ~clsOODebugPrint() {}
    virtual void flush() {}

    s32 m_s32SizeW;     // offset 0x4, size 0x4
    s32 m_s32SizeH;     // offset 0x8, size 0x4
    s8 m_s8StartPointX; // offset 0xC, size 0x1
    s8 m_s8StartPointY; // offset 0xD, size 0x1
    s8 m_s8NowPosY;     // offset 0xE, size 0x1
};

// total size: 0x14
class clsPfDebugPrint : public clsSingleton<clsPfDebugPrint>, public clsOODebugPrint {
public:
    clsPfDebugPrint(s32 s32Param1, s32 s32Param2) {}
    virtual ~clsPfDebugPrint() {}
    virtual void flush() {}

    static u8 m_au8PrintBuf[25200];
};

// total size: 0x1C
class clsPfFlashMgr : public clsSingleton<clsPfFlashMgr>, public clsOOFlashMgr {
public:
    clsPfFlashMgr() {}
    virtual ~clsPfFlashMgr() {}
};

#endif // MAIN2_HPP
