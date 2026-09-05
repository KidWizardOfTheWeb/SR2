#ifndef OOSTL_HPP
#define OOSTL_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOCompressedPair.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOStlAllocator.hpp"
#include "Develop/Projects/SR2/pgm/src/System/NewDelete.hpp"
#include "usr/local/metrowerks/PS2_Support/stl/deque.h"
#include "usr/local/sce/ee/gcc/ee/lib/libc/abort.h"
#include "usr/local/sce/ee/gcc/ee/lib/libc/fprintf.h"
#include "usr/local/sce/ee/gcc/ee/lib/libc/stdio.h"

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
class allocator;

template <class Allocator, class U>
struct __allocator_rebind;

template <class T, class U>
struct __allocator_rebind<oostd::clsOOStlAllocator<T>, U> {
    typedef oostd::clsOOStlAllocator<U> type;
    enum { is_std = 0 };
};

template <class T, class U>
struct __allocator_rebind<allocator<T>, U> {
    typedef allocator<U> type;
    enum { is_std = 1 };
};

template <int N>
class __red_black_tree {
public:
    class node_base;

    // total size: 0x4
    class __pointer_plus_bit {
    public:
        node_base* ptr_; // offset 0x0, size 0x4

        operator u32() const { return reinterpret_cast<u32>(ptr_); }

        __pointer_plus_bit& operator=(u32 value)
        {
            ptr_ = reinterpret_cast<node_base*>(value);
            return *this;
        }

        __pointer_plus_bit& operator|=(u32 value)
        {
            ptr_ = reinterpret_cast<node_base*>(reinterpret_cast<u32>(ptr_) | value);
            return *this;
        }

        void set_black() { ptr_ = reinterpret_cast<node_base*>(reinterpret_cast<u32>(ptr_) & ~1u); }
    };

    // total size: 0xC
    class node_base {
    public:
        node_base* left_;           // offset 0x0, size 0x4
        node_base* right_;          // offset 0x4, size 0x4
        __pointer_plus_bit parent_; // offset 0x8, size 0x4 (pointer + color bit)
    };

    static const node_base* parent(const node_base* node);
    static node_base* parent(node_base* node)
    {
        return reinterpret_cast<node_base*>(node->parent_ & ~1u);
    }

    static bool is_red(const node_base* node) { return (node->parent_ & 1u) != 0; }

    static void set_red(node_base* node) { node->parent_ |= 1u; }
    static void set_black(node_base* node) { node->parent_.set_black(); }

    static void increment(const node_base*& node);
    static void decrement(const node_base*& node);
    static void balance_insert(node_base* node, node_base* root);
    static void rotate_left(node_base* node, node_base*& root);
    static void rotate_right(node_base* node, node_base*& root);
};

template <class First, class Second>
class pair {
public:
    First first;
    Second second;

    pair() {}
    pair(const First& first_, const Second& second_) : first(first_), second(second_) {}

    template <class U, class V>
    pair(const pair<U, V>& other);
};

template <class First, class Second>
template <class U, class V>
pair<First, Second>::pair(const pair<U, V>& other) : first(other.first), second(other.second)
{
}

template <class Arg1, class Arg2, class Result>
class binary_function_t {};

template <class T>
class less : public binary_function_t<T, T, bool> {
public:
    bool operator()(const T& lhs, const T& rhs) const { return lhs < rhs; }
};

template <class T>
class equal_to : public binary_function_t<T, T, bool> {
public:
    bool operator()(const T& lhs, const T& rhs) const { return lhs == rhs; }
};

template <class Operation, class Bound>
class binder2nd {
public:
    Operation operation_;
    Bound value_;

    binder2nd(const Operation& operation, Bound value) : operation_(operation), value_(value) {}

    template <class Arg>
    bool operator()(const Arg& value) const
    {
        return operation_(value, value_);
    }
};

struct bidirectional_iterator_tag {};

