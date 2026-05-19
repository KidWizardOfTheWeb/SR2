#ifndef SURVIVALSTART_HPP
#define SURVIVALSTART_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOClock.hpp"

class hkShape;
class clsPlaySe_2D;

// total size: 0x120
class clsSurvivalBallStart_Obj : public clsPhantomGimmickObject {
public:
    clsSurvivalBallStart_Obj();
    virtual ~clsSurvivalBallStart_Obj() {}
    virtual nspPackId::enm getPackId() const { return nspPackId::SURVIVALBALL_START_28030; }
    virtual void contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject);
    virtual void contactAlwaysEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void createData();
    virtual void destroyData();

    void draw(clsModelType_OB_TX_MO_MA& rcModel,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4]);

    hkShape* m_pcShape;            // offset 0x60, size 0x4
    f32 m_f32Scale;                // offset 0x64, size 0x4
    f32 m_aObjMax[2][4][4];        // offset 0x70, size 0x80
    clsOOClock m_cClock_StartTime; // offset 0xF0, size 0x24
    clsPlaySe_2D* m_pcPlaySe2D;    // offset 0x114, size 0x4
};

// total size: 0x98
class clsSurvivalBallStart_Task : public clsSingleModelGimmick_Task<clsSurvivalBallStart_Task,
                                                                    clsSurvivalBallStart_Obj,
                                                                    clsModelType_OB_TX_MO_MA> {
public:
    clsSurvivalBallStart_Task(u32 u32ObjectAreaNum);
    virtual ~clsSurvivalBallStart_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // SURVIVALSTART_HPP
