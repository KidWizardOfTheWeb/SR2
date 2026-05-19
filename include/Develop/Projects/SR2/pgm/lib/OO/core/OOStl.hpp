#ifndef OOSTL_HPP
#define OOSTL_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOStlAllocator.hpp"
#include "usr/local/metrowerks/PS2_Support/stl/deque.h"

class node;
class node_base;

// total size: 0x4
class generic_iterator {
    u32 i_; // offset 0x0, size 0x4
};

// total size: 0x1
class iterator {};

// total size: 0x4
class reverse_iterator : public iterator {
public:
    generic_iterator current; // offset 0x0, size 0x4
};

// total size: 0x4
class __pointer_plus_bit {
public:
    node_base* ptr_; // offset 0x0, size 0x4
};

// total size: 0x4
class anchor {
public:
    node_base* left_; // offset 0x0, size 0x4
};

// total size: 0xC
class node_base : public anchor {
public:
    node_base* right_;          // offset 0x4, size 0x4
    __pointer_plus_bit parent_; // offset 0x8, size 0x4
};

// total size: 0x1
class binary_function {};

// total size: 0x1
class less : public binary_function {};

// total size: 0x1
class value_compare : public binary_function {
public:
    less comp; // offset 0x0, size 0x1
};

template <class TFirst, class TSecond, class TReserved>
class compressed_pair_imp {
public:
    TFirst first_;       // offset 0x0
    TSecond second_;     // offset 0x4
    TReserved reserved_; // offset varies by TSecond
};

template <class TFirst, class TSecond>
class compressed_pair_imp<TFirst, TSecond, void> {
public:
    TFirst first_;   // offset 0x0
    TSecond second_; // offset 0x4
};

// total size: 0x10
class compressed_pair : private compressed_pair_imp<clsOOStlAllocator, cdeque, void> {};

// total size: 0x1
class __red_black_tree {};

// total size: 0x14
class __tree : private __red_black_tree {
public:
    // Flattened STL template variants share this unqualified DWARF name.
    u8 alloc_[0x8];      // offset 0x0, size 0x8
    u8 node_alloc_[0x8]; // offset 0x8, size 0x8
    u8 comp_[0x4];       // offset 0x10, size 0x4
};

// total size: 0x14
class set {
public:
    __tree tree_; // offset 0x0, size 0x14
};

// total size: 0x14
class clsOOSet : public set {};

// Template stubs for function-signature mangling only (namespace-qualified forms).
namespace std {
template <class T>
class less {};
} // namespace std

namespace oostd {
template <class T, class C, class A>
class clsOOSet {};
} // namespace oostd

#endif // OOSTL_HPP
