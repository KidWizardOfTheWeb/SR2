#ifndef PS2SEMAPHORE_HPP
#define PS2SEMAPHORE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOSemaphore.hpp"

// total size: 0x8
class clsPfSemaphore : public clsOOSemaphore {
public:
    clsPfSemaphore() {}
    clsPfSemaphore(s32 s32InitCountI, s32 s32MaxCountI);
    virtual ~clsPfSemaphore();
    virtual void reinit();
    virtual void wait() {}
    virtual void signal() {}

    static clsOOSemaphore* createInstance(s32 s32InitCountI, s32 s32MaxCountI)
    {
        return new clsPfSemaphore(s32InitCountI, s32MaxCountI);
    }
    static void deleteInstance(clsOOSemaphore* pcSemaphore) { delete pcSemaphore; }

    s32 m_s32Id; // offset 0x4, size 0x4
};

// total size: 0x4
class clsPfSemaphoreObject {
public:
    clsPfSemaphore& m_semaphore; // offset 0x0, size 0x4
};

#endif // PS2SEMAPHORE_HPP
