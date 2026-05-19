#ifndef SPRITETEST_HPP
#define SPRITETEST_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/Flash/OOFlash.hpp"
#include "Develop/Projects/SR2/pgm/src/Advertise/AdvertiseMgr.hpp"
#include "Develop/Projects/SR2/pgm/src/Camera/MotionCamCtrl.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "types.h"

// total size: 0x18
struct stcDebugInfo {
    u32 u32Flg;     // offset 0x0, size 0x4
    s32 s32FlashNo; // offset 0x4, size 0x4
    u32 u32Frame;   // offset 0x8, size 0x4
    s32 s32LayerNo; // offset 0xC, size 0x4
    s32 s32OffsetX; // offset 0x10, size 0x4
    s32 s32OffsetY; // offset 0x14, size 0x4
};

// total size: 0x388
class clsSpriteTest : public clsTask {
public:
    // Note: enmRet collides with unrelated DWARF enum bodies; this body matches clsSpriteTest.
    enum enmRet {
        RET___UN_USE = 0,
        RET___INIT = 1,
        RET___EXEC = 2,
        RET___ERROR_DEF = 3,
        RET___ERROR_DIFFERENT_DISC = 4,
        RET___ERROR_OPENED_COVER = 5,
        RET___FINISH = 6,
        RET___CANCEL_EXEC = 7,
        RET___CANCEL_FINISH = 8,
    };

    void* m_pvData;                 // offset 0x54, size 0x4
    void* m_pvShareData;            // offset 0x58, size 0x4
    void* m_pvTex;                  // offset 0x5C, size 0x4
    void* m_pvShareTex;             // offset 0x60, size 0x4
    stcFlash m_sFlash;              // offset 0x64, size 0x58
    stcFlash m_sShareFlash;         // offset 0xBC, size 0x58
    stcPolyVert* m_psVert;          // offset 0x114, size 0x4
    u32 m_u32VertNum;               // offset 0x118, size 0x4
    stcPolyVert* m_psVert1;         // offset 0x11C, size 0x4
    u32 m_u32VertNum1;              // offset 0x120, size 0x4
    clsOOFMSprite m_cSprite;        // offset 0x128, size 0xF0
    clsOOFlashMovie m_cFlash;       // offset 0x218, size 0x8C
    clsOOFlashMovie m_cShareFlash;  // offset 0x2A4, size 0x8C
    enmRet m_eStat;                 // offset 0x330, size 0x4
    enmRet m_eTexStat;              // offset 0x334, size 0x4
    clsPfTexture* m_pcShareTexList; // offset 0x338, size 0x4
    clsPfTexture* m_pcTexList;      // offset 0x33C, size 0x4
    clsOOFlashPlayer m_cFP;         // offset 0x340, size 0x20
    clsOOFlashPlayer m_cTuto;       // offset 0x360, size 0x20
    s32 m_s32OffsetX;               // offset 0x380, size 0x4
    s32 m_s32OffsetY;               // offset 0x384, size 0x4
};

#endif // SPRITETEST_HPP
