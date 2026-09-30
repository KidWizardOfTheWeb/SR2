#ifndef GLINKTRAINTASK_HPP
#define GLINKTRAINTASK_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/GLinkTrain/GLinkTrainManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/GLinkTrain/GLinkTrainObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/DebugDetail.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/Debug.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "types.h"

// total size: 0xA8
class clsGLinkTrain_Task : public clsSingleModelGimmick_Task<clsGLinkTrain_Task,
                                                             clsGLinkTrainManager_Object,
                                                             clsModelType_OB_TX> {
public:
    clsGLinkTrain_Task(u32 u32ObjectAreaNum)
        : clsSingleModelGimmick_Task<clsGLinkTrain_Task,
                                     clsGLinkTrainManager_Object,
                                     clsModelType_OB_TX>(u32ObjectAreaNum, 101000)
    {
        hkVector4 cVec(clsGLinkTrain_Object::tosCollisionHalfSizeVec.x,
                       clsGLinkTrain_Object::tosCollisionHalfSizeVec.y,
                       clsGLinkTrain_Object::tosCollisionHalfSizeVec.z,
                       0.0f);
        m_pcRigidShape = new hkBoxShape(cVec, 0.0f);
        clsDebug::GS()->m_cOOMenu.addSubMenu("DEBUG", "G-DIVE TRAIN", nspDebugDetail::GDiveTrain);
    }
    virtual ~clsGLinkTrain_Task();

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

inline clsGLinkTrain_Task::~clsGLinkTrain_Task()
{
}

#endif // GLINKTRAINTASK_HPP
