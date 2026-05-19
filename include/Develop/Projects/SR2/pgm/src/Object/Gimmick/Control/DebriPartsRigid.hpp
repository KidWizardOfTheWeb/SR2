#ifndef DEBRIPARTSRIGID_HPP
#define DEBRIPARTSRIGID_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/DebriPartsBase.hpp"
#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsObject;
class clsRigidBody;
class hkRigidBodyCinfo;

// total size: 0x50
class clsDebriPartsRigid : public clsDebriPartsBase {
public:
    clsDebriPartsRigid() {}
    virtual ~clsDebriPartsRigid() {}

    virtual void reset();
    virtual void update();
    virtual void startBreak(NNS_VECTORFAST* psPosVecFast, NNS_VECTORFAST* psVelocityVecFast);
    virtual void draw(NNS_OBJECT* psObject, f32 f32ClipSqDist);

    void create(hkRigidBodyCinfo& rcRigidBodyInfo, clsObject* pcObject);

    NNS_QUATERNION m_sRotQuat;   // offset 0x30, size 0x10
    clsRigidBody* m_pcRigidBody; // offset 0x40, size 0x4
};

#endif // DEBRIPARTSRIGID_HPP
