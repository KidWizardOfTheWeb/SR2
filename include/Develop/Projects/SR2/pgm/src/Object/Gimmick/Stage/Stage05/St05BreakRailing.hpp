#ifndef ST05BREAKRAILING_HPP
#define ST05BREAKRAILING_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"

class clsBreakRailing_Obj;
class clsPlayerTask;

// total size: 0xC
class clsBreakRailingThrCol : public clsBaseThroughCollision {
public:
    virtual ~clsBreakRailingThrCol() {}

    virtual void contactAlwaysEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void contactRemoveEvent(hkContactPoint* pcObject, clsObject* pParam2);

    clsBreakRailing_Obj* m_pcBreakRailingObj; // offset 0x8, size 0x4
};

// total size: 0x120
class clsBreakRailing_Obj : public clsRigidBodyGimmickObj {
public:
    // enmMode collision with Game.hpp; this variant is local to break railing.
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    clsBreakRailing_Obj() {}
    virtual ~clsBreakRailing_Obj() {}

    virtual void reset();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST05_BREAK_RAILING_15070; }

    void checkThrough(clsPlayerTask* pcPlayerTask);

    enmMode m_eMode;                 // offset 0xD0, size 0x4
    clsBreakRailingThrCol m_cThrCol; // offset 0xD4, size 0xC
    f32 m_sInvMtx[4][4];             // offset 0xE0, size 0x40
};

// total size: 0x94
class clsBreakRailing_Task
    : public clsBaseGimmickBody<clsBreakRailing_Task, clsBreakRailing_Obj, clsModelType_OB> {
public:
    clsBreakRailing_Task(u32 param);
    virtual ~clsBreakRailing_Task();

    virtual void reset();
    virtual void createModel(stcBinInfo& rBinInfo);
    virtual void execute();
    virtual void draw();

    stcInfo* m_psInfo; // offset 0x90, size 0x4
};

#endif // ST05BREAKRAILING_HPP
