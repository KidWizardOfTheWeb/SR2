#ifndef NNCLIPSETUP_H
#define NNCLIPSETUP_H

#include "usr/local/sega/nn/src/System/nnclip.h"

struct NNS_VECTOR2D;

extern struct NNS_CLIP nngClip2d;

void nnSetClipPlane();
void nnSetClipScreenCoordinates(struct NNS_VECTOR2D* pos);
void nnSetClipZ(float znear, float zfar);

#endif // NNCLIPSETUP_H
