#ifndef GRAVITYTHROUGHCOLLISION_HPP
#define GRAVITYTHROUGHCOLLISION_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Collision/ThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"

class clsGravityThroughCollision : public clsThroughCollision {
public:
    virtual ~clsGravityThroughCollision();

    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);
    virtual void contactAlwaysEvent(clsPlayerTask* pcPlayer);
    virtual void contactRemoveEvent(clsPlayerTask* pParam1);
};

#endif // GRAVITYTHROUGHCOLLISION_HPP
