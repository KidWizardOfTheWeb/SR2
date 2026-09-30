#ifndef OOVECTOR_HPP
#define OOVECTOR_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/System/NewDelete.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOCompressedPair.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOStlAllocator.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOStl.hpp"
#include "usr/local/sce/ee/gcc/ee/lib/libc/abort.h"
#include "usr/local/sce/ee/gcc/ee/lib/libc/fprintf.h"
#include "usr/local/sce/ee/gcc/ee/lib/libc/stdio.h"

#include "usr/local/sce/ee/gcc/ee/lib/libc/memcpy.h"
#include "usr/local/sce/ee/gcc/ee/lib/libc/memmove.h"

// MWCC PS2 std::vector storage.
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
class allocator {
public:
    allocator() {}
    template <class U>
    allocator(const allocator<U>&)
    {
    }

    u32 max_size() const { return 0xffffffffu / sizeof(T); }

    T* allocate(u32 count, const void* = NULL)
    {
        T* data = static_cast<T*>(::operator new(count * sizeof(T)));
        if (data == NULL) {
            ::fprintf(stderr, "Memory allocation failure");
            ::abort();
        }
        return data;
    }

    void deallocate(T* ptr, u32) { ::operator delete(ptr); }
    void construct(T* ptr, const T& value) { new (ptr) T(value); }
    void destroy(T* ptr) { ptr->~T(); }
};

// RECONSTRUCTED: allocation helper.
template <class T>
inline T* __vector_allocate_signed_distance(u32 count)
{
    s64 signedCount = static_cast<s32>(count);
    T* data = static_cast<T*>(::operator new(static_cast<u32>(signedCount) * sizeof(T)));
    if (data == NULL) {
        ::fprintf(stderr, "Memory allocation failure");
        ::abort();
    }
    return data;
}

// RECONSTRUCTED: iterator traits.
template <class Pointer>
struct __wrap_iterator_reference;
template <class T>
struct __wrap_iterator_reference<T*> {
    typedef T& type;
};

// total size: 0x4
template <class Vector, class Pointer>
class __wrap_iterator {
public:
    typedef typename Vector::value_type value_type;
    typedef typename __wrap_iterator_reference<Pointer>::type reference;

    Pointer it_; // offset 0x0, size 0x4

    __wrap_iterator() {}
    explicit __wrap_iterator(const Pointer& p) : it_(p) {}
    template <class OtherPointer>
    __wrap_iterator(const __wrap_iterator<Vector, OtherPointer>& rhs) : it_(rhs.base())
    {
    }

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

template <class V, class P1, class P2>
inline bool operator!=(const __wrap_iterator<V, P1>& lhs, const __wrap_iterator<V, P2>& rhs)
{
    return !(lhs.base() == rhs.base());
}

// total size: 0xC
template <class T, class A>
class __vector_deleter {
public:
    typedef ::Metrowerks::compressed_pair<A, u32> capacity_pair;
    capacity_pair capacity_; // offset 0x0, size 0x4
    u32 size_;               // offset 0x4, size 0x4
    T* data_;                // offset 0x8, size 0x4

    A& alloc() { return capacity_.first(); }
    const A& alloc() const { return capacity_.first(); }
    u32& capacity() { return capacity_.second(); }
    const u32& capacity() const { return capacity_.second(); }

    __vector_deleter()
    {
        capacity_.second() = 0;
        size_ = 0;
        data_ = NULL;
    }
    explicit __vector_deleter(const A& allocator) : capacity_(allocator), size_(0), data_(NULL) {}
    void clear();
    T*& data() { return data_; }
    T* const& data() const { return data_; }
    ~__vector_deleter();
};

// total size: 0xC
template <class T, class A>
class __vector_pod {
public:
    typedef ::Metrowerks::compressed_pair<A, u32> capacity_pair;
    capacity_pair capacity_;
    u32 size_;
    T* data_;

    A& alloc() { return capacity_.first(); }
    const A& alloc() const { return capacity_.first(); }
    u32& capacity() { return capacity_.second(); }
    const u32& capacity() const { return capacity_.second(); }

