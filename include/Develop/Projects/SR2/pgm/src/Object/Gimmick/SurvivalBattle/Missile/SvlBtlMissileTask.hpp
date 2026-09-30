#ifndef SVLBTLMISSILETASK_HPP
#define SVLBTLMISSILETASK_HPP

#include "types.h"
#include "usr/local/sce/ee/gcc/ee/lib/libc/memset.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/Missile/SvlBtlMissileObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/SurvivalBattle/SurvivalBattleMsg2D.hpp"

class clsLockOnTarget2D_Task;
class clsLockOnAppoint3D_Task;
class clsLockOnFixed3D_Task;
class clsPlayerTask;

class clsSvlBtlMissile_Task;

// total size: 0x8
struct stcLockOnPlayerData {
    f32 m_f32Distance; // offset 0x0, size 0x4
    s8 m_s8PlayerNo;   // offset 0x4, size 0x1
    s8 m_s8Type;       // offset 0x5, size 0x1
};

// total size: 0x8
struct stcLockOnTargetData {
    f32 m_f32Distance; // offset 0x0, size 0x4
    s32 m_s32LockOnNo; // offset 0x4, size 0x4
};

// total size: 0x58
struct stcPlayerMissileData {
    clsSvlBtlMissile_Object* m_apcMissile[4];            // offset 0x0, size 0x10
    clsLockOnTarget2D_Task* m_pcLockOnTargetTask[4];     // offset 0x10, size 0x10
    clsSurvivalBattleMsg2D_Task* m_pcLockOnDistanceTask; // offset 0x20, size 0x4
    clsLockOnAppoint3D_Task* m_pcLockOnAppointTask;      // offset 0x24, size 0x4
    clsLockOnFixed3D_Task* m_pcLockOnFixedTask;          // offset 0x28, size 0x4
    stcLockOnPlayerData m_sLockOnPlayerData;             // offset 0x2C, size 0x8
    stcLockOnTargetData m_asLockOnTargetData[3];         // offset 0x34, size 0x18
    s32 m_s32StockNum;                                   // offset 0x4C, size 0x4
    s32 m_s32ChargeNum;                                  // offset 0x50, size 0x4
    s32 m_s32LockOnNum;                                  // offset 0x54, size 0x4
};

// total size: 0x1F4
class clsSvlBtlMissile_Task : public clsSingleModelGimmick_Task<clsSvlBtlMissile_Task,
                                                                clsSvlBtlMissile_Object,
                                                                clsModelType_OB_TX> {
public:
    enum enmLockOnPlayerType {
        LOCKON_PLAYER_TYPE__NONE = 0,
        LOCKON_PLAYER_TYPE__APPOINT = 1,
        LOCKON_PLAYER_TYPE__FIXED = 2,
    };

    virtual ~clsSvlBtlMissile_Task();
    clsSvlBtlMissile_Task(const stcSetDataDetail& param_1)
        : clsSingleModelGimmick_Task<clsSvlBtlMissile_Task,
                                     clsSvlBtlMissile_Object,
                                     clsModelType_OB_TX>(0x40, 0x18A88)
    {
        hkVector4 cVec(clsSvlBtlMissile_Object::tosCollisionHalfSizeVec.x,
                       clsSvlBtlMissile_Object::tosCollisionHalfSizeVec.y,
                       clsSvlBtlMissile_Object::tosCollisionHalfSizeVec.z,
                       0.0f);
        m_pcRigidShape = new hkBoxShape(cVec, hkConvexShapeDefaultRadius);
        memset(m_asPlayerData, 0, sizeof(m_asPlayerData));
        for (s32 s32i = 0; s32i < 0x40; ++s32i) {
            clsSvlBtlMissile_Object* pcObj = m_vecUnusedGmkObjArray.back();
            m_vecUnusedGmkObjArray.pop_back();
            m_vecGmkObjArray.push_back(pcObj);
            pcObj->setSetData(param_1);
        }
    }

    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void setSetData(const stcSetDataDetail& param_1) {}

    void cancelDrawTargetLockOnAll(s32 param_1);
    void setLockOnPlayer(f32 param_1, s32 param_2, s32 param_3, enmLockOnPlayerType param_4);
    void lostMissile(s32 param_1);
    void shootMissile(s32 param_1);
    void lockonMissile(s32 param_1);
    void setupMissile(s32 param_1, s32 param_2);
    s32 calcSetupMissileNum(s32 param_1, s32 param_2);

    static NNS_VECTORFAST m_OffsetPosVecFastTable[4];

    stcPlayerMissileData m_asPlayerData[4]; // offset 0x94, size 0x160
};

inline clsSvlBtlMissile_Task::~clsSvlBtlMissile_Task()
{
}

#endif // SVLBTLMISSILETASK_HPP
