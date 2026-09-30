#ifndef OODEQUE_HPP
#define OODEQUE_HPP

// RECONSTRUCTED: header placement and typedefs.
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOStl.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2Heap.hpp"
#include "usr/local/metrowerks/PS2_Support/stl/algorithm.h"

namespace Metrowerks {

template <class T, class A>
class __cdeque_deleter_common {
public:
    compressed_pair<A, u32> capacity_;
    u32 size_;
    u32 start_;
    T* data_;

    explicit __cdeque_deleter_common(const A& a) : capacity_(a), size_(0), start_(0), data_(NULL) {}
    A& alloc() { return capacity_.first(); }
    const A& alloc() const { return capacity_.first(); }
    u32 max_size() const;
    bool empty() const { return size_ == 0; }
};

template <class T, class A, int N>
class __cdeque_deleter : public __cdeque_deleter_common<T, A> {
    typedef __cdeque_deleter_common<T, A> Base;

public:
    explicit __cdeque_deleter(const A& a) : Base(a) {}
    ~__cdeque_deleter()
    {
        if (this->data_ != NULL) {
            this->alloc().deallocate(this->data_, this->capacity_.second());
        }
    }
    void pop_front();
    template <class Iter>
    void init(Iter first, Iter last);
};

template <class T, class A, int N>
void __cdeque_deleter<T, A, N>::pop_front()
{
    --this->size_;
    if (++this->start_ == this->capacity_.second()) {
        this->start_ = 0;
    }
}

template <class T, class A, int N>
template <class Iter>
void __cdeque_deleter<T, A, N>::init(Iter first, Iter last)
{
    s32 count = last - first;
    this->size_ = static_cast<u32>(count);
    if (count != 0) {
        if (this->max_size() < static_cast<u32>(count)) {
            ::fprintf(stderr, "cdeque::construction length error");
            ::abort();
        }
        this->data_ = this->alloc().allocate(this->capacity_.second() = this->size_ + 1);
        Iter source(first);
        Iter finish(last);
        T* output = this->data_;
        while (source != finish) {
            *output = *source;
            ++source;
            ++output;
        }
    }
}

template <class T, class A>
u32 __cdeque_deleter_common<T, A>::max_size() const
{
    u32 limit = 0x7fffffffU;
    static const u32 ms = std::min(alloc().max_size(), limit) - 1;
    return ms;
}

template <class T, class A, int N>
class __cdeque_imp : public __cdeque_deleter<T, A, N>, private compile_assert<1> {
    typedef __cdeque_deleter<T, A, N> Base;

public:
    explicit __cdeque_imp(const A& a) : Base(a) {}

    template <int Const>
    class generic_iterator {
    public:
        T* ptr_;
        T* beg_;
        T* start_;
        T* end_;

        generic_iterator() {}
        generic_iterator(T* ptr, T* beg, T* start, T* end)
            : ptr_(ptr), beg_(beg), start_(start), end_(end)
        {
        }
        T& operator*() const { return *ptr_; }
        generic_iterator& operator++()
        {
            if (++ptr_ == end_) {
                ptr_ = beg_;
            }
            return *this;
        }
        generic_iterator operator++(int)
        {
            generic_iterator tmp(*this);
            ++*this;
            return tmp;
        }
        bool operator==(const generic_iterator& rhs) const { return ptr_ == rhs.ptr_; }
        bool operator!=(const generic_iterator& rhs) const { return ptr_ != rhs.ptr_; }
        s32 operator-(const generic_iterator& rhs) const
        {
            T* beg = beg_;
            T* end = end_;
            T* s = start_;
            s32 n = ptr_ - rhs.ptr_;
            if (ptr_ >= s) {
                if (rhs.ptr_ < s) {
                    n -= end - beg;
                }
            } else if (rhs.ptr_ >= s) {
                n += end - beg;
            }
            return n;
        }
    };
};

} // namespace Metrowerks

