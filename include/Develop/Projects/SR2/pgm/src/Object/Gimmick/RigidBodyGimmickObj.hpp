#ifndef RIGIDBODYGIMMICKOBJ_HPP
#define RIGIDBODYGIMMICKOBJ_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/BreakControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/ContactControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickRigidBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/DebrisControl.hpp"

class clsPlayerTask;

// total size: 0xD0
class clsRigidBodyGimmickObj : public clsGimmickObj, public clsHaveGimmickRigidBody {
public:
    enum enmControlMode {
        CTRL_MODE_MAIN = 0,
        CTRL_MODE_GRAVITY = 1,
        CTRL_MODE_CRASH = 2,
        CTRL_MODE_BREAKING = 3,
        CTRL_MODE_DEAD = 4,
    };

    // Note: enmControlFlag "no Q2 mangling" – likely global, nested here to avoid collision
    enum enmControlFlag {
        CTRL_FLAG_UPDATE_BREAK = 1,
        CTRL_FLAG_UPDATE_CONTACT = 2,
        CTRL_FLAG_UPDATE_GRAVITY = 4,
        CTRL_FLAG_UPDATE_DEBRIS = 8,
        CTRL_FLAG_DRAW_CRASH_EFFECT = 16,
        CTRL_FLAG_DRAW_CONTACT_EFFECT = 32,
        CTRL_FLAG_DRAW_BREAK_EFFECT = 64,
        CTRL_FLAG_BREAK_GRAVITY = 256,
        CTRL_FLAG_UPDATE_INTERRACTION = 512,
        CTRL_FLAG_INTERRACTION = 1024,
        CTRL_FLAG_INTERRACTION_PHYSIC = 2048,
        CTRL_FLAG_GCANCEL_BREAK = 4096,
        MASK_CTRL_FLAG_ALL = -1,
        MASK_CTRL_FLAG_CLEAR = 0,
        CTRL_FLAG_DEFAULT = 115,
    };

    enum enmBreakType {
        BREAK_TYPE_OTHER = 0,
        BREAK_TYPE_PLAYER = 1,
        BREAK_TYPE_INTERRACTION = 2,
        BREAK_TYPE_GRAVITY = 3,
    };

    clsContactControl m_cContactControl;                // offset 0x58, size 0x14
    clsBreakControl m_cBreakControl;                    // offset 0x6C, size 0x30
    clsDebrisControl* m_pcDebrisControl;                // offset 0x9C, size 0x4
    clsGravityActionControl* m_pcGravityGimmickControl; // offset 0xA0, size 0x4
    clsObject* m_pcContactPlayer;                       // offset 0xA4, size 0x4
    clsObject* m_pcContactObject;                       // offset 0xA8, size 0x4
    enmControlMode m_eControlMode;                      // offset 0xAC, size 0x4
    enmControlFlag m_eControlFlag;                      // offset 0xB0, size 0x4
    enmBreakType m_eBreakType;                          // offset 0xB4, size 0x4
    f32 m_f32ContactBurnOutEffectFrame;                 // offset 0xB8, size 0x4
    s32 m_s32ContactBurnOutCount;                       // offset 0xBC, size 0x4
    f32 m_f32MissionBreakFrame;                         // offset 0xC0, size 0x4
    f32 m_f32ContactBurnOutFrame;                       // offset 0xC4, size 0x4
    s32 m_s32ContactBurnOutInterval;                    // offset 0xC8, size 0x4
    s8 m_s8ContactBurnOutRequestNum;                    // offset 0xCC, size 0x1

    clsRigidBodyGimmickObj() : clsGimmickObj(), clsHaveGimmickRigidBody() {}
    virtual ~clsRigidBodyGimmickObj() {}
    virtual enmType getObjectType() const { return TYPE_GIMMICK_RIGID; }
    virtual void contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject);
    virtual void contactTriggerCallback(hkContactPointConfirmedEvent& cEvent);
    virtual void contactAlwaysCallback(hkContactProcessEvent& cEvent);
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void drawCollision();
    virtual void reset();
    virtual void init() {}
    virtual void main() {}
    virtual void mainGravity() {}
    virtual void mainCrash() {}
    virtual void mainBreaking() {}
    virtual void mainDead() {}
    virtual void requestDrawContactEffect(const hkContactPoint* pcContact);
    virtual void requestDrawCrashEffect(const hkContactPoint* pParam1);
    virtual void requestDrawBreakEffect();
    virtual void requestPowerTypeSe(clsPlayerTask* pcPlayer) {}
    virtual void contactInterraction(clsRigidBodyGimmickObj* pcObject);
    virtual u8 checkRequestDrawDebris() { return m_cBreakControl.m_s32ContactNum > 0; }
    virtual u8 checkContactInterraction(clsRigidBodyGimmickObj* param_1) { return 1; }
    virtual void callbackGravityEvent() {}
    virtual void callbackCrashEvent() {}
    virtual void callbackBreakEvent() {}
    virtual void callbackDeadEvent() {}
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& param_1) {}
    virtual void boundAction(clsPlayerTask* pcPlayerTask);
    virtual void updateSetEditorCollision();
    virtual void checkSetEditorCollision();

    clsGravityActionControl* getGravityActionControlPtr() { return m_pcGravityGimmickControl; }
    enmControlMode getControlMode() const { return m_eControlMode; }
    void setControlMode(enmControlMode eMode);
    void setControlFlag(u32 u32Flag, u32 u32Mask)
    {
        m_eControlFlag =
            static_cast<enmControlFlag>((u32Flag & u32Mask) | (m_eControlFlag & ~u32Mask));
    }
    u8 contactGravityActionRangeEvent(clsPlayerTask* pcPlayer);
    void execute();
    void resetBaseControl();
    void startCrash(enmBreakType eBreakType)
    {
        m_cBreakControl.m_eMode = clsBreakControl::MODE_EXECUTE;
        m_cBreakControl.m_cLimitFrame.m_f32Frame = m_cBreakControl.m_cLimitFrame.m_f32CountFrame;
        setControlMode(CTRL_MODE_CRASH);
        m_eBreakType = eBreakType;
        m_u8PortalNo = 0x3F;
    }
    void startBreak(enmBreakType eBreakType)
    {
        setControlMode(CTRL_MODE_BREAKING);
        m_eBreakType = eBreakType;
        m_cBreakControl.startRebirth();
        m_cBreakControl.setBreak();
        if (m_pcDebrisControl != 0 && (m_eControlFlag & CTRL_FLAG_UPDATE_DEBRIS) != 0) {
            m_pcDebrisControl->setVelocity(getRigidBody()->getLinearVelocity());
        }
        m_pcRigidBody->setCollisionFilterLight(0, static_cast<u32>(-1));
        m_pcRigidBody->setMotionType(hkMotion::MOTION_CHARACTER,
                                     HK_ENTITY_ACTIVATION_DO_ACTIVATE,
                                     HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);
        if ((m_eControlFlag & CTRL_FLAG_DRAW_BREAK_EFFECT) != 0) {
            requestDrawBreakEffect();
        }
    }

    static stcInfo oasGroundInfo[4];
};

#endif // RIGIDBODYGIMMICKOBJ_HPP
