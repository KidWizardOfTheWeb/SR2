#ifndef OOCRI_HPP
#define OOCRI_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOHeapFragment.hpp"
#include "types.h"
#include "usr/local/cri/mwlib/ee/lib/cri_libs.h"

// total size: 0x180
class SNDF_PSPRM {
public:
    u32 porttbl[48]; // offset 0x0, size 0xC0
    u32 portpcm[48]; // offset 0xC0, size 0xC0
};

// total size: 0xC8
class _adx_talk {
public:
    s8 used;           // offset 0x0, size 0x1
    s8 stat;           // offset 0x1, size 0x1
    s8 pmode;          // offset 0x2, size 0x1
    s8 maxnch;         // offset 0x3, size 0x1
    void* sjd;         // offset 0x4, size 0x4
    void* stm;         // offset 0x8, size 0x4
    void* rna;         // offset 0xC, size 0x4
    SJ_OBJ* sjf;       // offset 0x10, size 0x4
    SJ_OBJ* sji;       // offset 0x14, size 0x4
    SJ_OBJ* sjo[2];    // offset 0x18, size 0x8
    s8* ibuf;          // offset 0x20, size 0x4
    s32 ibuflen;       // offset 0x24, size 0x4
    s32 ibufxlen;      // offset 0x28, size 0x4
    s16* obuf;         // offset 0x2C, size 0x4
    s32 obufsize;      // offset 0x30, size 0x4
    s32 obufdist;      // offset 0x34, size 0x4
    s32 svrfreq;       // offset 0x38, size 0x4
    s16 maxsct;        // offset 0x3C, size 0x2
    s16 minsct;        // offset 0x3E, size 0x2
    s16 outvol;        // offset 0x40, size 0x2
    s16 outpan[2];     // offset 0x42, size 0x4
    s16 outbalance;    // offset 0x46, size 0x2
    s32 maxdecsmpl;    // offset 0x48, size 0x4
    s32 lpcnt;         // offset 0x4C, size 0x4
    s32 lp_skiplen;    // offset 0x50, size 0x4
    s32 trp;           // offset 0x54, size 0x4
    s32 wpos;          // offset 0x58, size 0x4
    s32 mofst;         // offset 0x5C, size 0x4
    s16 ercode;        // offset 0x60, size 0x2
    s32 edecpos;       // offset 0x64, size 0x4
    s16 edeccnt;       // offset 0x68, size 0x2
    s16 eshrtcnt;      // offset 0x6A, size 0x2
    s8 lpflg;          // offset 0x6C, size 0x1
    s8 autorcvr;       // offset 0x6D, size 0x1
    s8 fltmode;        // offset 0x6E, size 0x1
    s8 execflag;       // offset 0x6F, size 0x1
    s8 pstwait_flag;   // offset 0x70, size 0x1
    s8 pstready_flag;  // offset 0x71, size 0x1
    s8 pause_flag;     // offset 0x72, size 0x1
    void* amp;         // offset 0x74, size 0x4
    SJ_OBJ* ampsji[2]; // offset 0x78, size 0x8
    SJ_OBJ* ampsjo[2]; // offset 0x80, size 0x8
    s32 time_ofst;     // offset 0x88, size 0x4
    s32 lesct;         // offset 0x8C, size 0x4
    s32 trpnsmpl;      // offset 0x90, size 0x4
    void* lsc;         // offset 0x94, size 0x4
    s8 lnkflg;         // offset 0x98, size 0x1
    s8 rsv;            // offset 0x99, size 0x1
    s16 rsv2;          // offset 0x9A, size 0x2
    u32 tvofst;        // offset 0x9C, size 0x4
    u32 svcnt;         // offset 0xA0, size 0x4
    u32 decofst;       // offset 0xA4, size 0x4
    s32 flush_nsmpl;   // offset 0xA8, size 0x4
    s8 stm_start_flg;  // offset 0xAC, size 0x1
    s8 ainf_sw;        // offset 0xAD, size 0x1
    s16 rsv4;          // offset 0xAE, size 0x2
    c8* fname_wk;      // offset 0xB0, size 0x4
    c8* fname;         // offset 0xB4, size 0x4
    void* dir;         // offset 0xB8, size 0x4
    u32 ofst;          // offset 0xBC, size 0x4
    u32 nsct;          // offset 0xC0, size 0x4
    u32 lpoff_len;     // offset 0xC4, size 0x4
};

