#ifndef PUTFIXEDMOTOBJ_HPP
#define PUTFIXEDMOTOBJ_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGimmick.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "types.h"

// total size: 0x60
class clsPutFixedMotObj_Obj : public clsGimmickObj {
public:
    clsPutFixedMotObj_Obj();
    virtual ~clsPutFixedMotObj_Obj();

    nspPackId::enm getPackId() const { return nspPackId::PUT_FIXEDMOTOBJ_2091; }
    virtual void draw(clsModelType_OB_TX_MO* pModel,
                      f32* pfMatA,
                      u32* pu32NodeCount,
                      f32* pfMatB,
                      f32 f32Param,
                      u32 u32Param);

    static f32 m_tof32CLIP_DISTx2;

    enum enmPutFixedMotObjMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enmPutFixedMotObjMode m_ePutFixedMotObjMode; // offset 0x50, size 0x4
};

// total size: 0x98
class clsPutFixedMotObj_Task : public clsMultiModelGimmick_Task<clsPutFixedMotObj_Task,
                                                                clsPutFixedMotObj_Obj,
                                                                clsMultiObjTxMoModels> {
public:
    clsPutFixedMotObj_Task(u32 u32ObjectAreaNum)
        : clsMultiModelGimmick_Task<clsPutFixedMotObj_Task,
                                    clsPutFixedMotObj_Obj,
                                    clsMultiObjTxMoModels>(u32ObjectAreaNum, 0x18A92)
    {
    }
    virtual ~clsPutFixedMotObj_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // PUTFIXEDMOTOBJ_HPP
