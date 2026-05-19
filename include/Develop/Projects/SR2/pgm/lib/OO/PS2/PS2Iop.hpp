#ifndef PS2IOP_HPP
#define PS2IOP_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"

// total size: 0xC
struct stcIrxLoadInfo {
    c8* pc8Module; // offset 0x0, size 0x4
    c8* pc8Argp;   // offset 0x4, size 0x4
    u32 u32Args;   // offset 0x8, size 0x4
};

// total size: 0x4
class clsPfIop : public clsSingleton<clsPfIop> {
public:
    clsPfIop();
    virtual ~clsPfIop() {}
};

#endif // PS2IOP_HPP
