#include "usr/local/sega/px/src/pxtex.h"
#include "usr/local/sega/px/src/px.h"

void PXTexBlockSizeToWidthHeight(
    unsigned int bit, unsigned int inw, unsigned int inh, unsigned int* outw, unsigned int* outh)
{
}

unsigned int PXTexWidthHeightToLevel(unsigned int wh)
{
}

unsigned int PXCalcTexLocalMemorySize(unsigned int width,
                                      unsigned int height,
                                      unsigned int bit,
                                      unsigned int miplevel,
                                      unsigned int* tb)
{
}

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
                   unsigned int k)
{
}

unsigned int PXPrepareTexImagePacketSub(struct PXS_QWDATA* p,
                                        unsigned int localptr,
                                        unsigned int dbw,
                                        unsigned int type,
                                        unsigned int bytesize,
                                        unsigned int width,
                                        unsigned int height,
                                        unsigned int sflag)
{
}

unsigned int PXPrepareTexImagePacket(void* startbuf,
                                     void** curtbuf,
                                     unsigned int type,
                                     unsigned int sbit,
                                     unsigned int in_width,
                                     unsigned int in_height,
                                     unsigned int localptr,
                                     unsigned int hostptr,
                                     unsigned int sflag)
{
}

enum PXE_ERR PXLoadTex(void* tagbuf)
{
}

void PXPutTexImage(void* imgtag)
{
    imgtag = (void*)(((int*)imgtag) + 0x8);
    PXPutCall(imgtag);
}

unsigned int PXPrepareTexImagePacketLinear(void* startbuf,
                                           void** curtbuf,
                                           unsigned int type,
                                           unsigned int sbit,
                                           unsigned int width,
                                           unsigned int height,
                                           unsigned int localptr,
                                           unsigned int hostptr,
                                           unsigned int sflag)
{
}
