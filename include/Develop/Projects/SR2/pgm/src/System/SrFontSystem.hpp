#ifndef SRFONTSYSTEM_HPP
#define SRFONTSYSTEM_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Texture/nntexture.h"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnFontSystem.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOFontSystem.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"

// Platform font system base (forward-declared, inherits from clsOOFontSystem)
class clsPfFontSystem : public clsOOFontSystem {
public:
    clsPfFontSystem() : clsOOFontSystem(0, 0, 0) {}
    virtual ~clsPfFontSystem() {}
};

namespace nspSrFontSystem {
enum enmFontNo {
    FONT_NO_NORMAL = 0,
    FONT_NO_NETWORK = 1,
    FONT_NO_MOVIE = 2,
    FONT_NO_STORY = 3,
    FONT_NO_MENU_J = 4,
    FONT_NO_MENU_E = 5,
    FONT_NO_MENU_G = 6,
    FONT_NO_MENU_F = 7,
    FONT_NO_MENU_S = 8,
    FONT_NO_MENU_I = 9,
    FONT_NO_EVENT = 10,
    FONT_NO_MISSION = 11,
    FONT_NO_USER_NAME = 12,
    FONT_NO_PECULIAR = 13,
    FONT_NO_REG_J = 14,
    FONT_NO_REG_E = 15,
    FONT_NO_REG_G = 16,
    FONT_NO_REG_F = 17,
    FONT_NO_REG_S = 18,
    FONT_NO_REG_I = 19,
    FONT_NO_TEMP1 = 20,
    FONT_NO_MAX_NUM = 21,
};
}

enum enmLoadMode {
    LOAD_MODE_NONE = 0,
    LOAD_MODE_LOAD = 1,
    LOAD_MODE_END = 2,
};

class clsPfTexture;
class clsPfSplitTexture;

// total size: 0x28
struct stcFontObjData {
    clsPfTexture* pcFontTex;   // offset 0x0, size 0x4
    clsOOFontObj* pcFontObj;   // offset 0x4, size 0x4
    clsOOFontStrTbl* pcStrTbl; // offset 0x8, size 0x4
    void* pvDelFontDataBuff;   // offset 0xC, size 0x4
    void* pvFontDataBuff;      // offset 0x10, size 0x4
    void* pvFontTexFile;       // offset 0x14, size 0x4
    void* pvStrTblFile;        // offset 0x18, size 0x4
    void* pvFontInfoFile;      // offset 0x1C, size 0x4
    s32 s32FontFileNo;         // offset 0x20, size 0x4
    enmLoadMode enLoadEnd;     // offset 0x24, size 0x4
};

// total size: 0x40C
class clsSrFontSystem : public clsPfFontSystem, public clsSingleton<clsSrFontSystem> {
public:
    clsSrFontSystem();
    virtual ~clsSrFontSystem();

    u8 chkAllLoadEnd();
    void reloadFontData(nspSrFontSystem::enmFontNo);
    void loadFontData(nspSrFontSystem::enmFontNo, s32 s32Param2, void* pvParam3, bool bParam4);
    void delUnResidenceFontData();
    void delBtnTexBuff();
    void delFontData(nspSrFontSystem::enmFontNo);
    void setFontDataFromFile(
        nspSrFontSystem::enmFontNo, void* pvParam2, void* pvParam3, void* pvParam4, s32 s32Param5);
    void setBtnDataFromFile(void* pvDataBuff, bool bSetUp, void* pvTex) {}
    void setFontLoadFunc(
        void (*fFontLoadFunc)(
            u32, s32, clsSrFontSystem*, nspSrFontSystem::enmFontNo, s32, void*, bool, void*),
        void (*fCancelLoadFont)(nspSrFontSystem::enmFontNo))
    {
        m_fFontLoadFunc = (void (*)(
            u32, s32, clsSrFontSystem*, nspSrFontSystem::enmFontNo, s32, void*, u8, void*))
            fFontLoadFunc;
        m_fCancelLoadFont = fCancelLoadFont;
    }

    stcFontObjData m_asFontObjData[21]; // offset 0x50, size 0x348
    clsPfSplitTexture* m_pcBtnData;     // offset 0x398, size 0x4
    void* m_pvBtnDataBuff;              // offset 0x39C, size 0x4
    void (*m_fFontLoadFunc)(u32,
                            s32,
                            clsSrFontSystem*,
                            nspSrFontSystem::enmFontNo,
                            s32,
                            void*,
                            u8,
                            void*);                        // offset 0x3A0, size 0x4
    void (*m_fCancelLoadFont)(nspSrFontSystem::enmFontNo); // offset 0x3A4, size 0x4
    s32 (*m_fStrCreate)(s32, u16*, s32*);                  // offset 0x3A8, size 0x4
    f32 m_af32Data[8];                                     // offset 0x3AC, size 0x20
    s32 m_as32Data[8];                                     // offset 0x3CC, size 0x20
    void* m_apovData[8];                                   // offset 0x3EC, size 0x20

    virtual void DrawLocalCode(
        s32 s32Param1,
        s32 s32Param2,
        const nspOOMisc::stcPoint3d<f32>* pParam3,
        u32 u32Param4,
        const nspOOMisc::stcPoint3d<f32>* pParam5,
        nspOOMisc::stcPoint3d<f32>* pParam6,
        nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* pParam7,
        f32* pParam8);
    virtual void DrawLocalCodeMemoCa(
        s32 s32Param1,
        const nspOOMisc::stcPoint3d<f32>* pParam2,
        u32 u32Param3,
        const nspOOMisc::stcPoint3d<f32>* pParam4,
        nspOOMisc::stcPoint3d<f32>* pParam5,
        nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* pParam6,
        f32* pParam7);
    virtual void DrawLocalCodeMission(
        s32 s32Param1,
        const nspOOMisc::stcPoint3d<f32>* pParam2,
        u32 u32Param3,
        const nspOOMisc::stcPoint3d<f32>* pParam4,
        nspOOMisc::stcPoint3d<f32>* pParam5,
        nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* pParam6,
        f32* pParam7);
    virtual void DrawLocalCodeUnion(
        s32 s32Param1,
        const nspOOMisc::stcPoint3d<f32>* pParam2,
        u32 u32Param3,
        const nspOOMisc::stcPoint3d<f32>* pParam4,
        nspOOMisc::stcPoint3d<f32>* pParam5,
        nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* pParam6,
        f32* pParam7);
};

#endif // SRFONTSYSTEM_HPP
