#ifndef ST08FZONEENEMY_HPP
#define ST08FZONEENEMY_HPP

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/FrameControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

struct stcPointData;

// total size: 0x100
class clsFZoneEnemy_Obj : public clsRigidBodyGimmickObj {
public:
    // RECONSTRUCTED: enum scope.
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    // RECONSTRUCTED: enum scope.
    enum enmState {
        STATE_WAIT = 0,
        STATE_MOVE = 1,
        STATE_SLOWDOWN = 2,
    };

    virtual ~clsFZoneEnemy_Obj();
    clsFZoneEnemy_Obj()
    {
        m_eMode = MODE_INIT;
        m_eState = STATE_WAIT;
        m_cFrameControl.m_f32Frame = -2.0f;
        m_cFrameControl.m_f32CountFrame = 0.0f;
        m_u8NowPointNo = 0;
        m_s8AddPoint = 0;
        m_opsPointData = NULL;
        m_u8PointNum = 0;
    }

    virtual void contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject);
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST08_FZONE_ENEMY_18060; }
    virtual void reset();
    virtual void init();
    virtual void main();
    virtual void mainCrash();
    virtual void requestDrawBreakEffect();

    void draw(clsModelType_OB_TX_MO& rcModel,
              NNS_MATRIX* psMtxPal,
              u32* psNodeStat,
              const NNS_MATRIX* opaNnViewMtx,
              NNS_MATRIX* psMtxWork,
              u32 u32ViewNo);
    void setVelocityAndFrame(f32 f32LengthRate, f32 f32Speed);

    static f32 m_tof32CLIP_DISTx2;

    enmMode m_eMode;                 // offset 0xD0, size 0x4
    enmState m_eState;               // offset 0xD4, size 0x4
    f32 m_f32Speed;                  // offset 0xD8, size 0x4
    f32 m_f32RotX;                   // offset 0xDC, size 0x4
    f32 m_f32AddRotX;                // offset 0xE0, size 0x4
    clsFrameControl m_cFrameControl; // offset 0xE4, size 0x8
    u8 m_u8NowPointNo;               // offset 0xEC, size 0x1
    s8 m_s8AddPoint;                 // offset 0xED, size 0x1
    stcPointData* m_opsPointData;    // offset 0xF0, size 0x4
    u8 m_u8PointNum;                 // offset 0xF4, size 0x1
};

class clsFZoneEnemy_Task : public clsSingleModelGimmick_Task<clsFZoneEnemy_Task,
                                                             clsFZoneEnemy_Obj,
                                                             clsModelType_OB_TX_MO> {
public:
    clsFZoneEnemy_Task(u32 u32Param1) : clsSingleModelGimmick_Task(u32Param1, 101000)
    {
        hkVector4 cBox(8.0f, 5.0f, 8.0f, 0.0f);
        m_pcRigidShape = new hkBoxShape(cBox, hkConvexShapeDefaultRadius);
    }
    virtual ~clsFZoneEnemy_Task();

    virtual void reset();
    virtual void execute();
    virtual void draw();
};

inline clsFZoneEnemy_Obj::~clsFZoneEnemy_Obj()
{
    destroyData();
}

inline clsFZoneEnemy_Task::~clsFZoneEnemy_Task()
{
}

#endif // ST08FZONEENEMY_HPP
