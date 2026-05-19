#ifndef GIMMICKRIGIDBODY_HPP
#define GIMMICKRIGIDBODY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickUnaryAction.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage15/St15CoreBase.hpp"

class clsObject;

// total size: 0x220
class clsGimmickRigidBody : public clsRigidBody {
public:
    clsGimmickRigidBody(const hkRigidBodyCinfo& rcParam1, clsObject* pcParam2)
        : clsRigidBody(rcParam1)
    {
    }
    virtual ~clsGimmickRigidBody() {}

    clsGimmickUnaryAction* m_pcUnaryAction; // offset 0x210, size 0x4
    u32 m_eFlag;                            // offset 0x214, size 0x4

    void setFlag(u32 u32Param1, u32 u32Param2) { m_eFlag = (m_eFlag & ~u32Param1) | u32Param2; }
};

#endif // GIMMICKRIGIDBODY_HPP
