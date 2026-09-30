#ifndef HAVEGIMMICKRIGIDBODY_HPP
#define HAVEGIMMICKRIGIDBODY_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickRigidBody.hpp"

// total size: 0x8
class clsHaveGimmickRigidBody {
public:
    clsGimmickRigidBody* m_pcRigidBody; // offset 0x0, size 0x4

    clsHaveGimmickRigidBody() : m_pcRigidBody(NULL) {}
    virtual ~clsHaveGimmickRigidBody()
    {
        delete m_pcRigidBody;
        m_pcRigidBody = NULL;
    }
    clsGimmickRigidBody* getRigidBody() { return m_pcRigidBody; }
};

#endif // HAVEGIMMICKRIGIDBODY_HPP
