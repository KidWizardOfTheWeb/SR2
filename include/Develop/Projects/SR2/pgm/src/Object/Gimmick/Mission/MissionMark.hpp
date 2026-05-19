#ifndef MISSIONMARK_HPP
#define MISSIONMARK_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Mission/MissionTarget.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

enum enmMissionMarkMode {
    MARK_MODE_MAIN = 0,
    MARK_MODE_DEAD = 1,
};

struct hkContactPoint;
class clsObject;

class clsMissionMark_Obj : public clsPhantomGimmickObject {
public:
    clsMissionMark_Obj();

    virtual ~clsMissionMark_Obj() {}
    virtual nspPackId::enm getPackId() const { return nspPackId::MISSION_MARK_27011; }

    virtual void createData();
    virtual void destroyData();
    virtual void contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2);
    void draw(clsModelType_OB_TX_MO_MA& rcObj,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4]);

    enum enmMissionMarkMode m_enMissionMarkMode; // offset 0x60, size 0x4
};

// total size: 0xB8
class clsMissionMark_Task : public clsSingleModelGimmick_Task<clsMissionMark_Task,
                                                              clsMissionMark_Obj,
                                                              clsModelType_OB_TX_MO_MA>,
                            private clsMissionTarget {
public:
    clsMissionMark_Task(u32 u32ObjectAreaNum);
    virtual ~clsMissionMark_Task();

    virtual void execute();
    virtual void draw();
    virtual void reset();

    virtual void setMode(u32);
    virtual void addMode();
    virtual void addMode(u32);
    virtual void subMode();
    virtual void subMode(u32);
    virtual void reinitMode();

    void createModel(stcBinInfo& rsBinInfo);
    void setSetData(const stcSetDataDetail& rsDetail);

    s32 getPathPoint() { return 0; }
    NNS_VECTORFAST* getPosVecFastPtr() { return 0; }

    // Members
};

#endif // MISSIONMARK_HPP
