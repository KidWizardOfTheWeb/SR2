#ifndef PS2NNCREATETEXTURE_HPP
#define PS2NNCREATETEXTURE_HPP

#include "usr/local/sega/nn/src/Texture/nntexture.h"
#include "types.h"

// total size: 0x18
class clsPfCreateTexture {
public:
    enum enmMemType {
        REQ_LO = 0,
        REQ_HI = 1,
    };

    virtual ~clsPfCreateTexture() {}

    void create(s32 s32SizeWI,
                s32 s32SizeHI,
                u32 eFormatI,
                void* pvLocalAddressI,
                enmMemType eMemTypeI,
                s32 s32TexNumI,
                s32 s32Param7);

    s8 m_s8DivNum;               // offset 0x4, size 0x1
    s8 m_s8PpbShift;             // offset 0x5, size 0x1
    void* m_pvNnTexListBuf_Heap; // offset 0x8, size 0x4
    _NNS_TEXLIST* m_psNnTexList; // offset 0xC, size 0x4
    s32 m_s32BuffWidth;          // offset 0x10, size 0x4
    s32 m_s32BuffHeight;         // offset 0x14, size 0x4
};

#endif // PS2NNCREATETEXTURE_HPP
