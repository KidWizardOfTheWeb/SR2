#ifndef ST04GLINKWATERSPHERE_HPP
#define ST04GLINKWATERSPHERE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptShadow.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Compression/OOLZSS.hpp"

// Enum used by clsGLinkWaterSphere_Object (owned by clsGLinkWaterSphere_Object)
enum enmWaterSphereMode {
    MODE_INIT = 0,
    MODE_WAIT = 1,
    MODE_RISE = 2,
    MODE_FLOAT = 3,
    MODE_MOVE_INIT = 4,
    MODE_MOVE = 5,
    MODE_END = 6,
};

// total size: 0x110
class clsGLinkWaterSphere_Object : public clsBaseGravityLinkObject {
public:
    clsGLinkWaterSphere_Object() {}
    virtual ~clsGLinkWaterSphere_Object();
    virtual void reset();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void main();
    virtual void mainGravity();
    virtual void mainCrash();
    virtual void requestDrawBreakEffect();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rParam1);
    virtual void drawEffect(clsPlayerTask* pParam1);
    virtual NNS_VECTOR* getCollisionHalfSizeVecPtr() const;
    virtual nspPackId::enm getPackId() const { return nspPackId::ST04_GLINK_WATERSPHERE_14010; }
    virtual void draw(clsModelType_OB_TX_MO_MA& rcModel,
                      f32 (*psMtxPal)[4][4],
                      u32* psNodeStat,
                      const f32 (*opaNnViewMtx)[4][4],
                      f32 (*psMtxWork)[4][4],
                      u32 u32ViewNo);

    NNS_OBJECT* m_psMorphObject; // offset 0xE0, size 0x4

    clsSe3DControl* m_pcSe3DControl; // offset 0xE4, size 0x4

    enmWaterSphereMode m_eMode; // offset 0xE8, size 0x4

    f32 m_f32MatFrame; // offset 0xEC, size 0x4

    f32 m_f32MorphFrame; // offset 0xF0, size 0x4

    f32 m_f32Scale; // offset 0xF4, size 0x4

    f32 m_f32EffectFrame; // offset 0xF8, size 0x4

    u8 m_bMorphMotion; // offset 0xFC, size 0x1
    u8 m_bCliping;     // offset 0xFD, size 0x1
    f32 m_f32Depth;    // offset 0x100, size 0x4
    f32 m_f32Width;    // offset 0x104, size 0x4
    f32 m_f32DiveRad;  // offset 0x108, size 0x4

    static NNS_VECTOR tosCollisionHalfSizeVec;
    static f32 tof32ClipSqDist;
    static clsGravityGimmickParam t_ocGravityGimmickParam;
};

// total size: 0xB0
class clsGLinkWaterSphere_Task : public clsSingleModelGimmick_Task<clsGLinkWaterSphere_Task,
                                                                   clsGLinkWaterSphere_Object,
                                                                   clsModelType_OB_TX_MO_MA> {
public:
    clsGLinkWaterSphere_Task(u32 u32ObjectAreaNum);
    virtual ~clsGLinkWaterSphere_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    hkShape* m_pcPartsShape; // offset 0xAC, size 0x4
};

#endif // ST04GLINKWATERSPHERE_HPP