    __vector_pod()
    {
        capacity() = 0;
        size_ = 0;
        data_ = NULL;
    }

    explicit __vector_pod(const A& allocator) : capacity_(allocator), size_(0), data_(NULL) {}
    __vector_pod(const __vector_pod& rhs)
    {
        capacity() = 0;
        size_ = 0;
        data_ = NULL;
        init(static_cast<const T*>(rhs.data_),
             static_cast<const T*>(rhs.data_) + rhs.size_,
             forward_iterator_tag());
    }
    __vector_pod& operator=(const __vector_pod& rhs)
    {
        if (this != &rhs)
            do_assign(static_cast<const T*>(rhs.data_),
                      static_cast<const T*>(rhs.data_) + rhs.size_,
                      forward_iterator_tag());
        return *this;
    }
    ~__vector_pod()
    {
        if (data_ != NULL)
            alloc().deallocate(data_, capacity());
    }
    void clear() { size_ = 0; }
    template <class Iter>
    void init(Iter, Iter, forward_iterator_tag);
    template <class Iter>
    void do_assign(Iter, Iter, forward_iterator_tag);
    void insert(T*, u32, const T&);
    void reserve(u32 requestedCapacity);
    void pop_back() { --size_; }
    T& at(u32 index);
    const T& at(u32 index) const;
};

// total size: 0xC
template <class T, class A, int N>
class __vector_imp : private __vector_deleter<T, A> {
    typedef __vector_deleter<T, A> Base;

protected:
    using Base::alloc;
    using Base::capacity;
    using Base::clear;
    using Base::data;
    using Base::data_;
    using Base::size_;

public:
    __vector_imp() : Base() {}
    explicit __vector_imp(const A& allocator) : Base(allocator) {}
    // RECONSTRUCTED: capacity accessor.
    u32 capacity_value() const { return Base::capacity(); }
    void reserve(u32);
    void pop_back()
    {
        --size_;
        alloc().destroy(data_ + size_);
    }
    T& at(u32 index)
    {
        if (index >= size_) {
            ::fprintf(stderr, "vector::at index out of range");
            ::abort();
        }
        return data_[index];
    }
    const T& at(u32 index) const
    {
        if (index >= size_) {
            ::fprintf(stderr, "vector::at index out of range");
            ::abort();
        }
        return data_[index];
    }
    void insert(T*, u32, const T&);

    template <class Iter>
    void init(Iter, Iter, forward_iterator_tag);

    template <class Iter>
    void do_assign(Iter, Iter, forward_iterator_tag);
};

// RECONSTRUCTED: N is unresolved.
template <class T, class A, int N>
class __vector_imp<T*, A, N> : private __vector_pod<u32, typename __allocator_rebind<A, u32>::type>,
                               private ::Metrowerks::compile_assert<sizeof(T*) == sizeof(u32)> {
    typedef __vector_pod<u32, typename __allocator_rebind<A, u32>::type> Base;

protected:
    using Base::clear;
    using Base::size_;
    T** data() { return reinterpret_cast<T**>(Base::data_); }
    T* const* data() const { return reinterpret_cast<T* const*>(Base::data_); }

public:
    __vector_imp() : Base() {}
    explicit __vector_imp(const A& rcAllocator)
        : Base(typename __allocator_rebind<A, u32>::type(rcAllocator))
    {
    }
    using Base::pop_back;
    using Base::reserve;
    T*& at(u32 index) { return reinterpret_cast<T*&>(Base::at(index)); }
    T* const& at(u32 index) const { return reinterpret_cast<T* const&>(Base::at(index)); }
    void insert(T** position, u32 count, T* const& value)
    {
        Base::insert(reinterpret_cast<u32*>(position), count, reinterpret_cast<const u32&>(value));
    }
    template <class Iter>
    void init(Iter first, Iter last, forward_iterator_tag tag)
    {
        Base::init(reinterpret_cast<const u32*>(first), reinterpret_cast<const u32*>(last), tag);
    }
    template <class Iter>
    void do_assign(Iter first, Iter last, forward_iterator_tag tag)
    {
        Base::do_assign(
            reinterpret_cast<const u32*>(first), reinterpret_cast<const u32*>(last), tag);
    }
};

template <class T, class A>
class vector : private __vector_imp<T, A, 0> {
    typedef __vector_imp<T, A, 0> Base;

public:
    typedef T value_type;
    typedef __wrap_iterator<vector<T, A>, T*> iterator;
    typedef __wrap_iterator<vector<T, A>, const T*> const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;

