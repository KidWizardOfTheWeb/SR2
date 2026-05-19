#ifndef PXCONTEXT_H
#define PXCONTEXT_H

#include "usr/local/sce/ee/lib/eestruct.h"
#include "usr/local/sega/nn/src/Texture/nntexture.h"

extern unsigned long pxg_frame_addr[2];   // size: 0x8, address: 0x5FAF90
extern unsigned long pxg_scissor_addr[2]; // size: 0x8, address: 0x5FAFA0

// total size: 0x160
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

extern struct PXS_CONTEXT pxg_context[2]; // size: 0x2C0, address: 0x6E66C0

// total size: 0x10
struct PXS_GSREG_AD {
    unsigned long data; // offset 0x0, size 0x4
    unsigned long addr; // offset 0x8, size 0x4
};

// total size: 0x20
struct PXS_CONTEXTBUFFER {
    unsigned int giftag[4];     // offset 0x0, size 0x10
    struct PXS_GSREG_AD reg[1]; // offset 0x10, size 0x10
};

enum PXE_CTX {
    PXE_CTX1 = 0,
    PXE_CTX2 = 1,
};

void PXInitContext(enum PXE_CTX context);
void PXPutContext(enum PXE_CTX context);
struct PXS_CONTEXTBUFFER* PXSetupCB(void* buf, unsigned int bufsize, signed int num);
void PXReferCB(struct PXS_CONTEXTBUFFER* cb);
void PXPutCB(struct PXS_CONTEXTBUFFER* cb);
void PXSetCB(struct PXS_CONTEXTBUFFER* cb, signed int num, unsigned long addr, unsigned long data);

#endif // PXCONTEXT_H
