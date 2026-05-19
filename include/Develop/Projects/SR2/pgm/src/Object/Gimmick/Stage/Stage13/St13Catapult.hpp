#ifndef ST13CATAPULT_HPP
#define ST13CATAPULT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsSt13Catapult_Obj;
class clsSt13Catapult_Task;
class clsPlayerTask;
class hkContactPoint;
class clsObject;
class clsSe3DControl;

enum enmIvyMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
    MODE_MOVE = 2,
    MODE_WAIT = 3,
};

enum enmMoveMode {
    MOVEMODE_WAIT = 0,
    MOVEMODE_APPROACH = 1,
    MOVEMODE_END = 2,
};

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"

// total size: 0xC0
class clsSt13Catapult_Obj : public clsPhantomGimmickObject {
public:
    clsSt13Catapult_Obj();
    virtual ~clsSt13Catapult_Obj();

    virtual void contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void createData();
    virtual void destroyData();
    virtual void init();
    virtual void reset();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST13_CATAPULT_23020; }
    virtual void shootPlayerToGround();
    virtual void movePlayer();

    NNS_VECTORFAST m_sOffsetVecFast;  // offset 0x60, size 0x10
    NNS_VECTORFAST m_sRollNrmVecFast; // offset 0x70, size 0x10
    enum enmIvyMode m_eIvyMode;       // offset 0x80, size 0x4
    clsPlayerTask* m_pcPlayer;        // offset 0x84, size 0x4
    f32 m_f32EndFrame;                // offset 0x88, size 0x4
    f32 m_f32MotionFrame;             // offset 0x8C, size 0x4
    f32 m_f32WaitFrame;               // offset 0x90, size 0x4
    f32 m_f32MoveEndFrame;            // offset 0x94, size 0x4
    f32 m_f32MotionPlayRate;          // offset 0x98, size 0x4
    f32 m_f32Speed;                   // offset 0x9C, size 0x4
    s32 m_s32ParentPathNo;            // offset 0xA0, size 0x4
    enum enmMoveMode m_eMoveMode;     // offset 0xA4, size 0x4
    clsPlayerTask* m_pcMovePlayer;    // offset 0xA8, size 0x4
    u8 m_bShoot;                      // offset 0xAC, size 0x1
    clsSe3DControl* m_pcSe3DControl;  // offset 0xB0, size 0x4
};

// total size: 0xC
class clsSt13CatapultThroughCollision : public clsBaseThroughCollision {
public:
    virtual ~clsSt13CatapultThroughCollision() {}
    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);

    static NNS_VECTOR tosPosVec;

    clsSt13Catapult_Task* m_pcSt13Catapult_Task; // offset 0x8, size 0x4
};

// total size: 0xAC
class clsSt13Catapult_Task : public clsSingleModelGimmick_Task<clsSt13Catapult_Task,
                                                               clsSt13Catapult_Obj,
                                                               clsModelType_OB_TX_MO> {
public:
    clsSt13Catapult_Task(u32 u32ObjectAreaNum);
    virtual ~clsSt13Catapult_Task() {}

    clsSt13CatapultThroughCollision m_cThroughCollision; // offset 0x9C, size 0xC

    virtual void reset();
    virtual void draw();
    virtual void execute();
    void GoToCatapult(clsPlayerTask* pcPlayer);
};

#endif // ST13CATAPULT_HPP
