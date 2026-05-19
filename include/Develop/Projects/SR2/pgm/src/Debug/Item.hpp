#ifndef ITEM_HPP
#define ITEM_HPP

#include "types.h"

// total size: 0x4
struct stcItem {
    u8 bEnableItemDebug; // offset 0x0, size 0x1
    s16 s16SelectItem;   // offset 0x2, size 0x2
};

#endif // ITEM_HPP
