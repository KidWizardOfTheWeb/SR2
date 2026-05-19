#ifndef OOCRCCTRL_HPP
#define OOCRCCTRL_HPP

#include "types.h"

class clsOOCrcCtrl {
public:
    static void initCrcTbl(s32* ps32Param1);
    static u8 getCrc(const u8* pu8Param1, u32 u32Param2, u32* pu32Param3, const s32* ps32Param4);
};

#endif // OOCRCCTRL_HPP
