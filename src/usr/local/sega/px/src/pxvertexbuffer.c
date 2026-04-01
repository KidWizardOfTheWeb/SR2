#include "usr/local/sega/px/src/pxvertexbuffer.h"
#include "usr/local/sce/ee/gcc/ee/lib/libc/memset.h"
#include "usr/local/sce/ee/lib/eestruct.h"

struct PXS_VERTEXBUFFER * PXSetupVB(void *addr, unsigned int size, unsigned int flag) {
	struct PXS_VERTEXBUFFER * vb;
    memset(addr, 0, sizeof(struct PXS_VERTEXBUFFER));
    vb = (struct PXS_VERTEXBUFFER *) addr;
    vb->magic[0] = 'P';
    vb->magic[1] = 'X';
    vb->magic[2] = 'V';
    vb->magic[3] = 'B';
    vb->version = 0x10;
    vb->addr = (__int128 *)( (char *)addr + sizeof(struct PXS_VERTEXBUFFER));
    vb->size = size;
    vb->flag = flag;
    vb->qwc = 0;
    vb->bufPtr = vb->addr;
    vb->lockFlag = 0;
    vb->vuOffset = 1;
    return vb;
}

void * PXLockVB(struct PXS_VERTEXBUFFER *vb, unsigned int flag) {
    vb->lockFlag = flag;
    return vb->bufPtr;
}

void PXUnlockVB(struct PXS_VERTEXBUFFER *vb, void *p) {
    if (((int) p & 0xF) != 0) {
        if (((int) p & 0xF) != 0) {
            do {
                *(int*)p = 0;
                ((int*)p)++;
            } while ((int) p & 0xF);
        }
    }

    vb->qwc = (((int) p - (int)vb->addr) / 16);
    vb->bufPtr = (__int128 *) p;
}

void * PXBeginPrimVB(struct PXS_VERTEXBUFFER * vb, void * addr, unsigned int vertices, unsigned int stride, unsigned int prim) {
    int vuaddr;  // not shown in the dwarf
    unsigned int * p;

    if (vb->vuOffset) {
        vuaddr = 0x200;
    } else {
        vuaddr = 0;
    }
    
    p = (unsigned int *) addr;
    p[0] = 0x01000404;
    p[1] = 0;
    p[2] = 0;
    p[3] = SCE_VIF1_SET_UNPACK(vuaddr, (vertices * stride) + 2, 12, 0);
    *(unsigned __int128 *)&p[4] = 0;
    p[4] = vertices;
    p[7] = vertices * 0xD0;
    *(unsigned long *)&p[8] = SCE_GIF_SET_TAG(vertices, 1, 1, prim, 0, 3);
    *(unsigned long *)&p[10] = 0x412;
    vb->vuOffset ^= 1;
    return ((unsigned int *) p) + 12;
}

void * PXEndPrimVB(int /* unused */, void * addr) {
	unsigned int *p = (unsigned int *) addr;
    p[0] = 0x17000000;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    return &p[4];
}
