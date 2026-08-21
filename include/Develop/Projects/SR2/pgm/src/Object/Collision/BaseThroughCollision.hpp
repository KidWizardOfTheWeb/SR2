#ifndef BASETHROUGHCOLLISION_HPP
#define BASETHROUGHCOLLISION_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGimmick.hpp"

class clsSimpleShapePhantom;
class clsPlayerTask;
class hkShape;

// total size: 0x8
class clsBaseThroughCollision : public clsCollision {
public:
    virtual ~clsBaseThroughCollision() { destroy(); }
    virtual void contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject);
    virtual void contactAlwaysEvent(hkContactPoint* pcContact, clsObject* pcObject);
    virtual void contactRemoveEvent(hkContactPoint* pcContact, clsObject* pcObject);
    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer) {}
    virtual void contactAlwaysEvent(clsPlayerTask* pcPlayer) {}
    virtual void contactRemoveEvent(clsPlayerTask* pcPlayer) {}

    void create(const NNS_VECTOR* psPosVec, const NNS_QUATERNION* psQuat, hkShape* pcShape);
    void destroy();
    void draw();

    clsSimpleShapePhantom* m_pcPhantom; // offset 0x4, size 0x4
};

#endif // BASETHROUGHCOLLISION_HPP