namespace std {

// RECONSTRUCTED: adaptor members.
template <class T, class Iter>
class __reinterpret_convert {
public:
    typedef Iter iterator_type;
    u32& operator()(T& value) const { return reinterpret_cast<u32&>(value); }
};

template <class Convert>
class __convert_iterator {
public:
    typedef typename Convert::iterator_type iterator_type;
    iterator_type iterator_;
    Convert converter_;

    explicit __convert_iterator(iterator_type i, const Convert& c = Convert()) : iterator_(i)
    {
        converter_ = c;
    }
    u32& operator*() const { return converter_(*iterator_); }
    __convert_iterator& operator++()
    {
        ++iterator_;
        return *this;
    }
    __convert_iterator operator++(int)
    {
        __convert_iterator tmp(*this);
        ++*this;
        return tmp;
    }
    bool operator==(const __convert_iterator& rhs) const { return iterator_ == rhs.iterator_; }
    bool operator!=(const __convert_iterator& rhs) const { return !(*this == rhs); }
    s32 operator-(const __convert_iterator& rhs) const { return iterator_ - rhs.iterator_; }
};

} // namespace std

namespace Metrowerks {

template <class T, class A>
class __cdeque_imp<T*, A, 1>
    : public __cdeque_deleter<u32, typename std::__allocator_rebind<A, u32>::type, 1>,
      private compile_assert<1> {
    typedef typename std::__allocator_rebind<A, u32>::type WordAllocator;
    typedef __cdeque_deleter<u32, WordAllocator, 1> Base;

public:
    explicit __cdeque_imp(const A& a) : Base(WordAllocator(a)) {}
    explicit __cdeque_imp(const WordAllocator& a) : Base(a) {}
    __cdeque_imp(const __cdeque_imp& rhs) : Base(rhs.alloc())
    {
        std::forward_iterator_tag tag;
        init(rhs.begin(), rhs.end(), tag);
    }

    template <int Const>
    class generic_iterator {
    public:
        typename __cdeque_imp<u32, WordAllocator, 1>::template generic_iterator<Const> i_;

        generic_iterator() {}
        generic_iterator(u32* const& data, u32 ptrindex, u32 startindex, u32 endindex)
            : i_(data + ptrindex, data, data + startindex, data + endindex)
        {
        }
        generic_iterator(u32* ptr, u32* beg, u32* start, u32* end) : i_(ptr, beg, start, end) {}
        T*& operator*() const { return reinterpret_cast<T*&>(*i_); }
        generic_iterator& operator++()
        {
            ++i_;
            return *this;
        }
        generic_iterator operator++(int)
        {
            generic_iterator tmp(*this);
            ++*this;
            return tmp;
        }
        bool operator==(const generic_iterator& rhs) const { return i_ == rhs.i_; }
        bool operator!=(const generic_iterator& rhs) const { return i_ != rhs.i_; }
        s32 operator-(const generic_iterator& rhs) const { return i_ - rhs.i_; }
    };

    generic_iterator<1> begin() const
    {
        return generic_iterator<1>(
            this->data_, this->start_, this->start_, this->capacity_.second());
    }
    typedef generic_iterator<1> const_iterator;
    const_iterator end() const
    {
        u32 cap = this->capacity_.second();
        u32 n = cap != 0 ? (this->start_ + this->size_) % cap : 0;
        return generic_iterator<1>(this->data_ + n,
                                   this->data_,
                                   this->data_ + this->start_,
                                   this->data_ + this->capacity_.second());
    }
    T*& front() { return reinterpret_cast<T*&>(this->data_[this->start_]); }
    T*& operator[](u32 n)
    {
        return reinterpret_cast<T*&>(this->data_[(this->start_ + n) % this->capacity_.second()]);
    }
    u32 size() const { return this->size_; }
    template <class Iter>
    void init(Iter first, Iter last, std::forward_iterator_tag)
    {
        typedef std::__convert_iterator<std::__reinterpret_convert<T*, Iter> > Converted;
        Base::init(Converted(first), Converted(last));
    }
};

template <class T, class A>
class cdeque : private __cdeque_imp<T, A, 1> {
    typedef __cdeque_imp<T, A, 1> Base;

public:
    typedef typename Base::template generic_iterator<1> const_iterator;
    explicit cdeque(const A& a) : Base(a) {}
    cdeque(const cdeque& rhs) : Base(rhs) {}
    using Base::begin;
    using Base::end;
    using Base::front;
    using Base::operator[];
    using Base::empty;
    using Base::pop_front;
    using Base::size;
};

} // namespace Metrowerks

