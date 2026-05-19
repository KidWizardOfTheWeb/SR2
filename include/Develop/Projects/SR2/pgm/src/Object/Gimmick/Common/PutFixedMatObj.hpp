#ifndef PUTFIXEDMATOBJ_HPP
#define PUTFIXEDMATOBJ_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGimmick.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "types.h"

// total size: 0x60
class clsPutFixedMatObj_Obj : public clsGimmickObj {
public:
    clsPutFixedMatObj_Obj();
    virtual ~clsPutFixedMatObj_Obj();

    nspPackId::enm getPackId() const { return nspPackId::PUT_FIXEDMATOBJ_2094; }
    virtual void draw(clsModelType_OB_TX_MO_MA* pModel,
                      f32* pfMatA,
                      u32* pu32NodeCount,
                      f32* pfMatB,
                      f32 f32Param,
                      u32 u32Param);

    static f32 m_tof32CLIP_DISTx2;

    enum enmPutFixedMatObjMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enmPutFixedMatObjMode m_ePutFixedMatObjMode; // offset 0x50, size 0x4
};

// total size: 0x98
class clsPutFixedMatObj_Task : public clsMultiModelGimmick_Task<clsPutFixedMatObj_Task,
                                                                clsPutFixedMatObj_Obj,
                                                                clsMultiObjTxMaModels> {
public:
    clsPutFixedMatObj_Task(u32 u32ObjectAreaNum)
        : clsMultiModelGimmick_Task<clsPutFixedMatObj_Task,
                                    clsPutFixedMatObj_Obj,
                                    clsMultiObjTxMaModels>(u32ObjectAreaNum, 0x18A92)
    {
    }
    virtual ~clsPutFixedMatObj_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // PUTFIXEDMATOBJ_HPP
