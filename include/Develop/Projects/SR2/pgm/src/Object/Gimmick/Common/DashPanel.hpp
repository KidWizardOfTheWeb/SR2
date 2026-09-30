#ifndef DASHPANEL_HPP
#define DASHPANEL_HPP

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBox.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class hkContactPoint;
class clsObject;

class clsDashPanel_Task;

class clsDashPanel_Obj : public clsPhantomGimmickObject {
public:
    clsDashPanel_Obj() {}
    virtual ~clsDashPanel_Obj() { destroyData(); }

    virtual void createData();
    virtual void destroyData();

    void draw(clsModelType_OB_TX& rModels,
              NNS_MATRIX* psMtxPal,
              u32* psNodeStat,
              const NNS_MATRIX* opaNnViewMtx,
              NNS_MATRIX* psMtxWork,
              u32 u32ViewNo);
    void contactAlwaysEvent(hkContactPoint* pcContact, clsObject* pcObject);
    void contactRemoveEvent(hkContactPoint* pcContact, clsObject* pcObject);

    nspPackId::enm getPackId() const { return nspPackId::DASH_PANEL_2020; }

    static f32 t_aof32ClipDistSq[];
    static f32 t_f32ClipDist;

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
          m_pf32TexCoordV(NULL)
    {
        m_pcPhantomShape = new hkSphereShape(2.0f);
        clsDashPanel_Obj::t_f32ClipDist =
            clsDashPanel_Obj::t_aof32ClipDistSq[nspGlobal::sTask.pcBaseRace->getStageNo()];
    }
    virtual ~clsDashPanel_Task() {}

    virtual void execute();
    virtual void draw();

    f32* m_pf32TexCoordV; // offset 0x98, size 0x4
};

#endif // DASHPANEL_HPP