template <class BidirectionalIterator, class Distance>
inline void __advance(BidirectionalIterator& iterator,
                      Distance distance,
                      bidirectional_iterator_tag)
{
    if (distance >= 0) {
        for (; distance > 0; --distance) {
            ++iterator;
        }
    } else {
        for (; distance < 0; ++distance) {
            --iterator;
        }
    }
}

template <class Iterator>
struct iterator_traits {
    typedef typename Iterator::iterator_category iterator_category;
};

template <class Iterator>
inline typename iterator_traits<Iterator>::iterator_category __iterator_category(const Iterator&)
{
    return typename iterator_traits<Iterator>::iterator_category();
}

template <class BidirectionalIterator, class Distance>
inline void advance(BidirectionalIterator& iterator, Distance distance)
{
    __advance(iterator, distance, __iterator_category(iterator));
}

template <class Iterator>
class reverse_iterator {
public:
    Iterator current;

    reverse_iterator() {}
    explicit reverse_iterator(Iterator iterator) : current(iterator) {}

    reverse_iterator& operator++()
    {
        __red_black_tree<1>::decrement(
            reinterpret_cast<const __red_black_tree<1>::node_base*&>(current.ptr_));
        return *this;
    }

    typename Iterator::value_type* operator->() const
    {
        Iterator iterator(current);
        __red_black_tree<1>::decrement(
            reinterpret_cast<const __red_black_tree<1>::node_base*&>(iterator.ptr_));
        return iterator.operator->();
    }
};

template <class Iterator>
bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
    return lhs.current.ptr_ != rhs.current.ptr_;
}

template <class T, class A>
class __list_deleter {
public:
    class node;

    // total size: 0x8
    class node_base {
    public:
        node* prev_; // offset 0x0, size 0x4
        node* next_; // offset 0x4, size 0x4
    };

    // total size: 0xC for the type-erased list node used here
    class node : public node_base {
    public:
        T data_; // offset 0x8
    };

    typedef oostd::clsOOStlAllocator<node> node_allocator;

    // The original cleanup-helper names and exact type decomposition are
    // not recoverable from the available symbols/DWARF. The target supports
    // a two-word node ownership guard plus an additional short-lived class
    // temporary in the cleanup path. node_deallocator is a neutral model
    // of that temporary, not a recovered historical type.
    class node_deallocator {
    public:
        node_allocator* allocator_;

        node_deallocator(node_allocator& allocator) : allocator_(&allocator) {}

        void operator()(node* ptr) const { allocator_->deallocate(ptr, 1); }
    };

    class node_guard {
    public:
        node_allocator* allocator_;
        node* ptr_;

        node_guard(node_allocator& allocator, node* ptr) : allocator_(&allocator), ptr_(ptr) {}

        ~node_guard()
        {
            if (ptr_ != 0) {
                node_deallocator cleanup(*allocator_);
                cleanup(ptr_);
            }
        }

        node* operator->() const { return ptr_; }

        node* release()
        {
            node* ptr = ptr_;
            ptr_ = 0;
            return ptr;
        }
    };

    template <int N>
    class generic_iterator {
    public:
        typedef bidirectional_iterator_tag iterator_category;
        node* node_; // offset 0x0, size 0x4

        generic_iterator() {}
        explicit generic_iterator(node* node) : node_(node) {}
        generic_iterator(const generic_iterator& rhs) : node_(rhs.node_) {}
        generic_iterator& operator++()
        {
            node_ = node_->next_;
            return *this;
        }
        generic_iterator& operator--()
        {
            node_ = node_->prev_;
            return *this;
        }
    };

    typedef Metrowerks::compressed_pair<A, u32> size_pair;
    typedef Metrowerks::compressed_pair<node_allocator, node_base> end_pair;

    size_pair size_; // offset 0x0, size 0x8
    end_pair end_;   // offset 0x8, size 0xC

    class temp_init_t {};

    __list_deleter() {}
    __list_deleter(const A& allocator);
    __list_deleter(const A& allocator, const temp_init_t*)
        : size_(allocator, Metrowerks::details::copy_first_zero_second_t()),
          end_(size_.first(), Metrowerks::details::copy_first_noinit_second_t())
    {
        node_base& sentinel = end_.second();
        sentinel.next_ = reinterpret_cast<node*>(&sentinel);
        sentinel.prev_ = reinterpret_cast<node*>(&sentinel);
    }

