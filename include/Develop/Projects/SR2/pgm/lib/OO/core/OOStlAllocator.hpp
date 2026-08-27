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
class clsOOStlAllocator {
public:
    clsOOHeapFragment* m_pcHeap; // offset 0x0, size 0x4

    clsOOStlAllocator() {}
    clsOOStlAllocator(clsOOHeapFragment& rcHeap) : m_pcHeap(&rcHeap) {}

    template <class U>
    clsOOStlAllocator(const clsOOStlAllocator<U>& rhs) : m_pcHeap(rhs.m_pcHeap)
    {
    }

    template <class U>
    clsOOStlAllocator(const clsOOStlAllocator<U>& rhs, void*) : m_pcHeap(rhs.m_pcHeap)
    {
    }

    T* allocate(u32 count)
    {
        return static_cast<T*>(
            m_pcHeap->_MallocHi(sizeof(T) * count, clsOOHeapFragment::m_tos32DefAlign));
    }

    clsOOHeapFragment* getHeap() const { return m_pcHeap; }

    u32 max_size() const { return 0xffffffffu / sizeof(T); }

    void deallocate(T* ptr, u32)
    {
        if (ptr != 0) {
            getHeap()->___FreeHi(ptr);
        }
    }

    void construct(T* ptr, const T& value)
    {
        if (ptr != 0) {
            *ptr = value;
        }
    }
    void destroy(T* ptr) { ptr->~T(); }
};
} // namespace oostd

#endif // OOSTLALLOCATOR_HPP
