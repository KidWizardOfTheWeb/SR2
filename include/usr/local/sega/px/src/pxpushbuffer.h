#ifndef PXPUSHBUFFER_H
#define PXPUSHBUFFER_H

#include "usr/local/sega/px/src/pxtex2.h"

// total size: 0x40
struct PXS_PUSHBUFFER1 {
    __int128* tagTop;          // offset 0x0, size 0x4
    __int128* tagPtr;          // offset 0x4, size 0x4
    __int128* bufTop;          // offset 0x8, size 0x4
    __int128* bufPtr;          // offset 0xC, size 0x4
    __int128* beginPtr;        // offset 0x10, size 0x4
    unsigned int bufSize;      // offset 0x14, size 0x4
    unsigned int maxTags;      // offset 0x18, size 0x4
    unsigned int numTags;      // offset 0x1C, size 0x4
    unsigned int numBytes;     // offset 0x20, size 0x4
    unsigned int pushVuOffset; // offset 0x24, size 0x4
    unsigned int nextVifCmd;   // offset 0x28, size 0x4
    unsigned int ready;        // offset 0x2C, size 0x4
    unsigned int reserved2[4]; // offset 0x30, size 0x10
};

// total size: 0xA0
struct tagPXS_PUSHBUFFER {
    unsigned int flag;              // offset 0x0, size 0x4
    unsigned short dbIndex;         // offset 0x4, size 0x2
    unsigned short renderIndex;     // offset 0x6, size 0x2
    unsigned int peakTags;          // offset 0x8, size 0x4
    unsigned int peakBytes;         // offset 0xC, size 0x4
    unsigned int beginFlag;         // offset 0x10, size 0x4
    void* recentAddr;               // offset 0x14, size 0x4
    struct tagPXS_PUSHBUFFER* prev; // offset 0x18, size 0x4
    struct tagPXS_PUSHBUFFER* next; // offset 0x1C, size 0x4
    struct PXS_PUSHBUFFER1 db[2];   // offset 0x20, size 0x80
};

// total size: 0x10
struct PXS_SPB_DATABUFINFO {
    void* dataBuf[2];         // offset 0x0, size 0x8
    unsigned int dataBufSize; // offset 0x8, size 0x4
    unsigned int reserved;    // offset 0xC, size 0x4
};

extern struct tagPXS_PUSHBUFFER* pxgLastDrawPB;

struct tagPXS_PUSHBUFFER* PXSetupPB(struct tagPXS_PUSHBUFFER* pb,
                                    unsigned int nTagBytes,
                                    unsigned int nDataBytes,
                                    void* addr,
                                    unsigned int bufsize,
                                    unsigned int flag);
void PXAddTagEnd(struct PXS_PUSHBUFFER1* db, unsigned int irq);
void PXFlipPB(struct tagPXS_PUSHBUFFER* pb);
enum PXE_ERR PXRenderPB(struct tagPXS_PUSHBUFFER* pb, unsigned int flag);
void* PXBeginPB(struct tagPXS_PUSHBUFFER* pb, unsigned int flag);
void PXAddTagCall(struct PXS_PUSHBUFFER1* db, void* addr);
void PXPutCallPB(struct tagPXS_PUSHBUFFER* pb, void* addr);
void PXPutRefPB(struct tagPXS_PUSHBUFFER* pb, void* addr, unsigned int qwc, unsigned int flag);
void PXAdjustSharedPB(struct tagPXS_PUSHBUFFER* pb);
void PXEndPB(struct tagPXS_PUSHBUFFER* pb, void* pEnd);
void PXPutShaderPB(struct tagPXS_PUSHBUFFER* pb, void* addr);
void PXPutShaderConstPB(struct tagPXS_PUSHBUFFER* pb,
                        unsigned int vumem,
                        void* addr,
                        unsigned int qwc);
void PXReferShaderConstPB(struct tagPXS_PUSHBUFFER* pb,
                          unsigned int vumem,
                          void* addr,
                          unsigned int qwc);
void* PXGetLastShaderConstAddrPB(struct tagPXS_PUSHBUFFER* pb);
void PXPutRegPB(struct tagPXS_PUSHBUFFER* pb, unsigned int addr, unsigned long data);
void PXStartShaderPB(struct tagPXS_PUSHBUFFER* pb);
void* PXBeginPrimPB(struct tagPXS_PUSHBUFFER* pb,
                    void* addr,
                    unsigned int vertices,
                    unsigned int stride,
                    unsigned int prim);
void* PXEndPrimPB(void* addr);

#endif // PXPUSHBUFFER_H
