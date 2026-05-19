#ifndef SCRIPTHEAP_HPP
#define SCRIPTHEAP_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOHeapFragment.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "types.h"

// total size: 0x3C
class clsPfScriptHeap : public clsSingleton<clsPfScriptHeap>, public clsOOHeapFragment {
public:
    clsPfScriptHeap(u32 u32AllocateSizeI);
    virtual ~clsPfScriptHeap() {}

    void freeBuf();

    u8* m_pu8HeapTop_Hi; // offset 0x38, size 0x4
};

#endif // SCRIPTHEAP_HPP
