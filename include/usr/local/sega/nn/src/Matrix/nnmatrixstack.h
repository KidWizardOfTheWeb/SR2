#ifndef NNMATRIXSTACK_H
#define NNMATRIXSTACK_H

// total size: 0x10
struct NNS_MATRIXSTACK {
    unsigned int nMtx;        // offset 0x0, size 0x4
    unsigned int StackIdx;    // offset 0x4, size 0x4
    float (*pStackTop)[4][4]; // offset 0x8, size 0x4
    float (*pCurrent)[4][4];  // offset 0xC, size 0x4
};

void nnSetUpMatrixStack(struct NNS_MATRIXSTACK* mstk, void* buf, unsigned int size);
float (*nnGetCurrentMatrix(struct NNS_MATRIXSTACK* mstk))[4][4];
void nnSetCurrentMatrix(struct NNS_MATRIXSTACK* mstk, float (*mtx)[4][4]);
void nnPushMatrix(struct NNS_MATRIXSTACK* mstk, float (*mtx)[4][4]);
void nnPopMatrix(struct NNS_MATRIXSTACK* mstk);

#endif // NNMATRIXSTACK_H
