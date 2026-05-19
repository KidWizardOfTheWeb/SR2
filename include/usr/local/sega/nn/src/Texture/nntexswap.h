#ifndef NNTEXSWAP_H
#define NNTEXSWAP_H

#include "usr/local/sega/nn/src/Texture/nntexture.h"

// total size: 0xC
struct NNS_TEXCACHE_INFO_PS2 {
    signed int CacheOrder;         // offset 0x0, size 0x4
    unsigned int CacheAddr;        // offset 0x4, size 0x4
    struct _NNS_TEXINFO* pTexInfo; // offset 0x8, size 0x4
};

// total size: 0xFC
struct NNS_TEXCACHE_PS2 {
    unsigned int Flag;                            // offset 0x0, size 0x4
    struct NNS_TEXCACHE_INFO_PS2 CacheInfo[2][8]; // offset 0x4, size 0xC0
    unsigned int iCurrOrder[2];                   // offset 0xC4, size 0x8
    unsigned int CacheSize[2];                    // offset 0xCC, size 0x8
    unsigned int iCurrCache;                      // offset 0xD4, size 0x4
    unsigned int nCache;                          // offset 0xD8, size 0x4
    unsigned int CacheBuffAddr;                   // offset 0xDC, size 0x4
    unsigned int CacheBuffSize;                   // offset 0xE0, size 0x4
    unsigned int TransferNum;                     // offset 0xE4, size 0x4
    unsigned int TransferSize;                    // offset 0xE8, size 0x4
    unsigned int CacheHitNum;                     // offset 0xEC, size 0x4
    unsigned int CacheHitSize;                    // offset 0xF0, size 0x4
    unsigned int fReqSync;                        // offset 0xF4, size 0x4
    void* pLastSyncPath3Tag;                      // offset 0xF8, size 0x4
};

// total size: 0x10
struct NNS_TEXDMATAGINFO {
    unsigned int nDmaTag;     // offset 0x0, size 0x4
    void* pLocalMemory;       // offset 0x4, size 0x4
    unsigned int nLocalBytes; // offset 0x8, size 0x4
    void* pDmaTagList;        // offset 0xC, size 0x4
};

extern unsigned int nngTexSwapMode;

void nnInitTextureSwapPS2();
void nnSetTextureSwapModePS2(unsigned int mode);

#endif // NNTEXSWAP_H
