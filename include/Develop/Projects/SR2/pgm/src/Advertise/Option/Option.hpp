#ifndef OPTION_HPP
#define OPTION_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Advertise/AdvertiseMgr.hpp"

enum enmSoundMode {
    SOUND_MODE___MONAURAL = 0,
    SOUND_MODE___STEREO = 1,
    SOUND_MODE___DOLBY_PROLOGIC2 = 2,
    SOUND_MODE___DOLBY_DIGITAL = 3,
    SOUND___MAX = 4,
};

enum enmLanguage {
    LANGUAGE___JAPANESE = 0,
    LANGUAGE___ENGLISH = 1,
    LANGUAGE___GERMAN = 2,
    LANGUAGE___FRENCH = 3,
    LANGUAGE___SPANISH = 4,
    LANGUAGE___ITALIAN = 5,
    LANGUAGE___DUTCH = 6,
    LANGUAGE___PORTUGUESE = 7,
    LANGUAGE___SIMP_CHINESE = 8,
    LANGUAGE___TRAD_CHINESE = 9,
    LANGUAGE___KOREAN = 10,
    LANGUAGE___MAX = 11,
};

// total size: 0x94
class clsOption_Task : public clsTask {
public:
    clsOption_Task(clsAdvertiseMgr_Task* pcAdv) : clsTask(0, 0) {}
    virtual ~clsOption_Task() {}
    virtual void execute();
    virtual void draw();

    void checkFont();
    void checkEnd();
    void checkAutoSave();
    void checkDeside();
    void setVibMovie(u32 u32Idx);
    void setVoiceMovie(u32 u32Idx);
    void setMessageMovie(u32 u32Idx);
    void setAudioMovie(u32 u32Idx);
    void setFastIn();

    clsAdvertiseMgr_Task* m_pcAdvertiseMgr_Task; // offset 0x54, size 0x4
    enmSoundMode m_eSoundMode;                   // offset 0x58, size 0x4
    enmLanguage m_eVoiceeLanguage;               // offset 0x5C, size 0x4
    enmLanguage m_eMessageLanguage;              // offset 0x60, size 0x4
    u8 m_bDisableAllRumble;                      // offset 0x64, size 0x1
    f32 m_f32ButtonDrawWait;                     // offset 0x68, size 0x4
    u8 m_bFastSet;                               // offset 0x6C, size 0x1
    void* m_pvKeyboardTextureLoFrame;            // offset 0x70, size 0x4
    u8 m_u8ReadMode;                             // offset 0x74, size 0x1
    u32 m_u32AudioSel;                           // offset 0x78, size 0x4
    u32 m_u32MessageSel;                         // offset 0x7C, size 0x4
    u32 m_u32VoiceSel;                           // offset 0x80, size 0x4
    u32 m_u32VibSel;                             // offset 0x84, size 0x4
    u32 m_u32CtrlSel;                            // offset 0x88, size 0x4
    u32 m_u32Deside;                             // offset 0x8C, size 0x4
    u32 m_u32AutoSave;                           // offset 0x90, size 0x4
};

#endif // OPTION_HPP
