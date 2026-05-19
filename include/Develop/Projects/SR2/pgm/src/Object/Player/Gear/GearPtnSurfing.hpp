#ifndef GEARPTNSURFING_HPP
#define GEARPTNSURFING_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearBasePrototype.hpp"

// total size: 0xA0
class clsGearPtnSurfing : public clsGearBasePrototype {
public:
    clsGearPtnSurfing(clsGearCtrl* pcGearCtrl,
                      const stcGearData& rsGearData,
                      const stcAddPrfm& rsGearPrfm)
        : clsGearBasePrototype(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearPtnSurfing() {}

    virtual enmGearType getGearType() const { return GEAR_TYPE_SURFING; }
    virtual enmDraw2DType getDraw2DType() const { return (enmDraw2DType)(5); }
    virtual void clearChangeActionParam();
    virtual void behavior();
    virtual void behavior_NodeMtx();
    virtual enmMotionType getBaseMotionType() const { return (enmMotionType)(6); }
    virtual s32 getGearRunSeNo() const { return 4; }

    f32 m_sBordMtx[4][4]; // offset 0x60, size 0x40
};

#endif // GEARPTNSURFING_HPP
