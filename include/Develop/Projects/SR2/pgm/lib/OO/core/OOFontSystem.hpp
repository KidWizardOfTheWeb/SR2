#ifndef OOFONTSYSTEM_HPP
#define OOFONTSYSTEM_HPP
#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOColor.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Flash/OOFlash.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OODraw2d.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOHeapFragment.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Keyboard2D.hpp"

// nspOOMisc namespace - template 2D math types used in function signatures
namespace nspOOMisc {
template <class T>
struct stcPoint3d {
    T x;
    T y;
    T z;
};
template <class T>
struct stcPoint2d {
    T x;
    T y;
};
template <class T>
struct stcSize2d {
    T w;
    T h;
};
template <class T>
struct stcUvRect {
    T u0;
    T v0;
    T u1;
    T v1;
};
template <class P, class S>
struct stcRect {
    P sPos;
    S sSize;
};
struct stcRgbaF32 {
    f32 f32r;
    f32 f32g;
    f32 f32b;
    f32 f32a;
};
} // namespace nspOOMisc

// nspFontSystem namespace
namespace nspFontSystem {
// total size: 0x4
struct stcCharaData {
    u8 u8CtrlCodeType; // offset 0x0, size 0x1
    u8 u8Reserve;      // offset 0x1, size 0x1
    u16 u16Code;       // offset 0x2, size 0x2
};
} // namespace nspFontSystem

// total size: 0x8
struct stcUv {
    s32 u; // offset 0x0, size 0x4
    s32 v; // offset 0x4, size 0x4
};

// total size: 0x10
struct stcUvRect {
    stcUv sUpperLeft;   // offset 0x0, size 0x8
    stcUv sBottomRight; // offset 0x8, size 0x8
};

// OO Font lib internal map container, size 0x10
class map {
private:
    u32 _capacity; // 0x0
    u32 _size;     // 0x4
    void* _lo;     // 0x8
    void* _hi;     // 0xC
};

// total size: 0x38
struct stcFontHeader {
    s8 ac8Id[8];           // offset 0x0, size 0x8
    u8 u8ByteOder;         // offset 0x8, size 0x1
    u8 au8Reserve[3];      // offset 0x9, size 0x3
    u16 u16Version;        // offset 0xC, size 0x2
    u16 u16Size;           // offset 0xE, size 0x2
    u32 u32GlyphNum;       // offset 0x10, size 0x4
    u32 u32BmpMaxGlyphNum; // offset 0x14, size 0x4
    u16 u16BmpNum;         // offset 0x18, size 0x2
    u16 u16BmpSizeX;       // offset 0x1A, size 0x2
    u16 u16BmpSizeY;       // offset 0x1C, size 0x2
    u16 u16EndBmpSizeX;    // offset 0x1E, size 0x2
    u16 u16EndBmpSizeY;    // offset 0x20, size 0x2
    u16 u16BmpGlyphNumX;   // offset 0x22, size 0x2
    u16 u16BmpGlyphNumY;   // offset 0x24, size 0x2
    u16 u16GlyphSizeX;     // offset 0x26, size 0x2
    u16 u16GlyphSizeY;     // offset 0x28, size 0x2
    u16 u16GlyphSpaceX;    // offset 0x2A, size 0x2
    u16 u16GlyphSpaceY;    // offset 0x2C, size 0x2
    u16 u16FontPoint;      // offset 0x2E, size 0x2
    u8 u8ColorDepth;       // offset 0x30, size 0x1
    u8 u8Proportional;     // offset 0x31, size 0x1
    u8 u8CharaCodeType;    // offset 0x32, size 0x1
    u8 au8Reseved2[5];     // offset 0x33, size 0x5
};

// total size: 0x14
struct stcStrGroupTblHeader {
    s8 ac8Id[8];      // offset 0x0, size 0x8
    u8 u8ByteOder;    // offset 0x8, size 0x1
    u8 au8Reserve[3]; // offset 0x9, size 0x3
    u16 u16Version;   // offset 0xC, size 0x2
    u16 u16Size;      // offset 0xE, size 0x2
    u32 u32GroupLen;  // offset 0x10, size 0x4
};

