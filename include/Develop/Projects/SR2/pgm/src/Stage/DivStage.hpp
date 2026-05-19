#ifndef DIVSTAGE_HPP
#define DIVSTAGE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Stage/BaseStage.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Portal.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

// total size: 0x498
class clsDivStage_Task : public clsBaseStage_Task {
public:
    clsDivStage_Task(stcBinInfo& rsBinInfoI);
    virtual ~clsDivStage_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual s32 getDivNum() const { return m_s32DivNum; }
    virtual void drawNormal(s32& s32PortalDataNo,
                            s32 s32d,
                            u8 u8CamCurrentPortal,
                            clsModelType_OB_TX_MO_MA* pcDivModel,
                            const f32 (*opaNnViewMtx)[4][4],
                            u32 u32v,
                            const u8** oppu8IgnoreResidencePortalData,
                            u8 u8NowPortal);

    void draw1Model(clsModelType_OB_TX_MO_MA* pcDivModel, const f32 (*opaNnViewMtx)[4][4]);

    clsModelType_OB_TX_MO_MA m_acDivModel[24]; // offset 0x140, size 0x300
    s32 m_s32DivNum;                           // offset 0x440, size 0x4
    clsPortal m_cMapPortal;                    // offset 0x444, size 0x50
    u8* m_opu8IgnoreResidencePortalData;       // offset 0x494, size 0x4
};

#endif // DIVSTAGE_HPP
