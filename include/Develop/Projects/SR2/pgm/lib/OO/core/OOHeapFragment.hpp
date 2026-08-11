#ifndef OOHEAPFRAGMENT_HPP
#define OOHEAPFRAGMENT_HPP
#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2Semaphore.hpp"

// total size: 0x10
struct stcFree {
    stcFree* m_psBackAddr; // offset 0x0, size 0x4
    stcFree* m_psNextAddr; // offset 0x4, size 0x4
    u32 m_u32FreeSize;     // offset 0x8, size 0x4
    u32 m_u32PreGap;       // offset 0xC, size 0x4
};

// total size: 0x34
class clsOOHeapFragment {
public:
    clsOOHeapFragment();
    virtual ~clsOOHeapFragment();
    virtual void DumpHi_Debug() const;

    stcFree* m_psAddrLo;                    // offset 0x4, size 0x4
    stcFree* m_psDefaultAddrLo;             // offset 0x8, size 0x4
    stcFree* m_psAddrHi;                    // offset 0xC, size 0x4
    stcFree* m_psDefaultAddrHi;             // offset 0x10, size 0x4
    s32 m_s32AllRestSize;                   // offset 0x14, size 0x4
    s32 m_s32AllocSizeLo;                   // offset 0x18, size 0x4
    s32 m_s32AllocSizeHi;                   // offset 0x1C, size 0x4
    clsPfSemaphore m_cOOSemaphore;          // offset 0x20, size 0x8
    clsPfSemaphore m_cOOSemaphoreUpperNest; // offset 0x28, size 0x8
    u16 m_u16LoCnt_Debug;                   // offset 0x30, size 0x2
    u16 m_u16HiCnt_Debug;                   // offset 0x32, size 0x2

    void AllFree();
    void ___FreeLoFrame(void* pvFrameAddrLoI);
    void* _WorstFitMallocHi(u32 u32SizeI, s32 s32AlignI);
    void* _CallocHi(u32 u32SizeI, s32 s32AlignI);
    void ___FreeHi(void* pvAddrI);
    void ___FreeLo(void* pvAddrI);
    void* _MallocHi(u32 u32SizeI, s32 s32AlignI);
    void* _CallocLo(u32 u32SizeI, s32 s32AlignI);
    void* _MallocLo(u32 u32SizeI, s32 s32AlignI);
    void Initialize(void* pvAddrLoI, void* pvAddrHiI);
    stcFree* getFreeLoFrame() const { return m_psAddrLo; }

    static s32 m_tos32DefAlign;
};

#endif // OOHEAPFRAGMENT_HPP
