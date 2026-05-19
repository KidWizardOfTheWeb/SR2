#ifndef CONTACTCONTROL_HPP
#define CONTACTCONTROL_HPP

#include "types.h"

class clsGimmickRigidBody;
class clsPlayerTask;
class hkContactPoint;

// total size: 0x14
class clsContactControl {
public:
    // Note: enmMode collides with global Game.hpp enum; nested here for disambiguation.
    enum enmMode {
        GAME_MODE___NONE = 0,
        GAME_MODE___ADVERTISE = 1,
        GAME_MODE___TITLE_DEMO = 2,
        GAME_MODE___FREE_RACE = 3,
        GAME_MODE___TIME_ATTACK = 4,
        GAME_MODE___STORY = 5,
        GAME_MODE___WORLD_GP = 6,
        GAME_MODE___MISSION = 7,
        GAME_MODE___TUTORIAL = 8,
        GAME_MODE___SURVIVAL_RELAY = 9,
        GAME_MODE___SURVIVAL_BALL = 10,
        GAME_MODE___SURVIVAL_BATTLE = 11,
        GAME_MODE___EVENT = 12,
        GAME_MODE___CREDIT = 13,
        GAME_MODE___EASY_MENU = 14,
        GAME_MODE___MODEL_VIEWER = 15,
        GAME_MODE___MAX = 16,
    };

    enum enmContactPlayerType {
        CONTACT_PLAYER_TYPE_NONE = 0,
    };

    enum enmContactAction {
        CONTACT_ACTION_NONE = 0,
    };

    // total size: 0x2
    struct stcContactStatus {
        u8 ePlayer; // offset 0x0, size 0x1
        u8 eRigid;  // offset 0x1, size 0x1
    };

    clsContactControl() {}
    ~clsContactControl() {}

    void setContactStatus(enmContactPlayerType eType,
                          enmContactAction ePlayer,
                          enmContactAction eRigid)
    {
    }
    void boundNormalPlayer(hkContactPoint* pcContact,
                           clsGimmickRigidBody* pcRigidBody,
                           clsPlayerTask* pcPlayer,
                           bool bRefrection,
                           f32 f32RefMaxSpeed);
    void boundPlayer(hkContactPoint* pcContact,
                     clsGimmickRigidBody* pcRigidBody,
                     clsPlayerTask* pcPlayer,
                     bool bRefrection);
    void reactionPlayerNormal(hkContactPoint* pcContact,
                              clsGimmickRigidBody* pcRigidBody,
                              clsPlayerTask* pcPlayer);
    void reactionPlayerPower(hkContactPoint* pcContact,
                             clsGimmickRigidBody* pcRigidBody,
                             clsPlayerTask* pcPlayer);
    void reactionPlayerGravityControl(hkContactPoint* pcContact,
                                      clsGimmickRigidBody* pcRigidBody,
                                      clsPlayerTask* pcPlayer);
    void reactionPlayerGravityDive(hkContactPoint* pcContact,
                                   clsGimmickRigidBody* pcRigidBody,
                                   clsPlayerTask* pcPlayer);
    void updateContactPlayer(hkContactPoint* pcContact,
                             clsGimmickRigidBody* pcRigidBody,
                             clsPlayerTask* pcPlayer);

    stcContactStatus* m_pcActiveContactStatus; // offset 0x0, size 0x4
    enmMode m_eMode;                           // offset 0x4, size 0x4
    s32 m_s32ContactNum;                       // offset 0x8, size 0x4
    stcContactStatus m_sContactStatus[4];      // offset 0xC, size 0x8
};

#endif // CONTACTCONTROL_HPP
