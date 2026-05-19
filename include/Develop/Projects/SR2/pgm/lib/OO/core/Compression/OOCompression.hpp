#ifndef OOCOMPRESSION_HPP
#define OOCOMPRESSION_HPP
#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOHeapFragment.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOSemaphore.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOBuffer.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOThread.hpp"

enum execAttr {
    ATTR_DBL_BUF = 1,
    ATTR_MULTI_BUF = 2,
    ATTR_MULTI_RING_BUF = 3,
};

// total size: 0x4
class clsOOCompObj {
public:
    virtual ~clsOOCompObj() {}
};

// total size: 0x4C
class clsOOCompression {
public:
    enum execMode {
        EXEC_SYNC = 0,
        EXEC_ASYNC = 1,
    };

    virtual ~clsOOCompression() {}

    static clsOOHeapFragment __dummy_heap;
    static s32 s_s32CompThPri;
    static s32 s_s32ObjThPri;

    clsOOCompression() : m_rcHeap(__dummy_heap) {}

    void init();
    void clearObject() {}
    s32 execDoubleBuffer() { return 0; }
    s32 execMultiBuffer() { return 0; }
    s32 execMultiRingBuffer() { return 0; }
    static void* execComp(const clsOOThread::_EntryArg* psArg);
    static void* doneCompObjTh(const clsOOThread::_EntryArg* psArg) { return 0; }
    static void initSetting(s32 s32CompThreadPri, s32 s32ObjThreadPri);
    s32 __startComp(clsOOBuffer& rcDstBuf, clsOORingBuffer& rcSrcBuf, execMode eMode);

    clsOOHeapFragment& m_rcHeap;     // offset 0x4, size 0x4
    clsOOVector m_vecCompObj;        // offset 0x8, size 0x10
    clsOOSemaphore* m_pcSema;        // offset 0x18, size 0x4
    clsOOThread* m_pcThread;         // offset 0x1C, size 0x4
    s32 m_vs32ExecRes;               // offset 0x20, size 0x4
    u32 m_vu32IsAbort;               // offset 0x24, size 0x4
    u8 m_vbIsRegistering;            // offset 0x28, size 0x1
    u8 m_vbIsDone;                   // offset 0x29, size 0x1
    execAttr m_eExecAttribute;       // offset 0x2C, size 0x4
    u8* m_u8StackAddr;               // offset 0x30, size 0x4
    u32 m_u32WorkBufSize;            // offset 0x34, size 0x4
    u8 m_bIsCompression;             // offset 0x38, size 0x1
    clsOOBuffer* m_pcSrcNormalBuf;   // offset 0x3C, size 0x4
    clsOORingBuffer* m_pcSrcRingBuf; // offset 0x40, size 0x4
    clsOOBuffer* m_pcDstNormalBuf;   // offset 0x44, size 0x4
    clsOORingBuffer* m_pcDstRingBuf; // offset 0x48, size 0x4
};

#endif // OOCOMPRESSION_HPP
