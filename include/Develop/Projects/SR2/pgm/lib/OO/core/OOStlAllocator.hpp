#ifndef OOSTLALLOCATOR_HPP
#define OOSTLALLOCATOR_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOHeapFragment.hpp"
#include "Develop/Projects/SR2/pgm/src/System/NewDelete.hpp"

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

    // RECONSTRUCTED: optional alignment argument.
    T* allocate(u32 count, s32 alignment = clsOOHeapFragment::m_tos32DefAlign)
    {
        return static_cast<T*>(m_pcHeap->_MallocHi(sizeof(T) * count, alignment));
    }

    clsOOHeapFragment* getHeap() const { return m_pcHeap; }

    u32 max_size() const { return 0xffffffffu / sizeof(T); }

    void deallocate(T* ptr, u32)
    {
        if (ptr != NULL) {
            m_pcHeap->___FreeHi(ptr);
        }
    }

    void construct(T* ptr, const T& value) { new (ptr) T(value); }
    void destroy(T* ptr) { ptr->~T(); }
};
} // namespace oostd

#endif // OOSTLALLOCATOR_HPP
