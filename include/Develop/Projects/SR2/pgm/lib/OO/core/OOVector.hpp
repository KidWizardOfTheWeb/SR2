#ifndef OOVECTOR_HPP
#define OOVECTOR_HPP

#include "types.h"

// MWCC PS2 std::vector stub (pointer-element instantiation, size 0xC).
// Full template definition lives in the standard library.
class vector {
public:
    u32 _capacity; // 0x0, size 0x4
    u32 _size;     // 0x4, size 0x4
    void* _data;   // 0x8, size 0x4
};

// total size: 0x10 (vtptr 0x4 + vector 0xC)
class clsOOVector : public vector {
public:
    virtual ~clsOOVector() {}
};

// Template stubs for function-signature mangling only.
// The flat 'class vector' above is used for struct member layout.
namespace std {
template <class T>
class allocator {};
template <class T, class A>
class vector {
public:
    u32 _capacity;
    u32 _size;
    T* _data;
};
} // namespace std

namespace oostd {
template <class T, class A>
class clsOOVector {};
} // namespace oostd

#endif // OOVECTOR_HPP
