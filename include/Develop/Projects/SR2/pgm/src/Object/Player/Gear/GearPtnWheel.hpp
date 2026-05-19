#ifndef GEARPTNWHEEL_HPP
#define GEARPTNWHEEL_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearBasePrototype.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsGearPtnWheel;

// total size: 0xB0
class clsGearPtnWheelDraw_Task : public clsTask {
public:
    virtual ~clsGearPtnWheelDraw_Task() {}
    virtual void draw();

    clsGearPtnWheel* m_pcGear; // offset 0x54, size 0x4
    f32 m_f32Alpha;            // offset 0x58, size 0x4
    u32 m_u32AddDrawFlag;      // offset 0x5C, size 0x4
    f32 m_sTrsMtx[4][4];       // offset 0x60, size 0x40
    u8 m_bIsDraw;              // offset 0xA0, size 0x1
};

// total size: 0x70
class clsGearPtnWheel : public clsGearBasePrototype {
public:
    clsGearPtnWheel(clsGearCtrl* pcGearCtrl,
                    const stcGearData& rsGearData,
                    const stcAddPrfm& rsGearPrfm)
        : clsGearBasePrototype(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearPtnWheel() {}

    virtual enmGearType getGearType() const { return GEAR_TYPE_WHEEL; }
    virtual enmDraw2DType getDraw2DType() const { return (enmDraw2DType)(4); }
    virtual void clearChangeActionParam();
    virtual void behavior();
    virtual void behavior_NodeMtx();
    virtual void draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlagI);
    virtual enmMotionType getBaseMotionType() const { return (enmMotionType)(5); }
    virtual s32 getGearRunSeNo() const { return 3; }
    virtual void controlMotion();
    virtual void controlMotionCurve00();
    virtual void drawWheel(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlagI);

    clsGearPtnWheelDraw_Task* m_pcDrawTask; // offset 0x60, size 0x4
};

#endif // GEARPTNWHEEL_HPP
