#ifndef OOMAINHEAP_HPP
#define OOMAINHEAP_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOHeapFragment.hpp"

// total size: 0x34
class clsOOMainHeap : public clsOOHeapFragment {
public:
    static clsOOMainHeap* getInstance() { return t_cInstance; }

    static clsOOMainHeap* t_cInstance;
};

#endif // OOMAINHEAP_HPP
