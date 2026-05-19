#ifndef PLAYERKEY_HPP
#define PLAYERKEY_HPP

#include "types.h"

// total size: 0x8
class _KeyBuf {
public:
    u32 u32KeyState; // offset 0x0, size 0x4
    s8 s8LeverX;     // offset 0x4, size 0x1
    s8 s8LeverY;     // offset 0x5, size 0x1
    u8 u8ExtType;    // offset 0x6, size 0x1
    u8 u8Padding;    // offset 0x7, size 0x1
};

// total size: 0x8
struct stcExtensionLeverRate {
    f32 f32LeverRateX; // offset 0x0, size 0x4
    f32 f32LeverRateY; // offset 0x4, size 0x4
};

// total size: 0x8
struct stcExtensionGDive {
    stcExtensionLeverRate sLever; // offset 0x0, size 0x8
};

// total size: 0x8
struct stcExtensionFlyAction {
    stcExtensionLeverRate sLever; // offset 0x0, size 0x8
};

// total size: 0x10
struct stcExtensionData {
    stcExtensionGDive sGDive;   // offset 0x0, size 0x8
    stcExtensionFlyAction sFly; // offset 0x8, size 0x8
};

// total size: 0x34
class clsPlayerKey {
public:
    enum enmStiffType {
        STIFF_TYPE__ALL = 0,
        STIFF_TYPE__LEVER = 1,
    };

    _KeyBuf m_sKeyData;            // offset 0x0, size 0x8
    u32 m_u32OldState;             // offset 0x8, size 0x4
    u32 m_u32KeyMask;              // offset 0xC, size 0x4
    f32 m_f32StiffFrame;           // offset 0x10, size 0x4
    s8 m_s8OldLeverX;              // offset 0x14, size 0x1
    s8 m_s8OldLeverY;              // offset 0x15, size 0x1
    enmStiffType m_eStiffType;     // offset 0x18, size 0x4
    u8 m_bValidFlag;               // offset 0x1C, size 0x1
    stcExtensionData m_sExtension; // offset 0x20, size 0x10

    clsPlayerKey();
    virtual ~clsPlayerKey();
    virtual void reset();

    void SetExtType(u8 param);

    void setKeyMask(u32 param) { m_u32KeyMask = param; }
    s8 GetLeverX() const { return m_sKeyData.s8LeverX; }
    s8 GetLeverY() const { return m_sKeyData.s8LeverY; }
    s8 GetOldLeverX() const { return m_s8OldLeverX; }
    _KeyBuf GetState() const { return m_sKeyData; }
    const stcExtensionData* getExtensionDataPtr() const { return &m_sExtension; }
    void setValidFlag(bool param) { m_bValidFlag = (u8)param; }
    void setStiffFrame(f32 param1, enmStiffType param2) {}

    static stcExtensionData t_osExtensionTable[3];
};

#endif // PLAYERKEY_HPP
