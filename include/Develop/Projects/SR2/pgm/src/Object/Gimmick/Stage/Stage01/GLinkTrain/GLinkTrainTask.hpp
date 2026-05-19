#ifndef GLINKTRAINTASK_HPP
#define GLINKTRAINTASK_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/GLinkTrain/GLinkTrainManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "types.h"

// total size: 0xA8
class clsGLinkTrain_Task : public clsSingleModelGimmick_Task<clsGLinkTrain_Task,
                                                             clsGLinkTrainManager_Object,
                                                             clsModelType_OB_TX> {
public:
    clsGLinkTrain_Task(u32 u32ObjectAreaNum) : clsSingleModelGimmick_Task(0, u32ObjectAreaNum) {}
    virtual ~clsGLinkTrain_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // GLINKTRAINTASK_HPP
