#ifndef PX_H
#define PX_H

#include "usr/local/sce/ee/lib/eestruct.h"
#include "usr/local/sega/px/src/pxgeom.h"
#include "usr/local/sega/px/src/pxpushbuffer.h"
#include "usr/local/sega/px/src/pxtex2.h"

// total size: 0x20
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

// total size: 0x10
struct PXS_QWDATA {
    union {
        __int128 ul128;        // offset 0x0, size 0x10
        unsigned long ul64[2]; // offset 0x0, size 0x8
        unsigned int ui32[4];  // offset 0x0, size 0x10
    };
};

// total size: 0x10
struct PXS_DMATAG {
    unsigned short qwc;    // offset 0x0, size 0x2
    unsigned short id;     // offset 0x2, size 0x2
    void* addr;            // offset 0x4, size 0x4
    unsigned int vifnop;   // offset 0x8, size 0x4
    unsigned int directhl; // offset 0xC, size 0x4
};

// total size: 0x18
struct PXS_PUSHBUFFERINFO {
    unsigned int numTags;   // offset 0x0, size 0x4
    unsigned int numBytes;  // offset 0x4, size 0x4
    unsigned int peakTags;  // offset 0x8, size 0x4
    unsigned int peakBytes; // offset 0xC, size 0x4
    unsigned int maxTags;   // offset 0x10, size 0x4
    unsigned int maxBytes;  // offset 0x14, size 0x4
};

// total size: 0x30
struct PXS_SUBSHADERPARAM {
    float uOfs;            // offset 0x0, size 0x4
    float vOfs;            // offset 0x4, size 0x4
    float rsvd0;           // offset 0x8, size 0x4
    float fa;              // offset 0xC, size 0x4
    float uScale;          // offset 0x10, size 0x4
    float vScale;          // offset 0x14, size 0x4
    float rsvd1;           // offset 0x18, size 0x4
    float fb;              // offset 0x1C, size 0x4
    unsigned int scisMode; // offset 0x20, size 0x4
    unsigned int triFan;   // offset 0x24, size 0x4
    unsigned int rsvd2;    // offset 0x28, size 0x4
    float fognear;         // offset 0x2C, size 0x4
};

// total size: 0x1C
struct PXS_PRMODESET {
    unsigned int giftag[4];   // offset 0x0, size 0x10
    unsigned int prmode0;     // offset 0x10, size 0x4
    unsigned int prmode1;     // offset 0x14, size 0x4
    unsigned long prmodeaddr; // offset 0x18, size 0x4
};

enum PXE_SVF {
    PXE_SVF_START = 0,
    PXE_SVF_POSITION = 1,
    PXE_SVF_NORMAL = 2,
    PXE_SVF_UV = 3,
    PXE_SVF_COLOR = 4,
    PXE_SVF_NORMAL16 = 5,
    PXE_SVF_UV16 = 6,
    PXE_SVF_UVM = 7,
    PXE_SVF_UV16M = 8,
};

extern char* __license_string_ptr__;
extern struct PXS_MATERIAL pxgDefaultMaterial;
extern signed int (*pxgDmaStartCallback)(void*);
extern float pxgGsGuardBand;
extern signed int pxgGsHandlerID;
extern struct PXS_INITPARAM pxgInitParam;
extern unsigned int pxgLastDmaAddr;
extern struct tagPXS_PUSHBUFFER pxgPBWork;
extern struct tagPXS_PUSHBUFFER* pxgCurrentPB;
extern struct tagPXS_PUSHBUFFER* pxgPrimaryPB;
extern void (*pxgRenderCallback)(void*);
extern void* pxgRenderCallbackArg;
extern unsigned int pxgRenderDmaBusy;
extern unsigned int pxgRenderFlag;
extern struct PXS_SCREENPARAM pxgScreenParam;
extern struct PXS_SUBSHADERPARAM pxgSubShaderParam;
extern char* pxgVersionPtr;
extern struct PXS_MATRIX pxgViewMatrix;
extern unsigned int pxgVuCode_Scissor;

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

#endif // PX_H
