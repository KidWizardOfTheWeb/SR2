#include "usr/local/sega/nvs/src/nvs.h"

unsigned short nvGetMipLevel(unsigned short type, unsigned short width, unsigned int cnksize)
{
}

void* nvGetSVRHeader(struct NVS_SVROBJ* svrobj, void* texptr)
{
}

unsigned int nvCalcSVRTexLocalMemorySize(struct NVS_SVROBJ* svrobj)
{
}

void nvSetupSVRTexObj(struct NVS_SVROBJ* svrobj,
                      unsigned int localptr,
                      unsigned int clutptr,
                      unsigned int cluttype,
                      unsigned int mag,
                      unsigned int min)
{
}

signed int nvCalcSVRTexDMANum(struct NVS_SVROBJ* svrobj)
{
}

void nvPrepareSVRTexImagePacket(
    void* startbuf, void** curtbuf, struct NVS_SVROBJ* svrobj, void* texptr, unsigned int localptr)
{
}

void nvTexBlockSizeToWidthHeight(
    unsigned int bit, unsigned int inw, unsigned int inh, unsigned int* outw, unsigned int* outh)
{
}

unsigned int nvPrepareClutImagePacket(void* startbuf,
                                      void** curtbuf,
                                      unsigned int type,
                                      unsigned int width,
                                      unsigned int height,
                                      unsigned int localptr,
                                      unsigned int hostptr)
{
}

void nvPrepareSVRTexImagePacketLinear(
    void* startbuf, void** curtbuf, struct NVS_SVROBJ* svrobj, void* texptr, unsigned int localptr)
{
}

signed int nvLoadSVRMemoryTexture(struct NVS_SVROBJ* svrobj,
                                  void* tex,
                                  struct NVS_SVRHEADER* svrh,
                                  signed int mag,
                                  signed int min,
                                  unsigned int bank)
{
}

signed int nvLoadSVRMemoryTextureLinear(struct NVS_SVROBJ* svrobj,
                                        void* tex,
                                        struct NVS_SVRHEADER* svrh,
                                        signed int mag,
                                        signed int min,
                                        unsigned int bank)
{
}

signed int nvReleaseSVRTexture(struct NVS_SVROBJ* svrobj)
{
}

signed int nvCalcSVRTexDMANumHigh(struct NVS_SVROBJ* svrobj)
{
}
