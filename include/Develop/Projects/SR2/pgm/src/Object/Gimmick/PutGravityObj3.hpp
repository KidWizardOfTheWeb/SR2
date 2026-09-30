#ifndef PUTGRAVITYOBJ3_HPP
#define PUTGRAVITYOBJ3_HPP

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PutGravityObj2.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGimmick.hpp"

class clsPutGravityObj3_Task;
class hkShape;

class clsPutGravityObj3_Obj : public clsPutGravityObj2_Obj {
public:
    clsPutGravityObj3_Obj() {}
    virtual ~clsPutGravityObj3_Obj() { destroyData(); }

    virtual void init();
    virtual hkShape* getShape();
    virtual f32 getMass();
    virtual f32 getRestitution();
    virtual f32 getFriction();
    virtual void createSe();

    void draw(clsModelType_OB_TX* pcModels,
              NNS_MATRIX* psMtxPal,
              u32* psNodeStat,
              const NNS_MATRIX* opaNnViewMtx,
              NNS_MATRIX* psMtxWork,
              u32 u32ViewNo,
              clsPutGravityObj3_Task* pcTask);

    virtual nspPackId::enm getPackId() const { return nspPackId::PUT_GRAVITYOBJ3_2104; }
};

// total size: 0xA8
class clsPutGravityObj3_Task : public clsMultiShape,
                               public clsMultiModelGimmick_Task<clsPutGravityObj3_Task,
                                                                clsPutGravityObj3_Obj,
                                                                clsMultiObTxModels> {
public:
    clsPutGravityObj3_Task(u32 u32ObjectAreaNum)
        : clsMultiShape(u32ObjectAreaNum),
          clsMultiModelGimmick_Task<clsPutGravityObj3_Task,
                                    clsPutGravityObj3_Obj,
                                    clsMultiObTxModels>(u32ObjectAreaNum, 101000)
    {
    }
    virtual ~clsPutGravityObj3_Task();

    virtual void init();
    virtual void reset();
    virtual void execute();
    virtual void draw();
};

inline clsPutGravityObj3_Task::~clsPutGravityObj3_Task()
{
}

#endif // PUTGRAVITYOBJ3_HPP
