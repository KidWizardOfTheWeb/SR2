#ifndef GEARPTNSKATE_HPP
#define GEARPTNSKATE_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearBasePrototype.hpp"

class clsSkateBurnLight_Task;

// total size: 0x70
class clsGearPtnSkate : public clsGearBasePrototype {
public:
    clsGearPtnSkate(clsGearCtrl* pcGearCtrl,
                    const stcGearData& rsGearData,
                    const stcAddPrfm& rsGearPrfm)
        : clsGearBasePrototype(pcGearCtrl, rsGearData, rsGearPrfm), m_pcBurnLight_Task(0)
    {
    }
    virtual ~clsGearPtnSkate() {}

    virtual enmGearType getGearType() const { return GEAR_TYPE_SKATE; }
    virtual enmDraw2DType getDraw2DType() const { return (enmDraw2DType)(2); }
    virtual u8 isUseModel() const { return 0; }
    virtual void clearChangeActionParam();
    virtual void behavior();
    virtual void behavior_NodeMtx();
    virtual void draw(const f32 (*pParam1)[4][4], f32 f32Param2, u32 u32Param3);
    virtual enmMotionType getBaseMotionType() const { return (enmMotionType)(3); }
    virtual s32 getGearRunSeNo() const { return 0; }
    virtual void controlMotion();
    virtual void controlMotionCurve00();

    clsSkateBurnLight_Task* m_pcBurnLight_Task; // offset 0x60, size 0x4
};

#endif // GEARPTNSKATE_HPP