    typedef generic_iterator<0> iterator0;

    A& alloc() { return size_.first(); }
    node_allocator& node_alloc() { return end_.first(); }

    iterator0 end();

    iterator0 erase(iterator0 first, iterator0 last);
    iterator0 erase(iterator0 position);

    iterator0 erase_nodes(iterator0 first, iterator0 last)
    {
        node_base* first_node = first.node_;
        if (first_node == last.node_)
            return last;
        node_base* last_prev = last.node_->prev_;
        first_node->prev_->next_ = last_prev->next_;
        last_prev->next_->prev_ = first_node->prev_;
        while (first.node_ != last.node_) {
            node* current = static_cast<node*>(first.node_);
            first.node_ = first.node_->next_;
            node_alloc().destroy(current);
            node_alloc().deallocate(current, 1);
            --size_.second();
        }
        return last;
    }
    iterator0 insert(iterator0 position, const T& value);
    void splice(iterator0 position, __list_deleter& other);

    void clear();

    ~__list_deleter()
    {
        erase(iterator0(end_.second().next_), iterator0(reinterpret_cast<node*>(&end_.second())));
    }
};

template <class T, class A>
__list_deleter<T, A>::__list_deleter(const A& allocator)
    : size_(allocator, Metrowerks::details::copy_first_zero_second_t()),
      end_(size_.first(), Metrowerks::details::copy_first_noinit_second_t())
{
    node_base& sentinel = end_.second();
    sentinel.next_ = reinterpret_cast<node*>(&sentinel);
    sentinel.prev_ = reinterpret_cast<node*>(&sentinel);
}

template <class T, class A>
typename __list_deleter<T, A>::iterator0 __list_deleter<T, A>::erase(iterator0 first,
                                                                     iterator0 last)
{
    node_base* first_node = first.node_;
    if (first_node == last.node_)
        return last;
    node_base* last_prev = last.node_->prev_;
    first_node->prev_->next_ = last_prev->next_;
    last_prev->next_->prev_ = first_node->prev_;
    while (first.node_ != last.node_) {
        node* current = static_cast<node*>(first.node_);
        first.node_ = first.node_->next_;
        node_alloc().destroy(current);
        node_alloc().deallocate(current, 1);
        --size_.second();
    }
    return last;
}

template <class T, class A>
typename __list_deleter<T, A>::iterator0 __list_deleter<T, A>::erase(iterator0 position)
{
    node* current = static_cast<node*>(position.node_);
    ++position;
    current->prev_->next_ = current->next_;
    current->next_->prev_ = current->prev_;
    node_alloc().destroy(current);
    node_alloc().deallocate(current, 1);
    --size_.second();
    return position;
}

template <class T, class A>
void __list_deleter<T, A>::clear()
{
    erase(generic_iterator<0>(end_.second().next_),
          generic_iterator<0>(reinterpret_cast<node*>(&end_.second())));
}

template <class T, class A>
typename __list_deleter<T, A>::iterator0 __list_deleter<T, A>::insert(iterator0 position,
                                                                      const T& value)
{
    node_guard hold(node_alloc(), node_alloc().allocate(1));
    alloc().construct(&hold->data_, value);

    node* new_node = hold.release();
    position.node_->prev_->next_ = new_node;
    new_node->prev_ = position.node_->prev_;
    position.node_->prev_ = new_node;
    new_node->next_ = reinterpret_cast<node*>(position.node_);
    ++size_.second();
    return iterator0(new_node);
}

template <class T, class A>
void __list_deleter<T, A>::splice(iterator0 position, __list_deleter& other)
{
    if (other.size_.second() != 0) {
        node* first = other.end_.second().next_;
        node* last = other.end_.second().prev_;
        other.end_.second().next_ = reinterpret_cast<node*>(&other.end_.second());
        other.end_.second().prev_ = reinterpret_cast<node*>(&other.end_.second());

        position.node_->prev_->next_ = first;
        first->prev_ = position.node_->prev_;
        position.node_->prev_ = last;
        last->next_ = reinterpret_cast<node*>(position.node_);

        size_.second() += other.size_.second();
        other.size_.second() = 0;
    }
}