// total size: 0x314
class clsOOCri {
    // Members
public:
    enum enmAllocate {
        ALLOCATE_NONE = 0,
        ALLOCATE_POOL = 1,
    };
    SNDF_PSPRM m_sSfPsprm;                  // offset 0x4, size 0x180
    _adx_talk* m_pasAdxtHandle_Bgm[4];      // offset 0x184, size 0x10
    _adx_talk* m_psAdxtHandle_Voice;        // offset 0x194, size 0x4
    _adx_talk* m_psAdxtHandle_Jingle;       // offset 0x198, size 0x4
    void* m_psSofdecHandle_Movie;           // offset 0x19C, size 0x4
    clsOOHeapFragment* m_pcAllocator_Movie; // offset 0x1A0, size 0x4
    u8* m_pu8AdxWork_Bgm;                   // offset 0x1A4, size 0x4
    u8* m_pu8AdxWork_Voice;                 // offset 0x1A8, size 0x4
    u8* m_pu8AdxWorkAfsPatInfo_Voice;       // offset 0x1AC, size 0x4
    u8* m_pu8AdxWork_Jingle;                // offset 0x1B0, size 0x4
    u8 m_u8AdxStreamNum_Bgm;                // offset 0x1B4, size 0x1
    s8 m_s8SfPortNo;                        // offset 0x1B5, size 0x1
    u8 m_au8SfId[256];                      // offset 0x1B6, size 0x100
    s8 m_s8SfIcsChannel;                    // offset 0x2B6, size 0x1
    u8 (*m_fnDiscError)();                  // offset 0x2B8, size 0x4
    MwsfdCrePrm m_sSofdecParam_Movie;       // offset 0x2BC, size 0x3C
    s16 m_as16DefVolume_Bgm[4];             // offset 0x2F8, size 0x8
    s16 m_s16DefVolume_Voice;               // offset 0x300, size 0x2
    s16 m_s16DefVolume_Jingle;              // offset 0x302, size 0x2
    s16 m_as16Volume_Bgm[4];                // offset 0x304, size 0x8
    s16 m_s16Volume_Voice;                  // offset 0x30C, size 0x2
    s16 m_s16Volume_Jingle;                 // offset 0x30E, size 0x2
    s16 m_s16PauseMinus;                    // offset 0x310, size 0x2

    // Virtual functions
public:
    clsOOCri();

    virtual s32 getSfFreeId(s32 s32RequestCodeI);
    virtual void loadSeSf(const c8* opc8FileNameI, u32 u32PackedSizeI, u32 u32PcmI);
    virtual s32 loadSeSf_ASync(const c8* opc8FileNameI, u32 u32PackedSizeI, u32 u32PcmI);
    virtual u8 isLoadedSeSf_ASync(s32 s32PortNoI);
    virtual void createSofdec_Movie(s32 s32WorkAlignI,
                                    s32 s32MaxBpsI,
                                    s32 s32WidthI,
                                    s32 s32HeightI,
                                    clsOOHeapFragment* pcAllocatorI,
                                    enmAllocate eAllocateI,
                                    s32 s32MaxPoolWorkI,
                                    s32 s32MaxStreamNumI);
    virtual void destroySofdec_Movie();

    void reset();
    void init(u32 u32AdxUseBgmStreamNumI,
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
              u32 u32SfWorkSizeI);
    void loadPartitionVoice(u32 u32PartitionNoI, const c8* opc8FileNameI);
    void freeSfFreeId_WithStopSe(s32 s32IdI);
    void deactivePort(s32 s32MinPortNoI);
    void reinitSfSeChannel_ICS();
    s32 getSfSeFreeChannel_ICS();
    u8 setAdxFadeVolume_Bgm(u32 u32AdxStremNoI, s32 s32FadeVolumeI);
    void setAdxPauseVolume_All();
    void resetAdxVolume_All();
    void pauseAdxBgm(u32 u32AdxStreamNoI) {}
    void playAdxBgmName(u32 u32AdxStreamNoI, const c8* opc8FileNameI) {}
    void resetAdxVolume_Bgm(u32 u32AdxStreamNoI) {}
    void playSfSe_WithId(s32 s32IdI) {}
    void playSfSe(s32 s32RequestCodeI) {}
    void stopSfSe_WithId(s32 s32IdI) {}
    void playAdxVoice(s32 s32PartitionNoI, s32 s32FileNoI) {}
    void stopAdxJingle() {}
    void stopAdxVoice() {}
    void stopAdxBgm_All() {}
};

typedef clsOOCri::enmAllocate enmAllocate;

#endif // OOCRI_HPP
