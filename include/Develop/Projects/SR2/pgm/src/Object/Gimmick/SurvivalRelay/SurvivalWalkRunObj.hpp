#ifndef SURVIVALWALKRUNOBJ_HPP
#define SURVIVALWALKRUNOBJ_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Texture/nntexture.h"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"

class clsSurvivalRelayPlayerTask;
class clsSurvivalRelayWalkRunLine_Obj;

// total size: 0x58
class clsSurvivalRelayWalkRunObjModels {
public:
    clsSurvivalRelayWalkRunObjModels() {}
    ~clsSurvivalRelayWalkRunObjModels() {}

    clsModelType_OB_TX_MO_MA m_cModelWall; // offset 0x0, size 0x20
    clsModelType_OB_TX_MO_MA m_cModelAT_B; // offset 0x20, size 0x20
    _NNS_TEXLIST* m_pcTexAT_R;             // offset 0x40, size 0x4
    clsModelType_OB_TX_MO m_cModelLine_B;  // offset 0x44, size 0x10
    _NNS_TEXLIST* m_pcTexLine_R;           // offset 0x54, size 0x4
};

// total size: 0x70
class clsSurvivalRelayWalkRunObj_Obj : public clsPhantomGimmickObject {
public:
    clsSurvivalRelayWalkRunObj_Obj() {}
    virtual ~clsSurvivalRelayWalkRunObj_Obj() {}
    virtual void contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void contactAlwaysEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void contactRemoveEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::SURVIVALRELAY_WALKRUN_28500; }
    virtual void main();

    hkShape* m_pcShape; // offset 0x60, size 0x4
};

// total size: 0xEC
class clsSurvivalRelayWalkRunObj_Task
    : public clsBaseGimmickBody<clsSurvivalRelayWalkRunObj_Task,
                                clsSurvivalRelayWalkRunObj_Obj,
                                clsSurvivalRelayWalkRunObjModels> {
public:
    clsSurvivalRelayWalkRunObj_Task(u32 u32ObjectAreaNum);
    virtual ~clsSurvivalRelayWalkRunObj_Task();
    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI);

    void startHitPlayer(clsSurvivalRelayPlayerTask* pcPlayer,
                        u32 u32TypeNo,
                        clsSurvivalRelayWalkRunObj_Obj* psObj,
                        const NNS_VECTOR* copsRot);

    clsSurvivalRelayWalkRunLine_Obj* m_pcWalkRunLine_Obj[2]; // offset 0xE4, size 0x8
};

#endif // SURVIVALWALKRUNOBJ_HPP