template <class T, class A>
class __list_imp : private __list_deleter<T, A> {
    typedef __list_deleter<T, A> Base;

protected:
    __list_imp() : Base() {}
    __list_imp(const A& allocator) : Base(allocator) {}
    __list_imp(const A& allocator, u32 count, const T& value)
        : Base(allocator, static_cast<const typename Base::temp_init_t*>(0))
    {
        init(count, value);
    }

    typedef typename Base::iterator0 base_iterator;
    typedef typename Base::node base_node;
    typedef typename Base::node_base base_node_base;

    typename Base::node_base* begin_node() { return this->end_.second().next_; }
    typename Base::node_base* end_node() { return &this->end_.second(); }

    using Base::insert;

public:
    void init(u32 n, const T& value);
    void insert(base_iterator position, u32 count, const T& value);
    base_iterator advance_to(u32 index);
    void resize(u32 size);

    template <class Predicate>
    void remove_if(Predicate predicate);

    bool empty() const { return this->size_.second() == 0; }
};

template <class T, class A>
typename __list_deleter<T, A>::iterator0 __list_deleter<T, A>::end()
{
    return iterator0(reinterpret_cast<node*>(&end_.second()));
}

template <class T, class A>
void __list_imp<T, A>::init(u32 n, const T& value)
{
    while (n != 0) {
        Base::insert(Base::end(), value);
        --n;
    }
}

template <class T, class A>
void __list_imp<T, A>::insert(base_iterator position, u32 count, const T& value)
{
    __list_imp temp(this->alloc(), count, value);
    this->splice(position, temp);
}

template <class T, class A>
template <class Predicate>
void __list_imp<T, A>::remove_if(Predicate predicate)
{
    base_iterator current(this->end_.second().next_);
    base_iterator last(reinterpret_cast<typename Base::node*>(&this->end_.second()));

    for (; current.node_ != last.node_; current.node_ = current.node_->next_) {
        if (predicate(static_cast<typename Base::node*>(current.node_)->data_)) {
            base_iterator next(current);
            ++next;
            while (next.node_ != last.node_) {
                if (!predicate(static_cast<typename Base::node*>(next.node_)->data_)) {
                    break;
                }
                next.node_ = next.node_->next_;
            }
            current = this->erase_nodes(current, next);
            if (current.node_ == last.node_) {
                break;
            }
        }
    }
}

template <class T, class A>
void __list_imp<T, A>::resize(u32 size)
{
    if (this->size_.second() < size) {
        base_iterator last(reinterpret_cast<typename Base::node*>(&this->end_.second()));
        u32 count = size - this->size_.second();
        const T value = T();
        insert(last, count, value);
    } else if (size < this->size_.second()) {
        this->erase_nodes(
            advance_to(size),
            base_iterator(reinterpret_cast<typename Base::node*>(&this->end_.second())));
    }
}

template <class T, class A>
typename __list_imp<T, A>::base_iterator __list_imp<T, A>::advance_to(u32 index)
{
    base_iterator iterator;
    if (index <= (this->size_.second() >> 1)) {
        iterator.node_ = this->end_.second().next_;
        std::advance(iterator, static_cast<s32>(index));
    } else {
        iterator.node_ = reinterpret_cast<typename Base::node*>(&this->end_.second());
        std::advance(iterator, static_cast<s32>(index - this->size_.second()));
    }
    return iterator;
}

template <class T, class A>
class list : private __list_imp<const void*, oostd::clsOOStlAllocator<const void*> > {
    typedef __list_imp<const void*, oostd::clsOOStlAllocator<const void*> > Base;
    typedef typename Base::base_iterator list_base_iterator;
    typedef typename Base::base_node list_base_node;

public:
    template <int N>
    class generic_iterator {
    public:
        list_base_iterator i_; // offset 0x0, size 0x4

