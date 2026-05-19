#ifndef GEARPTNEMPTY_HPP
#define GEARPTNEMPTY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearBasePrototype.hpp"

// total size: 0x60
class clsGearPtnEmpty : public clsGearBasePrototype {
public:
    clsGearPtnEmpty(clsGearCtrl* pcGearCtrl,
                    const stcGearData& rsGearData,
                    const stcAddPrfm& rsGearPrfm)
        : clsGearBasePrototype(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearPtnEmpty() {}

    virtual enmGearType getGearType() const { return GEAR_TYPE_EMPTY; }
    virtual enmDraw2DType getDraw2DType() const { return (enmDraw2DType)(32); }
    virtual u8 isUseModel() const { return 0; }
    virtual void clearChangeActionParam();
    virtual void behavior();
    virtual void behavior_NodeMtx();
    virtual void draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag) {}
    virtual enmMotionType getBaseMotionType() const { return (enmMotionType)(1); }
    virtual s32 getGearRunSeNo() const { return 0; }
    virtual void controlMotionCurve00();
    virtual void controlMotionCurve01();
};

#endif // GEARPTNEMPTY_HPP
