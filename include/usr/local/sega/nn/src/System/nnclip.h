#ifndef NNCLIP_H
#define NNCLIP_H

#include "usr/local/sega/nn/src/Object/nnobject.h"

// total size: 0x18
struct NNS_CLIP {
    float f_clip; // offset 0x0, size 0x4
    float n_clip; // offset 0x4, size 0x4
    float x1;     // offset 0x8, size 0x4
    float x0;     // offset 0xC, size 0x4
    float y1;     // offset 0x10, size 0x4
    float y0;     // offset 0x14, size 0x4
};

// total size: 0x8
struct NNS_CLIP_PLANE_XZ {
    union {
        float nx;  // offset 0x0, size 0x4
        float mul; // offset 0x0, size 0x4
    };
    union {
        float nz;  // offset 0x4, size 0x4
        float ofs; // offset 0x4, size 0x4
    };
};

// total size: 0x8
struct NNS_CLIP_PLANE_YZ {
    union {
        float ny;  // offset 0x0, size 0x4
        float mul; // offset 0x0, size 0x4
    };
    union {
        float nz;  // offset 0x4, size 0x4
        float ofs; // offset 0x4, size 0x4
    };
};

// total size: 0x20
struct NNS_CLIP_PLANE {
    struct NNS_CLIP_PLANE_YZ Top;    // offset 0x0, size 0x8
    struct NNS_CLIP_PLANE_YZ Bottom; // offset 0x8, size 0x8
    struct NNS_CLIP_PLANE_XZ Right;  // offset 0x10, size 0x8
    struct NNS_CLIP_PLANE_XZ Left;   // offset 0x18, size 0x8
};

extern struct NNS_CLIP nngClip3d;
extern struct NNS_CLIP_PLANE nngClipPlane;
extern struct NNS_CLIP_PLANE nngClipPlaneGs;

unsigned int nnCalcClipBox(
    struct NNS_VECTOR* center, float sx, float sy, float sz, float (*mtx)[4][4]);
unsigned int nnCalcClipCore(struct NNS_VECTOR* center, float radius, float (*mtx)[4][4]);
unsigned int nnCalcClip(struct NNS_VECTOR* center, float radius, float (*mtx)[4][4]);
void nnCalcClipSetNodeStatus(unsigned int* pNodeStatList,
                             struct NNS_NODE* pNodeList,
                             signed int nodeIdx,
                             float (*pNodeMtx)[4][4],
                             float rootscale,
                             unsigned int flag);
void nnSetUpNodeStatusListFlag(signed int nodeidx, unsigned int flag);
unsigned int nnCheckObjectClip(struct NNS_OBJECT* obj, float (*basemtx)[4][4]);
float nnEstimateMatrixScaling(float (*mtx)[4][4]);

#endif // NNCLIP_H
