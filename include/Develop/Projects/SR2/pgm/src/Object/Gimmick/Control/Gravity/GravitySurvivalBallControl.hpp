#ifndef GRAVITYSURVIVALBALLCONTROL_HPP
#define GRAVITYSURVIVALBALLCONTROL_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Gravity/GravityActionControl.hpp"

// total size: 0x50
class clsGravitySurvivalBallControl : public clsGravityActionControl {
public:
    virtual ~clsGravitySurvivalBallControl();

    virtual void gctrlInit();
    virtual void gctrlRise();
    virtual void gctrlFloat();
    virtual void gctrlMove();

    void adjustDirection();
};

#endif // GRAVITYSURVIVALBALLCONTROL_HPP
