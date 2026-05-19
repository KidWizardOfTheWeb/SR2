#ifndef PUTFIXEDOBJECT_HPP
#define PUTFIXEDOBJECT_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGimmick.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "types.h"

// total size: 0x60
class clsPutFixedObject_Obj : public clsGimmickObj {
public:
    clsPutFixedObject_Obj();
    virtual ~clsPutFixedObject_Obj();

    nspPackId::enm getPackId() const { return nspPackId::PUT_FIXEDOBJECT_2090; }
    virtual void draw(clsModelType_OB_TX** ppModels,
                      f32* pfMatA,
                      u32* pu32NodeCount,
                      f32* pfMatB,
                      f32 f32Param,
                      u32 u32Param);

    static f32 m_tof32CLIP_DISTx2;

    enum enmPutFixedObjectMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enmPutFixedObjectMode m_ePutFixedObjectMode; // offset 0x50, size 0x4
};

// total size: 0x98
class clsPutFixedObject_Task : public clsMultiModelGimmick_Task<clsPutFixedObject_Task,
                                                                clsPutFixedObject_Obj,
                                                                clsMultiObTxModels> {
public:
    clsPutFixedObject_Task(u32 u32ObjectAreaNum)
        : clsMultiModelGimmick_Task<clsPutFixedObject_Task,
                                    clsPutFixedObject_Obj,
                                    clsMultiObTxModels>(u32ObjectAreaNum, 0x18A92)
    {
    }
    virtual ~clsPutFixedObject_Task() {}

    virtual void execute();
    virtual void draw();
};

#endif // PUTFIXEDOBJECT_HPP