    vector() : Base() {}
    explicit vector(const A& allocator) : Base(allocator) {}
    vector(const vector& rhs) : Base()
    {
        const T* first = rhs.data();
        forward_iterator_tag tag;
        this->init(first, first + rhs.size(), tag);
    }
    vector& operator=(const vector& rhs)
    {
        if (this != &rhs) {
            const T* first = rhs.data();
            forward_iterator_tag tag;
            this->do_assign(first, first + rhs.size(), tag);
        }
        return *this;
    }

    T& operator[](u32 index) { return this->data()[index]; }
    const T& operator[](u32 index) const { return this->data()[index]; }
    void push_back(const T& value) { Base::insert(this->data() + this->size_, 1, value); }
    T& back() { return *rbegin(); }
    reverse_iterator rbegin() { return reverse_iterator(end()); }
    void pop_back() { Base::pop_back(); }

    u32 size() const { return this->size_; }

    iterator begin() { return iterator(this->data()); }
    iterator end() { return iterator(this->data() + this->size_); }
    T& at(u32 index) { return Base::at(index); }
    const T& at(u32 index) const { return Base::at(index); }
    void clear() { Base::clear(); }
    using Base::insert;
    void reserve(u32 requestedCapacity) { Base::reserve(requestedCapacity); }
};

template <class BidirectionalIterator1, class BidirectionalIterator2>
inline void __vector_copy_backward_impl(BidirectionalIterator1 first,
                                        BidirectionalIterator1 last,
                                        BidirectionalIterator2 result)
{
    while (first < last) {
        --last;
        --result;
        *result = *last;
    }
}

template <class BidirectionalIterator1, class BidirectionalIterator2>
inline void __vector_copy_backward(BidirectionalIterator1 first,
                                   BidirectionalIterator1 last,
                                   BidirectionalIterator2 result)
{
    __vector_copy_backward_impl(first, last, result);
}

struct __vector_copy_loop_tag {};
struct __vector_copy_mem_tag {};

// RECONSTRUCTED: copy traits.
template <class T>
struct __vector_copy_selector {
    typedef __vector_copy_loop_tag type;
};

template <>
struct __vector_copy_selector<u16> {
    typedef __vector_copy_mem_tag type;
};

template <class T>
inline void __vector_copy_backward_dispatch(T* first, T* last, T* result, __vector_copy_loop_tag)
{
    while (first < last) {
        --last;
        --result;
        *result = *last;
    }
}

template <class T>
inline void __vector_copy_backward_dispatch(T* first, T* last, T* result, __vector_copy_mem_tag)
{
    ::memmove(result - (last - first), first, (last - first) * sizeof(T));
}

template <class T>
inline void __vector_copy_backward(T* first, T* last, T* result)
{
    typename __vector_copy_selector<T>::type tag;
    __vector_copy_backward_dispatch(first, last, result, tag);
}

template <class OutputIterator, class Size, class Value>
inline void __vector_fill_n_impl(OutputIterator first, Size count, const Value& value)
{
    while (count != 0) {
        *first = value;
        --count;
        ++first;
    }
}

template <class OutputIterator, class Size, class Value>
inline void __vector_fill_n(OutputIterator first, Size count, const Value& value)
{
    __vector_fill_n_impl(first, count, value);
}

template <class T>
inline void __vector_swap(T& lhs, T& rhs)
{
    T temp = lhs;
    lhs = rhs;
    rhs = temp;
}

// RECONSTRUCTED: helper name.
template <class InputIterator, class OutputIterator>
inline void __vector_copy_forward(InputIterator first, InputIterator last, OutputIterator out)
{
    while (first < last) {
        *out = *first;
        ++first;
        ++out;
    }
}

template <class T>
inline void __vector_copy_forward_dispatch(T* first, T* last, T* out, __vector_copy_loop_tag)
{
    while (first < last) {
        *out = *first;
        ++first;
        ++out;
    }
}

template <class T>
inline void __vector_copy_forward_dispatch(T* first, T* last, T* out, __vector_copy_mem_tag)
{
    ::memcpy(out, first, (last - first) * sizeof(T));
}

template <class T>
inline void __vector_copy_forward(T* first, T* last, T* out)
{
    typename __vector_copy_selector<T>::type tag;
    __vector_copy_forward_dispatch(first, last, out, tag);
}

template <class T, class A>
template <class Iter>
void __vector_pod<T, A>::init(Iter first, Iter last, forward_iterator_tag)
{
    s32 count = last - first;
    capacity() = count;
    size_ = count;
    A& allocRef = alloc();
    if (allocRef.max_size() < size_) {
        ::fprintf(stderr, "vector length error\n");
        ::abort();
    }
    if (size_ != 0) {
        T** dataField = &data_;
        *dataField = allocRef.allocate(size_);
        T* out = data_;
        while (first < last) {
            *out = *first;
            ++first;
            ++out;
        }
    }
}

template <class T, class A>
template <class Iter>
void __vector_pod<T, A>::do_assign(Iter first, Iter last, forward_iterator_tag)
{
    s32 count = last - first;
    A& allocRef = alloc();
    if (capacity() < static_cast<u32>(count)) {
        if (allocRef.max_size() < static_cast<u32>(count)) {
            ::fprintf(stderr, "vector::assign length error\n");
            ::abort();
        }
        clear();
        if (data_ != NULL) {
            allocRef.deallocate(data_, capacity());
            data_ = NULL;
            capacity() = 0;
        }
        T** dataField = &data_;
        *dataField = allocRef.allocate(count);
        capacity() = count;
    }
    T* out = data_;
    while (first < last) {
        *out = *first;
        ++first;
        ++out;
    }
    size_ = count;
}

template <class T, class A>
void __vector_pod<T, A>::insert(T* position, u32 count, const T& value)
{
    if (count == 0)
        return;
    u32 maximum = alloc().max_size();
    if (count > maximum || size_ > maximum - count) {
        ::fprintf(stderr, "vector::insert length error\n");
        ::abort();
    }
    u32 requiredSize = size_ + count;
    if (requiredSize <= capacity()) {
        T* oldEnd = data_ + size_;
        u32 elementsAfter = oldEnd - position;
        const T* valuePtr = &value;
        T* insertedEnd = oldEnd - (elementsAfter - count);
        if (insertedEnd <= valuePtr && valuePtr < oldEnd)
            valuePtr += count;
        if (elementsAfter != 0)
            __vector_copy_backward(position, oldEnd, oldEnd + count);
        __vector_fill_n(position, count, *valuePtr);
        size_ += count;
    } else {
        u32 newCapacity;
        T* oldData = data_;
        s32 offset = position - oldData;
        const __vector_pod<T, A>& self = *this;
        const u32 currentCapacity = self.capacity();
        newCapacity = currentCapacity ? currentCapacity : 1;
        while (requiredSize > newCapacity) {
            if (newCapacity < maximum / 2)
                newCapacity *= 2;
            else
                newCapacity = maximum;
        }
        T** dataField = &data_;
        *dataField = alloc().allocate(newCapacity);
        __vector_fill_n(data_ + offset, count, value);
        if (oldData != NULL) {
            __vector_copy_forward(oldData, oldData + offset, data_);
            __vector_copy_forward(oldData + offset, oldData + size_, data_ + offset + count);
            alloc().deallocate(oldData, capacity());
        }
        size_ = requiredSize;
        capacity() = newCapacity;
    }
}

template <class T, class A, int N>
void __vector_imp<T, A, N>::insert(T* position, u32 count, const T& value)
{
    if (count == 0)
        return;

    A& allocRef = alloc();
    u32 maximum = allocRef.max_size();
    if (count > maximum || size_ > maximum - count) {
        ::fprintf(stderr, "vector::insert length error\n");
        ::abort();
    }

    if (size_ + count <= capacity()) {
        T* out;
        T* oldEnd = data_ + size_;
        u32 elementsAfter = oldEnd - position;
        const T* valuePtr = &value;

        if (elementsAfter < count) {
            out = oldEnd;
            while (elementsAfter < count) {
                allocRef.construct(out, *valuePtr);
                --count;
                ++out;
                ++size_;
            }
            T* src = position;
            while (src < oldEnd) {
                allocRef.construct(out, *src);
                ++src;
                ++out;
                ++size_;
            }
        } else {
            T* src = oldEnd - count;
            out = oldEnd;
            while (src < oldEnd) {
                allocRef.construct(out, *src);
                ++src;
                ++out;
                ++size_;
            }
            u32 remaining = elementsAfter - count;
            T* insertedEnd = oldEnd - remaining;
            if (insertedEnd <= valuePtr && valuePtr < oldEnd)
                valuePtr += count;
            T* sourceEnd = position + remaining;
            __vector_copy_backward(position, sourceEnd, oldEnd);
        }
        __vector_fill_n(position, count, *valuePtr);
    } else {
        __vector_deleter<T, A> temp(allocRef);
        u32 requiredSize = size_ + count;
        u32 newCapacity = capacity_value();
        newCapacity = newCapacity ? newCapacity : 1;
        while (requiredSize > newCapacity) {
            if (newCapacity < maximum / 2)
                newCapacity *= 2;
            else
                newCapacity = maximum;
        }

        T* out = allocRef.allocate(newCapacity);
        temp.capacity() = newCapacity;
        temp.data_ = out;

        T* src = data_;
        T* oldEnd = data_ + size_;
        while (src < position) {
            allocRef.construct(out, *src);
            ++src;
            ++out;
            ++temp.size_;
        }
        while (count != 0) {
            allocRef.construct(out, value);
            --count;
            ++out;
            ++temp.size_;
        }
        while (src < oldEnd) {
            allocRef.construct(out, *src);
            ++src;
            ++out;
            ++temp.size_;
        }

        if (&temp != static_cast<__vector_deleter<T, A>*>(this)) {
            __vector_swap(temp.alloc(), alloc());
            __vector_swap(temp.capacity(), capacity());
            __vector_swap(temp.data_, data_);
            __vector_swap(temp.size_, size_);
        }
    }
}

template <class T, class A, int N>
void __vector_imp<T, A, N>::reserve(u32 requestedCapacity)
{
    if (capacity() < requestedCapacity) {
        A& allocRef = alloc();
        if (allocRef.max_size() < requestedCapacity) {
            ::fprintf(stderr, "vector::reserve length error\n");
            ::abort();
        }

        __vector_deleter<T, A> temp(allocRef);
        T* out = allocRef.allocate(requestedCapacity);
        temp.capacity() = requestedCapacity;
        temp.data_ = out;

        T* src = data_;
        T* oldEnd = src + size_;
        while (src < oldEnd) {
            allocRef.construct(out, *src);
            ++src;
            ++out;
            ++temp.size_;
        }

        if (&temp != static_cast<__vector_deleter<T, A>*>(this)) {
            __vector_swap(temp.alloc(), alloc());
            __vector_swap(temp.capacity(), capacity());
            __vector_swap(temp.data_, data_);
            __vector_swap(temp.size_, size_);
        }
    }
}

template <class T, class A>
void __vector_pod<T, A>::reserve(u32 requestedCapacity)
{
    if (capacity() < requestedCapacity) {
        A& allocRef = alloc();
        if (allocRef.max_size() < requestedCapacity) {
            ::fprintf(stderr, "vector::reserve length error\n");
            ::abort();
        }

        T* oldData = data_;
        T** dataField = &data_;
        *dataField = allocRef.allocate(requestedCapacity);
        if (oldData != NULL) {
            T* src = oldData;
            T* oldEnd = src + size_;
            T* out = data_;
            while (src < oldEnd) {
                *out = *src;
                ++src;
                ++out;
            }
            allocRef.deallocate(oldData, capacity());
        }
        capacity() = requestedCapacity;
    }
}

template <class T, class A>
T& __vector_pod<T, A>::at(u32 index)
{
    if (index >= size_) {
        ::fprintf(stderr, "vector::at index out of range");
        ::abort();
    }
    return data_[index];
}

template <class T, class A>
const T& __vector_pod<T, A>::at(u32 index) const
{
    if (index >= size_) {
        ::fprintf(stderr, "vector::at index out of range");
        ::abort();
    }
    return data_[index];
}

template <class T, class A>
void __vector_deleter<T, A>::clear()
{
    T* destroyBegin = data_;
    T* destroyEnd = data_ + size_;
    while (destroyBegin < destroyEnd) {
        --destroyEnd;
        alloc().destroy(destroyEnd);
    }
    size_ = 0;
}

template <class T, class A>
__vector_deleter<T, A>::~__vector_deleter()
{
    clear();
    if (data_ != NULL)
        alloc().deallocate(data_, capacity());
}

template <class T, class A, int N>
template <class Iter>
void __vector_imp<T, A, N>::init(Iter first, Iter last, forward_iterator_tag)
{
    s32 count = last - first;
    A& allocRef = alloc();
    if (allocRef.max_size() < size_) {
        ::fprintf(stderr, "vector length error\n");
        ::abort();
    }
    if (count != 0) {
        T** dataField = &data_;
        *dataField = allocRef.allocate(static_cast<u32>(count));
        capacity() = count;
        T* out = data_;
        while (first != last) {
            allocRef.construct(out, *first);
            ++first;
            ++out;
            ++size_;
        }
    }
}

template <class T, class A, int N>
template <class Iter>
void __vector_imp<T, A, N>::do_assign(Iter first, Iter last, forward_iterator_tag)
{
    A& allocRef = alloc();
    s32 count = last - first;
    if (static_cast<u32>(count) <= capacity()) {
        u32 countTemp = count;
        const u32* commonCount = size_ < static_cast<u32>(count) ? &size_ : &countTemp;
        T* outBegin = data_;
        T* out = outBegin;
        T* copyLast = outBegin + *commonCount;
        while (out < copyLast) {
            *out = *first;
            ++out;
            ++first;
        }
        u32 oldSize = size_;
        s64 signedCount = count;
        if (static_cast<u32>(signedCount) < oldSize) {
            T* destroyBegin = data_ + static_cast<u32>(signedCount);
            T* destroyEnd = data_ + oldSize;
            while (destroyBegin < destroyEnd) {
                --destroyEnd;
                allocRef.destroy(destroyEnd);
            }
            size_ = static_cast<u32>(signedCount);
        } else if (oldSize < static_cast<u32>(signedCount)) {
            while (first != last) {
                allocRef.construct(out, *first);
                ++first;
                ++out;
                ++size_;
            }
        }
    } else {
        if (allocRef.max_size() < static_cast<u32>(count)) {
            ::fprintf(stderr, "vector length error\n");
            ::abort();
        }
        clear();
        if (data_ != NULL) {
            allocRef.deallocate(data_, capacity());
            data_ = NULL;
            capacity() = 0;
        }
        T** dataField = &data_;
        *dataField = __vector_allocate_signed_distance<T>(static_cast<u32>(count));
        capacity() = static_cast<s64>(count);
        T* out = data_;
        while (first != last) {
            allocRef.construct(out, *first);
            ++first;
            ++out;
            ++size_;
        }
    }
}

template <class Iterator, class Predicate>
inline Iterator find_if(Iterator first, Iterator last, const Predicate& predicate)
{
    while (first != last && !predicate(*first))
        ++first;
    return first;
}

template <class Iterator, class T>
inline Iterator find(Iterator first, Iterator last, const T& value)
{
    while (first != last && !(*first == value))
        ++first;
    return first;
}

} // namespace std

namespace oostd {
template <class T, class A>
class clsOOVector : public std::vector<T, A> {
    typedef std::vector<T, A> Base;

public:
    clsOOVector() : Base() {}
    explicit clsOOVector(clsOOHeapFragment& rcHeap) : Base(A(rcHeap)) {}
};
} // namespace oostd

#endif // OOVECTOR_HPP
