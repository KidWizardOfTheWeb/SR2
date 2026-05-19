#ifndef CHARANODEBASE_HPP
#define CHARANODEBASE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/Character.hpp"

// total size: 0x60 (same as clsCharacter — no own fields)
class clsCharaNodeBase : public clsCharacter {
public:
    clsCharaNodeBase(clsPlayerTask* pParam1, u8 u8Param2, u8 u8Param3);
    virtual ~clsCharaNodeBase() {}
    virtual void draw(u32 u32Param1) {}
    virtual s8 getNodeIndex(clsCharacter::enmCharaBornNo) const;

    static s8 as8ConvertTable[52];
};

#endif // CHARANODEBASE_HPP
