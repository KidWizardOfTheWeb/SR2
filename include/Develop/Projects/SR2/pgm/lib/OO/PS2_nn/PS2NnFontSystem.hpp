#ifndef PS2NNFONTSYSTEM_HPP
#define PS2NNFONTSYSTEM_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Texture/nntexture.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"

// total size: 0x1C
class clsPfTextureBase {
public:
    clsPfTextureBase(void* pvTex, bool bSetUp) { SetTexture_Base(pvTex, bSetUp); }
    virtual ~clsPfTextureBase() {}
    virtual void* GetSize_Base(s32 s32Param1) const
    {
        return static_cast<u8*>(m_cSizeList._data) + s32Param1 * 8;
    }

    void SetTexture_Base(void* pvTex, bool bSetUp);

    void* m_pvTex;          // offset 0x0, size 0x4
    void* m_pvTexLocalBuff; // offset 0x4, size 0x4
    _NNS_TEXLIST* m_psTex;  // offset 0x8, size 0x4
    vector m_cSizeList;     // offset 0xC, size 0xC
};

#endif // PS2NNFONTSYSTEM_HPP
