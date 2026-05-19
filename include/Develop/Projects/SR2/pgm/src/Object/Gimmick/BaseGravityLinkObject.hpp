#ifndef BASEGRAVITYLINKOBJECT_HPP
#define BASEGRAVITYLINKOBJECT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"

class clsPlayerTask;

// total size: 0xE0
class clsBaseGravityLinkObject : public clsRigidBodyGimmickObj {
public:
    clsBaseGravityLinkObject() {}
    virtual ~clsBaseGravityLinkObject() {}
    virtual enmType getObjectType() const { return TYPE_GIMMICK_GLINK; }
    virtual void actionLinkPlayer(clsPlayerTask* pParam1);
    virtual void playSe(clsPlayerTask* pParam1) {}
    virtual void drawEffect(clsPlayerTask* pParam1) {}

    u8 m_u8ParticleFrame; // offset 0xD0, size 0x1
    u8 m_u8ParticleType;  // offset 0xD1, size 0x1
};

#endif // BASEGRAVITYLINKOBJECT_HPP
