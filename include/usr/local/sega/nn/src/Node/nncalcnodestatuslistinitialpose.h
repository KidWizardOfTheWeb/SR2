#ifndef NNCALCNODESTATUSLISTINITIALPOSE_H
#define NNCALCNODESTATUSLISTINITIALPOSE_H

#include "usr/local/sega/nn/src/System/nnsystem.h"

struct NNS_OBJECT;

#ifdef __cplusplus
extern "C" {
#endif
void nnCalcNodeStatusListInitialPose(unsigned int* nodestatlist,
                                     struct NNS_OBJECT* obj,
                                     NNS_MATRIX* basemtx,
                                     unsigned int flag);
#ifdef __cplusplus
}
#endif

#endif // NNCALCNODESTATUSLISTINITIALPOSE_H
