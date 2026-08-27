#include "Develop/Projects/SR2/pgm/lib/OO/CRI/OOCri.hpp"
#include "usr/local/sce/ee/lib/libkernl/kprintf2.h"

namespace {

s32 CriErrFunc_CallBack_Debug(void* pParam, c8* pc8MsgIn)
{
    return scePrintf("*** CRI CriErrFunc_CallBack_Debug() %s\n", pc8MsgIn);
}

} // namespace

clsOOCri::clsOOCri()
{
}

void clsOOCri::resetAdxVolume_All()
{
}

void clsOOCri::setAdxPauseVolume_All()
{
}

u8 clsOOCri::setAdxFadeVolume_Bgm(u32 u32AdxStremNoI, s32 s32FadeVolumeI)
{
    return 0;
}

void clsOOCri::loadPartitionVoice(u32 u32PartitionNoI, const c8* opc8FileNameI)
{
}

s32 clsOOCri::getSfFreeId(s32 s32RequestCodeI)
{
    return 0;
}

void clsOOCri::freeSfFreeId_WithStopSe(s32 s32IdI)
{
}

void clsOOCri::deactivePort(s32 s32MinPortNoI)
{
}

void clsOOCri::reinitSfSeChannel_ICS()
{
}

s32 clsOOCri::getSfSeFreeChannel_ICS()
{
    return 0;
}

void clsOOCri::createSofdec_Movie(s32 s32WorkAlignI,
                                  s32 s32MaxBpsI,
                                  s32 s32WidthI,
                                  s32 s32HeightI,
                                  clsOOHeapFragment* pcAllocatorI,
                                  enmAllocate eAllocateI,
                                  s32 s32MaxPoolWorkI,
                                  s32 s32MaxStreamNumI)
{
}

void clsOOCri::init(u32 u32AdxUseBgmStreamNumI,
                    u32 u32AdxMaxChNum_BgmI,
                    u8* pu8AdxWork_BgmI,
                    u32 u32AdxWorkSize_BgmI,
                    u32 u32AdxMaxChNum_VoiceI,
                    u8* pu8AdxWork_VoiceI,
                    u32 u32AdxWorkSize_VoiceI,
                    u8* pu8AdxWorkAfsPatInfo_VoiceI,
                    u32 u32AdxMaxChNum_JingleI,
                    u8* pu8AdxWork_JingleI,
                    u32 u32AdxWorkSize_JingleI,
                    u8* pu8SfWorkI,
                    u32 u32SfWorkSizeI)
{
}

void clsOOCri::loadSeSf(const c8* opc8FileNameI, u32 u32PackedSizeI, u32 u32PcmI)
{
}

s32 clsOOCri::loadSeSf_ASync(const c8* opc8FileNameI, u32 u32PackedSizeI, u32 u32PcmI)
{
    return 0;
}

u8 clsOOCri::isLoadedSeSf_ASync(s32 s32PortNoI)
{
    return 0;
}

void clsOOCri::reset()
{
}

void clsOOCri::destroySofdec_Movie()
{
}
