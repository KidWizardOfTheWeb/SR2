#ifndef REPLAYKEY_HPP
#define REPLAYKEY_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Key/PlayerKey.hpp"

class clsPlayerTask;
class clsUserKey;

// total size: 0x48
class clsReplayKey : public clsPlayerKey {
public:
    clsReplayKey(clsPlayerTask* pcParam1) : clsPlayerKey(), m_s32BufPos(0), m_pcPlayer(pcParam1) {}
    virtual ~clsReplayKey() {}
    virtual void requestRumble(u32 u32Param1) {}
    virtual void playSfSe_User(s32 s32Param1) {}
    virtual void playSfSe_Com(s32 s32Param1) {}
    virtual void playSfPadSe(s32 s32Param1) {}
    virtual void stopSfPadSe(s32 s32Param1) {}
    virtual void reset();
    virtual void updateKey();

    void addReplayKey(clsUserKey* pcUserKey);

    vector m_vecKeyBuf;        // offset 0x34, size 0xC
    s32 m_s32BufPos;           // offset 0x40, size 0x4
    clsPlayerTask* m_pcPlayer; // offset 0x44, size 0x4
};

#endif // REPLAYKEY_HPP
