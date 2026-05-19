#ifndef DASHPANEL_HPP
#define DASHPANEL_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBox.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class hkContactPoint;
class clsObject;

class clsDashPanel_Obj : public clsPhantomGimmickObject {
public:
    clsDashPanel_Obj();
    virtual ~clsDashPanel_Obj();

    virtual void createData();
    virtual void destroyData();

    void draw(clsModelType_OB_TX& rModels,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);
    void contactAlwaysEvent(hkContactPoint* pcContact, clsObject* pcObject);
    void contactRemoveEvent(hkContactPoint* pcContact, clsObject* pcObject);

    nspPackId::enm getPackId() const { return nspPackId::DASH_PANEL_2020; }

    static f32 t_aof32ClipDistSq[];
    static f32 t_f32ClipDist;

    // Members
    f32 m_f32PushSpeed; // offset 0x60, size 0x4
};

// total size: 0x9C
class clsDashPanel_Task
    : public clsSingleModelGimmick_Task<clsDashPanel_Task, clsDashPanel_Obj, clsModelType_OB_TX>,
      public clsGimmickCommon {
public:
    clsDashPanel_Task(u32 u32Param1)
        : clsSingleModelGimmick_Task<clsDashPanel_Task, clsDashPanel_Obj, clsModelType_OB_TX>(
              u32Param1, 0x18A88),
          m_pf32TexCoordV(0)
    {
    }
    virtual ~clsDashPanel_Task() {}

    virtual void execute();
    virtual void draw();

    f32* m_pf32TexCoordV; // offset 0x98, size 0x4
};

#endif // DASHPANEL_HPP
