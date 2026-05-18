#ifndef PXCONTEXT_H
#define PXCONTEXT_H

extern unsigned long pxg_frame_addr[2];   // size: 0x8, address: 0x5FAF90
extern unsigned long pxg_scissor_addr[2]; // size: 0x8, address: 0x5FAFA0

struct PXS_GSREG_AD {
    unsigned long data; // offset 0x0, size 0x4
    unsigned long addr; // offset 0x8, size 0x4
};

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

#endif /* PXCONTEXT_H */
