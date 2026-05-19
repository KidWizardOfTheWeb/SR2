#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2Semaphore.hpp"

// total size: 0x18
class SemaParam {
public:
    s32 currentCount;   // offset 0x0, size 0x4
    s32 maxCount;       // offset 0x4, size 0x4
    s32 initCount;      // offset 0x8, size 0x4
    s32 numWaitThreads; // offset 0xC, size 0x4
    u32 attr;           // offset 0x10, size 0x4
    u32 option;         // offset 0x14, size 0x4
};

clsPfSemaphore::clsPfSemaphore(s32 s32InitCountI, s32 s32MaxCountI)
{
}

clsPfSemaphore::~clsPfSemaphore()
{
}

void clsPfSemaphore::reinit()
{
}
