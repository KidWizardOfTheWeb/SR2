#ifndef HKARRAY_HPP
#define HKARRAY_HPP

#include "types.h"

// Havok DWARF flattens hkArray<T> specializations to the unqualified hkArray name.
template <typename T>
class hkArray {
public:
    hkArray() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    hkArray(T* pData, s32 s32Size, s32 s32Capacity)
        : m_data(pData), m_size(s32Size), m_capacityAndFlags(0x80000000 | s32Capacity)
    {
    }
    ~hkArray() { releaseMemory(); }

    void releaseMemory()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0) {
            delete[] m_data;
        }
        m_data = 0;
        m_size = 0;
        m_capacityAndFlags = 0x80000000;
    }

    s32 getSize() const { return m_size; }

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
        T* pData = new T[s32NewCapacity];
        for (s32 i = 0; i < m_size; i++) {
            pData[i] = m_data[i];
        }
        if ((m_capacityAndFlags & 0x80000000) == 0) {
            delete[] m_data;
        }
        m_data = pData;
        m_capacityAndFlags = s32NewCapacity;
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

    void pushBack(const T& rValue)
    {
        if (m_size == (m_capacityAndFlags & 0x3FFFFFFF)) {
            reserve(m_size + 1);
        }
        m_data[m_size] = rValue;
        m_size++;
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

// Havok DWARF flattens hkInplaceArray<T, N> specializations to hkInplaceArray.
template <typename T, s32 Capacity>
class hkInplaceArray : public hkArray<T> {
public:
    hkInplaceArray() : hkArray<T>(m_storage, 0, Capacity) { this->m_size = 0; }
    ~hkInplaceArray();

    T m_storage[Capacity];
};

#endif // HKARRAY_HPP
