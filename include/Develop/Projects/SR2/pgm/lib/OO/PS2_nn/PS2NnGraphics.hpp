#ifndef PS2NNGRAPHICS_HPP
#define PS2NNGRAPHICS_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/BgColor.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sce/ee/lib/eestruct.h"
#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Texture/nntexture.h"
#include "usr/local/sega/px/src/px.h"
#include "usr/local/sega/px/src/pxcontext.h"
#include "usr/local/sega/px/src/pxpushbuffer.h"
#include "types.h"

namespace nspOOMisc {
struct stcPoint2D_s16;
}

// total size: 0x48
struct stcAttackModel {
    clsModelType_OB_TX_MO_MA sModel1; // offset 0x0, size 0x20
    clsModelType_OB_TX_MO_MA sModel2; // offset 0x20, size 0x20
    NNS_MOTION* psMotion1;            // offset 0x40, size 0x4
    NNS_MOTION* psMotion2;            // offset 0x44, size 0x4
};

class clsOOGraphics_Consumer {
public:
    enum enmZModeCompType {
        Z___NEVER = 0,
        Z___ALWAYS = 1,
        Z___G_EQUAL = 2,
        Z___GREATER = 3,
        Z___L_EQUAL = 4,
        Z___LESS = 5,
    };

    enum enmCullModeType {
        CULL___NONE = 0,
        CULL___CW = 1,
        CULL___CCW = 2,
    };

    enum enmScreenMode {
        SCREEN_MODE___NTSC = 0,
        SCREEN_MODE___NTSC_PROGRESSIVE = 1,
        SCREEN_MODE___PAL = 2,
        SCREEN_MODE___MPAL = 3,
        SCREEN_MODE___MPAL_PROGRESSIVE = 4,
        SCREEN_MODE___PAL60 = 5,
        SCREEN_MODE___PAL60_PROGRESSIVE = 6,
        SCREEN_MODE___MIN_WIDE = 7,
        SCREEN_MODE___NTSC_WIDE = 7,
        SCREEN_MODE___NTSC_PROGRESSIVE_WIDE = 8,
        SCREEN_MODE___PAL_WIDE = 9,
        SCREEN_MODE___MPAL_WIDE = 10,
        SCREEN_MODE___MPAL_PROGRESSIVE_WIDE = 11,
        SCREEN_MODE___PAL60_WIDE = 12,
        SCREEN_MODE___PAL60_PROGRESSIVE_WIDE = 13,
        SCREEN_MODE___MAX_WIDE = 14,
    };

    virtual ~clsOOGraphics_Consumer() {}

    virtual void clip2Screen(nspOOMisc::stcPoint2D_s16& rDst,
                             const NNS_VECTOR& rSrc,
                             s32 param) const;
    virtual void updatePalParam();
    virtual void setScreenMode(enmScreenMode mode);

    f32 getPalOffsetY(s32 param) const { return 0.0f; }
    f32 getPalOffsetY() const { return 0.0f; }
    f32 getPalOffsetRatioY(f32 param) const { return param; }
    f32 getPalOffsetRatioY() const { return 1.0f; }
    s32 getFbHeight() const { return m_s32FbHeight; }
    s32 getFbWidth() const { return m_s32FbWidht; }
    bool isPal() const { return m_bPal != 0; }

    static c8* m_toac8ScreenModeName_Debug[];

    enmZModeCompType m_eZModeCompType; // offset 0x4, size 0x4
    enmCullModeType m_eCullModeType;   // offset 0x8, size 0x4
    enmScreenMode m_eScreenMode;       // offset 0xC, size 0x4
    u32 m_u32WbID;                     // offset 0x10, size 0x4
    s32 m_s32FbWidht;                  // offset 0x14, size 0x4
    s32 m_s32FbHeight;                 // offset 0x18, size 0x4
    f32 m_f32FbWidht_Half;             // offset 0x1C, size 0x4
    f32 m_f32FbHeight_Half;            // offset 0x20, size 0x4
    u8 m_bProgressive;                 // offset 0x24, size 0x1
    u8 m_bPal;                         // offset 0x25, size 0x1
    u8 m_bWide;                        // offset 0x26, size 0x1
};

// total size: 0x50
class clsPfGraphics : public clsSingleton<clsPfGraphics>, public clsOOGraphics_Consumer {
public:
    clsPfGraphics();
    virtual ~clsPfGraphics() {}

    virtual void setZMode_DefaultCompType(enmZModeCompType eZModeCompTypeI)
    {
        m_eZModeCompType = eZModeCompTypeI;
    }
    virtual void setZMode_Def() {}
    virtual void setZMode_Comp(enmZModeCompType eZModeCompTypeI) const {}
    virtual void setZMode_Write(bool bWriteI) {}
    virtual void setCullMode_DefaultType(enmCullModeType eCullModeTypeI)
    {
        m_eCullModeType = eCullModeTypeI;
    }
    virtual void setCullMode_Def() const {}
    virtual void setCullMode(enmCullModeType eCullModeTypeI) const {}
    virtual void setCullModeCounter() const {}
    virtual f32 getPalOffsetY() const { return m_s32PalOffsetY; }
    virtual f32 getPalOffsetRatioY() const { return m_f32PalOffsetRatioY; }
    virtual f32 getPalOffsetY(s32 s32Param1) const { return m_s32PalOffsetY; }
    virtual f32 getPalOffsetRatioY(f32 f32Param1) const { return f32Param1; }
    virtual void clip2Screen(nspOOMisc::stcPoint2D_s16& rDst,
                             const NNS_VECTOR& rSrc,
                             s32 s32Param1) const
    {
    }
    virtual void updatePalParam();

    void initFrameBuffer() {}
    void resetTextureBuffer(s32 s32SizeI, s32 s32ResidenceSizeI);
    void setVideoMode(enmScreenMode eScreenModeI);
    void updateFrameBuffer();
    void exit();
    u32 getDrawFrameBufferAddr() { return 0; }
    static s32 tVifEndCB_Debug(s32 s32Param1);

    static sceGsDBuffDc m_tsGsDBuffDc;

    void* m_pvMainTextureBuffer;    // offset 0x2C, size 0x4
    void* m_pvSpecialTextureBuffer; // offset 0x30, size 0x4
    tagPXS_PUSHBUFFER* m_psPxPb_nn; // offset 0x34, size 0x4
    PXS_CONTEXTBUFFER* m_psPxCb_nn; // offset 0x38, size 0x4
    stcBgColor m_sBgColor;          // offset 0x3C, size 0x4
    s32 m_s32RestTextureBufferSize; // offset 0x40, size 0x4
    s32 m_s32PalOffsetY;            // offset 0x44, size 0x4
    f32 m_f32PalOffsetRatioY;       // offset 0x48, size 0x4
    u8 m_bOdev;                     // offset 0x4C, size 0x1
};

#endif // PS2NNGRAPHICS_HPP
