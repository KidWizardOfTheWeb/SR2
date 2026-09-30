#ifndef PUTARROWOBJ_HPP
#define PUTARROWOBJ_HPP

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsPutArrow_Obj : public clsPhantomGimmickObject {
public:
    clsPutArrow_Obj();
    virtual ~clsPutArrow_Obj() { destroyData(); }

    void draw(clsModelType_OB_TX_MO* pcModel,
              NNS_MATRIX* psMtxPal,
              u32* psNodeStat,
              const NNS_MATRIX* opaNnViewMtx,
              const NNS_MATRIX* opaBillBoardMtx,
              NNS_MATRIX* psMtxWork,
              u32 u32ViewNo);

    virtual nspPackId::enm getPackId() const { return nspPackId::PUT_ARROW_2105; }
};

class clsPutArrow_Task
    : public clsSingleModelGimmick_Task<clsPutArrow_Task, clsPutArrow_Obj, clsModelType_OB_TX_MO> {
public:
    clsPutArrow_Task(u32 u32ObjectAreaNum)
        : clsSingleModelGimmick_Task<clsPutArrow_Task, clsPutArrow_Obj, clsModelType_OB_TX_MO>(
              u32ObjectAreaNum, 101010)
    {
    }
    virtual ~clsPutArrow_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // PUTARROWOBJ_HPP
