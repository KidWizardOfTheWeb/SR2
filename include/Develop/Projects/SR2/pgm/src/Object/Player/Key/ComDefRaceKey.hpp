#ifndef COMDEFRACEKEY_HPP
#define COMDEFRACEKEY_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Key/ComKey.hpp"
#include "types.h"

// total size: 0x190
class clsComDefRaceKey : public clsComKey {
public:
    virtual ~clsComDefRaceKey() {}
    virtual enmComGearChangeMode getGearChangeMode() const { return GEAR_CHANGE_MODE_RACE; }
};

#endif // COMDEFRACEKEY_HPP
