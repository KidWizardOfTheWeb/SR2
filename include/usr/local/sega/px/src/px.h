#include "usr/local/sce/ee/lib/eestruct.h"

#ifndef PX_H
#define PX_H

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

struct PXS_CONTEXT {
    struct sceGsTexflush texflush;     // offset 0x0, size 0x8
    unsigned long texflushaddr;        // offset 0x8, size 0x4
    struct sceGsFrame frame;           // offset 0x10, size 0x8
    unsigned long frameaddr;           // offset 0x18, size 0x4
    struct sceGsZbuf zbuf;             // offset 0x20, size 0x8
    unsigned long zbufaddr;            // offset 0x28, size 0x4
    struct sceGsXyoffset xyoffset;     // offset 0x30, size 0x8
    unsigned long xyoffsetaddr;        // offset 0x38, size 0x4
    struct sceGsScissor scissor;       // offset 0x40, size 0x8
    unsigned long scissoraddr;         // offset 0x48, size 0x4
    struct sceGsAlpha alpha;           // offset 0x50, size 0x8
    unsigned long alphaaddr;           // offset 0x58, size 0x4
    struct sceGsClamp clamp;           // offset 0x60, size 0x8
    unsigned long clampaddr;           // offset 0x68, size 0x4
    struct sceGsDimx dimx;             // offset 0x70, size 0x8
    unsigned long dimxaddr;            // offset 0x78, size 0x4
    struct sceGsDthe dthe;             // offset 0x80, size 0x8
    unsigned long dtheaddr;            // offset 0x88, size 0x4
    struct sceGsFba fba;               // offset 0x90, size 0x8
    unsigned long fbaaddr;             // offset 0x98, size 0x4
    struct sceGsFogcol fogcol;         // offset 0xA0, size 0x8
    unsigned long fogcoladdr;          // offset 0xA8, size 0x4
    struct sceGsMiptbp1 miptbp1;       // offset 0xB0, size 0x8
    unsigned long miptbp1addr;         // offset 0xB8, size 0x4
    struct sceGsMiptbp2 miptbp2;       // offset 0xC0, size 0x8
    unsigned long miptbp2addr;         // offset 0xC8, size 0x4
    struct sceGsPrmodecont prmodecont; // offset 0xD0, size 0x8
    unsigned long prmodecontaddr;      // offset 0xD8, size 0x4
    struct sceGsPrmode prmode;         // offset 0xE0, size 0x8
    unsigned long prmodeaddr;          // offset 0xE8, size 0x4
    struct sceGsTest test;             // offset 0xF0, size 0x8
    unsigned long testaddr;            // offset 0xF8, size 0x4
    struct sceGsTex1 tex1;             // offset 0x100, size 0x8
    unsigned long tex1addr;            // offset 0x108, size 0x4
    struct sceGsTex0 tex0;             // offset 0x110, size 0x8
    unsigned long tex0addr;            // offset 0x118, size 0x4
    struct sceGsTex2 tex2;             // offset 0x120, size 0x8
    unsigned long tex2addr;            // offset 0x128, size 0x4
    struct sceGsTexa texa;             // offset 0x130, size 0x8
    unsigned long texaaddr;            // offset 0x138, size 0x4
    struct sceGsTexclut texclut;       // offset 0x140, size 0x8
    unsigned long texclutaddr;         // offset 0x148, size 0x4
    struct sceGsRgbaq rgbaq;           // offset 0x150, size 0x8
    unsigned long rgbaqaddr;           // offset 0x158, size 0x4
};

enum PXE_ERR {
    PXE_ERR_OK = 0,
    PXE_ERR_INVALIDARG = -1,
    PXE_ERR_BUSY = -2,
    PXE_ERR_NOTREADY = -10,
    PXE_ERR_NOTVB = -50,
    PXE_ERR_INVALIDVBVERSION = -51,
    PXE_ERR_TOOMANYVERTICES = -52,
    PXE_ERR_NODATA = -53,
    PXE_ERR_NOTENOUGHBUFFER = -54,
    PXE_ERR_INCORRECTDBINDEX = -55,
};

struct PXS_INITPARAM {
    unsigned int tagSize;       // offset 0x0, size 0x4
    unsigned int dataSize;      // offset 0x4, size 0x4
    void* pushBuffer;           // offset 0x8, size 0x4
    unsigned int bufSize;       // offset 0xC, size 0x4
    unsigned int chainSize;     // offset 0x10, size 0x4
    void* chainBuffer;          // offset 0x14, size 0x4
    unsigned int pushBufferMax; // offset 0x18, size 0x4
    unsigned int flag;          // offset 0x1C, size 0x4
};

struct PXS_PRMODESET {
    unsigned int giftag[4];   // offset 0x0, size 0x10
    unsigned int prmode0;     // offset 0x10, size 0x4
    unsigned int prmode1;     // offset 0x14, size 0x4
    unsigned long prmodeaddr; // offset 0x18, size 0x4
};

extern struct tagPXS_PUSHBUFFER* pxgPrimaryPB; // size: 0x4, address: 0x6D1F04
extern struct tagPXS_PUSHBUFFER* pxgCurrentPB; // size: 0x4, address: 0x6D1F08
extern struct tagPXS_PUSHBUFFER pxgPBWork;
extern struct PXS_INITPARAM pxgInitParam;

extern char* __license_string_ptr__; // size: 0x4, address: 0x6D1F2C
extern char* pxgVersionPtr;

extern struct PXS_CONTEXT pxg_context[2]; // size: 0x2C0, address: 0x6E66C0

enum PXE_ERR PXInit(struct PXS_INITPARAM* iprm);
signed int PXGsInterruptHandler(signed int ca);
void PXInitInterrupt(unsigned int flag);
void PXExit();
enum PXE_ERR PXRender(unsigned int flag);
void* PXBegin(unsigned int flag);
void PXEnd(void* p);
void PXPutReg(unsigned int addr, unsigned long data);
void PXPutCustomShader(void* addr);
void PXStartShader();
void PXPutCall(void* addr);
void PXPutRef(void* addr, unsigned int qwc, unsigned int flag);
void* PXBeginPrim(void* addr, unsigned int vertices, unsigned int stride, unsigned int prim);
void* PXEndPrim(void* addr);
void PXPutVifMask();

#endif
