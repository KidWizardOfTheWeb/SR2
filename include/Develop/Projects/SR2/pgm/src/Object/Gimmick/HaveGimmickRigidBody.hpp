#ifndef HAVEGIMMICKRIGIDBODY_HPP
#define HAVEGIMMICKRIGIDBODY_HPP

class clsGimmickRigidBody;

// total size: 0x8
class clsHaveGimmickRigidBody {
public:
    clsHaveGimmickRigidBody() : m_pcRigidBody(0) {}
    virtual ~clsHaveGimmickRigidBody() {}
    clsGimmickRigidBody* getRigidBody() { return m_pcRigidBody; }

    clsGimmickRigidBody* m_pcRigidBody; // offset 0x4, size 0x4 (DWARF shows 0x0: vtptr implicit)
};

#endif // HAVEGIMMICKRIGIDBODY_HPP
