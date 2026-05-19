#ifndef PUTARROWOBJ_HPP
#define PUTARROWOBJ_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsPutArrow_Obj : public clsPhantomGimmickObject {
public:
    clsPutArrow_Obj();
    virtual ~clsPutArrow_Obj() {}

    void draw(clsModelType_OB_TX_MO* pcModel,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              const f32 (*opaBillBoardMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);

    virtual nspPackId::enm getPackId() const { return nspPackId::PUT_ARROW_2105; }
};

class clsPutArrow_Task
    : public clsSingleModelGimmick_Task<clsPutArrow_Task, clsPutArrow_Obj, clsModelType_OB_TX_MO> {
public:
    clsPutArrow_Task(u32 u32ObjectAreaNum) : clsSingleModelGimmick_Task(0, u32ObjectAreaNum) {}
    virtual ~clsPutArrow_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // PUTARROWOBJ_HPP
