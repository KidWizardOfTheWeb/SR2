#include "usr/local/sega/nn/src/System/nnclip.h"

unsigned int
nnCalcClipBox(struct NNS_VECTOR* center, float sx, float sy, float sz, float (*mtx)[4][4])
{
}

unsigned int nnCalcClipCore(struct NNS_VECTOR* center, float radius, float (*mtx)[4][4])
{
}

unsigned int nnCalcClip(struct NNS_VECTOR* center, float radius, float (*mtx)[4][4])
{
}

void nnCalcClipSetNodeStatus(unsigned int* pNodeStatList,
                             struct NNS_NODE* pNodeList,
                             signed int nodeIdx,
                             float (*pNodeMtx)[4][4],
                             float rootscale,
                             unsigned int flag)
{
}

void nnSetUpNodeStatusListFlag(signed int nodeidx, unsigned int flag)
{
}

unsigned int nnCheckObjectClip(struct NNS_OBJECT* obj, float (*basemtx)[4][4])
{
}

float nnEstimateMatrixScaling(float (*mtx)[4][4])
{
}
