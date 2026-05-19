#ifndef NNMORPHMOTION_H
#define NNMORPHMOTION_H

#include "usr/local/sega/nn/src/Morph/nnmorph.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "usr/local/sega/nn/src/System/nnsystem.h"

enum NNE_BOOL nnCalcMorphMotionWeight(struct NNS_SUBMOTION* submot, float frame, float* weight);
void nnCalcMorphMotion(float* mwpal,
                       struct NNS_MORPHTARGETLIST* mtgt,
                       struct NNS_MOTION* mot,
                       float frame);

#endif // NNMORPHMOTION_H
