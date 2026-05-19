#ifndef NVS_H
#define NVS_H

#include "usr/local/sega/px/src/pxtex.h"

// total size: 0x60
struct NVS_SVROBJ2 {
    struct NVS_GBIXHEADER gbixh; // offset 0x0, size 0x8
    struct NVS_SVRHEADER svrh;   // offset 0x8, size 0x8
    struct PXS_TEXOBJ2 texobj;   // offset 0x10, size 0x50
};

// total size: 0x8
struct NVS_TEXSIZEINFO {
    unsigned char sbit;     // offset 0x0, size 0x1
    unsigned char w_shift;  // offset 0x1, size 0x1
    unsigned char h_shift;  // offset 0x2, size 0x1
    unsigned char reserved; // offset 0x3, size 0x1
    unsigned short w_min;   // offset 0x4, size 0x2
    unsigned short h_min;   // offset 0x6, size 0x2
};

unsigned short nvGetMipLevel(unsigned short type, unsigned short width, unsigned int cnksize);
void* nvGetSVRHeader(struct NVS_SVROBJ* svrobj, void* texptr);
unsigned int nvCalcSVRTexLocalMemorySize(struct NVS_SVROBJ* svrobj);
void nvSetupSVRTexObj(struct NVS_SVROBJ* svrobj,
                      unsigned int localptr,
                      unsigned int clutptr,
                      unsigned int cluttype,
                      unsigned int mag,
                      unsigned int min);
signed int nvCalcSVRTexDMANum(struct NVS_SVROBJ* svrobj);
void nvPrepareSVRTexImagePacket(
    void* startbuf, void** curtbuf, struct NVS_SVROBJ* svrobj, void* texptr, unsigned int localptr);
void nvTexBlockSizeToWidthHeight(
    unsigned int bit, unsigned int inw, unsigned int inh, unsigned int* outw, unsigned int* outh);
unsigned int nvPrepareClutImagePacket(void* startbuf,
                                      void** curtbuf,
                                      unsigned int type,
                                      unsigned int width,
                                      unsigned int height,
                                      unsigned int localptr,
                                      unsigned int hostptr);
void nvPrepareSVRTexImagePacketLinear(
    void* startbuf, void** curtbuf, struct NVS_SVROBJ* svrobj, void* texptr, unsigned int localptr);
signed int nvLoadSVRMemoryTexture(struct NVS_SVROBJ* svrobj,
                                  void* tex,
                                  struct NVS_SVRHEADER* svrh,
                                  signed int mag,
                                  signed int min,
                                  unsigned int bank);
signed int nvLoadSVRMemoryTextureLinear(struct NVS_SVROBJ* svrobj,
                                        void* tex,
                                        struct NVS_SVRHEADER* svrh,
                                        signed int mag,
                                        signed int min,
                                        unsigned int bank);
signed int nvReleaseSVRTexture(struct NVS_SVROBJ* svrobj);
signed int nvCalcSVRTexDMANumHigh(struct NVS_SVROBJ* svrobj);

#endif // NVS_H
