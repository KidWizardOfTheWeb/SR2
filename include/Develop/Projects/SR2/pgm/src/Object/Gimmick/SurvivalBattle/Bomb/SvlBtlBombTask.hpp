#ifndef SVLBTLBOMBTASK_HPP
#define SVLBTLBOMBTASK_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/Bomb/SvlBtlBombObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsLockOnAppoint3D_Task;
class clsLockOnTarget2D_Task;

// total size: 0xC
struct stcPlayerBombData {
    clsSvlBtlBomb_Object* m_pcBombObject;       // offset 0x0, size 0x4
    clsLockOnTarget2D_Task* m_pcLockOnTarget;   // offset 0x4, size 0x4
    clsLockOnAppoint3D_Task* m_pcLockOnAppoint; // offset 0x8, size 0x4
};

// total size: 0xC4
class clsSvlBtlBomb_Task : public clsSingleModelGimmick_Task<clsSvlBtlBomb_Task,
                                                             clsSvlBtlBomb_Object,
                                                             clsModelType_OB_TX> {
public:
    clsSvlBtlBomb_Task(const stcSetDataDetail& rParam1) : clsSingleModelGimmick_Task(0, 0) {}
    virtual ~clsSvlBtlBomb_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void setSetData(const stcSetDataDetail& rParam1) {}

    u8 isGetBomb(s32 s32PlayerNo);
    u8 isGlopBomb(s32 s32PlayerNo);
    void setup(s32 s32PlayerNo);
    void glop(s32 s32PlayerNo, s32 s32TargetNo);
    void requestRegistLockOnTargetEffect(s32 s32PlayerNo, s32 s32TargetNo);
    void requestDeleteLockOnTargetEffect(s32 s32PlayerNo);

    stcPlayerBombData m_asPlayerData[4]; // offset 0x94, size 0x30
};

#endif // SVLBTLBOMBTASK_HPP
