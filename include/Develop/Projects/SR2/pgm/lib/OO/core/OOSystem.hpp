#ifndef OOSYSTEM_HPP
#define OOSYSTEM_HPP

#include "Develop/Projects/SR2/pgm/src/Advertise/Option/Option.hpp"
#include "types.h"

struct stcScissorRect;

// OO system base
class clsOOSystem {
public:
    // total size: 0x8
    struct stcDateTime {
        u16 u16Year; // offset 0x0, size 0x2
        u8 u8Month;  // offset 0x2, size 0x1
        u8 u8Day;    // offset 0x3, size 0x1
        u8 u8Hour;   // offset 0x4, size 0x1
        u8 u8Min;    // offset 0x5, size 0x1
        u8 u8Sec;    // offset 0x6, size 0x1
    };

    enum enmSoundMode {
        SOUND_MODE___MONAURAL = 0,
        SOUND_MODE___STEREO = 1,
        SOUND_MODE___DOLBY_PROLOGIC2 = 2,
        SOUND_MODE___DOLBY_DIGITAL = 3,
        SOUND___MAX = 4,
    };

    typedef u32 enmState;

    // total size: 0x10
    struct stcViewRect {
        s32 s32Left;   // offset 0x0, size 0x4
        s32 s32Top;    // offset 0x4, size 0x4
        s32 s32Right;  // offset 0x8, size 0x4
        s32 s32Bottom; // offset 0xC, size 0x4
    };

    virtual ~clsOOSystem() {}
    virtual void setSoundMode(enmSoundMode eSoundMode) { m_eSoundMode = eSoundMode; }
    virtual u8 isMono() const { return m_eSoundMode == SOUND_MODE___MONAURAL; }
    virtual u8 isMonaural() const { return m_eSoundMode == SOUND_MODE___MONAURAL; }
    virtual u8 isStereo() const { return m_eSoundMode == SOUND_MODE___STEREO; }
    virtual u8 isPrologic2() const { return m_eSoundMode == SOUND_MODE___DOLBY_PROLOGIC2; }
    virtual u8 isDolbyDigital() const { return m_eSoundMode == SOUND_MODE___DOLBY_DIGITAL; }

    f32 getFrameRate() const { return m_f32FrameRate; }
    f32 getFrameRateAdd() const { return m_f32FrameRateAdd; }
    u32 getGameCnt() const { return m_u32GameCnt; }
    s8 getViewportNum() const { return m_s8ViewportNum; }
    s8 getBackUpViewportNum() const { return m_s8BackUpViewportNum; }
    u8 getDisablePauseCancel() const { return m_bDisablePauseCancel; }
    enmLanguage getMessageLanguage() const { return m_eMessageLanguage; }
    void setPauseFlag(bool bPause) { m_bNextPause = bPause; }
    void setOnlyState(enmState eState) { m_eState = eState; }
    void setState(enmState eState) { m_eState |= eState; }
    void clearState(enmState eState) { m_eState &= ~eState; }
    u32 getState(u32 u32State) const { return m_eState & u32State; }
    const stcScissorRect* getScissorRect(u32 u32Param1) const
    {
        return m_apsScissorRect[u32Param1];
    }
    void setViewRect(u32 u32I, const stcViewRect* psViewRect);
    u8 getTonTon_V() const { return 0; }
    u8 getTonTon_G() const { return 0; }

    static c8* m_tac8LanguageName_Debug[11];
    static c8 m_tac8RomRegionName_Debug[3];

    enmSoundMode m_eSoundMode;                // offset 0x4, size 0x4
    enmLanguage m_eMessageLanguage;           // offset 0x8, size 0x4
    enmLanguage m_eVoiceLanguage;             // offset 0xC, size 0x4
    f32 m_f32FrameRate;                       // offset 0x10, size 0x4
    f32 m_f32FrameRateAdd;                    // offset 0x14, size 0x4
    f32 m_f32FrameRateAdd2;                   // offset 0x18, size 0x4
    f32 m_f32FrameRateAddCount;               // offset 0x1C, size 0x4
    f32 m_f32FrameRateAddCount2;              // offset 0x20, size 0x4
    s32 m_s32FrameRateMaxMicroSec;            // offset 0x24, size 0x4
    u32 m_u32VblankCnt;                       // offset 0x28, size 0x4
    u32 m_u32VblankCntOld;                    // offset 0x2C, size 0x4
    u32 m_u32GameCnt;                         // offset 0x30, size 0x4
    u32 m_eState;                             // offset 0x34, size 0x4
    stcViewRect* m_apsViewRect[5];            // offset 0x38, size 0x14
    stcScissorRect* m_apsScissorRect[5];      // offset 0x4C, size 0x14
    stcScissorRect* m_apsScissorRect_NTSC[5]; // offset 0x60, size 0x14
    u8 m_u8FrameRateDef;                      // offset 0x74, size 0x1
    u8 m_u8VblankNum;                         // offset 0x75, size 0x1
    s8 m_s8ViewportNum;                       // offset 0x76, size 0x1
    s8 m_s8BackUpViewportNum;                 // offset 0x77, size 0x1
    s8 m_s8MaxViewportNum;                    // offset 0x78, size 0x1
    u8 m_bPause;                              // offset 0x79, size 0x1
    u8 m_bUnPause;                            // offset 0x7A, size 0x1
    u8 m_bEnablePauseWorks;                   // offset 0x7B, size 0x1
    u8 m_bDisablePauseCancel;                 // offset 0x7C, size 0x1
    u8 m_bDisablePauseDraw;                   // offset 0x7D, size 0x1
    u8 m_bNextPause;                          // offset 0x7E, size 0x1
};

typedef clsOOSystem::stcViewRect stcViewRect;

#endif // OOSYSTEM_HPP
