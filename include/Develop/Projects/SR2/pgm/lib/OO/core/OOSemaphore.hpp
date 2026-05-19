#ifndef OOSEMAPHORE_HPP
#define OOSEMAPHORE_HPP

#include "types.h"

// total size: 0x4
class clsOOSemaphore {
public:
    virtual ~clsOOSemaphore() {}

    static clsOOSemaphore* (*s_pfCreateFunc)(s32, s32);
    static void (*s_pfDeleteFunc)(clsOOSemaphore*);

    void deleteInstance(clsOOSemaphore* p) {}
};

#endif // OOSEMAPHORE_HPP
