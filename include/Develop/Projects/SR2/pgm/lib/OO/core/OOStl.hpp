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

template <class First, class Second>
class pair {
public:
    First first;
    Second second;
};

template <class Arg1, class Arg2, class Result>
class binary_function_t {};

template <class T>
class less : public binary_function_t<T, T, bool> {
public:
    bool operator()(const T& lhs, const T& rhs) const { return lhs < rhs; }
};

template <class T, class A>
class __list_deleter {
public:
    u32 m_au32Storage[5]; // offset 0x0, size 0x14

    template <int N>
    class generic_iterator {
    public:
        void* node_; // offset 0x0, size 0x4

        generic_iterator() {}
        explicit generic_iterator(void* node) : node_(node) {}
        generic_iterator(const generic_iterator& rhs) : node_(rhs.node_) {}
    };

    typedef generic_iterator<0> iterator0;

    __list_deleter(const A& allocator);
    iterator0 erase(iterator0 first, iterator0 last);

    ~__list_deleter()
    {
        erase(iterator0(reinterpret_cast<void*>(m_au32Storage[4])),
              iterator0(reinterpret_cast<void*>(&m_au32Storage[3])));
    }
};

template <class T, class A>
class __list_imp : private __list_deleter<T, A> {
    typedef __list_deleter<T, A> Base;

protected:
    __list_imp(const A& allocator) : Base(allocator) {}
};

template <class T, class A>
class list : private __list_imp<const void*, oostd::clsOOStlAllocator<const void*> > {
    typedef __list_imp<const void*, oostd::clsOOStlAllocator<const void*> > Base;

public:
    template <int N>
    class generic_iterator {
    public:
        void* node_; // offset 0x0, size 0x4
    };

    list(const A& allocator) : Base(oostd::clsOOStlAllocator<const void*>(allocator)) {}
};

template <class Value, class Compare, class Allocator>
class __tree {
public:
    class node;

    class anchor {
    public:
        node* left_;
    };

    class alloc_pair {
    public:
        Allocator first_;
        u32 second_;

        alloc_pair(const Allocator& allocator) : first_(allocator), second_(0) {}
    };

    class node_alloc_pair {
    public:
        Allocator first_;
        anchor second_;

        node_alloc_pair(const Allocator& allocator) : first_(allocator) { second_.left_ = 0; }
    };

    class comp_pair {
    public:
        Compare first_;
        node* second_;

        comp_pair(const Compare& compare, node* end) : first_(compare), second_(end) {}
    };

    alloc_pair alloc_;
    node_alloc_pair node_alloc_;
    comp_pair comp_;

    __tree(const Compare& compare, const Allocator& allocator);
    void destroy(node* root);

    ~__tree()
    {
        node* root = node_alloc_.second_.left_;
        if (root != 0) {
            destroy(root);
        }
    }
};

template <class Value, class Compare, class Allocator>
__tree<Value, Compare, Allocator>::__tree(const Compare& compare, const Allocator& allocator)
    : alloc_(allocator), node_alloc_(allocator),
      comp_(compare, reinterpret_cast<node*>(&node_alloc_.second_))
{
}

template <class Key, class T, class Compare, class Allocator>
class map {
public:
    typedef pair<const Key, T> value_type;

    class value_compare : public binary_function_t<value_type, value_type, bool> {
    public:
        Compare comp; // offset 0x0, size 0x1 for std::less<u32>

        value_compare(Compare compare) : comp(compare) {}
    };

    typedef __tree<value_type, value_compare, Allocator> tree_type;

    tree_type tree_; // offset 0x0, size 0x18

    map(const Compare& compare, const Allocator& allocator)
        : tree_(value_compare(compare), allocator)
    {
    }
};

} // namespace std

namespace oostd {

template <class T, class A>
class clsOOList : public std::list<T, A> {
    typedef std::list<T, A> Base;

public:
    clsOOList(clsOOHeapFragment& rcHeap) : Base(A(rcHeap)) {}
};

template <class Key, class T, class Compare, class Allocator>
class clsOOMap : public std::map<Key, T, Compare, Allocator> {
    typedef std::map<Key, T, Compare, Allocator> Base;

public:
    clsOOMap(clsOOHeapFragment& rcHeap) : Base(Compare(), Allocator(rcHeap)) {}
};

template <class T, class C, class A>
class clsOOSet {};

} // namespace oostd

#endif // OOSTL_HPP
