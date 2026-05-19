#include "Develop/Projects/SR2/pgm/lib/OO/PS2_CRI/PS2Cri.hpp"

// total size: 0x18
class SNDFPS2_SPRM {
public:
    u32 iopmemsize;        // offset 0x0, size 0x4
    void* iopmemaddr;      // offset 0x4, size 0x4
    u32 sdinit;            // offset 0x8, size 0x4
    u32 dmach;             // offset 0xC, size 0x4
    u32 nouse_setportsize; // offset 0x10, size 0x4
    u32 datasizespu2;      // offset 0x14, size 0x4
};

static s8 tau8usr_stack_usrvsync[4096];
static s8 tau8usr_stack_usridle[4096];

void clsPfCri::setThreadParam()
{
}

void clsPfCri::setThreadParamEx()
{
}

s32 clsPfCri::tSoundVsyncCallback(s32 s32Param1)
{
    return 0;
}

void clsPfCri::initAdx(u32 u32AdxMaxChNum_BgmI,
                       u32 u32AdxWorkSize_BgmI,
                       u32 u32AdxMaxChNum_VoiceI,
                       u32 u32AdxWorkSize_VoiceI,
                       u32 u32AdxMaxChNum_JingleI,
                       u32 u32AdxWorkSize_JingleI)
{
}

void clsPfCri::initSf(u8* pu8SfWorkI, u32 u32SfWorkSizeI)
{
}

void clsPfCri::setParameterSfSe_3D(s32 s32IdI,
                                   u32 u32vI,
                                   const f32 (*opsViewMtxI)[4][4],
                                   const NNS_VECTORFAST* opsPosFastI,
                                   f32 f32DistDownKI)
{
}

void clsPfCri::createSofdec_Movie(s32 s32WorkAlignI,
                                  s32 s32MaxBpsI,
                                  s32 s32WidthI,
                                  s32 s32HeightI,
                                  clsOOHeapFragment* pcAllocatorI,
                                  enmAllocate eAllocateI,
                                  s32 s32MaxPoolWorkI,
                                  s32 s32MaxStreamNumI)
{
}

void clsPfCri::destroySofdec_Movie()
{
}

void clsPfCri::destroy()
{
}
