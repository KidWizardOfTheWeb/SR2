#ifndef SURVIVALPOINTRING_HPP
#define SURVIVALPOINTRING_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsSurvivalBallPointRing_Obj;
class clsPlaySe_2D;
class clsRigidBodyGimmickObj;
class clsModelType_OB_TX_MO_MA;
class hkShape;

// total size: 0xC
class clsSurvivalBallPointRing_Collision : public clsBaseThroughCollision {
public:
    virtual ~clsSurvivalBallPointRing_Collision() {}

    void execute();

    clsSurvivalBallPointRing_Obj* m_pcSurvivalBallPointRing_Obj; // offset 0x8, size 0x4
};

enum enmSurvivalBallPointRingMode {
    SURVIVALBALL_MODE_MAIN = 0,
    SURVIVALBALL_MODE_DEAD = 1,
};

enum enmSurvivalBallPointRingPoint {
    SURVIVALBALLPOINTRING_POINT_10 = 0,
    SURVIVALBALLPOINTRING_POINT_30 = 1,
    SURVIVALBALLPOINTRING_POINT_50 = 2,
    SURVIVALBALLPOINTRING_POINT_MAX = 3,
};

// total size: 0x100
class clsSurvivalBallPointRing_Obj : public clsRigidBodyGimmickObj {
public:
    clsSurvivalBallPointRing_Obj();
    virtual ~clsSurvivalBallPointRing_Obj() {}

    u8 m_enMode;                                            // offset 0xD0, size 0x4
    u8 m_enPointType;                                       // offset 0xD4, size 0x4
    clsSurvivalBallPointRing_Collision m_cThroughCollision; // offset 0xD8, size 0xC
    u32 m_u32SetType;                                       // offset 0xE4, size 0x4
    clsPlaySe_2D* m_pcPlayGoalSe2D;                         // offset 0xE8, size 0x4
    f32 m_f32GoalMotionFrame;                               // offset 0xEC, size 0x4
    u32 m_u32RstartCount;                                   // offset 0xF0, size 0x4

    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const;
    virtual void reset();
    virtual void init();
    virtual void main();
    virtual void contactInterraction(clsRigidBodyGimmickObj* pParam1);
    virtual void draw(clsModelType_OB_TX_MO_MA* pcModel,
                      f32 (*psMtxPal)[4][4],
                      u32* psNodeStat,
                      const f32 (*opaNnViewMtx)[4][4],
                      f32 (*psMtxWork)[4][4],
                      u32 u32ViewNo);
    virtual void contactInterractionPhantomShape(clsRigidBodyGimmickObj* pcObject);
};

class clsSurvivalBallPointRing_Task
    : public clsSingleModelGimmick_Task<clsSurvivalBallPointRing_Task,
                                        clsSurvivalBallPointRing_Obj,
                                        clsModelType_OB_TX_MO_MA> {
public:
    clsSurvivalBallPointRing_Task(u32 u32Param1);
    virtual ~clsSurvivalBallPointRing_Task() {}
    virtual void reset();
    virtual void execute();
    virtual void draw();

    hkShape* m_pcPhantomShape[3]; // offset 0xAC, size 0xC
    hkShape* m_pcRigidShape[3];   // offset 0xB8, size 0xC
};

#endif // SURVIVALPOINTRING_HPP
