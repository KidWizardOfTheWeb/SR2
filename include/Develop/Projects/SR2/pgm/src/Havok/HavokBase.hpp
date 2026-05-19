#ifndef HAVOKBASE_HPP
#define HAVOKBASE_HPP

#include "types.h"

class clsHavokBase {
public:
    static void initMemory(u32 u32Param1);
    static void resetMemory();
    static void exitMemory();

    static u8 t_cMemoryManager[0xA30];
    static void* t_pcThreadMemory;
};

extern c8 HK_KEYCODE[21];
extern u32 HK_KEYVALUE;
void tErrorReport(c8* msg);

#endif // HAVOKBASE_HPP
