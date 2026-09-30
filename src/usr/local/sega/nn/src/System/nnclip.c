#include "usr/local/sega/nn/src/System/nnclip.h"

unsigned int nnCalcClipBox(struct NNS_VECTOR* center, float sx, float sy, float sz, NNS_MATRIX* mtx)
{
}

unsigned int nnCalcClipCore(struct NNS_VECTOR* center, float radius, NNS_MATRIX* mtx)
{
}

unsigned int nnCalcClip(struct NNS_VECTOR* center, float radius, NNS_MATRIX* mtx)
{
}

void nnCalcClipSetNodeStatus(unsigned int* pNodeStatList,
                             struct NNS_NODE* pNodeList,
                             signed int nodeIdx,
                             NNS_MATRIX* pNodeMtx,
                             float rootscale,
                             unsigned int flag)
{
}

void nnSetUpNodeStatusListFlag(signed int nodeidx, unsigned int flag)
{
}

unsigned int nnCheckObjectClip(const struct NNS_OBJECT* obj, const NNS_MATRIX* basemtx)
{
}

float nnEstimateMatrixScaling(NNS_MATRIX* mtx)
{
}
