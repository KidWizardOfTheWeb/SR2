#ifndef OOSTLALLOCATOR_HPP
#define OOSTLALLOCATOR_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOHeapFragment.hpp"

// total size: 0x4
class clsOOStlAllocator {
public:
    clsOOHeapFragment* m_pcHeap; // offset 0x0, size 0x4
};

// Template stub for function-signature mangling only (namespace-qualified form).
namespace oostd {
template <class T>
class clsOOStlAllocator {};
} // namespace oostd

#endif // OOSTLALLOCATOR_HPP
