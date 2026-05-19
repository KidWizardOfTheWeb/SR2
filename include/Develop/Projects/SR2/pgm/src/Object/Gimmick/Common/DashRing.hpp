#ifndef DASHRING_HPP
#define DASHRING_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBox.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PutGravityObj2.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class hkContactPoint;
class clsObject;

namespace nspDashRing {
extern f32 tof32CLIP_DISTx2[17];
}

// total size: 0x80
class clsDashRing_Obj : public clsPhantomGimmickObject {
public:
    inline clsDashRing_Obj() : clsPhantomGimmickObject() {}
    virtual ~clsDashRing_Obj() {}

    u32 m_u32RingNo;        // offset 0x60, size 0x4
    f32 m_f32Scale;         // offset 0x64, size 0x4
    f32 m_f32PushSpeed;     // offset 0x68, size 0x4
    s32 m_s32GravityPathNo; // offset 0x6C, size 0x4
    s32 m_s32StiffFrame;    // offset 0x70, size 0x4

    static f32 m_tf32CLIP_DISTx2;

    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const;
    virtual void draw(clsModelType_OB_TX& rcObj,
                      f32 (*psMtxPal)[4][4],
                      u32* psNodeStat,
                      const f32 (*opaNnViewMtx)[4][4],
                      f32 (*psMtxWork)[4][4]);
    virtual void contactTriggerEvent(hkContactPoint* pParam1, clsObject* pcObject);
};

// total size: 0xB0
class clsDashRing_Task
    : public clsMultiShape,
      public clsSingleModelGimmick_Task<clsDashRing_Task, clsDashRing_Obj, clsModelType_OB_TX>,
      public clsGimmickCommon {
public:
    clsDashRing_Task(u32 u32ObjectAreaNum)
        : clsSingleModelGimmick_Task<clsDashRing_Task, clsDashRing_Obj, clsModelType_OB_TX>(
              u32ObjectAreaNum, 0x18A88),
          m_psFlushLightTexIdx(0), m_pf32FlushLightTexCoordV(0)
    {
    }
    virtual ~clsDashRing_Task() {}

    virtual void execute();
    virtual void draw();

    u16* m_psFlushLightTexIdx;      // offset 0xA8, size 0x4
    f32* m_pf32FlushLightTexCoordV; // offset 0xAC, size 0x4
};

#endif // DASHRING_HPP
