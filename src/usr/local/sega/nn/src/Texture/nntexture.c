#include "usr/local/sega/nn/src/Texture/nntexture.h"

void nnSetInitIgnoreTextureSwitchPS2(enum NNE_BOOL on_off)
{
}

void nnInitTexturePS2(unsigned int localptr, unsigned int size)
{
}

void nnExitTexturePS2()
{
}

unsigned int nnEstimateTexlistSize(signed int num)
{
}

void nnSetUpTexlist(struct _NNS_TEXLIST** texlist, signed int num, void* buf)
{
}

signed int nnSetTextureList(struct _NNS_TEXLIST* pTexList)
{
}

signed int nnLoadTextureMemoryOne(struct _NNS_TEXINFO* pTexInfo,
                                  void* tex,
                                  unsigned short minfilter,
                                  unsigned short magfilter,
                                  unsigned int globalindex,
                                  unsigned int bank,
                                  unsigned int flag)
{
}

signed int nnReleaseTextureOne(struct _NNS_TEXINFO* pTexInfo)
{
}

void* nnAllocTexLocalMemoryPS2(unsigned int size)
{
}

void nnFreeTexLocalMemoryPS2(void* addr)
{
}

unsigned int nnCalcTexLocalMemoryFreeMaxPS2()
{
}

unsigned int nnCalcTexDmaTagSizeOneCorePS2(struct _NNS_TEXINFO* pTexInfo)
{
}
