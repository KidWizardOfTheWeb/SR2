#ifndef LIGHTTHROUGHCOLLISION_HPP
#define LIGHTTHROUGHCOLLISION_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Collision/ThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"

class clsLightThroughCollision : public clsThroughCollision {
public:
    virtual ~clsLightThroughCollision();

    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);
    virtual void contactRemoveEvent(clsPlayerTask* pcPlayer);
};

#endif // LIGHTTHROUGHCOLLISION_HPP
