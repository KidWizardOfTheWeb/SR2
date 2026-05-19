#ifndef GEARBASEPARTS_HPP
#define GEARBASEPARTS_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearBasePrototype.hpp"

// total size: 0x50
class clsGearBaseParts : public clsGear {
public:
    clsGearBaseParts(clsGearCtrl* pcGearCtrl,
                     const stcGearData& rsGearData,
                     const stcAddPrfm& rsGearPrfm)
        : clsGear(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }

    virtual ~clsGearBaseParts() {}

    virtual u8 isUseModel() const { return 1; }

    virtual enmChangeRes
    initAddParts(clsGear* pcReleaseGear, clsGear** pParam2, clsGearBaseParts* pParam3);

    virtual enmChangeRes
    execAddParts(clsGear* pcReleaseGear, clsGear** pParam2, clsGearBaseParts* pParam3);
};

#endif // GEARBASEPARTS_HPP
