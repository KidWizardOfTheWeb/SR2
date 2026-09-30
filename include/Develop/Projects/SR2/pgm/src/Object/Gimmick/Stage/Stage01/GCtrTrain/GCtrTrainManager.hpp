#ifndef GCTRTRAINMANAGER_HPP
#define GCTRTRAINMANAGER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/System/NewDelete.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GmkBurnLight.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/GLinkTrain/GLinkTrainTask.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/GCtrTrain/GCtrTrain.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

class clsGCtrlTrainManager_Obj;
class clsGCtrlTrain_Obj;
struct stcTrainData;

// total size: 0x10
class clsGCtrlTrainThroughCol : public clsBaseThroughCollision {
public:
    virtual ~clsGCtrlTrainThroughCol() {}

    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);

    static s8 m_toas8ViewToEffectiveRanking[4];

    clsGCtrlTrainManager_Obj* m_pcManager; // offset 0x8, size 0x4
    f32 m_f32WaitFrame;                    // offset 0xC, size 0x4
};

// total size: 0x80
class clsGCtrlTrainManager_Obj : public clsGimmickObj {
public:
    // RECONSTRUCTED: enum scope.
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
        MODE_WAIT = 2,
    };

    clsGCtrlTrainManager_Obj()
    {
        m_cThroughCol.m_pcManager = this;
        m_cThroughCol.m_f32WaitFrame = 0.0f;
        m_eMode = MODE_INIT;
        m_s32TrainNum = 0;
        m_s32VehiclesNum = 0;
        m_f32Speed = 1.0f;
        m_psSetData = NULL;
        m_psTrainData = NULL;
        m_pcTrainObj = NULL;
    }
    virtual ~clsGCtrlTrainManager_Obj();

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST01_PATH_TRAIN_11040; }
    virtual u32 getMultiDrawNum() const { return m_s32TrainNum * m_s32VehiclesNum; }

    void start();
    void execute();

    static u32 otau32Se_TrainHorn[2];
    static u32 otau32Se_TrainL[2];

    clsGCtrlTrainThroughCol m_cThroughCol; // offset 0x50, size 0x10
    enmMode m_eMode;                       // offset 0x60, size 0x4
    s32 m_s32TrainNum;                     // offset 0x64, size 0x4
    s32 m_s32VehiclesNum;                  // offset 0x68, size 0x4
    f32 m_f32Speed;                        // offset 0x6C, size 0x4
    f32 m_f32SpeedUpFrame;                 // offset 0x70, size 0x4
    stcSetDataDetail* m_psSetData;         // offset 0x74, size 0x4
    stcTrainData* m_psTrainData;           // offset 0x78, size 0x4
    clsGCtrlTrain_Obj* m_pcTrainObj;       // offset 0x7C, size 0x4
};

class clsGCtrlTrain_Task
    : public clsBaseGimmickBody<clsGCtrlTrain_Task, clsGCtrlTrainManager_Obj, clsModelType_OB_TX> {
public:
    clsGCtrlTrain_Task(u32 u32ObjectAreaNum)
        : clsBaseGimmickBody<clsGCtrlTrain_Task, clsGCtrlTrainManager_Obj, clsModelType_OB_TX>(
              u32ObjectAreaNum, 101000)
    {
        hkVector4 cVec(4.5f, 2.6f, 12.0f, 0.0f);
        m_pcRigidShape = new hkBoxShape(cVec, hkConvexShapeDefaultRadius);
        clsModelType_OB_TX& rcModel = clsGLinkTrain_Task::GS()->m_cModel;
        pcGmkBurnLight_Task = new (16, 2, (u32ObjectAreaNum + 1) * 64)
            clsGmkBurnLight_Task<clsModelType_OB_TX>(rcModel, u32ObjectAreaNum + 1, 1);
    }
    virtual ~clsGCtrlTrain_Task();

    virtual void createModel(stcBinInfo& rParam1) { m_ePackId = nspPackId::ST01_GCTRL_TRAIN_11220; }

    virtual void reset();
    virtual void execute();
    virtual void draw();
};

inline clsGCtrlTrain_Task::~clsGCtrlTrain_Task()
{
}

inline clsGCtrlTrainManager_Obj::~clsGCtrlTrainManager_Obj()
{
    destroyData();
}

#endif // GCTRTRAINMANAGER_HPP
