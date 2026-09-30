#ifndef OOFLAG_HPP
#define OOFLAG_HPP

#include "types.h"

// RECONSTRUCTED: header placement.
template <class T>
class clsFlag {
public:
    clsFlag(T tData) : m_tData(tData) {}
    T getParam() const { return m_tData; }
    void setParam(u32 u32Data, u32 u32Mask)
    {
        m_tData = static_cast<T>((m_tData & ~u32Mask) | (u32Data & u32Mask));
    }

    T m_tData; // offset 0x0, size 0x4
};

// RECONSTRUCTED: header placement.
template <class T, class U>
const T OOCheckBit(const T& rtValue, const U& rtMask)
{
    return rtValue & rtMask;
}

template <class T, class U>
inline const bool OOCheckBitsEq(const T& rtValue, const U& rtMask)
{
    return (rtValue & rtMask) == rtMask;
}

template <class T, class U>
inline void OOSetBit(T& rtValue, const U& rtMask)
{
    rtValue |= rtMask;
}

template <class T, class U>
inline void OOClearBit(T& rtValue, const U& rtMask)
{
    rtValue &= ~rtMask;
}

#endif // OOFLAG_HPP
