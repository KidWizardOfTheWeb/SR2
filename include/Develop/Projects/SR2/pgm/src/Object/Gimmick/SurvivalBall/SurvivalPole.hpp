#ifndef SURVIVALPOLE_HPP
#define SURVIVALPOLE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsSe3DControl;

enum enmSurvivalBallPoleMode {
    BALLPOLE_MODE_MAIN = 0,
    BALLPOLE_MODE_DEAD = 1,
    CTRLFLAG = 1536,
};

enum enmSurvivalBallPoleType {
    SURVIVALBALLPOLE_TYPE_A = 0,
    SURVIVALBALLPOLE_TYPE_B = 1,
    SURVIVALBALLPOLE_TYPE_MAX = 2,
};

// total size: 0xF0
class clsSurvivalBallPole_Obj : public clsRigidBodyGimmickObj {
public:
    inline clsSurvivalBallPole_Obj() : clsRigidBodyGimmickObj() {}
    virtual ~clsSurvivalBallPole_Obj() {}

    enmSurvivalBallPoleMode m_enMode;      // offset 0xD0, size 0x4
    enmSurvivalBallPoleType m_enPointType; // offset 0xD4, size 0x4
    u32 m_u32SetType;                      // offset 0xD8, size 0x4
    f32 m_f32ContactFrame;                 // offset 0xDC, size 0x4
    clsSe3DControl* m_pcSe3DControl;       // offset 0xE0, size 0x4

    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void requestDrawContactEffect(const hkContactPoint* pParam1);
    virtual void requestDrawBreakEffect();
    virtual void main();
    virtual void mainCrash();
    virtual void draw(clsModelType_OB_TX_MO_MA& rcModel,
                      f32 (*psMtxPal)[4][4],
                      u32* psNodeStat,
                      const f32 (*opaNnViewMtx)[4][4],
                      f32 (*psMtxWork)[4][4],
                      u32 u32ViewNo);
    inline void init() {}
    inline nspPackId::enm getPackId() const { return nspPackId::SURVIVALBALL_POLE_28020; }
};

// total size: 0xB4
class clsSurvivalBallPole_Task : public clsSingleModelGimmick_Task<clsSurvivalBallPole_Task,
                                                                   clsSurvivalBallPole_Obj,
                                                                   clsModelType_OB_TX_MO_MA> {
public:
    clsSurvivalBallPole_Task(u32 u32ObjectAreaNum);
    virtual ~clsSurvivalBallPole_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    hkShape* m_pcRigidShape[2]; // offset 0xAC, size 0x8
};

#endif // SURVIVALPOLE_HPP
