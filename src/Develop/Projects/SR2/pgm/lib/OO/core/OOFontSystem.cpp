#include "Develop/Projects/SR2/pgm/lib/OO/core/OOFontSystem.hpp"

u16 m_toau16NumberCode[10];

stcRgbaF32 clsOOFontDataSet::m_tosFontDefColor = {1.0f, 1.0f, 1.0f, 1.0f};

void clsOOFontStrTbl::SetStrTblData(void* pvStrTblData)
{
}

u8 clsOOFontStrTbl::IsCharaCntData(const nspFontSystem::stcCharaData* psCharaData) const
{
    return 0;
}

void clsOOFontObj::SetFontData(clsOOTexture* psTex, void* pvFontStatus)
{
}

void clsOOFontObj::SetFontStrTbl(clsOOFontStrTbl* pcStrTbl)
{
}

clsOOFontDataSet::clsOOFontDataSet(clsOOFontObj* pcObj,
                                   f32 f32Size,
                                   const nspOOMisc::stcRgbaF32& sColor)
{
}

clsOOFontSystem::clsOOFontSystem(clsOODraw2d* pcDraw2d,
                                 u32 u32MaxFontObj,
                                 clsOOHeapFragment* pcAllocator)
{
}

u8 clsOOFontSystem::ConvertCharaDataFromUTF16(const u16* pu16Str,
                                              u32 u32Len,
                                              nspFontSystem::stcCharaData* pcCharaData,
                                              u32 u32BufLen) const
{
    return 0;
}

void clsOOFontSystem::GetDrawStringUTF16Size(
    nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect,
    const u16* pu16Str,
    const nspOOMisc::stcPoint3d<f32>* psPos,
    u32 u32Param,
    const nspOOMisc::stcPoint3d<f32>* psScale,
    nspOOMisc::stcPoint3d<f32>* psEndPos)
{
}

u32 clsOOFontSystem::ConvertNumberUTF16FromNumber(u32 u32Val, u16* pu16Buf, u32 u32BufLen)
{
    return 0;
}

void clsOOFontSystem::GetDrawStrTblSize(
    nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect,
    s32 s32TblIdx,
    const nspOOMisc::stcPoint3d<f32>* psPos,
    u32 u32Param,
    const nspOOMisc::stcPoint3d<f32>* psScale,
    nspOOMisc::stcPoint3d<f32>* psEndPos)
{
}

void clsOOFontSystem::DrawStringUTF16(
    const u16* pu16Str,
    const nspOOMisc::stcPoint3d<f32>* psPos,
    u32 u32Param,
    const nspOOMisc::stcPoint3d<f32>* psScale,
    nspOOMisc::stcPoint3d<f32>* psEndPos,
    nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect,
    f32* pf32)
{
}

void clsOOFontSystem::DrawStrTbl(
    s32 s32TblIdx,
    const nspOOMisc::stcPoint3d<f32>* psPos,
    u32 u32Param,
    const nspOOMisc::stcPoint3d<f32>* psScale,
    nspOOMisc::stcPoint3d<f32>* psEndPos,
    nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect,
    f32* pf32)
{
}

void clsOOFontSystem::DrawString(
    const nspFontSystem::stcCharaData* pcChara,
    const nspOOMisc::stcPoint3d<f32>* psPos,
    u32 u32Param,
    const nspOOMisc::stcPoint3d<f32>* psScale,
    nspOOMisc::stcPoint3d<f32>* psEndPos,
    nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect,
    f32* pf32)
{
}

void clsOOFontSystem::AutoReturnString(
    clsOOFontDataSet* pcDataSet,
    const nspOOMisc::stcRect<nspOOMisc::stcPoint2d<s32>, nspOOMisc::stcSize2d<s32> >& rClip,
    f32 f32a,
    f32 f32b,
    nspOOMisc::stcPoint3d<f32>* psPos,
    nspOOMisc::stcPoint3d<f32>* psEndPos,
    f32* pf32)
{
}

u8 clsOOFontSystem::ExecCtrlCode(
    const nspFontSystem::stcCharaData& rChara,
    nspOOMisc::stcPoint3d<f32>* psPos,
    const nspOOMisc::stcRect<nspOOMisc::stcPoint2d<s32>, nspOOMisc::stcSize2d<s32> >& rClip,
    f32 f32a,
    f32* pf32b,
    f32* pf32c,
    u32* pu32,
    nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect)
{
    return 0;
}

u8 clsOOFontSystem::DrawChara(
    const nspFontSystem::stcCharaData& rChara,
    const nspOOMisc::stcPoint3d<f32>& rPos,
    const nspOOMisc::stcRect<nspOOMisc::stcPoint2d<s32>, nspOOMisc::stcSize2d<s32> >& rClip,
    nspOOMisc::stcSize2d<f32>* psSize,
    nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect)
{
    return 0;
}

u8 clsOOFontSystem::ChkCharaClipping(
    nspOOMisc::stcPoint3d<f32>* psPos,
    nspOOMisc::stcSize2d<f32>* psSize,
    nspOOMisc::stcUvRect<f32>* psUv,
    const nspOOMisc::stcUvRect<s32>& rUvInt,
    const nspOOMisc::stcRect<nspOOMisc::stcPoint2d<s32>, nspOOMisc::stcSize2d<s32> >& rClip,
    f32 f32a,
    const nspOOMisc::stcSize2d<s32>& rSizeInt)
{
    return 0;
}

u8 clsOOFontSystem::DrawBtn(
    u8 u8Param,
    const nspOOMisc::stcPoint3d<f32>& rPos,
    const nspOOMisc::stcRect<nspOOMisc::stcPoint2d<s32>, nspOOMisc::stcSize2d<s32> >& rClip,
    nspOOMisc::stcSize2d<f32>* psSize,
    nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect)
{
    return 0;
}

void clsOOFontSystem::DrawData(nspOOMisc::stcPoint3d<f32>& rPos,
                               nspOOMisc::stcSize2d<f32>& rSize,
                               nspOOMisc::stcUvRect<f32>& rUv,
                               clsOOTexture& rTex,
                               s32 s32Param,
                               u32 u32Param)
{
}

void clsOOFontSystem::DrawLocalCode(
    s32 s32a,
    s32 s32b,
    const nspOOMisc::stcPoint3d<f32>* psPos,
    u32 u32Param,
    const nspOOMisc::stcPoint3d<f32>* psScale,
    nspOOMisc::stcPoint3d<f32>* psEndPos,
    nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* psRect,
    f32* pf32)
{
}

f32 clsOOFontDataSet::GetFontPointSize() const
{
    return 0.0f;
}
