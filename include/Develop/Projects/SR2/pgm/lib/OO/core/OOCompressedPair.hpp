#ifndef OOCOMPRESSEDPAIR_HPP
#define OOCOMPRESSEDPAIR_HPP

// RECONSTRUCTED: header ownership and helper tags.

namespace std {
template <class T>
class allocator;
template <class T>
class less;
} // namespace std

namespace Metrowerks {

template <int N>
class compile_assert;

template <>
class compile_assert<1> {
public:
    compile_assert() {}
};

namespace details {

struct copy_first_zero_second_t {};
struct copy_first_noinit_second_t {};

template <class First, class Second, int EBO>
class compressed_pair_imp;

template <class First, class Second>
class compressed_pair_imp<First, Second, 0> {
public:
    First first_;   // offset 0x0
    Second second_; // offset sizeof(First)

    compressed_pair_imp() {}
    explicit compressed_pair_imp(const First& first) : first_(first), second_() {}
    compressed_pair_imp(const First& first, const Second& second) : first_(first), second_(second)
    {
    }
    compressed_pair_imp(const First& first, copy_first_zero_second_t) : first_(first), second_() {}
    compressed_pair_imp(const First& first, copy_first_noinit_second_t) : first_(first) {}

    First& first() { return first_; }
    const First& first() const { return first_; }
    Second& second() { return second_; }
    const Second& second() const { return second_; }
};

template <class First, class Second>
class compressed_pair_imp<First, Second, 1> : private First {
public:
    Second second_; // offset 0x0

    compressed_pair_imp() : First() {}
    explicit compressed_pair_imp(const First& first) : First(first), second_() {}
    compressed_pair_imp(const First& first, const Second& second) : First(first), second_(second) {}
    compressed_pair_imp(const First& first, copy_first_zero_second_t) : First(first), second_() {}
    compressed_pair_imp(const First& first, copy_first_noinit_second_t) : First(first) {}

    First& first() { return *this; }
    const First& first() const { return *this; }
    Second& second() { return second_; }
    const Second& second() const { return second_; }
};

template <class First>
struct compressed_pair_ebo {
    enum { value = 0 };
};

template <class T>
struct compressed_pair_ebo<std::allocator<T> > {
    enum { value = 1 };
};

template <class T>
struct compressed_pair_ebo<std::less<T> > {
    enum { value = 1 };
};

} // namespace details

template <class First, class Second>
class compressed_pair
    : private details::
          compressed_pair_imp<First, Second, details::compressed_pair_ebo<First>::value> {
    typedef details::compressed_pair_imp<First, Second, details::compressed_pair_ebo<First>::value>
        Base;

public:
    compressed_pair() : Base() {}
    explicit compressed_pair(const First& first) : Base(first) {}
    compressed_pair(const First& first, const Second& second) : Base(first, second) {}
    compressed_pair(const First& first, details::copy_first_zero_second_t tag) : Base(first, tag) {}
    compressed_pair(const First& first, details::copy_first_noinit_second_t tag) : Base(first, tag)
    {
    }

    using Base::first;
    using Base::second;
};

} // namespace Metrowerks

#endif // OOCOMPRESSEDPAIR_HPP
