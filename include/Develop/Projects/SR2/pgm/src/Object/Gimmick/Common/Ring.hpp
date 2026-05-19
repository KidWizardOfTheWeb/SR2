#ifndef RING_HPP
#define RING_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBox.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/Spring.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOTask.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"

class clsRingBase;

// total size: 0x60
class clsRingBase : public clsGimmickObj {
public:
    enum enmFollowType {
        FOLLOW_LINE = 0,
        FOLLOW_CIRCLE = 1,
    };

    enum enmMode {
        MODE_NONE = 0,
        MODE_EXECUTE = 1,
        MODE_BREAK = 2,
    } m_eMode; // offset 0x50, size 0x4

    f32 m_f32WaitTimer; // offset 0x54, size 0x4

    enum enmAttr {
        ATTR_NULL = 0,
        ATTR_HOMING = 1,
        ATTR_CRASH = 2,
    } m_eAttr; // offset 0x58, size 0x4

    virtual ~clsRingBase();
    virtual void setSleep();
    virtual nspPackId::enm getPackId() const { return nspPackId::CHARA_0; }
    virtual void requestFollow(clsPlayerTask* pcPlayer, enmFollowType eFollowType);
    virtual void wakeup();

    // total size: 0x60
};

typedef clsRingBase::enmFollowType enmFollowType;

// total size: 0x70
// filed unaligned size: 0x74
class clsRingCrash_Obj : public clsRingBase, public clsHaveGimmickRigidBody {
public:
    clsRingCrash_Obj() : clsRingBase() {}
    virtual ~clsRingCrash_Obj();
    virtual void createData();
    virtual void destroyData();
    virtual void drawCollision();
    virtual void setSleep();
    virtual u8 execute();
    virtual void draw(clsModelType_OB_TX& rParam1,
                      f32 (*)[4][4],
                      u32* pParam3,
                      const f32 (*)[4][4],
                      u32 u32Param5,
                      f32 (*)[4][4],
                      u32 u32Param7);
    virtual void requestFollow(clsPlayerTask* pcPlayer, enmFollowType eFollowType);
    virtual void destroyCollision();
    virtual void updateSetEditorCollision();

    void setPositionRigid();
    void setCrushParam(const NNS_VECTORFAST& rsPosVecFast,
                       const NNS_QUATERNION& rsRotQuat,
                       const NNS_VECTORFAST& rsVelocityFast);
    void contactAlwaysEvent(hkContactPoint* pParam1, clsObject* pParam2);

    // total size: 0x70
    // filed unaligned size: 0x74
};

// total size: 0x70
class clsRing_Obj : public clsRingBase, public clsHaveGimmickPhantom {
public:
    clsRing_Obj() : clsRingBase() {}
    virtual ~clsRing_Obj();
    virtual void createData();
    virtual void destroyData();
    virtual void drawCollision();
    virtual void setSleep();
    virtual u8 execute();
    virtual void draw(clsModelType_OB_TX& rParam1,
                      f32 (*)[4][4],
                      u32* pParam3,
                      const f32 (*)[4][4],
                      u32 u32Param5,
                      f32 (*)[4][4],
                      u32 u32Param7);
    virtual void requestFollow(clsPlayerTask* pcPlayer, enmFollowType eFollowType);
    virtual void destroyCollision();
    virtual void updateSetEditorCollision();

    void reset();
    void setPositionPhantom();
    void contactAlwaysEvent(hkContactPoint* pParam1, clsObject* pcObject);

    // total size: 0x70
};

// total size: 0x80
class clsRingFollow_Obj : public clsRingBase {
public:
    clsRingFollow_Obj() : clsRingBase() {}
    virtual ~clsRingFollow_Obj();
    enum enmFollowType m_eFollowType; // offset 0x60, size 0x4

    clsPlayerTask* m_pcPlayer; // offset 0x64, size 0x4

    clsRingBase* m_pcParent; // offset 0x68, size 0x4

    s32 m_A32Angle; // offset 0x6C, size 0x4

    s32 m_A32AddAngle; // offset 0x70, size 0x4

    f32 m_f32Length; // offset 0x74, size 0x4

    f32 m_f32Height; // offset 0x78, size 0x4
    virtual u8 execute();
    virtual void draw(clsModelType_OB_TX& rcObj,
                      f32 (*psMtxPal)[4][4],
                      u32* psNodeStat,
                      const f32 (*opaNnViewMtx)[4][4],
                      u32 u32RotY,
                      f32 (*psMtxWork)[4][4],
                      u32 u32ViewNo);

    void regist(clsPlayerTask* pcPlayer,
                enmFollowType eFollowType,
                const NNS_VECTORFAST& rcPosVecFast,
                f32 f32WaitFrame,
                clsRingBase* pcParent);
    u8 followLine();
    u8 followCircel();

    // total size: 0x80

    typedef void (*t_opFollowFunc)(clsRingFollow_Obj*);
    static t_opFollowFunc t_opFollowFuncTbl[2];
};

// Struct used by clsRing_Task::m_vctDrawRing
struct stcDrawRing {
    u16 u16Index; // offset 0x0, size 0x2

    u8 u8Num; // offset 0x2, size 0x1

    u8 u8PortalType; // offset 0x3, size 0x1
};

// total size: 0x6AF0
class clsRing_Task
    : public clsSingleModelGimmick_Task<clsRing_Task, clsRing_Obj, clsModelType_OB_TX>,
      public clsGimmickCommon {
public:
    clsRing_Task(u32 u32ObjectAreaNum) : clsSingleModelGimmick_Task(0, 0) {}
    virtual ~clsRing_Task();
    clsRingCrash_Obj m_cCrashRing[128]; // offset 0xA0, size 0x3800

    clsRingFollow_Obj m_cFollowRing[100]; // offset 0x38A0, size 0x3200

    u32 m_u32RotCount; // offset 0x6AA0, size 0x4

    clsOOList m_lpcExecuteRing; // offset 0x6AA4, size 0x14

    clsOOVector m_tdvctReqDrawBuff; // offset 0x6AB8, size 0x10

    clsOOVector m_vctDrawRing; // offset 0x6AC8, size 0x10

    u8 m_bErrorDrawRing; // offset 0x6AD8, size 0x1

    hkShape* m_apcShape[2]; // offset 0x6ADC, size 0x8

    virtual void execute();
    virtual void draw();
    virtual void reset();

    void setFollowRing(clsPlayerTask* pcPlayerTask,
                       u8 u8Num,
                       enmFollowType eFollowType,
                       f32 f32WaitIntervalFrame,
                       const NNS_VECTORFAST& rsPosVecFast,
                       clsRingBase* pcRingObj);
    void setCrashRing(clsPlayerTask* pcPlayerTask);
    void createDrawRingWork();

    // total size: 0x6AF0

    static f32 t_of32ShapeRadius[2];
};

#endif // RING_HPP
