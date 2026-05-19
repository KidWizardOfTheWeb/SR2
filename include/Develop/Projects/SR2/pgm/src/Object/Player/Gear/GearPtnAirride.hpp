#ifndef GEARPTNAIRRIDE_HPP
#define GEARPTNAIRRIDE_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearBasePrototype.hpp"

// total size: 0x60
class clsGearPtnAirride : public clsGearBasePrototype {
public:
    clsGearPtnAirride(clsGearCtrl* pcGearCtrl,
                      const stcGearData& rsGearData,
                      const stcAddPrfm& rsGearPrfm)
        : clsGearBasePrototype(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearPtnAirride() {}

    virtual enmGearType getGearType() const { return GEAR_TYPE_AIRRIDE; }
    virtual enmDraw2DType getDraw2DType() const { return (enmDraw2DType)(3); }
    virtual void clearChangeActionParam();
    virtual void behavior();
    virtual enmMotionType getBaseMotionType() const { return (enmMotionType)(4); }
    virtual s32 getGearRunSeNo() const { return 0; }
    virtual s32 getGearFlySeNo() const { return 2; }
    virtual void Curve(f32 f32Ratio);
    virtual void controlMotionCurve00();
};

#endif // GEARPTNAIRRIDE_HPP
