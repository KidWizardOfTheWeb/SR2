#ifndef ST11SECURITYROBOMANAGER_HPP
#define ST11SECURITYROBOMANAGER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"

struct stcRoboData;
class clsSecurityRoboManager_Obj;

// total size: 0x18
class clsSt11SecurityRoboModels {
public:
    clsSt11SecurityRoboModels() {}
    ~clsSt11SecurityRoboModels() {}

    clsModelType_OB_TX_MO m_cRoboStand; // offset 0x0, size 0x10
    clsModelType_OB_TX m_cRoboBall;     // offset 0x10, size 0x8
};

// total size: 0x2C
struct stcRoboArray {
    u8 u8RoboNum;         // offset 0x0, size 0x1
    f32 f32WaitFrame[10]; // offset 0x4, size 0x28
};

// total size: 0x10
class clsSecurityRoboCollision : public clsBaseThroughCollision {
public:
    virtual ~clsSecurityRoboCollision() {}
    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);

    clsSecurityRoboManager_Obj* m_pcManager; // offset 0x8, size 0x4
    f32 m_f32WaitFrame;                      // offset 0xC, size 0x4
};

// total size: 0x70
class clsSecurityRoboManager_Obj : public clsGimmickObj {
public:
    clsSecurityRoboManager_Obj() {}
    virtual ~clsSecurityRoboManager_Obj() {}
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST11_PATH_SECURITY_ROBO_21020; }

    clsSecurityRoboCollision m_cThroughCol; // offset 0x50, size 0x10
    enmMode m_eMode;                        // offset 0x60, size 0x4
    stcSetDataDetail* m_psSetData;          // offset 0x64, size 0x4
    stcRoboData* m_psRoboData;              // offset 0x68, size 0x4
    u8 m_u8RoboArrayNo;                     // offset 0x6C, size 0x1

    static stcRoboArray m_oastcRoboArray[3];
};

// total size: 0xA8
class clsSecurityRoboManager_Task : public clsBaseGimmickBody<clsSecurityRoboManager_Task,
                                                              clsSecurityRoboManager_Obj,
                                                              clsSt11SecurityRoboModels> {
public:
    clsSecurityRoboManager_Task(u32 u32ObjectAreaNum);
    virtual ~clsSecurityRoboManager_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI);

    f32 getMotionEndFrame() { return m_cModel.m_cRoboStand.m_psMotion->EndFrame; }
    hkShape* getShapeRobo() { return m_pcShapeRobo; }

    hkShape* m_pcShapeRobo; // offset 0xA4, size 0x4
};

#endif // ST11SECURITYROBOMANAGER_HPP
