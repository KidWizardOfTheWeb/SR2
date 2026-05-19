#ifndef ST05SPAIN_HPP
#define ST05SPAIN_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/PlayerData.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

class clsPlayerTask;
class clsSpain_Obj;
class hkShape;

class clsSpain_Task : public clsBaseGimmickBody<clsSpain_Task, clsSpain_Obj, clsModelType_OB_TX> {
public:
    clsSpain_Task(u32 p0) : clsBaseGimmickBody(0, 0) {}
    virtual ~clsSpain_Task() {}

    virtual void createModel(stcBinInfo& p0) {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

// total size: 0xF0
class clsSpain_Obj : public clsPhantomGimmickObject {
public:
    // Note: enmMode name collision with global enmMode in GimmickObj.hpp.
    enum enmMode {
        MODE__READY = 0,
        MODE__WAIT = 1,
        MODE__CHARGE = 2,
        MODE__SHOOT = 3,
        MODE__HORMING = 4,
        MODE__BLAST = 5,
    };

    clsSpain_Obj() {}
    virtual ~clsSpain_Obj() {}

    void setMode(enmMode eMode) { m_eMode = eMode; }
    virtual nspPackId::enm getPackId() const { return nspPackId::ST05_SPAIN_15030; }
    void moveTrg(clsPlayerTask* pcPlayer) {}

    virtual void contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2);
    virtual void contactRemoveEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void createData();
    virtual void destroyData();
    virtual void reset();

    void moveRemove(clsPlayerTask* pcPlayer);

    enmMode m_eMode;                 // offset 0x60, size 0x4
    hkShape* m_pcShape;              // offset 0x64, size 0x4
    f32 m_sInvMtx[4][4];             // offset 0x70, size 0x40
    stcPlayerData m_asPlayerData[8]; // offset 0xB0, size 0x40
};

#endif // ST05SPAIN_HPP
