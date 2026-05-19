#ifndef PS2CRI_HPP
#define PS2CRI_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/CRI/OOCri.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "types.h"

// total size: 0x1B1C
class clsPfCri : public clsSingleton<clsPfCri>, public clsOOCri {
public:
    virtual ~clsPfCri() {}

    virtual void setParameterSfSe_3D(s32 s32IdI,
                                     u32 u32vI,
                                     const f32 (*opsViewMtxI)[4][4],
                                     const NNS_VECTORFAST* opsPosFastI,
                                     f32 f32DistDownKI);
    virtual void stopSfSe_All() {}
    virtual void pauseSfSe_All() {}
    virtual void continueSfSe_All() {}
    virtual void playSfSe_3D(s32 s32IdI) {}
    virtual void stopSfSe_3D(s32 s32IdI) {}
    virtual void destroy();
    virtual void createSofdec_Movie(s32 s32WorkAlignI,
                                    s32 s32MaxBpsI,
                                    s32 s32WidthI,
                                    s32 s32HeightI,
                                    clsOOHeapFragment* pcAllocatorI,
                                    enmAllocate eAllocateI,
                                    s32 s32MaxPoolWorkI,
                                    s32 s32MaxStreamNumI);
    virtual void destroySofdec_Movie();
    virtual void setDolbyDigitalCh_Movie(s32 s32Param1) {}
    virtual void setThreadParam();
    virtual void setThreadParamEx();
    virtual void initAdx(u32 u32AdxMaxChNum_BgmI,
                         u32 u32AdxWorkSize_BgmI,
                         u32 u32AdxMaxChNum_VoiceI,
                         u32 u32AdxWorkSize_VoiceI,
                         u32 u32AdxMaxChNum_JingleI,
                         u32 u32AdxWorkSize_JingleI);
    virtual void initSf(u8* pu8SfWorkI, u32 u32SfWorkSizeI);

    static s32 tSoundVsyncCallback(s32 s32Param1);

    u8 m_au8Ac3Work_Bgm[6144]; // offset 0x318, size 0x1800
    void* m_pvAc3Work_Heap;    // offset 0x1B18, size 0x4
};

#endif // PS2CRI_HPP
