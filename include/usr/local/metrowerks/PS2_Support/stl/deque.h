#ifndef DEQUE_H
#define DEQUE_H

// Metrowerks MWCC PS2 STL deque — minimal layout skeleton
// Field layouts verified against DWARF. Internal STL types may use raw C++ types.

// Empty base classes (empty-base optimization targets)
class compile_assert {}; // size 0x1
class allocator {};      // size 0x1
class __deque_buf {};    // size 0x1

// cdeque: internal single-level deque core, size 0x10
class __cdeque_deleter_common {
public:
    unsigned int capacity_; // offset 0x0, size 0x4 (compressed_pair<allocator,u32> via EBO)
    unsigned int size_;     // offset 0x4, size 0x4
    unsigned int start_;    // offset 0x8, size 0x4
    unsigned int* data_;    // offset 0xC, size 0x4
}; // total size: 0x10

class __cdeque_deleter : public __cdeque_deleter_common {}; // total size: 0x10

class __cdeque_imp : public __cdeque_deleter, private compile_assert {}; // total size: 0x10

class cdeque : private __cdeque_imp {}; // total size: 0x10

// deque: outer two-level deque, size 0x18
// __deque_deleter_common inherits __deque_buf (EBO), holds compressed_pair<allocator,cdeque>
// which via EBO is just cdeque at offset 0x0
class __deque_deleter_common : private __deque_buf {
public:
    cdeque buf_;         // offset 0x0, size 0x10 (compressed_pair<allocator,cdeque> via EBO)
    unsigned int start_; // offset 0x10, size 0x4
    unsigned int size_;  // offset 0x14, size 0x4
}; // total size: 0x18

class __deque_deleter : public __deque_deleter_common {}; // total size: 0x18

class __deque_imp : public __deque_deleter, private compile_assert {}; // total size: 0x18

class deque : private __deque_imp {}; // total size: 0x18

#endif // DEQUE_H
