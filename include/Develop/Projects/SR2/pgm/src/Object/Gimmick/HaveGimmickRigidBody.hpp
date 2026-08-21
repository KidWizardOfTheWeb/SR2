#ifndef HAVEGIMMICKRIGIDBODY_HPP
#define HAVEGIMMICKRIGIDBODY_HPP

class clsGimmickRigidBody;

// total size: 0x8
class clsHaveGimmickRigidBody {
public:
    clsGimmickRigidBody* m_pcRigidBody; // offset 0x0, size 0x4

    clsHaveGimmickRigidBody() : m_pcRigidBody(0) {}
    virtual ~clsHaveGimmickRigidBody();
    clsGimmickRigidBody* getRigidBody() { return m_pcRigidBody; }
};

#endif // HAVEGIMMICKRIGIDBODY_HPP
