#ifndef GEARPTNEFFECTPART_HPP
#define GEARPTNEFFECTPART_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearBaseParts.hpp"

// total size: 0x50
class clsGearPtnEffectPart : public clsGearBaseParts {
public:
    clsGearPtnEffectPart(clsGearCtrl* pcGearCtrl,
                         const stcGearData& rsGearData,
                         const stcAddPrfm& rsGearPrfm)
        : clsGearBaseParts(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearPtnEffectPart() {}

    virtual enmGearType getGearType() const { return GEAR_TYPE_EFFECT_PART; }
    virtual u8 isUseModel() const { return 0; }
    virtual void clearChangeActionParam();
};

#endif // GEARPTNEFFECTPART_HPP
