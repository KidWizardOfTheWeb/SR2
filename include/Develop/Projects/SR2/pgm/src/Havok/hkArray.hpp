#ifndef HKARRAY_HPP
#define HKARRAY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Havok/hkBaseObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/hkThreadMemory.hpp"

class hkArrayUtil {
public:
    static void _reserve(void*, s32, s32);
    static void _reserveMore(void*, s32);
    static void _reduce(void*, s32, c8*, s32);
};

template <typename T>
class hkArray {
public:
    hkArray() : m_data(NULL), m_size(0), m_capacityAndFlags(0x80000000) {}
    hkArray(hkFinishLoadedObjectFlag sParam1) {}
    hkArray(T* pData, s32 s32Size, s32 s32Capacity)
        : m_data(pData), m_size(s32Size), m_capacityAndFlags(0x80000000 | s32Capacity)
    {
    }
    ~hkArray() { releaseMemory(); }
    hkArray<T>& operator=(const hkArray<T>& rOther)
    {
        if (getCapacity() < rOther.m_size) {
            if ((m_capacityAndFlags & 0x80000000) == 0) {
                hkThreadMemory::s_threadMemoryInstance->deallocateChunk(
                    m_data, getCapacity() * sizeof(T), HK_MEMORY_CLASS_ARRAY);
            }
            m_data = static_cast<T*>(hkThreadMemory::s_threadMemoryInstance->allocateChunk(
                rOther.m_size * sizeof(T), HK_MEMORY_CLASS_ARRAY));
            m_capacityAndFlags = rOther.m_size | (m_capacityAndFlags & 0x40000000);
        }

        const s32 s32Size = rOther.m_size;
        m_size = s32Size;
        const T* pSource = rOther.m_data;
        T* pDestination = m_data;
        for (s32 i = 0; i < s32Size; ++i) {
            pDestination[i] = pSource[i];
        }
        return *this;
    }

    void clearAndDeallocate()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0) {
            hkThreadMemory::s_threadMemoryInstance->deallocateChunk(
                m_data, getCapacity() * sizeof(T), HK_MEMORY_CLASS_ARRAY);
        }
        m_data = NULL;
        m_size = 0;
        m_capacityAndFlags = (m_capacityAndFlags & 0x40000000) | 0x80000000;
    }

    void releaseMemory()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0) {
            hkThreadMemory::s_threadMemoryInstance->deallocateChunk(
                m_data, getCapacity() * sizeof(T), HK_MEMORY_CLASS_ARRAY);
        }
    }

    s32 getSize() const { return m_size; }
    s32 getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }

    s32 indexOf(const T& rValue) const
    {
        for (s32 s32Index = 0; s32Index < m_size; ++s32Index) {
            if (m_data[s32Index] == rValue) {
                return s32Index;
            }
        }
        return -1;
    }

    void swap(hkArray<T>& rOther)
    {
        T* pData = m_data;
        s32 s32Size = m_size;
        s32 s32CapacityAndFlags = m_capacityAndFlags;
        m_data = rOther.m_data;
        m_size = rOther.m_size;
        m_capacityAndFlags = rOther.m_capacityAndFlags;
        rOther.m_data = pData;
        rOther.m_size = s32Size;
        rOther.m_capacityAndFlags = s32CapacityAndFlags;
    }

    void reserve(s32 s32Capacity)
    {
        if ((m_capacityAndFlags & 0x3FFFFFFF) >= s32Capacity) {
            return;
        }
        s32 s32NewCapacity = (m_capacityAndFlags & 0x3FFFFFFF) * 2;
        if (s32NewCapacity < s32Capacity) {
            s32NewCapacity = s32Capacity;
        }
        hkArrayUtil::_reserve(this, s32NewCapacity, sizeof(T));
    }

    void insertAt(s32 s32Index, const T* pValues, s32 s32Count)
    {
        s32 s32NewSize = m_size + s32Count;
        reserve(s32NewSize);
        for (s32 i = m_size - 1; i >= s32Index; i--) {
            m_data[i + s32Count] = m_data[i];
        }
        for (s32 i = 0; i < s32Count; i++) {
            m_data[s32Index + i] = pValues[i];
        }
        m_size = s32NewSize;
    }

    void insertAt(s32 s32Index, const T& rValue) { insertAt(s32Index, &rValue, 1); }

    // RECONSTRUCTED: accessor name.
    T& expandOne()
    {
        if (m_size == (m_capacityAndFlags & 0x3FFFFFFF)) {
            hkArrayUtil::_reserveMore(this, sizeof(T));
        }
        return m_data[m_size++];
    }

    void pushBack(const T& rValue)
    {
        if (m_size == (m_capacityAndFlags & 0x3FFFFFFF)) {
            hkArrayUtil::_reserveMore(this, sizeof(T));
        }
        m_data[m_size++] = rValue;
    }

    void removeAt(s32 s32Index)
    {
        --m_size;
        m_data[s32Index] = m_data[m_size];
    }

    void removeAtAndCopy(s32 s32Index)
    {
        --m_size;
        for (; s32Index < m_size; ++s32Index) {
            m_data[s32Index] = m_data[s32Index + 1];
        }
    }

    T& back() { return m_data[m_size - 1]; }

    T* m_data;              // offset 0x0, size 0x4
    s32 m_size;             // offset 0x4, size 0x4
    s32 m_capacityAndFlags; // offset 0x8, size 0x4
};

// total size: 0x200
class hkAgentNnSector {
public:
    u8 m_data[512]; // offset 0x0, size 0x200
};

template <typename T, s32 Capacity>
class hkInplaceArray : public hkArray<T> {
public:
    hkInplaceArray() : hkArray<T>(m_storage, 0, Capacity) { this->m_size = 0; }
    ~hkInplaceArray();

    T m_storage[Capacity];
};

#endif // HKARRAY_HPP
