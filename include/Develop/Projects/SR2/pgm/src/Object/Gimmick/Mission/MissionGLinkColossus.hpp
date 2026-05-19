#ifndef MISSIONGLINKCOLOSSUS_HPP
#define MISSIONGLINKCOLOSSUS_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsSe3DControl;
class clsPlayerTask;

// total size: 0xF0
class clsMissionGLinkColossus_Object : public clsBaseGravityLinkObject {
public:
    inline clsMissionGLinkColossus_Object() : clsBaseGravityLinkObject() {}
    virtual ~clsMissionGLinkColossus_Object() {}

    enum enmMode {
        MODE_NONE = 0,
        MODE_CRASH = 1,
        MODE_BREAK = 2,
    }; // Note: name collision with Game.hpp enmMode

    u8 m_eMode;                      // offset 0xE0, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xE4, size 0x4
    u32 m_u32DrawFlg;                // offset 0xE8, size 0x4

    static NNS_VECTOR tosCollisionHalfSizeVec;
    static f32 tof32ClipSqDist;
    static clsGravityGimmickParam t_ocGravityGimmickParam;

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();
    virtual u8 draw(NNS_OBJECT* psObject,
                    f32 (*psMtxPal)[4][4],
                    u32* psNodeStat,
                    const f32 (*opaNnViewMtx)[4][4],
                    f32 (*psMtxWork)[4][4],
                    u32 u32ViewNo);
    virtual void requestDrawContactEffect(const hkContactPoint* pcContact);
    virtual void requestDrawBreakEffect();
    virtual void drawEffect(clsPlayerTask* pcPlayer);
    virtual NNS_VECTOR* getCollisionHalfSizeVecPtr() const;
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rParam1);
};

// total size: 0x98
class clsMissionGLinkColossus_Task
    : public clsSingleModelGimmick_Task<clsMissionGLinkColossus_Task,
                                        clsMissionGLinkColossus_Object,
                                        clsModelType_OB_TX> {
public:
    clsMissionGLinkColossus_Task(u32 u32ObjectAreaNum);
    virtual ~clsMissionGLinkColossus_Task() {}

    virtual void execute();
    virtual void draw();

    clsGmkBurnLight_Task<clsModelType_OB_TX_MO_MA>* m_pcBurnLightTask; // offset 0x94, size 0x4
};

#endif // MISSIONGLINKCOLOSSUS_HPP
