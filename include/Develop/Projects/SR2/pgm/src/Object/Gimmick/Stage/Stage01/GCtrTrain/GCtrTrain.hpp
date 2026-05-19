#ifndef GCTRTRAIN_HPP
#define GCTRTRAIN_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Path.hpp"

class clsPlayerTask;
class clsBackLineEffectTask;

// total size: 0x350
class clsGCtrlTrain_Obj : public clsRigidBodyGimmickObj {
public:
    // Note: enmMode collision with global in Game.hpp — nested per DWARF ownership
    enum enmMode {
        MODE__READY = 0,
        MODE__WAIT = 1,
        MODE__CHARGE = 2,
        MODE__SHOOT = 3,
        MODE__HORMING = 4,
        MODE__BLAST = 5,
    };

    enmMode m_eMode;                         // offset 0xD0, size 0x4
    clsGimmickPath m_cGimmickPath;           // offset 0xE0, size 0x190
    clsPath m_cPathPlayer;                   // offset 0x270, size 0x60
    u32 m_u32PlayerTaskNum;                  // offset 0x2D0, size 0x4
    clsGCtrlTrain_Obj* m_pcParentObj;        // offset 0x2D4, size 0x4
    clsPlayerTask* m_pcPlayerTask[4];        // offset 0x2D8, size 0x10
    f32 m_f32PlayerDashEfcFrame[4];          // offset 0x2E8, size 0x10
    f32 m_f32Offset;                         // offset 0x2F8, size 0x4
    f32 m_sDrawMtx[4][4];                    // offset 0x300, size 0x40
    clsBackLineEffectTask* m_apcLineTask[2]; // offset 0x340, size 0x8

    static f32 m_tof32CLIP_DISTx2;

    clsGCtrlTrain_Obj();
    virtual ~clsGCtrlTrain_Obj() {}
    virtual nspPackId::enm getPackId() const { return nspPackId::ST01_GCTRL_TRAIN_OBJECT_11221; }
    virtual void contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2);
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void init();
    virtual void main();
    void start();
    void controlPlayer();
    u8 draw(NNS_OBJECT* pParam1,
            f32 (*)[4][4],
            u32* pParam3,
            const f32 (*)[4][4],
            f32 (*)[4][4],
            u32 u32Param6);
};

#endif // GCTRTRAIN_HPP
