#ifndef NNTEXTURE_H
#define NNTEXTURE_H

#include "usr/local/sega/nn/src/System/nnsystem.h"

struct sceGsTex1 {
    unsigned long LCM : 1;
    unsigned long pad01 : 1;
    unsigned long MXL : 3;
    unsigned long MMAG : 1;
    unsigned long MMIN : 3;
    unsigned long MTBA : 1;
    unsigned long pad10 : 9;
    unsigned long L : 2;
    unsigned long pad21 : 11;
    unsigned long K : 12;
    unsigned long pad44 : 20;
};

struct sceGsTex0 {
    unsigned long TBP0 : 14;
    unsigned long TBW : 6;
    unsigned long PSM : 6;
    unsigned long TW : 4;
    unsigned long TH : 4;
    unsigned long TCC : 1;
    unsigned long TFX : 2;
    unsigned long CBP : 14;
    unsigned long CPSM : 4;
    unsigned long CSM : 1;
    unsigned long CSA : 5;
    unsigned long CLD : 3;
};

struct sceGsMiptbp1 {
    unsigned long TBP1 : 14;
    unsigned long TBW1 : 6;
    unsigned long TBP2 : 14;
    unsigned long TBW2 : 6;
    unsigned long TBP3 : 14;
    unsigned long TBW3 : 6;
    unsigned long pad60 : 4;
};

struct sceGsMiptbp2 {
    unsigned long TBP4 : 14;
    unsigned long TBW4 : 6;
    unsigned long TBP5 : 14;
    unsigned long TBW5 : 6;
    unsigned long TBP6 : 14;
    unsigned long TBW6 : 6;
    unsigned long pad60 : 4;
};

struct PXS_TEXREG {
    struct sceGsTex1 tex1;       // offset 0x0, size 0x8
    struct sceGsTex0 tex0;       // offset 0x8, size 0x8
    struct sceGsMiptbp1 miptbp1; // offset 0x10, size 0x8
    struct sceGsMiptbp2 miptbp2; // offset 0x18, size 0x8
};

struct PXS_TEXOBJ {
    struct PXS_TEXREG texReg; // offset 0x0, size 0x20
};

struct NVS_GBIXHEADER {
    unsigned int globalIndex; // offset 0x0, size 0x4
    unsigned int bank;        // offset 0x4, size 0x4
};

struct NVS_SVRHEADER {
    unsigned short type;     // offset 0x0, size 0x2
    unsigned short miplevel; // offset 0x2, size 0x2
    unsigned short width;    // offset 0x4, size 0x2
    unsigned short height;   // offset 0x6, size 0x2
};

struct NVS_SVROBJ {
    struct NVS_GBIXHEADER gbixh; // offset 0x0, size 0x8
    struct NVS_SVRHEADER svrh;   // offset 0x8, size 0x8
    struct PXS_TEXOBJ texobj;    // offset 0x10, size 0x20
};

// total size: 0x50
struct _NNS_TEXINFO {
    struct NVS_SVROBJ SvrObj;  // offset 0x0, size 0x30
    void* pMainMemory;         // offset 0x30, size 0x4
    void* pLocalMemory;        // offset 0x34, size 0x4
    unsigned int nLocalBytes;  // offset 0x38, size 0x4
    unsigned int nDmaTagBytes; // offset 0x3C, size 0x4
    unsigned int GlobalIndex;  // offset 0x40, size 0x4
    unsigned int Bank;         // offset 0x44, size 0x4
    unsigned short MinFilter;  // offset 0x48, size 0x2
    unsigned short MagFilter;  // offset 0x4A, size 0x2
    unsigned int Flag;         // offset 0x4C, size 0x4
};

// total size: 0x8
struct _NNS_TEXLIST {
    signed int nTex;                   // offset 0x0, size 0x4
    struct _NNS_TEXINFO* pTexInfoList; // offset 0x4, size 0x4
};

// total size: 0x10
struct NNS_TEXAREA_PARAM {
    unsigned int startaddr; // offset 0x0, size 0x4
    unsigned int endaddr;   // offset 0x4, size 0x4
    unsigned int curraddr;  // offset 0x8, size 0x4
    unsigned int size;      // offset 0xC, size 0x4
};

extern struct _NNS_TEXLIST* nngCurrentTextureList;
extern struct NNS_TEXAREA_PARAM nngTexArea;
extern enum NNE_BOOL nnsIgnoreTextureSwitch;

void nnSetInitIgnoreTextureSwitchPS2(enum NNE_BOOL on_off);
void nnInitTexturePS2(unsigned int localptr, unsigned int size);
void nnExitTexturePS2();
unsigned int nnEstimateTexlistSize(signed int num);
void nnSetUpTexlist(struct _NNS_TEXLIST** texlist, signed int num, void* buf);
signed int nnSetTextureList(struct _NNS_TEXLIST* pTexList);
signed int nnLoadTextureMemoryOne(struct _NNS_TEXINFO* pTexInfo,
                                  void* tex,
                                  unsigned short minfilter,
                                  unsigned short magfilter,
                                  unsigned int globalindex,
                                  unsigned int bank,
                                  unsigned int flag);
signed int nnReleaseTextureOne(struct _NNS_TEXINFO* pTexInfo);
void* nnAllocTexLocalMemoryPS2(unsigned int size);
void nnFreeTexLocalMemoryPS2(void* addr);
unsigned int nnCalcTexLocalMemoryFreeMaxPS2();
unsigned int nnCalcTexDmaTagSizeOneCorePS2(struct _NNS_TEXINFO* pTexInfo);

#endif // NNTEXTURE_H
