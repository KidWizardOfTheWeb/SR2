#ifndef PATHTRAIN_HPP
#define PATHTRAIN_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"

class clsGimmickObj;
class clsBackLineEffectTask;

enum enmPathTrainMode {
    MODE_INIT = 0,
    MODE_STARTWAIT = 1,
    MODE_MAIN = 2,
    MODE_WAIT = 3,
};

// total size: 0x2D0
class clsPathTrain_Obj : public clsRigidBodyGimmickObj {
public:
    enmPathTrainMode m_ePathTrainMode;       // offset 0xD0, size 0x4
    clsGimmickPath m_cGimmickPath;           // offset 0xE0, size 0x190
    u32 m_u32PlayerTaskNum;                  // offset 0x270, size 0x4
    clsPathTrain_Obj* m_pcParentObj;         // offset 0x274, size 0x4
    f32 m_sDrawMtx[4][4];                    // offset 0x280, size 0x40
    clsBackLineEffectTask* m_apcLineTask[2]; // offset 0x2C0, size 0x8
    u8 m_bMoveRigidBody;                     // offset 0x2C8, size 0x1
    u8 m_bLight;                             // offset 0x2C9, size 0x1
    f32 m_f32LightMotionFrame;               // offset 0x2CC, size 0x4

    clsPathTrain_Obj();
    virtual ~clsPathTrain_Obj();
    virtual nspPackId::enm getPackId() const
    {
        return nspPackId::ST01_PATH_TRAIN_11040;
    } // likely: return 11040;
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void init();
    virtual void main();
    void start();
    void setTrainQuat(NNS_QUATERNION* pParam1, clsGimmickObj* pParam2, clsGimmickObj* pParam3);
    void draw(clsModelType_OB_TX* pParam1,
              clsModelType_OB_TX_MO_MA* pParam2,
              f32 (*)[4][4],
              u32* pParam4,
              const f32 (*)[4][4],
              f32 (*)[4][4],
              u32 u32Param7);
};

#endif // PATHTRAIN_HPP
