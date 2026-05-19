#ifndef ROBOCURV_HPP
#define ROBOCURV_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Effect/BaseEffect.hpp"

// total size: 0xE0
class clsRoboCurvEffect_Task : public clsBaseEffect_Task {
public:
    clsRoboCurvEffect_Task(clsModelType_OB_TX_MO_MA* pcModelI,
                           const NNS_VECTORFAST* opsPosVecFast,
                           const NNS_QUATERNION* opsQuat);
    virtual ~clsRoboCurvEffect_Task();

    virtual void execute();
    virtual void draw();

    NNS_VECTORFAST* m_opsFollowPosVecFast; // offset 0xD0, size 0x4
    NNS_QUATERNION* m_opsFollowQuat;       // offset 0xD4, size 0x4
};

#endif // ROBOCURV_HPP
