#include "usr/local/sega/nn/src/Matrix/nnmatrixstack.h"

void nnSetUpMatrixStack(struct NNS_MATRIXSTACK* mstk, void* buf, unsigned int size)
{
}

float (*nnGetCurrentMatrix(struct NNS_MATRIXSTACK* mstk))[4][4]
{
}

void nnSetCurrentMatrix(struct NNS_MATRIXSTACK* mstk, float (*mtx)[4][4])
{
}

void nnPushMatrix(struct NNS_MATRIXSTACK* mstk, float (*mtx)[4][4])
{
}

void nnPopMatrix(struct NNS_MATRIXSTACK* mstk)
{
}
