#ifndef NNCAMERAMOTION_H
#define NNCAMERAMOTION_H

#include "usr/local/sega/nn/src/Camera/nncamera.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"

void nnCalcMotionCameraAngle(struct NNS_SUBMOTION* submot, float frame, signed int* ang);
void nnCalcMotionCameraXYZ(struct NNS_SUBMOTION* submot, float frame, struct NNS_VECTOR* xyz);
void nnCalcCameraMotionCore(struct NNS_CAMERAPTR* dstptr,
                            struct NNS_CAMERAPTR* camptr,
                            struct NNS_MOTION* mot,
                            float frame);
void nnCalcCameraMotion(struct NNS_CAMERAPTR* dstptr,
                        struct NNS_CAMERAPTR* camptr,
                        struct NNS_MOTION* mot,
                        float frame);

#endif // NNCAMERAMOTION_H
