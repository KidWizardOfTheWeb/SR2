#ifndef NNLIGHTMOTION_H
#define NNLIGHTMOTION_H

#include "usr/local/sega/nn/src/Light/nnlight.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"

void nnCalcMotionLightAngle(struct NNS_SUBMOTION* submot, float frame, signed int* ang);
void nnCalcMotionLightXYZ(struct NNS_SUBMOTION* submot, float frame, struct NNS_VECTOR* xyz);
void nnCalcMotionLightRGB(struct NNS_SUBMOTION* submot, float frame, struct NNS_RGB* col);
void nnCalcLightMotionCore(struct NNS_LIGHTPTR* dstptr,
                           struct NNS_LIGHTPTR* litptr,
                           struct NNS_MOTION* mot,
                           float frame);
void nnCalcLightMotion(struct NNS_LIGHTPTR* dstptr,
                       struct NNS_LIGHTPTR* litptr,
                       struct NNS_MOTION* mot,
                       float frame);

#endif // NNLIGHTMOTION_H
