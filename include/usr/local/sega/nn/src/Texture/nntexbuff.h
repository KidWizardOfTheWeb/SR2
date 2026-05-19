#ifndef NNTEXBUFF_H
#define NNTEXBUFF_H

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "usr/local/sega/nn/src/Texture/nntexture.h"

// total size: 0x18
struct NNS_PUSHBUFFER1 {
    __int128* tagTop;      // offset 0x0, size 0x4
    __int128* tagPtr;      // offset 0x4, size 0x4
    unsigned int bufSize;  // offset 0x8, size 0x4
    unsigned int maxTags;  // offset 0xC, size 0x4
    unsigned int numTags;  // offset 0x10, size 0x4
    unsigned int numBytes; // offset 0x14, size 0x4
};

// total size: 0x48
struct NNS_PUSHBUFFER {
    unsigned int flag;            // offset 0x0, size 0x4
    unsigned int dbIndex;         // offset 0x4, size 0x4
    unsigned int maxData;         // offset 0x8, size 0x4
    unsigned int workSize;        // offset 0xC, size 0x4
    unsigned int peakTags;        // offset 0x10, size 0x4
    unsigned int peakBytes;       // offset 0x14, size 0x4
    struct NNS_PUSHBUFFER1 db[2]; // offset 0x18, size 0x30
};

// total size: 0x34
struct NNS_TEXBUFF_PS2 {
    unsigned int Flag;              // offset 0x0, size 0x4
    unsigned int StartAddr[3];      // offset 0x4, size 0xC
    unsigned int EndAddr[3];        // offset 0x10, size 0xC
    unsigned int CurrAddr;          // offset 0x1C, size 0x4
    unsigned int BlockSize;         // offset 0x20, size 0x4
    unsigned char nBlock;           // offset 0x24, size 0x1
    unsigned char iCurrBlock;       // offset 0x25, size 0x1
    unsigned short iCurrBlockTotal; // offset 0x26, size 0x2
    unsigned short iCurr;           // offset 0x28, size 0x2
    unsigned short fReqSync;        // offset 0x2A, size 0x2
    unsigned int TransferNum;       // offset 0x2C, size 0x4
    unsigned int TransferSize;      // offset 0x30, size 0x4
};

// total size: 0xE
struct NNS_TEXPATH3DMA_PS2 {
    unsigned short nBlock;     // offset 0x0, size 0x2
    unsigned short iCurrBlock; // offset 0x2, size 0x2
    unsigned short iTail;      // offset 0x4, size 0x2
    unsigned short iDraw;      // offset 0x6, size 0x2
    signed short iStall;       // offset 0x8, size 0x2
    unsigned short fGIFStall;  // offset 0xA, size 0x2
    unsigned short fVIFStall;  // offset 0xC, size 0x2
};

// total size: 0xC
struct NNS_TEXBUFF_CHANGETEXBUFFSTAT_PS2 {
    enum NNE_BOOL bReserved; // offset 0x0, size 0x4
    void* localbuf;          // offset 0x4, size 0x4
    unsigned int localsize;  // offset 0x8, size 0x4
};

extern struct NNS_TEXBUFF_PS2 nngTexBuff;
extern struct NNS_PUSHBUFFER nngTexPath3PBWork;
extern struct NNS_TEXPATH3DMA_PS2 nngTexPath3Dma;
extern unsigned int nngTexturePath3TransferMode;

signed int nnTextureBufferPath3DmacFuncGIF();
signed int nnTextureBufferPath3IntcFuncVIF1();
void nnPutTextureBufferCorePS2(struct _NNS_TEXINFO* pTexInfo, void* localbuf, void* dmatagbuf);
signed int nnPutTextureBufferPS2(struct _NNS_TEXINFO** ppTexInfo, signed int nTex);
void* nnInitTexturePushBufferPS2(void* pushbuf, unsigned int pushsize);
void* nnInitTextureBufferPS2(void* pushbuf,
                             unsigned int pushsize,
                             void* localbuf,
                             unsigned int localsize,
                             signed int blocknum);
void nnExitTextureBufferPS2();
void nnExecTextureBufferPS2();
signed int
nnChangeTextureBufferPS2(void* localbuf, unsigned int localsize, enum NNE_BOOL immediate);
void nnRequestTextureBufferSyncPS2();

#endif // NNTEXBUFF_H
