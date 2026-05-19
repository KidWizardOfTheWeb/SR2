#ifndef MISSIONPATHROBO_HPP
#define MISSIONPATHROBO_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Mission/MissionPathTarget.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnquaternion.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsBackLineEffectTask;
class clsMissionPathRobo_Obj;
class clsPlayerTask;

class clsMissionPathRoboCollision : public clsBaseThroughCollision {
    // total size: 0xC
public:
    virtual ~clsMissionPathRoboCollision() {}
    virtual void contactTriggerEvent(clsPlayerTask* pParam1);

    void setPosRot(const NNS_VECTORFAST* psPosVec, const NNS_QUATERNION* psQuat);

    clsMissionPathRobo_Obj* m_pcMissionPathRobo_Obj; // offset 0x8, size 0x4
};

// total size: 0x2D0
class clsMissionPathRobo_Obj : public clsMissionPathTarget_Obj {
    // Members
public:
    f32 m_f32EffectFrame;                     // offset 0x260, size 0x4
    f32 m_sDrawMtx[4][4];                     // offset 0x270, size 0x40
    clsBackLineEffectTask* m_apcLineTask[2];  // offset 0x2B0, size 0x8
    u8 m_bStartFlag;                          // offset 0x2B8, size 0x1
    clsMissionPathRoboCollision m_cCollision; // offset 0x2BC, size 0xC

    // Weak/inline functions
public:
    virtual ~clsMissionPathRobo_Obj() {}
    nspPackId::enm getPackId() const { return nspPackId::MISSION_PATH_ROBO_27020; }

    // Non-weak functions
public:
    clsMissionPathRobo_Obj();

    virtual void init();
    virtual void main();
    virtual void reset();
    virtual void createData();
    virtual void destroyData();
    virtual void draw(clsModelType_OB_TX& rcObj,
                      f32 (*psMtxPal)[4][4],
                      u32* psNodeStat,
                      const f32 (*opaNnViewMtx)[4][4],
                      f32 (*psMtxWork)[4][4],
                      u32 u32ViewNo);
};

// total size: 0xA0
class clsMissionPathRobo_Task : public clsSingleModelGimmick_Task<clsMissionPathRobo_Task,
                                                                  clsMissionPathRobo_Obj,
                                                                  clsModelType_OB_TX>,
                                private clsMissionTarget {
public:
    clsMissionPathRobo_Task(u32 u32ObjectAreaNum);
    virtual ~clsMissionPathRobo_Task();

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

    s32 getPathPoint();
    NNS_VECTORFAST* getPosVecFastPtr();

    // Members
};

#endif // MISSIONPATHROBO_HPP
