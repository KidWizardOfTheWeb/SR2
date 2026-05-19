#ifndef NNCALCNODESTATUSLISTINITIALPOSE_H
#define NNCALCNODESTATUSLISTINITIALPOSE_H

struct NNS_OBJECT;

void nnCalcNodeStatusListInitialPose(unsigned int* nodestatlist,
                                     struct NNS_OBJECT* obj,
                                     float (*basemtx)[4][4],
                                     unsigned int flag);

#endif // NNCALCNODESTATUSLISTINITIALPOSE_H
