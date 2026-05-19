#ifndef PUTPARALLAXOBJ_HPP
#define PUTPARALLAXOBJ_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsPutParallax_Obj : public clsPhantomGimmickObject {
public:
    clsPutParallax_Obj();
    virtual ~clsPutParallax_Obj() {}
    void draw(clsModelType_OB_TX_MO_MA* pcModel,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              const f32 (*opaBillBoardMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);
    virtual nspPackId::enm getPackId() const { return nspPackId::PUT_PARALLAX_2103; }
};

class clsPutParallax_Task : public clsSingleModelGimmick_Task<clsPutParallax_Task,
                                                              clsPutParallax_Obj,
                                                              clsModelType_OB_TX_MO_MA> {
public:
    clsPutParallax_Task(u32 u32Param1)
        : clsSingleModelGimmick_Task<clsPutParallax_Task,
                                     clsPutParallax_Obj,
                                     clsModelType_OB_TX_MO_MA>(u32Param1, 0x18A88)
    {
    }
    virtual ~clsPutParallax_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // PUTPARALLAXOBJ_HPP
