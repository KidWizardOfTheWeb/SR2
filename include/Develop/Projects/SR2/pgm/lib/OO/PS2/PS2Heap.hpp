#ifndef PS2HEAP_HPP
#define PS2HEAP_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/GearChenge/GearTypeChange.hpp"

// total size: 0x38
class clsPfMainHeap : public clsSingleton<clsPfMainHeap>, public clsOOMainHeap {
public:
    clsPfMainHeap(u32 u32RestUsedSizeI);
    virtual ~clsPfMainHeap() {}
};

#endif // PS2HEAP_HPP
