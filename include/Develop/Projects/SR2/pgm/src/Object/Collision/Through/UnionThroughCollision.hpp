#ifndef UNIONTHROUGHCOLLISION_HPP
#define UNIONTHROUGHCOLLISION_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Collision/ThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"

class clsUnionThroughCollision : public clsThroughCollision {
public:
    virtual ~clsUnionThroughCollision();

    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);
    virtual void contactAlwaysEvent(clsPlayerTask* pcPlayer);
    virtual void contactRemoveEvent(clsPlayerTask* pcPlayer);
};

#endif // UNIONTHROUGHCOLLISION_HPP
