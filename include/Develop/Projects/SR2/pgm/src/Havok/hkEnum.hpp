#ifndef HKENUM_HPP
#define HKENUM_HPP

#include "types.h"

template <typename TEnum, typename TStorage = TEnum>
class hkEnum {
public:
    void operator=(TEnum sParam1) { m_storage = static_cast<TStorage>(sParam1); }

    operator TEnum() const { return static_cast<TEnum>(m_storage); }

    TStorage m_storage; // offset 0x0
};

#endif // HKENUM_HPP
