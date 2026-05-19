#ifndef PUTGRAVITYOBJ3_HPP
#define PUTGRAVITYOBJ3_HPP

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
    clsPutGravityObj3_Obj();
    virtual ~clsPutGravityObj3_Obj();

    virtual void init();
    virtual hkShape* getShape();
    virtual f32 getMass();
    virtual f32 getRestitution();
    virtual f32 getFriction();
    virtual void createSe();

    void draw(clsModelType_OB_TX* pcModels,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
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
    clsPutGravityObj3_Task(u32 param);
    virtual ~clsPutGravityObj3_Task();

    virtual void init();
    virtual void reset();
    virtual void execute();
    virtual void draw();
};

#endif // PUTGRAVITYOBJ3_HPP
