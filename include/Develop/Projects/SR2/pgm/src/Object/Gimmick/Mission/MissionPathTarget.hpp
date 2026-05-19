#ifndef MISSIONPATHTARGET_HPP
#define MISSIONPATHTARGET_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PathGravityObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Mission/MissionTarget.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class hkShape;

// total size: 0x260
class clsMissionPathTarget_Obj : public clsMissionTarget_Obj, public clsPathGravityObj_Obj {
public:
    clsMissionPathTarget_Obj();
    virtual ~clsMissionPathTarget_Obj() {}

    virtual void init();
    virtual void main();
    virtual void reset();
    virtual void draw(clsModelType_OB_TX& rcObj,
                      f32 (*psMtxPal)[4][4],
                      u32* psNodeStat,
                      const f32 (*opaNnViewMtx)[4][4],
                      f32 (*psMtxWork)[4][4],
                      u32 u32Param6);
    virtual void createData();
    virtual void destroyData();
    virtual void calcPathPostural();

    u8 nextSearchPath();

    hkShape* m_pcPartsShape; // offset 0x250, size 0x4
};

// total size: 0xA0
class clsMissionPathTarget_Task : public clsSingleModelGimmick_Task<clsMissionPathTarget_Task,
                                                                    clsMissionPathTarget_Obj,
                                                                    clsModelType_OB_TX>,
                                  private clsMissionTarget {
public:
    clsMissionPathTarget_Task(u32 u32ObjectAreaNum);
    virtual ~clsMissionPathTarget_Task();

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

    nspPackId::enm getPackId() const;

    // Members
};

#endif // MISSIONPATHTARGET_HPP
