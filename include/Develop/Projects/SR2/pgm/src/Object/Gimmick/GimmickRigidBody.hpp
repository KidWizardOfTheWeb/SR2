#ifndef GIMMICKRIGIDBODY_HPP
#define GIMMICKRIGIDBODY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickUnaryAction.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/RigidBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/Havok.hpp"

class clsObject;

// total size: 0x220
class clsGimmickRigidBody : public clsRigidBody {
public:
    clsGimmickRigidBody(const hkRigidBodyCinfo& rcInfo, clsObject* pcObject)
        : clsRigidBody(rcInfo), m_pcUnaryAction(NULL), m_eFlag(0)
    {
        m_userData = pcObject;
        addCollisionListener(clsHavok::GS()->m_pcRigidListener);
    }
    virtual ~clsGimmickRigidBody()
    {
        if (m_pcUnaryAction != NULL) {
            if (m_pcUnaryAction->m_world != NULL) {
                clsHavok::GS()->m_pcWorld->removeAction(m_pcUnaryAction);
            }
            delete m_pcUnaryAction;
            m_pcUnaryAction = NULL;
        }
    }

    clsGimmickUnaryAction* m_pcUnaryAction; // offset 0x210, size 0x4
    u32 m_eFlag;                            // offset 0x214, size 0x4

    void setFlag(u32 u32Param1, u32 u32Param2) { m_eFlag = (m_eFlag & ~u32Param1) | u32Param2; }
};

#endif // GIMMICKRIGIDBODY_HPP
