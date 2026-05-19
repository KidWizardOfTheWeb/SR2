#ifndef ST02IVY_HPP
#define ST02IVY_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"
#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsIvy_Obj;
class clsPlayerTask;

enum enmIvyMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
    MODE_MOVE = 2,
    MODE_WAIT = 3,
};

class clsIvy_Obj : public clsPhantomGimmickObject {
public:
    clsIvy_Obj(u32 u32ObjectAreaNum);
    virtual ~clsIvy_Obj();
    virtual void reset();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const;
    void init();
    void setLandingGround();
    void shootPlayerToGround();
    void contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2);

    // Members
    NNS_VECTORFAST m_sRollNrmVecFast; // offset 0x60, size 0x10
    enmIvyMode m_eIvyMode;            // offset 0x70, size 0x4
    clsPlayerTask* m_pcPlayer;        // offset 0x74, size 0x4
    f32 m_f32EndFrame;                // offset 0x78, size 0x4
    f32 m_f32MotionFrame;             // offset 0x7C, size 0x4
    f32 m_f32WaitFrame;               // offset 0x80, size 0x4
    f32 m_f32MoveEndFrame;            // offset 0x84, size 0x4
    f32 m_f32MotionPlayRate;          // offset 0x88, size 0x4
    f32 m_f32Speed;                   // offset 0x8C, size 0x4
    s32 m_s32ParentPathNo;            // offset 0x90, size 0x4
};

class clsIvy_Task
    : public clsSingleModelGimmick_Task<clsIvy_Task, clsIvy_Obj, clsModelType_OB_TX_MO> {
public:
    clsIvy_Task(u32 u32ObjectAreaNum);
    virtual ~clsIvy_Task();
    virtual void reset();
    virtual void execute();
    virtual void draw();
    void shootPlayerToIvy(clsPlayerTask* pcPlayerTask);
};

#endif
