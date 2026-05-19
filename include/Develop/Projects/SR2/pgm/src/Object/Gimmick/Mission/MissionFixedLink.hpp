#ifndef MISSIONFIXEDLINK_HPP
#define MISSIONFIXEDLINK_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsPlayerTask;

class clsMissionFixedLink_Object : public clsBaseGravityLinkObject {
public:
    clsMissionFixedLink_Object();
    virtual ~clsMissionFixedLink_Object();

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();
    virtual void drawEffect(clsPlayerTask* pcPlayer);

    void draw(clsModelType_OB_TX_MO_MA& rModels,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);

    static f32 tof32ClipSqDist;

    // Members
    s32 m_s32BreakMode; // offset 0xE0, size 0x4
};

class clsMissionFixedLink_Task : public clsSingleModelGimmick_Task<clsMissionFixedLink_Task,
                                                                   clsMissionFixedLink_Object,
                                                                   clsModelType_OB_TX_MO_MA> {
public:
    clsMissionFixedLink_Task(u32 u32ObjectAreaNum);
    virtual ~clsMissionFixedLink_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    // Members
    f32 m_f32MatFrame; // offset 0xAC, size 0x4
};

#endif // MISSIONFIXEDLINK_HPP
