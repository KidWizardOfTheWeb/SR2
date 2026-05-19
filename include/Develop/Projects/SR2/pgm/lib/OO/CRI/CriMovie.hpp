#ifndef CRIMOVIE_HPP
#define CRIMOVIE_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/CRI/OOCri.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnCreateTexture.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OODraw2d.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/CharaData.hpp"
#include "types.h"

// total size: 0xF8
class clsCriMovie {
public:
    enum enmLoopFlag {
        LOOP_OFF = 0,
        LOOP_ON = 1,
    };

    enum enmSubTitle {
        SUB_TITLE_OFF = 0,
        SUB_TITLE_ON = 1,
    };

    clsCriMovie(const stcData& orsDataI,
                s32 s32DrawXI,
                s32 s32DrawYI,
                enmLoopFlag eLoopI,
                enmSubTitle eSubTitleI,
                enmAllocate eAllocateI,
                s32 s32DrawWI,
                s32 s32DrawHI);
    virtual ~clsCriMovie() {}

    virtual void restart();
    virtual void render();
    virtual void stop();
    virtual void pause(u32 bSetI);
    MwsfdStat getStatus() const;
    f32 getTime_Sec() const;

    clsPfCreateTexture m_cPfCreateTexture; // offset 0x4, size 0x18
    const stcData& m_orsData;              // offset 0x1C, size 0x4
    MwsfdFrmObj m_sFrameObj;               // offset 0x20, size 0xA0
    enmAllocate m_eAllocate;               // offset 0xC0, size 0x4
    stcTexUV m_TextureUv;                  // offset 0xC4, size 0x10
    u32 m_u32TexMainBufSize;               // offset 0xD4, size 0x4
    f32 m_f32DrawX;                        // offset 0xD8, size 0x4
    f32 m_f32DrawY;                        // offset 0xDC, size 0x4
    f32 m_f32DrawW;                        // offset 0xE0, size 0x4
    f32 m_f32DrawH;                        // offset 0xE4, size 0x4
    enmLoopFlag m_eLoop;                   // offset 0xE8, size 0x4
    enmSubTitle m_eSubTitle;               // offset 0xEC, size 0x4
    s32 m_s32SubTitleDataPos;              // offset 0xF0, size 0x4
};

#endif // CRIMOVIE_HPP
