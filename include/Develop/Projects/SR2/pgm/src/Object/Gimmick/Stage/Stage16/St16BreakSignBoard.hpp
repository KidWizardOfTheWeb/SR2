#ifndef ST16BREAKSIGNBOARD_HPP
#define ST16BREAKSIGNBOARD_HPP

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"

// total size: 0xE0
class clsBreakSignBoard_Obj : public clsRigidBodyGimmickObj {
public:
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enum enmMode m_eMode; // offset 0xD0, size 0x4

    clsBreakSignBoard_Obj() : clsRigidBodyGimmickObj(), m_eMode(MODE_INIT) {}
    virtual ~clsBreakSignBoard_Obj() { destroyData(); }
    virtual void reset();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject);
    virtual nspPackId::enm getPackId() const { return nspPackId::ST16_BREAK_SIGNBOARD_26020; }
    virtual void main();
    virtual void draw(clsModelType_OB_TX* pcModels,
                      NNS_MATRIX* psMtxPal,
                      u32* psNodeStat,
                      const NNS_MATRIX* opaNnViewMtx,
                      NNS_MATRIX* psMtxWork);

    static f32 m_tof32CLIP_DISTx2;

    // total size: 0xE0
};

// total size: 0x8
class clsSignBoardModel {
public:
    clsSignBoardModel() : m_u32Num(0), m_apcModels(NULL) {}
    ~clsSignBoardModel()
    {
        u32 u32Index = 1;
        clsModelType_OB_TX* pcModel = m_apcModels;
        if (m_u32Num > 1) {
            ++pcModel;
            do {
                pcModel->m_psObject = NULL;
                ++u32Index;
                ++pcModel;
            } while (u32Index < m_u32Num);
        }
        if (m_apcModels != NULL) {
            delete[] m_apcModels;
        }
        m_apcModels = NULL;
    }
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
                                    clsSignBoardModel>(u32Param1, 99999)
    {
    }
    virtual ~clsBreakSignBoard_Task();
    virtual void execute();
    virtual void draw();
    virtual void reset();

    static NNS_VECTOR m_toafDebrisOffset[4];
};

inline clsBreakSignBoard_Task::~clsBreakSignBoard_Task()
{
}

#endif // ST16BREAKSIGNBOARD_HPP
