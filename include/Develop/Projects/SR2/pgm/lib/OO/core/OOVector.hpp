#ifndef OOVECTOR_HPP
#define OOVECTOR_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/System/NewDelete.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOCompressedPair.hpp"
#include "usr/local/sce/ee/gcc/ee/lib/libc/abort.h"
#include "usr/local/sce/ee/gcc/ee/lib/libc/fprintf.h"
#include "usr/local/sce/ee/gcc/ee/lib/libc/stdio.h"

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

    T* allocate(u32 count, const void* = 0)
    {
        T* data = static_cast<T*>(::operator new(count * sizeof(T)));
        if (data == 0) {
            ::fprintf(reinterpret_cast<void**>(::_impure_ptr)[3], "Memory allocation failure");
            ::abort();
        }
        return data;
    }

    void deallocate(T* ptr, u32) { ::operator delete(ptr); }
    void construct(T* ptr, const T& value) { new (ptr) T(value); }
    void destroy(T* ptr) { ptr->~T(); }
};

template <class T>
inline T* __vector_allocate_signed_distance(u32 count)
{
    s64 signedCount = (s32)count;
    T* data = static_cast<T*>(::operator new((u32)signedCount * sizeof(T)));
    if (data == 0) {
        ::fprintf(reinterpret_cast<void**>(::_impure_ptr)[3], "Memory allocation failure");
        ::abort();
    }
    return data;
}

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
    typedef ::Metrowerks::compressed_pair<A, u32> capacity_pair;
    capacity_pair capacity_; // offset 0x0, size 0x4
    u32 size_;               // offset 0x4, size 0x4
    T* data_;                // offset 0x8, size 0x4

    A& alloc() { return capacity_.first(); }
    const A& alloc() const { return capacity_.first(); }
    u32& capacity() { return capacity_.second(); }
    const u32& capacity() const { return capacity_.second(); }
    T* end_data() { return data_ + size_; }

    __vector_deleter()
    {
        capacity_.second() = 0;
        size_ = 0;
        data_ = 0;
    }
    void clear();
    T*& data() { return data_; }
    ~__vector_deleter();
};

// total size: 0xC
template <class T, class A, int N>
class __vector_imp : private __vector_deleter<T, A> {
    typedef __vector_deleter<T, A> Base;

protected:
    using Base::alloc;
    using Base::capacity;
    using Base::clear;
    using Base::data_;
    using Base::size_;

public:
    __vector_imp() : Base() {}
    void reserve(u32);
    void insert(T*, u32, const T&);

    template <class Iter>
    void init(Iter, Iter, forward_iterator_tag);

    template <class Iter>
    void do_assign(Iter, Iter, forward_iterator_tag);
};

template <class T, class A, int N>
inline u32 __vector_capacity(const __vector_imp<T, A, N>& value)
{
    // All tested vector implementations flatten capacity to the first word.
    return *reinterpret_cast<const u32*>(&value);
}

// total size: 0xC
template <class T, class A>
class vector : private __vector_imp<T, A, 0> {
    typedef __vector_imp<T, A, 0> Base;

public:
    typedef T value_type;
    typedef __wrap_iterator<vector<T, A>, T*> iterator;

    vector() : Base() {}
    vector(const vector& rhs) : Base()
    {
        const T* first = rhs.data_ptr();
        forward_iterator_tag tag;
        this->init(first, first + rhs.size_value(), tag);
    }
    vector& operator=(const vector& rhs)
    {
        if (this != &rhs) {
            const T* first = rhs.data_ptr();
            forward_iterator_tag tag;
            this->do_assign(first, first + rhs.size_value(), tag);
        }
        return *this;
    }

    T* data_ptr() { return this->data_; }
    const T* data_ptr() const { return this->data_; }
    u32 size_value() const { return this->size_; }
    T* end_ptr() { return this->data_ + this->size_; }