        generic_iterator() {}

        explicit generic_iterator(void* node) : i_(static_cast<list_base_node*>(node)) {}

        generic_iterator(const generic_iterator& rhs) : i_(rhs.i_) {}

        generic_iterator& operator++()
        {
            ++i_;
            return *this;
        }

        T& operator*() const
        {
            return *reinterpret_cast<T*>(static_cast<u8*>(static_cast<void*>(i_.node_)) + 8);
        }

        friend bool operator==(const generic_iterator& lhs, const generic_iterator& rhs)
        {
            return lhs.i_.node_ == rhs.i_.node_;
        }

        friend bool operator!=(const generic_iterator& lhs, const generic_iterator& rhs)
        {
            return lhs.i_.node_ != rhs.i_.node_;
        }
    };

    typedef generic_iterator<0> iterator;

    iterator begin() { return generic_iterator<0>(Base::begin_node()); }

    iterator end() { return generic_iterator<0>(Base::end_node()); }

    bool empty() const { return Base::empty(); }

    void resize(u32 size);

    iterator insert(iterator position, const T& value);

    list(const A& allocator) : Base(oostd::clsOOStlAllocator<const void*>(allocator)) {}
};

template <class T, class A>
void list<T, A>::resize(u32 size)
{
    Base::resize(size);
}

template <class T, class A>
typename list<T, A>::iterator list<T, A>::insert(iterator position, const T& value)
{
    typename Base::base_iterator result =
        Base::insert(position.i_, reinterpret_cast<const void* const&>(value));
    return iterator(result.node_);
}

template <class Value, class Compare, class Allocator>
class __tree {
public:
    // The PS2 STL stores three compressed pairs.  Their concrete flattened
    // layout is verified from the prototype DWARF.
    class node;

    // total size: 0x4
    class anchor {
    public:
        node* left_; // offset 0x0, size 0x4

        anchor() : left_(0) {}
    };

    typedef typename __allocator_rebind<Allocator, node>::type node_allocator;
    typedef Metrowerks::compressed_pair<Allocator, u32> alloc_pair;
    typedef Metrowerks::compressed_pair<node_allocator, anchor> node_alloc_pair;
    typedef Metrowerks::compressed_pair<Compare, node*> comp_pair;

    // total size: 0xC
    class node_base {
    public:
        node* left_;                                              // offset 0x0, size 0x4
        node* right_;                                             // offset 0x4, size 0x4
        typename __red_black_tree<1>::__pointer_plus_bit parent_; // offset 0x8, size 0x4
    };

    // total size: sizeof(node_base) + sizeof(Value)
    class node : public node_base {
    public:
        Value data_; // offset 0xC
    };

    template <int N>
    class __generic_iterator {
    public:
        typedef Value value_type;

        node_base* ptr_; // offset 0x0, size 0x4

        __generic_iterator() {}
        __generic_iterator(node_base* node) : ptr_(node) {}

        __generic_iterator& operator=(const __generic_iterator& rhs)
        {
            ptr_ = rhs.ptr_;
            return *this;
        }

        __generic_iterator& operator++()
        {
            __red_black_tree<1>::increment(
                reinterpret_cast<const __red_black_tree<1>::node_base*&>(ptr_));
            return *this;
        }

        Value* operator->() const { return &static_cast<node*>(ptr_)->data_; }

        friend bool operator==(const __generic_iterator& lhs, const __generic_iterator& rhs)
        {
            return lhs.ptr_ == rhs.ptr_;
        }

        friend bool operator!=(const __generic_iterator& lhs, const __generic_iterator& rhs)
        {
            return lhs.ptr_ != rhs.ptr_;
        }
    };

    typedef __generic_iterator<0> iterator;

    alloc_pair alloc_;           // offset 0x0, size 0x8
    node_alloc_pair node_alloc_; // offset 0x8, size 0x8
    comp_pair comp_;             // offset 0x10, size 0x8