namespace std {

template <class T>
class __deque_buf {};

template <class T, class A>
class __deque_deleter_common : private __deque_buf<T> {
public:
    typedef typename __allocator_rebind<A, T*>::type BufferAllocator;
    typedef ::Metrowerks::cdeque<T*, BufferAllocator> Buffer;
    ::Metrowerks::compressed_pair<A, Buffer> buf_;
    u32 start_;
    u32 size_;

    explicit __deque_deleter_common(const A& a)
        : buf_(a, Buffer(BufferAllocator(a))), start_(0), size_(0)
    {
    }
    ~__deque_deleter_common();
    bool empty() const { return size_ == 0; }
};

template <class T, class A>
__deque_deleter_common<T, A>::~__deque_deleter_common()
{
    const Buffer& rcBuffer = buf_.second();
    if (!buf_.second().empty()) {
        typename Buffer::const_iterator last = rcBuffer.end();
        typename Buffer::const_iterator it = rcBuffer.begin();
        while (it != last) {
            if (*it != NULL) {
                buf_.first().deallocate(*it, 512 / sizeof(T));
            }
            ++it;
        }
    }
}

template <class T, class A, int N>
class __deque_deleter : public __deque_deleter_common<T, A> {
    typedef __deque_deleter_common<T, A> Base;

public:
    explicit __deque_deleter(const A& a) : Base(a) {}
    void clear();
    void pop_front()
    {
        if (this->size_ == 1) {
            clear();
        } else {
            --this->size_;
            ++this->start_;
            while (this->start_ >= 1024 / sizeof(T)) {
                this->buf_.first().deallocate(this->buf_.second().front(), 512 / sizeof(T));
                this->buf_.second().pop_front();
                this->start_ -= 512 / sizeof(T);
            }
        }
    }
};

template <class T, class A, int N>
void __deque_deleter<T, A, N>::clear()
{
    this->size_ = 0;
    if (this->buf_.second().size() > 1) {
        while (this->buf_.second().size() > 2) {
            this->buf_.first().deallocate(this->buf_.second().front(), 512 / sizeof(T));
            this->buf_.second().pop_front();
        }
        this->start_ = 256 / sizeof(T);
    } else {
        this->start_ = 0;
    }
}

template <class T, class A, int N>
class __deque_imp;

template <class T, class A>
class __deque_imp<T*, A, 1>
    : public __deque_deleter<u32, typename __allocator_rebind<A, u32>::type, 1>,
      private ::Metrowerks::compile_assert<1> {
    typedef typename __allocator_rebind<A, u32>::type WordAllocator;
    typedef __deque_deleter<u32, WordAllocator, 1> Base;

public:
    explicit __deque_imp(const A& a) : Base(WordAllocator(a)) {}
    T*& front()
    {
        return reinterpret_cast<T*&>(this->buf_.second()[this->start_ / 128][this->start_ % 128]);
    }
};

template <class T, class A>
class deque : private __deque_imp<T, A, 1> {
    typedef __deque_imp<T, A, 1> Base;

public:
    explicit deque(const A& a) : Base(a) {}
    using Base::empty;
    using Base::front;
    using Base::pop_front;
};

} // namespace std

namespace oostd {

template <class T, class A = clsOOStlAllocator<T> >
class clsOODeque : public std::deque<T, A> {
    typedef std::deque<T, A> Base;

public:
    explicit clsOODeque(clsOOHeapFragment& rcHeap = clsPfMainHeap::RS()) : Base(A(rcHeap)) {}
};

} // namespace oostd

#endif // OODEQUE_HPP
