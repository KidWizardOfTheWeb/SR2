#ifndef PLAYERDATA_HPP
#define PLAYERDATA_HPP

#include "types.h"

class clsPlayerTask;

// total size: 0x14
class _stcPlayerData {
public:
    // Note: enmControlMode name collision with TutorialRace.hpp — nested variant
    enum enmControlMode {
        CONTROL_FOLLOW = 0,
        CONTROL_MAIN = 1,
    };

    // Members
    enmControlMode eControlMode; // offset 0x0, size 0x4
    s32 A32RotateY;              // offset 0x4, size 0x4
    clsPlayerTask* pcPlayerTask; // offset 0x8, size 0x4
    u32 u32LeafNo;               // offset 0xC, size 0x4
    f32 f32FollowFrame;          // offset 0x10, size 0x4
};

// total size: 0x8
struct stcPlayerData {
    f32 f32OldZ;  // offset 0x0, size 0x4
    u8 u8TrgFlg;  // offset 0x4, size 0x1
    u8 u8Padd[3]; // offset 0x5, size 0x3
};

#endif // PLAYERDATA_HPP
