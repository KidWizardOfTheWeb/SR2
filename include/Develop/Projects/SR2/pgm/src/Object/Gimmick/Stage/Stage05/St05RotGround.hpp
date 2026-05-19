#ifndef ST05ROTGROUND_HPP
#define ST05ROTGROUND_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "types.h"

class clsPlaySe_2D;
class clsRotGround_Obj;
class clsTask;

// total size: 0x8
struct stcRotGroundPath {
    f32 f32Rate; // offset 0x0, size 0x4
    s16 s16x;    // offset 0x4, size 0x2
    s16 s16y;    // offset 0x6, size 0x2
};

// total size: 0x10
class clsRotGroundThroughCollision : public clsBaseThroughCollision {
public:
    virtual ~clsRotGroundThroughCollision() {}

    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);
    virtual void contactRemoveEvent(clsPlayerTask* pcPlayer);

    clsRotGround_Obj* m_pcRotGroundObj; // offset 0x8, size 0x4
    hkShape* m_pcShape;                 // offset 0xC, size 0x4
};

// total size: 0x210
class clsRotGround_Obj : public clsGimmickObj {
public:
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    clsRotGround_Obj() {}
    virtual ~clsRotGround_Obj() {}

    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST05_ROT_GROUND_15000; }

    f32 getLengthRate(const NNS_VECTORFAST& rsPosVecFast);
    void execute();
    void draw(clsModelType_OB_TX& rcModel);
    f32 getLengthRate(u32 u32Param1) const { return m_af32LengthRate[u32Param1]; }
    u8 isPlayer(u32 u32Param1) { return (m_u32PlayerFlg & (1 << u32Param1)) != 0; }

    static NNS_VECTORFAST m_tosColiPosVecFast;
    static f32 m_tof32ColiRot;

    enmMode m_eMode;                                  // offset 0x50, size 0x4
    u32 m_u32PlayerFlg;                               // offset 0x54, size 0x4
    f32 m_af32Rot[8];                                 // offset 0x58, size 0x20
    f32 m_af32LengthRate[8];                          // offset 0x78, size 0x20
    clsRotGroundThroughCollision m_cThroughCollision; // offset 0x98, size 0x10
    clsTask* m_apcParticleTask[5];                    // offset 0xA8, size 0x14
    f32 m_asParticleMtx[5][4][4];                     // offset 0xC0, size 0x140
    clsPlaySe_2D* m_pcPlaySe2D;                       // offset 0x200, size 0x4
    u8 m_bPlaySeFlg;                                  // offset 0x204, size 0x1
};

// total size: 0x94
class clsRotGround_Task
    : public clsSingleModelGimmick_Task<clsRotGround_Task, clsRotGround_Obj, clsModelType_OB_TX> {
public:
    clsRotGround_Task(u32 u32ObjectAreaNum) : clsSingleModelGimmick_Task(0, u32ObjectAreaNum) {}
    virtual ~clsRotGround_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST05ROTGROUND_HPP
