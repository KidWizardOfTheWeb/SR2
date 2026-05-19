#ifndef ST07WALLTHROUGHCOLLISION_HPP
#define ST07WALLTHROUGHCOLLISION_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsWallThroughCollision_Obj;
class hkShape;

// total size: 0x14
class clsWallThroughCollision : public clsBaseThroughCollision {
public:
    clsWallThroughCollision() : clsBaseThroughCollision(), m_pcWallThroughCollision_Obj(0) {}
    virtual ~clsWallThroughCollision() {}

    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);

    clsWallThroughCollision_Obj* m_pcWallThroughCollision_Obj; // offset 0x8, size 0x4
    u32 m_u32colNum;                                           // offset 0xC, size 0x4
    u8 m_bCheckFlag;                                           // offset 0x10, size 0x1
};

// total size: 0xB0
class clsWallThroughCollision_Obj : public clsGimmickObj {
public:
    enum enmMode {
        MODE_INIT = 0,
        MODE_STOP = 1,
        MODE_MOVE = 2,
    };

    clsWallThroughCollision_Obj() : clsGimmickObj() {}
    virtual ~clsWallThroughCollision_Obj() {}

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST07_WALL_THROUGH_17060; }
    virtual void reset();

    u8 CheckMode(u32 u32Lap, u32 u32Rank);

    static f32 tof32ClipSqDist;

    enmMode m_eMode;                          // offset 0x50, size 0x4
    clsWallThroughCollision m_acCollision[4]; // offset 0x54, size 0x50
    hkShape* m_pcShape;                       // offset 0xA4, size 0x4
    u32 m_u32Num;                             // offset 0xA8, size 0x4
};

// total size: 0xA0
class clsWallThroughCollision_Task : public clsSingleModelGimmick_Task<clsWallThroughCollision_Task,
                                                                       clsWallThroughCollision_Obj,
                                                                       clsModelType_OB_TX_MO> {
public:
    clsWallThroughCollision_Task(u32 u32ObjectAreaNum);
    virtual ~clsWallThroughCollision_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rParam1);

    f32* m_pf32TexCoordV; // offset 0x9C, size 0x4
};

#endif // ST07WALLTHROUGHCOLLISION_HPP
