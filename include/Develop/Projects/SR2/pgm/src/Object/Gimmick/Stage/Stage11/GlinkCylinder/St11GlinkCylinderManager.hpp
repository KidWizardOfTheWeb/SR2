#ifndef ST11GLINKCYLINDERMANAGER_HPP
#define ST11GLINKCYLINDERMANAGER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/GlinkCylinder/St11GlinkCylinder.hpp"
#include "usr/local/sega/nn/src/Object/nnobject.h"

class clsGlinkCylinderManager_Obj;

// total size: 0x10
class clsGlinkCylinderThroughCol : public clsBaseThroughCollision {
public:
    virtual ~clsGlinkCylinderThroughCol() {}

    virtual void contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2);

    clsGlinkCylinderManager_Obj* m_pcManager; // offset 0x8, size 0x4
    f32 m_f32WaitFrame;                       // offset 0xC, size 0x4
};

// total size: 0x70
class clsGlinkCylinderManager_Obj : public clsGimmickObj {
public:
    // enmMode collision with Game.hpp; this variant is local to Glink cylinder manager.
    enum enmMode {
        MODE_INIT = 0,
        MODE_START_WAIT = 1,
        MODE_MAIN = 2,
        MODE_WAIT = 3,
    };

    clsGlinkCylinderManager_Obj() {}
    virtual ~clsGlinkCylinderManager_Obj() {}

    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST11_GLINK_CYLINDER_21050; }

    void reset();
    void execute();
    void draw(NNS_OBJECT* psObject,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);

    enmMode m_eMode;                          // offset 0x50, size 0x4
    u32 m_u32Num;                             // offset 0x54, size 0x4
    clsGlinkCylinder_Object* m_pcCylinders;   // offset 0x58, size 0x4
    stcSetDataDetail* m_psSetData;            // offset 0x5C, size 0x4
    clsGlinkCylinderThroughCol m_cThroughCol; // offset 0x60, size 0x10
};

#endif // ST11GLINKCYLINDERMANAGER_HPP
