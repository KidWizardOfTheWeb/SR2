#ifndef MISSIONTIMEGATE_HPP
#define MISSIONTIMEGATE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"

enum enmMissionTimeGateMode {
    TIMEGATE_MODE_MAIN = 0,
    TIMEGATE_MODE_DEAD = 1,
};

struct hkContactPoint;
class clsObject;

class clsMissionTimeGate_Obj : public clsPhantomGimmickObject {
public:
    clsMissionTimeGate_Obj();

    virtual ~clsMissionTimeGate_Obj() {}
    virtual nspPackId::enm getPackId() const { return nspPackId::MISSION_TIME_GATE_27010; }

    virtual void createData();
    virtual void destroyData();
    virtual void contactTriggerEvent(hkContactPoint* p0, clsObject* p1);
    void draw(clsModelType_OB_TX_MO_MA& p0,
              f32 (*psMtxPal)[4][4],
              u32* p2,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 p3);

    u32 m_u32AddTime;                                    // offset 0x60, size 0x4
    enum enmMissionTimeGateMode m_enMissionTimeGateMode; // offset 0x64, size 0x4
};

// total size: 0xB0
class clsMissionTimeGate_Task : public clsSingleModelGimmick_Task<clsMissionTimeGate_Task,
                                                                  clsMissionTimeGate_Obj,
                                                                  clsModelType_OB_TX_MO_MA> {
public:
    clsMissionTimeGate_Task(u32 u32ObjectAreaNum)
        : clsSingleModelGimmick_Task<clsMissionTimeGate_Task,
                                     clsMissionTimeGate_Obj,
                                     clsModelType_OB_TX_MO_MA>(u32ObjectAreaNum, 0x18A88)
    {
    }
    virtual ~clsMissionTimeGate_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    f32* m_pf32TexCoordV; // offset 0xAC, size 0x4
};

#endif // MISSIONTIMEGATE_HPP
