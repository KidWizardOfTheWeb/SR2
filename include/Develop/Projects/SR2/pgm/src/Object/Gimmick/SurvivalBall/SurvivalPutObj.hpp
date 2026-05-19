#ifndef SURVIVALPUTOBJ_HPP
#define SURVIVALPUTOBJ_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

// total size: 0xE0
class clsSurvivalBallPutObj_Obj : public clsRigidBodyGimmickObj {
public:
    // Note: enmMode collision with Game.hpp — nested here for disambiguation
    enum enmMode {
        MODE_NONE = 0,
        MODE_CRASH = 1,
        MODE_BREAK = 2,
    };

    clsSurvivalBallPutObj_Obj();
    virtual ~clsSurvivalBallPutObj_Obj() {}
    virtual void contactTriggerCallback(hkContactPointConfirmedEvent& cEvent);
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::SURVIVALBALL_PUT_OBJ_28040; }
    virtual void reset();
    virtual void init() {}
    virtual void main();

    void draw(NNS_OBJECT* psObject,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);

    enmMode m_eMode;                 // offset 0xD0, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xD4, size 0x4
};

// total size: 0x98
class clsSurvivalBallPutObj_Task : public clsSingleModelGimmick_Task<clsSurvivalBallPutObj_Task,
                                                                     clsSurvivalBallPutObj_Obj,
                                                                     clsModelType_OB_TX> {
public:
    clsSurvivalBallPutObj_Task(u32 u32ObjectAreaNum);
    virtual ~clsSurvivalBallPutObj_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // SURVIVALPUTOBJ_HPP
