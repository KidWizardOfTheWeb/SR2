#ifndef ST15COREBASE_HPP
#define ST15COREBASE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/RigidBody.hpp"

// total size: 0x60
class clsCoreBase_Obj : public clsGimmickObj {
public:
    clsCoreBase_Obj() {}
    virtual ~clsCoreBase_Obj() {}

    virtual nspPackId::enm getPackId() const { return nspPackId::ST15_CORE_BASE_25000; }

    enum enmCoreBaseMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    static f32 m_tof32CLIP_DISTx2;

    enmCoreBaseMode m_eCoreBaseMode; // offset 0x50, size 0x4
    u8 m_bDrawFlag;                  // offset 0x54, size 0x1
};

// total size: 0x98
class clsCoreBase_Task : public clsSingleModelGimmick_Task<clsCoreBase_Task,
                                                           clsCoreBase_Obj,
                                                           clsModelType_OB_TX_MO_MA> {
public:
    clsCoreBase_Task(u32 u32ObjectAreaNum)
        : clsSingleModelGimmick_Task<clsCoreBase_Task, clsCoreBase_Obj, clsModelType_OB_TX_MO_MA>(
              u32ObjectAreaNum, 0x18A88)
    {
    }
    virtual ~clsCoreBase_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset() {}

    void setCoreBase();
    void endCoreBase();
};

#endif // ST15COREBASE_HPP
