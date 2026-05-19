#ifndef NNCALCNODEHIDEMOTION_H
#define NNCALCNODEHIDEMOTION_H

struct NNS_MOTION;
struct NNS_SUBMOTION;

signed int nnCalcMotionNodeHide(struct NNS_SUBMOTION* submot, float frame);
void nnCalcNodeHideMotion(unsigned int* nodestatlist, struct NNS_MOTION* mot, float frame);

#endif // NNCALCNODEHIDEMOTION_H
