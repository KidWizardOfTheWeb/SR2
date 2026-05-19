#include "Develop/Projects/SR2/pgm/src/System/SrFontSystem.hpp"

namespace {
static u16 tau16StrBuff[32];
}

clsSrFontSystem::clsSrFontSystem()
{
}

void clsSrFontSystem::setFontDataFromFile(
    nspSrFontSystem::enmFontNo, void* pvParam2, void* pvParam3, void* pvParam4, s32 s32Param5)
{
}

void clsSrFontSystem::delFontData(nspSrFontSystem::enmFontNo)
{
}

void clsSrFontSystem::delBtnTexBuff()
{
}

void clsSrFontSystem::delUnResidenceFontData()
{
}

void clsSrFontSystem::loadFontData(nspSrFontSystem::enmFontNo,
                                   s32 s32Param2,
                                   void* pvParam3,
                                   bool bParam4)
{
}

void clsSrFontSystem::reloadFontData(nspSrFontSystem::enmFontNo)
{
}

u8 clsSrFontSystem::chkAllLoadEnd()
{
    return 0;
}

void clsSrFontSystem::DrawLocalCode(
    s32 s32Param1,
    s32 s32Param2,
    const nspOOMisc::stcPoint3d<f32>* pParam3,
    u32 u32Param4,
    const nspOOMisc::stcPoint3d<f32>* pParam5,
    nspOOMisc::stcPoint3d<f32>* pParam6,
    nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* pParam7,
    f32* pParam8)
{
}

void clsSrFontSystem::DrawLocalCodeMemoCa(
    s32 s32Param1,
    const nspOOMisc::stcPoint3d<f32>* pParam2,
    u32 u32Param3,
    const nspOOMisc::stcPoint3d<f32>* pParam4,
    nspOOMisc::stcPoint3d<f32>* pParam5,
    nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* pParam6,
    f32* pParam7)
{
}

void clsSrFontSystem::DrawLocalCodeMission(
    s32 s32Param1,
    const nspOOMisc::stcPoint3d<f32>* pParam2,
    u32 u32Param3,
    const nspOOMisc::stcPoint3d<f32>* pParam4,
    nspOOMisc::stcPoint3d<f32>* pParam5,
    nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* pParam6,
    f32* pParam7)
{
}

void clsSrFontSystem::DrawLocalCodeUnion(
    s32 s32Param1,
    const nspOOMisc::stcPoint3d<f32>* pParam2,
    u32 u32Param3,
    const nspOOMisc::stcPoint3d<f32>* pParam4,
    nspOOMisc::stcPoint3d<f32>* pParam5,
    nspOOMisc::stcRect<nspOOMisc::stcPoint2d<f32>, nspOOMisc::stcSize2d<f32> >* pParam6,
    f32* pParam7)
{
}

clsSrFontSystem::~clsSrFontSystem()
{
}
