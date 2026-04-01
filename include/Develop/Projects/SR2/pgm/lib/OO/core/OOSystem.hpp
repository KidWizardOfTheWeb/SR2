#ifndef OOSYSTEM_HPP
#define OOSYSTEM_HPP

// OO system base
class clsOOSystem {
public:
    void* __vtable;               // 0x00
    int   m_eSoundMode;           // 0x04
    int   m_eMessageLanguage;     // 0x08
    int   m_eVoiceLanguage;       // 0x0C
    float m_f32FrameRate;         // 0x10
    float m_f32FrameRateAdd;      // 0x14
    float m_f32FrameRateAdd2;     // 0x18
};

#endif // OOSYSTEM_HPP
