#ifndef PXTEX_H
#define PXTEX_H

#include "usr/local/sega/nn/src/Texture/nntexture.h"
#include "usr/local/sega/px/src/pxtex2.h"

struct PXS_QWDATA;

// total size: 0x50
struct PXS_TEXREG2 {
    unsigned int giftag[4];      // offset 0x0, size 0x10
    struct sceGsTex1 tex1;       // offset 0x10, size 0x8
    unsigned long tex1addr;      // offset 0x18, size 0x4
    struct sceGsTex0 tex0;       // offset 0x20, size 0x8
    unsigned long tex0addr;      // offset 0x28, size 0x4
    struct sceGsMiptbp1 miptbp1; // offset 0x30, size 0x8
    unsigned long miptbp1addr;   // offset 0x38, size 0x4
    struct sceGsMiptbp2 miptbp2; // offset 0x40, size 0x8
    unsigned long miptbp2addr;   // offset 0x48, size 0x4
};

// total size: 0x50
struct PXS_TEXOBJ2 {
    struct PXS_TEXREG2 texReg; // offset 0x0, size 0x50
};

// total size: 0x6
struct PXS_TEXSIZEINFO {
    unsigned char dbit;  // offset 0x0, size 0x1
    unsigned char shift; // offset 0x1, size 0x1
    unsigned short wmin; // offset 0x2, size 0x2
    unsigned short hmin; // offset 0x4, size 0x2
};

void PXTexBlockSizeToWidthHeight(
    unsigned int bit, unsigned int inw, unsigned int inh, unsigned int* outw, unsigned int* outh);
unsigned int PXTexWidthHeightToLevel(unsigned int wh);
unsigned int PXCalcTexLocalMemorySize(unsigned int width,
                                      unsigned int height,
                                      unsigned int bit,
                                      unsigned int miplevel,
                                      unsigned int* tb);
void PXSetupTexObj(struct PXS_TEXOBJ* texobj,
                   unsigned int localptr,
                   unsigned int type,
                   unsigned int width,
                   unsigned int height,
                   unsigned int tcc,
                   unsigned int tfx,
                   unsigned int clutptr,
                   unsigned int cluttype,
                   unsigned int csm,
                   unsigned int csa,
                   unsigned int lcm,
                   unsigned int miplevel,
                   unsigned int mag,
                   unsigned int min,
                   unsigned int l,
                   unsigned int k);
unsigned int PXPrepareTexImagePacketSub(struct PXS_QWDATA* p,
                                        unsigned int localptr,
                                        unsigned int dbw,
                                        unsigned int type,
                                        unsigned int bytesize,
                                        unsigned int width,
                                        unsigned int height,
                                        unsigned int sflag);
unsigned int PXPrepareTexImagePacket(void* startbuf,
                                     void** curtbuf,
                                     unsigned int type,
                                     unsigned int sbit,
                                     unsigned int in_width,
                                     unsigned int in_height,
                                     unsigned int localptr,
                                     unsigned int hostptr,
                                     unsigned int sflag);
enum PXE_ERR PXLoadTex(void* tagbuf);
void PXPutTexImage(void* imgtag);
unsigned int PXPrepareTexImagePacketLinear(void* startbuf,
                                           void** curtbuf,
                                           unsigned int type,
                                           unsigned int sbit,
                                           unsigned int width,
                                           unsigned int height,
                                           unsigned int localptr,
                                           unsigned int hostptr,
                                           unsigned int sflag);

#endif // PXTEX_H
