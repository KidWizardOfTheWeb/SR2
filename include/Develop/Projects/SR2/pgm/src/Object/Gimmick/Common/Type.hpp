#ifndef TYPE_HPP
#define TYPE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBox.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

// total size: 0x50
class clsType_Obj : public clsGimmickObj {
public:
    static f32 t_aof32ClipDistSq[17];
    static f32 t_f32ClipDist;

    clsType_Obj() {}
    virtual ~clsType_Obj() {}
    virtual nspPackId::enm getPackId() const { return nspPackId::TYPE_2070; }

    void draw(clsModelType_OB_TX_MO_MA& rcObj,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u16** apsTexIdx,
              u32 u32GameCount,
              u32 u32Param8);
};

// total size: 0xC4
class clsType_Task
    : public clsSingleModelGimmick_Task<clsType_Task, clsType_Obj, clsModelType_OB_TX_MO_MA>,
      public clsGimmickCommon {
public:
    clsType_Task(u32 u32ObjectAreaNum)
        : clsSingleModelGimmick_Task<clsType_Task, clsType_Obj, clsModelType_OB_TX_MO_MA>(
              u32ObjectAreaNum, 0x18A88)
    {
    }
    virtual ~clsType_Task() {}

    virtual void execute();
    virtual void draw();

    u16* m_psObjectType_MonitorYajiTexIdx;      // offset 0xB0, size 0x4
    f32* m_pf32ObjectType_MonitorYajiTexCoordV; // offset 0xB4, size 0x4
    u16* m_psAnimationTexId;                    // offset 0xB8, size 0x4
    u16* m_psObjectType_MonitorLineTexIdx;      // offset 0xBC, size 0x4
    u16* m_psObjectType_MojiTexIdx;             // offset 0xC0, size 0x4
};

#endif // TYPE_HPP