    iterator begin() { return iterator(this->data_); }
    iterator end() { return iterator(this->data_ + this->size_); }
    void clear() { Base::clear(); }
    using Base::insert;
    using Base::reserve;
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

template <class T, class A, int N>
void __vector_imp<T, A, N>::insert(T* position, u32 count, const T& value)
{
    if (count == 0)
        return;

    A& allocRef = this->alloc();
    u32 maximum = allocRef.max_size();
    if (count > maximum || this->size_ > maximum - count) {
        ::fprintf(reinterpret_cast<void**>(::_impure_ptr)[3], "vector length error\n");
        ::abort();
    }

    if (this->size_ + count <= this->capacity()) {
        T* out;
        T* oldEnd = this->data_ + this->size_;
        u32 elementsAfter = oldEnd - position;
        const T* valuePtr = &value;

        if (elementsAfter < count) {
            out = oldEnd;
            while (elementsAfter < count) {
                allocRef.construct(out, *valuePtr);
                --count;
                ++out;
                ++this->size_;
            }
            T* src = position;
            while (src < oldEnd) {
                allocRef.construct(out, *src);
                ++src;
                ++out;
                ++this->size_;
            }
        } else {
            T* src = oldEnd - count;
            out = oldEnd;
            while (src < oldEnd) {
                allocRef.construct(out, *src);
                ++src;
                ++out;
                ++this->size_;
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
        __vector_deleter<T, A> temp;
        u32 requiredSize = this->size_ + count;
        u32 newCapacity = __vector_capacity(*this);
        newCapacity = newCapacity ? newCapacity : 1;
        while (requiredSize > newCapacity) {
            if (newCapacity < maximum / 2)
                newCapacity *= 2;
            else
                newCapacity = maximum;
        }

        T* out = allocRef.allocate(newCapacity, 0);
        temp.capacity() = newCapacity;
        temp.data_ = out;

        T* src = this->data_;
        T* oldEnd = this->data_ + this->size_;
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
            __vector_swap(temp.capacity(), this->capacity());
            __vector_swap(temp.data_, this->data_);
            __vector_swap(temp.size_, this->size_);
        }
    }
}

template <class T, class A, int N>
void __vector_imp<T, A, N>::reserve(u32 requestedCapacity)
{
    if (this->capacity() < requestedCapacity) {
        A& allocRef = this->alloc();
        if (allocRef.max_size() < requestedCapacity) {
            ::fprintf(reinterpret_cast<void**>(::_impure_ptr)[3], "vector length error\n");
            ::abort();
        }

        __vector_deleter<T, A> temp;
        T* out = allocRef.allocate(requestedCapacity, 0);
        temp.capacity() = requestedCapacity;
        temp.data_ = out;

        T* src = this->data_;
        T* oldEnd = src + this->size_;
        while (src < oldEnd) {
            allocRef.construct(out, *src);
            ++src;
            ++out;
            ++temp.size_;
        }

        if (&temp != static_cast<__vector_deleter<T, A>*>(this)) {
            __vector_swap(temp.capacity(), this->capacity());
            __vector_swap(temp.data_, this->data_);
            __vector_swap(temp.size_, this->size_);
        }
    }
}

template <class T, class A>
void __vector_deleter<T, A>::clear()
{
    T* destroyBegin = this->data_;
    T* destroyEnd = end_data();
    while (destroyBegin < destroyEnd) {
        --destroyEnd;
        destroyEnd->~T();
    }
    this->size_ = 0;
}

template <class T, class A>
__vector_deleter<T, A>::~__vector_deleter()
{
    clear();
    if (data() != 0)
        ::operator delete(data());
}

template <class T, class A, int N>
template <class Iter>
void __vector_imp<T, A, N>::init(Iter first, Iter last, forward_iterator_tag)
{
    s32 count = last - first;
    A& allocRef = this->alloc();
    if (allocRef.max_size() < this->size_) {
        ::fprintf(reinterpret_cast<void**>(::_impure_ptr)[3], "vector length error\n");
        ::abort();
    }
    if (count != 0) {
        T** dataField = &this->data_;
        *dataField = allocRef.allocate((u32)count, 0);
        this->capacity() = count;
        T* out = this->data_;
        while (first != last) {
            allocRef.construct(out, *first);
            ++first;
            ++out;
            ++this->size_;
        }
    }
}

template <class T, class A, int N>
template <class Iter>
void __vector_imp<T, A, N>::do_assign(Iter first, Iter last, forward_iterator_tag)
{
    A& allocRef = this->alloc();
    s32 count = last - first;
    if ((u32)count <= this->capacity()) {
        u32 countTemp = count;
        const u32* commonCount = this->size_ < (u32)count ? &this->size_ : &countTemp;
        T* outBegin = this->data_;
        T* out = outBegin;
        T* copyLast = outBegin + *commonCount;
        while (out < copyLast) {
            *out = *first;
            ++out;
            ++first;
        }
        u32 oldSize = this->size_;
        s64 signedCount = count;
        if ((u32)signedCount < oldSize) {
            T* destroyBegin = this->data_ + (u32)signedCount;
            T* destroyEnd = this->data_ + oldSize;
            while (destroyBegin < destroyEnd) {
                --destroyEnd;
                allocRef.destroy(destroyEnd);
            }
            this->size_ = (u32)signedCount;
        } else if (oldSize < (u32)signedCount) {
            while (first != last) {
                allocRef.construct(out, *first);
                ++first;
                ++out;
                ++this->size_;
            }
        }
    } else {
        if (allocRef.max_size() < (u32)count) {
            ::fprintf(reinterpret_cast<void**>(::_impure_ptr)[3], "vector length error\n");
            ::abort();
        }
        this->clear();
        if (this->data_ != 0) {
            allocRef.deallocate(this->data_, this->capacity());
            this->data_ = 0;
            this->capacity() = 0;
        }
        T** dataField = &this->data_;
        *dataField = __vector_allocate_signed_distance<T>((u32)count);
        this->capacity() = (s64)count;
        T* out = this->data_;
        while (first != last) {
            allocRef.construct(out, *first);
            ++first;
            ++out;
            ++this->size_;
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
class clsOOVector {};
} // namespace oostd

#endif // OOVECTOR_HPP
