#ifndef GEARPTNMODELPART_HPP
#define GEARPTNMODELPART_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearBaseParts.hpp"
#include "types.h"

// total size: 0x60
class clsGearPtnModelPart : public clsGearBaseParts {
public:
    clsGearPtnModelPart(clsGearCtrl* pcGearCtrl,
                        const stcGearData& rsGearData,
                        const stcAddPrfm& rsGearPrfm)
        : clsGearBaseParts(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearPtnModelPart() {}

    f32 m_f32AddY; // offset 0x50, size 0x4

    virtual enmGearType getGearType() const { return GEAR_TYPE_MODEL_PART; }
    virtual u8 isUseModel() const { return 1; }
    virtual void clearChangeActionParam();
    virtual void behavior();
    virtual void draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlagI);
};

#endif // GEARPTNMODELPART_HPP
