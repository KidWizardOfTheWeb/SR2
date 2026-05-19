#ifndef SCRIPTOBJECT_HPP
#define SCRIPTOBJECT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"

// total size: 0x20
struct stcScriptObject {
    u8 u8Type;         // offset 0x0, size 0x1
    c8* pc8Name;       // offset 0x4, size 0x4
    vector vecsFunc;   // offset 0x8, size 0xC
    vector vecsMember; // offset 0x14, size 0xC
};

#endif // SCRIPTOBJECT_HPP
