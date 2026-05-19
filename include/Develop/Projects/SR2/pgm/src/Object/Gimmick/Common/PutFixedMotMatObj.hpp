#ifndef PUTFIXEDMOTMATOBJ_HPP
#define PUTFIXEDMOTMATOBJ_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGimmick.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "types.h"

// total size: 0x60
class clsPutFixedMotMatObj_Obj : public clsGimmickObj {
public:
    clsPutFixedMotMatObj_Obj();
    virtual ~clsPutFixedMotMatObj_Obj();

    nspPackId::enm getPackId() const { return nspPackId::PUT_FIXEDMOTMATOBJ_2092; }
    virtual void draw(clsModelType_OB_TX_MO_MA* pModel,
                      f32* pfMatA,
                      u32* pu32NodeCount,
                      f32* pfMatB,
                      f32 f32Param,
                      u32 u32Param);

    static f32 m_tof32CLIP_DISTx2;

    enum enmPutFixedMotMatObjMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enmPutFixedMotMatObjMode m_ePutFixedMotMatObjMode; // offset 0x50, size 0x4
};

// total size: 0x98
class clsPutFixedMotMatObj_Task : public clsMultiModelGimmick_Task<clsPutFixedMotMatObj_Task,
                                                                   clsPutFixedMotMatObj_Obj,
                                                                   clsMultiObjTxMoMaModels> {
public:
    clsPutFixedMotMatObj_Task(u32 u32ObjectAreaNum)
        : clsMultiModelGimmick_Task<clsPutFixedMotMatObj_Task,
                                    clsPutFixedMotMatObj_Obj,
                                    clsMultiObjTxMoMaModels>(u32ObjectAreaNum, 0x18A92)
    {
    }
    virtual ~clsPutFixedMotMatObj_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // PUTFIXEDMOTMATOBJ_HPP
