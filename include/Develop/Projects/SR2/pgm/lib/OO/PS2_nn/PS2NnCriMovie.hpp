#ifndef PS2NNCRIMOVIE_HPP
#define PS2NNCRIMOVIE_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/CRI/CriMovie.hpp"
#include "types.h"

// total size: 0x110
class clsPfMovie : public clsCriMovie {
public:
    clsPfMovie(const stcData& orsDataI,
               s32 s32DrawXI,
               s32 s32DrawYI,
               clsCriMovie::enmLoopFlag eLoopI,
               clsCriMovie::enmSubTitle eSubTitleI,
               enmAllocate eAllocateI,
               s32 s32DrawWI,
               s32 s32DrawHI);
    virtual ~clsPfMovie();

    virtual void updateTexture(MwsfdFrmObj* psPlayFrameI);
    virtual void beforeRender();
    void createTexture(void* pvLocalAddressI);

    void* m_apvTexMainBuf_Heap[2];   // offset 0xF8, size 0x8
    void* m_apvDmaPacketBuf_Heap[2]; // offset 0x100, size 0x8
    u32 m_u32ToggleId;               // offset 0x108, size 0x4
};

#endif // PS2NNCRIMOVIE_HPP
