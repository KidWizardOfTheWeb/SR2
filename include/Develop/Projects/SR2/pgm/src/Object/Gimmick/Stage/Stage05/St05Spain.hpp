#ifndef ST05SPAIN_HPP
#define ST05SPAIN_HPP

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "usr/local/sce/ee/gcc/ee/lib/libc/memset.h"
#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/PlayerData.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

class clsPlayerTask;
class clsSpain_Obj;
class hkShape;

// total size: 0xF0
class clsSpain_Obj : public clsPhantomGimmickObject {
public:
    // RECONSTRUCTED: enum scope.
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    clsSpain_Obj() : m_eMode(MODE_INIT), m_pcShape(NULL)
    {
        memset(m_asPlayerData, 0, sizeof(m_asPlayerData));
    }
    virtual ~clsSpain_Obj();

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
    NNS_MATRIX m_sInvMtx;            // offset 0x70, size 0x40
    stcPlayerData m_asPlayerData[8]; // offset 0xB0, size 0x40
};

inline clsSpain_Obj::~clsSpain_Obj()
{
    destroyData();
}

class clsSpain_Task : public clsBaseGimmickBody<clsSpain_Task, clsSpain_Obj, clsModelType_OB_TX> {
public:
    clsSpain_Task(u32 u32ObjectAreaNum) : clsBaseGimmickBody(u32ObjectAreaNum, 101000) {}
    virtual ~clsSpain_Task() {}

    virtual void createModel(stcBinInfo& p0) {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST05SPAIN_HPP
