#ifndef IONMIST_HPP
#define IONMIST_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OODraw2d.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Texture/nntexture.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0xE4
class clsIonMist_Task : public clsTask {
public:
    // total size: 0x10
    struct stcTexArea {
        u32 u32Flg;   // offset 0x0, size 0x4
        f32 f32TuSpd; // offset 0x4, size 0x4
        f32 f32TvSpd; // offset 0x8, size 0x4
        f32 f32Size;  // offset 0xC, size 0x4
    };

    // total size: 0x30
    struct stcNearStatus {
        NNS_VECTOR sStartPos; // offset 0x0, size 0xC
        f32 f32StartAlpha;    // offset 0xC, size 0x4
        NNS_VECTOR sEndPos;   // offset 0x10, size 0xC
        f32 f32EndAlpha;      // offset 0x1C, size 0x4
        stcTexArea sTexArea;  // offset 0x20, size 0x10
    };

    // total size: 0x30
    struct stcFarStatus {
        NNS_VECTOR sStartPos; // offset 0x0, size 0xC
        f32 f32ClipVec;       // offset 0xC, size 0x4
        NNS_VECTOR sEndPos;   // offset 0x10, size 0xC
        f32 f32Alpha;         // offset 0x1C, size 0x4
        stcTexArea sTexArea;  // offset 0x20, size 0x10
    };

    // total size: 0x6C
    struct stcParam {
        u32 u32Flg;          // offset 0x0
        u8 u8StageNo;        // offset 0x4
        u8 u8PortalNum;      // offset 0x5
        s8 ac8Portal[4];     // offset 0x6, size 0x4
        stcNearStatus sNear; // offset 0xC, size 0x30
        stcFarStatus sFar;   // offset 0x3C, size 0x30
    };

    // total size: 0x8
    struct stcDebugParam {
        u32 u32Page; // offset 0x0, size 0x4
        u8 bUsed;    // offset 0x4, size 0x1
    };

    virtual ~clsIonMist_Task() {}
    virtual void execute();
    virtual void draw();

    clsIonMist_Task(u8 u8StageNo);

    void setData(u8 u8StageNo);
    s32 DebugInfo(s32 s32xI, s32 s32yI, s32 s32ActiveNoI, s32 s32Param4);
    void anmTexArea(stcTexUV* psTex, stcTexArea* psTexArea);
    u8 calcNearAlpha(u32 u32View);
    u8 calcFarAlpha(u32 u32View, f32* pf32OfsZ);

    static _NNS_TEXLIST* m_psTex;        // address: 0x00B15E38
    static u8 m_tu8DrawFlg;              // address: 0x00B15E40
    static u8 m_tbSpFlg;                 // address: 0x00B15E48
    static stcParam m_tsDebugFullParam;  // address: 0x00B15E50
    static stcDebugParam m_tsDebugParam; // address: 0x00B15EC0

    u8 m_u8StageNo;        // offset 0x54, size 0x1
    stcParam m_sFullParam; // offset 0x58, size 0x6C
    stcTexUV m_sNTex;      // offset 0xC4, size 0x10
    stcTexUV m_sFTex;      // offset 0xD4, size 0x10
};

#endif // IONMIST_HPP
