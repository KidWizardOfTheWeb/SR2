#ifndef OOVECTOR_HPP
#define OOVECTOR_HPP

#include "types.h"

// total size: 0xC
class vector {
public:
    u32 _capacity; // offset 0x0, size 0x4
    u32 _size;     // offset 0x4, size 0x4
    void* _data;   // offset 0x8, size 0x4
};

// total size: 0x10 (vtptr 0x4 + vector 0xC)
class clsOOVector : public vector {
public:
    virtual ~clsOOVector() {}
};

namespace std {

struct forward_iterator_tag {};

template <class T>
class allocator {};

// total size: 0x4
template <class Vector, class Pointer>
class __wrap_iterator {
public:
    typedef typename Vector::value_type value_type;
    typedef value_type& reference;

    Pointer it_; // offset 0x0, size 0x4

    __wrap_iterator() {}
    explicit __wrap_iterator(const Pointer& p) : it_(p) {}

    const Pointer& base() const { return it_; }
    Pointer operator->() const { return it_; }
    reference operator*() const { return *it_; }
    __wrap_iterator& operator++()
    {
        ++it_;
        return *this;
    }
    __wrap_iterator operator++(int)
    {
        __wrap_iterator tmp(*this);
        ++it_;
        return tmp;
    }
    __wrap_iterator& operator--()
    {
        --it_;
        return *this;
    }
    __wrap_iterator& operator+=(int n)
    {
        it_ += n;
        return *this;
    }
    __wrap_iterator operator+(int n) const { return __wrap_iterator(it_ + n); }
    __wrap_iterator operator-(int n) const
    {
        Pointer p = it_;
        p += -n;
        return __wrap_iterator(p);
    }
};

template <class V, class P>
inline bool operator==(const __wrap_iterator<V, P>& lhs, const __wrap_iterator<V, P>& rhs)
{
    return lhs.it_ == rhs.it_;
}

template <class V, class P>
inline bool operator!=(const __wrap_iterator<V, P>& lhs, const __wrap_iterator<V, P>& rhs)
{
    return !(lhs.base() == rhs.base());
}

// total size: 0xC
template <class T, class A>
class __vector_deleter {
public:
    u32 _capacity; // offset 0x0, size 0x4
    u32 _size;     // offset 0x4, size 0x4
    T* _data;      // offset 0x8, size 0x4

    __vector_deleter() : _capacity(0), _size(0), _data(0) {}
    void clear();
    ~__vector_deleter();
};

// total size: 0xC
template <class T, class A, int N>
class __vector_imp : public __vector_deleter<T, A> {
public:
    void reserve(u32);
    void insert(T*, u32, const T&);

    template <class Iter>
    void init(Iter, Iter, forward_iterator_tag);

    template <class Iter>
    void do_assign(Iter, Iter, forward_iterator_tag);
};

// total size: 0xC
template <class T, class A>
class vector : public __vector_imp<T, A, 0> {
public:
    typedef T value_type;
    typedef __wrap_iterator<vector<T, A>, T*> iterator;

    iterator begin() { return iterator(this->_data); }
    iterator end() { return iterator(this->_data + this->_size); }
    void clear() { __vector_deleter<T, A>::clear(); }
};

template <class Iterator, class Predicate>
inline Iterator find_if(Iterator first, Iterator last, const Predicate& predicate)
{
    while (first != last && !predicate(*first)) {
        ++first;
    }
    return first;
}

template <class Iterator, class T>
inline Iterator find(Iterator first, Iterator last, const T& value)
{
    while (first != last && !(*first == value)) {
        ++first;
    }
    return first;
}

} // namespace std

namespace oostd {
template <class T, class A>
class clsOOVector {};
} // namespace oostd

#endif // OOVECTOR_HPP
