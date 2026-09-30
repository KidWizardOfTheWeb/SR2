#ifndef MACROS_H
#define MACROS_H

#include "types.h"
#include "usr/local/sce/ee/lib/libkernl/kprintf2.h"

#define SUPER_ASSERT(u32Id, pc8File, u32Line, pc8Message)                                          \
    do {                                                                                           \
        scePrintf("\n■■■■■■■\n");                                                                  \
        scePrintf(                                                                                 \
            "SUPER ASSERTION→ <0x%08x> %s(%d) in %s()\n", u32Id, pc8File, u32Line, __FUNCTION__);  \
        scePrintf("[%s] : ", "nakawatari");                                                        \
        scePrintf(pc8Message);                                                                     \
        scePrintf("■■■■■■■\n");                                                                    \
        ABORT();                                                                                   \
    } while (0)

#endif // MACROS_H