    __tree(const Compare& compare, const Allocator& allocator);

    Allocator& alloc() { return alloc_.first(); }
    node_allocator& node_alloc() { return node_alloc_.first(); }

    void destroy(node* root);

    pair<iterator, bool> insert_one(const Value& value);
    iterator insert_multi(const Value& value);
    node* insert_node_at(node* parent, bool insert_left, bool update_begin, const Value& value);

    template <class Key>
    iterator find(const Key& key);

    void clear();

    ~__tree()
    {
        if (node_alloc_.second().left_ != 0) {
            destroy(node_alloc_.second().left_);
        }
    }
};

template <class Value, class Compare, class Allocator>
__tree<Value, Compare, Allocator>::__tree(const Compare& compare, const Allocator& allocator)
    : alloc_(allocator), node_alloc_(allocator),
      comp_(compare, reinterpret_cast<node*>(&node_alloc_.second()))
{
}

template <class Value, class Compare, class Allocator>
void __tree<Value, Compare, Allocator>::destroy(node* root)
{
    if (root->left_ != 0) {
        destroy(root->left_);
    }
    if (root->right_ != 0) {
        destroy(root->right_);
    }
    alloc().destroy(&root->data_);
    node_alloc().deallocate(root, 1);
}

template <class Value, class Compare, class Allocator>
void __tree<Value, Compare, Allocator>::clear()
{
    if (node_alloc_.second().left_ != 0) {
        destroy(node_alloc_.second().left_);
        alloc_.second() = 0;
        node_alloc_.second().left_ = 0;
        comp_.second() = reinterpret_cast<node*>(&node_alloc_.second());
    }
}

template <class Value, class Compare, class Allocator>
typename __tree<Value, Compare, Allocator>::node* __tree<Value, Compare, Allocator>::insert_node_at(
    node* parent, bool insert_left, bool update_begin, const Value& value)
{
    if (alloc_.second() > 0xffffffffu - 1u) {
        ::fprintf(reinterpret_cast<void**>(::_impure_ptr)[3], "tree::insert length error\n");
        ::abort();
    }

    node* new_node = node_alloc().allocate(1);
    if (__allocator_rebind<Allocator, node>::is_std && new_node == 0) {
        ::fprintf(reinterpret_cast<void**>(::_impure_ptr)[3], "Memory allocation failure");
        ::abort();
    }
    Value* value_ptr = &new_node->data_;
    new (value_ptr) Value(value);
    new_node->right_ = 0;
    new_node->left_ = 0;
    new_node->parent_ = reinterpret_cast<u32>(parent) | (new_node->parent_ & 1u);

    if (insert_left) {
        parent->left_ = new_node;
    } else {
        parent->right_ = new_node;
    }

    ++alloc_.second();
    __red_black_tree<1>::balance_insert(
        reinterpret_cast<__red_black_tree<1>::node_base*>(new_node),
        reinterpret_cast<__red_black_tree<1>::node_base*>(node_alloc_.second().left_));

    if (update_begin) {
        comp_.second() = new_node;
    }
    return new_node;
}

template <class Value, class Compare, class Allocator>
pair<typename __tree<Value, Compare, Allocator>::iterator, bool> __tree<Value, Compare, Allocator>::
    insert_one(const Value& value)
{
    node* previous = 0;
    node* parent = reinterpret_cast<node*>(&node_alloc_.second());
    node* current = node_alloc_.second().left_;
    bool insert_left = true;
    bool update_begin = true;

    while (current != 0) {
        parent = current;
        if (comp_.first()(value, current->data_)) {
            current = current->left_;
            insert_left = true;
        } else {
            previous = current;
            current = current->right_;
            insert_left = false;
            update_begin = false;
        }
    }

    if (previous == 0 || comp_.first()(previous->data_, value)) {
        return pair<iterator, bool>(insert_node_at(parent, insert_left, update_begin, value), true);
    }
    return pair<iterator, bool>(previous, false);
}

