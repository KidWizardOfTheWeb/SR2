#ifndef CONTACTCONTROL_HPP
#define CONTACTCONTROL_HPP

#include "types.h"

class clsGimmickRigidBody;
class clsPlayerTask;
class hkContactPoint;

// total size: 0x14
class clsContactControl {
public:
    enum enmMode {
        MODE_NONE = 0,
        MODE_EXECUTE = 1,
        MODE_BREAK = 2,
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

    clsContactControl() : m_pcActiveContactStatus(0), m_eMode(MODE_NONE), m_s32ContactNum(0)
    {
        m_sContactStatus[0].ePlayer = 2;
        m_sContactStatus[0].eRigid = 0;
        m_sContactStatus[1].ePlayer = 3;
        m_sContactStatus[1].eRigid = 1;
        m_sContactStatus[2].ePlayer = 2;
        m_sContactStatus[2].eRigid = 1;
        m_sContactStatus[3].ePlayer = 2;
        m_sContactStatus[3].eRigid = 1;
    }
    ~clsContactControl();

    void reset()
    {
        m_eMode = MODE_NONE;
        m_pcActiveContactStatus = 0;
        m_s32ContactNum = 0;
    }
    u8 isBreak() const { return m_eMode == MODE_BREAK; }
    u8 isExecute() const { return m_eMode == MODE_EXECUTE; }

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
