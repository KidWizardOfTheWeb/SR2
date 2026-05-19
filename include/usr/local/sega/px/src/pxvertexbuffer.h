#ifndef PXVERTEXBUFFER_H
#define PXVERTEXBUFFER_H

struct PXS_VERTEXBUFFER {
    char magic[4];             // offset 0x0, size 0x4
    unsigned int version;      // offset 0x4, size 0x4
    unsigned int size;         // offset 0x8, size 0x4
    unsigned int flag;         // offset 0xC, size 0x4
    __int128* addr;            // offset 0x10, size 0x4
    unsigned int qwc;          // offset 0x14, size 0x4
    __int128* bufPtr;          // offset 0x18, size 0x4
    unsigned int lockFlag;     // offset 0x1C, size 0x4
    unsigned int vuOffset;     // offset 0x20, size 0x4
    unsigned int reserved2[3]; // offset 0x24, size 0xC
    unsigned int reserved3[4]; // offset 0x30, size 0x10
};

struct PXS_VERTEXBUFFER* PXSetupVB(void* addr, unsigned int size, unsigned int flag);
void* PXLockVB(struct PXS_VERTEXBUFFER* vb, unsigned int flag);
void PXUnlockVB(struct PXS_VERTEXBUFFER* vb, void* p);
void* PXBeginPrimVB(struct PXS_VERTEXBUFFER* vb,
                    void* addr,
                    unsigned int vertices,
                    unsigned int stride,
                    unsigned int prim);
void* PXEndPrimVB(int /* unused */, void* addr);

#endif
