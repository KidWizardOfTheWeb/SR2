#ifndef PRODUCTIONROBOMANAGER_HPP
#define PRODUCTIONROBOMANAGER_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/ProductionRobo/ProductionRobo.hpp"
#include "types.h"

class clsProductRoboManager_Obj;
struct stcRoboData;

// total size: 0x10
class clsProductionRoboCollision : public clsBaseThroughCollision {
public:
    virtual ~clsProductionRoboCollision() {}

    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);

    clsProductRoboManager_Obj* m_pcManager; // offset 0x8, size 0x4
    f32 m_f32WaitFrame;                     // offset 0xC, size 0x4
};

// total size: 0x70
class clsProductRoboManager_Obj : public clsGimmickObj {
public:
    // enmMode collision with Game.hpp; this variant is local to product robo manager.
    enum enmMode {
        MODE_NONE = 0,
        MODE_CRASH = 1,
        MODE_BREAK = 2,
    };

    clsProductRoboManager_Obj() {}
    virtual ~clsProductRoboManager_Obj() {}

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST01_PRODUCTION_ROBO_11050; }
    virtual u32 getMultiDrawNum() const { return m_u8RoboNum; }

    clsProductionRoboCollision m_cThroughCol; // offset 0x50, size 0x10
    enmMode m_eMode;                          // offset 0x60, size 0x4
    stcSetDataDetail* m_psSetData;            // offset 0x64, size 0x4
    stcRoboData* m_psRoboData;                // offset 0x68, size 0x4
    u8 m_u8RoboNum;                           // offset 0x6C, size 0x1
};

// total size: 0x610
struct stcRoboData {
    clsProductionRobo_Obj m_cRoboObj[2]; // offset 0x0, size 0x600
    u8 bExecute;                         // offset 0x600
};

// total size: 0x18
class clsSecurityRoboModels {
public:
    clsSecurityRoboModels() {}
    ~clsSecurityRoboModels() {}

    clsModelType_OB_TX_MO m_cRoboStand; // offset 0x0, size 0x10
    clsModelType_OB_TX m_cRoboBall;     // offset 0x10, size 0x8
};

// total size: 0xA8
class clsProductionRobo_Task : public clsBaseGimmickBody<clsProductionRobo_Task,
                                                         clsProductRoboManager_Obj,
                                                         clsSecurityRoboModels> {
public:
    clsProductionRobo_Task(u32 u32ObjectAreaNum);
    virtual ~clsProductionRobo_Task();

    hkShape* getShapeRobo();
    f32 getMotionEndFrame();

    virtual void execute();
    virtual void draw();
    virtual void reset();
    void createModel(stcBinInfo& rsBinInfoI);

    hkShape* m_pcShapeRobo; // offset 0xA4, size 0x4
};

#endif // PRODUCTIONROBOMANAGER_HPP
