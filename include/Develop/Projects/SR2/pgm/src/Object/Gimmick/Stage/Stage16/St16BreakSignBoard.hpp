#ifndef ST16BREAKSIGNBOARD_HPP
#define ST16BREAKSIGNBOARD_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"

// Enum used by clsBreakSignBoard_Obj (owned by clsBreakSignBoard_Obj)
enum enmBreakSignBoardMode {
    MODE_START = 0,
    MODE_MAIN = 1,
    MODE_WAIT = 2,
};

// total size: 0xE0
class clsBreakSignBoard_Obj : public clsRigidBodyGimmickObj {
public:
    enum enmBreakSignBoardMode m_eMode; // offset 0xD0, size 0x4

    clsBreakSignBoard_Obj() : clsRigidBodyGimmickObj() {}
    virtual ~clsBreakSignBoard_Obj();
    virtual void reset();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject);
    virtual nspPackId::enm getPackId() const { return nspPackId::ST16_BREAK_SIGNBOARD_26020; }
    virtual void main();
    virtual void draw(clsModelType_OB_TX* pcModels,
                      f32 (*psMtxPal)[4][4],
                      u32* psNodeStat,
                      const f32 (*opaNnViewMtx)[4][4],
                      f32 (*psMtxWork)[4][4]);

    static f32 m_tof32CLIP_DISTx2;

    // total size: 0xE0
};

// total size: 0x8
class clsSignBoardModel {
public:
    ~clsSignBoardModel() {}
    void createModels(stcBinInfo& rsBinInfoI, u32 u32CalcObjNum);

    u32 m_u32Num;                    // offset 0x0, size 0x4
    clsModelType_OB_TX* m_apcModels; // offset 0x4, size 0x4
};

// total size: 0x98
class clsBreakSignBoard_Task : public clsMultiModelGimmick_Task<clsBreakSignBoard_Task,
                                                                clsBreakSignBoard_Obj,
                                                                clsSignBoardModel> {
public:
    clsBreakSignBoard_Task(u32 u32Param1)
        : clsMultiModelGimmick_Task<clsBreakSignBoard_Task,
                                    clsBreakSignBoard_Obj,
                                    clsSignBoardModel>(0, 0)
    {
    }
    virtual ~clsBreakSignBoard_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();

    static NNS_VECTOR m_toafDebrisOffset[4];
};

#endif // ST16BREAKSIGNBOARD_HPP