// total size: 0xC
struct stcGlyphABC {
    s32 s32A; // offset 0x0, size 0x4
    u32 u32B; // offset 0x4, size 0x4
    s32 s32C; // offset 0x8, size 0x4
};

// total size: 0x18
class clsOOFontStrTbl {
public:
    void* m_pvStrTbl;   // offset 0x0, size 0x4
    u32 m_u32GroupLen;  // offset 0x4, size 0x4
    vector m_cGroupTbl; // offset 0x8, size 0xC

    clsOOFontStrTbl() : m_pvStrTbl(0), m_u32GroupLen(0) {}
    virtual ~clsOOFontStrTbl() {}

    void SetStrTblData(void* pvStrTblData);
    u8 IsCharaCntData(const nspFontSystem::stcCharaData* psCharaData) const;

    bool ChkEOS(const nspFontSystem::stcCharaData& rCharaData) const { return false; }
};

// total size: 0x4
class clsOOTexture {
public:
    virtual ~clsOOTexture() {}
    virtual void SetTexture(void* pvTex, bool bSetUp) = 0;
    virtual void SetDrawTexture(s32 s32TexNo) = 0;
    virtual const nspOOMisc::stcSize2d<s32>& GetSize(s32 s32TexNo) const = 0;
};

// total size: 0x10
class clsOOSplitTexture : public clsOOTexture {
public:
    // RECONSTRUCTED: fields and UV grouping.
    struct stcTexUVData {
        u8 u8TexNo;
        stcUvRect sTexUV;
    };

    // RECONSTRUCTED: file layout.
    struct stcTexUVFileEntry {
        u8 u8TexNo;
        u8 au8Unknown[3];
        s16 s16U0;
        s16 s16V0;
        s16 s16U1;
        s16 s16V1;
    };
    struct stcTexUVFile {
        u8 au8Unknown[16];
        u32 u32Num;
        stcTexUVFileEntry asEntries[1];
    };

    std::vector<stcTexUVData*, std::allocator<stcTexUVData*> > m_cTexUVList; // offset 0x4, size 0xC

    clsOOSplitTexture() {}
    virtual ~clsOOSplitTexture()
    {
        for (std::vector<stcTexUVData*, std::allocator<stcTexUVData*> >::const_iterator cIt =
                 m_cTexUVList.begin();
             cIt != m_cTexUVList.end();
             cIt++)
        {
            delete *cIt;
        }
    }
    void SetTexUVListFile(const void* pvFile)
    {
        const stcTexUVFile* psFile = static_cast<const stcTexUVFile*>(pvFile);
        m_cTexUVList.reserve(psFile->u32Num);
        const stcTexUVFileEntry* psEntry = psFile->asEntries;
        for (u32 u32Idx = 0; u32Idx < psFile->u32Num; ++u32Idx, ++psEntry) {
            stcTexUVData* psData = new stcTexUVData;
            psData->u8TexNo = psEntry->u8TexNo;
            psData->sTexUV.sUpperLeft.u = psEntry->s16U0;
            psData->sTexUV.sUpperLeft.v = psEntry->s16V0;
            psData->sTexUV.sBottomRight.u = psEntry->s16U1;
            psData->sTexUV.sBottomRight.v = psEntry->s16V1;
            m_cTexUVList.push_back(psData);
        }
    }
};

// total size: 0x34
class clsOOFontObj {
public:
    // total size: 0x10
    struct stcGlyphData {
        stcGlyphABC sSize; // offset 0x0, size 0xC
        u16 u16CharaCode;  // offset 0xC, size 0x2
        u16 u16Code;       // offset 0xE, size 0x2
    };

    clsOOTexture* m_psFontTex;     // offset 0x0, size 0x4
    stcFontHeader* m_psFontHeader; // offset 0x4, size 0x4
    void* m_pvFontStatus;          // offset 0x8, size 0x4
    clsOOFontStrTbl* m_psStrTbl;   // offset 0xC, size 0x4
    map m_cGlyphMap;               // offset 0x10, size 0x10
    map m_cGlyphUTF16Map;          // offset 0x20, size 0x10

