#ifndef HKENUM_HPP
#define HKENUM_HPP

#include "types.h"

// Havok DWARF flattens hkEnum<TStorage> specializations to the unqualified hkEnum name.
template <typename TStorage>
class hkEnum {
public:
    TStorage m_storage; // offset 0x0
};

#endif // HKENUM_HPP