template <class Value, class Compare, class Allocator>
template <class Key>
typename __tree<Value, Compare, Allocator>::iterator __tree<Value, Compare, Allocator>::find(
    const Key& key)
{
    node* current = node_alloc_.second().left_;
    node* result = reinterpret_cast<node*>(&node_alloc_.second());

    while (current != 0) {
        if (!comp_.first()(current->data_, key)) {
            result = current;
            current = current->left_;
        } else {
            current = current->right_;
        }
    }

    if (result == reinterpret_cast<node*>(&node_alloc_.second()) ||
        comp_.first()(key, result->data_))
    {
        return iterator(reinterpret_cast<node_base*>(&node_alloc_.second()));
    }
    return iterator(result);
}

template <class Value, class Compare, class Allocator>
typename __tree<Value, Compare, Allocator>::iterator __tree<Value, Compare, Allocator>::
    insert_multi(const Value& value)
{
    node* parent = reinterpret_cast<node*>(&node_alloc_.second());
    node* current = node_alloc_.second().left_;
    bool insert_left = true;
    bool update_begin = true;

    while (current != 0) {
        parent = current;
        if (comp_.first()(value, current->data_)) {
            current = current->left_;
            insert_left = true;
        } else {
            current = current->right_;
            insert_left = false;
            update_begin = false;
        }
    }

    return iterator(insert_node_at(parent, insert_left, update_begin, value));
}

template <class Key, class T, class Compare, class Allocator>
class map {
public:
    typedef pair<const Key, T> value_type;

    class value_compare : public binary_function_t<value_type, value_type, bool> {
    public:
        Compare comp; // offset 0x0, size 0x1 for std::less<u32>

        value_compare(Compare compare) : comp(compare) {}

        bool operator()(const value_type& lhs, const value_type& rhs) const
        {
            return comp(lhs.first, rhs.first);
        }

        bool operator()(const value_type& lhs, const Key& rhs) const
        {
            return comp(lhs.first, rhs);
        }

        bool operator()(const Key& lhs, const value_type& rhs) const
        {
            return comp(lhs, rhs.first);
        }
    };

    typedef __tree<value_type, value_compare, Allocator> tree_type;

    tree_type tree_; // offset 0x0, size 0x18

    typedef typename tree_type::iterator iterator;

    map(const Compare& compare, const Allocator& allocator)
        : tree_(value_compare(compare), allocator)
    {
    }

    iterator begin();
    iterator end();

    pair<iterator, bool> insert(const value_type& value) { return tree_.insert_one(value); }

    iterator find(const Key& key) { return tree_.find(key); }
};

template <class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::begin()
{
    iterator result;
    result.ptr_ = tree_.comp_.second();
    return result;
}

template <class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::end()
{
    iterator result;
    result.ptr_ = reinterpret_cast<typename tree_type::node_base*>(&tree_.node_alloc_.second());
    return result;
}

template <int N>
void __red_black_tree<N>::balance_insert(node_base* node, node_base* root)
{
    set_red(node);
    node_base* parent_node;
    while (node != root && is_red(parent_node = parent(node)) == true) {
        if (parent_node == parent(parent_node)->left_) {
            node_base* uncle = parent(parent_node)->right_;
            if (uncle != 0 && is_red(uncle) == true) {
                set_black(parent(node));
                set_black(uncle);
                node = parent(parent(node));
                set_red(node);
            } else {
                if (node == parent(node)->right_) {
                    node = parent(node);
                    rotate_left(node, root);
                }
                set_black(parent(node));
                set_red(parent(parent(node)));
                rotate_right(parent(parent(node)), root);
            }
        } else {
            node_base* uncle = parent(parent_node)->left_;
            if (uncle != 0 && is_red(uncle) == true) {
                set_black(parent(node));
                set_black(uncle);
                node = parent(parent(node));
                set_red(node);
            } else {
                if (node == parent(node)->left_) {
                    node = parent(node);
                    rotate_right(node, root);
                }
                set_black(parent(node));
                set_red(parent(parent(node)));
                rotate_left(parent(parent(node)), root);
            }
        }
    }
    set_black(root);
}