    virtual ~clsOOFontObj() {}
    virtual void SetFontData(clsOOTexture* psTex, void* pvFontStatus);
    virtual void SetFontStrTbl(clsOOFontStrTbl* pcStrTbl);
};

// total size: 0x48
class clsOOFontDataSet {
public:
    clsOOFontObj* m_pcObj;   // offset 0x0, size 0x4
    f32 m_f32Size;           // offset 0x4, size 0x4
    s32 m_s32InterlineSpace; // offset 0x8, size 0x4
    s32 m_s32DrawCharaSpace; // offset 0xC, size 0x4
    u32 m_u32DrawParam;      // offset 0x10, size 0x4
    stcRgbaF32 m_sColor;     // offset 0x14, size 0x10
    stcRect m_sDrawRect;     // offset 0x24, size 0x10
    stcPoint3d m_sDrawPos;   // offset 0x34, size 0xC
    u8 m_bRtnFlag;           // offset 0x40, size 0x1
    u8 m_bPropFontDraw;      // offset 0x41, size 0x1

    clsOOFontDataSet(clsOOFontObj* pcObj, f32 f32Size, const nspOOMisc::stcRgbaF32& sColor);
    virtual ~clsOOFontDataSet() {}

    f32 GetFontSize() const { return m_f32Size; }
    f32 GetFontPointSize() const;

    static stcRgbaF32 m_tosFontDefColor;
};

// total size: 0x4C
class clsOOFontSystem {
public:
    vector m_cFontObjList;             // offset 0x0, size 0xC
    u32 m_u32MaxFontObj;               // offset 0xC, size 0x4
    u32 m_u32CurrentFontNo;            // offset 0x10, size 0x4
    stcRect m_sGlobalDrawRect;         // offset 0x14, size 0x10
    clsOOSplitTexture* m_pcBtnTexture; // offset 0x24, size 0x4
    u32 m_u32BtnTexPointSize;          // offset 0x28, size 0x4
    u8 m_bDrawChara;                   // offset 0x2C, size 0x1
    clsOODraw2d* m_pcDraw2d;           // offset 0x30, size 0x4
    clsOOHeapFragment* m_pcAllocator;  // offset 0x34, size 0x4
    stcUvRect m_sUvOffset;             // offset 0x38, size 0x10

    clsOOFontSystem(clsOODraw2d* pcDraw2d, u32 u32MaxFontObj, clsOOHeapFragment* pcAllocator);
    virtual ~clsOOFontSystem() {}

    void SetBtnSplitTexture(clsOOSplitTexture* pcTex, u32 u32PointSize)
    {
        m_pcBtnTexture = pcTex;
        m_u32BtnTexPointSize = u32PointSize;
    }

    virtual void DrawString(
        const nspFontSystem::stcCharaData* pcChara,
        const nspOOMisc::stcPoint3d<f32>* psPos,
        u32 u32Param,
        const nspOOMisc::stcPoint3d<f32>* psScale,
        nspOOMisc::stcPoint3d<f32>* psEndPos,
        nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect,
        f32* pf32);

    virtual u8 DrawChara(
        const nspFontSystem::stcCharaData& rChara,
        const nspOOMisc::stcPoint3d<f32>& rPos,
        const nspOOMisc::stcRect<nspOOMisc::stcPoint2d<s32>, nspOOMisc::stcSize2d<s32> >& rClip,
        nspOOMisc::stcSize2d<f32>* psSize,
        nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect);

    virtual void DrawData(nspOOMisc::stcPoint3d<f32>& rPos,
                          nspOOMisc::stcSize2d<f32>& rSize,
                          nspOOMisc::stcUvRect<f32>& rUv,
                          clsOOTexture& rTex,
                          s32 s32Param,
                          u32 u32Param);

    virtual void AutoReturnString(
        clsOOFontDataSet* pcDataSet,
        const nspOOMisc::stcRect<nspOOMisc::stcPoint2d<s32>, nspOOMisc::stcSize2d<s32> >& rClip,
        f32 f32a,
        f32 f32b,
        nspOOMisc::stcPoint3d<f32>* psPos,
        nspOOMisc::stcPoint3d<f32>* psEndPos,
        f32* pf32);

