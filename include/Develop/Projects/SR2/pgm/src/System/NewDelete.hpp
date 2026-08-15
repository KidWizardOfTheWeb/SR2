#ifndef NEWDELETE_HPP
#define NEWDELETE_HPP

#include "types.h"

inline void* operator new(u32, void* ptr)
{
    return ptr;
}

#endif // NEWDELETE_HPP
