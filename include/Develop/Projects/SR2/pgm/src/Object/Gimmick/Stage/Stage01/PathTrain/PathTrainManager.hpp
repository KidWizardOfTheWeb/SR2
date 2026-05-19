#ifndef PATHTRAINMANAGER_HPP
#define PATHTRAINMANAGER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/FrameControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

class clsPathTrainManager_Obj;
class clsPathTrain_Obj;
struct stcTrainData;

// total size: 0xAC
class clsPathTrain_Task : public clsBaseGimmickBody<clsPathTrain_Task,
                                                    clsPathTrainManager_Obj,
                                                    clsModelType_OB_TX_MO_MA> {
public:
    clsPathTrain_Task(u32 param);
    virtual ~clsPathTrain_Task();

    virtual void reset();
    virtual void createModel(stcBinInfo& rBinInfo);
    virtual void execute();
    virtual void draw();
};

// total size: 0x18
class clsPathTrainThroughCol : public clsBaseThroughCollision {
public:
    virtual ~clsPathTrainThroughCol() {}

    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);

    clsPathTrainManager_Obj* m_pcManager; // offset 0x8, size 0x4
    clsFrameControl m_cFrameControl;      // offset 0xC, size 0x8
    s8 m_s8StartCount;                    // offset 0x14, size 0x1
};

// total size: 0x90
class clsPathTrainManager_Obj : public clsGimmickObj {
public:
    enum enmMode {
        MODE_START = 0,
        MODE_MAIN = 1,
        MODE_WAIT = 2,
    };

    clsPathTrainManager_Obj() {}
    virtual ~clsPathTrainManager_Obj() {}

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST01_PATH_TRAIN_11040; }
    virtual u32 getMultiDrawNum() const { return m_s32TrainNum; }

    void start();
    void execute();

    static u32 otau32Se_TrainHorn[2];
    static u32 otau32Se_TrainL[2];

    clsPathTrainThroughCol m_cThroughCol; // offset 0x50, size 0x18
    enmMode m_eMode;                      // offset 0x68, size 0x4
    s32 m_s32TrainNum;                    // offset 0x6C, size 0x4
    s32 m_s32VehiclesNum;                 // offset 0x70, size 0x4
    f32 m_f32Speed;                       // offset 0x74, size 0x4
    f32 m_f32SpeedUpFrame;                // offset 0x78, size 0x4
    stcSetDataDetail* m_psSetData;        // offset 0x7C, size 0x4
    stcTrainData* m_psTrainData;          // offset 0x80, size 0x4
    clsPathTrain_Obj* m_pcTrainObj;       // offset 0x84, size 0x4
};

#endif // PATHTRAINMANAGER_HPP
