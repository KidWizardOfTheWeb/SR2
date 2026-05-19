#ifndef CHARAVOICE_HPP
#define CHARAVOICE_HPP

#include "types.h"

class clsPlayerTask;

namespace nspVoice {
enum enmVoiceType {};
} // namespace nspVoice

// total size: 0x10
class clsCharaVoice {
public:
    clsCharaVoice(clsPlayerTask* pcPlayer);
    virtual ~clsCharaVoice() {}

    void update();
    void playCharaVoice(nspVoice::enmVoiceType eVoiceType);

    clsPlayerTask* m_pcPlayer;       // offset 0x4, size 0x4
    f32 m_f32VoiceDelayFrameRunPast; // offset 0x8, size 0x4
    f32 m_f32VoiceDelayFrameAttack;  // offset 0xC, size 0x4
};

#endif // CHARAVOICE_HPP
