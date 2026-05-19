#ifndef GRAVITYST15FLOORCONTROL_HPP
#define GRAVITYST15FLOORCONTROL_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Gravity/GrindLinkControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Path.hpp"

// total size: 0xD0
class clsGravitySt15FloorControl : public clsGrindLinkControl {
public:
    clsPath m_cPath; // offset 0x70, size 0x60

    virtual ~clsGravitySt15FloorControl() {} // size:112
    virtual void actionGravityDive();
};

#endif // GRAVITYST15FLOORCONTROL_HPP
