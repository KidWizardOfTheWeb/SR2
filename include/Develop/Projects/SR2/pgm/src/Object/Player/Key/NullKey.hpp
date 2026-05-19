#ifndef NULLKEY_HPP
#define NULLKEY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Key/PlayerKey.hpp"

// total size: 0x34
class clsNullKey : public clsPlayerKey {
public:
    virtual ~clsNullKey() {}

    void reset();
    void updateKey();
    void requestRumble(u32 u32Param1) {}
    void playSfSe_User(s32 s32Param1) {}
    void playSfSe_Com(s32 s32Param1) {}
    void playSfPadSe(s32 s32Param1) {}
    void stopSfPadSe(s32 s32Param1) {}
};

#endif // NULLKEY_HPP
