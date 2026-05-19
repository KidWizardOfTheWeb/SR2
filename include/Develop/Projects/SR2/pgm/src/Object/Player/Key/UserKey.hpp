#ifndef USERKEY_HPP
#define USERKEY_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Key/PlayerKey.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Key/ReplayKey.hpp"

class clsPlayerTask;

// total size: 0x40
class clsUserKey : public clsPlayerKey {
public:
    virtual ~clsUserKey() {}
    virtual void reset() {}

    void updateKey();
    void requestRumble(u32 u32Param1) {}
    void playSfSe_User(s32 s32Param1) {}
    void playSfSe_Com(s32 s32Param1) {}
    void playSfPadSe(s32 s32Param1) {}
    void stopSfPadSe(s32 s32Param1) {}

    u32 m_u32PadNo;              // offset 0x34, size 0x4
    clsReplayKey* m_pcReplayKey; // offset 0x38, size 0x4
    clsPlayerTask* m_pcPlayer;   // offset 0x3C, size 0x4
};

#endif // USERKEY_HPP