template <int N>
void __red_black_tree<N>::rotate_right(node_base* node, node_base*& root)
{
    node_base* pivot = node->left_;
    if (root == node) {
        root = pivot;
    }

    node->left_ = pivot->right_;
    if (pivot->right_ != 0) {
        pivot->right_->parent_ = reinterpret_cast<u32>(node) | (pivot->right_->parent_ & 1u);
    }

    pivot->parent_ = (node->parent_ & ~1u) | (pivot->parent_ & 1u);
    node_base* parent_node = reinterpret_cast<node_base*>(node->parent_ & ~1u);
    if (node == parent_node->left_) {
        parent_node->left_ = pivot;
    } else {
        parent_node->right_ = pivot;
    }

    pivot->right_ = node;
    node->parent_ = reinterpret_cast<u32>(pivot) | (node->parent_ & 1u);
}

template <int N>
void __red_black_tree<N>::rotate_left(node_base* node, node_base*& root)
{
    node_base* pivot = node->right_;
    if (root == node) {
        root = pivot;
    }

    node->right_ = pivot->left_;
    if (pivot->left_ != 0) {
        pivot->left_->parent_ = reinterpret_cast<u32>(node) | (pivot->left_->parent_ & 1u);
    }

    pivot->parent_ = (node->parent_ & ~1u) | (pivot->parent_ & 1u);
    node_base* parent_node = reinterpret_cast<node_base*>(node->parent_ & ~1u);
    if (node == parent_node->left_) {
        parent_node->left_ = pivot;
    } else {
        parent_node->right_ = pivot;
    }

    pivot->left_ = node;
    node->parent_ = reinterpret_cast<u32>(pivot) | (node->parent_ & 1u);
}

template <int N>
const typename __red_black_tree<N>::node_base* __red_black_tree<N>::parent(const node_base* node)
{
    return reinterpret_cast<const node_base*>(node->parent_ & ~1u);
}

template <int N>
void __red_black_tree<N>::increment(const node_base*& node)
{
    if (node->right_ != 0) {
        const node_base* next = node->right_;
        while (next->left_ != 0) {
            next = next->left_;
        }
        node = next;
    } else {
        while (node != reinterpret_cast<const node_base*>(node->parent_ & ~1u)->left_) {
            node = reinterpret_cast<const node_base*>(node->parent_ & ~1u);
        }
        node = reinterpret_cast<const node_base*>(node->parent_ & ~1u);
    }
}

template <int N>
void __red_black_tree<N>::decrement(const node_base*& node)
{
    if (node->left_ != 0) {
        const node_base* previous = node->left_;
        const node_base* next = previous->right_;
        while (next != 0) {
            previous = next;
            next = next->right_;
        }
        node = previous;
    } else {
        while (node == reinterpret_cast<const node_base*>(node->parent_ & ~1u)->left_) {
            node = reinterpret_cast<const node_base*>(node->parent_ & ~1u);
        }
        node = reinterpret_cast<const node_base*>(node->parent_ & ~1u);
    }
}

template <class Key, class T, class Compare, class Allocator>
class multimap {
public:
    typedef pair<const Key, T> value_type;

    class value_compare : public binary_function_t<value_type, value_type, bool> {
    public:
        Compare comp;

        value_compare(Compare compare) : comp(compare) {}

        bool operator()(const value_type& lhs, const value_type& rhs) const
        {
            return comp(lhs.first, rhs.first);
        }
    };

    typedef __tree<value_type, value_compare, Allocator> tree_type;
    typedef typename tree_type::iterator iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;

    tree_type tree_;

    reverse_iterator rbegin()
    {
        reverse_iterator result;
        result.current.ptr_ =
            reinterpret_cast<typename tree_type::node_base*>(&tree_.node_alloc_.second());
        return result;
    }

    reverse_iterator rend()
    {
        reverse_iterator result;
        result.current.ptr_ = tree_.comp_.second();
        return result;
    }

    bool empty() const { return tree_.alloc_.second() == 0; }

    void clear() { tree_.clear(); }
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