    virtual u8 ExecCtrlCode(
        const nspFontSystem::stcCharaData& rChara,
        nspOOMisc::stcPoint3d<f32>* psPos,
        const nspOOMisc::stcRect<nspOOMisc::stcPoint2d<s32>, nspOOMisc::stcSize2d<s32> >& rClip,
        f32 f32a,
        f32* pf32b,
        f32* pf32c,
        u32* pu32,
        nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect);

    virtual u8 ChkCharaClipping(
        nspOOMisc::stcPoint3d<f32>* psPos,
        nspOOMisc::stcSize2d<f32>* psSize,
        nspOOMisc::stcUvRect<f32>* psUv,
        const nspOOMisc::stcUvRect<s32>& rUvInt,
        const nspOOMisc::stcRect<nspOOMisc::stcPoint2d<s32>, nspOOMisc::stcSize2d<s32> >& rClip,
        f32 f32a,
        const nspOOMisc::stcSize2d<s32>& rSizeInt);

    virtual u8 DrawBtn(
        u8 u8Param,
        const nspOOMisc::stcPoint3d<f32>& rPos,
        const nspOOMisc::stcRect<nspOOMisc::stcPoint2d<s32>, nspOOMisc::stcSize2d<s32> >& rClip,
        nspOOMisc::stcSize2d<f32>* psSize,
        nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect);

    virtual void DrawLocalCode(
        s32 s32a,
        s32 s32b,
        const nspOOMisc::stcPoint3d<f32>* psPos,
        u32 u32Param,
        const nspOOMisc::stcPoint3d<f32>* psScale,
        nspOOMisc::stcPoint3d<f32>* psEndPos,
        nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect,
        f32* pf32);

    void DrawStrTbl(
        s32 s32TblIdx,
        const nspOOMisc::stcPoint3d<f32>* psPos,
        u32 u32Param,
        const nspOOMisc::stcPoint3d<f32>* psScale,
        nspOOMisc::stcPoint3d<f32>* psEndPos,
        nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect,
        f32* pf32);

    void DrawStrTbl(
        u32 u32LangIdx,
        s32 s32TblIdx,
        f32 f32a,
        f32 f32b,
        f32 f32c,
        u32 u32Param,
        const nspOOMisc::stcPoint3d<f32>* psPos,
        nspOOMisc::stcPoint3d<f32>* psEndPos,
        nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect,
        f32* pf32)
    {
    }

    void DrawStringUTF16(
        const u16* pu16Str,
        const nspOOMisc::stcPoint3d<f32>* psPos,
        u32 u32Param,
        const nspOOMisc::stcPoint3d<f32>* psScale,
        nspOOMisc::stcPoint3d<f32>* psEndPos,
        nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect,
        f32* pf32);

    void GetDrawStrTblSize(
        nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect,
        s32 s32TblIdx,
        const nspOOMisc::stcPoint3d<f32>* psPos,
        u32 u32Param,
        const nspOOMisc::stcPoint3d<f32>* psScale,
        nspOOMisc::stcPoint3d<f32>* psEndPos);

    void GetDrawStrTblSize(
        nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect,
        u32 u32LangIdx,
        s32 s32TblIdx,
        const nspOOMisc::stcPoint3d<f32>* psPos,
        u32 u32Param,
        const nspOOMisc::stcPoint3d<f32>* psScale,
        nspOOMisc::stcPoint3d<f32>* psEndPos)
    {
    }

    u32 ConvertNumberUTF16FromNumber(u32 u32Val, u16* pu16Buf, u32 u32BufLen);

    void GetDrawStringUTF16Size(
        nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect,
        const u16* pu16Str,
        const nspOOMisc::stcPoint3d<f32>* psPos,
        u32 u32Param,
        const nspOOMisc::stcPoint3d<f32>* psScale,
        nspOOMisc::stcPoint3d<f32>* psEndPos);

    u8 ConvertCharaDataFromUTF16(const u16* pu16Str,
                                 u32 u32Len,
                                 nspFontSystem::stcCharaData* pcCharaData,
                                 u32 u32BufLen) const;

    clsOOFontDataSet* GetFontSetting(u32 u32FontNo) { return NULL; }
};

#endif // OOFONTSYSTEM_HPP
