#ifndef PS2NNFONTSYSTEM_HPP
#define PS2NNFONTSYSTEM_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOMainHeap.hpp"
#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOFontSystem.hpp"
#include "usr/local/sega/nn/src/Texture/nntexture.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"

// total size: 0x1C
class clsPfTextureBase {
public:
    void* m_pvTex;          // offset 0x0, size 0x4
    void* m_pvTexLocalBuff; // offset 0x4, size 0x4
    _NNS_TEXLIST* m_psTex;  // offset 0x8, size 0x4
    std::vector<nspOOMisc::stcSize2d<s32>,
                std::allocator<nspOOMisc::stcSize2d<s32> > >
        m_cSizeList; // offset 0xC, size 0xC

    clsPfTextureBase(void* pvTex, bool bSetUp)
        : m_pvTex(pvTex), m_pvTexLocalBuff(NULL), m_psTex(NULL)
    {
        SetTexture_Base(pvTex, bSetUp);
    }
    virtual ~clsPfTextureBase()
    {
        if (m_pvTexLocalBuff != NULL) {
            clsOOMainHeap::getInstance()->___FreeHi(m_pvTexLocalBuff);
            m_pvTexLocalBuff = NULL;
        }
    }
    // RECONSTRUCTED: reference return.
    virtual const nspOOMisc::stcSize2d<s32>& GetSize_Base(s32 s32Param1) const
    {
        return m_cSizeList[s32Param1];
    }

    void SetTexture_Base(void* pvTex, bool bSetUp);
};

// total size: 0x2C
class clsPfSplitTexture : public clsOOSplitTexture, private clsPfTextureBase {
public:
    clsPfSplitTexture(void* pvTex, bool bSetUp, void* pvTexUVListFile)
        : clsOOSplitTexture(), clsPfTextureBase(pvTex, bSetUp)
    {
        SetTexUVListFile(pvTexUVListFile);
    }
    virtual ~clsPfSplitTexture() {}
    virtual void SetTexture(void* pvTex, bool bSetUp) { SetTexture_Base(pvTex, bSetUp); }
    virtual void SetDrawTexture(s32 s32Param1) { nnSetPrimitiveTexNum(m_psTex, s32Param1); }
    virtual const nspOOMisc::stcSize2d<s32>& GetSize(s32 s32Param1) const
    {
        return GetSize_Base(s32Param1);
    }
};

#endif // PS2NNFONTSYSTEM_HPP
