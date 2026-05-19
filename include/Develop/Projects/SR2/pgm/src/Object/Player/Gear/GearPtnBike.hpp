#ifndef GEARPTNBIKE_HPP
#define GEARPTNBIKE_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearBasePrototype.hpp"

// total size: 0x60
class clsGearPtnBike : public clsGearBasePrototype {
public:
    clsGearPtnBike(clsGearCtrl* pcGearCtrl,
                   const stcGearData& rsGearData,
                   const stcAddPrfm& rsGearPrfm)
        : clsGearBasePrototype(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearPtnBike() {}

    virtual enmGearType getGearType() const { return GEAR_TYPE_BIKE; }
    virtual enmDraw2DType getDraw2DType() const { return (enmDraw2DType)(1); }
    virtual void clearChangeActionParam();
    virtual void behavior();
    virtual void behavior_NodeMtx() {}
    virtual enmMotionType getBaseMotionType() const { return (enmMotionType)(2); }
    virtual s32 getGearRunSeNo() const { return 1; }
    virtual void Curve(f32 f32Ratio);
    virtual void controlMotionCurve00();
};

#endif // GEARPTNBIKE_HPP
